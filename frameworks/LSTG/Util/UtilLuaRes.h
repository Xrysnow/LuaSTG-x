#pragma once
#include "Resource/GameResources.h"

namespace lstg
{
	namespace lua
	{
		ResAnimation* toResAnimation(lua_State* L, int lo);
		ResTexture* toResTexture(lua_State* L, int lo);
		ResSprite* toResSprite(lua_State* L, int lo);
		ResMusic* toResMusic(lua_State* L, int lo);
		ResSound* toResSound(lua_State* L, int lo);
		ResParticle* toResParticle(lua_State* L, int lo);
		ResFont* toResFont(lua_State* L, int lo);
		ResFX* toResFX(lua_State* L, int lo);
		ResRenderTarget* toResRenderTarget(lua_State* L, int lo);
		// get Texture2D from ResTexture or ResRenderTarget
		cocos2d::Texture2D* toTexture2D(lua_State* L, int lo);

		int setResFX(ResFX* p, lua_State* L, int lo);
	}
}
