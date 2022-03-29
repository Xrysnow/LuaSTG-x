#include "GameObjectPropertyHash.h"
#include "cocos2d.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "platform/CCPlatformMacros.h"
#include "LogSystem.h"
#include <unordered_map>
#if CC_64BITS && (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32) && (CC_TARGET_PLATFORM != CC_PLATFORM_LINUX)
#define HASH_OFFSET (-3)
#else
#define HASH_OFFSET (-2)
#endif

using namespace std;
using namespace lstg;
//#define PROP_OLD_STYLE

static unordered_map<string, GameObjectProperty> prop_map = {
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
static unordered_map<uint32_t, GameObjectProperty> prop_hash_map;

void lstg::InitGameObjectPropertyHash()
{
	prop_hash_map.clear();
	const auto L = cocos2d::LuaEngine::getInstance()->getLuaStack()->getLuaState();
	const auto top = lua_gettop(L);
	if (!luaL_dostring(L, "return ffi.abi('gc64')"))
	{
		const auto gc64 = lua_toboolean(L, -1);
#if HASH_OFFSET == -3
		if (!gc64)
#else
		if (gc64)
#endif
		{
			const auto msg = cocos2d::StringUtils::format(
				"HASH_OFFSET is invalid, please set it to %d and recompile", gc64 ? -3 : -2);
			XERROR("%s", msg.c_str());
			cocos2d::ccMessageBox(msg.c_str(), "Error");
		}
	}
	lua_settop(L, top);
	for (auto& it : prop_map)
	{
		lua_pushstring(L, it.first.c_str());
		const auto hash = ((const uint32_t*)lua_tolstring(L, -1, nullptr))[HASH_OFFSET];
		lua_pop(L, 1);
		prop_hash_map[hash] = it.second;
	}
}

GameObjectProperty lstg::GameObjectPropertyHash(const char* key)
{
	const auto hash = ((const uint32_t*)key)[HASH_OFFSET];
	const auto it = prop_hash_map.find(hash);
	if (it != prop_hash_map.end())
		return it->second;
	return GameObjectProperty::_KEY_NOT_FOUND;
}

GameObjectProperty lstg::GameObjectPropertyHash(lua_State* L, int lo, const char** str)
{
	const auto s = lua_tolstring(L, lo, nullptr);
	if (str)
		*str = s;
	// hack into lua
	const auto hash = ((const uint32_t*)s)[HASH_OFFSET];
	const auto it = prop_hash_map.find(hash);
	if (it != prop_hash_map.end())
		return it->second;
	return GameObjectProperty::_KEY_NOT_FOUND;
}

std::unordered_map<std::string, GameObjectProperty> lstg::GetGameObjectPropertyMap()
{
	return prop_map;
}
