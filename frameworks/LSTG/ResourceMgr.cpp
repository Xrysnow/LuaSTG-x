#include "ResourceMgr.h"
#include "AppFrame.h"
#include "Util/Utility.h"
#include "XFileUtils.h"
#include "LogSystem.h"
#include "platform/CCFileStream.h"
#include "io/MemoryStream.h"
#include <atomic>

using namespace std;
using namespace lstg;
using namespace cocos2d;

namespace
{
	// Only this Atomic owner and immutable native bytes cross thread boundaries;
	// resource caches keep their existing FileBytes ownership and generation rules.
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

	// Legacy main-thread API only. Worker caches never own Refs.
	Buffer* bufferView(const string& path, const FileBytes& data,
		unordered_map<string, pair<FileBytes, RefPtr<Buffer>>>& views)
	{
		if (!data)
			return nullptr;
		const auto source = views.find(path);
		if (source != views.end() && source->second.first == data)
			return source->second.second;
		const auto ret = Buffer::create();
		if (!ret)
			return nullptr;
		ret->assign_values(*data);
		ret->setWritable(false);
		ret->setResizable(false);
		// Pair the source and its view atomically; RAII also covers map allocation failure.
		views.insert_or_assign(path, make_pair(data, RefPtr<Buffer>{ret}));
		return ret;
	}
}

// A queued task or in-flight reader owns this state independently of the Ref wrapper.
struct ResourcePack::State
{
	struct ZipFile
	{
		unz_file_info info;
		int64_t pos;
	};
	string path;
	string password;
	atomic<float> priority{0.f};
	unzFile zipFile = nullptr;
	mutex zipMutex;
	unordered_map<string, ZipFile> files;
	ResourceFileCache loadedFiles;

	~State()
	{
		if (zipFile)
			unzClose(zipFile);
	}

	bool init(const string& path_, const string& passwd)
	{
		path = path_;
		password = passwd;
		zlib_filefunc64_def funcs{};
		fill_fopen64_filefunc(&funcs);
		zipFile = unzOpen2_64(FileUtils::getInstance()->getSuitableFOpen(path).c_str(), &funcs);
		if (!zipFile)
			return false;
		for (int status = unzGoToFirstFile(zipFile); status == UNZ_OK; status = unzGoToNextFile(zipFile))
		{
			ZipFile file{};
			char name[MAX_PATH]{};
			if (unzGetCurrentFileInfo(zipFile, &file.info, name, sizeof(name), nullptr, 0, nullptr, 0) == UNZ_OK
				&& file.info.size_filename < sizeof(name))
			{
				file.pos = unzGetOffset64(zipFile);
				files[name] = file;
			}
		}
		return true;
	}

	FileBytes load(const string& fpath)
	{
		return loadedFiles.load(fpath, [this, &fpath]() -> FileBytes
		{
			const auto it = files.find(fpath);
			if (it == files.end())
				return nullptr;
			lock_guard<mutex> lock(zipMutex);
			if (unzSetOffset64(zipFile, it->second.pos) != UNZ_OK
				|| unzOpenCurrentFilePassword(zipFile, password.empty() ? nullptr : password.c_str()) != UNZ_OK)
				return nullptr;
			struct CloseFile
			{
				unzFile file;
				~CloseFile() { if (file) unzCloseCurrentFile(file); }
			} close{zipFile};
			auto data = make_shared<vector<uint8_t>>(it->second.info.uncompressed_size);
			size_t offset = 0;
			while (offset < data->size())
			{
				const auto length = static_cast<unsigned>(min(data->size() - offset, size_t(numeric_limits<int>::max())));
				const auto count = unzReadCurrentFile(zipFile, data->data() + offset, length);
				if (count <= 0)
					return nullptr;
				offset += count;
			}
			const auto status = unzCloseCurrentFile(zipFile);
			close.file = nullptr;
			return status == UNZ_OK ? data : nullptr;
		});
	}

	void cacheAll()
	{
		for (const auto& file : files)
			load(file.first);
	}
};

ResourcePack::ResourcePack() : state(make_shared<State>()) {}
ResourcePack::~ResourcePack() = default;

bool ResourcePack::init(const string& path, const string& passwd)
{
	return state->init(path, passwd);
}

ResourcePack* ResourcePack::create(const string& fullPath, const string& password)
{
	ResourcePack* ret = nullptr;
	try
	{
		ret = new (nothrow) ResourcePack();
		if (ret && ret->init(fullPath, password))
		{
			ret->autorelease();
			return ret;
		}
	}
	catch (const bad_alloc&) {}
	catch (const length_error&) {}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

string ResourcePack::getPath() const { return state->path; }
size_t ResourcePack::getFileCount() const { return state->files.size(); }
bool ResourcePack::isFileOrDirectoryExist(const string& path) const { return state->files.count(path) != 0; }
float ResourcePack::getPriority() const { return state->priority.load(); }
void ResourcePack::setPriority(float value) { state->priority.store(value); }

uint32_t ResourcePack::getCRC32(const string& path)
{
	const auto it = state->files.find(path);
	return it == state->files.end() ? 0 : it->second.info.crc;
}

uint32_t ResourcePack::getCompressedSize(const string& path)
{
	const auto it = state->files.find(path);
	return it == state->files.end() ? 0 : it->second.info.compressed_size;
}

uint32_t ResourcePack::getUncompressedSize(const string& path)
{
	const auto it = state->files.find(path);
	return it == state->files.end() ? 0 : it->second.info.uncompressed_size;
}

FileBytes ResourcePack::getFileData(const string& path)
{
	try { return state->load(path); }
	catch (const bad_alloc&) { return nullptr; }
	catch (const length_error&) { return nullptr; }
}

Buffer* ResourcePack::loadAndCache(const string& path)
{
	try { return bufferView(path, getFileData(path), bufferViews); }
	catch (const bad_alloc&) { return nullptr; }
	catch (const length_error&) { return nullptr; }
}

string ResourcePack::getStringFromFile(const string& path) { return bytesToString(getFileData(path)); }
bool ResourcePack::cacheFile(const string& path) { return !!getFileData(path); }

void ResourcePack::cacheFileAsync(const string& path, const function<void()>& callback)
{
	const auto data = state;
	AsyncTaskPool::getInstance()->enqueue(AsyncTaskPool::TaskType::TASK_IO,
		[callback](void*) { if (callback) callback(); }, nullptr,
		[data, path]()
		{
			try { data->load(path); }
			catch (const bad_alloc&) {}
			catch (const length_error&) {}
		});
}

void ResourcePack::cacheAllFiles()
{
	for (const auto& file : state->files)
		getFileData(file.first);
}

void ResourcePack::cacheAllFilesAsync(const function<void()>& callback)
{
	const auto data = state;
	AsyncTaskPool::getInstance()->enqueue(AsyncTaskPool::TaskType::TASK_IO,
		[callback](void*) { if (callback) callback(); }, nullptr,
		[data]()
		{
			try { data->cacheAll(); }
			catch (const bad_alloc&) {}
			catch (const length_error&) {}
		});
}

bool ResourcePack::isFileCached(const string& path) { return state->loadedFiles.contains(path); }
bool ResourcePack::removeFileCache(const string& path)
{
	bufferViews.erase(path);
	return state->loadedFiles.remove(path);
}
void ResourcePack::clearFileCache()
{
	bufferViews.clear();
	state->loadedFiles.clear();
}
size_t ResourcePack::getFileCacheSize() { return state->loadedFiles.size(); }
vector<string> ResourcePack::listFiles()
{
	vector<string> ret;
	for (const auto& file : state->files)
		ret.push_back(file.first);
	return ret;
}
vector<string> ResourcePack::listCachedFiles() { return state->loadedFiles.list(); }

ResourceMgr::ResourceMgr() = default;
ResourceMgr::~ResourceMgr() = default;
ResourceMgr* ResourceMgr::getInstance()
{
	static ResourceMgr instance;
	return &instance;
}

FileBytes ResourceMgr::getLocalFileData(const string& path)
{
	try
	{
		if (const auto data = localFiles.find(path))
			return data;
		return localFiles.load(path, [&path]() -> FileBytes
		{
			// The generation includes path resolution. No cache/map lock is held.
			const auto fullPath = FileUtils::getInstance()->fullPathForFilename(path);
			auto data = make_shared<vector<uint8_t>>();
			return FileUtils::getInstance()->getContents(fullPath, data.get()) == FileUtils::Status::OK ? data : nullptr;
		});
	}
	catch (const bad_alloc&) { return nullptr; }
	catch (const length_error&) { return nullptr; }
}

Buffer* ResourceMgr::loadLocalFileAndCache(const string& path)
{
	try { return bufferView(path, getLocalFileData(path), localBuffers); }
	catch (const bad_alloc&) { return nullptr; }
	catch (const length_error&) { return nullptr; }
}
string ResourceMgr::getStringFromLocalFile(const string& path) { return bytesToString(getLocalFileData(path)); }
bool ResourceMgr::cacheLocalFile(const string& path) { return !!getLocalFileData(path); }

void ResourceMgr::cacheLocalFileAsync(const string& path, const function<void()>& callback)
{
	AsyncTaskPool::getInstance()->enqueue(AsyncTaskPool::TaskType::TASK_IO,
		[callback](void*) { if (callback) callback(); }, nullptr,
		[this, path]() { cacheLocalFile(path); });
}

bool ResourceMgr::isLocalFileCached(const string& path) { return localFiles.contains(path); }
bool ResourceMgr::removeLocalFileCache(const string& path)
{
	localBuffers.erase(path);
	return localFiles.remove(path);
}
void ResourceMgr::clearLocalFileCache()
{
	localBuffers.clear();
	localFiles.clear();
}
vector<string> ResourceMgr::listCachedLocalFiles() { return localFiles.list(); }

size_t ResourceMgr::getFileCacheSize()
{
	size_t total = localFiles.size();
	for (const auto& pack : getPackStates())
		total += pack->loadedFiles.size();
	return total;
}

ResourcePack* ResourceMgr::loadResourcePack(const string& path, const string& password)
{
	if (const auto loaded = getResourcePack(path))
		return loaded;
	const auto pack = ResourcePack::create(path, password);
	if (!pack)
		return nullptr;
	lock_guard<mutex> lock(mut);
	pack->setPriority(static_cast<float>(packs.size()));
	packs.insert(path, pack);
	return pack;
}

bool ResourceMgr::isResourcePackLoaded(const string& path) { return !!getResourcePack(path); }
void ResourceMgr::addResourcePack(ResourcePack* pack, bool override)
{
	if (!pack)
		return;
	lock_guard<mutex> lock(mut);
	if (override || packs.find(pack->getPath()) == packs.end())
		packs.insert(pack->getPath(), pack);
}
bool ResourceMgr::unloadResourcePack(const string& path)
{
	lock_guard<mutex> lock(mut);
	const auto it = packs.find(path);
	if (it == packs.end())
		return false;
	packs.erase(it);
	return true;
}
void ResourceMgr::unloadAllResourcePacks()
{
	lock_guard<mutex> lock(mut);
	packs.clear();
}
ResourcePack* ResourceMgr::getResourcePack(const string& path)
{
	lock_guard<mutex> lock(mut);
	const auto it = packs.find(path);
	return it == packs.end() ? nullptr : it->second;
}
vector<ResourcePack*> ResourceMgr::getResourcePacks()
{
	lock_guard<mutex> lock(mut);
	vector<ResourcePack*> ret;
	for (const auto& pack : packs)
		ret.push_back(pack.second);
	sort(ret.begin(), ret.end(), [](ResourcePack* a, ResourcePack* b) { return a->getPriority() > b->getPriority(); });
	return ret;
}

vector<shared_ptr<ResourcePack::State>> ResourceMgr::getPackStates() const
{
	lock_guard<mutex> lock(mut);
	vector<pair<float, shared_ptr<ResourcePack::State>>> ordered;
	for (const auto& pack : packs)
		ordered.emplace_back(pack.second->getPriority(), pack.second->state);
	// Capture priority once: concurrent setPriority must not change the comparator
	// during sort. Only standard shared ownership leaves the registry lock.
	sort(ordered.begin(), ordered.end(), [](const auto& a, const auto& b) { return a.first > b.first; });
	vector<shared_ptr<ResourcePack::State>> ret;
	ret.reserve(ordered.size());
	for (auto& pack : ordered)
		ret.push_back(std::move(pack.second));
	return ret;
}

bool ResourceMgr::isFileOrDirectoryExist(const string& path) const
{
	if (!path.empty())
		for (const auto& pack : getPackStates())
			if (pack->files.count(path))
				return true;
	return false;
}

vector<string> ResourceMgr::listPackFiles(const string& directory) const
{
	vector<string> ret;
	if (directory.empty())
		return ret;
	auto prefix = directory;
	replace(prefix.begin(), prefix.end(), '\\', '/');
	if (prefix.back() != '/')
		prefix += '/';
	for (const auto& pack : getPackStates())
		for (const auto& file : pack->files)
			if (file.first.compare(0, prefix.size(), prefix) == 0
				&& file.first.find('/', prefix.size()) == string::npos)
				ret.push_back(file.first);
	return ret;
}

FileBytes ResourceMgr::getFileData(const string& path)
{
	try
	{
		for (const auto& pack : getPackStates())
			if (const auto data = pack->load(path))
				return data;
		return getLocalFileData(path);
	}
	catch (const bad_alloc&) { return nullptr; }
	catch (const length_error&) { return nullptr; }
}

io::Result<io::StreamPtr> ResourceMgr::openReadStream(const string& path)
{
	using Output = io::Result<io::StreamPtr>;
	const auto bytes = getFileData(path);
	// The snapshot loader does not distinguish a missing file from other errors.
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
	// Legacy Ref objects are materialized only on the main thread.
	for (const auto& pack : getResourcePacks())
		if (const auto data = pack->loadAndCache(path))
			return data;
	return loadLocalFileAndCache(path);
}
string ResourceMgr::getStringFromFile(const string& path) { return bytesToString(getFileData(path)); }

bool ResourceMgr::extractFile(const string& path, const string& target)
{
	const auto data = getFileData(path);
	if (!data)
		return false;
	// A stream handles empty files and keeps ownership independent of Data::fastSet.
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
