#pragma once
#include "Global.h"
#include "unzip/unzip.h"
#include "Resource/GameResources.h"
#include "../Classes/XBuffer.h"
#include "ResourceFileCache.h"

#define LRES (*lstg::ResourceMgr::getInstance())

class XFileUtils;

namespace lstg
{
	/**
	 * A ResourcePack manages a zip file.
	 * After reading a file from ResourcePack, it will cache the data in memory.
	 * You have to manually invoke `removeFileCache` or `clearFileCache` if you want to save memory.
	 */
	class ResourcePack : public cocos2d::Ref
	{
		// Workers retain only State, never this Ref or a Buffer/autorelease object.
		struct State;
		std::shared_ptr<State> state;
		std::unordered_map<std::string, std::pair<FileBytes, cocos2d::RefPtr<Buffer>>> bufferViews;
		friend class ResourceMgr;

		bool init(const std::string& path_, const std::string& passwd);

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
		// Legacy Ref/Buffer and pack registry APIs are main-thread only.
		Buffer* loadAndCache(const std::string& fpath);
		// Native snapshot API; safe across cache eviction and pack unloading.
		FileBytes getFileData(const std::string& fpath);
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
		size_t getFileCacheSize();

		std::vector<std::string> listFiles();
		std::vector<std::string> listCachedFiles();

		float getPriority() const;
		void setPriority(float v);

	private:
		ResourcePack();
		~ResourcePack() override;
	};

	/**
	 * ResourceMgr is a singleton class that manages ResourcePacks and cache local files.
	 * Like ResourcePack, you have to manully release caches of local files.
	 * It is connected to FileUtils (by XFileUtils class) so that cocos engine can load files from here.
	 */
	class ResourceMgr
	{
		cocos2d::Map<std::string, ResourcePack*> packs;
		mutable std::mutex mut;
		ResourceFileCache localFiles;
		// Buffer views are legacy main-thread API objects, separate from worker data.
		std::unordered_map<std::string, std::pair<FileBytes, cocos2d::RefPtr<Buffer>>> localBuffers;
		std::vector<std::shared_ptr<ResourcePack::State>> getPackStates() const;
		FileBytes getLocalFileData(const std::string& fpath);
		std::vector<std::string> listPackFiles(const std::string& directory) const;
		friend class ::XFileUtils;

		ResourceMgr();
		~ResourceMgr();
	public:

		static ResourceMgr* getInstance();

		// Buffer views and cache/registry mutation are main-thread API operations.
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
		size_t getFileCacheSize();

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
		// C++ readers must hold this snapshot through consumption of its bytes.
		FileBytes getFileData(const std::string& filePath);

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
