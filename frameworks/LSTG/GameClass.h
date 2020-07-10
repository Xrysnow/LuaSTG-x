#pragma once
#include "GameObjectSymbol.h"
#include <array>

namespace lstg
{
	namespace symbol
	{
		class Block;
	}
	class GameClass
	{
	public:
		GameClass();
		~GameClass();
		static GameClass* registerClass(lua_State* L);
		static GameClass* getByID(uint32_t id);
		static void clear(lua_State* L);

		void pushLua(lua_State* L);
		void pushLuaFrameFunc(lua_State* L);
		void pushLuaRenderFunc(lua_State* L);

		uint32_t id = 0;
		symbol::Block* frameBlock = nullptr;
		bool isDefaultFrame = false;
		bool isDefaultRender = false;
		bool extProperty = false;
		bool is3D = false;
	private:
		static const uint32_t MAX_CLASS_COUNT = 4096;
		static std::array<GameClass, MAX_CLASS_COUNT> classes;
		static cocos2d::Map<uint32_t, symbol::Block*> classFrameBlocks;
	};
}
