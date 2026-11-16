#pragma once
#include "lua_conversion/lua_conversion.hpp"
#include "fairygui/FairyGUI.h"

namespace lua
{
	LUA_TO_NATIVE_STRUCT4(fairygui::Margin, left, top, right, bottom);
	LUA_TO_LUA_STRUCT4(fairygui::Margin, left, top, right, bottom);

	LUA_TO_NATIVE_STRUCT2(fairygui::HtmlParseOptions, linkUnderline, linkColor);
	LUA_TO_LUA_STRUCT2(fairygui::HtmlParseOptions, linkUnderline, linkColor);

	template<>
	struct to_native<fairygui::EventTag> {
		static bool F(lua_State* L, int lo, fairygui::EventTag* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			if (lua_isnumber(L, lo))
				*outValue = luaL_checkinteger(L, lo);
			else if (lua_isnil(L, lo))
				*outValue = fairygui::EventTag::None;
			else
			{
				fairygui::EventTag* cobj = nullptr;
				if (!luaval_to_native(L, lo, &cobj, fName))
					return false;
				*outValue = cobj ? *cobj : fairygui::EventTag::None;
			}
			return true;
		}
	};

	template<>
	struct to_lua<fairygui::EventTag> {
		static void F(lua_State* L, const fairygui::EventTag& inValue) {
			if (!L) return;
			const auto cobj = new fairygui::EventTag(inValue);
			native_to_luaval(L, cobj);
			tolua_register_gc(L, lua_gettop(L));
		}
	};

	template<>
	struct to_native<fairygui::TextFormat> {
		static bool F(lua_State* L, int lo, fairygui::TextFormat* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			fairygui::TextFormat* cobj = nullptr;
			if (!luaval_to_native(L, lo, &cobj, fName) || !cobj)
				return false;
			*outValue = *cobj;
			return true;
		}
	};

	template<>
	struct to_lua<fairygui::TextFormat> {
		static void F(lua_State* L, const fairygui::TextFormat& inValue) {
			if (!L) return;
			const auto cobj = new fairygui::TextFormat(inValue);
			native_to_luaval(L, cobj);
			tolua_register_gc(L, lua_gettop(L));
		}
	};

	template<>
	struct to_native<fairygui::TweenValue> {
		static bool F(lua_State* L, int lo, fairygui::TweenValue* outValue, const char* fName = "") {
			LUA_CHECK_TO_NATIVE;
			fairygui::TweenValue* cobj = nullptr;
			if (!luaval_to_native(L, lo, &cobj, fName) || !cobj)
				return false;
			*outValue = *cobj;
			return true;
		}
	};

	template<>
	struct to_lua<fairygui::TweenValue> {
		static void F(lua_State* L, const fairygui::TweenValue& inValue) {
			if (!L) return;
			const auto cobj = new fairygui::TweenValue(inValue);
			native_to_luaval(L, cobj);
			tolua_register_gc(L, lua_gettop(L));
		}
	};
}
