#include "LWBuiltInFunction.h"
#include "AppFrame.h"
#include "../Classes/XLuaModuleRegistry.h"

using namespace std;
using namespace lstg;
using cocos2d::Color4B;

// Misc
LUA_REGISTER_FUNC_DEF(lstg, Snapshot)
{
	LAPP.snapShot(luaL_checkstring(L, 1));
	return 0;
}
// Debug
LUA_REGISTER_FUNC_DEF(lstg, ObjTable)
{
	return LPOOL.GetObjectTable(L);
}
// Deprecated
LUA_REGISTER_FUNC_DEF(lstg, UpdateObjList)
{
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, RegTTF)
{
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, UpdateSound)
{
	return 0;
}
LUA_REGISTER_FUNC_DEF(lstg, Execute)
{
	return 0;
}
