#pragma once
#include "Global.h"
#include "unzip/unzip.h"
#include "Resource/GameResources.h"
#include "../Classes/XBuffer.h"

#define LRES (*lstg::ResourceMgr::getInstance())

namespace lstg
{
	/**
	 * A ResourcePack manages a zip file.
	 * After reading a file from ResourcePack, it will cache the data in memory.
	 * You have to manually invoke `removeFileCache` or `clearFileCache` if you want to save memory.
	 */
	class ResourcePack : public cocos2d::Ref
	{
		struct ZipFile
		{
			unz_file_info info;
			std::string path;
			int64_t pos;
		};
	private:
		std::string path;
		std::string password;
		std::mutex mut;
		float priority = 0.f;

		unzFile zipFile = nullptr;
		uint64_t sizeCompr = 0;
		uint64_t sizeUcompr = 0;

		std::unordered_map<std::string, ZipFile> files;
		cocos2d::Map<std::string, Buffer*> loadedFiles;

		bool init(const std::string& path_, const std::string& passwd);
		void loadAllFileInfo();
		Buffer* loadFile(const std::string& fpath);

	public:

		static ResourcePack* create(const std::string& fullPath, const std::string& password);

		std::string getPath() const;
		size_t getFileCount() const;
		bool isFileOrDirectoryExist(const std::string& fpath) const;
		//
		uint32_t getCRC32(const std::string& fpath);
		uint32_t getCompressedSize(const std::string& fpath);
		uint32_t getUncompressedSize(const std::string& fpath);
		//
		Buffer* loadAndCache(const std::string& fpath);
		std::string getStringFromFile(const std::string& fpath);
		//
		bool cacheFile(const std::string& fpath);
		void cacheFileAsync(
			const std::string& fpath,
			const std::function<void()>& callback = nullptr);
		void cacheAllFiles();
		void cacheAllFilesAsync(
			const std::function<void()>& callback = nullptr);

		bool isFileCached(const std::string& fpath);
		bool removeFileCache(const std::string& fpath);
		void clearFileCache();

		std::vector<std::string> listFiles();
		std::vector<std::string> listCachedFiles();

		float getPriority() const { return priority; }
		void setPriority(float v) { priority = v; }

	private:
		ResourcePack();
		virtual ~ResourcePack();
	};

	/**
	 * ResourceMgr is a singleton class that manages ResourcePacks and cache local files.
	 * Like ResourcePack, you have to manully release caches of local files.
	 * It is connected to FileUtils (by XFileUtils class) so that cocos engine can load files from here.
	 */
	class ResourceMgr
	{
		cocos2d::Map<std::string, ResourcePack*> packs;
		std::mutex mut;
		cocos2d::Map<std::string, Buffer*> localFiles;

		ResourceMgr();
		~ResourceMgr();
	public:

		static ResourceMgr* getInstance();

		Buffer* loadLocalFileAndCache(const std::string& fpath);
		std::string getStringFromLocalFile(const std::string& fpath);

		bool cacheLocalFile(const std::string& fpath);
		void cacheLocalFileAsync(
			const std::string& fpath,
			const std::function<void()>& callback = nullptr);

		bool isLocalFileCached(const std::string& fpath);
		bool removeLocalFileCache(const std::string& fpath);
		void clearLocalFileCache();
		std::vector<std::string> listCachedLocalFiles();

		ResourcePack* loadResourcePack(const std::string& fullPath, const std::string& password);
		bool isResourcePackLoaded(const std::string& packPath);
		void addResourcePack(ResourcePack* pack, bool override);
		bool unloadResourcePack(const std::string& path);
		void unloadAllResourcePacks();
		ResourcePack* getResourcePack(const std::string& packPath);
		/** Gives a vector of all ResourcePacks in priority order (higher in front). */
		std::vector<ResourcePack*> getResourcePacks();

		//

		/** Returns if the file path exists in any ResourcePack. */
		bool isFileOrDirectoryExist(const std::string& fpath) const;

		//
		Buffer* getBufferFromFile(const std::string& filePath);

		std::string getStringFromFile(const std::string& filePath);

		/**
		 * Extract data in pack into a file
		 *
		 * @param filePath The file path
		 * @param targetPath The full path to the file you want to save data
		 * @return If it's successed
		 */
		bool extractFile(const std::string& filePath, const std::string& targetPath);
		/** Unload all ResourcePacks and clear local file caches. */
		void clear();
	};
}
