#include "ResourceMgr.h"
#include "base/AsyncTaskPool.h"
#include "io/core/MemoryStream.h"
#include "io/zip/ZipReadAdapter.h"
#include "io/zip/ZipReader.h"
#include "platform/FileUtils.h"
#include <cmath>
#include <limits>

using namespace std;
using namespace lstg;
using namespace cc;

namespace
{
	class FileSnapshotOwner final : public Ref
	{
	public:
		FileSnapshotOwner(RefConstructionToken token, FileBytes bytes)
			: Ref(token), bytes(std::move(bytes)) {}
	private:
		FileBytes bytes;
	};

	string bytesToString(const FileBytes& data)
	{
		return data && !data->empty()
			? string(reinterpret_cast<const char*>(data->data()), data->size()) : string{};
	}

	Buffer* bufferView(const string& key, const FileBytes& data,
		unordered_map<string, pair<FileBytes, cc::IntrusivePtr<Buffer>>>& views)
	{
		if (!data)
			return nullptr;
		const auto source = views.find(key);
		if (source != views.end() && source->second.first == data)
			return source->second.second;
		const auto ret = Buffer::create();
		if (!ret)
			return nullptr;
		ret->assign_values(*data);
		ret->setWritable(false);
		ret->setResizable(false);
		views.insert_or_assign(key, make_pair(data, cc::IntrusivePtr<Buffer>{ret}));
		return ret;
	}

	string cacheKey(const FileHit& hit)
	{
		return to_string(hit.adapterId()) + ':' + hit.entry().entryKey;
	}

	const ZipReadAdapter* zipAdapter(const FileHit& hit)
	{
		return dynamic_cast<const ZipReadAdapter*>(hit.adapter().get());
	}

	template<class Work>
	void cacheAsync(const function<void()>& callback, Work&& work)
	{
		AsyncTaskPool::getInstance()->enqueue(AsyncTaskPool::TaskType::TASK_IO,
			[callback](void*) { if (callback) callback(); }, nullptr, std::forward<Work>(work));
	}
}

struct ResourcePack::State
{
	string path;
	float priority = 0;
	archive::ZipReader::Ptr reader;
	shared_ptr<ZipReadAdapter> adapter;

	void cacheAll() const
	{
		for (const auto& entry : reader->entries())
			if (entry.type == archive::EntryType::File)
				adapter->readBytes(entry.name);
	}
};

ResourcePack::ResourcePack() : state(make_shared<State>()) {}
ResourcePack::~ResourcePack() = default;

bool ResourcePack::init(const string& path, const string& password)
{
	archive::ZipReadOptions options;
	options.password = password;
	auto reader = archive::ZipReader::openFile(path, options);
	if (!reader)
		return false;
	cc::ZipMountOptions mountOptions;
	mountOptions.entry.temporaryDirectory = FileUtils::getInstance()->getWritablePath();
	auto adapter = ZipReadAdapter::create(reader.value, {""}, mountOptions);
	if (!adapter)
		return false;
	state->path = path;
	state->reader = std::move(reader.value);
	state->adapter = std::move(adapter.value);
	return true;
}

cc::IntrusivePtr<ResourcePack> ResourcePack::create(const string& fullPath, const string& password)
{
	try
	{
		cc::IntrusivePtr ret{new ResourcePack()};
		if (ret->init(fullPath, password))
			return ret;
	}
	catch (const bad_alloc&) {}
	catch (const length_error&) {}
	return nullptr;
}

string ResourcePack::getPath() const { return state->path; }
size_t ResourcePack::getFileCount() const { return state->reader->entries().size(); }
bool ResourcePack::isFileOrDirectoryExist(const string& path) const
{
	return state->adapter->containsEntry(path);
}

float ResourcePack::getPriority() const
{
	if (adapterId)
		for (const auto& adapter : FileUtils::getInstance()->getReadAdapters())
			if (adapter.id == adapterId)
				return adapter.priority;
	return state->priority;
}

void ResourcePack::setPriority(float value)
{
	if (std::isfinite(value) &&
		(!adapterId || FileUtils::getInstance()->setAdapterPriority(adapterId, value)))
		state->priority = value;
}

uint32_t ResourcePack::getCRC32(const string& path)
{
	const auto info = state->adapter->entryInfo(path);
	return info ? info->crc.value_or(0) : 0;
}

uint64_t ResourcePack::getCompressedSize(const string& path)
{
	const auto info = state->adapter->entryInfo(path);
	return info ? info->compressedSize.value_or(0) : 0;
}

uint64_t ResourcePack::getUncompressedSize(const string& path)
{
	const auto info = state->adapter->entryInfo(path);
	return info ? info->size.value_or(0) : 0;
}

FileBytes ResourcePack::getFileData(const string& path)
{
	return state->adapter->readBytes(path).value;
}

Buffer* ResourcePack::loadAndCache(const string& path)
{
	try
	{
		const auto info = state->adapter->entryInfo(path);
		return info ? bufferView(info->name, getFileData(info->name), bufferViews) : nullptr;
	}
	catch (const bad_alloc&) { return nullptr; }
	catch (const length_error&) { return nullptr; }
}

string ResourcePack::getStringFromFile(const string& path) { return bytesToString(getFileData(path)); }
bool ResourcePack::cacheFile(const string& path) { return !!getFileData(path); }

void ResourcePack::cacheFileAsync(const string& path, const function<void()>& callback)
{
	cacheAsync(callback, [archive = state->adapter, path]() { archive->readBytes(path); });
}

void ResourcePack::cacheAllFiles() { state->cacheAll(); }

void ResourcePack::cacheAllFilesAsync(const function<void()>& callback)
{
	cacheAsync(callback, [archive = state]() { archive->cacheAll(); });
}

bool ResourcePack::isFileCached(const string& path) { return state->adapter->isCached(path); }

bool ResourcePack::removeFileCache(const string& path)
{
	if (const auto info = state->adapter->entryInfo(path))
		bufferViews.erase(info->name);
	return state->adapter->removeCached(path);
}

void ResourcePack::clearFileCache()
{
	bufferViews.clear();
	state->adapter->clearCache();
}

size_t ResourcePack::getFileCacheSize() { return state->adapter->cachedBytes(); }

vector<string> ResourcePack::listFiles()
{
	vector<string> files;
	for (const auto& entry : state->reader->entries())
		files.push_back(entry.name);
	return files;
}

vector<string> ResourcePack::listCachedFiles() { return state->adapter->cachedEntryNames(); }

ResourceMgr::ResourceMgr() = default;
ResourceMgr::~ResourceMgr() = default;
ResourceMgr* ResourceMgr::getInstance()
{
	static ResourceMgr instance;
	return &instance;
}

io::Result<FileBytes> ResourceMgr::readFileHit(const FileHit& hit)
{
	using Result = io::Result<FileBytes>;
	if (!hit.adapterId())
		return Result::failure({io::ErrorCode::NotFound});
	if (const auto zip = zipAdapter(hit))
		return zip->readBytes(hit.entry().entryKey);
	try
	{
		io::StreamError error;
		const auto data = localFiles.load(cacheKey(hit), [&hit, &error]() -> FileBytes
		{
			auto file = FileUtils::getInstance()->openRead(hit);
			if (!file)
			{
				error = file.error;
				return nullptr;
			}
			const auto size = file.value->size();
			if (size < 0 || static_cast<uint64_t>(size) > numeric_limits<size_t>::max())
			{
				error = {size < 0 ? io::ErrorCode::IoError : io::ErrorCode::Overflow};
				return nullptr;
			}
			auto bytes = make_shared<vector<uint8_t>>(static_cast<size_t>(size));
			size_t offset = 0;
			while (offset < bytes->size())
			{
				const auto chunk = min(bytes->size() - offset, size_t(numeric_limits<int>::max()));
				const auto amount = file.value->read(bytes->data() + offset, static_cast<unsigned>(chunk));
				if (amount <= 0)
				{
					error = {io::ErrorCode::IoError};
					return nullptr;
				}
				offset += amount;
			}
			if (file.value->close() == 0)
				return bytes;
			error = {io::ErrorCode::IoError};
			return nullptr;
		});
		return data ? Result::success(data) : Result::failure(error);
	}
	catch (const bad_alloc&) { return Result::failure({io::ErrorCode::OutOfMemory}); }
	catch (const length_error&) { return Result::failure({io::ErrorCode::Overflow}); }
}

Buffer* ResourceMgr::loadLocalFileAndCache(const string& path)
{
	const auto hit = FileUtils::getInstance()->findPlatformFile(path);
	if (!hit)
		return nullptr;
	try { return bufferView(cacheKey(hit.value), readFileHit(hit.value).value, localBuffers); }
	catch (const bad_alloc&) { return nullptr; }
	catch (const length_error&) { return nullptr; }
}

string ResourceMgr::getStringFromLocalFile(const string& path)
{
	const auto hit = FileUtils::getInstance()->findPlatformFile(path);
	return hit ? bytesToString(readFileHit(hit.value).value) : string{};
}

bool ResourceMgr::cacheLocalFile(const string& path)
{
	const auto hit = FileUtils::getInstance()->findPlatformFile(path);
	return hit && cacheFileHit(hit.value);
}

void ResourceMgr::cacheLocalFileAsync(const string& path, const function<void()>& callback)
{
	cacheFileHitAsync(FileUtils::getInstance()->findPlatformFile(path).value, callback);
}

bool ResourceMgr::isLocalFileCached(const string& path)
{
	const auto hit = FileUtils::getInstance()->findPlatformFile(path);
	return hit && localFiles.contains(cacheKey(hit.value));
}

bool ResourceMgr::removeLocalFileCache(const string& path)
{
	const auto hit = FileUtils::getInstance()->findPlatformFile(path);
	return hit && removeFileHitCache(hit.value);
}

void ResourceMgr::clearLocalFileCache()
{
	localBuffers.clear();
	localFiles.clear();
}

vector<string> ResourceMgr::listCachedLocalFiles()
{
	auto entries = localFiles.list();
	for (auto& entry : entries)
		entry.erase(0, entry.find(':') + 1);
	return entries;
}

size_t ResourceMgr::getFileCacheSize()
{
	size_t total = localFiles.size();
	for (const auto& pack : packs)
		total += pack.second->getFileCacheSize();
	return total;
}

string ResourceMgr::resolvePackAlias(const string& path) const
{
	auto key = path;
	replace(key.begin(), key.end(), '\\', '/');
	const auto alias = packAliases.find(key);
	return alias != packAliases.end() ? alias->second : key;
}

ResourcePack* ResourceMgr::loadResourcePack(const string& path, const string& password)
{
	if (const auto loaded = getResourcePack(path))
		return loaded;
	auto fu = FileUtils::getInstance();
	for (const auto& info : fu->getReadAdapters())
	{
		if (info.kind != "physical")
			continue;
		const auto hit = fu->findFileIn(info.id, path);
		if (!hit && hit.error.code != io::ErrorCode::NotFound)
			return nullptr;
		if (!hit || !hit.value.entry().nativePath)
			continue;
		const auto& nativePath = *hit.value.entry().nativePath;
		auto pack = cc::IntrusivePtr<ResourcePack>{getResourcePack(nativePath)};
		if (!pack)
		{
			pack = ResourcePack::create(nativePath, password);
			if (!pack)
				return nullptr;
			pack->setPriority(static_cast<float>(nextPackPriority));
			addResourcePack(pack, false);
			if (!pack->adapterId)
				return nullptr;
			++nextPackPriority;
		}
		packAliases.insert_or_assign(resolvePackAlias(path), resolvePackAlias(nativePath));
		return pack;
	}
	return nullptr;
}

bool ResourceMgr::isResourcePackLoaded(const string& path) { return !!getResourcePack(path); }

void ResourceMgr::addResourcePack(ResourcePack* pack, bool override)
{
	if (!pack || pack->adapterId)
		return;
	const auto key = resolvePackAlias(pack->getPath());
	const auto it = packs.find(key);
	const auto previous = it == packs.end() ? nullptr : it->second;
	if (previous && !override)
		return;
	const auto previousPriority = previous ? previous->getPriority() : 0;
	auto fu = FileUtils::getInstance();
	const auto registration = previous
		? fu->replaceReadAdapter(previous->adapterId, key, pack->state->adapter, pack->getPriority())
		: fu->registerReadAdapter(key, pack->state->adapter, pack->getPriority());
	if (!registration)
		return;
	if (previous)
	{
		previous->state->priority = previousPriority;
		previous->adapterId = 0;
	}
	pack->adapterId = registration.value;
	packs.insert(key, pack);
}

bool ResourceMgr::unloadResourcePack(const string& path)
{
	const auto key = resolvePackAlias(path);
	const auto it = packs.find(key);
	if (it == packs.end())
		return false;
	auto pack = it->second;
	pack->state->priority = pack->getPriority();
	if (!FileUtils::getInstance()->unregisterReadAdapter(pack->adapterId))
		return false;
	pack->adapterId = 0;
	packs.erase(it);
	std::erase_if(packAliases, [&key](const auto& alias) { return alias.second == key; });
	return true;
}

void ResourceMgr::unloadAllResourcePacks()
{
	vector<string> paths;
	for (const auto& pack : packs)
		paths.push_back(pack.first);
	for (const auto& path : paths)
		unloadResourcePack(path);
}

ResourcePack* ResourceMgr::getResourcePack(const string& path)
{
	const auto it = packs.find(resolvePackAlias(path));
	return it == packs.end() ? nullptr : it->second;
}

vector<ResourcePack*> ResourceMgr::getResourcePacks()
{
	vector<ResourcePack*> ordered;
	for (const auto& adapter : FileUtils::getInstance()->getReadAdapters())
		if (auto pack = getResourcePack(adapter.name); pack && pack->adapterId == adapter.id)
			ordered.push_back(pack);
	return ordered;
}

ResourcePack* ResourceMgr::getResourcePackForHit(const FileHit& hit)
{
	auto pack = getResourcePack(hit.name());
	return pack && pack->adapterId == hit.adapterId() ? pack : nullptr;
}

bool ResourceMgr::isFileOrDirectoryExist(const string& path) const
{
	const auto matches = FileUtils::getInstance()->findAllFiles(path);
	if (matches)
		for (const auto& hit : matches.value)
			if (zipAdapter(hit))
				return true;
	for (const auto& pack : packs)
		if (pack.second->isFileOrDirectoryExist(path))
			return true;
	return false;
}

FileBytes ResourceMgr::getFileData(const string& path)
{
	const auto hit = FileUtils::getInstance()->findFile(path);
	return hit ? readFileHit(hit.value).value : nullptr;
}

bool ResourceMgr::cacheFileHit(const FileHit& hit) { return !!readFileHit(hit); }

void ResourceMgr::cacheFileHitAsync(const FileHit& hit, const function<void()>& callback)
{
	cacheAsync(callback, [this, hit]() { readFileHit(hit); });
}

bool ResourceMgr::removeFileHitCache(const FileHit& hit)
{
	if (!hit.adapterId())
		return false;
	if (const auto zip = zipAdapter(hit))
	{
		if (const auto pack = getResourcePackForHit(hit))
			if (const auto entry = zip->entryInfo(hit.entry().entryKey))
				pack->bufferViews.erase(entry->name);
		return zip->removeCached(hit.entry().entryKey);
	}
	const auto key = cacheKey(hit);
	localBuffers.erase(key);
	return localFiles.remove(key);
}

io::Result<io::StreamPtr> ResourceMgr::openReadStream(const string& path)
{
	const auto hit = FileUtils::getInstance()->findFile(path);
	if (!hit)
		return io::Result<io::StreamPtr>::failure(hit.error);
	auto bytes = readFileHit(hit.value);
	return bytes ? openFileSnapshot(bytes.value) : io::Result<io::StreamPtr>::failure(bytes.error);
}

io::Result<io::StreamPtr> ResourceMgr::openFileSnapshot(const FileBytes& bytes)
{
	using Output = io::Result<io::StreamPtr>;
	if (!bytes)
		return Output::failure({io::ErrorCode::IoError});
	try
	{
		auto owner = makeThreadSafeRef<FileSnapshotOwner>(bytes);
		auto stream = io::MemoryStream::borrow(bytes->data(), bytes->size(), std::move(owner));
		if (!stream)
			return Output::failure(stream.error);
		return Output::success(std::move(stream.value));
	}
	catch (const bad_alloc&) { return Output::failure({io::ErrorCode::OutOfMemory}); }
}

Buffer* ResourceMgr::getBufferFromFile(const string& path)
{
	const auto hit = FileUtils::getInstance()->findFile(path);
	if (!hit)
		return nullptr;
	try
	{
		if (const auto pack = getResourcePackForHit(hit.value))
			return pack->loadAndCache(hit.value.entry().entryKey);
		return bufferView(cacheKey(hit.value), readFileHit(hit.value).value, localBuffers);
	}
	catch (const bad_alloc&) { return nullptr; }
	catch (const length_error&) { return nullptr; }
}

string ResourceMgr::getStringFromFile(const string& path) { return bytesToString(getFileData(path)); }

bool ResourceMgr::extractFile(const string& path, const string& target)
{
	const auto data = getFileData(path);
	if (!data)
		return false;
	const auto file = FileUtils::getInstance()->openFileStream(target, FileStream::Mode::WRITE);
	if (!file || !file->isOpen())
		return false;
	size_t offset = 0;
	while (offset < data->size())
	{
		const auto length = static_cast<unsigned>(min(data->size() - offset, size_t(numeric_limits<int>::max())));
		const auto count = file->write(data->data() + offset, length);
		if (count <= 0)
			return false;
		offset += count;
	}
	return file->close() == 0;
}

void ResourceMgr::clear()
{
	unloadAllResourcePacks();
	clearLocalFileCache();
}
