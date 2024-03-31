#include "lua_cc_fairygui_manual.hpp"
#include "lua_cc_fairygui_auto.hpp"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "../LSTG/Util/UtilLuaConversion.h"
#include "FairyGUI.h"
#include "GLoader3D.h"
#include "tween/EaseManager.h"
#include "tween/GPath.h"
#include "display/FUISprite.h"
#include "utils/html/HtmlElement.h"
#include "utils/html/HtmlObject.h"
#include "utils/html/HtmlParser.h"
#include "Margin.h"
#include "utils/ByteBuffer.h"
#include "display/BitmapFont.h"

#ifndef LUA_CHECK_COBJ_TYPE
#ifdef LUA_DEBUG
#define LUA_CHECK_COBJ_TYPE(L, TYPE, NAME) if(!tolua_isusertype((L), 1, (TYPE), 0, nullptr)) { return luaL_error((L), "invalid 'cobj' in '%s': '%s', expects '%s'", NAME, tolua_typename((L), 1), (TYPE)); }
#else
#define LUA_CHECK_COBJ_TYPE(L, TYPE, NAME) (void)(TYPE);
#endif
#endif
#ifndef LUA_CHECK_COBJ
#ifdef LUA_DEBUG
#define LUA_CHECK_COBJ(L, COBJ, NAME) if(!(COBJ)) { return luaL_error((L), "invalid 'cobj' in '%s'", NAME); }
#else
#define LUA_CHECK_COBJ(L, COBJ, NAME)
#endif
#endif
#ifndef LUA_CHECK_PARAMETER
#define LUA_CHECK_PARAMETER(L, OK, NAME) if(!(OK)) { return luaL_error((L), "invalid arguments in '%s'", NAME); }
#endif
#ifndef LUA_PARAMETER_ERROR
#define LUA_PARAMETER_ERROR(L, NAME, ARGC, EXPECT) return luaL_error((L), "wrong number of arguments in '%s': %d, expects %s", NAME, (ARGC), EXPECT);
#endif

using ::lua::native_to_luaval;

#define GOBJECT_AS(T)\
	int lua_cc_fairygui_GObject_as##T(lua_State * tolua_S) {\
		constexpr auto LUA_OBJ_TYPE = "fgui.GObject";\
		constexpr auto LUA_FNAME = "fgui.GObject:as" #T;\
		LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);\
		auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);\
		LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);\
		const int argc = lua_gettop(tolua_S) - 1;\
		if (argc == 0) {\
			native_to_luaval(tolua_S, cobj->as<fairygui::T>());\
			return 1;\
		}\
		LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");\
	}

#define REG_GOBJECT_AS(T)\
	tolua_function(L, "as" #T, lua_cc_fairygui_GObject_as##T);

GOBJECT_AS(GComponent)
GOBJECT_AS(GGraph)
GOBJECT_AS(GGroup)
GOBJECT_AS(GLoader)
GOBJECT_AS(GLoader3D)
GOBJECT_AS(GMovieClip)
GOBJECT_AS(GTextField)
GOBJECT_AS(GImage)
GOBJECT_AS(GBasicTextField)
GOBJECT_AS(GTextInput)
GOBJECT_AS(GRichTextField)
GOBJECT_AS(GComboBox)
GOBJECT_AS(GScrollBar)
GOBJECT_AS(Window)
GOBJECT_AS(GRoot)
GOBJECT_AS(GProgressBar)
GOBJECT_AS(GButton)
GOBJECT_AS(GSlider)
GOBJECT_AS(GList)
GOBJECT_AS(GLabel)
GOBJECT_AS(GTree)

static void extendGObject(lua_State* L)
{
	lua_pushstring(L, "fgui.GObject");
	lua_rawget(L, LUA_REGISTRYINDEX);
	if (lua_istable(L, -1))
	{
		REG_GOBJECT_AS(GComponent)
		REG_GOBJECT_AS(GGraph)
		REG_GOBJECT_AS(GGroup)
		REG_GOBJECT_AS(GLoader)
		REG_GOBJECT_AS(GLoader3D)
		REG_GOBJECT_AS(GMovieClip)
		REG_GOBJECT_AS(GTextField)
		REG_GOBJECT_AS(GImage)
		REG_GOBJECT_AS(GBasicTextField)
		REG_GOBJECT_AS(GTextInput)
		REG_GOBJECT_AS(GRichTextField)
		REG_GOBJECT_AS(GComboBox)
		REG_GOBJECT_AS(GScrollBar)
		REG_GOBJECT_AS(Window)
		REG_GOBJECT_AS(GRoot)
		REG_GOBJECT_AS(GProgressBar)
		REG_GOBJECT_AS(GButton)
		REG_GOBJECT_AS(GSlider)
		REG_GOBJECT_AS(GList)
		REG_GOBJECT_AS(GLabel)
		REG_GOBJECT_AS(GTree)
	}
	lua_pop(L, 1);
}

int register_all_cc_fairygui_manual(lua_State* L)
{
	if (!L)
		return 0;
	extendGObject(L);
	return 0;
}
