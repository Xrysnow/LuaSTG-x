#include "GameObjectPropertyHash.h"
#include "lua.hpp"
#include <new>

using namespace std;
using namespace lstg;
//#define PROP_OLD_STYLE

static const unordered_map<string_view, GameObjectProperty> prop_map = {
	{ "x",		GameObjectProperty::X		},
	{ "y",		GameObjectProperty::Y		},
	{ "dx",		GameObjectProperty::DX		},
	{ "dy",		GameObjectProperty::DY		},
	{ "rot",	GameObjectProperty::ROT		},
	{ "omiga",	GameObjectProperty::OMEGA	},
	{ "timer",	GameObjectProperty::TIMER	},
	{ "vx",		GameObjectProperty::VX		},
	{ "vy",		GameObjectProperty::VY		},
	{ "ax",		GameObjectProperty::AX		},
	{ "ay",		GameObjectProperty::AY		},
	{ "layer",	GameObjectProperty::LAYER	},
	{ "group",	GameObjectProperty::GROUP	},
	{ "hide",	GameObjectProperty::HIDE	},
	{ "bound",	GameObjectProperty::BOUND	},
	{ "navi",	GameObjectProperty::NAVI	},
	{ "colli",	GameObjectProperty::COLLI	},
	{ "status",	GameObjectProperty::STATUS	},
	{ "hscale",	GameObjectProperty::HSCALE	},
	{ "vscale",	GameObjectProperty::VSCALE	},
	{ "class",	GameObjectProperty::CLASS	},
	{ "a",		GameObjectProperty::A		},
	{ "b",		GameObjectProperty::B		},
	{ "rect",	GameObjectProperty::RECT	},
	{ "img",	GameObjectProperty::IMG		},
	{ "ani",	GameObjectProperty::ANI		},

#ifdef PROP_OLD_STYLE
	{ "_blend",	GameObjectProperty::RENDERMODE},
	{ "_color",	GameObjectProperty::COLOR	},
#else
	{ "rm",		GameObjectProperty::RENDERMODE},
	{ "color",	GameObjectProperty::COLOR	},
#endif
	{ "res",	GameObjectProperty::RES		},
	{ "rc",		GameObjectProperty::RES_COMPONENT},
#ifdef PROP_OLD_STYLE
	{ "_a",		GameObjectProperty::_A		},
	{ "_r",		GameObjectProperty::_R		},
	{ "_g",		GameObjectProperty::_G		},
	{ "_b",		GameObjectProperty::_B		},
#else
	{ "A",		GameObjectProperty::_A		},
	{ "R",		GameObjectProperty::_R		},
	{ "G",		GameObjectProperty::_G		},
	{ "B",		GameObjectProperty::_B		},
#endif
	{ "light",	GameObjectProperty::LIGHT	},

	{ "z",		GameObjectProperty::Z		},
	{ "dz",		GameObjectProperty::DZ		},
	{ "vz",		GameObjectProperty::VZ		},
	{ "az",		GameObjectProperty::AZ		},
	{ "zscale",	GameObjectProperty::ZSCALE	},
	{ "quat",	GameObjectProperty::QUAT	},
};
namespace
{
	struct PropertyCache
	{
		unordered_map<const char*, GameObjectProperty> properties;
		lua_State* state = nullptr;
	};
	struct PropertyCacheOwner
	{
		PropertyCache* cache = nullptr;
	};
	struct PropertyCacheIndex
	{
		unordered_map<lua_State*, PropertyCache*> states;
		lua_State* last_state = nullptr;
		PropertyCache* last_cache = nullptr;
	};
	// VM initialization, lookup and finalization use the owning host thread.
	thread_local PropertyCacheIndex property_cache_index;
	char property_cache_key;

	PropertyCache* getRegistryPropertyCache(lua_State* L)
	{
		lua_pushlightuserdata(L, &property_cache_key);
		lua_rawget(L, LUA_REGISTRYINDEX);
		const auto owner = static_cast<PropertyCacheOwner*>(lua_touserdata(L, -1));
		const auto cache = owner ? owner->cache : nullptr;
		lua_pop(L, 1);
		return cache;
	}

	void unindexPropertyCache(PropertyCache* cache)
	{
		auto& index = property_cache_index;
		if (index.last_cache == cache)
		{
			index.last_state = nullptr;
			index.last_cache = nullptr;
		}
		const auto it = index.states.find(cache->state);
		// A replaced owner's finalizer must not erase the new binding.
		if (it != index.states.end() && it->second == cache)
			index.states.erase(it);
	}

	int destroyPropertyCache(lua_State* L)
	{
		const auto owner = static_cast<PropertyCacheOwner*>(lua_touserdata(L, 1));
		if (const auto cache = owner->cache)
		{
			owner->cache = nullptr;
			unindexPropertyCache(cache);
			delete cache;
		}
		return 0;
	}
}

void lstg::InitGameObjectPropertyHash(lua_State* L)
{
	lua_newtable(L);
	lua_pushcfunction(L, destroyPropertyCache);
	lua_setfield(L, -2, "__gc");
	const auto owner = new (lua_newuserdata(L, sizeof(PropertyCacheOwner))) PropertyCacheOwner();
	lua_pushvalue(L, -2);
	lua_setmetatable(L, -2);
	lua_remove(L, -2);
	const auto cache = owner->cache = new PropertyCache();
	cache->state = L;
	cache->properties.reserve(prop_map.size());

	// The userdata environment keeps every interned name alive in this VM.
	lua_createtable(L, 0, static_cast<int>(prop_map.size()));
	for (const auto& it : prop_map)
	{
		lua_pushlstring(L, it.first.data(), it.first.size());
		cache->properties.emplace(lua_tolstring(L, -1, nullptr), it.second);
		lua_pushboolean(L, 1);
		lua_rawset(L, -3);
	}
	// Init may be called on a coroutine: keep the indexed state alive too.
	lua_pushthread(L);
	lua_pushboolean(L, 1);
	lua_rawset(L, -3);
	lua_setfenv(L, -2);

	if (const auto old_cache = getRegistryPropertyCache(L))
		unindexPropertyCache(old_cache);
	property_cache_index.states[L] = cache;

	// Registry ownership also releases the C++ map when this VM closes.
	lua_pushlightuserdata(L, &property_cache_key);
	lua_pushvalue(L, -2);
	lua_rawset(L, LUA_REGISTRYINDEX);
	lua_pop(L, 1);
}

GameObjectProperty lstg::GameObjectPropertyHash(string_view key)
{
	const auto it = prop_map.find(key);
	if (it != prop_map.end())
		return it->second;
	return GameObjectProperty::_KEY_NOT_FOUND;
}

GameObjectProperty lstg::GameObjectPropertyHash(lua_State* L, int lo, const char** str)
{
	const auto s = lua_tolstring(L, lo, nullptr);
	if (str)
		*str = s;
	if (!s)
		return GameObjectProperty::_KEY_NOT_FOUND;
	auto& index = property_cache_index;
	auto cache = index.last_cache;
	if (index.last_state != L)
	{
		const auto state = index.states.find(L);
		if (state != index.states.end())
		{
			cache = state->second;
			index.last_state = L;
			index.last_cache = cache;
		}
		else
		{
			// Unregistered coroutines can be collected before VM close. Do not
			// retain their addresses in either the state table or the fast path.
			cache = getRegistryPropertyCache(L);
		}
	}
	if (!cache)
		return GameObjectProperty::_KEY_NOT_FOUND;
	const auto it = cache->properties.find(s);
	if (it != cache->properties.end())
		return it->second;
	return GameObjectProperty::_KEY_NOT_FOUND;
}

std::unordered_map<std::string, GameObjectProperty> lstg::GetGameObjectPropertyMap()
{
	unordered_map<string, GameObjectProperty> result;
	result.reserve(prop_map.size());
	for (const auto& it : prop_map)
		result.emplace(string(it.first), it.second);
	return result;
}
