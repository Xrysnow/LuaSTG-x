#include "LW_Graph.h"
#include "AppFrame.h"
#include "LuaWrapper.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Renderer.h"
#include "Util/Utility.h"
#include "Util/UtilLua.h"
#include "Util/UtilLuaRes.h"
#include "../Classes/XLuaModuleRegistry.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;
using lua::luaval_to_c4b;

LUA_REGISTER_FUNC_DEF(lstg, BeginScene)
{
	if (!LRR.beginScene())
		return luaL_error(L, "can't invoke 'BeginScene'.");
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, EndScene)
{
	if (!LRR.endScene())
		return luaL_error(L, "can't invoke 'EndScene'.");
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, RenderClear)
{
	auto color = Color4B(0, 0, 0, 0);
	if (lua_gettop(L) > 0)
	{
		color = luaval_to_c4b(L, 1);
	}
	LRR.renderClear(Color4F(color));
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, SetViewport)
{
	if (!LRR.setViewport(
		luaL_checknumber(L, 1),
		luaL_checknumber(L, 2),
		luaL_checknumber(L, 3),
		luaL_checknumber(L, 4)
	))
	{
		return luaL_error(L, "invalid arguments for 'SetViewport'.");
	}
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, SetOrtho)
{
	LRR.setOrtho(
		luaL_checknumber(L, 1),
		luaL_checknumber(L, 2),
		luaL_checknumber(L, 3),
		luaL_checknumber(L, 4)
	);
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, SetPerspective)
{
	LRR.setPerspective(
		luaL_checknumber(L, 1),
		luaL_checknumber(L, 2),
		luaL_checknumber(L, 3),
		luaL_checknumber(L, 4),
		luaL_checknumber(L, 5),
		luaL_checknumber(L, 6),
		luaL_checknumber(L, 7),
		luaL_checknumber(L, 8),
		luaL_checknumber(L, 9),
		luaL_checknumber(L, 10),
		luaL_checknumber(L, 11),
		luaL_checknumber(L, 12),
		luaL_checknumber(L, 13)
	);
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, PushRenderTarget)
{
	auto p = lua::toResRenderTarget(L, 1);
	if (!p || !p->checkTarget())
		return luaL_error(L, "can't find rendertarget");
	if (!LRR.pushRenderTarget(p))
		return luaL_error(L, "push rendertarget failed");
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, PopRenderTarget)
{
	if (!LRR.popRenderTarget())
		return luaL_error(L, "pop rendertarget failed");
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, PostEffect)
{
	auto rt = lua::toResRenderTarget(L, 1);
	if (!rt)
		return luaL_error(L, "can't find rendertarget");
	auto fx = lua::toResFX(L, 2);
	if (!fx)
		return luaL_error(L, "can't find effect");
	auto blend = TranslateRenderMode(L, 3);
	if (lua_gettop(L) >= 4)
		lua::setResFX(fx, L, 4);
	if (!LRR.postEffect(rt, fx, blend))
		return luaL_error(L, "PostEffect failed.");
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, CreateShaderProgramFromPath)
{
	const auto s1 = luaL_checkstring(L, 1);
	const auto s2 = luaL_checkstring(L, 2);
	const auto p = util::CreateProgramFromPath(s1, s2);
	if (!p)
		return luaL_error(L, "can't create Program from path [%s] and [%s]", s1, s2);
	object_to_luaval<backend::Program>(L, "ccb.Program", p);
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, CreateShaderProgramFromString)
{
	const auto s1 = luaL_checkstring(L, 1);
	const auto s2 = luaL_checkstring(L, 2);
	const auto p = util::CreateProgramFromString(s1, s2);
	if (!p)
		return luaL_error(L, "can't create Program from string");
	object_to_luaval<backend::Program>(L, "ccb.Program", p);
	return 1;
}

LUA_REGISTER_FUNC_DEF(lstg, CopyFrameBuffer)
{
	const auto p = LRR.copyFrameBuffer();
	object_to_luaval<cocos2d::RenderTexture>(L, "cc.RenderTexture", p);
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, SetOffscreen)
{
	LRR.setOffscreen(lua_toboolean(L, 1));
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, GetFrameBuffer)
{
	const auto p = LRR.getFrameBuffer();
	object_to_luaval<cocos2d::RenderTexture>(L, "cc.RenderTexture", p);
	return 1;
}

static set<int> MSAALevels = { 0,2,4,8,16 };
LUA_REGISTER_FUNC_DEF(lstg, SetMSAALevel)
{
	const auto level = luaL_checkinteger(L, 1);
	bool ok = false;
	if (MSAALevels.find(level) != MSAALevels.end())
	{
		ok = true;
		GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8, level };
		GLView::setGLContextAttrs(glContextAttrs);
	}
	lua_pushboolean(L, ok);
	return 1;
}
