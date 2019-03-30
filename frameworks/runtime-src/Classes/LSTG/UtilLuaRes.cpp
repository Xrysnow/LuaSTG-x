#include "UtilLuaRes.h"
#include "AppFrame.h"
#include "UtilLua.h"

using namespace lstg;
#define USE_LRES 0

ResAnimation* lua::toResAnimation(lua_State* L, int lo)
{
	ResAnimation* ret = nullptr;
#if USE_LRES
	const auto type = lua_type(L, lo);
	if (type == LUA_TSTRING)
		ret = LRES.FindAnimation(luaL_checkstring(L, lo));
	else
#endif
		ret = dynamic_cast<ResAnimation*>(Resource::fromLua(L, lo, ResourceType::Animation));
	return ret;
}

ResTexture* lua::toResTexture(lua_State* L, int lo)
{
	ResTexture* ret = nullptr;
#if USE_LRES
	const auto type = lua_type(L, lo);
	if (type == LUA_TSTRING)
		ret = LRES.FindTexture(luaL_checkstring(L, lo));
	else
#endif
		ret = dynamic_cast<ResTexture*>(Resource::fromLua(L, lo, ResourceType::Texture));
	return ret;
}

ResSprite* lua::toResSprite(lua_State* L, int lo)
{
	ResSprite* ret = nullptr;
#if USE_LRES
	const auto type = lua_type(L, lo);
	if (type == LUA_TSTRING)
		ret = LRES.FindSprite(luaL_checkstring(L, lo));
	else
#endif
		ret = dynamic_cast<ResSprite*>(Resource::fromLua(L, lo, ResourceType::Sprite));
	return ret;
}

ResMusic* lua::toResMusic(lua_State* L, int lo)
{
	ResMusic* ret = nullptr;
#if USE_LRES
	const auto type = lua_type(L, lo);
	if (type == LUA_TSTRING)
		ret = LRES.FindMusic(luaL_checkstring(L, lo));
	else
#endif
		ret = dynamic_cast<ResMusic*>(Resource::fromLua(L, lo, ResourceType::Music));
	return ret;
}

ResSound* lua::toResSound(lua_State* L, int lo)
{
	ResSound* ret = nullptr;
#if USE_LRES
	const auto type = lua_type(L, lo);
	if (type == LUA_TSTRING)
		ret = LRES.FindSound(luaL_checkstring(L, lo));
	else
#endif
		ret = dynamic_cast<ResSound*>(Resource::fromLua(L, lo, ResourceType::SoundEffect));
	return ret;
}

ResParticle* lua::toResParticle(lua_State* L, int lo)
{
	ResParticle* ret = nullptr;
#if USE_LRES
	const auto type = lua_type(L, lo);
	if (type == LUA_TSTRING)
		ret = LRES.FindParticle(luaL_checkstring(L, lo));
	else
#endif
		ret = dynamic_cast<ResParticle*>(Resource::fromLua(L, lo, ResourceType::Particle));
	return ret;
}

ResFont* lua::toResFont(lua_State* L, int lo)
{
	ResFont* ret = nullptr;
#if USE_LRES
	const auto type = lua_type(L, lo);
	if (type == LUA_TSTRING)
		ret = LRES.FindFont(luaL_checkstring(L, lo));
	else
#endif
		ret = dynamic_cast<ResFont*>(Resource::fromLua(L, lo, ResourceType::Font));
	return ret;
}

ResFX* lua::toResFX(lua_State* L, int lo)
{
	ResFX* ret = nullptr;
#if USE_LRES
	const auto type = lua_type(L, lo);
	if (type == LUA_TSTRING)
		ret = LRES.FindFX(luaL_checkstring(L, lo));
	else
#endif
		ret = dynamic_cast<ResFX*>(Resource::fromLua(L, lo, ResourceType::FX));
	return ret;
}

ResRenderTarget* lua::toResRenderTarget(lua_State* L, int lo)
{
	ResRenderTarget* ret = nullptr;
#if USE_LRES
	const auto type = lua_type(L, lo);
	if (type == LUA_TSTRING)
		ret = LRES.FindRenderTarget(luaL_checkstring(L, lo));
	else
#endif
		ret = dynamic_cast<ResRenderTarget*>(Resource::fromLua(L, lo, ResourceType::RenderTarget));
	return ret;
}

cocos2d::Texture2D* lua::toTexture2D(lua_State* L, int lo)
{
	auto t = toResTexture(L, lo);
	if (t) return t->getTexture();
	auto rt = toResRenderTarget(L, lo);
	if (rt) return rt->getTexture();
	return nullptr;
}

int lua::setResFX(ResFX* p, lua_State* L, int lo)
{
	//if (lua_istable(L, lo))
	//{
	//	// table -> fx
	//	lua_pushnil(L);  // s s t ... nil
	//	while (0 != lua_next(L, lo))
	//	{
	//		// s s t ... nil key value
	//		const char* key = luaL_checkstring(L, -2);
	//		if (lua_isnumber(L, -1))
	//			p->setValue(key, (float)lua_tonumber(L, -1));
	//		else if (lua_isstring(L, -1))
	//		{
	//			auto texname = lua_tostring(L, -1);
	//			auto tex = LRES.FindTexture2D(texname);
	//			if (!tex)
	//				return luaL_error(L, "can't find texture '%s'.", texname);
	//			p->setTexture(key, tex);
	//		}
	//		else if (lua_isuserdata(L, -1))
	//		{
	//			p->setColor(key, luaval_to_c4b(L, -1));
	//		}
	//		else
	//			return luaL_error(L, "invalid data type.");

	//		lua_pop(L, 1);  // s s t ... nil key
	//	}
	//}
	//else
	//	return luaL_error(L, "setResFX failed.");
	return 0;
}
