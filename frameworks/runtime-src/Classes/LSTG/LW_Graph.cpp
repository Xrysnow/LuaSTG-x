#include "LW_Graph.h"
#include "AppFrame.h"
#include "LuaWrapper.h"
#include "Utility.h"
#include "UtilLua.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "Renderer.h"
#include "UtilLuaRes.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"

using namespace std;
using namespace lstg;
using namespace cocos2d;
using lua::_luaval_to_color4b;
using lua::luaval_to_c4b;

static int BeginScene(lua_State* L) noexcept
{
	if (!LRR.beginScene())
		return luaL_error(L, "can't invoke 'BeginScene'.");
	return 0;
}
static int EndScene(lua_State* L) noexcept
{
	if (!LRR.endScene())
		return luaL_error(L, "can't invoke 'EndScene'.");
	return 0;
}
static int RenderClear(lua_State* L) noexcept
{
	auto color = Color4B(0, 0, 0, 0);
	if (lua_gettop(L) > 0)
	{
		color = luaval_to_c4b(L, 1);
	}
	LRR.renderClear(Color4F(color));
	return 0;
}
static int SetViewport(lua_State* L) noexcept
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
static int SetOrtho(lua_State* L) noexcept
{
	LRR.setOrtho(
		luaL_checknumber(L, 1),
		luaL_checknumber(L, 2),
		luaL_checknumber(L, 3),
		luaL_checknumber(L, 4)
	);
	return 0;
}
static int SetPerspective(lua_State* L) noexcept
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
static int SetFog(lua_State* L) noexcept
{
	if (lua_gettop(L) == 3)
	{
		LRR.setFog(
			luaL_checknumber(L, 1),
			luaL_checknumber(L, 2),
			Color4F(luaval_to_c4b(L, 3))
		);
	}
	else if (lua_gettop(L) == 2)
	{
		const Color4F c(0, 0, 0, 1);//TODO: default?
		LRR.setFog(
			luaL_checknumber(L, 1),
			luaL_checknumber(L, 2),
			c
		);
	}
	else
	{
		LRR.setFog(0.0f, 0.0f, Color4F());
	}
	return 0;
}
static int PushRenderTarget(lua_State* L) noexcept
{
	auto p = lua::toResRenderTarget(L, 1);
	if (!p || !p->checkTarget())
		return luaL_error(L, "can't find rendertarget");
	if (!LRR.pushRenderTarget(p))
		return luaL_error(L, "push rendertarget failed");
	return 0;
}
static int PopRenderTarget(lua_State* L) noexcept
{
	if (!LRR.popRenderTarget())
		return luaL_error(L, "pop rendertarget failed");
	return 0;
}
static int PostEffect(lua_State* L) noexcept
{
	auto rt = lua::toResRenderTarget(L, 1);
	if (!rt)
		return luaL_error(L, "can't find rendertarget");
	auto fx = lua::toResFX(L, 2);
	if (!fx)
		return luaL_error(L, "can't find effect");
	auto blend = TranslateBlendMode(L, 3);
	if (lua_gettop(L) >= 4)
		lua::setResFX(fx, L, 4);
	if (!LRR.postEffect(rt, fx, blend))
		return luaL_error(L, "PostEffect failed.");
	return 0;
}
//static int PostEffectCapture(lua_State* L) noexcept
//{
//	if (!LRR.postEffectCapture())
//		return luaL_error(L, "PostEffectCapture failed.");
//	return 0;
//}
//static int PostEffectApply(lua_State* L) noexcept
//{
//	auto p = lua::toResFX(L, 1);
//	if (!p)
//		return luaL_error(L, "can't find effect");
//	auto blend = TranslateBlendMode(L, 2);
//	if (lua_gettop(L) >= 3)
//		lua::setResFX(p, L, 3);
//	if (!LRR.postEffectApply(p, blend))
//		return luaL_error(L, "PostEffectApply failed.");
//	return 0;
//}
//static int SetShaderUniform(lua_State* L) noexcept
//{
//	auto p = lua::toResFX(L, 1);
//	if (!p)
//		return luaL_error(L, "can't find effect");
//	return lua::setResFX(p, L, 2);
//}
static int CreateGLProgramFromPath(lua_State* L) noexcept
{
	const auto s1 = lua_tostring(L, 1);
	const auto s2 = lua_tostring(L, 2);
	const auto p = util::CreateGLProgramFromPath(s1, s2);
	if (!p)
		return luaL_error(L, "can't create GLProgram from path [%s] and [%s]", s1, s2);
	object_to_luaval<cocos2d::GLProgram>(L, "cc.GLProgram", p);
	return 1;
}
static int CreateGLProgramFromString(lua_State* L) noexcept
{
	const auto s1 = lua_tostring(L, 1);
	const auto s2 = lua_tostring(L, 2);
	const auto p = util::CreateGLProgramFromString(s1, s2);
	if (!p)
		return luaL_error(L, "can't create GLProgram from string");
	object_to_luaval<cocos2d::GLProgram>(L, "cc.GLProgram", p);
	return 1;
}

static int CopyFrameBuffer(lua_State* L) noexcept
{
	const auto p = LRR.copyFrameBuffer();
	if (!p)
		return luaL_error(L, "can't create GLProgram from string");
	object_to_luaval<cocos2d::RenderTexture>(L, "cc.RenderTexture", p);
	return 1;
}


vector<luaL_Reg> lstg::LW_Graph()
{
	vector<luaL_Reg> ret = {
		{ "BeginScene", &BeginScene },
		{ "EndScene", &EndScene },
		{ "RenderClear", &RenderClear },
		{ "SetViewport", &SetViewport },
		{ "SetOrtho", &SetOrtho },
		{ "SetPerspective", &SetPerspective },
		{ "SetFog", &SetFog },
		{ "PushRenderTarget", &PushRenderTarget },
		{ "PopRenderTarget", &PopRenderTarget },
		{ "PostEffect", &PostEffect },
		//{ "PostEffectCapture", &PostEffectCapture },
		//{ "PostEffectApply", &PostEffectApply },

		//{ "SetShaderUniform", &SetShaderUniform },
		{ "CreateGLProgramFromPath", &CreateGLProgramFromPath },
		{ "CreateGLProgramFromString", &CreateGLProgramFromString },
		{ "CopyFrameBuffer", &CopyFrameBuffer },
	};
	return ret;
}
