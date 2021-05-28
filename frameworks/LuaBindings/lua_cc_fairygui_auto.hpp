#pragma once
#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif
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

namespace lstg
{
	namespace lua
	{
#ifndef CHECK_TO_NATIVE
#define CHECK_TO_NATIVE const auto top = lua_gettop(L); if (nullptr == L || nullptr == outValue || top < lo) return false;
#endif
		template<>
		struct to_native<fairygui::Margin> {
			static bool F(lua_State* L, int lo, fairygui::Margin* outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
				if (!lua_istable(L, lo))
					return false;
				return luaval_field_to_native(L, lo, "left", &outValue->left, fName) &&
					luaval_field_to_native(L, lo, "top", &outValue->top, fName) &&
					luaval_field_to_native(L, lo, "right", &outValue->right, fName) &&
					luaval_field_to_native(L, lo, "bottom", &outValue->bottom, fName);
			}
		};

		template<>
		struct to_lua<fairygui::Margin> {
			static void F(lua_State* L, const fairygui::Margin& inValue) {
				if (!L) return;
				lua_createtable(L, 0, 4);
				native_to_luaval_field(L, -1, "left", inValue.left);
				native_to_luaval_field(L, -1, "top", inValue.top);
				native_to_luaval_field(L, -1, "right", inValue.right);
				native_to_luaval_field(L, -1, "bottom", inValue.bottom);
			}
		};

		template<>
		struct to_native<fairygui::EventTag> {
			static bool F(lua_State* L, int lo, fairygui::EventTag* outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
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
			}
		};

		template<>
		struct to_native<fairygui::TextFormat> {
			static bool F(lua_State* L, int lo, fairygui::TextFormat* outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
				fairygui::TextFormat* cobj = nullptr;
				if (!luaval_to_native(L, lo, &cobj, fName))
					return false;
				if(cobj)
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
			}
		};

		template<>
		struct to_native<fairygui::HtmlParseOptions> {
			static bool F(lua_State* L, int lo, fairygui::HtmlParseOptions* outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
				fairygui::HtmlParseOptions* cobj = nullptr;
				if (!luaval_to_native(L, lo, &cobj, fName))
					return false;
				if(cobj)
					*outValue = *cobj;
				return true;
			}
		};

		template<>
		struct to_lua<fairygui::HtmlParseOptions> {
			static void F(lua_State* L, const fairygui::HtmlParseOptions& inValue) {
				if (!L) return;
				const auto cobj = new fairygui::HtmlParseOptions(inValue);
				native_to_luaval(L, cobj);
			}
		};

		template<>
		struct to_native<fairygui::TweenValue> {
			static bool F(lua_State* L, int lo, fairygui::TweenValue* outValue, const char* fName = "") {
				CHECK_TO_NATIVE;
				fairygui::TweenValue* cobj = nullptr;
				if (!luaval_to_native(L, lo, &cobj, fName))
					return false;
				if(cobj)
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
			}
		};
	}
}

int register_all_cc_fairygui(lua_State* tolua_S);
