#include "lua_FileDialog_auto.hpp"
#include "XFileDialog.h"

int lua_lstg_FileDialog_getLastError(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.FileDialog", "lstg.FileDialog:getLastError");
	LUA_TRY_INVOKE_R(0, &lstg::FileDialog::getLastError);
	LUA_SINVOKE_FOOTER("0");
}
int lua_lstg_FileDialog_open(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.FileDialog", "lstg.FileDialog:open");
	LUA_TRY_INVOKE_R(2, &lstg::FileDialog::open);
	LUA_SINVOKE_FOOTER("2");
}
int lua_lstg_FileDialog_openMultiple(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.FileDialog", "lstg.FileDialog:openMultiple");
	LUA_TRY_INVOKE_R(2, &lstg::FileDialog::openMultiple);
	LUA_SINVOKE_FOOTER("2");
}
int lua_lstg_FileDialog_pickFolder(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.FileDialog", "lstg.FileDialog:pickFolder");
	LUA_TRY_INVOKE_R(1, &lstg::FileDialog::pickFolder);
	LUA_SINVOKE_FOOTER("1");
}
int lua_lstg_FileDialog_save(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.FileDialog", "lstg.FileDialog:save");
	LUA_TRY_INVOKE_R(2, &lstg::FileDialog::save);
	LUA_SINVOKE_FOOTER("2");
}
int luaReg_FileDialog_lstgFileDialog(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF(lstg::FileDialog, "FileDialog", "lstg.FileDialog",
		nullptr, nullptr);
	LUA_METHOD("getLastError", lua_lstg_FileDialog_getLastError);
	LUA_METHOD("open", lua_lstg_FileDialog_open);
	LUA_METHOD("openMultiple", lua_lstg_FileDialog_openMultiple);
	LUA_METHOD("pickFolder", lua_lstg_FileDialog_pickFolder);
	LUA_METHOD("save", lua_lstg_FileDialog_save);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
