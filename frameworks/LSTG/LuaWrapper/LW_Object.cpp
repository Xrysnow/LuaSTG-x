#include "LW_Object.h"
#include "AppFrame.h"
#include "LuaWrapper.h"
#include "Util/UtilLua.h"
#include "../Classes/XLuaModuleRegistry.h"
#include <vector>

#ifdef RegisterClass
#undef RegisterClass
#endif // RegisterClass

using namespace std;
using namespace lstg;

LUA_REGISTER_FUNC_DEF(lstg, GetnObj)
{
	lua_pushinteger(L, (lua_Integer)LPOOL.GetObjectCount());
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, ObjTable)
{
	return LPOOL.GetObjectTable(L);
}
LUA_REGISTER_FUNC_DEF(lstg, ObjFrame)
{
	LPOOL.DoFrame();
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, ObjRender)
{
	LPOOL.DoRender();
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, BoundCheck)
{
	LPOOL.BoundCheck();
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, SetBound)
{
	LPOOL.SetBound(
		luaL_checkinteger(L, 1),
		luaL_checkinteger(L, 2),
		luaL_checkinteger(L, 3),
		luaL_checkinteger(L, 4)
	);
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, CollisionCheck)
{
	const auto t1 = lua_type(L, 1);
	const auto t2 = lua_type(L, 2);
	if (t1 == LUA_TNUMBER && t2 == LUA_TNUMBER)
	{
		LPOOL.CollisionCheck(luaL_checkinteger(L, 1), luaL_checkinteger(L, 2));
	}
	else if (t1 == LUA_TNUMBER && t2 == LUA_TTABLE)
	{
		lua_rawgeti(L, 2, 2);  // o1 o2 ??? id
		const auto p = LPOOL.GetPooledObject(size_t(luaL_checkinteger(L, -1)));
		if (!p) return luaL_objerror(L);
		LPOOL.CollisionCheck(luaL_checkinteger(L, 1), p);
	}
	else if (t1 == LUA_TTABLE && t2 == LUA_TNUMBER)
	{
		lua_rawgeti(L, 1, 2);  // o1 o2 ??? id
		const auto p = LPOOL.GetPooledObject(size_t(luaL_checkinteger(L, -1)));
		if (!p) return luaL_objerror(L);
		LPOOL.CollisionCheck(p, luaL_checkinteger(L, 2));
	}
	else if (t1 == LUA_TTABLE && t2 == LUA_TTABLE)
	{
		lua_rawgeti(L, 1, 2);  // o1 o2 ??? id1
		const auto p1 = LPOOL.GetPooledObject(size_t(luaL_checkinteger(L, -1)));
		if (!p1) return luaL_objerror(L);
		lua_rawgeti(L, 2, 2);  // o1 o2 ??? id1 id2
		const auto p2 = LPOOL.GetPooledObject(size_t(luaL_checkinteger(L, -1)));
		if (!p2) return luaL_objerror(L);
		LPOOL.CollisionCheck(p1, p2);
	}
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, CollisionCheck3D)
{
	LPOOL.CollisionCheck3D(luaL_checkinteger(L, 1), luaL_checkinteger(L, 2));
	return 0;
}

LUA_REGISTER_FUNC_DEF(lstg, UpdateXY)
{
	const int nArg = lua_gettop(L);
	if (nArg == 0)
	{
		LPOOL.UpdateXY();
	}
	else
	{
		do
		{
			if (!lua_istable(L, 1)) break;
			lua_rawgeti(L, 1, 2);  // t(object) ??? id
			auto p = LPOOL.GetPooledObject(size_t(luaL_checkinteger(L, -1)));
			if(!p) break;
			p->UpdateXY();
			return 0;
		}
		while (false);
		return luaL_objerror(L);
	}
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, AfterFrame)
{
	LPOOL.AfterFrame();
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, New)
{
	return LPOOL.New(L);
}
LUA_REGISTER_FUNC_DEF(lstg, Del)
{
	return LPOOL.Del(L);
}
LUA_REGISTER_FUNC_DEF(lstg, Kill)
{
	return LPOOL.Kill(L);
}
LUA_REGISTER_FUNC_DEF(lstg, IsValid)
{
	return LPOOL.IsValid(L);
}
LUA_REGISTER_FUNC_DEF(lstg, Angle)
{
	if (lua_gettop(L) == 2)
	{
		do
		{
			if (!lua_istable(L, 1) || !lua_istable(L, 2)) break;
			lua_rawgeti(L, 1, 2);  // t(object) t(object) ??? id
			lua_rawgeti(L, 2, 2);  // t(object) t(object) ??? id id
			double tRet;
			if (!LPOOL.Angle((size_t)luaL_checkinteger(L, -2), (size_t)luaL_checkinteger(L, -1), tRet))
				break;
			lua_pushnumber(L, tRet);
			return 1;
		}
		while (false);
		return luaL_objerror(L);
	}
	else
	{
		lua_pushnumber(L,
			atan2(luaL_checknumber(L, 4) - luaL_checknumber(L, 2),
				luaL_checknumber(L, 3) - luaL_checknumber(L, 1)) * LRAD2DEGREE
		);
		return 1;
	}
}
LUA_REGISTER_FUNC_DEF(lstg, Dist)
{
	if (lua_gettop(L) == 2)
	{
		do
		{
			if (!lua_istable(L, 1) || !lua_istable(L, 2)) break;
			lua_rawgeti(L, 1, 2);  // t(object) t(object) id
			lua_rawgeti(L, 2, 2);  // t(object) t(object) id id
			double tRet;
			const auto idA = size_t(luaL_checkinteger(L, -2));
			const auto idB = size_t(luaL_checkinteger(L, -1));
			if (!LPOOL.Dist(idA, idB, tRet))
				break;
			lua_pushnumber(L, tRet);
			return 1;
		}
		while (false);
		return luaL_objerror(L);
	}
	else
	{
		const auto dx = luaL_checknumber(L, 3) - luaL_checknumber(L, 1);
		const auto dy = luaL_checknumber(L, 4) - luaL_checknumber(L, 2);
		lua_pushnumber(L, sqrt(dx*dx + dy*dy));
		return 1;
	}
}
LUA_REGISTER_FUNC_DEF(lstg, GetV)
{
	do
	{
		if (!lua_istable(L, 1)) break;
		double v, a;
		lua_rawgeti(L, 1, 2);  // t(object) ??? id
		if (!LPOOL.GetV(size_t(luaL_checkinteger(L, -1)), v, a))
			break;
		lua_pushnumber(L, v);
		lua_pushnumber(L, a);
		return 2;
	}
	while (false);
	return luaL_objerror(L);
}
LUA_REGISTER_FUNC_DEF(lstg, SetV)
{
	if (!lua_istable(L, 1))
		return luaL_objerror(L);
	const int nArg = lua_gettop(L);
	if (nArg == 3)
	{
		lua_rawgeti(L, 1, 2);  // t(object) 'v' 'a' ??? id
		if (!LPOOL.SetV(size_t(luaL_checkinteger(L, -1)),
			luaL_checknumber(L, 2), luaL_checknumber(L, 3), false))
			return luaL_objerror(L);
	}
	else if (nArg == 4)
	{
		lua_rawgeti(L, 1, 2);  // t(object) 'v' 'a' 'rot' ??? id
		if (!LPOOL.SetV(size_t(luaL_checkinteger(L, -1)),
			luaL_checknumber(L, 2), luaL_checknumber(L, 3), lua_toboolean(L, 4) != 0))
			return luaL_objerror(L);
	}
	else
		return luaL_objerror(L);
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, SetImgState)
{
	if (!lua_istable(L, 1))
		return luaL_objerror(L);
	lua_rawgeti(L, 1, 2);  // t(object) ??? id
	const auto id = size_t(luaL_checkinteger(L, -1));
	lua_pop(L, 1);

	const auto m = TranslateRenderMode(L, 2);
	// A R G B -> R G B A
	const auto c = cocos2d::Color4B(
		luaL_checkinteger(L, 4),
		luaL_checkinteger(L, 5),
		luaL_checkinteger(L, 6),
		luaL_checkinteger(L, 3));
	if (!LPOOL.SetImgState(id, m, c))
		return luaL_objerror(L);
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, BoxCheck)
{
	if (!lua_istable(L, 1))
		return luaL_objerror(L);
	lua_rawgeti(L, 1, 2);  // t(object) 'l' 'r' 'b' 't' ??? id
	bool tRet;
	if (!LPOOL.BoxCheck(
		size_t(luaL_checkinteger(L, -1)),
		luaL_checknumber(L, 2),
		luaL_checknumber(L, 3),
		luaL_checknumber(L, 4),
		luaL_checknumber(L, 5),
		tRet))
	{
		return luaL_objerror(L);
	}
	lua_pushboolean(L, tRet);
	return 1;
}
LUA_REGISTER_FUNC_DEF(lstg, ResetPool)
{
	LPOOL.ResetPool();
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, DefaultRenderFunc)
{
	do
	{
		if (!lua_istable(L, 1)) break;
		lua_rawgeti(L, 1, 2);  // t(object) ??? id
		if (!LPOOL.DoDefaultRender(luaL_checkinteger(L, -1))) break;
		return 0;
	}
	while (false);
	return luaL_objerror(L);
}
LUA_REGISTER_FUNC_DEF(lstg, NextObject)
{
	return LPOOL.NextObject(L);
}
LUA_REGISTER_FUNC_DEF(lstg, ObjList)
{
	int g = luaL_checkinteger(L, 1);  // i(groupId)
	lua_pushcfunction(L, LuaFunc_lstg_NextObject);
	lua_pushinteger(L, g);
	lua_pushinteger(L, LPOOL.FirstObject(g));
	return 3;
}
LUA_REGISTER_FUNC_DEF(lstg, GetAttr)
{
	return LPOOL.GetAttr(L);
}
LUA_REGISTER_FUNC_DEF(lstg, SetAttr)
{
	return LPOOL.SetAttr(L);
}

LUA_REGISTER_FUNC_DEF(lstg, GetParticlePool)
{
	return LPOOL.GetParticlePool(L);
}

LUA_REGISTER_FUNC_DEF(lstg, RegisterClass)
{
	return LPOOL.RegistClass(L);
}

LUA_REGISTER_FUNC_DEF(lstg, GetGroupTable)
{
	LPOOL.pushGroup(L, luaL_checkinteger(L, 1));
	return 1;
}

LUA_REGISTER_FUNC_DEF(lstg, GetLastXY)
{
	do
	{
		if (!lua_istable(L, 1)) break;
		double x, y;
		lua_rawgeti(L, 1, 2);  // t(object) ??? id
		if (!LPOOL.GetLastXY(size_t(luaL_checkinteger(L, -1)), x, y)) break;
		lua_pushnumber(L, x);
		lua_pushnumber(L, y);
		return 2;
	}
	while (false);
	return luaL_objerror(L);
}
LUA_REGISTER_FUNC_DEF(lstg, SetLastXY)
{
	do
	{
		if (!lua_istable(L, 1)) break;
		const auto x = luaL_checknumber(L, 2);
		const auto y = luaL_checknumber(L, 3);
		lua_rawgeti(L, 1, 2);  // t(object) ??? id
		if (!LPOOL.SetLastXY(size_t(luaL_checkinteger(L, -1)), x, y)) break;
		return 0;
	}
	while (false);
	return luaL_objerror(L);
}
LUA_REGISTER_FUNC_DEF(lstg, UpdateParticle)
{
	do
	{
		if (!lua_istable(L, 1)) break;
		lua_rawgeti(L, 1, 2);  // t(object) ??? id
		if (!LPOOL.UpdateParticle(size_t(luaL_checkinteger(L, -1)))) break;
		return 0;
	} while (false);
	return luaL_objerror(L);
}
LUA_REGISTER_FUNC_DEF(lstg, FreeObject)
{
	do
	{
		if (!lua_istable(L, 1)) break;
		lua_rawgeti(L, 1, 2);  // t(object) ??? id
		const auto id = size_t(luaL_checkinteger(L, -1));
		const auto p = LPOOL.GetPooledObject(id);

		const auto next_id = LPOOL.NextObject(-1, id);
		LPOOL.freeObject(p);
		if (next_id < 0)
			return 0;
		lua_pushinteger(L, next_id);  // ??? i(next)
		lua_pushlightuserdata(L, (void*)&LAPP);
		lua_gettable(L, LUA_REGISTRYINDEX);// ??? i(next) ot
		
		lua_rawgeti(L, -1, id + 1);  // ??? i(next) ot t(object)
		lua_remove(L, -2);  // ??? i(next) t(object)
		lua_remove(L, -2);  // ??? t(object)
		return 1;
	} while (false);
	return luaL_objerror(L);
}
//LUA_REGISTER_FUNC_DEF(lstg, Clone)
//{
//	return LPOOL.Clone(L, 1);
//}
LUA_REGISTER_FUNC_DEF(lstg, RawNew)
{
	return LPOOL.RawNew(L);
}

LUA_REGISTER_FUNC_DEF(lstg, AllocateObject)
{
	lua::GameObject_to_luaval(L, LPOOL.allocateObject());
	return 1;
}

LUA_REGISTER_FUNC_DEF(lstg, GetObjID)
{
	const auto size = LPOOL.updateIDForLua();
	LPOOL.pushIDForLua(L);
	lua_pushnumber(L, size);
	return 2;
}

LUA_REGISTER_FUNC_DEF(lstg, ObjOnFrame)
{
	lua_rawgeti(L, 1, 2);
	const auto id = size_t(lua_tonumber(L, -1));
	lua_pop(L, 1);
	const auto p = LPOOL.GetPooledObject(id);
	if (!p)
		luaL_objerror(L);
	p->OnDoFrame();
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, BindNode)
{
	return LPOOL.BindNode(L);
}
