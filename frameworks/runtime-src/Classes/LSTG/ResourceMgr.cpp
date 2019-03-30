#include "ResourceMgr.h"
#include "AppFrame.h"
#include "Utility.h"
#include "unzip/unzip.h"
#include "XFileUtils.h"
#include "LogSystem.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;

////////////////////////////////////////////////////////////////////////////////
/// ResourcePack
////////////////////////////////////////////////////////////////////////////////

ResourcePack::ResourcePack()
{
}

ResourcePack::~ResourcePack()
{
	unzClose(zipFile);
}

bool ResourcePack::init(const std::string& path_, const std::string& passwd)
{
	path = path_;
	password = passwd;
	zlib_filefunc64_def tZlibFileFunc;
	memset(&tZlibFileFunc, 0, sizeof(tZlibFileFunc));
	fill_fopen64_filefunc(&tZlibFileFunc);
	zipFile = unzOpen2_64(FileUtils::getInstance()->getSuitableFOpen(path).c_str(), &tZlibFileFunc);
	if (!zipFile)
	{
		return false;
	}
	loadAllFileInfo();
	return true;
}

void ResourcePack::loadAllFileInfo()
{
	sizeCompr = sizeUcompr = 0;
	int status = unzGoToFirstFile(zipFile);
	while (UNZ_OK == status)
	{
		ZipFile f;
		char zipName[MAX_PATH];
		if (UNZ_OK == unzGetCurrentFileInfo(zipFile, &f.info, zipName, sizeof(zipName), nullptr, 0, nullptr, 0))
		{
			// note that f can be a file or folder
			f.path = zipName;
			f.pos = unzGetOffset64(zipFile);
			// there may be duplicated path in a zip file, use the latter
			if (files.find(f.path) != files.end())
			{
				LWARNING("ResourcePack '%s' has duplicate path '%s'", path.c_str(), f.path.c_str());
			}
			files[f.path] = f;
			sizeCompr += f.info.compressed_size;
			sizeUcompr += f.info.uncompressed_size;
		}
		status = unzGoToNextFile(zipFile);
	}
}

bool ResourcePack::loadFile(const string& fpath, Data* outBuf)
{
	const auto it = files.find(fpath);
	if (it != files.end())
	{
		const char* pwd = password.length() > 0 ? password.c_str() : nullptr;
		if (unzSetOffset64(zipFile, it->second.pos) != UNZ_OK
			|| unzOpenCurrentFilePassword(zipFile, pwd) != UNZ_OK)
		{
			return false;
		}
		try
		{
			const auto unc_size = it->second.info.uncompressed_size;
			auto bytes = (unsigned char*)malloc(sizeof(unsigned char) * unc_size);
			if (unzReadCurrentFile(zipFile, bytes, unc_size) < 0)
			{
				unzCloseCurrentFile(zipFile);
				return false;
			}
			outBuf->fastSet(bytes, unc_size);
		}
		catch (const bad_alloc&)
		{
			unzCloseCurrentFile(zipFile);
			XERROR("OOM");
			return false;
		}
		unzCloseCurrentFile(zipFile);
		return true;
	}
	return false;
}

ResourcePack* ResourcePack::create(const std::string& fullPath, const std::string& password)
{
	auto ret = new (std::nothrow) ResourcePack();
	if (ret && ret->init(fullPath, password))
	{
		ret->autorelease();
		return ret;
	}
	CC_SAFE_DELETE(ret);
	return nullptr;
}

std::string ResourcePack::getPath() const
{
	return path;
}

size_t ResourcePack::getFileCount() const
{
	return files.size();
}

bool ResourcePack::isFileOrDirectoryExist(const std::string& fpath) const
{
	return files.find(fpath) != files.end();
}

uint32_t ResourcePack::getCRC32(const std::string& fpath)
{
	const auto it = files.find(fpath);
	if (it != files.end())
		return it->second.info.crc;
	return 0;
}

uint32_t ResourcePack::getCompressedSize(const std::string& fpath)
{
	const auto it = files.find(fpath);
	if (it != files.end())
		return it->second.info.compressed_size;
	return 0;
}

uint32_t ResourcePack::getUncompressedSize(const std::string& fpath)
{
	const auto it = files.find(fpath);
	if (it != files.end())
		return it->second.info.uncompressed_size;
	return 0;
}

data_shared_ptr ResourcePack::getAndCache(const string& fpath)
{
	lock_guard<mutex> lock(mut);

	const auto it = loadedFiles.find(fpath);
	if (it != loadedFiles.end())
		return it->second;
	auto data = make_shared<Data>();
	if (loadFile(fpath, data.get()))
	{
		loadedFiles[fpath] = data;
		return data;
	}
	return nullptr;
}

std::string ResourcePack::getStringFromFile(const std::string& fpath)
{
	const auto data = getAndCache(fpath);
	if (!data)
		return "";
	return string((const char*)data->getBytes(), (size_t)data->getSize());
}

bool ResourcePack::cacheFile(const std::string& fpath)
{
	return !!getAndCache(fpath);
}

void ResourcePack::cacheFileAsync(const std::string& fpath, const std::function<void()>& callback)
{
	this->retain();
	const auto cb = [this, callback](void*)
	{
		this->release();
		if (callback)
			callback();
	};
	const auto task = [this, fpath]()
	{
		this->getAndCache(fpath);
	};
	AsyncTaskPool::getInstance()->enqueue(
		AsyncTaskPool::TaskType::TASK_IO, cb, nullptr, task);
}

void ResourcePack::cacheAllFiles()
{
	for (auto& f : files)
		getAndCache(f.first);
}

void ResourcePack::cacheAllFilesAsync(const std::function<void()>& callback)
{
	this->retain();
	const auto cb = [this, callback](void*)
	{
		this->release();
		if (callback)
			callback();
	};
	const auto task = [this]()
	{
		this->cacheAllFiles();
	};
	AsyncTaskPool::getInstance()->enqueue(
		AsyncTaskPool::TaskType::TASK_IO, cb, nullptr, task);
}

bool ResourcePack::isFileCached(const std::string& fpath)
{
	lock_guard<mutex> lock(mut);
	return loadedFiles.find(fpath) != loadedFiles.end();
}

bool ResourcePack::removeFileCache(const std::string& fpath)
{
	lock_guard<mutex> lock(mut);
	const auto it = loadedFiles.find(fpath);
	if (it == loadedFiles.end())
		return false;
	loadedFiles.erase(it);
	return true;
}

void ResourcePack::clearFileCache()
{
	lock_guard<mutex> lock(mut);
	loadedFiles.clear();
}

vector<string> ResourcePack::listFiles()
{
	lock_guard<mutex> lock(mut);
	vector<string> ret;
	for (auto& f : files)
		ret.push_back(f.first);
	return ret;
}

vector<string> ResourcePack::listCachedFiles()
{
	lock_guard<mutex> lock(mut);
	vector<string> ret;
	for (auto& f : loadedFiles)
		ret.push_back(f.first);
	return ret;
}

////////////////////////////////////////////////////////////////////////////////
/// ResourceMgr
////////////////////////////////////////////////////////////////////////////////

ResourceMgr::ResourceMgr()
{
}

ResourceMgr::~ResourceMgr()
{
}

ResourceMgr* ResourceMgr::getInstance()
{
	static ResourceMgr ins;
	return &ins;
}

float ResourceMgr::getGlobalImageScaleFactor() const noexcept
{
	return globalImageScaleFactor;
}

void ResourceMgr::setGlobalImageScaleFactor(float v) noexcept
{
	globalImageScaleFactor = v;
}

data_shared_ptr ResourceMgr::getLocalAndCache(const std::string& fpath)
{
	lock_guard<mutex> lock(mut);
	// from cache
	const auto it = localFiles.find(fpath);
	if (it != localFiles.end())
		return it->second;
	// from local path
	try
	{
		Data data;
		const auto path = FileUtils::getInstance()->fullPathForFilename(fpath);
		if (FileUtils::getInstance()->getContents(path, &data) == FileUtils::Status::OK)
		{
			auto d = make_shared<Data>(data);
			localFiles[fpath] = d;
			return d;
		}
	}
	catch (const bad_alloc&)
	{
		XERROR("OOM");
	}
	return nullptr;
}

std::string ResourceMgr::getStringFromLocalFile(const std::string& fpath)
{
	const auto data = getLocalAndCache(fpath);
	if (!data)
		return "";
	return string((const char*)data->getBytes(), (size_t)data->getSize());
}

bool ResourceMgr::cacheLocalFile(const std::string& fpath)
{
	return !!getLocalAndCache(fpath);
}

void ResourceMgr::cacheLocalFileAsync(const std::string& fpath, const std::function<void()>& callback)
{
	const auto cb = [callback](void*)
	{
		if (callback)
			callback();
	};
	const auto task = [this, fpath]()
	{
		this->cacheLocalFile(fpath);
	};
	AsyncTaskPool::getInstance()->enqueue(
		AsyncTaskPool::TaskType::TASK_IO, cb, nullptr, task);
}

bool ResourceMgr::isLocalFileCached(const std::string& fpath)
{
	lock_guard<mutex> lock(mut);
	return localFiles.find(fpath) != localFiles.end();
}

bool ResourceMgr::removeLocalFileCache(const std::string& fpath)
{
	lock_guard<mutex> lock(mut);
	const auto it = localFiles.find(fpath);
	if (it == localFiles.end())
		return false;
	localFiles.erase(it);
	return true;
}

void ResourceMgr::clearLocalFileCache()
{
	lock_guard<mutex> lock(mut);
	localFiles.clear();
}

vector<string> ResourceMgr::listCachedLocalFiles()
{
	lock_guard<mutex> lock(mut);
	vector<string> ret;
	for (auto& it : localFiles)
		ret.push_back(it.first);
	return ret;
}

ResourcePack* ResourceMgr::loadResourcePack(const std::string& fullPath, const std::string& password)
{
	const auto loaded = getResourcePack(fullPath);
	if (loaded)
		return loaded;
	const auto pack = ResourcePack::create(fullPath, password);
	if (!pack)
		return nullptr;
	pack->setPriority(packs.size());
	packs.insert(fullPath, pack);
	return pack;
}

bool ResourceMgr::isResourcePackLoaded(const std::string& packPath)
{
	return !!getResourcePack(packPath);
}

void ResourceMgr::addResourcePack(ResourcePack* pack, bool override)
{
	if (!override && isResourcePackLoaded(pack->getPath()))
		return;
	packs.insert(pack->getPath(), pack);
}

bool ResourceMgr::unloadResourcePack(const std::string& path)
{
	const auto it = packs.find(path);
	if (it == packs.end())
		return false;
	packs.erase(it);
	return true;
}

void ResourceMgr::unloadAllResourcePacks()
{
	packs.clear();
}

ResourcePack* ResourceMgr::getResourcePack(const std::string& packPath)
{
	const auto it = packs.find(packPath);
	if (it != packs.end())
		return it->second;
	return nullptr;
}

vector<ResourcePack*> ResourceMgr::getResourcePacks()
{
	vector<ResourcePack*> ret;
	for (auto& it : packs)
		ret.push_back(it.second);
	// ResourcePack with higher priority will be put at front
	std::sort(ret.begin(), ret.end(),[](ResourcePack* a, ResourcePack* b)
	{
		return a->getPriority() > b->getPriority();
	});
	return ret;
}

bool ResourceMgr::isFileOrDirectoryExist(const std::string& fpath) const
{
	if (fpath.empty())
		return false;
	for (auto& it: packs)
	{
		if (it.second->isFileOrDirectoryExist(fpath))
			return true;
	}
	return false;
}

data_shared_ptr ResourceMgr::getDataFromFile(const string& filePath)
{
	// from packs
	data_shared_ptr data = nullptr;
	// getResourcePacks gives in priority order
	for (auto& it : getResourcePacks())
	{
		const auto d = it->getAndCache(filePath);
		if (d)
			return d;
	}
	// from cache or local path
	return getLocalAndCache(filePath);
}

Data ResourceMgr::getDataCopyFromFile(const string& filePath)
{
	Data data;
	const auto d = getDataFromFile(filePath);
	if (d)
		data.copy(d->getBytes(), d->getSize());
	return data;
}

bool ResourceMgr::extractFile(const string& filePath, const string& targetPath)
{
	const auto data = getDataFromFile(filePath);
	if (!data)
		return false;
	if (!FileUtils::getInstance()->writeDataToFile(*data, targetPath))
		return false;
	return true;
}

void ResourceMgr::clear()
{
	globalImageScaleFactor = 1.f;
	unloadAllResourcePacks();
	clearLocalFileCache();
}
