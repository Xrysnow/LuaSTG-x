#pragma once
#include "cocos2d.h"

namespace lstg
{
	enum class GameObjectProperty
	{
		X = 0,
		Y = 1,
		DX = 2,
		DY = 3,
		ROT = 4,
		OMEGA = 5,
		TIMER = 6,
		VX = 7,
		VY = 8,
		AX = 9,
		AY = 10,
		LAYER = 11,
		GROUP = 12,
		HIDE = 13,
		BOUND = 14,
		NAVI = 15,
		COLLI = 16,
		STATUS = 17,
		HSCALE = 18,
		VSCALE = 19,
		CLASS = 20,
		A = 21,
		B = 22,
		RECT = 23,
		IMG = 24,
		ANI = 25,

		RENDERMODE = 26,
		COLOR = 27,
		RES = 28,
		RES_COMPONENT = 29,
		_A = 30,
		_R = 31,
		_G = 32,
		_B = 33,
		LIGHT = 34,

		Z = 35,
		DZ = 36,
		VZ = 37,
		AZ = 38,
		ZSCALE = 39,
		QUAT = 40,

		_KEY_NOT_FOUND = -1
	};

	void InitGameObjectPropertyHash();
	GameObjectProperty GameObjectPropertyHash(const char* key);
	GameObjectProperty GameObjectPropertyHash(lua_State* L, int lo, const char** str);
}
