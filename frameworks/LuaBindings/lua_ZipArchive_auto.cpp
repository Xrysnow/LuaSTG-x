#include "lua_ZipArchive_auto.hpp"
#include "XZipArchive.h"

int luaReg_ZipArchive_lstgZipArchiveOpenMode(lua_State* lua_S)
{
	LUA_ENUM_DEF("OpenMode");
	LUA_ENUM_ENTRY("NotOpen", lstg::ZipArchive::OpenMode::NotOpen);
	LUA_ENUM_ENTRY("ReadOnly", lstg::ZipArchive::OpenMode::ReadOnly);
	LUA_ENUM_ENTRY("Write", lstg::ZipArchive::OpenMode::Write);
	LUA_ENUM_ENTRY("New", lstg::ZipArchive::OpenMode::New);
	LUA_ENUM_END();
	return 0;
}
int luaReg_ZipArchive_lstgZipArchiveState(lua_State* lua_S)
{
	LUA_ENUM_DEF("State");
	LUA_ENUM_ENTRY("Original", lstg::ZipArchive::State::Original);
	LUA_ENUM_ENTRY("Current", lstg::ZipArchive::State::Current);
	LUA_ENUM_END();
	return 0;
}
int luaReg_ZipArchive_lstgZipArchiveEncryption(lua_State* lua_S)
{
	LUA_ENUM_DEF("Encryption");
	LUA_ENUM_ENTRY("None", lstg::ZipArchive::Encryption::None);
	LUA_ENUM_ENTRY("Aes128", lstg::ZipArchive::Encryption::Aes128);
	LUA_ENUM_ENTRY("Aes192", lstg::ZipArchive::Encryption::Aes192);
	LUA_ENUM_ENTRY("Aes256", lstg::ZipArchive::Encryption::Aes256);
	LUA_ENUM_ENTRY("TradPkware", lstg::ZipArchive::Encryption::TradPkware);
	LUA_ENUM_END();
	return 0;
}
int lua_lstg_ZipArchive_addData(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:addData");
	LUA_TRY_INVOKE_R(2, &lstg::ZipArchive::addData);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ZipArchive_addEntry(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:addEntry");
	LUA_TRY_INVOKE_R(1, &lstg::ZipArchive::addEntry);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ZipArchive_addFile(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:addFile");
	LUA_TRY_INVOKE_R(2, &lstg::ZipArchive::addFile);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ZipArchive_addString(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:addString");
	LUA_TRY_INVOKE_R(2, &lstg::ZipArchive::addString);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ZipArchive_close(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:close");
	LUA_TRY_INVOKE_R(0, &lstg::ZipArchive::close);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ZipArchive_deleteEntry(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:deleteEntry");
	LUA_TRY_INVOKE_R(1, &lstg::ZipArchive::deleteEntry);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ZipArchive_discard(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:discard");
	LUA_TRY_INVOKE(0, &lstg::ZipArchive::discard);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ZipArchive_extractEntry(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:extractEntry");
	LUA_TRY_INVOKE_R(3, static_cast<bool(lstg::ZipArchive::*)(const std::string&, const std::string&, lstg::ZipArchive::State)>(&lstg::ZipArchive::extractEntry));
	LUA_TRY_INVOKE_R(2, [](lstg::ZipArchive* obj, const std::string& arg0,const std::string& arg1){{return obj->extractEntry(arg0,arg1);}});
	LUA_INVOKE_FOOTER("2,3");
}
int lua_lstg_ZipArchive_getComment(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:getComment");
	LUA_TRY_INVOKE_R(1, static_cast<std::basic_string<char>(lstg::ZipArchive::*)(lstg::ZipArchive::State)const>(&lstg::ZipArchive::getComment));
	LUA_TRY_INVOKE_R(0, [](lstg::ZipArchive* obj){{return obj->getComment();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_lstg_ZipArchive_getEntries(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:getEntries");
	LUA_TRY_INVOKE_R(1, static_cast<std::vector<std::basic_string<char>>(lstg::ZipArchive::*)(lstg::ZipArchive::State)const>(&lstg::ZipArchive::getEntries));
	LUA_TRY_INVOKE_R(0, [](lstg::ZipArchive* obj){{return obj->getEntries();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_lstg_ZipArchive_getEntryByIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:getEntryByIndex");
	LUA_TRY_INVOKE_R(2, static_cast<std::basic_string<char>(lstg::ZipArchive::*)(int64_t, lstg::ZipArchive::State)const>(&lstg::ZipArchive::getEntryByIndex));
	LUA_TRY_INVOKE_R(1, [](lstg::ZipArchive* obj, int64_t arg0){{return obj->getEntryByIndex(std::move(arg0));}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_ZipArchive_getEntryComment(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:getEntryComment");
	LUA_TRY_INVOKE_R(2, static_cast<std::basic_string<char>(lstg::ZipArchive::*)(const std::string&, lstg::ZipArchive::State)const>(&lstg::ZipArchive::getEntryComment));
	LUA_TRY_INVOKE_R(1, [](lstg::ZipArchive* obj, const std::string& arg0){{return obj->getEntryComment(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_ZipArchive_getEntryCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:getEntryCount");
	LUA_TRY_INVOKE_R(1, static_cast<int64_t(lstg::ZipArchive::*)(lstg::ZipArchive::State)const>(&lstg::ZipArchive::getEntryCount));
	LUA_TRY_INVOKE_R(0, [](lstg::ZipArchive* obj){{return obj->getEntryCount();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_lstg_ZipArchive_getEntryInfo(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:getEntryInfo");
	LUA_TRY_INVOKE_R(2, static_cast<lstg::ZipArchive::ZipEntryInfo(lstg::ZipArchive::*)(const std::string&, lstg::ZipArchive::State)>(&lstg::ZipArchive::getEntryInfo));
	LUA_TRY_INVOKE_R(1, [](lstg::ZipArchive* obj, const std::string& arg0){{return obj->getEntryInfo(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_ZipArchive_getMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:getMode");
	LUA_TRY_INVOKE_R(0, &lstg::ZipArchive::getMode);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ZipArchive_hasEntry(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:hasEntry");
	LUA_TRY_INVOKE_R(4, static_cast<bool(lstg::ZipArchive::*)(const std::string&, bool, bool, lstg::ZipArchive::State)const>(&lstg::ZipArchive::hasEntry));
	LUA_TRY_INVOKE_R(3, [](lstg::ZipArchive* obj, const std::string& arg0,bool arg1,bool arg2){{return obj->hasEntry(arg0,std::move(arg1),std::move(arg2));}});
	LUA_TRY_INVOKE_R(2, [](lstg::ZipArchive* obj, const std::string& arg0,bool arg1){{return obj->hasEntry(arg0,std::move(arg1));}});
	LUA_TRY_INVOKE_R(1, [](lstg::ZipArchive* obj, const std::string& arg0){{return obj->hasEntry(arg0);}});
	LUA_INVOKE_FOOTER("1,2,3,4");
}
int lua_lstg_ZipArchive_isEncrypted(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:isEncrypted");
	LUA_TRY_INVOKE_R(0, &lstg::ZipArchive::isEncrypted);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ZipArchive_isEntryCompressionEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:isEntryCompressionEnabled");
	LUA_TRY_INVOKE_R(2, static_cast<bool(lstg::ZipArchive::*)(const std::string&, lstg::ZipArchive::State)const>(&lstg::ZipArchive::isEntryCompressionEnabled));
	LUA_TRY_INVOKE_R(1, [](lstg::ZipArchive* obj, const std::string& arg0){{return obj->isEntryCompressionEnabled(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_ZipArchive_isMutable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:isMutable");
	LUA_TRY_INVOKE_R(0, &lstg::ZipArchive::isMutable);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ZipArchive_isOpen(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:isOpen");
	LUA_TRY_INVOKE_R(0, &lstg::ZipArchive::isOpen);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ZipArchive_open(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:open");
	LUA_TRY_INVOKE_R(2, static_cast<bool(lstg::ZipArchive::*)(lstg::ZipArchive::OpenMode, bool)>(&lstg::ZipArchive::open));
	LUA_TRY_INVOKE_R(1, [](lstg::ZipArchive* obj, lstg::ZipArchive::OpenMode arg0){{return obj->open(std::move(arg0));}});
	LUA_TRY_INVOKE_R(0, [](lstg::ZipArchive* obj){{return obj->open();}});
	LUA_INVOKE_FOOTER("0,1,2");
}
int lua_lstg_ZipArchive_readEntry(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:readEntry");
	LUA_TRY_INVOKE_R(2, static_cast<lstg::Buffer*(lstg::ZipArchive::*)(const std::string&, lstg::ZipArchive::State)>(&lstg::ZipArchive::readEntry));
	LUA_TRY_INVOKE_R(1, [](lstg::ZipArchive* obj, const std::string& arg0){{return obj->readEntry(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_ZipArchive_removeComment(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:removeComment");
	LUA_TRY_INVOKE_R(0, &lstg::ZipArchive::removeComment);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ZipArchive_renameEntry(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:renameEntry");
	LUA_TRY_INVOKE_R(2, &lstg::ZipArchive::renameEntry);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_ZipArchive_setComment(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:setComment");
	LUA_TRY_INVOKE_R(1, &lstg::ZipArchive::setComment);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_ZipArchive_setEntryComment(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:setEntryComment");
	LUA_TRY_INVOKE_R(3, static_cast<bool(lstg::ZipArchive::*)(const std::string&, const std::string&, lstg::ZipArchive::State)const>(&lstg::ZipArchive::setEntryComment));
	LUA_TRY_INVOKE_R(2, [](lstg::ZipArchive* obj, const std::string& arg0,const std::string& arg1){{return obj->setEntryComment(arg0,arg1);}});
	LUA_INVOKE_FOOTER("2,3");
}
int lua_lstg_ZipArchive_setEntryCompressionEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:setEntryCompressionEnabled");
	LUA_TRY_INVOKE_R(3, static_cast<bool(lstg::ZipArchive::*)(const std::string&, bool, lstg::ZipArchive::State)const>(&lstg::ZipArchive::setEntryCompressionEnabled));
	LUA_TRY_INVOKE_R(2, [](lstg::ZipArchive* obj, const std::string& arg0,bool arg1){{return obj->setEntryCompressionEnabled(arg0,std::move(arg1));}});
	LUA_INVOKE_FOOTER("2,3");
}
int lua_lstg_ZipArchive_unlink(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:unlink");
	LUA_TRY_INVOKE_R(0, &lstg::ZipArchive::unlink);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_ZipArchive_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:create");
	LUA_TRY_INVOKE_R(3, static_cast<lstg::ZipArchive*(*)(const std::string&, const std::string&, lstg::ZipArchive::Encryption)>(&lstg::ZipArchive::create));
	LUA_TRY_INVOKE_R(2, [](const std::string& arg0,const std::string& arg1){{return lstg::ZipArchive::create(arg0,arg1);}});
	LUA_TRY_INVOKE_R(1, [](const std::string& arg0){{return lstg::ZipArchive::create(arg0);}});
	LUA_SINVOKE_FOOTER("1,2,3");
}
int lua_lstg_ZipArchive_createFromBuffer(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ZipArchive", "lstg.ZipArchive:createFromBuffer");
	LUA_TRY_INVOKE_R(3, static_cast<lstg::ZipArchive*(*)(lstg::Buffer*, lstg::ZipArchive::OpenMode, bool)>(&lstg::ZipArchive::createFromBuffer));
	LUA_TRY_INVOKE_R(2, [](lstg::Buffer* arg0,lstg::ZipArchive::OpenMode arg1){{return lstg::ZipArchive::createFromBuffer(arg0,std::move(arg1));}});
	LUA_TRY_INVOKE_R(1, [](lstg::Buffer* arg0){{return lstg::ZipArchive::createFromBuffer(arg0);}});
	LUA_SINVOKE_FOOTER("1,2,3");
}
int luaReg_ZipArchive_lstgZipArchive(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::ZipArchive, "ZipArchive", "lstg.ZipArchive",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("addData", lua_lstg_ZipArchive_addData);
	LUA_METHOD("addEntry", lua_lstg_ZipArchive_addEntry);
	LUA_METHOD("addFile", lua_lstg_ZipArchive_addFile);
	LUA_METHOD("addString", lua_lstg_ZipArchive_addString);
	LUA_METHOD("close", lua_lstg_ZipArchive_close);
	LUA_METHOD("deleteEntry", lua_lstg_ZipArchive_deleteEntry);
	LUA_METHOD("discard", lua_lstg_ZipArchive_discard);
	LUA_METHOD("extractEntry", lua_lstg_ZipArchive_extractEntry);
	LUA_METHOD("getComment", lua_lstg_ZipArchive_getComment);
	LUA_METHOD("getEntries", lua_lstg_ZipArchive_getEntries);
	LUA_METHOD("getEntryByIndex", lua_lstg_ZipArchive_getEntryByIndex);
	LUA_METHOD("getEntryComment", lua_lstg_ZipArchive_getEntryComment);
	LUA_METHOD("getEntryCount", lua_lstg_ZipArchive_getEntryCount);
	LUA_METHOD("getEntryInfo", lua_lstg_ZipArchive_getEntryInfo);
	LUA_METHOD("getMode", lua_lstg_ZipArchive_getMode);
	LUA_METHOD("hasEntry", lua_lstg_ZipArchive_hasEntry);
	LUA_METHOD("isEncrypted", lua_lstg_ZipArchive_isEncrypted);
	LUA_METHOD("isEntryCompressionEnabled", lua_lstg_ZipArchive_isEntryCompressionEnabled);
	LUA_METHOD("isMutable", lua_lstg_ZipArchive_isMutable);
	LUA_METHOD("isOpen", lua_lstg_ZipArchive_isOpen);
	LUA_METHOD("open", lua_lstg_ZipArchive_open);
	LUA_METHOD("readEntry", lua_lstg_ZipArchive_readEntry);
	LUA_METHOD("removeComment", lua_lstg_ZipArchive_removeComment);
	LUA_METHOD("renameEntry", lua_lstg_ZipArchive_renameEntry);
	LUA_METHOD("setComment", lua_lstg_ZipArchive_setComment);
	LUA_METHOD("setEntryComment", lua_lstg_ZipArchive_setEntryComment);
	LUA_METHOD("setEntryCompressionEnabled", lua_lstg_ZipArchive_setEntryCompressionEnabled);
	LUA_METHOD("unlink", lua_lstg_ZipArchive_unlink);
	LUA_METHOD("create", lua_lstg_ZipArchive_create);
	LUA_METHOD("createFromBuffer", lua_lstg_ZipArchive_createFromBuffer);
	luaReg_ZipArchive_lstgZipArchiveEncryption(lua_S);
	luaReg_ZipArchive_lstgZipArchiveOpenMode(lua_S);
	luaReg_ZipArchive_lstgZipArchiveState(lua_S);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
