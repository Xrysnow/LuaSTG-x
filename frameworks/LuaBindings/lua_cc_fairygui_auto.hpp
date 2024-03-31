#pragma once
#include "base/ccConfig.h"
#include "lua_conversion/lua_conversion.hpp"
#include "fairygui/FairyGUI.h"

extern int luaReg_fgui_fguiPackageItemType(lua_State* lua_S);
extern int luaReg_fgui_fguiObjectType(lua_State* lua_S);
extern int luaReg_fgui_fguiButtonMode(lua_State* lua_S);
extern int luaReg_fgui_fguiChildrenRenderOrder(lua_State* lua_S);
extern int luaReg_fgui_fguiOverflowType(lua_State* lua_S);
extern int luaReg_fgui_fguiScrollType(lua_State* lua_S);
extern int luaReg_fgui_fguiScrollBarDisplayType(lua_State* lua_S);
extern int luaReg_fgui_fguiLoaderFillType(lua_State* lua_S);
extern int luaReg_fgui_fguiProgressTitleType(lua_State* lua_S);
extern int luaReg_fgui_fguiListLayoutType(lua_State* lua_S);
extern int luaReg_fgui_fguiListSelectionMode(lua_State* lua_S);
extern int luaReg_fgui_fguiGroupLayoutType(lua_State* lua_S);
extern int luaReg_fgui_fguiPopupDirection(lua_State* lua_S);
extern int luaReg_fgui_fguiAutoSizeType(lua_State* lua_S);
extern int luaReg_fgui_fguiFlipType(lua_State* lua_S);
extern int luaReg_fgui_fguiTransitionActionType(lua_State* lua_S);
extern int luaReg_fgui_fguiFillMethod(lua_State* lua_S);
extern int luaReg_fgui_fguiFillOrigin(lua_State* lua_S);
extern int luaReg_fgui_fguiObjectPropID(lua_State* lua_S);
extern int luaReg_fgui_fguiUIConfig(lua_State* lua_S);
extern int luaReg_fgui_fguiInputEvent(lua_State* lua_S);
extern int luaReg_fgui_fguiEventContext(lua_State* lua_S);
extern int luaReg_fgui_fguiUIEventType(lua_State* lua_S);
extern int luaReg_fgui_fguiEventTag(lua_State* lua_S);
extern int luaReg_fgui_fguiUIEventDispatcher(lua_State* lua_S);
extern int luaReg_fgui_fguiGController(lua_State* lua_S);
extern int luaReg_fgui_fguiRelationType(lua_State* lua_S);
extern int luaReg_fgui_fguiRelationItem(lua_State* lua_S);
extern int luaReg_fgui_fguiRelations(lua_State* lua_S);
extern int luaReg_fgui_fguiEaseType(lua_State* lua_S);
extern int luaReg_fgui_fguiGearBase(lua_State* lua_S);
extern int luaReg_fgui_fguiGObject(lua_State* lua_S);
extern int luaReg_fgui_fguiPackageItem(lua_State* lua_S);
extern int luaReg_fgui_fguiUIPackage(lua_State* lua_S);
extern int luaReg_fgui_fguiGImage(lua_State* lua_S);
extern int luaReg_fgui_fguiGMovieClip(lua_State* lua_S);
extern int luaReg_fgui_fguiTextFormat(lua_State* lua_S);
extern int luaReg_fgui_fguiFUILabel(lua_State* lua_S);
extern int luaReg_fgui_fguiGTextField(lua_State* lua_S);
extern int luaReg_fgui_fguiGBasicTextField(lua_State* lua_S);
extern int luaReg_fgui_fguiFUIRichText(lua_State* lua_S);
extern int luaReg_fgui_fguiGRichTextField(lua_State* lua_S);
extern int luaReg_fgui_fguiFUIInput(lua_State* lua_S);
extern int luaReg_fgui_fguiGTextInput(lua_State* lua_S);
extern int luaReg_fgui_fguiGGraph(lua_State* lua_S);
extern int luaReg_fgui_fguiGLoader(lua_State* lua_S);
extern int luaReg_fgui_fguiGGroup(lua_State* lua_S);
extern int luaReg_fgui_fguiScrollPane(lua_State* lua_S);
extern int luaReg_fgui_fguiTransition(lua_State* lua_S);
extern int luaReg_fgui_fguiFUIContainer(lua_State* lua_S);
extern int luaReg_fgui_fguiIHitTest(lua_State* lua_S);
extern int luaReg_fgui_fguiPixelHitTestData(lua_State* lua_S);
extern int luaReg_fgui_fguiPixelHitTest(lua_State* lua_S);
extern int luaReg_fgui_fguiGComponent(lua_State* lua_S);
extern int luaReg_fgui_fguiGLabel(lua_State* lua_S);
extern int luaReg_fgui_fguiGButton(lua_State* lua_S);
extern int luaReg_fgui_fguiGList(lua_State* lua_S);
extern int luaReg_fgui_fguiGComboBox(lua_State* lua_S);
extern int luaReg_fgui_fguiGProgressBar(lua_State* lua_S);
extern int luaReg_fgui_fguiGSlider(lua_State* lua_S);
extern int luaReg_fgui_fguiGScrollBar(lua_State* lua_S);
extern int luaReg_fgui_fguiGTreeNode(lua_State* lua_S);
extern int luaReg_fgui_fguiGTree(lua_State* lua_S);
extern int luaReg_fgui_fguiIUISource(lua_State* lua_S);
extern int luaReg_fgui_fguiWindow(lua_State* lua_S);
extern int luaReg_fgui_fguiInputProcessor(lua_State* lua_S);
extern int luaReg_fgui_fguiGRoot(lua_State* lua_S);
extern int luaReg_fgui_fguiPopupMenu(lua_State* lua_S);
extern int luaReg_fgui_fguiUIObjectFactory(lua_State* lua_S);
extern int luaReg_fgui_fguiDragDropManager(lua_State* lua_S);
extern int luaReg_fgui_fguiTweenPropType(lua_State* lua_S);
extern int luaReg_fgui_fguiGTweener(lua_State* lua_S);
extern int luaReg_fgui_fguiGTween(lua_State* lua_S);
extern int luaReg_fgui_fguiGLoader3D(lua_State* lua_S);
extern int luaReg_fgui_fguiEaseManager(lua_State* lua_S);
extern int luaReg_fgui_fguiGPath(lua_State* lua_S);
extern int luaReg_fgui_fguiFUISprite(lua_State* lua_S);
extern int luaReg_fgui_fguiHtmlElement(lua_State* lua_S);
extern int luaReg_fgui_fguiHtmlObject(lua_State* lua_S);

inline int luaReg_fgui(lua_State* lua_S)
{
	luaReg_fgui_fguiPackageItemType(lua_S);
	luaReg_fgui_fguiObjectType(lua_S);
	luaReg_fgui_fguiButtonMode(lua_S);
	luaReg_fgui_fguiChildrenRenderOrder(lua_S);
	luaReg_fgui_fguiOverflowType(lua_S);
	luaReg_fgui_fguiScrollType(lua_S);
	luaReg_fgui_fguiScrollBarDisplayType(lua_S);
	luaReg_fgui_fguiLoaderFillType(lua_S);
	luaReg_fgui_fguiProgressTitleType(lua_S);
	luaReg_fgui_fguiListLayoutType(lua_S);
	luaReg_fgui_fguiListSelectionMode(lua_S);
	luaReg_fgui_fguiGroupLayoutType(lua_S);
	luaReg_fgui_fguiPopupDirection(lua_S);
	luaReg_fgui_fguiAutoSizeType(lua_S);
	luaReg_fgui_fguiFlipType(lua_S);
	luaReg_fgui_fguiTransitionActionType(lua_S);
	luaReg_fgui_fguiFillMethod(lua_S);
	luaReg_fgui_fguiFillOrigin(lua_S);
	luaReg_fgui_fguiObjectPropID(lua_S);
	luaReg_fgui_fguiUIConfig(lua_S);
	luaReg_fgui_fguiInputEvent(lua_S);
	luaReg_fgui_fguiEventContext(lua_S);
	luaReg_fgui_fguiUIEventType(lua_S);
	luaReg_fgui_fguiEventTag(lua_S);
	luaReg_fgui_fguiUIEventDispatcher(lua_S);
	luaReg_fgui_fguiGController(lua_S);
	luaReg_fgui_fguiRelationType(lua_S);
	luaReg_fgui_fguiRelationItem(lua_S);
	luaReg_fgui_fguiRelations(lua_S);
	luaReg_fgui_fguiEaseType(lua_S);
	luaReg_fgui_fguiGearBase(lua_S);
	luaReg_fgui_fguiGObject(lua_S);
	luaReg_fgui_fguiPackageItem(lua_S);
	luaReg_fgui_fguiUIPackage(lua_S);
	luaReg_fgui_fguiGImage(lua_S);
	luaReg_fgui_fguiGMovieClip(lua_S);
	luaReg_fgui_fguiTextFormat(lua_S);
	luaReg_fgui_fguiFUILabel(lua_S);
	luaReg_fgui_fguiGTextField(lua_S);
	luaReg_fgui_fguiGBasicTextField(lua_S);
	luaReg_fgui_fguiFUIRichText(lua_S);
	luaReg_fgui_fguiGRichTextField(lua_S);
	luaReg_fgui_fguiFUIInput(lua_S);
	luaReg_fgui_fguiGTextInput(lua_S);
	luaReg_fgui_fguiGGraph(lua_S);
	luaReg_fgui_fguiGLoader(lua_S);
	luaReg_fgui_fguiGGroup(lua_S);
	luaReg_fgui_fguiScrollPane(lua_S);
	luaReg_fgui_fguiTransition(lua_S);
	luaReg_fgui_fguiFUIContainer(lua_S);
	luaReg_fgui_fguiIHitTest(lua_S);
	luaReg_fgui_fguiPixelHitTestData(lua_S);
	luaReg_fgui_fguiPixelHitTest(lua_S);
	luaReg_fgui_fguiGComponent(lua_S);
	luaReg_fgui_fguiGLabel(lua_S);
	luaReg_fgui_fguiGButton(lua_S);
	luaReg_fgui_fguiGList(lua_S);
	luaReg_fgui_fguiGComboBox(lua_S);
	luaReg_fgui_fguiGProgressBar(lua_S);
	luaReg_fgui_fguiGSlider(lua_S);
	luaReg_fgui_fguiGScrollBar(lua_S);
	luaReg_fgui_fguiGTreeNode(lua_S);
	luaReg_fgui_fguiGTree(lua_S);
	luaReg_fgui_fguiIUISource(lua_S);
	luaReg_fgui_fguiWindow(lua_S);
	luaReg_fgui_fguiInputProcessor(lua_S);
	luaReg_fgui_fguiGRoot(lua_S);
	luaReg_fgui_fguiPopupMenu(lua_S);
	luaReg_fgui_fguiUIObjectFactory(lua_S);
	luaReg_fgui_fguiDragDropManager(lua_S);
	luaReg_fgui_fguiTweenPropType(lua_S);
	luaReg_fgui_fguiGTweener(lua_S);
	luaReg_fgui_fguiGTween(lua_S);
	luaReg_fgui_fguiGLoader3D(lua_S);
	luaReg_fgui_fguiEaseManager(lua_S);
	luaReg_fgui_fguiGPath(lua_S);
	luaReg_fgui_fguiFUISprite(lua_S);
	luaReg_fgui_fguiHtmlElement(lua_S);
	luaReg_fgui_fguiHtmlObject(lua_S);
	return 0;
}

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
