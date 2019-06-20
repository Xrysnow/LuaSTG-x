#include "GameObjectPropertyHash.h"
#include "cocos2d.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include <unordered_map>

#include "platform/CCPlatformMacros.h"
#if CC_64BITS
#define HASH_OFFSET -3
#else
#define HASH_OFFSET -2
#endif

using namespace std;
using namespace lstg;

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

	{ "blend",	GameObjectProperty::BLEND	},
	{ "color",	GameObjectProperty::COLOR	},
	{ "res",	GameObjectProperty::RES		},
	{ "_a",		GameObjectProperty::_A		},
	{ "_r",		GameObjectProperty::_R		},
	{ "_g",		GameObjectProperty::_G		},
	{ "_b",		GameObjectProperty::_B		},
	{ "light",	GameObjectProperty::LIGHT	},
	{ "shader",	GameObjectProperty::SHADER	},

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
	for (auto it : prop_map)
	{
		lua_pushstring(L, it.first.c_str());
		const auto hash = ((uint32_t*)lua_tolstring(L, -1, nullptr))[HASH_OFFSET];
		lua_pop(L, 1);
		prop_hash_map[hash] = it.second;
	}
}

GameObjectProperty lstg::GameObjectPropertyHash(const char* key)
{
	const auto hash = ((uint32_t*)key)[HASH_OFFSET];
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
	const auto hash = ((uint32_t*)s)[HASH_OFFSET];
	const auto it = prop_hash_map.find(hash);
	if (it != prop_hash_map.end())
		return it->second;
	return GameObjectProperty::_KEY_NOT_FOUND;
}
