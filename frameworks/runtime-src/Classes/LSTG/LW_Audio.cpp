#include "LW_Audio.h"
#include "AppFrame.h"
#include "UtilLua.h"
#include "UtilLuaRes.h"

using namespace std;
using namespace lstg;

#ifdef PlaySound
#undef PlaySound
#endif

#define GET_SOUND auto p = lua::toResSound(L, 1);\
	if (!p) return luaL_error(L, "sound '%s' not found.", lua_tostring(L, 1));
#define GET_MUSIC auto p = lua::toResMusic(L, 1);\
	if (!p) return luaL_error(L, "sound '%s' not found.", lua_tostring(L, 1));

static int GetFFT(lua_State* L) noexcept
{
	GET_MUSIC;
	lua::cptr_to_luaval(L, p->getFFT(), "float*");
	lua_pushnumber(L, p->getFFTSize());
	return 2;
}

vector<luaL_Reg> lstg::LW_Audio()
{
	vector<luaL_Reg> ret = {
		{ "GetFFT", &GetFFT },//new
	};
	return ret;
}
