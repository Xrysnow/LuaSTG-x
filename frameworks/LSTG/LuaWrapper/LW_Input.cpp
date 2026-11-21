#include "LW_Input.h"
#include "AppFrame.h"
#include "scripting/lua-bindings/manual/LuaEngine.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "InputManager.h"
#include "Util/UtilLua.h"
#include "../Classes/XLuaModuleRegistry.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "ntcvt/ntcvt.hpp"
#endif

using namespace std;
using namespace lstg;
using namespace cc;

LUA_REGISTER_FUNC_DEF(lstg, GetKeyState)
{
	lua_pushboolean(L, LIM.getKeyState(luaL_checkinteger(L, 1)));
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, GetLastKey)
{
	lua_pushinteger(L, LIM.getLastKey());
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, SetKeyboardHookEnabled)
{
	LIM.setKeyboardHookEnabled(lua_toboolean(L, 1));
	return 0;
}

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
LUA_REGISTER_FUNC_DEF(lstg, SaveSettingsAtomically)
{
	const auto path = luaL_checkstring(L, 1);
	size_t size = 0;
	const auto* data = luaL_checklstring(L, 2, &size);
	const std::string temporary = std::string(path) + ".tmp-" + std::to_string(GetCurrentProcessId())
		+ "-" + std::to_string(GetTickCount64());
	const auto files = FileUtils::getInstance();
	if (!files->writeStringToFile(std::string_view(data, size), temporary))
	{
		files->removeFile(temporary);
		lua_pushboolean(L, false);
		return 1;
	}
	const auto from = ntcvt::from_chars(temporary);
	const auto to = ntcvt::from_chars(std::string_view(path));
	const bool saved = MoveFileExW(from.c_str(), to.c_str(), MOVEFILE_REPLACE_EXISTING | MOVEFILE_WRITE_THROUGH) != 0;
	if (!saved)
		files->removeFile(temporary);
	lua_pushboolean(L, saved);
	return 1;
}
#endif
// mouse

LUA_REGISTER_FUNC_DEF(lstg, GetMousePosition)
{
	const auto pos = LIM.getMousePosition();
	lua_pushnumber(L, pos.x);
	lua_pushnumber(L, pos.y);
	return 2;
}
LUA_REGISTER_FUNC_DEF(lstg, GetMouseState)
{
	lua_pushboolean(L, LIM.getMouseState(luaL_checkinteger(L, 1) - 1));
	return 1;
}
