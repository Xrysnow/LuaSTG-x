#pragma once
#include "base/ccConfig.h"
#include "LuaBindings.h"

extern int luaReg_Resource_lstgResource(lua_State* lua_S);
extern int luaReg_Resource_lstgResourceColliable(lua_State* lua_S);
extern int luaReg_Resource_lstgResourceQuad(lua_State* lua_S);
extern int luaReg_Resource_lstgResTexture(lua_State* lua_S);
extern int luaReg_Resource_lstgResAnimation(lua_State* lua_S);
extern int luaReg_Resource_lstgResSprite(lua_State* lua_S);
extern int luaReg_Resource_lstgResParticle(lua_State* lua_S);
extern int luaReg_Resource_lstgResFont(lua_State* lua_S);
extern int luaReg_Resource_lstgResAudio(lua_State* lua_S);
extern int luaReg_Resource_lstgResSound(lua_State* lua_S);
extern int luaReg_Resource_lstgResMusic(lua_State* lua_S);
extern int luaReg_Resource_lstgResFX(lua_State* lua_S);
extern int luaReg_Resource_lstgResRenderTarget(lua_State* lua_S);

inline int luaReg_Resource(lua_State* lua_S)
{
	luaReg_Resource_lstgResource(lua_S);
	luaReg_Resource_lstgResourceColliable(lua_S);
	luaReg_Resource_lstgResourceQuad(lua_S);
	luaReg_Resource_lstgResTexture(lua_S);
	luaReg_Resource_lstgResAnimation(lua_S);
	luaReg_Resource_lstgResSprite(lua_S);
	luaReg_Resource_lstgResParticle(lua_S);
	luaReg_Resource_lstgResFont(lua_S);
	luaReg_Resource_lstgResAudio(lua_S);
	luaReg_Resource_lstgResSound(lua_S);
	luaReg_Resource_lstgResMusic(lua_S);
	luaReg_Resource_lstgResFX(lua_S);
	luaReg_Resource_lstgResRenderTarget(lua_S);
	return 0;
}
