#include "lua_ResourceMgr_auto.hpp"
#include "ResourceMgr.h"

int lua_lstg_ResourcePack_cacheAllFiles(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:cacheAllFiles");
	LUA_TRY_INVOKE(0, &lstg::ResourcePack::cacheAllFiles);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourcePack_cacheAllFilesAsync(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:cacheAllFilesAsync");
	LUA_TRY_INVOKE(1, static_cast<void(lstg::ResourcePack::*)(const std::function<void ()>&)>(&lstg::ResourcePack::cacheAllFilesAsync));
	LUA_TRY_INVOKE(0, [](lstg::ResourcePack* obj){{return obj->cacheAllFilesAsync();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_lstg_ResourcePack_cacheFile(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:cacheFile");
	LUA_TRY_INVOKE_R(1, &lstg::ResourcePack::cacheFile);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourcePack_cacheFileAsync(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:cacheFileAsync");
	LUA_TRY_INVOKE(2, static_cast<void(lstg::ResourcePack::*)(const std::string&, const std::function<void ()>&)>(&lstg::ResourcePack::cacheFileAsync));
	LUA_TRY_INVOKE(1, [](lstg::ResourcePack* obj, const std::string& arg0){{return obj->cacheFileAsync(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_ResourcePack_clearFileCache(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:clearFileCache");
	LUA_TRY_INVOKE(0, &lstg::ResourcePack::clearFileCache);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourcePack_getCRC32(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:getCRC32");
	LUA_TRY_INVOKE_R(1, &lstg::ResourcePack::getCRC32);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourcePack_getCompressedSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:getCompressedSize");
	LUA_TRY_INVOKE_R(1, &lstg::ResourcePack::getCompressedSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourcePack_getFileCacheSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:getFileCacheSize");
	LUA_TRY_INVOKE_R(0, &lstg::ResourcePack::getFileCacheSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourcePack_getFileCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:getFileCount");
	LUA_TRY_INVOKE_R(0, &lstg::ResourcePack::getFileCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourcePack_getPath(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:getPath");
	LUA_TRY_INVOKE_R(0, &lstg::ResourcePack::getPath);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourcePack_getPriority(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:getPriority");
	LUA_TRY_INVOKE_R(0, &lstg::ResourcePack::getPriority);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourcePack_getStringFromFile(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:getStringFromFile");
	LUA_TRY_INVOKE_R(1, &lstg::ResourcePack::getStringFromFile);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourcePack_getUncompressedSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:getUncompressedSize");
	LUA_TRY_INVOKE_R(1, &lstg::ResourcePack::getUncompressedSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourcePack_isFileCached(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:isFileCached");
	LUA_TRY_INVOKE_R(1, &lstg::ResourcePack::isFileCached);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourcePack_isFileOrDirectoryExist(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:isFileOrDirectoryExist");
	LUA_TRY_INVOKE_R(1, &lstg::ResourcePack::isFileOrDirectoryExist);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourcePack_listCachedFiles(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:listCachedFiles");
	LUA_TRY_INVOKE_R(0, &lstg::ResourcePack::listCachedFiles);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourcePack_listFiles(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:listFiles");
	LUA_TRY_INVOKE_R(0, &lstg::ResourcePack::listFiles);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourcePack_loadAndCache(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:loadAndCache");
	LUA_TRY_INVOKE_R(1, &lstg::ResourcePack::loadAndCache);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourcePack_removeFileCache(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:removeFileCache");
	LUA_TRY_INVOKE_R(1, &lstg::ResourcePack::removeFileCache);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourcePack_setPriority(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:setPriority");
	LUA_TRY_INVOKE(1, &lstg::ResourcePack::setPriority);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourcePack_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResourcePack", "lstg.ResourcePack:create");
	LUA_TRY_INVOKE_R(2, &lstg::ResourcePack::create);
	LUA_SINVOKE_FOOTER("2");
}
int luaReg_ResourceMgr_lstgResourcePack(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ResourcePack, "ResourcePack", "lstg.ResourcePack",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("cacheAllFiles", lua_lstg_ResourcePack_cacheAllFiles);
	LUA_METHOD("cacheAllFilesAsync", lua_lstg_ResourcePack_cacheAllFilesAsync);
	LUA_METHOD("cacheFile", lua_lstg_ResourcePack_cacheFile);
	LUA_METHOD("cacheFileAsync", lua_lstg_ResourcePack_cacheFileAsync);
	LUA_METHOD("clearFileCache", lua_lstg_ResourcePack_clearFileCache);
	LUA_METHOD("getCRC32", lua_lstg_ResourcePack_getCRC32);
	LUA_METHOD("getCompressedSize", lua_lstg_ResourcePack_getCompressedSize);
	LUA_METHOD("getFileCacheSize", lua_lstg_ResourcePack_getFileCacheSize);
	LUA_METHOD("getFileCount", lua_lstg_ResourcePack_getFileCount);
	LUA_METHOD("getPath", lua_lstg_ResourcePack_getPath);
	LUA_METHOD("getPriority", lua_lstg_ResourcePack_getPriority);
	LUA_METHOD("getStringFromFile", lua_lstg_ResourcePack_getStringFromFile);
	LUA_METHOD("getUncompressedSize", lua_lstg_ResourcePack_getUncompressedSize);
	LUA_METHOD("isFileCached", lua_lstg_ResourcePack_isFileCached);
	LUA_METHOD("isFileOrDirectoryExist", lua_lstg_ResourcePack_isFileOrDirectoryExist);
	LUA_METHOD("listCachedFiles", lua_lstg_ResourcePack_listCachedFiles);
	LUA_METHOD("listFiles", lua_lstg_ResourcePack_listFiles);
	LUA_METHOD("loadAndCache", lua_lstg_ResourcePack_loadAndCache);
	LUA_METHOD("removeFileCache", lua_lstg_ResourcePack_removeFileCache);
	LUA_METHOD("setPriority", lua_lstg_ResourcePack_setPriority);
	LUA_METHOD("create", lua_lstg_ResourcePack_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_lstg_ResourceMgr_addResourcePack(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:addResourcePack");
	LUA_TRY_INVOKE(2, &lstg::ResourceMgr::addResourcePack);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ResourceMgr_cacheLocalFile(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:cacheLocalFile");
	LUA_TRY_INVOKE_R(1, &lstg::ResourceMgr::cacheLocalFile);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourceMgr_cacheLocalFileAsync(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:cacheLocalFileAsync");
	LUA_TRY_INVOKE(2, static_cast<void(lstg::ResourceMgr::*)(const std::string&, const std::function<void ()>&)>(&lstg::ResourceMgr::cacheLocalFileAsync));
	LUA_TRY_INVOKE(1, [](lstg::ResourceMgr* obj, const std::string& arg0){{return obj->cacheLocalFileAsync(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_ResourceMgr_clear(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:clear");
	LUA_TRY_INVOKE(0, &lstg::ResourceMgr::clear);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourceMgr_clearLocalFileCache(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:clearLocalFileCache");
	LUA_TRY_INVOKE(0, &lstg::ResourceMgr::clearLocalFileCache);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourceMgr_extractFile(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:extractFile");
	LUA_TRY_INVOKE_R(2, &lstg::ResourceMgr::extractFile);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ResourceMgr_getBufferFromFile(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:getBufferFromFile");
	LUA_TRY_INVOKE_R(1, &lstg::ResourceMgr::getBufferFromFile);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourceMgr_getFileCacheSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:getFileCacheSize");
	LUA_TRY_INVOKE_R(0, &lstg::ResourceMgr::getFileCacheSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourceMgr_getResourcePack(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:getResourcePack");
	LUA_TRY_INVOKE_R(1, &lstg::ResourceMgr::getResourcePack);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourceMgr_getResourcePacks(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:getResourcePacks");
	LUA_TRY_INVOKE_R(0, &lstg::ResourceMgr::getResourcePacks);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourceMgr_getStringFromFile(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:getStringFromFile");
	LUA_TRY_INVOKE_R(1, &lstg::ResourceMgr::getStringFromFile);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourceMgr_getStringFromLocalFile(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:getStringFromLocalFile");
	LUA_TRY_INVOKE_R(1, &lstg::ResourceMgr::getStringFromLocalFile);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourceMgr_isFileOrDirectoryExist(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:isFileOrDirectoryExist");
	LUA_TRY_INVOKE_R(1, &lstg::ResourceMgr::isFileOrDirectoryExist);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourceMgr_isLocalFileCached(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:isLocalFileCached");
	LUA_TRY_INVOKE_R(1, &lstg::ResourceMgr::isLocalFileCached);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourceMgr_isResourcePackLoaded(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:isResourcePackLoaded");
	LUA_TRY_INVOKE_R(1, &lstg::ResourceMgr::isResourcePackLoaded);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourceMgr_listCachedLocalFiles(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:listCachedLocalFiles");
	LUA_TRY_INVOKE_R(0, &lstg::ResourceMgr::listCachedLocalFiles);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourceMgr_loadLocalFileAndCache(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:loadLocalFileAndCache");
	LUA_TRY_INVOKE_R(1, &lstg::ResourceMgr::loadLocalFileAndCache);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourceMgr_loadResourcePack(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:loadResourcePack");
	LUA_TRY_INVOKE_R(2, &lstg::ResourceMgr::loadResourcePack);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ResourceMgr_removeLocalFileCache(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:removeLocalFileCache");
	LUA_TRY_INVOKE_R(1, &lstg::ResourceMgr::removeLocalFileCache);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourceMgr_unloadAllResourcePacks(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:unloadAllResourcePacks");
	LUA_TRY_INVOKE(0, &lstg::ResourceMgr::unloadAllResourcePacks);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ResourceMgr_unloadResourcePack(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:unloadResourcePack");
	LUA_TRY_INVOKE_R(1, &lstg::ResourceMgr::unloadResourcePack);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ResourceMgr_getInstance(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResourceMgr", "lstg.ResourceMgr:getInstance");
	LUA_TRY_INVOKE_R(0, &lstg::ResourceMgr::getInstance);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_ResourceMgr_lstgResourceMgr(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF(lstg::ResourceMgr, "ResourceMgr", "lstg.ResourceMgr",
		nullptr, nullptr);
	LUA_METHOD("addResourcePack", lua_lstg_ResourceMgr_addResourcePack);
	LUA_METHOD("cacheLocalFile", lua_lstg_ResourceMgr_cacheLocalFile);
	LUA_METHOD("cacheLocalFileAsync", lua_lstg_ResourceMgr_cacheLocalFileAsync);
	LUA_METHOD("clear", lua_lstg_ResourceMgr_clear);
	LUA_METHOD("clearLocalFileCache", lua_lstg_ResourceMgr_clearLocalFileCache);
	LUA_METHOD("extractFile", lua_lstg_ResourceMgr_extractFile);
	LUA_METHOD("getBufferFromFile", lua_lstg_ResourceMgr_getBufferFromFile);
	LUA_METHOD("getFileCacheSize", lua_lstg_ResourceMgr_getFileCacheSize);
	LUA_METHOD("getResourcePack", lua_lstg_ResourceMgr_getResourcePack);
	LUA_METHOD("getResourcePacks", lua_lstg_ResourceMgr_getResourcePacks);
	LUA_METHOD("getStringFromFile", lua_lstg_ResourceMgr_getStringFromFile);
	LUA_METHOD("getStringFromLocalFile", lua_lstg_ResourceMgr_getStringFromLocalFile);
	LUA_METHOD("isFileOrDirectoryExist", lua_lstg_ResourceMgr_isFileOrDirectoryExist);
	LUA_METHOD("isLocalFileCached", lua_lstg_ResourceMgr_isLocalFileCached);
	LUA_METHOD("isResourcePackLoaded", lua_lstg_ResourceMgr_isResourcePackLoaded);
	LUA_METHOD("listCachedLocalFiles", lua_lstg_ResourceMgr_listCachedLocalFiles);
	LUA_METHOD("loadLocalFileAndCache", lua_lstg_ResourceMgr_loadLocalFileAndCache);
	LUA_METHOD("loadResourcePack", lua_lstg_ResourceMgr_loadResourcePack);
	LUA_METHOD("removeLocalFileCache", lua_lstg_ResourceMgr_removeLocalFileCache);
	LUA_METHOD("unloadAllResourcePacks", lua_lstg_ResourceMgr_unloadAllResourcePacks);
	LUA_METHOD("unloadResourcePack", lua_lstg_ResourceMgr_unloadResourcePack);
	LUA_METHOD("getInstance", lua_lstg_ResourceMgr_getInstance);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
