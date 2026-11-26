#include "LuaBindings.h"
#include "../Classes/XLuaModuleRegistry.h"

#include "lua_BentLaser_auto.hpp"
LUA_REGISTER_MODULE(x_BentLaser, luaReg_BentLaser);
#include "lua_RenderMode_auto.hpp"
LUA_REGISTER_MODULE(x_RenderMode, luaReg_RenderMode);
#include "lua_Buffer_auto.hpp"
LUA_REGISTER_MODULE(x_Buffer, luaReg_Buffer);
#include "lua_cc_configuration_auto.hpp"
LUA_REGISTER_MODULE(cc_configuration, register_all_cc_configuration);
#include "lua_cc_ext.hpp"
LUA_REGISTER_MODULE(cc_Image_ext, register_all_cc_ext);
#include "lua_Latex_auto.hpp"
LUA_REGISTER_MODULE(x_Latex, luaReg_Latex);
#include "lua_LogSystem_auto.hpp"
LUA_REGISTER_MODULE(x_LogSystem, luaReg_LogSystem);
#include "lua_ObjSym_auto.hpp"
LUA_REGISTER_MODULE(x_ObjSym, luaReg_ObjSym);
#include "lua_Random_auto.hpp"
LUA_REGISTER_MODULE(x_Random, luaReg_Random);
#include "lua_Resource_auto.hpp"
LUA_REGISTER_MODULE(x_Resource, luaReg_Resource);
#include "lua_ResourceMgr_auto.hpp"
LUA_REGISTER_MODULE(x_ResourceMgr, luaReg_ResourceMgr);
#include "ResourceMgr.h"
#include "scripting/lua-bindings/manual/base/cclua_file_read.hpp"
#include "lua_StopWatch_auto.hpp"
LUA_REGISTER_MODULE(x_StopWatch, luaReg_StopWatch);
#include "lua_TextInput_manual.hpp"
using lstg::registerLuaTextInput;
LUA_REGISTER_MODULE(x_TextInput, registerLuaTextInput);
#include "lua_Triangles_auto.hpp"
LUA_REGISTER_MODULE(x_Triangles, luaReg_Triangles);
#include "lua_WindowHelper_auto.hpp"
LUA_REGISTER_MODULE(x_WindowHelper, luaReg_WindowHelper);

#ifdef CC_USE_FAIRYGUI
	#include "lua_cc_fairygui_auto.hpp"
	LUA_REGISTER_MODULE(cc_fairygui, luaReg_fgui);
	#include "lua_cc_fairygui_manual.hpp"
	// Manual overrides must run after the generated modules (priority 0).
	static CC_UNUSED auto& fairyGuiManualModule = LuaModuleRegistry::addModule(
		"cc_fairygui_manual", register_all_cc_fairygui_manual, 1);
#endif

#include "lua_audio_auto.hpp"
LUA_REGISTER_MODULE(cc_audio, register_all_cc_audio);

#ifndef LSTGX_NO_LIVE2D
	#include "../Live2D/lua_live2d_auto.hpp"
	LUA_REGISTER_MODULE(cc_l2d, register_all_live2d);
#endif

//#include "../reader/lua-bindings/creator_reader_bindings.hpp"
//LUA_REGISTER_MODULE(cc_creator_reader, register_creator_reader_module);

extern "C" int luaopen_lfs(lua_State *L);
LUA_REGISTER_MODULE_DEF(lfs) { luaopen_lfs(L); lua_pop(L, 3); return 0; }

#include "lptree.h"
LUA_REGISTER_MODULE_DEF(lpeg) { luaopen_lpeg(L); lua_pop(L, 2); return 0; }

extern "C" int luaopen_cjson(lua_State * L);
LUA_REGISTER_MODULE_DEF(cjson) { luaopen_cjson(L); lua_setglobal(L, "cjson"); return 0; }

#include "../imgui/lua-bindings/imgui_lua.hpp"
LUA_REGISTER_MODULE(imgui, luaopen_imgui);

#ifndef LSTGX_NO_YUESCRIPT
	extern "C" int luaopen_yue(lua_State * L);
	LUA_REGISTER_MODULE(yue, luaopen_yue);
#endif

#include "Util/UtilLua.h"

namespace
{
	template<class T>
	T& resourceBindingSelf(lua_State* L, const char* type)
	{
		if (!lua::isusertype(L, 1, type))
			luaL_argerror(L, 1, type);
		auto self = static_cast<T*>(tolua_tousertype(L, 1, nullptr));
		if (!self)
			luaL_argerror(L, 1, type);
		return *self;
	}

	int resourcePackForHit(lua_State* L)
	{
		auto& manager = resourceBindingSelf<lstg::ResourceMgr>(L, "lstg.ResourceMgr");
		lua::native_to_luaval(L, manager.getResourcePackForHit(cc::luaio::checkFileHit(L, 2)));
		return 1;
	}

	int cacheFileHit(lua_State* L)
	{
		auto& manager = resourceBindingSelf<lstg::ResourceMgr>(L, "lstg.ResourceMgr");
		lua_pushboolean(L, manager.cacheFileHit(cc::luaio::checkFileHit(L, 2)));
		return 1;
	}

	int cacheFileHitAsync(lua_State* L)
	{
		auto& manager = resourceBindingSelf<lstg::ResourceMgr>(L, "lstg.ResourceMgr");
		const auto& hit = lua_isnil(L, 2) ? cc::FileHit{} : cc::luaio::checkFileHit(L, 2);
		std::function<void()> callback;
		if (!lua_isnoneornil(L, 3) &&
			!lua::luaval_to_owned_callback(L, 3, &callback, "lstg.ResourceMgr:cacheFileHitAsync"))
			return luaL_argerror(L, 3, "callback expected");
		manager.cacheFileHitAsync(hit, callback);
		return 0;
	}

	int removeFileHitCache(lua_State* L)
	{
		auto& manager = resourceBindingSelf<lstg::ResourceMgr>(L, "lstg.ResourceMgr");
		lua_pushboolean(L, manager.removeFileHitCache(cc::luaio::checkFileHit(L, 2)));
		return 1;
	}

	template<auto Method>
	int packFileSize(lua_State* L)
	{
		auto& pack = resourceBindingSelf<lstg::ResourcePack>(L, "lstg.ResourcePack");
		const std::string path(cc::luaio::checkString(L, 2));
		cc::luaio::pushExact(L, (pack.*Method)(path));
		return 1;
	}

	int registerResourceFileBindings(lua_State* L)
	{
		luaL_getmetatable(L, "lstg.ResourceMgr");
		const luaL_Reg methods[] = {
			{"getResourcePackForHit", resourcePackForHit}, {"cacheFileHit", cacheFileHit},
			{"cacheFileHitAsync", cacheFileHitAsync}, {"removeFileHitCache", removeFileHitCache},
			{nullptr, nullptr}
		};
		luaL_register(L, nullptr, methods);
		lua_pop(L, 1);
		luaL_getmetatable(L, "lstg.ResourcePack");
		const luaL_Reg packMethods[] = {
			{"getCompressedSize", packFileSize<&lstg::ResourcePack::getCompressedSize>},
			{"getUncompressedSize", packFileSize<&lstg::ResourcePack::getUncompressedSize>},
			{nullptr, nullptr}
		};
		luaL_register(L, nullptr, packMethods);
		lua_pop(L, 1);
		return 0;
	}
}

static CC_UNUSED auto& resourceFileModule = LuaModuleRegistry::addModule(
	"x_resource_file_reads", registerResourceFileBindings, 1);
#include "Symbol/GameObjectSymbol.h"

// Block::executeLua is a stack-producing helper, so its Lua adapter owns the
// result suffix explicitly rather than treating it as an ordinary void method.
static int lua_lstg_symbol_Block_executeLua_manual(lua_State* L)
{
	const int argc = lua_gettop(L) - 1;
	if (argc != 0 && argc != 1)
		return luaL_error(L, "wrong number of arguments in 'lstg_sym.Block:executeLua': %d, expects 0,1", argc);
	// Keep the original self, including a .c_instance wrapper, on the input stack.
	lua_pushvalue(L, 1);
	lstg::symbol::Block* block = nullptr;
	if (!lua::luaval_to_native(L, -1, &block) || !block)
		return luaL_error(L, "invalid class object in 'lstg_sym.Block:executeLua'");
	lua_pop(L, 1);
	// The legacy symbol evaluator uses the engine's state, including when this
	// adapter is entered on a coroutine. Reclaim only its own output suffix.
	auto* state = lstg::lua::stack()->getLuaState();
	const int base = lua_gettop(state);
	if (argc == 1)
	{
		lstg::GameObject* object = nullptr;
		if (!lstg::lua::luaval_to_GameObject(L, 2, &object))
			return luaL_error(L, "invalid game object in 'lstg_sym.Block:executeLua'");
		block->executeLua(object);
	}
	else
		block->executeLua();
	lua_settop(state, base);
	// Preserve the established fluent setter return; helper outputs are private.
	lua_settop(L, 1);
	return 1;
}

static int luaReg_ObjSym_manual(lua_State* lua_S)
{
	LUA_ENTRY("lstg_sym");
	LUA_ENTRY("Block");
	LUA_METHOD("executeLua", lua_lstg_symbol_Block_executeLua_manual);
	LUA_ENTRY_END(2);
	return 0;
}
static CC_UNUSED auto& objSymManualModule = LuaModuleRegistry::addModule(
	"x_ObjSym_manual", luaReg_ObjSym_manual, 1);

bool lua::luaval_to_RenderMode(lua_State* L, int lo, lstg::RenderMode** outValue, const char* fName)
{
	return lstg::lua::luaval_to_RenderMode(L, lo, outValue, fName);
}

bool lua::luaval_to_Color4B(lua_State* L, int lo, cc::Color4B* outValue, const char* fName)
{
	return lstg::lua::_luaval_to_color4b(L, lo, outValue, fName);
}

#include "Resource/ResAudio.h"

int lua_lstg_ResAudio_getFFT(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.ResAudio", "lstg.ResAudio:getFFT");
	if (!lua::isusertype(lua_S, 1, LUA_OBJ_TYPE))
		return luaL_error(lua_S, "invalid class object in '%s'", LUA_FNAME);
	auto cobj = (lstg::ResAudio*)tolua_tousertype(lua_S, 1, nullptr);
	if (!cobj)
		return luaL_error(lua_S, "invalid class object in '%s'", LUA_FNAME);
	if (argc == (0) && !ok)
	{
		lstg::lua::cptr_to_luaval(lua_S, cobj->getFFT(), "float*");
		return 1;
	}
	LUA_INVOKE_FOOTER("0");
}
int luaReg_ResAudio_manual(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_ENTRY("ResAudio");
	LUA_METHOD("getFFT", lua_lstg_ResAudio_getFFT);
	LUA_ENTRY_END(2);
	return 0;
}
LUA_REGISTER_MODULE(x_ResAudio_manual, luaReg_ResAudio_manual);

#include "Resource/ResFont.h"

static int lua_lstg_ResFont_HGE2BMF_manual(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.ResFont", "lstg.ResFont:HGE2BMF");
	if (argc != 1)
		return luaL_error(lua_S, "wrong number of arguments in '%s': %d, expects 1", LUA_FNAME, argc);
	if (!lua_isstring(lua_S, 2))
		return luaL_error(lua_S, "invalid argument #1 in '%s'", LUA_FNAME);
	std::string data, textureName;
	lua::luaval_to_native(lua_S, 2, &data);
	const auto bmf = lstg::ResFont::HGE2BMF(data, textureName);
	lua::native_to_luaval(lua_S, bmf);
	lua::native_to_luaval(lua_S, textureName);
	return 2;
}

int luaReg_ResFont_manual(lua_State* lua_S)
{
	if (!lua_S)
		return 0;
	LUA_ENTRY("lstg");
	LUA_ENTRY("ResFont");
	LUA_METHOD("HGE2BMF", lua_lstg_ResFont_HGE2BMF_manual);
	LUA_ENTRY_END(2);
	return 0;
}
// ResFont is defined by x_Resource at the default priority.
static CC_UNUSED auto& resFontManualModule = LuaModuleRegistry::addModule(
	"x_ResFont_manual", luaReg_ResFont_manual, 1);
