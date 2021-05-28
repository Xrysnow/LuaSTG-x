#include "lua_cc_fairygui_auto.hpp"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Util/UtilLuaConversion.h"
using namespace lstg::lua;

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

int lua_register_cc_fairygui_PackageItemType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "PackageItemType", 0);
	tolua_beginmodule(tolua_S,"PackageItemType");
		tolua_constant(tolua_S, "IMAGE", (lua_Number)fairygui::PackageItemType::IMAGE);
		tolua_constant(tolua_S, "MOVIECLIP", (lua_Number)fairygui::PackageItemType::MOVIECLIP);
		tolua_constant(tolua_S, "SOUND", (lua_Number)fairygui::PackageItemType::SOUND);
		tolua_constant(tolua_S, "COMPONENT", (lua_Number)fairygui::PackageItemType::COMPONENT);
		tolua_constant(tolua_S, "ATLAS", (lua_Number)fairygui::PackageItemType::ATLAS);
		tolua_constant(tolua_S, "FONT", (lua_Number)fairygui::PackageItemType::FONT);
		tolua_constant(tolua_S, "SWF", (lua_Number)fairygui::PackageItemType::SWF);
		tolua_constant(tolua_S, "MISC", (lua_Number)fairygui::PackageItemType::MISC);
		tolua_constant(tolua_S, "UNKNOWN", (lua_Number)fairygui::PackageItemType::UNKNOWN);
		tolua_constant(tolua_S, "SPINE", (lua_Number)fairygui::PackageItemType::SPINE);
		tolua_constant(tolua_S, "DRAGONBONES", (lua_Number)fairygui::PackageItemType::DRAGONBONES);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_ObjectType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "ObjectType", 0);
	tolua_beginmodule(tolua_S,"ObjectType");
		tolua_constant(tolua_S, "IMAGE", (lua_Number)fairygui::ObjectType::IMAGE);
		tolua_constant(tolua_S, "MOVIECLIP", (lua_Number)fairygui::ObjectType::MOVIECLIP);
		tolua_constant(tolua_S, "SWF", (lua_Number)fairygui::ObjectType::SWF);
		tolua_constant(tolua_S, "GRAPH", (lua_Number)fairygui::ObjectType::GRAPH);
		tolua_constant(tolua_S, "LOADER", (lua_Number)fairygui::ObjectType::LOADER);
		tolua_constant(tolua_S, "GROUP", (lua_Number)fairygui::ObjectType::GROUP);
		tolua_constant(tolua_S, "TEXT", (lua_Number)fairygui::ObjectType::TEXT);
		tolua_constant(tolua_S, "RICHTEXT", (lua_Number)fairygui::ObjectType::RICHTEXT);
		tolua_constant(tolua_S, "INPUTTEXT", (lua_Number)fairygui::ObjectType::INPUTTEXT);
		tolua_constant(tolua_S, "COMPONENT", (lua_Number)fairygui::ObjectType::COMPONENT);
		tolua_constant(tolua_S, "LIST", (lua_Number)fairygui::ObjectType::LIST);
		tolua_constant(tolua_S, "LABEL", (lua_Number)fairygui::ObjectType::LABEL);
		tolua_constant(tolua_S, "BUTTON", (lua_Number)fairygui::ObjectType::BUTTON);
		tolua_constant(tolua_S, "COMBOBOX", (lua_Number)fairygui::ObjectType::COMBOBOX);
		tolua_constant(tolua_S, "PROGRESSBAR", (lua_Number)fairygui::ObjectType::PROGRESSBAR);
		tolua_constant(tolua_S, "SLIDER", (lua_Number)fairygui::ObjectType::SLIDER);
		tolua_constant(tolua_S, "SCROLLBAR", (lua_Number)fairygui::ObjectType::SCROLLBAR);
		tolua_constant(tolua_S, "TREE", (lua_Number)fairygui::ObjectType::TREE);
		tolua_constant(tolua_S, "LOADER3D", (lua_Number)fairygui::ObjectType::LOADER3D);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_ButtonMode(lua_State* tolua_S)
{

	tolua_module(tolua_S, "ButtonMode", 0);
	tolua_beginmodule(tolua_S,"ButtonMode");
		tolua_constant(tolua_S, "COMMON", (lua_Number)fairygui::ButtonMode::COMMON);
		tolua_constant(tolua_S, "CHECK", (lua_Number)fairygui::ButtonMode::CHECK);
		tolua_constant(tolua_S, "RADIO", (lua_Number)fairygui::ButtonMode::RADIO);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_ChildrenRenderOrder(lua_State* tolua_S)
{

	tolua_module(tolua_S, "ChildrenRenderOrder", 0);
	tolua_beginmodule(tolua_S,"ChildrenRenderOrder");
		tolua_constant(tolua_S, "ASCENT", (lua_Number)fairygui::ChildrenRenderOrder::ASCENT);
		tolua_constant(tolua_S, "DESCENT", (lua_Number)fairygui::ChildrenRenderOrder::DESCENT);
		tolua_constant(tolua_S, "ARCH", (lua_Number)fairygui::ChildrenRenderOrder::ARCH);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_OverflowType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "OverflowType", 0);
	tolua_beginmodule(tolua_S,"OverflowType");
		tolua_constant(tolua_S, "VISIBLE", (lua_Number)fairygui::OverflowType::VISIBLE);
		tolua_constant(tolua_S, "HIDDEN", (lua_Number)fairygui::OverflowType::HIDDEN);
		tolua_constant(tolua_S, "SCROLL", (lua_Number)fairygui::OverflowType::SCROLL);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_ScrollType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "ScrollType", 0);
	tolua_beginmodule(tolua_S,"ScrollType");
		tolua_constant(tolua_S, "HORIZONTAL", (lua_Number)fairygui::ScrollType::HORIZONTAL);
		tolua_constant(tolua_S, "VERTICAL", (lua_Number)fairygui::ScrollType::VERTICAL);
		tolua_constant(tolua_S, "BOTH", (lua_Number)fairygui::ScrollType::BOTH);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_ScrollBarDisplayType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "ScrollBarDisplayType", 0);
	tolua_beginmodule(tolua_S,"ScrollBarDisplayType");
		tolua_constant(tolua_S, "DEFAULT", (lua_Number)fairygui::ScrollBarDisplayType::DEFAULT);
		tolua_constant(tolua_S, "VISIBLE", (lua_Number)fairygui::ScrollBarDisplayType::VISIBLE);
		tolua_constant(tolua_S, "AUTO", (lua_Number)fairygui::ScrollBarDisplayType::AUTO);
		tolua_constant(tolua_S, "HIDDEN", (lua_Number)fairygui::ScrollBarDisplayType::HIDDEN);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_LoaderFillType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "LoaderFillType", 0);
	tolua_beginmodule(tolua_S,"LoaderFillType");
		tolua_constant(tolua_S, "NONE", (lua_Number)fairygui::LoaderFillType::NONE);
		tolua_constant(tolua_S, "SCALE", (lua_Number)fairygui::LoaderFillType::SCALE);
		tolua_constant(tolua_S, "SCALE_MATCH_HEIGHT", (lua_Number)fairygui::LoaderFillType::SCALE_MATCH_HEIGHT);
		tolua_constant(tolua_S, "SCALE_MATCH_WIDTH", (lua_Number)fairygui::LoaderFillType::SCALE_MATCH_WIDTH);
		tolua_constant(tolua_S, "SCALE_FREE", (lua_Number)fairygui::LoaderFillType::SCALE_FREE);
		tolua_constant(tolua_S, "SCALE_NO_BORDER", (lua_Number)fairygui::LoaderFillType::SCALE_NO_BORDER);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_ProgressTitleType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "ProgressTitleType", 0);
	tolua_beginmodule(tolua_S,"ProgressTitleType");
		tolua_constant(tolua_S, "PERCENT", (lua_Number)fairygui::ProgressTitleType::PERCENT);
		tolua_constant(tolua_S, "VALUE_MAX", (lua_Number)fairygui::ProgressTitleType::VALUE_MAX);
		tolua_constant(tolua_S, "VALUE", (lua_Number)fairygui::ProgressTitleType::VALUE);
		tolua_constant(tolua_S, "MAX", (lua_Number)fairygui::ProgressTitleType::MAX);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_ListLayoutType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "ListLayoutType", 0);
	tolua_beginmodule(tolua_S,"ListLayoutType");
		tolua_constant(tolua_S, "SINGLE_COLUMN", (lua_Number)fairygui::ListLayoutType::SINGLE_COLUMN);
		tolua_constant(tolua_S, "SINGLE_ROW", (lua_Number)fairygui::ListLayoutType::SINGLE_ROW);
		tolua_constant(tolua_S, "FLOW_HORIZONTAL", (lua_Number)fairygui::ListLayoutType::FLOW_HORIZONTAL);
		tolua_constant(tolua_S, "FLOW_VERTICAL", (lua_Number)fairygui::ListLayoutType::FLOW_VERTICAL);
		tolua_constant(tolua_S, "PAGINATION", (lua_Number)fairygui::ListLayoutType::PAGINATION);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_ListSelectionMode(lua_State* tolua_S)
{

	tolua_module(tolua_S, "ListSelectionMode", 0);
	tolua_beginmodule(tolua_S,"ListSelectionMode");
		tolua_constant(tolua_S, "SINGLE", (lua_Number)fairygui::ListSelectionMode::SINGLE);
		tolua_constant(tolua_S, "MULTIPLE", (lua_Number)fairygui::ListSelectionMode::MULTIPLE);
		tolua_constant(tolua_S, "MULTIPLE_SINGLECLICK", (lua_Number)fairygui::ListSelectionMode::MULTIPLE_SINGLECLICK);
		tolua_constant(tolua_S, "NONE", (lua_Number)fairygui::ListSelectionMode::NONE);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_GroupLayoutType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "GroupLayoutType", 0);
	tolua_beginmodule(tolua_S,"GroupLayoutType");
		tolua_constant(tolua_S, "NONE", (lua_Number)fairygui::GroupLayoutType::NONE);
		tolua_constant(tolua_S, "HORIZONTAL", (lua_Number)fairygui::GroupLayoutType::HORIZONTAL);
		tolua_constant(tolua_S, "VERTICAL", (lua_Number)fairygui::GroupLayoutType::VERTICAL);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_PopupDirection(lua_State* tolua_S)
{

	tolua_module(tolua_S, "PopupDirection", 0);
	tolua_beginmodule(tolua_S,"PopupDirection");
		tolua_constant(tolua_S, "AUTO", (lua_Number)fairygui::PopupDirection::AUTO);
		tolua_constant(tolua_S, "UP", (lua_Number)fairygui::PopupDirection::UP);
		tolua_constant(tolua_S, "DOWN", (lua_Number)fairygui::PopupDirection::DOWN);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_AutoSizeType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "AutoSizeType", 0);
	tolua_beginmodule(tolua_S,"AutoSizeType");
		tolua_constant(tolua_S, "NONE", (lua_Number)fairygui::AutoSizeType::NONE);
		tolua_constant(tolua_S, "BOTH", (lua_Number)fairygui::AutoSizeType::BOTH);
		tolua_constant(tolua_S, "HEIGHT", (lua_Number)fairygui::AutoSizeType::HEIGHT);
		tolua_constant(tolua_S, "SHRINK", (lua_Number)fairygui::AutoSizeType::SHRINK);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_FlipType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "FlipType", 0);
	tolua_beginmodule(tolua_S,"FlipType");
		tolua_constant(tolua_S, "NONE", (lua_Number)fairygui::FlipType::NONE);
		tolua_constant(tolua_S, "HORIZONTAL", (lua_Number)fairygui::FlipType::HORIZONTAL);
		tolua_constant(tolua_S, "VERTICAL", (lua_Number)fairygui::FlipType::VERTICAL);
		tolua_constant(tolua_S, "BOTH", (lua_Number)fairygui::FlipType::BOTH);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_TransitionActionType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "TransitionActionType", 0);
	tolua_beginmodule(tolua_S,"TransitionActionType");
		tolua_constant(tolua_S, "XY", (lua_Number)fairygui::TransitionActionType::XY);
		tolua_constant(tolua_S, "Size", (lua_Number)fairygui::TransitionActionType::Size);
		tolua_constant(tolua_S, "Scale", (lua_Number)fairygui::TransitionActionType::Scale);
		tolua_constant(tolua_S, "Pivot", (lua_Number)fairygui::TransitionActionType::Pivot);
		tolua_constant(tolua_S, "Alpha", (lua_Number)fairygui::TransitionActionType::Alpha);
		tolua_constant(tolua_S, "Rotation", (lua_Number)fairygui::TransitionActionType::Rotation);
		tolua_constant(tolua_S, "Color", (lua_Number)fairygui::TransitionActionType::Color);
		tolua_constant(tolua_S, "Animation", (lua_Number)fairygui::TransitionActionType::Animation);
		tolua_constant(tolua_S, "Visible", (lua_Number)fairygui::TransitionActionType::Visible);
		tolua_constant(tolua_S, "Sound", (lua_Number)fairygui::TransitionActionType::Sound);
		tolua_constant(tolua_S, "Transition", (lua_Number)fairygui::TransitionActionType::Transition);
		tolua_constant(tolua_S, "Shake", (lua_Number)fairygui::TransitionActionType::Shake);
		tolua_constant(tolua_S, "ColorFilter", (lua_Number)fairygui::TransitionActionType::ColorFilter);
		tolua_constant(tolua_S, "Skew", (lua_Number)fairygui::TransitionActionType::Skew);
		tolua_constant(tolua_S, "Text", (lua_Number)fairygui::TransitionActionType::Text);
		tolua_constant(tolua_S, "Icon", (lua_Number)fairygui::TransitionActionType::Icon);
		tolua_constant(tolua_S, "Unknown", (lua_Number)fairygui::TransitionActionType::Unknown);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_FillMethod(lua_State* tolua_S)
{

	tolua_module(tolua_S, "FillMethod", 0);
	tolua_beginmodule(tolua_S,"FillMethod");
		tolua_constant(tolua_S, "None", (lua_Number)fairygui::FillMethod::None);
		tolua_constant(tolua_S, "Horizontal", (lua_Number)fairygui::FillMethod::Horizontal);
		tolua_constant(tolua_S, "Vertical", (lua_Number)fairygui::FillMethod::Vertical);
		tolua_constant(tolua_S, "Radial90", (lua_Number)fairygui::FillMethod::Radial90);
		tolua_constant(tolua_S, "Radial180", (lua_Number)fairygui::FillMethod::Radial180);
		tolua_constant(tolua_S, "Radial360", (lua_Number)fairygui::FillMethod::Radial360);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_FillOrigin(lua_State* tolua_S)
{

	tolua_module(tolua_S, "FillOrigin", 0);
	tolua_beginmodule(tolua_S,"FillOrigin");
		tolua_constant(tolua_S, "Top", (lua_Number)fairygui::FillOrigin::Top);
		tolua_constant(tolua_S, "Bottom", (lua_Number)fairygui::FillOrigin::Bottom);
		tolua_constant(tolua_S, "Left", (lua_Number)fairygui::FillOrigin::Left);
		tolua_constant(tolua_S, "Right", (lua_Number)fairygui::FillOrigin::Right);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_register_cc_fairygui_ObjectPropID(lua_State* tolua_S)
{

	tolua_module(tolua_S, "ObjectPropID", 0);
	tolua_beginmodule(tolua_S,"ObjectPropID");
		tolua_constant(tolua_S, "Text", (lua_Number)fairygui::ObjectPropID::Text);
		tolua_constant(tolua_S, "Icon", (lua_Number)fairygui::ObjectPropID::Icon);
		tolua_constant(tolua_S, "Color", (lua_Number)fairygui::ObjectPropID::Color);
		tolua_constant(tolua_S, "OutlineColor", (lua_Number)fairygui::ObjectPropID::OutlineColor);
		tolua_constant(tolua_S, "Playing", (lua_Number)fairygui::ObjectPropID::Playing);
		tolua_constant(tolua_S, "Frame", (lua_Number)fairygui::ObjectPropID::Frame);
		tolua_constant(tolua_S, "DeltaTime", (lua_Number)fairygui::ObjectPropID::DeltaTime);
		tolua_constant(tolua_S, "TimeScale", (lua_Number)fairygui::ObjectPropID::TimeScale);
		tolua_constant(tolua_S, "FontSize", (lua_Number)fairygui::ObjectPropID::FontSize);
		tolua_constant(tolua_S, "Selected", (lua_Number)fairygui::ObjectPropID::Selected);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_cc_fairygui_UIConfig_getRealFontName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIConfig";
	constexpr auto LUA_FNAME = "fgui.UIConfig:getRealFontName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::UIConfig::getRealFontName(arg0);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	if (argc == 2) {
		std::string arg0;
		bool* arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, "LUA_FNAME");
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::UIConfig::getRealFontName(arg0, arg1);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_UIConfig_registerFont(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIConfig";
	constexpr auto LUA_FNAME = "fgui.UIConfig:registerFont";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		fairygui::UIConfig::registerFont(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
static int lua_cc_fairygui_UIConfig_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_UIConfig(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.UIConfig");
	tolua_cclass(tolua_S, "UIConfig", "fgui.UIConfig", "", nullptr);

	tolua_beginmodule(tolua_S, "UIConfig");
		tolua_function(tolua_S, "getRealFontName", lua_cc_fairygui_UIConfig_getRealFontName);
		tolua_function(tolua_S, "registerFont", lua_cc_fairygui_UIConfig_registerFont);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::UIConfig).name();
	g_luaType[typeName] = "fgui.UIConfig";
	g_typeCast["UIConfig"] = "fgui.UIConfig";
	return 1;
}

int lua_cc_fairygui_InputEvent_getButton(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:getButton";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getButton();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_getKeyCode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:getKeyCode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getKeyCode();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_getMouseWheelDelta(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:getMouseWheelDelta";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getMouseWheelDelta();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_getPosition(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:getPosition";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPosition();
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_getProcessor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:getProcessor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getProcessor();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_getTarget(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:getTarget";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTarget();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_getTouch(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:getTouch";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTouch();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_getTouchId(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:getTouchId";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTouchId();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_getX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:getX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getX();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_getY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:getY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getY();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_isAltDown(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:isAltDown";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isAltDown();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_isCtrlDown(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:isCtrlDown";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isCtrlDown();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_isDoubleClick(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:isDoubleClick";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isDoubleClick();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_isShiftDown(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent:isShiftDown";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputEvent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isShiftDown();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputEvent_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputEvent";
	constexpr auto LUA_FNAME = "fgui.InputEvent constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::InputEvent();
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_InputEvent_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_InputEvent(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.InputEvent");
	tolua_cclass(tolua_S, "InputEvent", "fgui.InputEvent", "", nullptr);

	tolua_beginmodule(tolua_S, "InputEvent");
		tolua_function(tolua_S, "new", lua_cc_fairygui_InputEvent_constructor);
		tolua_function(tolua_S, "getButton", lua_cc_fairygui_InputEvent_getButton);
		tolua_function(tolua_S, "getKeyCode", lua_cc_fairygui_InputEvent_getKeyCode);
		tolua_function(tolua_S, "getMouseWheelDelta", lua_cc_fairygui_InputEvent_getMouseWheelDelta);
		tolua_function(tolua_S, "getPosition", lua_cc_fairygui_InputEvent_getPosition);
		tolua_function(tolua_S, "getProcessor", lua_cc_fairygui_InputEvent_getProcessor);
		tolua_function(tolua_S, "getTarget", lua_cc_fairygui_InputEvent_getTarget);
		tolua_function(tolua_S, "getTouch", lua_cc_fairygui_InputEvent_getTouch);
		tolua_function(tolua_S, "getTouchId", lua_cc_fairygui_InputEvent_getTouchId);
		tolua_function(tolua_S, "getX", lua_cc_fairygui_InputEvent_getX);
		tolua_function(tolua_S, "getY", lua_cc_fairygui_InputEvent_getY);
		tolua_function(tolua_S, "isAltDown", lua_cc_fairygui_InputEvent_isAltDown);
		tolua_function(tolua_S, "isCtrlDown", lua_cc_fairygui_InputEvent_isCtrlDown);
		tolua_function(tolua_S, "isDoubleClick", lua_cc_fairygui_InputEvent_isDoubleClick);
		tolua_function(tolua_S, "isShiftDown", lua_cc_fairygui_InputEvent_isShiftDown);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::InputEvent).name();
	g_luaType[typeName] = "fgui.InputEvent";
	g_typeCast["InputEvent"] = "fgui.InputEvent";
	return 1;
}

int lua_cc_fairygui_EventContext_captureTouch(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.EventContext";
	constexpr auto LUA_FNAME = "fgui.EventContext:captureTouch";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::EventContext*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->captureTouch();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_EventContext_getData(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.EventContext";
	constexpr auto LUA_FNAME = "fgui.EventContext:getData";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::EventContext*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getData();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_EventContext_getDataValue(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.EventContext";
	constexpr auto LUA_FNAME = "fgui.EventContext:getDataValue";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::EventContext*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getDataValue();
		ccvalue_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_EventContext_getInput(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.EventContext";
	constexpr auto LUA_FNAME = "fgui.EventContext:getInput";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::EventContext*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getInput();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_EventContext_getSender(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.EventContext";
	constexpr auto LUA_FNAME = "fgui.EventContext:getSender";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::EventContext*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSender();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_EventContext_getType(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.EventContext";
	constexpr auto LUA_FNAME = "fgui.EventContext:getType";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::EventContext*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getType();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_EventContext_isDefaultPrevented(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.EventContext";
	constexpr auto LUA_FNAME = "fgui.EventContext:isDefaultPrevented";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::EventContext*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isDefaultPrevented();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_EventContext_preventDefault(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.EventContext";
	constexpr auto LUA_FNAME = "fgui.EventContext:preventDefault";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::EventContext*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->preventDefault();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_EventContext_stopPropagation(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.EventContext";
	constexpr auto LUA_FNAME = "fgui.EventContext:stopPropagation";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::EventContext*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->stopPropagation();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_EventContext_uncaptureTouch(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.EventContext";
	constexpr auto LUA_FNAME = "fgui.EventContext:uncaptureTouch";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::EventContext*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->uncaptureTouch();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_EventContext_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.EventContext";
	constexpr auto LUA_FNAME = "fgui.EventContext constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::EventContext();
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_EventContext_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_EventContext(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.EventContext");
	tolua_cclass(tolua_S, "EventContext", "fgui.EventContext", "", nullptr);

	tolua_beginmodule(tolua_S, "EventContext");
		tolua_function(tolua_S, "new", lua_cc_fairygui_EventContext_constructor);
		tolua_function(tolua_S, "captureTouch", lua_cc_fairygui_EventContext_captureTouch);
		tolua_function(tolua_S, "getData", lua_cc_fairygui_EventContext_getData);
		tolua_function(tolua_S, "getDataValue", lua_cc_fairygui_EventContext_getDataValue);
		tolua_function(tolua_S, "getInput", lua_cc_fairygui_EventContext_getInput);
		tolua_function(tolua_S, "getSender", lua_cc_fairygui_EventContext_getSender);
		tolua_function(tolua_S, "getType", lua_cc_fairygui_EventContext_getType);
		tolua_function(tolua_S, "isDefaultPrevented", lua_cc_fairygui_EventContext_isDefaultPrevented);
		tolua_function(tolua_S, "preventDefault", lua_cc_fairygui_EventContext_preventDefault);
		tolua_function(tolua_S, "stopPropagation", lua_cc_fairygui_EventContext_stopPropagation);
		tolua_function(tolua_S, "uncaptureTouch", lua_cc_fairygui_EventContext_uncaptureTouch);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::EventContext).name();
	g_luaType[typeName] = "fgui.EventContext";
	g_typeCast["EventContext"] = "fgui.EventContext";
	return 1;
}

static int lua_cc_fairygui_UIEventType_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_UIEventType(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.UIEventType");
	tolua_cclass(tolua_S, "UIEventType", "fgui.UIEventType", "", nullptr);

	tolua_beginmodule(tolua_S, "UIEventType");
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::UIEventType).name();
	g_luaType[typeName] = "fgui.UIEventType";
	g_typeCast["UIEventType"] = "fgui.UIEventType";
	return 1;
}

int lua_cc_fairygui_EventTag_isNone(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.EventTag";
	constexpr auto LUA_FNAME = "fgui.EventTag:isNone";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::EventTag*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isNone();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
static int lua_cc_fairygui_EventTag_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_EventTag(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.EventTag");
	tolua_cclass(tolua_S, "EventTag", "fgui.EventTag", "", nullptr);

	tolua_beginmodule(tolua_S, "EventTag");
		tolua_function(tolua_S, "isNone", lua_cc_fairygui_EventTag_isNone);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::EventTag).name();
	g_luaType[typeName] = "fgui.EventTag";
	g_typeCast["EventTag"] = "fgui.EventTag";
	return 1;
}

int lua_cc_fairygui_UIEventDispatcher_addEventListener(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIEventDispatcher";
	constexpr auto LUA_FNAME = "fgui.UIEventDispatcher:addEventListener";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::UIEventDispatcher*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 3) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			std::function<void (fairygui::EventContext *)> arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			int handler3 = query_luafunction_handler(tolua_S, 3, LUA_FNAME);
			ok &= handler3 != 0;
			if (!ok) { break; }
			fairygui::EventTag arg2;
			ok &= luaval_to_native(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			cobj->addEventListener(arg0, arg1, arg2);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 2) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			std::function<void (fairygui::EventContext *)> arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			int handler3 = query_luafunction_handler(tolua_S, 3, LUA_FNAME);
			ok &= handler3 != 0;
			if (!ok) { break; }
			cobj->addEventListener(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_UIEventDispatcher_hasEventListener(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIEventDispatcher";
	constexpr auto LUA_FNAME = "fgui.UIEventDispatcher:hasEventListener";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::UIEventDispatcher*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			fairygui::EventTag arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->hasEventListener(arg0, arg1);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->hasEventListener(arg0);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIEventDispatcher_isDispatchingEvent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIEventDispatcher";
	constexpr auto LUA_FNAME = "fgui.UIEventDispatcher:isDispatchingEvent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::UIEventDispatcher*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isDispatchingEvent(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIEventDispatcher_removeEventListener(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIEventDispatcher";
	constexpr auto LUA_FNAME = "fgui.UIEventDispatcher:removeEventListener";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::UIEventDispatcher*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			fairygui::EventTag arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->removeEventListener(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cobj->removeEventListener(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIEventDispatcher_removeEventListeners(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIEventDispatcher";
	constexpr auto LUA_FNAME = "fgui.UIEventDispatcher:removeEventListeners";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::UIEventDispatcher*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->removeEventListeners();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_UIEventDispatcher_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIEventDispatcher";
	constexpr auto LUA_FNAME = "fgui.UIEventDispatcher constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::UIEventDispatcher();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_UIEventDispatcher_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_UIEventDispatcher(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.UIEventDispatcher");
	tolua_cclass(tolua_S, "UIEventDispatcher", "fgui.UIEventDispatcher", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "UIEventDispatcher");
		tolua_function(tolua_S, "new", lua_cc_fairygui_UIEventDispatcher_constructor);
		tolua_function(tolua_S, "addEventListener", lua_cc_fairygui_UIEventDispatcher_addEventListener);
		tolua_function(tolua_S, "hasEventListener", lua_cc_fairygui_UIEventDispatcher_hasEventListener);
		tolua_function(tolua_S, "isDispatchingEvent", lua_cc_fairygui_UIEventDispatcher_isDispatchingEvent);
		tolua_function(tolua_S, "removeEventListener", lua_cc_fairygui_UIEventDispatcher_removeEventListener);
		tolua_function(tolua_S, "removeEventListeners", lua_cc_fairygui_UIEventDispatcher_removeEventListeners);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::UIEventDispatcher).name();
	g_luaType[typeName] = "fgui.UIEventDispatcher";
	g_typeCast["UIEventDispatcher"] = "fgui.UIEventDispatcher";
	return 1;
}

int lua_cc_fairygui_GController_getPageCount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:getPageCount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPageCount();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GController_getPageId(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:getPageId";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPageId(arg0);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GController_getPageIndexById(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:getPageIndexById";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPageIndexById(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GController_getPageNameById(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:getPageNameById";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPageNameById(arg0);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GController_getParent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:getParent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getParent();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GController_getPreviousPage(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:getPreviousPage";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPreviousPage();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GController_getPreviousPageId(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:getPreviousPageId";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPreviousPageId();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GController_getPrevisousIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:getPrevisousIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPrevisousIndex();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GController_getSelectedIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:getSelectedIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSelectedIndex();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GController_getSelectedPage(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:getSelectedPage";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSelectedPage();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GController_getSelectedPageId(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:getSelectedPageId";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSelectedPageId();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GController_hasPage(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:hasPage";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->hasPage(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GController_runActions(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:runActions";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->runActions();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GController_setOppositePageId(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:setOppositePageId";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setOppositePageId(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GController_setParent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:setParent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GComponent* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setParent(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GController_setSelectedIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:setSelectedIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelectedIndex(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		int arg0;
		bool arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelectedIndex(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_GController_setSelectedPage(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:setSelectedPage";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelectedPage(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		std::string arg0;
		bool arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelectedPage(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_GController_setSelectedPageId(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:setSelectedPageId";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelectedPageId(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		std::string arg0;
		bool arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelectedPageId(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_GController_setup(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController:setup";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::ByteBuffer* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setup(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GController_getname(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController.name getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->name);
	return 1;
}
int lua_cc_fairygui_GController_setname(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController.name setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->name, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GController_getchanging(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController.changing getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->changing);
	return 1;
}
int lua_cc_fairygui_GController_setchanging(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController.changing setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->changing, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GController_getautoRadioGroupDepth(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController.autoRadioGroupDepth getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->autoRadioGroupDepth);
	return 1;
}
int lua_cc_fairygui_GController_setautoRadioGroupDepth(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController.autoRadioGroupDepth setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GController*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->autoRadioGroupDepth, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GController_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GController";
	constexpr auto LUA_FNAME = "fgui.GController constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GController();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GController_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GController(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GController");
	tolua_cclass(tolua_S, "GController", "fgui.GController", "fgui.UIEventDispatcher", nullptr);

	tolua_beginmodule(tolua_S, "GController");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GController_constructor);
		tolua_function(tolua_S, "getPageCount", lua_cc_fairygui_GController_getPageCount);
		tolua_function(tolua_S, "getPageId", lua_cc_fairygui_GController_getPageId);
		tolua_function(tolua_S, "getPageIndexById", lua_cc_fairygui_GController_getPageIndexById);
		tolua_function(tolua_S, "getPageNameById", lua_cc_fairygui_GController_getPageNameById);
		tolua_function(tolua_S, "getParent", lua_cc_fairygui_GController_getParent);
		tolua_function(tolua_S, "getPreviousPage", lua_cc_fairygui_GController_getPreviousPage);
		tolua_function(tolua_S, "getPreviousPageId", lua_cc_fairygui_GController_getPreviousPageId);
		tolua_function(tolua_S, "getPrevisousIndex", lua_cc_fairygui_GController_getPrevisousIndex);
		tolua_function(tolua_S, "getSelectedIndex", lua_cc_fairygui_GController_getSelectedIndex);
		tolua_function(tolua_S, "getSelectedPage", lua_cc_fairygui_GController_getSelectedPage);
		tolua_function(tolua_S, "getSelectedPageId", lua_cc_fairygui_GController_getSelectedPageId);
		tolua_function(tolua_S, "hasPage", lua_cc_fairygui_GController_hasPage);
		tolua_function(tolua_S, "runActions", lua_cc_fairygui_GController_runActions);
		tolua_function(tolua_S, "setOppositePageId", lua_cc_fairygui_GController_setOppositePageId);
		tolua_function(tolua_S, "setParent", lua_cc_fairygui_GController_setParent);
		tolua_function(tolua_S, "setSelectedIndex", lua_cc_fairygui_GController_setSelectedIndex);
		tolua_function(tolua_S, "setSelectedPage", lua_cc_fairygui_GController_setSelectedPage);
		tolua_function(tolua_S, "setSelectedPageId", lua_cc_fairygui_GController_setSelectedPageId);
		tolua_function(tolua_S, "setup", lua_cc_fairygui_GController_setup);
		tolua_variable(tolua_S, "name", lua_cc_fairygui_GController_getname, lua_cc_fairygui_GController_setname);
		tolua_variable(tolua_S, "changing", lua_cc_fairygui_GController_getchanging, lua_cc_fairygui_GController_setchanging);
		tolua_variable(tolua_S, "autoRadioGroupDepth", lua_cc_fairygui_GController_getautoRadioGroupDepth, lua_cc_fairygui_GController_setautoRadioGroupDepth);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GController).name();
	g_luaType[typeName] = "fgui.GController";
	g_typeCast["GController"] = "fgui.GController";
	return 1;
}

int lua_register_cc_fairygui_RelationType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "RelationType", 0);
	tolua_beginmodule(tolua_S,"RelationType");
		tolua_constant(tolua_S, "Left_Left", (lua_Number)fairygui::RelationType::Left_Left);
		tolua_constant(tolua_S, "Left_Center", (lua_Number)fairygui::RelationType::Left_Center);
		tolua_constant(tolua_S, "Left_Right", (lua_Number)fairygui::RelationType::Left_Right);
		tolua_constant(tolua_S, "Center_Center", (lua_Number)fairygui::RelationType::Center_Center);
		tolua_constant(tolua_S, "Right_Left", (lua_Number)fairygui::RelationType::Right_Left);
		tolua_constant(tolua_S, "Right_Center", (lua_Number)fairygui::RelationType::Right_Center);
		tolua_constant(tolua_S, "Right_Right", (lua_Number)fairygui::RelationType::Right_Right);
		tolua_constant(tolua_S, "Top_Top", (lua_Number)fairygui::RelationType::Top_Top);
		tolua_constant(tolua_S, "Top_Middle", (lua_Number)fairygui::RelationType::Top_Middle);
		tolua_constant(tolua_S, "Top_Bottom", (lua_Number)fairygui::RelationType::Top_Bottom);
		tolua_constant(tolua_S, "Middle_Middle", (lua_Number)fairygui::RelationType::Middle_Middle);
		tolua_constant(tolua_S, "Bottom_Top", (lua_Number)fairygui::RelationType::Bottom_Top);
		tolua_constant(tolua_S, "Bottom_Middle", (lua_Number)fairygui::RelationType::Bottom_Middle);
		tolua_constant(tolua_S, "Bottom_Bottom", (lua_Number)fairygui::RelationType::Bottom_Bottom);
		tolua_constant(tolua_S, "Width", (lua_Number)fairygui::RelationType::Width);
		tolua_constant(tolua_S, "Height", (lua_Number)fairygui::RelationType::Height);
		tolua_constant(tolua_S, "LeftExt_Left", (lua_Number)fairygui::RelationType::LeftExt_Left);
		tolua_constant(tolua_S, "LeftExt_Right", (lua_Number)fairygui::RelationType::LeftExt_Right);
		tolua_constant(tolua_S, "RightExt_Left", (lua_Number)fairygui::RelationType::RightExt_Left);
		tolua_constant(tolua_S, "RightExt_Right", (lua_Number)fairygui::RelationType::RightExt_Right);
		tolua_constant(tolua_S, "TopExt_Top", (lua_Number)fairygui::RelationType::TopExt_Top);
		tolua_constant(tolua_S, "TopExt_Bottom", (lua_Number)fairygui::RelationType::TopExt_Bottom);
		tolua_constant(tolua_S, "BottomExt_Top", (lua_Number)fairygui::RelationType::BottomExt_Top);
		tolua_constant(tolua_S, "BottomExt_Bottom", (lua_Number)fairygui::RelationType::BottomExt_Bottom);
		tolua_constant(tolua_S, "Size", (lua_Number)fairygui::RelationType::Size);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_cc_fairygui_RelationItem_add(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.RelationItem";
	constexpr auto LUA_FNAME = "fgui.RelationItem:add";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::RelationItem*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::RelationType arg0;
		bool arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->add(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_RelationItem_applyOnSelfSizeChanged(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.RelationItem";
	constexpr auto LUA_FNAME = "fgui.RelationItem:applyOnSelfSizeChanged";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::RelationItem*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		double arg0;
		double arg1;
		bool arg2;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->applyOnSelfSizeChanged(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_cc_fairygui_RelationItem_copyFrom(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.RelationItem";
	constexpr auto LUA_FNAME = "fgui.RelationItem:copyFrom";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::RelationItem*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::RelationItem* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->copyFrom(*arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_RelationItem_getTarget(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.RelationItem";
	constexpr auto LUA_FNAME = "fgui.RelationItem:getTarget";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::RelationItem*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTarget();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_RelationItem_internalAdd(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.RelationItem";
	constexpr auto LUA_FNAME = "fgui.RelationItem:internalAdd";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::RelationItem*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::RelationType arg0;
		bool arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->internalAdd(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_RelationItem_isEmpty(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.RelationItem";
	constexpr auto LUA_FNAME = "fgui.RelationItem:isEmpty";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::RelationItem*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isEmpty();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_RelationItem_remove(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.RelationItem";
	constexpr auto LUA_FNAME = "fgui.RelationItem:remove";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::RelationItem*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::RelationType arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->remove(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_RelationItem_setTarget(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.RelationItem";
	constexpr auto LUA_FNAME = "fgui.RelationItem:setTarget";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::RelationItem*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTarget(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_RelationItem_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.RelationItem";
	constexpr auto LUA_FNAME = "fgui.RelationItem constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::RelationItem(arg0);
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}

static int lua_cc_fairygui_RelationItem_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_RelationItem(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.RelationItem");
	tolua_cclass(tolua_S, "RelationItem", "fgui.RelationItem", "", nullptr);

	tolua_beginmodule(tolua_S, "RelationItem");
		tolua_function(tolua_S, "new", lua_cc_fairygui_RelationItem_constructor);
		tolua_function(tolua_S, "add", lua_cc_fairygui_RelationItem_add);
		tolua_function(tolua_S, "applyOnSelfSizeChanged", lua_cc_fairygui_RelationItem_applyOnSelfSizeChanged);
		tolua_function(tolua_S, "copyFrom", lua_cc_fairygui_RelationItem_copyFrom);
		tolua_function(tolua_S, "getTarget", lua_cc_fairygui_RelationItem_getTarget);
		tolua_function(tolua_S, "internalAdd", lua_cc_fairygui_RelationItem_internalAdd);
		tolua_function(tolua_S, "isEmpty", lua_cc_fairygui_RelationItem_isEmpty);
		tolua_function(tolua_S, "remove", lua_cc_fairygui_RelationItem_remove);
		tolua_function(tolua_S, "setTarget", lua_cc_fairygui_RelationItem_setTarget);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::RelationItem).name();
	g_luaType[typeName] = "fgui.RelationItem";
	g_typeCast["RelationItem"] = "fgui.RelationItem";
	return 1;
}

int lua_cc_fairygui_Relations_add(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Relations";
	constexpr auto LUA_FNAME = "fgui.Relations:add";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Relations*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 3) {
			fairygui::GObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			fairygui::RelationType arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			bool arg2;
			ok &= luaval_to_boolean(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			cobj->add(arg0, arg1, arg2);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 2) {
			fairygui::GObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			fairygui::RelationType arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->add(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_Relations_clearAll(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Relations";
	constexpr auto LUA_FNAME = "fgui.Relations:clearAll";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Relations*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->clearAll();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Relations_clearFor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Relations";
	constexpr auto LUA_FNAME = "fgui.Relations:clearFor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Relations*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->clearFor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Relations_contains(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Relations";
	constexpr auto LUA_FNAME = "fgui.Relations:contains";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Relations*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->contains(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Relations_copyFrom(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Relations";
	constexpr auto LUA_FNAME = "fgui.Relations:copyFrom";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Relations*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::Relations* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->copyFrom(*arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Relations_isEmpty(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Relations";
	constexpr auto LUA_FNAME = "fgui.Relations:isEmpty";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Relations*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isEmpty();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Relations_onOwnerSizeChanged(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Relations";
	constexpr auto LUA_FNAME = "fgui.Relations:onOwnerSizeChanged";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Relations*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		double arg0;
		double arg1;
		bool arg2;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->onOwnerSizeChanged(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_cc_fairygui_Relations_remove(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Relations";
	constexpr auto LUA_FNAME = "fgui.Relations:remove";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Relations*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GObject* arg0;
		fairygui::RelationType arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->remove(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_Relations_setup(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Relations";
	constexpr auto LUA_FNAME = "fgui.Relations:setup";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Relations*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::ByteBuffer* arg0;
		bool arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setup(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_Relations_gethandling(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.Relations";
	constexpr auto LUA_FNAME = "fgui.Relations.handling getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Relations*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->handling);
	return 1;
}
int lua_cc_fairygui_Relations_sethandling(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.Relations";
	constexpr auto LUA_FNAME = "fgui.Relations.handling setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Relations*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->handling, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Relations_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Relations";
	constexpr auto LUA_FNAME = "fgui.Relations constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::Relations(arg0);
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}

static int lua_cc_fairygui_Relations_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_Relations(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.Relations");
	tolua_cclass(tolua_S, "Relations", "fgui.Relations", "", nullptr);

	tolua_beginmodule(tolua_S, "Relations");
		tolua_function(tolua_S, "new", lua_cc_fairygui_Relations_constructor);
		tolua_function(tolua_S, "add", lua_cc_fairygui_Relations_add);
		tolua_function(tolua_S, "clearAll", lua_cc_fairygui_Relations_clearAll);
		tolua_function(tolua_S, "clearFor", lua_cc_fairygui_Relations_clearFor);
		tolua_function(tolua_S, "contains", lua_cc_fairygui_Relations_contains);
		tolua_function(tolua_S, "copyFrom", lua_cc_fairygui_Relations_copyFrom);
		tolua_function(tolua_S, "isEmpty", lua_cc_fairygui_Relations_isEmpty);
		tolua_function(tolua_S, "onOwnerSizeChanged", lua_cc_fairygui_Relations_onOwnerSizeChanged);
		tolua_function(tolua_S, "remove", lua_cc_fairygui_Relations_remove);
		tolua_function(tolua_S, "setup", lua_cc_fairygui_Relations_setup);
		tolua_variable(tolua_S, "handling", lua_cc_fairygui_Relations_gethandling, lua_cc_fairygui_Relations_sethandling);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::Relations).name();
	g_luaType[typeName] = "fgui.Relations";
	g_typeCast["Relations"] = "fgui.Relations";
	return 1;
}

int lua_register_cc_fairygui_EaseType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "EaseType", 0);
	tolua_beginmodule(tolua_S,"EaseType");
		tolua_constant(tolua_S, "Linear", (lua_Number)fairygui::EaseType::Linear);
		tolua_constant(tolua_S, "SineIn", (lua_Number)fairygui::EaseType::SineIn);
		tolua_constant(tolua_S, "SineOut", (lua_Number)fairygui::EaseType::SineOut);
		tolua_constant(tolua_S, "SineInOut", (lua_Number)fairygui::EaseType::SineInOut);
		tolua_constant(tolua_S, "QuadIn", (lua_Number)fairygui::EaseType::QuadIn);
		tolua_constant(tolua_S, "QuadOut", (lua_Number)fairygui::EaseType::QuadOut);
		tolua_constant(tolua_S, "QuadInOut", (lua_Number)fairygui::EaseType::QuadInOut);
		tolua_constant(tolua_S, "CubicIn", (lua_Number)fairygui::EaseType::CubicIn);
		tolua_constant(tolua_S, "CubicOut", (lua_Number)fairygui::EaseType::CubicOut);
		tolua_constant(tolua_S, "CubicInOut", (lua_Number)fairygui::EaseType::CubicInOut);
		tolua_constant(tolua_S, "QuartIn", (lua_Number)fairygui::EaseType::QuartIn);
		tolua_constant(tolua_S, "QuartOut", (lua_Number)fairygui::EaseType::QuartOut);
		tolua_constant(tolua_S, "QuartInOut", (lua_Number)fairygui::EaseType::QuartInOut);
		tolua_constant(tolua_S, "QuintIn", (lua_Number)fairygui::EaseType::QuintIn);
		tolua_constant(tolua_S, "QuintOut", (lua_Number)fairygui::EaseType::QuintOut);
		tolua_constant(tolua_S, "QuintInOut", (lua_Number)fairygui::EaseType::QuintInOut);
		tolua_constant(tolua_S, "ExpoIn", (lua_Number)fairygui::EaseType::ExpoIn);
		tolua_constant(tolua_S, "ExpoOut", (lua_Number)fairygui::EaseType::ExpoOut);
		tolua_constant(tolua_S, "ExpoInOut", (lua_Number)fairygui::EaseType::ExpoInOut);
		tolua_constant(tolua_S, "CircIn", (lua_Number)fairygui::EaseType::CircIn);
		tolua_constant(tolua_S, "CircOut", (lua_Number)fairygui::EaseType::CircOut);
		tolua_constant(tolua_S, "CircInOut", (lua_Number)fairygui::EaseType::CircInOut);
		tolua_constant(tolua_S, "ElasticIn", (lua_Number)fairygui::EaseType::ElasticIn);
		tolua_constant(tolua_S, "ElasticOut", (lua_Number)fairygui::EaseType::ElasticOut);
		tolua_constant(tolua_S, "ElasticInOut", (lua_Number)fairygui::EaseType::ElasticInOut);
		tolua_constant(tolua_S, "BackIn", (lua_Number)fairygui::EaseType::BackIn);
		tolua_constant(tolua_S, "BackOut", (lua_Number)fairygui::EaseType::BackOut);
		tolua_constant(tolua_S, "BackInOut", (lua_Number)fairygui::EaseType::BackInOut);
		tolua_constant(tolua_S, "BounceIn", (lua_Number)fairygui::EaseType::BounceIn);
		tolua_constant(tolua_S, "BounceOut", (lua_Number)fairygui::EaseType::BounceOut);
		tolua_constant(tolua_S, "BounceInOut", (lua_Number)fairygui::EaseType::BounceInOut);
		tolua_constant(tolua_S, "Custom", (lua_Number)fairygui::EaseType::Custom);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_cc_fairygui_GearBase_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GearBase";
	constexpr auto LUA_FNAME = "fgui.GearBase:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GObject* arg0;
		int arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GearBase::create(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GearBase_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GearBase";
	constexpr auto LUA_FNAME = "fgui.GearBase constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GearBase(arg0);
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}

static int lua_cc_fairygui_GearBase_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GearBase(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GearBase");
	tolua_cclass(tolua_S, "GearBase", "fgui.GearBase", "", nullptr);

	tolua_beginmodule(tolua_S, "GearBase");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GearBase_constructor);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GearBase_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GearBase).name();
	g_luaType[typeName] = "fgui.GearBase";
	g_typeCast["GearBase"] = "fgui.GearBase";
	return 1;
}

int lua_cc_fairygui_GObject_addClickListener(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:addClickListener";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			std::function<void (fairygui::EventContext *)> arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			int handler2 = query_luafunction_handler(tolua_S, 2, LUA_FNAME);
			ok &= handler2 != 0;
			if (!ok) { break; }
			fairygui::EventTag arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->addClickListener(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			std::function<void (fairygui::EventContext *)> arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			int handler2 = query_luafunction_handler(tolua_S, 2, LUA_FNAME);
			ok &= handler2 != 0;
			if (!ok) { break; }
			cobj->addClickListener(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_addDisplayLock(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:addDisplayLock";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->addDisplayLock();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_addRelation(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:addRelation";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GObject* arg0;
		fairygui::RelationType arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->addRelation(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) {
		fairygui::GObject* arg0;
		fairygui::RelationType arg1;
		bool arg2;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->addRelation(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2 to 3");
}
int lua_cc_fairygui_GObject_center(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:center";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->center();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->center(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 1");
}
int lua_cc_fairygui_GObject_checkGearController(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:checkGearController";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		int arg0;
		fairygui::GController* arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->checkGearController(arg0, arg1);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GObject_constructFromResource(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:constructFromResource";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->constructFromResource();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GObject::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_displayObject(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:displayObject";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->displayObject();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_findParent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:findParent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->findParent();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getAlpha(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getAlpha";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getAlpha();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getCustomData(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getCustomData";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getCustomData();
		ccvalue_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getDraggingObject(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getDraggingObject";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GObject::getDraggingObject();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getGear(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getGear";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getGear(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_getGroup(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getGroup";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getGroup();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getHeight(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getHeight";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getHeight();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getIcon(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getIcon";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getIcon();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getPackageItem(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getPackageItem";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPackageItem();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getParent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getParent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getParent();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getPivot(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getPivot";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPivot();
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getPosition(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getPosition";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPosition();
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getProp(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getProp";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::ObjectPropID arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getProp(arg0);
		ccvalue_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_getResourceURL(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getResourceURL";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getResourceURL();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getRoot(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getRoot";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getRoot();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getRotation(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getRotation";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getRotation();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getScale(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getScale";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getScale();
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getScaleX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getScaleX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getScaleX();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getScaleY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getScaleY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getScaleY();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getSkewX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getSkewX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSkewX();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getSkewY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getSkewY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSkewY();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getSortingOrder(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getSortingOrder";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSortingOrder();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getText(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getText";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getText();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getTooltips(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getTooltips";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTooltips();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getWidth(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getWidth";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getWidth();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getX();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getXMin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getXMin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getXMin();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getY();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getYMin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:getYMin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getYMin();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_globalToLocal(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:globalToLocal";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 1) {
			cocos2d::Rect arg0;
			ok &= luaval_to_rect(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->globalToLocal(arg0);
			rect_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			cocos2d::Vec2 arg0;
			ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->globalToLocal(arg0);
			vec2_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_hitTest(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:hitTest";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		cocos2d::Vec2 arg0;
		const cocos2d::Camera* arg1;
		ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->hitTest(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GObject_isDraggable(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:isDraggable";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isDraggable();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_isGrayed(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:isGrayed";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isGrayed();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_isPivotAsAnchor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:isPivotAsAnchor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isPivotAsAnchor();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_isPixelSnapping(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:isPixelSnapping";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isPixelSnapping();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_isTouchable(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:isTouchable";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isTouchable();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_isVisible(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:isVisible";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isVisible();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_localToGlobal(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:localToGlobal";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 1) {
			cocos2d::Rect arg0;
			ok &= luaval_to_rect(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->localToGlobal(arg0);
			rect_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			cocos2d::Vec2 arg0;
			ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->localToGlobal(arg0);
			vec2_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_makeFullScreen(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:makeFullScreen";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->makeFullScreen();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_onStage(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:onStage";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->onStage();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_relations(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:relations";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->relations();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_releaseDisplayLock(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:releaseDisplayLock";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		unsigned int arg0;
		ok &= luaval_to_uint32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->releaseDisplayLock(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_removeClickListener(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:removeClickListener";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::EventTag arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->removeClickListener(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_removeFromParent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:removeFromParent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->removeFromParent();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_removeRelation(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:removeRelation";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GObject* arg0;
		fairygui::RelationType arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->removeRelation(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GObject_setAlpha(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setAlpha";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAlpha(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setCustomData(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setCustomData";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Value arg0;
		ok &= luaval_to_ccvalue(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setCustomData(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setDragBounds(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setDragBounds";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= luaval_to_rect(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setDragBounds(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setDraggable(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setDraggable";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setDraggable(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setGrayed(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setGrayed";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setGrayed(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setGroup(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setGroup";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GGroup* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setGroup(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setHeight(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setHeight";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setHeight(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setIcon(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setIcon";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setIcon(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setPivot(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setPivot";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPivot(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) {
		double arg0;
		double arg1;
		bool arg2;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPivot(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2 to 3");
}
int lua_cc_fairygui_GObject_setPixelSnapping(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setPixelSnapping";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPixelSnapping(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setPosition(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setPosition";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPosition(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GObject_setProp(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setProp";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::ObjectPropID arg0;
		cocos2d::Value arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_ccvalue(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setProp(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GObject_setRotation(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setRotation";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setRotation(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setScale(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setScale";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setScale(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GObject_setScaleX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setScaleX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setScaleX(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setScaleY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setScaleY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setScaleY(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSize(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) {
		double arg0;
		double arg1;
		bool arg2;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSize(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2 to 3");
}
int lua_cc_fairygui_GObject_setSkewX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setSkewX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSkewX(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setSkewY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setSkewY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSkewY(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setSortingOrder(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setSortingOrder";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSortingOrder(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setText(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setText";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setText(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setTooltips(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setTooltips";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTooltips(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setTouchable(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setTouchable";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTouchable(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setVisible(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setVisible";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVisible(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setWidth(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setWidth";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setWidth(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setX(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setXMin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setXMin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setXMin(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setY(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_setYMin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:setYMin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setYMin(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_startDrag(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:startDrag";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->startDrag();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->startDrag(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 1");
}
int lua_cc_fairygui_GObject_stopDrag(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:stopDrag";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->stopDrag();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_transformRect(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:transformRect";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		cocos2d::Rect arg0;
		fairygui::GObject* arg1;
		ok &= luaval_to_rect(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->transformRect(arg0, arg1);
		rect_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GObject_treeNode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject:treeNode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->treeNode();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GObject_getid(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject.id getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->id);
	return 1;
}
int lua_cc_fairygui_GObject_setid(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject.id setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->id, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_getname(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject.name getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->name);
	return 1;
}
int lua_cc_fairygui_GObject_setname(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject.name setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->name, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_getsourceSize(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject.sourceSize getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->sourceSize);
	return 1;
}
int lua_cc_fairygui_GObject_setsourceSize(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject.sourceSize setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->sourceSize, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_getinitSize(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject.initSize getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->initSize);
	return 1;
}
int lua_cc_fairygui_GObject_setinitSize(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject.initSize setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->initSize, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_getminSize(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject.minSize getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->minSize);
	return 1;
}
int lua_cc_fairygui_GObject_setminSize(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject.minSize setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->minSize, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_getmaxSize(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject.maxSize getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->maxSize);
	return 1;
}
int lua_cc_fairygui_GObject_setmaxSize(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject.maxSize setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->maxSize, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_get_underConstruct(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject._underConstruct getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->_underConstruct);
	return 1;
}
int lua_cc_fairygui_GObject_set_underConstruct(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject._underConstruct setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->_underConstruct, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_get_gearLocked(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject._gearLocked getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->_gearLocked);
	return 1;
}
int lua_cc_fairygui_GObject_set_gearLocked(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject._gearLocked setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->_gearLocked, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_get_alignToBL(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject._alignToBL getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->_alignToBL);
	return 1;
}
int lua_cc_fairygui_GObject_set_alignToBL(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject._alignToBL setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GObject*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->_alignToBL, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GObject_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GObject";
	constexpr auto LUA_FNAME = "fgui.GObject constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GObject();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GObject_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GObject(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GObject");
	tolua_cclass(tolua_S, "GObject", "fgui.GObject", "fgui.UIEventDispatcher", nullptr);

	tolua_beginmodule(tolua_S, "GObject");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GObject_constructor);
		tolua_function(tolua_S, "addClickListener", lua_cc_fairygui_GObject_addClickListener);
		tolua_function(tolua_S, "addDisplayLock", lua_cc_fairygui_GObject_addDisplayLock);
		tolua_function(tolua_S, "addRelation", lua_cc_fairygui_GObject_addRelation);
		tolua_function(tolua_S, "center", lua_cc_fairygui_GObject_center);
		tolua_function(tolua_S, "checkGearController", lua_cc_fairygui_GObject_checkGearController);
		tolua_function(tolua_S, "constructFromResource", lua_cc_fairygui_GObject_constructFromResource);
		tolua_function(tolua_S, "displayObject", lua_cc_fairygui_GObject_displayObject);
		tolua_function(tolua_S, "findParent", lua_cc_fairygui_GObject_findParent);
		tolua_function(tolua_S, "getAlpha", lua_cc_fairygui_GObject_getAlpha);
		tolua_function(tolua_S, "getCustomData", lua_cc_fairygui_GObject_getCustomData);
		tolua_function(tolua_S, "getGear", lua_cc_fairygui_GObject_getGear);
		tolua_function(tolua_S, "getGroup", lua_cc_fairygui_GObject_getGroup);
		tolua_function(tolua_S, "getHeight", lua_cc_fairygui_GObject_getHeight);
		tolua_function(tolua_S, "getIcon", lua_cc_fairygui_GObject_getIcon);
		tolua_function(tolua_S, "getPackageItem", lua_cc_fairygui_GObject_getPackageItem);
		tolua_function(tolua_S, "getParent", lua_cc_fairygui_GObject_getParent);
		tolua_function(tolua_S, "getPivot", lua_cc_fairygui_GObject_getPivot);
		tolua_function(tolua_S, "getPosition", lua_cc_fairygui_GObject_getPosition);
		tolua_function(tolua_S, "getProp", lua_cc_fairygui_GObject_getProp);
		tolua_function(tolua_S, "getResourceURL", lua_cc_fairygui_GObject_getResourceURL);
		tolua_function(tolua_S, "getRoot", lua_cc_fairygui_GObject_getRoot);
		tolua_function(tolua_S, "getRotation", lua_cc_fairygui_GObject_getRotation);
		tolua_function(tolua_S, "getScale", lua_cc_fairygui_GObject_getScale);
		tolua_function(tolua_S, "getScaleX", lua_cc_fairygui_GObject_getScaleX);
		tolua_function(tolua_S, "getScaleY", lua_cc_fairygui_GObject_getScaleY);
		tolua_function(tolua_S, "getSize", lua_cc_fairygui_GObject_getSize);
		tolua_function(tolua_S, "getSkewX", lua_cc_fairygui_GObject_getSkewX);
		tolua_function(tolua_S, "getSkewY", lua_cc_fairygui_GObject_getSkewY);
		tolua_function(tolua_S, "getSortingOrder", lua_cc_fairygui_GObject_getSortingOrder);
		tolua_function(tolua_S, "getText", lua_cc_fairygui_GObject_getText);
		tolua_function(tolua_S, "getTooltips", lua_cc_fairygui_GObject_getTooltips);
		tolua_function(tolua_S, "getWidth", lua_cc_fairygui_GObject_getWidth);
		tolua_function(tolua_S, "getX", lua_cc_fairygui_GObject_getX);
		tolua_function(tolua_S, "getXMin", lua_cc_fairygui_GObject_getXMin);
		tolua_function(tolua_S, "getY", lua_cc_fairygui_GObject_getY);
		tolua_function(tolua_S, "getYMin", lua_cc_fairygui_GObject_getYMin);
		tolua_function(tolua_S, "globalToLocal", lua_cc_fairygui_GObject_globalToLocal);
		tolua_function(tolua_S, "hitTest", lua_cc_fairygui_GObject_hitTest);
		tolua_function(tolua_S, "isDraggable", lua_cc_fairygui_GObject_isDraggable);
		tolua_function(tolua_S, "isGrayed", lua_cc_fairygui_GObject_isGrayed);
		tolua_function(tolua_S, "isPivotAsAnchor", lua_cc_fairygui_GObject_isPivotAsAnchor);
		tolua_function(tolua_S, "isPixelSnapping", lua_cc_fairygui_GObject_isPixelSnapping);
		tolua_function(tolua_S, "isTouchable", lua_cc_fairygui_GObject_isTouchable);
		tolua_function(tolua_S, "isVisible", lua_cc_fairygui_GObject_isVisible);
		tolua_function(tolua_S, "localToGlobal", lua_cc_fairygui_GObject_localToGlobal);
		tolua_function(tolua_S, "makeFullScreen", lua_cc_fairygui_GObject_makeFullScreen);
		tolua_function(tolua_S, "onStage", lua_cc_fairygui_GObject_onStage);
		tolua_function(tolua_S, "relations", lua_cc_fairygui_GObject_relations);
		tolua_function(tolua_S, "releaseDisplayLock", lua_cc_fairygui_GObject_releaseDisplayLock);
		tolua_function(tolua_S, "removeClickListener", lua_cc_fairygui_GObject_removeClickListener);
		tolua_function(tolua_S, "removeFromParent", lua_cc_fairygui_GObject_removeFromParent);
		tolua_function(tolua_S, "removeRelation", lua_cc_fairygui_GObject_removeRelation);
		tolua_function(tolua_S, "setAlpha", lua_cc_fairygui_GObject_setAlpha);
		tolua_function(tolua_S, "setCustomData", lua_cc_fairygui_GObject_setCustomData);
		tolua_function(tolua_S, "setDragBounds", lua_cc_fairygui_GObject_setDragBounds);
		tolua_function(tolua_S, "setDraggable", lua_cc_fairygui_GObject_setDraggable);
		tolua_function(tolua_S, "setGrayed", lua_cc_fairygui_GObject_setGrayed);
		tolua_function(tolua_S, "setGroup", lua_cc_fairygui_GObject_setGroup);
		tolua_function(tolua_S, "setHeight", lua_cc_fairygui_GObject_setHeight);
		tolua_function(tolua_S, "setIcon", lua_cc_fairygui_GObject_setIcon);
		tolua_function(tolua_S, "setPivot", lua_cc_fairygui_GObject_setPivot);
		tolua_function(tolua_S, "setPixelSnapping", lua_cc_fairygui_GObject_setPixelSnapping);
		tolua_function(tolua_S, "setPosition", lua_cc_fairygui_GObject_setPosition);
		tolua_function(tolua_S, "setProp", lua_cc_fairygui_GObject_setProp);
		tolua_function(tolua_S, "setRotation", lua_cc_fairygui_GObject_setRotation);
		tolua_function(tolua_S, "setScale", lua_cc_fairygui_GObject_setScale);
		tolua_function(tolua_S, "setScaleX", lua_cc_fairygui_GObject_setScaleX);
		tolua_function(tolua_S, "setScaleY", lua_cc_fairygui_GObject_setScaleY);
		tolua_function(tolua_S, "setSize", lua_cc_fairygui_GObject_setSize);
		tolua_function(tolua_S, "setSkewX", lua_cc_fairygui_GObject_setSkewX);
		tolua_function(tolua_S, "setSkewY", lua_cc_fairygui_GObject_setSkewY);
		tolua_function(tolua_S, "setSortingOrder", lua_cc_fairygui_GObject_setSortingOrder);
		tolua_function(tolua_S, "setText", lua_cc_fairygui_GObject_setText);
		tolua_function(tolua_S, "setTooltips", lua_cc_fairygui_GObject_setTooltips);
		tolua_function(tolua_S, "setTouchable", lua_cc_fairygui_GObject_setTouchable);
		tolua_function(tolua_S, "setVisible", lua_cc_fairygui_GObject_setVisible);
		tolua_function(tolua_S, "setWidth", lua_cc_fairygui_GObject_setWidth);
		tolua_function(tolua_S, "setX", lua_cc_fairygui_GObject_setX);
		tolua_function(tolua_S, "setXMin", lua_cc_fairygui_GObject_setXMin);
		tolua_function(tolua_S, "setY", lua_cc_fairygui_GObject_setY);
		tolua_function(tolua_S, "setYMin", lua_cc_fairygui_GObject_setYMin);
		tolua_function(tolua_S, "startDrag", lua_cc_fairygui_GObject_startDrag);
		tolua_function(tolua_S, "stopDrag", lua_cc_fairygui_GObject_stopDrag);
		tolua_function(tolua_S, "transformRect", lua_cc_fairygui_GObject_transformRect);
		tolua_function(tolua_S, "treeNode", lua_cc_fairygui_GObject_treeNode);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GObject_create);
		tolua_function(tolua_S, "getDraggingObject", lua_cc_fairygui_GObject_getDraggingObject);
		tolua_variable(tolua_S, "id", lua_cc_fairygui_GObject_getid, lua_cc_fairygui_GObject_setid);
		tolua_variable(tolua_S, "name", lua_cc_fairygui_GObject_getname, lua_cc_fairygui_GObject_setname);
		tolua_variable(tolua_S, "sourceSize", lua_cc_fairygui_GObject_getsourceSize, lua_cc_fairygui_GObject_setsourceSize);
		tolua_variable(tolua_S, "initSize", lua_cc_fairygui_GObject_getinitSize, lua_cc_fairygui_GObject_setinitSize);
		tolua_variable(tolua_S, "minSize", lua_cc_fairygui_GObject_getminSize, lua_cc_fairygui_GObject_setminSize);
		tolua_variable(tolua_S, "maxSize", lua_cc_fairygui_GObject_getmaxSize, lua_cc_fairygui_GObject_setmaxSize);
		tolua_variable(tolua_S, "_underConstruct", lua_cc_fairygui_GObject_get_underConstruct, lua_cc_fairygui_GObject_set_underConstruct);
		tolua_variable(tolua_S, "_gearLocked", lua_cc_fairygui_GObject_get_gearLocked, lua_cc_fairygui_GObject_set_gearLocked);
		tolua_variable(tolua_S, "_alignToBL", lua_cc_fairygui_GObject_get_alignToBL, lua_cc_fairygui_GObject_set_alignToBL);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GObject).name();
	g_luaType[typeName] = "fgui.GObject";
	g_typeCast["GObject"] = "fgui.GObject";
	return 1;
}

int lua_cc_fairygui_PackageItem_getBranch(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem:getBranch";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getBranch();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_PackageItem_getHighResolution(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem:getHighResolution";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getHighResolution();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_PackageItem_load(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem:load";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->load();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_PackageItem_getowner(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.owner getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->owner);
	return 1;
}
int lua_cc_fairygui_PackageItem_setowner(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.owner setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->owner, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_gettype(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.type getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->type);
	return 1;
}
int lua_cc_fairygui_PackageItem_settype(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.type setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->type, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getobjectType(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.objectType getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->objectType);
	return 1;
}
int lua_cc_fairygui_PackageItem_setobjectType(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.objectType setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->objectType, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getid(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.id getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->id);
	return 1;
}
int lua_cc_fairygui_PackageItem_setid(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.id setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->id, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getname(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.name getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->name);
	return 1;
}
int lua_cc_fairygui_PackageItem_setname(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.name setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->name, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getwidth(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.width getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->width);
	return 1;
}
int lua_cc_fairygui_PackageItem_setwidth(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.width setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->width, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getheight(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.height getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->height);
	return 1;
}
int lua_cc_fairygui_PackageItem_setheight(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.height setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->height, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getfile(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.file getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->file);
	return 1;
}
int lua_cc_fairygui_PackageItem_setfile(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.file setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->file, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getrawData(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.rawData getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->rawData);
	return 1;
}
int lua_cc_fairygui_PackageItem_setrawData(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.rawData setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->rawData, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getbranches(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.branches getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->branches);
	return 1;
}
int lua_cc_fairygui_PackageItem_setbranches(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.branches setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->branches, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_gethighResolution(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.highResolution getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->highResolution);
	return 1;
}
int lua_cc_fairygui_PackageItem_sethighResolution(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.highResolution setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->highResolution, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_gettexture(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.texture getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->texture);
	return 1;
}
int lua_cc_fairygui_PackageItem_settexture(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.texture setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->texture, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getscale9Grid(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.scale9Grid getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->scale9Grid);
	return 1;
}
int lua_cc_fairygui_PackageItem_setscale9Grid(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.scale9Grid setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->scale9Grid, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getscaleByTile(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.scaleByTile getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->scaleByTile);
	return 1;
}
int lua_cc_fairygui_PackageItem_setscaleByTile(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.scaleByTile setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->scaleByTile, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_gettileGridIndice(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.tileGridIndice getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->tileGridIndice);
	return 1;
}
int lua_cc_fairygui_PackageItem_settileGridIndice(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.tileGridIndice setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->tileGridIndice, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getspriteFrame(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.spriteFrame getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->spriteFrame);
	return 1;
}
int lua_cc_fairygui_PackageItem_setspriteFrame(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.spriteFrame setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->spriteFrame, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getpixelHitTestData(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.pixelHitTestData getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->pixelHitTestData);
	return 1;
}
int lua_cc_fairygui_PackageItem_setpixelHitTestData(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.pixelHitTestData setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->pixelHitTestData, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getanimation(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.animation getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->animation);
	return 1;
}
int lua_cc_fairygui_PackageItem_setanimation(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.animation setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->animation, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getdelayPerUnit(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.delayPerUnit getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->delayPerUnit);
	return 1;
}
int lua_cc_fairygui_PackageItem_setdelayPerUnit(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.delayPerUnit setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->delayPerUnit, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getrepeatDelay(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.repeatDelay getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->repeatDelay);
	return 1;
}
int lua_cc_fairygui_PackageItem_setrepeatDelay(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.repeatDelay setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->repeatDelay, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getswing(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.swing getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->swing);
	return 1;
}
int lua_cc_fairygui_PackageItem_setswing(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.swing setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->swing, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getextensionCreator(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.extensionCreator getter";
	constexpr auto LUA_FIELDNAME = "fgui.PackageItem.extensionCreator";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	handler_to_luafunction(tolua_S, query_luafunction_handler(tolua_S, 2, LUA_FIELDNAME));
	return 1;
}
int lua_cc_fairygui_PackageItem_setextensionCreator(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.extensionCreator setter";
	constexpr auto LUA_FIELDNAME = "fgui.PackageItem.extensionCreator";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		std::function<fairygui::GComponent * ()> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FIELDNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->extensionCreator = arg0;
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_gettranslated(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.translated getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->translated);
	return 1;
}
int lua_cc_fairygui_PackageItem_settranslated(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.translated setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->translated, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getbitmapFont(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.bitmapFont getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->bitmapFont);
	return 1;
}
int lua_cc_fairygui_PackageItem_setbitmapFont(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.bitmapFont setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->bitmapFont, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_getskeletonAnchor(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.skeletonAnchor getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->skeletonAnchor);
	return 1;
}
int lua_cc_fairygui_PackageItem_setskeletonAnchor(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem.skeletonAnchor setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PackageItem*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->skeletonAnchor, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PackageItem_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PackageItem";
	constexpr auto LUA_FNAME = "fgui.PackageItem constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::PackageItem();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_PackageItem_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_PackageItem(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.PackageItem");
	tolua_cclass(tolua_S, "PackageItem", "fgui.PackageItem", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "PackageItem");
		tolua_function(tolua_S, "new", lua_cc_fairygui_PackageItem_constructor);
		tolua_function(tolua_S, "getBranch", lua_cc_fairygui_PackageItem_getBranch);
		tolua_function(tolua_S, "getHighResolution", lua_cc_fairygui_PackageItem_getHighResolution);
		tolua_function(tolua_S, "load", lua_cc_fairygui_PackageItem_load);
		tolua_variable(tolua_S, "owner", lua_cc_fairygui_PackageItem_getowner, lua_cc_fairygui_PackageItem_setowner);
		tolua_variable(tolua_S, "type", lua_cc_fairygui_PackageItem_gettype, lua_cc_fairygui_PackageItem_settype);
		tolua_variable(tolua_S, "objectType", lua_cc_fairygui_PackageItem_getobjectType, lua_cc_fairygui_PackageItem_setobjectType);
		tolua_variable(tolua_S, "id", lua_cc_fairygui_PackageItem_getid, lua_cc_fairygui_PackageItem_setid);
		tolua_variable(tolua_S, "name", lua_cc_fairygui_PackageItem_getname, lua_cc_fairygui_PackageItem_setname);
		tolua_variable(tolua_S, "width", lua_cc_fairygui_PackageItem_getwidth, lua_cc_fairygui_PackageItem_setwidth);
		tolua_variable(tolua_S, "height", lua_cc_fairygui_PackageItem_getheight, lua_cc_fairygui_PackageItem_setheight);
		tolua_variable(tolua_S, "file", lua_cc_fairygui_PackageItem_getfile, lua_cc_fairygui_PackageItem_setfile);
		tolua_variable(tolua_S, "rawData", lua_cc_fairygui_PackageItem_getrawData, lua_cc_fairygui_PackageItem_setrawData);
		tolua_variable(tolua_S, "branches", lua_cc_fairygui_PackageItem_getbranches, lua_cc_fairygui_PackageItem_setbranches);
		tolua_variable(tolua_S, "highResolution", lua_cc_fairygui_PackageItem_gethighResolution, lua_cc_fairygui_PackageItem_sethighResolution);
		tolua_variable(tolua_S, "texture", lua_cc_fairygui_PackageItem_gettexture, lua_cc_fairygui_PackageItem_settexture);
		tolua_variable(tolua_S, "scale9Grid", lua_cc_fairygui_PackageItem_getscale9Grid, lua_cc_fairygui_PackageItem_setscale9Grid);
		tolua_variable(tolua_S, "scaleByTile", lua_cc_fairygui_PackageItem_getscaleByTile, lua_cc_fairygui_PackageItem_setscaleByTile);
		tolua_variable(tolua_S, "tileGridIndice", lua_cc_fairygui_PackageItem_gettileGridIndice, lua_cc_fairygui_PackageItem_settileGridIndice);
		tolua_variable(tolua_S, "spriteFrame", lua_cc_fairygui_PackageItem_getspriteFrame, lua_cc_fairygui_PackageItem_setspriteFrame);
		tolua_variable(tolua_S, "pixelHitTestData", lua_cc_fairygui_PackageItem_getpixelHitTestData, lua_cc_fairygui_PackageItem_setpixelHitTestData);
		tolua_variable(tolua_S, "animation", lua_cc_fairygui_PackageItem_getanimation, lua_cc_fairygui_PackageItem_setanimation);
		tolua_variable(tolua_S, "delayPerUnit", lua_cc_fairygui_PackageItem_getdelayPerUnit, lua_cc_fairygui_PackageItem_setdelayPerUnit);
		tolua_variable(tolua_S, "repeatDelay", lua_cc_fairygui_PackageItem_getrepeatDelay, lua_cc_fairygui_PackageItem_setrepeatDelay);
		tolua_variable(tolua_S, "swing", lua_cc_fairygui_PackageItem_getswing, lua_cc_fairygui_PackageItem_setswing);
		tolua_variable(tolua_S, "extensionCreator", lua_cc_fairygui_PackageItem_getextensionCreator, lua_cc_fairygui_PackageItem_setextensionCreator);
		tolua_variable(tolua_S, "translated", lua_cc_fairygui_PackageItem_gettranslated, lua_cc_fairygui_PackageItem_settranslated);
		tolua_variable(tolua_S, "bitmapFont", lua_cc_fairygui_PackageItem_getbitmapFont, lua_cc_fairygui_PackageItem_setbitmapFont);
		tolua_variable(tolua_S, "skeletonAnchor", lua_cc_fairygui_PackageItem_getskeletonAnchor, lua_cc_fairygui_PackageItem_setskeletonAnchor);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::PackageItem).name();
	g_luaType[typeName] = "fgui.PackageItem";
	g_typeCast["PackageItem"] = "fgui.PackageItem";
	return 1;
}

int lua_cc_fairygui_UIPackage_addPackage(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:addPackage";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::UIPackage::addPackage(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIPackage_createObject(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:createObject";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::UIPackage::createObject(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_UIPackage_createObjectFromURL(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:createObjectFromURL";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::UIPackage::createObjectFromURL(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIPackage_getBranch(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:getBranch";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::UIPackage::getBranch();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_UIPackage_getById(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:getById";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::UIPackage::getById(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIPackage_getByName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:getByName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::UIPackage::getByName(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIPackage_getEmptyTexture(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:getEmptyTexture";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::UIPackage::getEmptyTexture();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_UIPackage_getId(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:getId";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::UIPackage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getId();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_UIPackage_getItem(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:getItem";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::UIPackage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getItem(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIPackage_getItemByName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:getItemByName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::UIPackage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getItemByName(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIPackage_getItemByURL(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:getItemByURL";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::UIPackage::getItemByURL(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIPackage_getItemURL(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:getItemURL";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::UIPackage::getItemURL(arg0, arg1);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_UIPackage_getName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:getName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::UIPackage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getName();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_UIPackage_getVar(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:getVar";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::UIPackage::getVar(arg0);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIPackage_normalizeURL(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:normalizeURL";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::UIPackage::normalizeURL(arg0);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIPackage_removeAllPackages(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:removeAllPackages";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		fairygui::UIPackage::removeAllPackages();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_UIPackage_removePackage(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:removePackage";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		fairygui::UIPackage::removePackage(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIPackage_setBranch(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:setBranch";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		fairygui::UIPackage::setBranch(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIPackage_setVar(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage:setVar";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		fairygui::UIPackage::setVar(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_UIPackage_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIPackage";
	constexpr auto LUA_FNAME = "fgui.UIPackage constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::UIPackage();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_UIPackage_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_UIPackage(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.UIPackage");
	tolua_cclass(tolua_S, "UIPackage", "fgui.UIPackage", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "UIPackage");
		tolua_function(tolua_S, "new", lua_cc_fairygui_UIPackage_constructor);
		tolua_function(tolua_S, "getId", lua_cc_fairygui_UIPackage_getId);
		tolua_function(tolua_S, "getItem", lua_cc_fairygui_UIPackage_getItem);
		tolua_function(tolua_S, "getItemByName", lua_cc_fairygui_UIPackage_getItemByName);
		tolua_function(tolua_S, "getName", lua_cc_fairygui_UIPackage_getName);
		tolua_function(tolua_S, "addPackage", lua_cc_fairygui_UIPackage_addPackage);
		tolua_function(tolua_S, "createObject", lua_cc_fairygui_UIPackage_createObject);
		tolua_function(tolua_S, "createObjectFromURL", lua_cc_fairygui_UIPackage_createObjectFromURL);
		tolua_function(tolua_S, "getBranch", lua_cc_fairygui_UIPackage_getBranch);
		tolua_function(tolua_S, "getById", lua_cc_fairygui_UIPackage_getById);
		tolua_function(tolua_S, "getByName", lua_cc_fairygui_UIPackage_getByName);
		tolua_function(tolua_S, "getEmptyTexture", lua_cc_fairygui_UIPackage_getEmptyTexture);
		tolua_function(tolua_S, "getItemByURL", lua_cc_fairygui_UIPackage_getItemByURL);
		tolua_function(tolua_S, "getItemURL", lua_cc_fairygui_UIPackage_getItemURL);
		tolua_function(tolua_S, "getVar", lua_cc_fairygui_UIPackage_getVar);
		tolua_function(tolua_S, "normalizeURL", lua_cc_fairygui_UIPackage_normalizeURL);
		tolua_function(tolua_S, "removeAllPackages", lua_cc_fairygui_UIPackage_removeAllPackages);
		tolua_function(tolua_S, "removePackage", lua_cc_fairygui_UIPackage_removePackage);
		tolua_function(tolua_S, "setBranch", lua_cc_fairygui_UIPackage_setBranch);
		tolua_function(tolua_S, "setVar", lua_cc_fairygui_UIPackage_setVar);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::UIPackage).name();
	g_luaType[typeName] = "fgui.UIPackage";
	g_typeCast["UIPackage"] = "fgui.UIPackage";
	return 1;
}

int lua_cc_fairygui_GImage_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GImage::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GImage_getColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage:getColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GImage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColor();
		color3b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GImage_getFillAmount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage:getFillAmount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GImage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFillAmount();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GImage_getFillMethod(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage:getFillMethod";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GImage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFillMethod();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GImage_getFillOrigin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage:getFillOrigin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GImage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFillOrigin();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GImage_getFlip(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage:getFlip";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GImage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFlip();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GImage_isFillClockwise(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage:isFillClockwise";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GImage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isFillClockwise();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GImage_setColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage:setColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GImage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= luaval_to_color3b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GImage_setFillAmount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage:setFillAmount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GImage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFillAmount(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GImage_setFillClockwise(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage:setFillClockwise";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GImage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFillClockwise(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GImage_setFillMethod(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage:setFillMethod";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GImage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::FillMethod arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFillMethod(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GImage_setFillOrigin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage:setFillOrigin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GImage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::FillOrigin arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFillOrigin(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GImage_setFlip(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage:setFlip";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GImage*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::FlipType arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFlip(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GImage_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GImage";
	constexpr auto LUA_FNAME = "fgui.GImage constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GImage();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GImage_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GImage(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GImage");
	tolua_cclass(tolua_S, "GImage", "fgui.GImage", "fgui.GObject", nullptr);

	tolua_beginmodule(tolua_S, "GImage");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GImage_constructor);
		tolua_function(tolua_S, "getColor", lua_cc_fairygui_GImage_getColor);
		tolua_function(tolua_S, "getFillAmount", lua_cc_fairygui_GImage_getFillAmount);
		tolua_function(tolua_S, "getFillMethod", lua_cc_fairygui_GImage_getFillMethod);
		tolua_function(tolua_S, "getFillOrigin", lua_cc_fairygui_GImage_getFillOrigin);
		tolua_function(tolua_S, "getFlip", lua_cc_fairygui_GImage_getFlip);
		tolua_function(tolua_S, "isFillClockwise", lua_cc_fairygui_GImage_isFillClockwise);
		tolua_function(tolua_S, "setColor", lua_cc_fairygui_GImage_setColor);
		tolua_function(tolua_S, "setFillAmount", lua_cc_fairygui_GImage_setFillAmount);
		tolua_function(tolua_S, "setFillClockwise", lua_cc_fairygui_GImage_setFillClockwise);
		tolua_function(tolua_S, "setFillMethod", lua_cc_fairygui_GImage_setFillMethod);
		tolua_function(tolua_S, "setFillOrigin", lua_cc_fairygui_GImage_setFillOrigin);
		tolua_function(tolua_S, "setFlip", lua_cc_fairygui_GImage_setFlip);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GImage_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GImage).name();
	g_luaType[typeName] = "fgui.GImage";
	g_typeCast["GImage"] = "fgui.GImage";
	return 1;
}

int lua_cc_fairygui_GMovieClip_advance(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip:advance";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->advance(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GMovieClip_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GMovieClip::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GMovieClip_getColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip:getColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColor();
		color3b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GMovieClip_getFlip(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip:getFlip";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFlip();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GMovieClip_getFrame(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip:getFrame";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFrame();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GMovieClip_getTimeScale(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip:getTimeScale";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTimeScale();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GMovieClip_isPlaying(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip:isPlaying";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isPlaying();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GMovieClip_setColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip:setColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= luaval_to_color3b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GMovieClip_setFlip(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip:setFlip";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::FlipType arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFlip(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GMovieClip_setFrame(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip:setFrame";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFrame(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GMovieClip_setPlaySettings(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip:setPlaySettings";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPlaySettings();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPlaySettings(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		int arg0;
		int arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPlaySettings(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) {
		int arg0;
		int arg1;
		int arg2;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPlaySettings(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 4) {
		int arg0;
		int arg1;
		int arg2;
		int arg3;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 5, &arg3, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPlaySettings(arg0, arg1, arg2, arg3);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 5) {
		int arg0;
		int arg1;
		int arg2;
		int arg3;
		std::function<void ()> arg4;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 6, &arg4, LUA_FNAME);
		int handler6 = query_luafunction_handler(tolua_S, 6, LUA_FNAME);
		ok &= handler6 != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPlaySettings(arg0, arg1, arg2, arg3, arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 5");
}
int lua_cc_fairygui_GMovieClip_setPlaying(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip:setPlaying";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPlaying(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GMovieClip_setTimeScale(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip:setTimeScale";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GMovieClip*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTimeScale(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GMovieClip_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GMovieClip";
	constexpr auto LUA_FNAME = "fgui.GMovieClip constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GMovieClip();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GMovieClip_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GMovieClip(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GMovieClip");
	tolua_cclass(tolua_S, "GMovieClip", "fgui.GMovieClip", "fgui.GObject", nullptr);

	tolua_beginmodule(tolua_S, "GMovieClip");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GMovieClip_constructor);
		tolua_function(tolua_S, "advance", lua_cc_fairygui_GMovieClip_advance);
		tolua_function(tolua_S, "getColor", lua_cc_fairygui_GMovieClip_getColor);
		tolua_function(tolua_S, "getFlip", lua_cc_fairygui_GMovieClip_getFlip);
		tolua_function(tolua_S, "getFrame", lua_cc_fairygui_GMovieClip_getFrame);
		tolua_function(tolua_S, "getTimeScale", lua_cc_fairygui_GMovieClip_getTimeScale);
		tolua_function(tolua_S, "isPlaying", lua_cc_fairygui_GMovieClip_isPlaying);
		tolua_function(tolua_S, "setColor", lua_cc_fairygui_GMovieClip_setColor);
		tolua_function(tolua_S, "setFlip", lua_cc_fairygui_GMovieClip_setFlip);
		tolua_function(tolua_S, "setFrame", lua_cc_fairygui_GMovieClip_setFrame);
		tolua_function(tolua_S, "setPlaySettings", lua_cc_fairygui_GMovieClip_setPlaySettings);
		tolua_function(tolua_S, "setPlaying", lua_cc_fairygui_GMovieClip_setPlaying);
		tolua_function(tolua_S, "setTimeScale", lua_cc_fairygui_GMovieClip_setTimeScale);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GMovieClip_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GMovieClip).name();
	g_luaType[typeName] = "fgui.GMovieClip";
	g_typeCast["GMovieClip"] = "fgui.GMovieClip";
	return 1;
}

int lua_cc_fairygui_TextFormat_disableEffect(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat:disableEffect";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->disableEffect(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_enableEffect(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat:enableEffect";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->enableEffect(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_hasEffect(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat:hasEffect";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->hasEffect(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_setFormat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat:setFormat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::TextFormat arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFormat(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getface(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.face getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->face);
	return 1;
}
int lua_cc_fairygui_TextFormat_setface(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.face setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->face, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getfontSize(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.fontSize getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->fontSize);
	return 1;
}
int lua_cc_fairygui_TextFormat_setfontSize(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.fontSize setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->fontSize, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getcolor(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.color getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->color);
	return 1;
}
int lua_cc_fairygui_TextFormat_setcolor(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.color setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->color, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getbold(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.bold getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->bold);
	return 1;
}
int lua_cc_fairygui_TextFormat_setbold(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.bold setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->bold, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getitalics(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.italics getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->italics);
	return 1;
}
int lua_cc_fairygui_TextFormat_setitalics(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.italics setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->italics, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getunderline(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.underline getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->underline);
	return 1;
}
int lua_cc_fairygui_TextFormat_setunderline(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.underline setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->underline, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getlineSpacing(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.lineSpacing getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->lineSpacing);
	return 1;
}
int lua_cc_fairygui_TextFormat_setlineSpacing(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.lineSpacing setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->lineSpacing, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getletterSpacing(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.letterSpacing getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->letterSpacing);
	return 1;
}
int lua_cc_fairygui_TextFormat_setletterSpacing(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.letterSpacing setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->letterSpacing, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getalign(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.align getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->align);
	return 1;
}
int lua_cc_fairygui_TextFormat_setalign(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.align setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->align, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getverticalAlign(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.verticalAlign getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->verticalAlign);
	return 1;
}
int lua_cc_fairygui_TextFormat_setverticalAlign(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.verticalAlign setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->verticalAlign, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_geteffect(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.effect getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->effect);
	return 1;
}
int lua_cc_fairygui_TextFormat_seteffect(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.effect setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->effect, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getoutlineColor(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.outlineColor getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->outlineColor);
	return 1;
}
int lua_cc_fairygui_TextFormat_setoutlineColor(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.outlineColor setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->outlineColor, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getoutlineSize(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.outlineSize getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->outlineSize);
	return 1;
}
int lua_cc_fairygui_TextFormat_setoutlineSize(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.outlineSize setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->outlineSize, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getshadowColor(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.shadowColor getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->shadowColor);
	return 1;
}
int lua_cc_fairygui_TextFormat_setshadowColor(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.shadowColor setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->shadowColor, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getshadowOffset(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.shadowOffset getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->shadowOffset);
	return 1;
}
int lua_cc_fairygui_TextFormat_setshadowOffset(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.shadowOffset setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->shadowOffset, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getshadowBlurRadius(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.shadowBlurRadius getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->shadowBlurRadius);
	return 1;
}
int lua_cc_fairygui_TextFormat_setshadowBlurRadius(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.shadowBlurRadius setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->shadowBlurRadius, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_getglowColor(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.glowColor getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->glowColor);
	return 1;
}
int lua_cc_fairygui_TextFormat_setglowColor(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat.glowColor setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->glowColor, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_get_hasColor(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat._hasColor getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->_hasColor);
	return 1;
}
int lua_cc_fairygui_TextFormat_set_hasColor(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat._hasColor setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::TextFormat*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->_hasColor, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_TextFormat_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.TextFormat";
	constexpr auto LUA_FNAME = "fgui.TextFormat constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::TextFormat();
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_TextFormat_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_TextFormat(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.TextFormat");
	tolua_cclass(tolua_S, "TextFormat", "fgui.TextFormat", "", nullptr);

	tolua_beginmodule(tolua_S, "TextFormat");
		tolua_function(tolua_S, "new", lua_cc_fairygui_TextFormat_constructor);
		tolua_function(tolua_S, "disableEffect", lua_cc_fairygui_TextFormat_disableEffect);
		tolua_function(tolua_S, "enableEffect", lua_cc_fairygui_TextFormat_enableEffect);
		tolua_function(tolua_S, "hasEffect", lua_cc_fairygui_TextFormat_hasEffect);
		tolua_function(tolua_S, "setFormat", lua_cc_fairygui_TextFormat_setFormat);
		tolua_variable(tolua_S, "face", lua_cc_fairygui_TextFormat_getface, lua_cc_fairygui_TextFormat_setface);
		tolua_variable(tolua_S, "fontSize", lua_cc_fairygui_TextFormat_getfontSize, lua_cc_fairygui_TextFormat_setfontSize);
		tolua_variable(tolua_S, "color", lua_cc_fairygui_TextFormat_getcolor, lua_cc_fairygui_TextFormat_setcolor);
		tolua_variable(tolua_S, "bold", lua_cc_fairygui_TextFormat_getbold, lua_cc_fairygui_TextFormat_setbold);
		tolua_variable(tolua_S, "italics", lua_cc_fairygui_TextFormat_getitalics, lua_cc_fairygui_TextFormat_setitalics);
		tolua_variable(tolua_S, "underline", lua_cc_fairygui_TextFormat_getunderline, lua_cc_fairygui_TextFormat_setunderline);
		tolua_variable(tolua_S, "lineSpacing", lua_cc_fairygui_TextFormat_getlineSpacing, lua_cc_fairygui_TextFormat_setlineSpacing);
		tolua_variable(tolua_S, "letterSpacing", lua_cc_fairygui_TextFormat_getletterSpacing, lua_cc_fairygui_TextFormat_setletterSpacing);
		tolua_variable(tolua_S, "align", lua_cc_fairygui_TextFormat_getalign, lua_cc_fairygui_TextFormat_setalign);
		tolua_variable(tolua_S, "verticalAlign", lua_cc_fairygui_TextFormat_getverticalAlign, lua_cc_fairygui_TextFormat_setverticalAlign);
		tolua_variable(tolua_S, "effect", lua_cc_fairygui_TextFormat_geteffect, lua_cc_fairygui_TextFormat_seteffect);
		tolua_variable(tolua_S, "outlineColor", lua_cc_fairygui_TextFormat_getoutlineColor, lua_cc_fairygui_TextFormat_setoutlineColor);
		tolua_variable(tolua_S, "outlineSize", lua_cc_fairygui_TextFormat_getoutlineSize, lua_cc_fairygui_TextFormat_setoutlineSize);
		tolua_variable(tolua_S, "shadowColor", lua_cc_fairygui_TextFormat_getshadowColor, lua_cc_fairygui_TextFormat_setshadowColor);
		tolua_variable(tolua_S, "shadowOffset", lua_cc_fairygui_TextFormat_getshadowOffset, lua_cc_fairygui_TextFormat_setshadowOffset);
		tolua_variable(tolua_S, "shadowBlurRadius", lua_cc_fairygui_TextFormat_getshadowBlurRadius, lua_cc_fairygui_TextFormat_setshadowBlurRadius);
		tolua_variable(tolua_S, "glowColor", lua_cc_fairygui_TextFormat_getglowColor, lua_cc_fairygui_TextFormat_setglowColor);
		tolua_variable(tolua_S, "_hasColor", lua_cc_fairygui_TextFormat_get_hasColor, lua_cc_fairygui_TextFormat_set_hasColor);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::TextFormat).name();
	g_luaType[typeName] = "fgui.TextFormat";
	g_typeCast["TextFormat"] = "fgui.TextFormat";
	return 1;
}

int lua_cc_fairygui_FUILabel_applyTextFormat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUILabel";
	constexpr auto LUA_FNAME = "fgui.FUILabel:applyTextFormat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUILabel*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->applyTextFormat();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUILabel_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUILabel";
	constexpr auto LUA_FNAME = "fgui.FUILabel:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::FUILabel::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUILabel_getText(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUILabel";
	constexpr auto LUA_FNAME = "fgui.FUILabel:getText";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUILabel*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getText();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUILabel_getTextFormat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUILabel";
	constexpr auto LUA_FNAME = "fgui.FUILabel:getTextFormat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUILabel*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTextFormat();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUILabel_setGrayed(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUILabel";
	constexpr auto LUA_FNAME = "fgui.FUILabel:setGrayed";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUILabel*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setGrayed(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUILabel_setText(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUILabel";
	constexpr auto LUA_FNAME = "fgui.FUILabel:setText";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUILabel*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setText(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUILabel_setUnderlineColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUILabel";
	constexpr auto LUA_FNAME = "fgui.FUILabel:setUnderlineColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUILabel*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= luaval_to_color3b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setUnderlineColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUILabel_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUILabel";
	constexpr auto LUA_FNAME = "fgui.FUILabel constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::FUILabel();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_FUILabel_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_FUILabel(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.FUILabel");
	tolua_cclass(tolua_S, "FUILabel", "fgui.FUILabel", "cc.Label", nullptr);

	tolua_beginmodule(tolua_S, "FUILabel");
		tolua_function(tolua_S, "new", lua_cc_fairygui_FUILabel_constructor);
		tolua_function(tolua_S, "applyTextFormat", lua_cc_fairygui_FUILabel_applyTextFormat);
		tolua_function(tolua_S, "getText", lua_cc_fairygui_FUILabel_getText);
		tolua_function(tolua_S, "getTextFormat", lua_cc_fairygui_FUILabel_getTextFormat);
		tolua_function(tolua_S, "setGrayed", lua_cc_fairygui_FUILabel_setGrayed);
		tolua_function(tolua_S, "setText", lua_cc_fairygui_FUILabel_setText);
		tolua_function(tolua_S, "setUnderlineColor", lua_cc_fairygui_FUILabel_setUnderlineColor);
		tolua_function(tolua_S, "create", lua_cc_fairygui_FUILabel_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::FUILabel).name();
	g_luaType[typeName] = "fgui.FUILabel";
	g_typeCast["FUILabel"] = "fgui.FUILabel";
	return 1;
}

int lua_cc_fairygui_GTextField_applyTextFormat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:applyTextFormat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->applyTextFormat();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTextField_flushVars(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:flushVars";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->flushVars();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTextField_getAutoSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:getAutoSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getAutoSize();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTextField_getColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:getColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColor();
		color3b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTextField_getFontSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:getFontSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFontSize();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTextField_getOutlineColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:getOutlineColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getOutlineColor();
		color3b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTextField_getTextFormat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:getTextFormat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTextFormat();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTextField_getTextSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:getTextSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTextSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTextField_isSingleLine(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:isSingleLine";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isSingleLine();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTextField_isUBBEnabled(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:isUBBEnabled";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isUBBEnabled();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTextField_setAutoSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:setAutoSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::AutoSizeType arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAutoSize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTextField_setColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:setColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= luaval_to_color3b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTextField_setFontSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:setFontSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFontSize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTextField_setOutlineColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:setOutlineColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= luaval_to_color3b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setOutlineColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTextField_setSingleLine(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:setSingleLine";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSingleLine(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTextField_setUBBEnabled(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:setUBBEnabled";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setUBBEnabled(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTextField_setVar(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextField";
	constexpr auto LUA_FNAME = "fgui.GTextField:setVar";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		cocos2d::Value arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_ccvalue(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setVar(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
static int lua_cc_fairygui_GTextField_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GTextField(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GTextField");
	tolua_cclass(tolua_S, "GTextField", "fgui.GTextField", "fgui.GObject", nullptr);

	tolua_beginmodule(tolua_S, "GTextField");
		tolua_function(tolua_S, "applyTextFormat", lua_cc_fairygui_GTextField_applyTextFormat);
		tolua_function(tolua_S, "flushVars", lua_cc_fairygui_GTextField_flushVars);
		tolua_function(tolua_S, "getAutoSize", lua_cc_fairygui_GTextField_getAutoSize);
		tolua_function(tolua_S, "getColor", lua_cc_fairygui_GTextField_getColor);
		tolua_function(tolua_S, "getFontSize", lua_cc_fairygui_GTextField_getFontSize);
		tolua_function(tolua_S, "getOutlineColor", lua_cc_fairygui_GTextField_getOutlineColor);
		tolua_function(tolua_S, "getTextFormat", lua_cc_fairygui_GTextField_getTextFormat);
		tolua_function(tolua_S, "getTextSize", lua_cc_fairygui_GTextField_getTextSize);
		tolua_function(tolua_S, "isSingleLine", lua_cc_fairygui_GTextField_isSingleLine);
		tolua_function(tolua_S, "isUBBEnabled", lua_cc_fairygui_GTextField_isUBBEnabled);
		tolua_function(tolua_S, "setAutoSize", lua_cc_fairygui_GTextField_setAutoSize);
		tolua_function(tolua_S, "setColor", lua_cc_fairygui_GTextField_setColor);
		tolua_function(tolua_S, "setFontSize", lua_cc_fairygui_GTextField_setFontSize);
		tolua_function(tolua_S, "setOutlineColor", lua_cc_fairygui_GTextField_setOutlineColor);
		tolua_function(tolua_S, "setSingleLine", lua_cc_fairygui_GTextField_setSingleLine);
		tolua_function(tolua_S, "setUBBEnabled", lua_cc_fairygui_GTextField_setUBBEnabled);
		tolua_function(tolua_S, "setVar", lua_cc_fairygui_GTextField_setVar);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GTextField).name();
	g_luaType[typeName] = "fgui.GTextField";
	g_typeCast["GTextField"] = "fgui.GTextField";
	return 1;
}

int lua_cc_fairygui_GBasicTextField_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GBasicTextField";
	constexpr auto LUA_FNAME = "fgui.GBasicTextField:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GBasicTextField::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GBasicTextField_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GBasicTextField";
	constexpr auto LUA_FNAME = "fgui.GBasicTextField constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GBasicTextField();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GBasicTextField_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GBasicTextField(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GBasicTextField");
	tolua_cclass(tolua_S, "GBasicTextField", "fgui.GBasicTextField", "fgui.GTextField", nullptr);

	tolua_beginmodule(tolua_S, "GBasicTextField");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GBasicTextField_constructor);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GBasicTextField_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GBasicTextField).name();
	g_luaType[typeName] = "fgui.GBasicTextField";
	g_typeCast["GBasicTextField"] = "fgui.GBasicTextField";
	return 1;
}

int lua_cc_fairygui_FUIRichText_applyTextFormat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:applyTextFormat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->applyTextFormat();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIRichText_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::FUIRichText::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIRichText_getAnchorFontColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:getAnchorFontColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getAnchorFontColor();
		color3b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIRichText_getControl(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:getControl";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getControl(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIRichText_getControls(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:getControls";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getControls();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIRichText_getDimensions(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:getDimensions";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getDimensions();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIRichText_getOverflow(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:getOverflow";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getOverflow();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIRichText_getTextFormat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:getTextFormat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTextFormat();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIRichText_hitTestLink(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:hitTestLink";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->hitTestLink(arg0);
		tolua_pushstring(tolua_S, (const char*)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIRichText_isAnchorTextUnderline(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:isAnchorTextUnderline";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isAnchorTextUnderline();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIRichText_parseOptions(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:parseOptions";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->parseOptions();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIRichText_setAnchorFontColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:setAnchorFontColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= luaval_to_color3b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAnchorFontColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIRichText_setAnchorTextUnderline(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:setAnchorTextUnderline";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAnchorTextUnderline(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIRichText_setDimensions(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:setDimensions";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setDimensions(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_FUIRichText_setObjectFactory(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:setObjectFactory";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::function<fairygui::HtmlObject * (fairygui::HtmlElement *)> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		int handler2 = query_luafunction_handler(tolua_S, 2, LUA_FNAME);
		ok &= handler2 != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setObjectFactory(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIRichText_setOverflow(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:setOverflow";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Label::Overflow arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setOverflow(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIRichText_setText(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText:setText";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIRichText*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setText(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIRichText_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIRichText";
	constexpr auto LUA_FNAME = "fgui.FUIRichText constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::FUIRichText();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_FUIRichText_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_FUIRichText(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.FUIRichText");
	tolua_cclass(tolua_S, "FUIRichText", "fgui.FUIRichText", "cc.Node", nullptr);

	tolua_beginmodule(tolua_S, "FUIRichText");
		tolua_function(tolua_S, "new", lua_cc_fairygui_FUIRichText_constructor);
		tolua_function(tolua_S, "applyTextFormat", lua_cc_fairygui_FUIRichText_applyTextFormat);
		tolua_function(tolua_S, "getAnchorFontColor", lua_cc_fairygui_FUIRichText_getAnchorFontColor);
		tolua_function(tolua_S, "getControl", lua_cc_fairygui_FUIRichText_getControl);
		tolua_function(tolua_S, "getControls", lua_cc_fairygui_FUIRichText_getControls);
		tolua_function(tolua_S, "getDimensions", lua_cc_fairygui_FUIRichText_getDimensions);
		tolua_function(tolua_S, "getOverflow", lua_cc_fairygui_FUIRichText_getOverflow);
		tolua_function(tolua_S, "getTextFormat", lua_cc_fairygui_FUIRichText_getTextFormat);
		tolua_function(tolua_S, "hitTestLink", lua_cc_fairygui_FUIRichText_hitTestLink);
		tolua_function(tolua_S, "isAnchorTextUnderline", lua_cc_fairygui_FUIRichText_isAnchorTextUnderline);
		tolua_function(tolua_S, "parseOptions", lua_cc_fairygui_FUIRichText_parseOptions);
		tolua_function(tolua_S, "setAnchorFontColor", lua_cc_fairygui_FUIRichText_setAnchorFontColor);
		tolua_function(tolua_S, "setAnchorTextUnderline", lua_cc_fairygui_FUIRichText_setAnchorTextUnderline);
		tolua_function(tolua_S, "setDimensions", lua_cc_fairygui_FUIRichText_setDimensions);
		tolua_function(tolua_S, "setObjectFactory", lua_cc_fairygui_FUIRichText_setObjectFactory);
		tolua_function(tolua_S, "setOverflow", lua_cc_fairygui_FUIRichText_setOverflow);
		tolua_function(tolua_S, "setText", lua_cc_fairygui_FUIRichText_setText);
		tolua_function(tolua_S, "create", lua_cc_fairygui_FUIRichText_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::FUIRichText).name();
	g_luaType[typeName] = "fgui.FUIRichText";
	g_typeCast["FUIRichText"] = "fgui.FUIRichText";
	return 1;
}

int lua_cc_fairygui_GRichTextField_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRichTextField";
	constexpr auto LUA_FNAME = "fgui.GRichTextField:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GRichTextField::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRichTextField_getControl(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRichTextField";
	constexpr auto LUA_FNAME = "fgui.GRichTextField:getControl";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRichTextField*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getControl(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRichTextField_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRichTextField";
	constexpr auto LUA_FNAME = "fgui.GRichTextField constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GRichTextField();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GRichTextField_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GRichTextField(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GRichTextField");
	tolua_cclass(tolua_S, "GRichTextField", "fgui.GRichTextField", "fgui.GTextField", nullptr);

	tolua_beginmodule(tolua_S, "GRichTextField");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GRichTextField_constructor);
		tolua_function(tolua_S, "getControl", lua_cc_fairygui_GRichTextField_getControl);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GRichTextField_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GRichTextField).name();
	g_luaType[typeName] = "fgui.GRichTextField";
	g_typeCast["GRichTextField"] = "fgui.GRichTextField";
	return 1;
}

int lua_cc_fairygui_FUIInput_applyTextFormat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIInput";
	constexpr auto LUA_FNAME = "fgui.FUIInput:applyTextFormat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->applyTextFormat();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIInput_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIInput";
	constexpr auto LUA_FNAME = "fgui.FUIInput:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::FUIInput::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIInput_getText(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIInput";
	constexpr auto LUA_FNAME = "fgui.FUIInput:getText";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getText();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIInput_getTextFormat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIInput";
	constexpr auto LUA_FNAME = "fgui.FUIInput:getTextFormat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTextFormat();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIInput_isPassword(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIInput";
	constexpr auto LUA_FNAME = "fgui.FUIInput:isPassword";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isPassword();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIInput_isSingleLine(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIInput";
	constexpr auto LUA_FNAME = "fgui.FUIInput:isSingleLine";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isSingleLine();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIInput_keyboardType(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIInput";
	constexpr auto LUA_FNAME = "fgui.FUIInput:keyboardType";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->keyboardType();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIInput_openKeyboard(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIInput";
	constexpr auto LUA_FNAME = "fgui.FUIInput:openKeyboard";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->openKeyboard();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIInput_setKeyboardType(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIInput";
	constexpr auto LUA_FNAME = "fgui.FUIInput:setKeyboardType";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setKeyboardType(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIInput_setPassword(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIInput";
	constexpr auto LUA_FNAME = "fgui.FUIInput:setPassword";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPassword(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIInput_setSingleLine(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIInput";
	constexpr auto LUA_FNAME = "fgui.FUIInput:setSingleLine";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSingleLine(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIInput_setText(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIInput";
	constexpr auto LUA_FNAME = "fgui.FUIInput:setText";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setText(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIInput_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIInput";
	constexpr auto LUA_FNAME = "fgui.FUIInput constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::FUIInput();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_FUIInput_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_FUIInput(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.FUIInput");
	tolua_cclass(tolua_S, "FUIInput", "fgui.FUIInput", "ccui.EditBox", nullptr);

	tolua_beginmodule(tolua_S, "FUIInput");
		tolua_function(tolua_S, "new", lua_cc_fairygui_FUIInput_constructor);
		tolua_function(tolua_S, "applyTextFormat", lua_cc_fairygui_FUIInput_applyTextFormat);
		tolua_function(tolua_S, "getText", lua_cc_fairygui_FUIInput_getText);
		tolua_function(tolua_S, "getTextFormat", lua_cc_fairygui_FUIInput_getTextFormat);
		tolua_function(tolua_S, "isPassword", lua_cc_fairygui_FUIInput_isPassword);
		tolua_function(tolua_S, "isSingleLine", lua_cc_fairygui_FUIInput_isSingleLine);
		tolua_function(tolua_S, "keyboardType", lua_cc_fairygui_FUIInput_keyboardType);
		tolua_function(tolua_S, "openKeyboard", lua_cc_fairygui_FUIInput_openKeyboard);
		tolua_function(tolua_S, "setKeyboardType", lua_cc_fairygui_FUIInput_setKeyboardType);
		tolua_function(tolua_S, "setPassword", lua_cc_fairygui_FUIInput_setPassword);
		tolua_function(tolua_S, "setSingleLine", lua_cc_fairygui_FUIInput_setSingleLine);
		tolua_function(tolua_S, "setText", lua_cc_fairygui_FUIInput_setText);
		tolua_function(tolua_S, "create", lua_cc_fairygui_FUIInput_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::FUIInput).name();
	g_luaType[typeName] = "fgui.FUIInput";
	g_typeCast["FUIInput"] = "fgui.FUIInput";
	return 1;
}

int lua_cc_fairygui_GTextInput_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextInput";
	constexpr auto LUA_FNAME = "fgui.GTextInput:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GTextInput::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTextInput_setKeyboardType(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextInput";
	constexpr auto LUA_FNAME = "fgui.GTextInput:setKeyboardType";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setKeyboardType(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTextInput_setMaxLength(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextInput";
	constexpr auto LUA_FNAME = "fgui.GTextInput:setMaxLength";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setMaxLength(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTextInput_setPassword(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextInput";
	constexpr auto LUA_FNAME = "fgui.GTextInput:setPassword";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPassword(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTextInput_setPrompt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextInput";
	constexpr auto LUA_FNAME = "fgui.GTextInput:setPrompt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPrompt(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTextInput_setRestrict(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextInput";
	constexpr auto LUA_FNAME = "fgui.GTextInput:setRestrict";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTextInput*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setRestrict(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTextInput_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTextInput";
	constexpr auto LUA_FNAME = "fgui.GTextInput constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GTextInput();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GTextInput_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GTextInput(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GTextInput");
	tolua_cclass(tolua_S, "GTextInput", "fgui.GTextInput", "fgui.GTextField", nullptr);

	tolua_beginmodule(tolua_S, "GTextInput");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GTextInput_constructor);
		tolua_function(tolua_S, "setKeyboardType", lua_cc_fairygui_GTextInput_setKeyboardType);
		tolua_function(tolua_S, "setMaxLength", lua_cc_fairygui_GTextInput_setMaxLength);
		tolua_function(tolua_S, "setPassword", lua_cc_fairygui_GTextInput_setPassword);
		tolua_function(tolua_S, "setPrompt", lua_cc_fairygui_GTextInput_setPrompt);
		tolua_function(tolua_S, "setRestrict", lua_cc_fairygui_GTextInput_setRestrict);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GTextInput_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GTextInput).name();
	g_luaType[typeName] = "fgui.GTextInput";
	g_typeCast["GTextInput"] = "fgui.GTextInput";
	return 1;
}

int lua_cc_fairygui_GGraph_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGraph";
	constexpr auto LUA_FNAME = "fgui.GGraph:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GGraph::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GGraph_drawEllipse(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGraph";
	constexpr auto LUA_FNAME = "fgui.GGraph:drawEllipse";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGraph*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 5) {
		double arg0;
		double arg1;
		int arg2;
		cocos2d::Color4F arg3;
		cocos2d::Color4F arg4;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 4, &arg2, LUA_FNAME);
		ok &=luaval_to_color4f(tolua_S, 5, &arg3, LUA_FNAME);
		ok &=luaval_to_color4f(tolua_S, 6, &arg4, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->drawEllipse(arg0, arg1, arg2, arg3, arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "5");
}
int lua_cc_fairygui_GGraph_drawRect(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGraph";
	constexpr auto LUA_FNAME = "fgui.GGraph:drawRect";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGraph*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 5) {
		double arg0;
		double arg1;
		int arg2;
		cocos2d::Color4F arg3;
		cocos2d::Color4F arg4;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 4, &arg2, LUA_FNAME);
		ok &=luaval_to_color4f(tolua_S, 5, &arg3, LUA_FNAME);
		ok &=luaval_to_color4f(tolua_S, 6, &arg4, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->drawRect(arg0, arg1, arg2, arg3, arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "5");
}
int lua_cc_fairygui_GGraph_getColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGraph";
	constexpr auto LUA_FNAME = "fgui.GGraph:getColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGraph*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColor();
		color3b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GGraph_isEmpty(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGraph";
	constexpr auto LUA_FNAME = "fgui.GGraph:isEmpty";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGraph*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isEmpty();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GGraph_setColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGraph";
	constexpr auto LUA_FNAME = "fgui.GGraph:setColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGraph*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= luaval_to_color3b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GGraph_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGraph";
	constexpr auto LUA_FNAME = "fgui.GGraph constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GGraph();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GGraph_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GGraph(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GGraph");
	tolua_cclass(tolua_S, "GGraph", "fgui.GGraph", "fgui.GObject", nullptr);

	tolua_beginmodule(tolua_S, "GGraph");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GGraph_constructor);
		tolua_function(tolua_S, "drawEllipse", lua_cc_fairygui_GGraph_drawEllipse);
		tolua_function(tolua_S, "drawRect", lua_cc_fairygui_GGraph_drawRect);
		tolua_function(tolua_S, "getColor", lua_cc_fairygui_GGraph_getColor);
		tolua_function(tolua_S, "isEmpty", lua_cc_fairygui_GGraph_isEmpty);
		tolua_function(tolua_S, "setColor", lua_cc_fairygui_GGraph_setColor);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GGraph_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GGraph).name();
	g_luaType[typeName] = "fgui.GGraph";
	g_typeCast["GGraph"] = "fgui.GGraph";
	return 1;
}

int lua_cc_fairygui_GLoader_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GLoader::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_getAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:getAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getAlign();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_getAutoSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:getAutoSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getAutoSize();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_getColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:getColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColor();
		color3b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_getComponent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:getComponent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getComponent();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_getContentSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:getContentSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getContentSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_getFill(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:getFill";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFill();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_getFillAmount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:getFillAmount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFillAmount();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_getFillMethod(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:getFillMethod";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFillMethod();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_getFillOrigin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:getFillOrigin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFillOrigin();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_getFrame(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:getFrame";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFrame();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_getURL(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:getURL";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getURL();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_getVerticalAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:getVerticalAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getVerticalAlign();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_isFillClockwise(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:isFillClockwise";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isFillClockwise();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_isPlaying(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:isPlaying";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isPlaying();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_isShrinkOnly(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:isShrinkOnly";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isShrinkOnly();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader_setAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:setAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::TextHAlignment arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAlign(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader_setAutoSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:setAutoSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAutoSize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader_setColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:setColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= luaval_to_color3b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader_setFill(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:setFill";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::LoaderFillType arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFill(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader_setFillAmount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:setFillAmount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFillAmount(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader_setFillClockwise(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:setFillClockwise";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFillClockwise(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader_setFillMethod(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:setFillMethod";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::FillMethod arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFillMethod(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader_setFillOrigin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:setFillOrigin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::FillOrigin arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFillOrigin(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader_setFrame(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:setFrame";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFrame(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader_setPlaying(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:setPlaying";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPlaying(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader_setShrinkOnly(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:setShrinkOnly";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setShrinkOnly(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader_setURL(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:setURL";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setURL(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader_setVerticalAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader:setVerticalAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::TextVAlignment arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVerticalAlign(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader";
	constexpr auto LUA_FNAME = "fgui.GLoader constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GLoader();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GLoader_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GLoader(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GLoader");
	tolua_cclass(tolua_S, "GLoader", "fgui.GLoader", "fgui.GObject", nullptr);

	tolua_beginmodule(tolua_S, "GLoader");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GLoader_constructor);
		tolua_function(tolua_S, "getAlign", lua_cc_fairygui_GLoader_getAlign);
		tolua_function(tolua_S, "getAutoSize", lua_cc_fairygui_GLoader_getAutoSize);
		tolua_function(tolua_S, "getColor", lua_cc_fairygui_GLoader_getColor);
		tolua_function(tolua_S, "getComponent", lua_cc_fairygui_GLoader_getComponent);
		tolua_function(tolua_S, "getContentSize", lua_cc_fairygui_GLoader_getContentSize);
		tolua_function(tolua_S, "getFill", lua_cc_fairygui_GLoader_getFill);
		tolua_function(tolua_S, "getFillAmount", lua_cc_fairygui_GLoader_getFillAmount);
		tolua_function(tolua_S, "getFillMethod", lua_cc_fairygui_GLoader_getFillMethod);
		tolua_function(tolua_S, "getFillOrigin", lua_cc_fairygui_GLoader_getFillOrigin);
		tolua_function(tolua_S, "getFrame", lua_cc_fairygui_GLoader_getFrame);
		tolua_function(tolua_S, "getURL", lua_cc_fairygui_GLoader_getURL);
		tolua_function(tolua_S, "getVerticalAlign", lua_cc_fairygui_GLoader_getVerticalAlign);
		tolua_function(tolua_S, "isFillClockwise", lua_cc_fairygui_GLoader_isFillClockwise);
		tolua_function(tolua_S, "isPlaying", lua_cc_fairygui_GLoader_isPlaying);
		tolua_function(tolua_S, "isShrinkOnly", lua_cc_fairygui_GLoader_isShrinkOnly);
		tolua_function(tolua_S, "setAlign", lua_cc_fairygui_GLoader_setAlign);
		tolua_function(tolua_S, "setAutoSize", lua_cc_fairygui_GLoader_setAutoSize);
		tolua_function(tolua_S, "setColor", lua_cc_fairygui_GLoader_setColor);
		tolua_function(tolua_S, "setFill", lua_cc_fairygui_GLoader_setFill);
		tolua_function(tolua_S, "setFillAmount", lua_cc_fairygui_GLoader_setFillAmount);
		tolua_function(tolua_S, "setFillClockwise", lua_cc_fairygui_GLoader_setFillClockwise);
		tolua_function(tolua_S, "setFillMethod", lua_cc_fairygui_GLoader_setFillMethod);
		tolua_function(tolua_S, "setFillOrigin", lua_cc_fairygui_GLoader_setFillOrigin);
		tolua_function(tolua_S, "setFrame", lua_cc_fairygui_GLoader_setFrame);
		tolua_function(tolua_S, "setPlaying", lua_cc_fairygui_GLoader_setPlaying);
		tolua_function(tolua_S, "setShrinkOnly", lua_cc_fairygui_GLoader_setShrinkOnly);
		tolua_function(tolua_S, "setURL", lua_cc_fairygui_GLoader_setURL);
		tolua_function(tolua_S, "setVerticalAlign", lua_cc_fairygui_GLoader_setVerticalAlign);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GLoader_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GLoader).name();
	g_luaType[typeName] = "fgui.GLoader";
	g_typeCast["GLoader"] = "fgui.GLoader";
	return 1;
}

int lua_cc_fairygui_GGroup_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GGroup::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GGroup_getColumnGap(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:getColumnGap";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColumnGap();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GGroup_getLayout(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:getLayout";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getLayout();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GGroup_getLineGap(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:getLineGap";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getLineGap();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GGroup_getMainGridIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:getMainGridIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getMainGridIndex();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GGroup_getMainGridMinSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:getMainGridMinSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getMainGridMinSize();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GGroup_isAutoSizeDisabled(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:isAutoSizeDisabled";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isAutoSizeDisabled();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GGroup_isExcludeInvisibles(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:isExcludeInvisibles";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isExcludeInvisibles();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GGroup_moveChildren(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:moveChildren";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->moveChildren(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GGroup_resizeChildren(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:resizeChildren";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->resizeChildren(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GGroup_setAutoSizeDisabled(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:setAutoSizeDisabled";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAutoSizeDisabled(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GGroup_setBoundsChangedFlag(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:setBoundsChangedFlag";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setBoundsChangedFlag();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setBoundsChangedFlag(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 1");
}
int lua_cc_fairygui_GGroup_setColumnGap(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:setColumnGap";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setColumnGap(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GGroup_setExcludeInvisibles(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:setExcludeInvisibles";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setExcludeInvisibles(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GGroup_setLayout(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:setLayout";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GroupLayoutType arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setLayout(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GGroup_setLineGap(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:setLineGap";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setLineGap(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GGroup_setMainGridIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:setMainGridIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setMainGridIndex(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GGroup_setMainGridMinSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup:setMainGridMinSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setMainGridMinSize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GGroup_get_updating(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup._updating getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->_updating);
	return 1;
}
int lua_cc_fairygui_GGroup_set_updating(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup._updating setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GGroup*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->_updating, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GGroup_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GGroup";
	constexpr auto LUA_FNAME = "fgui.GGroup constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GGroup();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GGroup_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GGroup(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GGroup");
	tolua_cclass(tolua_S, "GGroup", "fgui.GGroup", "fgui.GObject", nullptr);

	tolua_beginmodule(tolua_S, "GGroup");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GGroup_constructor);
		tolua_function(tolua_S, "getColumnGap", lua_cc_fairygui_GGroup_getColumnGap);
		tolua_function(tolua_S, "getLayout", lua_cc_fairygui_GGroup_getLayout);
		tolua_function(tolua_S, "getLineGap", lua_cc_fairygui_GGroup_getLineGap);
		tolua_function(tolua_S, "getMainGridIndex", lua_cc_fairygui_GGroup_getMainGridIndex);
		tolua_function(tolua_S, "getMainGridMinSize", lua_cc_fairygui_GGroup_getMainGridMinSize);
		tolua_function(tolua_S, "isAutoSizeDisabled", lua_cc_fairygui_GGroup_isAutoSizeDisabled);
		tolua_function(tolua_S, "isExcludeInvisibles", lua_cc_fairygui_GGroup_isExcludeInvisibles);
		tolua_function(tolua_S, "moveChildren", lua_cc_fairygui_GGroup_moveChildren);
		tolua_function(tolua_S, "resizeChildren", lua_cc_fairygui_GGroup_resizeChildren);
		tolua_function(tolua_S, "setAutoSizeDisabled", lua_cc_fairygui_GGroup_setAutoSizeDisabled);
		tolua_function(tolua_S, "setBoundsChangedFlag", lua_cc_fairygui_GGroup_setBoundsChangedFlag);
		tolua_function(tolua_S, "setColumnGap", lua_cc_fairygui_GGroup_setColumnGap);
		tolua_function(tolua_S, "setExcludeInvisibles", lua_cc_fairygui_GGroup_setExcludeInvisibles);
		tolua_function(tolua_S, "setLayout", lua_cc_fairygui_GGroup_setLayout);
		tolua_function(tolua_S, "setLineGap", lua_cc_fairygui_GGroup_setLineGap);
		tolua_function(tolua_S, "setMainGridIndex", lua_cc_fairygui_GGroup_setMainGridIndex);
		tolua_function(tolua_S, "setMainGridMinSize", lua_cc_fairygui_GGroup_setMainGridMinSize);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GGroup_create);
		tolua_variable(tolua_S, "_updating", lua_cc_fairygui_GGroup_get_updating, lua_cc_fairygui_GGroup_set_updating);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GGroup).name();
	g_luaType[typeName] = "fgui.GGroup";
	g_typeCast["GGroup"] = "fgui.GGroup";
	return 1;
}

int lua_cc_fairygui_ScrollPane_cancelDragging(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:cancelDragging";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->cancelDragging();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getContentSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getContentSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getContentSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getDecelerationRate(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getDecelerationRate";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getDecelerationRate();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getDraggingPane(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getDraggingPane";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::ScrollPane::getDraggingPane();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getFooter(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getFooter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFooter();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getHeader(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getHeader";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getHeader();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getHzScrollBar(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getHzScrollBar";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getHzScrollBar();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getOwner(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getOwner";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getOwner();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getPageController(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getPageController";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPageController();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getPageX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getPageX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPageX();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getPageY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getPageY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPageY();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getPercX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getPercX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPercX();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getPercY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getPercY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPercY();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getPosX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getPosX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPosX();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getPosY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getPosY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPosY();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getScrollStep(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getScrollStep";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getScrollStep();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getScrollingPosX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getScrollingPosX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getScrollingPosX();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getScrollingPosY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getScrollingPosY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getScrollingPosY();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getViewSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getViewSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getViewSize();
		size_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_getVtScrollBar(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:getVtScrollBar";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getVtScrollBar();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_isBottomMost(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:isBottomMost";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isBottomMost();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_isBouncebackEffect(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:isBouncebackEffect";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isBouncebackEffect();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_isChildInView(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:isChildInView";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isChildInView(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_isInertiaDisabled(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:isInertiaDisabled";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isInertiaDisabled();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_isMouseWheelEnabled(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:isMouseWheelEnabled";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isMouseWheelEnabled();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_isPageMode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:isPageMode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isPageMode();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_isRightMost(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:isRightMost";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isRightMost();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_isSnapToItem(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:isSnapToItem";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isSnapToItem();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_isTouchEffect(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:isTouchEffect";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isTouchEffect();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_ScrollPane_lockFooter(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:lockFooter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->lockFooter(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_lockHeader(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:lockHeader";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->lockHeader(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_scrollBottom(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:scrollBottom";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollBottom();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollBottom(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 1");
}
int lua_cc_fairygui_ScrollPane_scrollDown(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:scrollDown";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollDown();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollDown(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		double arg0;
		bool arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollDown(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 2");
}
int lua_cc_fairygui_ScrollPane_scrollLeft(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:scrollLeft";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollLeft();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollLeft(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		double arg0;
		bool arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollLeft(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 2");
}
int lua_cc_fairygui_ScrollPane_scrollRight(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:scrollRight";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollRight();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollRight(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		double arg0;
		bool arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollRight(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 2");
}
int lua_cc_fairygui_ScrollPane_scrollToView(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:scrollToView";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 1) {
			cocos2d::Rect arg0;
			ok &= luaval_to_rect(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cobj->scrollToView(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 2) {
			cocos2d::Rect arg0;
			ok &= luaval_to_rect(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			bool arg1;
			ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->scrollToView(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 3) {
			cocos2d::Rect arg0;
			ok &= luaval_to_rect(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			bool arg1;
			ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			bool arg2;
			ok &= luaval_to_boolean(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			cobj->scrollToView(arg0, arg1, arg2);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			fairygui::GObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cobj->scrollToView(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 2) {
			fairygui::GObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			bool arg1;
			ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->scrollToView(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 3) {
			fairygui::GObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			bool arg1;
			ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			bool arg2;
			ok &= luaval_to_boolean(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			cobj->scrollToView(arg0, arg1, arg2);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_scrollTop(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:scrollTop";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollTop();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollTop(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 1");
}
int lua_cc_fairygui_ScrollPane_scrollUp(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:scrollUp";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollUp();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollUp(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		double arg0;
		bool arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollUp(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 2");
}
int lua_cc_fairygui_ScrollPane_setBouncebackEffect(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setBouncebackEffect";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setBouncebackEffect(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_setDecelerationRate(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setDecelerationRate";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setDecelerationRate(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_setInertiaDisabled(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setInertiaDisabled";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setInertiaDisabled(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_setMouseWheelEnabled(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setMouseWheelEnabled";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setMouseWheelEnabled(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_setPageController(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setPageController";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GController* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPageController(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_setPageMode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setPageMode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPageMode(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_setPageX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setPageX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPageX(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		int arg0;
		bool arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPageX(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_ScrollPane_setPageY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setPageY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPageY(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		int arg0;
		bool arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPageY(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_ScrollPane_setPercX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setPercX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPercX(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		double arg0;
		bool arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPercX(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_ScrollPane_setPercY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setPercY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPercY(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		double arg0;
		bool arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPercY(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_ScrollPane_setPosX(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setPosX";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPosX(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		double arg0;
		bool arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPosX(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_ScrollPane_setPosY(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setPosY";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPosY(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		double arg0;
		bool arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPosY(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_ScrollPane_setScrollStep(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setScrollStep";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setScrollStep(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_setSnapToItem(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setSnapToItem";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSnapToItem(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_setTouchEffect(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setTouchEffect";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTouchEffect(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_setup(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane:setup";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::ScrollPane*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::ByteBuffer* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setup(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_ScrollPane_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.ScrollPane";
	constexpr auto LUA_FNAME = "fgui.ScrollPane constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GComponent* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::ScrollPane(arg0);
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}

static int lua_cc_fairygui_ScrollPane_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_ScrollPane(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.ScrollPane");
	tolua_cclass(tolua_S, "ScrollPane", "fgui.ScrollPane", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "ScrollPane");
		tolua_function(tolua_S, "new", lua_cc_fairygui_ScrollPane_constructor);
		tolua_function(tolua_S, "cancelDragging", lua_cc_fairygui_ScrollPane_cancelDragging);
		tolua_function(tolua_S, "getContentSize", lua_cc_fairygui_ScrollPane_getContentSize);
		tolua_function(tolua_S, "getDecelerationRate", lua_cc_fairygui_ScrollPane_getDecelerationRate);
		tolua_function(tolua_S, "getFooter", lua_cc_fairygui_ScrollPane_getFooter);
		tolua_function(tolua_S, "getHeader", lua_cc_fairygui_ScrollPane_getHeader);
		tolua_function(tolua_S, "getHzScrollBar", lua_cc_fairygui_ScrollPane_getHzScrollBar);
		tolua_function(tolua_S, "getOwner", lua_cc_fairygui_ScrollPane_getOwner);
		tolua_function(tolua_S, "getPageController", lua_cc_fairygui_ScrollPane_getPageController);
		tolua_function(tolua_S, "getPageX", lua_cc_fairygui_ScrollPane_getPageX);
		tolua_function(tolua_S, "getPageY", lua_cc_fairygui_ScrollPane_getPageY);
		tolua_function(tolua_S, "getPercX", lua_cc_fairygui_ScrollPane_getPercX);
		tolua_function(tolua_S, "getPercY", lua_cc_fairygui_ScrollPane_getPercY);
		tolua_function(tolua_S, "getPosX", lua_cc_fairygui_ScrollPane_getPosX);
		tolua_function(tolua_S, "getPosY", lua_cc_fairygui_ScrollPane_getPosY);
		tolua_function(tolua_S, "getScrollStep", lua_cc_fairygui_ScrollPane_getScrollStep);
		tolua_function(tolua_S, "getScrollingPosX", lua_cc_fairygui_ScrollPane_getScrollingPosX);
		tolua_function(tolua_S, "getScrollingPosY", lua_cc_fairygui_ScrollPane_getScrollingPosY);
		tolua_function(tolua_S, "getViewSize", lua_cc_fairygui_ScrollPane_getViewSize);
		tolua_function(tolua_S, "getVtScrollBar", lua_cc_fairygui_ScrollPane_getVtScrollBar);
		tolua_function(tolua_S, "isBottomMost", lua_cc_fairygui_ScrollPane_isBottomMost);
		tolua_function(tolua_S, "isBouncebackEffect", lua_cc_fairygui_ScrollPane_isBouncebackEffect);
		tolua_function(tolua_S, "isChildInView", lua_cc_fairygui_ScrollPane_isChildInView);
		tolua_function(tolua_S, "isInertiaDisabled", lua_cc_fairygui_ScrollPane_isInertiaDisabled);
		tolua_function(tolua_S, "isMouseWheelEnabled", lua_cc_fairygui_ScrollPane_isMouseWheelEnabled);
		tolua_function(tolua_S, "isPageMode", lua_cc_fairygui_ScrollPane_isPageMode);
		tolua_function(tolua_S, "isRightMost", lua_cc_fairygui_ScrollPane_isRightMost);
		tolua_function(tolua_S, "isSnapToItem", lua_cc_fairygui_ScrollPane_isSnapToItem);
		tolua_function(tolua_S, "isTouchEffect", lua_cc_fairygui_ScrollPane_isTouchEffect);
		tolua_function(tolua_S, "lockFooter", lua_cc_fairygui_ScrollPane_lockFooter);
		tolua_function(tolua_S, "lockHeader", lua_cc_fairygui_ScrollPane_lockHeader);
		tolua_function(tolua_S, "scrollBottom", lua_cc_fairygui_ScrollPane_scrollBottom);
		tolua_function(tolua_S, "scrollDown", lua_cc_fairygui_ScrollPane_scrollDown);
		tolua_function(tolua_S, "scrollLeft", lua_cc_fairygui_ScrollPane_scrollLeft);
		tolua_function(tolua_S, "scrollRight", lua_cc_fairygui_ScrollPane_scrollRight);
		tolua_function(tolua_S, "scrollToView", lua_cc_fairygui_ScrollPane_scrollToView);
		tolua_function(tolua_S, "scrollTop", lua_cc_fairygui_ScrollPane_scrollTop);
		tolua_function(tolua_S, "scrollUp", lua_cc_fairygui_ScrollPane_scrollUp);
		tolua_function(tolua_S, "setBouncebackEffect", lua_cc_fairygui_ScrollPane_setBouncebackEffect);
		tolua_function(tolua_S, "setDecelerationRate", lua_cc_fairygui_ScrollPane_setDecelerationRate);
		tolua_function(tolua_S, "setInertiaDisabled", lua_cc_fairygui_ScrollPane_setInertiaDisabled);
		tolua_function(tolua_S, "setMouseWheelEnabled", lua_cc_fairygui_ScrollPane_setMouseWheelEnabled);
		tolua_function(tolua_S, "setPageController", lua_cc_fairygui_ScrollPane_setPageController);
		tolua_function(tolua_S, "setPageMode", lua_cc_fairygui_ScrollPane_setPageMode);
		tolua_function(tolua_S, "setPageX", lua_cc_fairygui_ScrollPane_setPageX);
		tolua_function(tolua_S, "setPageY", lua_cc_fairygui_ScrollPane_setPageY);
		tolua_function(tolua_S, "setPercX", lua_cc_fairygui_ScrollPane_setPercX);
		tolua_function(tolua_S, "setPercY", lua_cc_fairygui_ScrollPane_setPercY);
		tolua_function(tolua_S, "setPosX", lua_cc_fairygui_ScrollPane_setPosX);
		tolua_function(tolua_S, "setPosY", lua_cc_fairygui_ScrollPane_setPosY);
		tolua_function(tolua_S, "setScrollStep", lua_cc_fairygui_ScrollPane_setScrollStep);
		tolua_function(tolua_S, "setSnapToItem", lua_cc_fairygui_ScrollPane_setSnapToItem);
		tolua_function(tolua_S, "setTouchEffect", lua_cc_fairygui_ScrollPane_setTouchEffect);
		tolua_function(tolua_S, "setup", lua_cc_fairygui_ScrollPane_setup);
		tolua_function(tolua_S, "getDraggingPane", lua_cc_fairygui_ScrollPane_getDraggingPane);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::ScrollPane).name();
	g_luaType[typeName] = "fgui.ScrollPane";
	g_typeCast["ScrollPane"] = "fgui.ScrollPane";
	return 1;
}

int lua_cc_fairygui_Transition_changePlayTimes(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:changePlayTimes";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->changePlayTimes(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Transition_clearHooks(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:clearHooks";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->clearHooks();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Transition_getLabelTime(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:getLabelTime";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getLabelTime(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Transition_getOwner(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:getOwner";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getOwner();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Transition_getTimeScale(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:getTimeScale";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTimeScale();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Transition_isPlaying(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:isPlaying";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isPlaying();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Transition_onOwnerAddedToStage(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:onOwnerAddedToStage";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->onOwnerAddedToStage();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Transition_onOwnerRemovedFromStage(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:onOwnerRemovedFromStage";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->onOwnerRemovedFromStage();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Transition_play(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:play";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->play(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 3) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			std::function<void ()> arg2;
			ok &= luaval_to_native(tolua_S, 4, &arg2, LUA_FNAME);
			int handler4 = query_luafunction_handler(tolua_S, 4, LUA_FNAME);
			ok &= handler4 != 0;
			if (!ok) { break; }
			cobj->play(arg0, arg1, arg2);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			cobj->play();
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			std::function<void ()> arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			int handler2 = query_luafunction_handler(tolua_S, 2, LUA_FNAME);
			ok &= handler2 != 0;
			if (!ok) { break; }
			cobj->play(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 4) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			double arg2;
			ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			double arg3;
			ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
			if (!ok) { break; }
			cobj->play(arg0, arg1, arg2, arg3);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 5) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			double arg2;
			ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			double arg3;
			ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
			if (!ok) { break; }
			std::function<void ()> arg4;
			ok &= luaval_to_native(tolua_S, 6, &arg4, LUA_FNAME);
			int handler6 = query_luafunction_handler(tolua_S, 6, LUA_FNAME);
			ok &= handler6 != 0;
			if (!ok) { break; }
			cobj->play(arg0, arg1, arg2, arg3, arg4);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "4");
}
int lua_cc_fairygui_Transition_playReverse(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:playReverse";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->playReverse(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 3) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			std::function<void ()> arg2;
			ok &= luaval_to_native(tolua_S, 4, &arg2, LUA_FNAME);
			int handler4 = query_luafunction_handler(tolua_S, 4, LUA_FNAME);
			ok &= handler4 != 0;
			if (!ok) { break; }
			cobj->playReverse(arg0, arg1, arg2);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			cobj->playReverse();
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			std::function<void ()> arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			int handler2 = query_luafunction_handler(tolua_S, 2, LUA_FNAME);
			ok &= handler2 != 0;
			if (!ok) { break; }
			cobj->playReverse(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Transition_setAutoPlay(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:setAutoPlay";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		bool arg0;
		int arg1;
		double arg2;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAutoPlay(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_cc_fairygui_Transition_setDuration(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:setDuration";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		double arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setDuration(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_Transition_setHook(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:setHook";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::function<void ()> arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		int handler3 = query_luafunction_handler(tolua_S, 3, LUA_FNAME);
		ok &= handler3 != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setHook(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_Transition_setPaused(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:setPaused";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPaused(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Transition_setTarget(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:setTarget";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		fairygui::GObject* arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTarget(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_Transition_setTimeScale(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:setTimeScale";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTimeScale(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Transition_setValue(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:setValue";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		cocos2d::ValueVector arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_ccvaluevector(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setValue(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_Transition_setup(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:setup";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::ByteBuffer* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setup(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Transition_stop(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:stop";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			bool arg0;
			ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			bool arg1;
			ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->stop(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			cobj->stop();
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Transition_updateFromRelations(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition:updateFromRelations";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		std::string arg0;
		double arg1;
		double arg2;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->updateFromRelations(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_cc_fairygui_Transition_getname(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition.name getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->name);
	return 1;
}
int lua_cc_fairygui_Transition_setname(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition.name setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Transition*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->name, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Transition_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Transition";
	constexpr auto LUA_FNAME = "fgui.Transition constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GComponent* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::Transition(arg0);
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}

static int lua_cc_fairygui_Transition_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_Transition(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.Transition");
	tolua_cclass(tolua_S, "Transition", "fgui.Transition", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "Transition");
		tolua_function(tolua_S, "new", lua_cc_fairygui_Transition_constructor);
		tolua_function(tolua_S, "changePlayTimes", lua_cc_fairygui_Transition_changePlayTimes);
		tolua_function(tolua_S, "clearHooks", lua_cc_fairygui_Transition_clearHooks);
		tolua_function(tolua_S, "getLabelTime", lua_cc_fairygui_Transition_getLabelTime);
		tolua_function(tolua_S, "getOwner", lua_cc_fairygui_Transition_getOwner);
		tolua_function(tolua_S, "getTimeScale", lua_cc_fairygui_Transition_getTimeScale);
		tolua_function(tolua_S, "isPlaying", lua_cc_fairygui_Transition_isPlaying);
		tolua_function(tolua_S, "onOwnerAddedToStage", lua_cc_fairygui_Transition_onOwnerAddedToStage);
		tolua_function(tolua_S, "onOwnerRemovedFromStage", lua_cc_fairygui_Transition_onOwnerRemovedFromStage);
		tolua_function(tolua_S, "play", lua_cc_fairygui_Transition_play);
		tolua_function(tolua_S, "playReverse", lua_cc_fairygui_Transition_playReverse);
		tolua_function(tolua_S, "setAutoPlay", lua_cc_fairygui_Transition_setAutoPlay);
		tolua_function(tolua_S, "setDuration", lua_cc_fairygui_Transition_setDuration);
		tolua_function(tolua_S, "setHook", lua_cc_fairygui_Transition_setHook);
		tolua_function(tolua_S, "setPaused", lua_cc_fairygui_Transition_setPaused);
		tolua_function(tolua_S, "setTarget", lua_cc_fairygui_Transition_setTarget);
		tolua_function(tolua_S, "setTimeScale", lua_cc_fairygui_Transition_setTimeScale);
		tolua_function(tolua_S, "setValue", lua_cc_fairygui_Transition_setValue);
		tolua_function(tolua_S, "setup", lua_cc_fairygui_Transition_setup);
		tolua_function(tolua_S, "stop", lua_cc_fairygui_Transition_stop);
		tolua_function(tolua_S, "updateFromRelations", lua_cc_fairygui_Transition_updateFromRelations);
		tolua_variable(tolua_S, "name", lua_cc_fairygui_Transition_getname, lua_cc_fairygui_Transition_setname);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::Transition).name();
	g_luaType[typeName] = "fgui.Transition";
	g_typeCast["Transition"] = "fgui.Transition";
	return 1;
}

int lua_cc_fairygui_FUIContainer_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::FUIContainer::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIContainer_getAlphaThreshold(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer:getAlphaThreshold";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIContainer*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getAlphaThreshold();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIContainer_getClippingRegion(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer:getClippingRegion";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIContainer*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getClippingRegion();
		rect_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIContainer_getStencil(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer:getStencil";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIContainer*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getStencil();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIContainer_isClippingEnabled(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer:isClippingEnabled";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIContainer*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isClippingEnabled();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIContainer_isInverted(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer:isInverted";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIContainer*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isInverted();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUIContainer_setAlphaThreshold(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer:setAlphaThreshold";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIContainer*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAlphaThreshold(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIContainer_setClippingEnabled(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer:setClippingEnabled";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIContainer*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setClippingEnabled(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIContainer_setClippingRegion(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer:setClippingRegion";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIContainer*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Rect arg0;
		ok &= luaval_to_rect(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setClippingRegion(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIContainer_setInverted(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer:setInverted";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIContainer*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setInverted(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIContainer_setStencil(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer:setStencil";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIContainer*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Node* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setStencil(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIContainer_getgOwner(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer.gOwner getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIContainer*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->gOwner);
	return 1;
}
int lua_cc_fairygui_FUIContainer_setgOwner(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer.gOwner setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUIContainer*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->gOwner, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUIContainer_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUIContainer";
	constexpr auto LUA_FNAME = "fgui.FUIContainer constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::FUIContainer();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_FUIContainer_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_FUIContainer(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.FUIContainer");
	tolua_cclass(tolua_S, "FUIContainer", "fgui.FUIContainer", "cc.Node", nullptr);

	tolua_beginmodule(tolua_S, "FUIContainer");
		tolua_function(tolua_S, "new", lua_cc_fairygui_FUIContainer_constructor);
		tolua_function(tolua_S, "getAlphaThreshold", lua_cc_fairygui_FUIContainer_getAlphaThreshold);
		tolua_function(tolua_S, "getClippingRegion", lua_cc_fairygui_FUIContainer_getClippingRegion);
		tolua_function(tolua_S, "getStencil", lua_cc_fairygui_FUIContainer_getStencil);
		tolua_function(tolua_S, "isClippingEnabled", lua_cc_fairygui_FUIContainer_isClippingEnabled);
		tolua_function(tolua_S, "isInverted", lua_cc_fairygui_FUIContainer_isInverted);
		tolua_function(tolua_S, "setAlphaThreshold", lua_cc_fairygui_FUIContainer_setAlphaThreshold);
		tolua_function(tolua_S, "setClippingEnabled", lua_cc_fairygui_FUIContainer_setClippingEnabled);
		tolua_function(tolua_S, "setClippingRegion", lua_cc_fairygui_FUIContainer_setClippingRegion);
		tolua_function(tolua_S, "setInverted", lua_cc_fairygui_FUIContainer_setInverted);
		tolua_function(tolua_S, "setStencil", lua_cc_fairygui_FUIContainer_setStencil);
		tolua_function(tolua_S, "create", lua_cc_fairygui_FUIContainer_create);
		tolua_variable(tolua_S, "gOwner", lua_cc_fairygui_FUIContainer_getgOwner, lua_cc_fairygui_FUIContainer_setgOwner);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::FUIContainer).name();
	g_luaType[typeName] = "fgui.FUIContainer";
	g_typeCast["FUIContainer"] = "fgui.FUIContainer";
	return 1;
}

int lua_cc_fairygui_IHitTest_hitTest(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.IHitTest";
	constexpr auto LUA_FNAME = "fgui.IHitTest:hitTest";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::IHitTest*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GComponent* arg0;
		cocos2d::Vec2 arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_vec2(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->hitTest(arg0, arg1);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
static int lua_cc_fairygui_IHitTest_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_IHitTest(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.IHitTest");
	tolua_cclass(tolua_S, "IHitTest", "fgui.IHitTest", "", nullptr);

	tolua_beginmodule(tolua_S, "IHitTest");
		tolua_function(tolua_S, "hitTest", lua_cc_fairygui_IHitTest_hitTest);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::IHitTest).name();
	g_luaType[typeName] = "fgui.IHitTest";
	g_typeCast["IHitTest"] = "fgui.IHitTest";
	return 1;
}

int lua_cc_fairygui_PixelHitTestData_load(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTestData";
	constexpr auto LUA_FNAME = "fgui.PixelHitTestData:load";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTestData*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::ByteBuffer* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->load(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PixelHitTestData_getpixelWidth(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTestData";
	constexpr auto LUA_FNAME = "fgui.PixelHitTestData.pixelWidth getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTestData*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->pixelWidth);
	return 1;
}
int lua_cc_fairygui_PixelHitTestData_setpixelWidth(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTestData";
	constexpr auto LUA_FNAME = "fgui.PixelHitTestData.pixelWidth setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTestData*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->pixelWidth, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PixelHitTestData_getscale(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTestData";
	constexpr auto LUA_FNAME = "fgui.PixelHitTestData.scale getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTestData*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->scale);
	return 1;
}
int lua_cc_fairygui_PixelHitTestData_setscale(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTestData";
	constexpr auto LUA_FNAME = "fgui.PixelHitTestData.scale setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTestData*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->scale, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PixelHitTestData_getpixels(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTestData";
	constexpr auto LUA_FNAME = "fgui.PixelHitTestData.pixels getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTestData*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->pixels);
	return 1;
}
int lua_cc_fairygui_PixelHitTestData_setpixels(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTestData";
	constexpr auto LUA_FNAME = "fgui.PixelHitTestData.pixels setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTestData*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->pixels, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PixelHitTestData_getpixelsLength(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTestData";
	constexpr auto LUA_FNAME = "fgui.PixelHitTestData.pixelsLength getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTestData*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->pixelsLength);
	return 1;
}
int lua_cc_fairygui_PixelHitTestData_setpixelsLength(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTestData";
	constexpr auto LUA_FNAME = "fgui.PixelHitTestData.pixelsLength setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTestData*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->pixelsLength, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PixelHitTestData_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTestData";
	constexpr auto LUA_FNAME = "fgui.PixelHitTestData constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::PixelHitTestData();
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_PixelHitTestData_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_PixelHitTestData(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.PixelHitTestData");
	tolua_cclass(tolua_S, "PixelHitTestData", "fgui.PixelHitTestData", "", nullptr);

	tolua_beginmodule(tolua_S, "PixelHitTestData");
		tolua_function(tolua_S, "new", lua_cc_fairygui_PixelHitTestData_constructor);
		tolua_function(tolua_S, "load", lua_cc_fairygui_PixelHitTestData_load);
		tolua_variable(tolua_S, "pixelWidth", lua_cc_fairygui_PixelHitTestData_getpixelWidth, lua_cc_fairygui_PixelHitTestData_setpixelWidth);
		tolua_variable(tolua_S, "scale", lua_cc_fairygui_PixelHitTestData_getscale, lua_cc_fairygui_PixelHitTestData_setscale);
		tolua_variable(tolua_S, "pixels", lua_cc_fairygui_PixelHitTestData_getpixels, lua_cc_fairygui_PixelHitTestData_setpixels);
		tolua_variable(tolua_S, "pixelsLength", lua_cc_fairygui_PixelHitTestData_getpixelsLength, lua_cc_fairygui_PixelHitTestData_setpixelsLength);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::PixelHitTestData).name();
	g_luaType[typeName] = "fgui.PixelHitTestData";
	g_typeCast["PixelHitTestData"] = "fgui.PixelHitTestData";
	return 1;
}

int lua_cc_fairygui_PixelHitTest_getoffsetX(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTest";
	constexpr auto LUA_FNAME = "fgui.PixelHitTest.offsetX getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTest*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->offsetX);
	return 1;
}
int lua_cc_fairygui_PixelHitTest_setoffsetX(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTest";
	constexpr auto LUA_FNAME = "fgui.PixelHitTest.offsetX setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTest*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->offsetX, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PixelHitTest_getoffsetY(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTest";
	constexpr auto LUA_FNAME = "fgui.PixelHitTest.offsetY getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTest*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->offsetY);
	return 1;
}
int lua_cc_fairygui_PixelHitTest_setoffsetY(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTest";
	constexpr auto LUA_FNAME = "fgui.PixelHitTest.offsetY setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTest*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->offsetY, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PixelHitTest_getscaleX(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTest";
	constexpr auto LUA_FNAME = "fgui.PixelHitTest.scaleX getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTest*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->scaleX);
	return 1;
}
int lua_cc_fairygui_PixelHitTest_setscaleX(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTest";
	constexpr auto LUA_FNAME = "fgui.PixelHitTest.scaleX setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTest*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->scaleX, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PixelHitTest_getscaleY(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTest";
	constexpr auto LUA_FNAME = "fgui.PixelHitTest.scaleY getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTest*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->scaleY);
	return 1;
}
int lua_cc_fairygui_PixelHitTest_setscaleY(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTest";
	constexpr auto LUA_FNAME = "fgui.PixelHitTest.scaleY setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PixelHitTest*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->scaleY, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PixelHitTest_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PixelHitTest";
	constexpr auto LUA_FNAME = "fgui.PixelHitTest constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		fairygui::PixelHitTestData* arg0;
		int arg1;
		int arg2;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::PixelHitTest(arg0, arg1, arg2);
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}

static int lua_cc_fairygui_PixelHitTest_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_PixelHitTest(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.PixelHitTest");
	tolua_cclass(tolua_S, "PixelHitTest", "fgui.PixelHitTest", "fgui.IHitTest", nullptr);

	tolua_beginmodule(tolua_S, "PixelHitTest");
		tolua_function(tolua_S, "new", lua_cc_fairygui_PixelHitTest_constructor);
		tolua_variable(tolua_S, "offsetX", lua_cc_fairygui_PixelHitTest_getoffsetX, lua_cc_fairygui_PixelHitTest_setoffsetX);
		tolua_variable(tolua_S, "offsetY", lua_cc_fairygui_PixelHitTest_getoffsetY, lua_cc_fairygui_PixelHitTest_setoffsetY);
		tolua_variable(tolua_S, "scaleX", lua_cc_fairygui_PixelHitTest_getscaleX, lua_cc_fairygui_PixelHitTest_setscaleX);
		tolua_variable(tolua_S, "scaleY", lua_cc_fairygui_PixelHitTest_getscaleY, lua_cc_fairygui_PixelHitTest_setscaleY);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::PixelHitTest).name();
	g_luaType[typeName] = "fgui.PixelHitTest";
	g_typeCast["PixelHitTest"] = "fgui.PixelHitTest";
	return 1;
}

int lua_cc_fairygui_GComponent_addChild(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:addChild";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->addChild(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_addChildAt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:addChildAt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GObject* arg0;
		int arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->addChildAt(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GComponent_addController(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:addController";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GController* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->addController(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_adjustRadioGroupDepth(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:adjustRadioGroupDepth";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GObject* arg0;
		fairygui::GController* arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->adjustRadioGroupDepth(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GComponent_applyAllControllers(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:applyAllControllers";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->applyAllControllers();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_applyController(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:applyController";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GController* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->applyController(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_childSortingOrderChanged(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:childSortingOrderChanged";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		fairygui::GObject* arg0;
		int arg1;
		int arg2;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->childSortingOrderChanged(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_cc_fairygui_GComponent_childStateChanged(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:childStateChanged";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->childStateChanged(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_constructFromResource(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:constructFromResource";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::vector<fairygui::GObject *>* arg0;
		int arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->constructFromResource(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GComponent_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GComponent::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_ensureBoundsCorrect(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:ensureBoundsCorrect";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->ensureBoundsCorrect();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_getApexIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getApexIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getApexIndex();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_getChild(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getChild";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getChild(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_getChildAt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getChildAt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getChildAt(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_getChildById(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getChildById";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getChildById(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_getChildInGroup(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getChildInGroup";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		const fairygui::GGroup* arg0;
		std::string arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getChildInGroup(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GComponent_getChildIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getChildIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		const fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getChildIndex(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_getChildren(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getChildren";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getChildren();
		ccvector_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_getChildrenRenderOrder(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getChildrenRenderOrder";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getChildrenRenderOrder();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_getController(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getController";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getController(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_getControllerAt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getControllerAt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getControllerAt(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_getControllers(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getControllers";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getControllers();
		ccvector_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_getFirstChildInView(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getFirstChildInView";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFirstChildInView();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_getHitArea(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getHitArea";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getHitArea();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_getMargin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getMargin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getMargin();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_getMask(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getMask";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getMask();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_getOpaque(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getOpaque";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getOpaque();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_getScrollPane(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getScrollPane";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getScrollPane();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_getSnappingPosition(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getSnappingPosition";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSnappingPosition(arg0);
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_getTransition(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getTransition";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTransition(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_getTransitionAt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getTransitionAt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTransitionAt(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_getTransitions(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getTransitions";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTransitions();
		ccvector_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_getViewHeight(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getViewHeight";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getViewHeight();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_getViewWidth(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:getViewWidth";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getViewWidth();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_isAncestorOf(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:isAncestorOf";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		const fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isAncestorOf(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_isChildInView(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:isChildInView";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isChildInView(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_numChildren(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:numChildren";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->numChildren();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_removeChild(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:removeChild";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->removeChild(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_removeChildAt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:removeChildAt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->removeChildAt(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_removeChildren(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:removeChildren";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			int arg1;
			ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->removeChildren(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			cobj->removeChildren();
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_removeController(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:removeController";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GController* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->removeController(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_setApexIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:setApexIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setApexIndex(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_setBoundsChangedFlag(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:setBoundsChangedFlag";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setBoundsChangedFlag();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComponent_setChildIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:setChildIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GObject* arg0;
		int arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setChildIndex(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GComponent_setChildIndexBefore(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:setChildIndexBefore";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GObject* arg0;
		int arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setChildIndexBefore(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GComponent_setChildrenRenderOrder(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:setChildrenRenderOrder";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::ChildrenRenderOrder arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setChildrenRenderOrder(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_setHitArea(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:setHitArea";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::IHitTest* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setHitArea(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_setMargin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:setMargin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::Margin arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setMargin(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_setMask(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:setMask";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Node* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setMask(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		cocos2d::Node* arg0;
		bool arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setMask(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_GComponent_setOpaque(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:setOpaque";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setOpaque(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_setViewHeight(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:setViewHeight";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setViewHeight(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_setViewWidth(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:setViewWidth";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setViewWidth(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_swapChildren(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:swapChildren";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GObject* arg0;
		fairygui::GObject* arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->swapChildren(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GComponent_swapChildrenAt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent:swapChildrenAt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		int arg0;
		int arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->swapChildrenAt(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GComponent_get_buildingDisplayList(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent._buildingDisplayList getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->_buildingDisplayList);
	return 1;
}
int lua_cc_fairygui_GComponent_set_buildingDisplayList(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent._buildingDisplayList setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComponent*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->_buildingDisplayList, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComponent_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComponent";
	constexpr auto LUA_FNAME = "fgui.GComponent constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GComponent();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GComponent_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GComponent(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GComponent");
	tolua_cclass(tolua_S, "GComponent", "fgui.GComponent", "fgui.GObject", nullptr);

	tolua_beginmodule(tolua_S, "GComponent");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GComponent_constructor);
		tolua_function(tolua_S, "addChild", lua_cc_fairygui_GComponent_addChild);
		tolua_function(tolua_S, "addChildAt", lua_cc_fairygui_GComponent_addChildAt);
		tolua_function(tolua_S, "addController", lua_cc_fairygui_GComponent_addController);
		tolua_function(tolua_S, "adjustRadioGroupDepth", lua_cc_fairygui_GComponent_adjustRadioGroupDepth);
		tolua_function(tolua_S, "applyAllControllers", lua_cc_fairygui_GComponent_applyAllControllers);
		tolua_function(tolua_S, "applyController", lua_cc_fairygui_GComponent_applyController);
		tolua_function(tolua_S, "childSortingOrderChanged", lua_cc_fairygui_GComponent_childSortingOrderChanged);
		tolua_function(tolua_S, "childStateChanged", lua_cc_fairygui_GComponent_childStateChanged);
		tolua_function(tolua_S, "constructFromResource", lua_cc_fairygui_GComponent_constructFromResource);
		tolua_function(tolua_S, "ensureBoundsCorrect", lua_cc_fairygui_GComponent_ensureBoundsCorrect);
		tolua_function(tolua_S, "getApexIndex", lua_cc_fairygui_GComponent_getApexIndex);
		tolua_function(tolua_S, "getChild", lua_cc_fairygui_GComponent_getChild);
		tolua_function(tolua_S, "getChildAt", lua_cc_fairygui_GComponent_getChildAt);
		tolua_function(tolua_S, "getChildById", lua_cc_fairygui_GComponent_getChildById);
		tolua_function(tolua_S, "getChildInGroup", lua_cc_fairygui_GComponent_getChildInGroup);
		tolua_function(tolua_S, "getChildIndex", lua_cc_fairygui_GComponent_getChildIndex);
		tolua_function(tolua_S, "getChildren", lua_cc_fairygui_GComponent_getChildren);
		tolua_function(tolua_S, "getChildrenRenderOrder", lua_cc_fairygui_GComponent_getChildrenRenderOrder);
		tolua_function(tolua_S, "getController", lua_cc_fairygui_GComponent_getController);
		tolua_function(tolua_S, "getControllerAt", lua_cc_fairygui_GComponent_getControllerAt);
		tolua_function(tolua_S, "getControllers", lua_cc_fairygui_GComponent_getControllers);
		tolua_function(tolua_S, "getFirstChildInView", lua_cc_fairygui_GComponent_getFirstChildInView);
		tolua_function(tolua_S, "getHitArea", lua_cc_fairygui_GComponent_getHitArea);
		tolua_function(tolua_S, "getMargin", lua_cc_fairygui_GComponent_getMargin);
		tolua_function(tolua_S, "getMask", lua_cc_fairygui_GComponent_getMask);
		tolua_function(tolua_S, "getOpaque", lua_cc_fairygui_GComponent_getOpaque);
		tolua_function(tolua_S, "getScrollPane", lua_cc_fairygui_GComponent_getScrollPane);
		tolua_function(tolua_S, "getSnappingPosition", lua_cc_fairygui_GComponent_getSnappingPosition);
		tolua_function(tolua_S, "getTransition", lua_cc_fairygui_GComponent_getTransition);
		tolua_function(tolua_S, "getTransitionAt", lua_cc_fairygui_GComponent_getTransitionAt);
		tolua_function(tolua_S, "getTransitions", lua_cc_fairygui_GComponent_getTransitions);
		tolua_function(tolua_S, "getViewHeight", lua_cc_fairygui_GComponent_getViewHeight);
		tolua_function(tolua_S, "getViewWidth", lua_cc_fairygui_GComponent_getViewWidth);
		tolua_function(tolua_S, "isAncestorOf", lua_cc_fairygui_GComponent_isAncestorOf);
		tolua_function(tolua_S, "isChildInView", lua_cc_fairygui_GComponent_isChildInView);
		tolua_function(tolua_S, "numChildren", lua_cc_fairygui_GComponent_numChildren);
		tolua_function(tolua_S, "removeChild", lua_cc_fairygui_GComponent_removeChild);
		tolua_function(tolua_S, "removeChildAt", lua_cc_fairygui_GComponent_removeChildAt);
		tolua_function(tolua_S, "removeChildren", lua_cc_fairygui_GComponent_removeChildren);
		tolua_function(tolua_S, "removeController", lua_cc_fairygui_GComponent_removeController);
		tolua_function(tolua_S, "setApexIndex", lua_cc_fairygui_GComponent_setApexIndex);
		tolua_function(tolua_S, "setBoundsChangedFlag", lua_cc_fairygui_GComponent_setBoundsChangedFlag);
		tolua_function(tolua_S, "setChildIndex", lua_cc_fairygui_GComponent_setChildIndex);
		tolua_function(tolua_S, "setChildIndexBefore", lua_cc_fairygui_GComponent_setChildIndexBefore);
		tolua_function(tolua_S, "setChildrenRenderOrder", lua_cc_fairygui_GComponent_setChildrenRenderOrder);
		tolua_function(tolua_S, "setHitArea", lua_cc_fairygui_GComponent_setHitArea);
		tolua_function(tolua_S, "setMargin", lua_cc_fairygui_GComponent_setMargin);
		tolua_function(tolua_S, "setMask", lua_cc_fairygui_GComponent_setMask);
		tolua_function(tolua_S, "setOpaque", lua_cc_fairygui_GComponent_setOpaque);
		tolua_function(tolua_S, "setViewHeight", lua_cc_fairygui_GComponent_setViewHeight);
		tolua_function(tolua_S, "setViewWidth", lua_cc_fairygui_GComponent_setViewWidth);
		tolua_function(tolua_S, "swapChildren", lua_cc_fairygui_GComponent_swapChildren);
		tolua_function(tolua_S, "swapChildrenAt", lua_cc_fairygui_GComponent_swapChildrenAt);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GComponent_create);
		tolua_variable(tolua_S, "_buildingDisplayList", lua_cc_fairygui_GComponent_get_buildingDisplayList, lua_cc_fairygui_GComponent_set_buildingDisplayList);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GComponent).name();
	g_luaType[typeName] = "fgui.GComponent";
	g_typeCast["GComponent"] = "fgui.GComponent";
	return 1;
}

int lua_cc_fairygui_GLabel_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLabel";
	constexpr auto LUA_FNAME = "fgui.GLabel:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GLabel::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLabel_getTextField(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLabel";
	constexpr auto LUA_FNAME = "fgui.GLabel:getTextField";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTextField();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLabel_getTitle(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLabel";
	constexpr auto LUA_FNAME = "fgui.GLabel:getTitle";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTitle();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLabel_getTitleColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLabel";
	constexpr auto LUA_FNAME = "fgui.GLabel:getTitleColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTitleColor();
		color3b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLabel_getTitleFontSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLabel";
	constexpr auto LUA_FNAME = "fgui.GLabel:getTitleFontSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTitleFontSize();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLabel_setTitle(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLabel";
	constexpr auto LUA_FNAME = "fgui.GLabel:setTitle";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTitle(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLabel_setTitleColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLabel";
	constexpr auto LUA_FNAME = "fgui.GLabel:setTitleColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= luaval_to_color3b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTitleColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLabel_setTitleFontSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLabel";
	constexpr auto LUA_FNAME = "fgui.GLabel:setTitleFontSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLabel*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTitleFontSize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLabel_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLabel";
	constexpr auto LUA_FNAME = "fgui.GLabel constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GLabel();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GLabel_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GLabel(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GLabel");
	tolua_cclass(tolua_S, "GLabel", "fgui.GLabel", "fgui.GComponent", nullptr);

	tolua_beginmodule(tolua_S, "GLabel");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GLabel_constructor);
		tolua_function(tolua_S, "getTextField", lua_cc_fairygui_GLabel_getTextField);
		tolua_function(tolua_S, "getTitle", lua_cc_fairygui_GLabel_getTitle);
		tolua_function(tolua_S, "getTitleColor", lua_cc_fairygui_GLabel_getTitleColor);
		tolua_function(tolua_S, "getTitleFontSize", lua_cc_fairygui_GLabel_getTitleFontSize);
		tolua_function(tolua_S, "setTitle", lua_cc_fairygui_GLabel_setTitle);
		tolua_function(tolua_S, "setTitleColor", lua_cc_fairygui_GLabel_setTitleColor);
		tolua_function(tolua_S, "setTitleFontSize", lua_cc_fairygui_GLabel_setTitleFontSize);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GLabel_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GLabel).name();
	g_luaType[typeName] = "fgui.GLabel";
	g_typeCast["GLabel"] = "fgui.GLabel";
	return 1;
}

int lua_cc_fairygui_GButton_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GButton::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GButton_getRelatedController(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:getRelatedController";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getRelatedController();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GButton_getSelectedIcon(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:getSelectedIcon";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSelectedIcon();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GButton_getSelectedTitle(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:getSelectedTitle";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSelectedTitle();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GButton_getTextField(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:getTextField";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTextField();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GButton_getTitle(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:getTitle";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTitle();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GButton_getTitleColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:getTitleColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTitleColor();
		color3b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GButton_getTitleFontSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:getTitleFontSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTitleFontSize();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GButton_isChangeStateOnClick(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:isChangeStateOnClick";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isChangeStateOnClick();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GButton_isSelected(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:isSelected";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isSelected();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GButton_setChangeStateOnClick(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:setChangeStateOnClick";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setChangeStateOnClick(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GButton_setRelatedController(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:setRelatedController";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GController* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setRelatedController(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GButton_setSelected(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:setSelected";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelected(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GButton_setSelectedIcon(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:setSelectedIcon";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelectedIcon(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GButton_setSelectedTitle(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:setSelectedTitle";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelectedTitle(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GButton_setTitle(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:setTitle";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTitle(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GButton_setTitleColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:setTitleColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= luaval_to_color3b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTitleColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GButton_setTitleFontSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton:setTitleFontSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GButton*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTitleFontSize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GButton_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GButton";
	constexpr auto LUA_FNAME = "fgui.GButton constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GButton();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GButton_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GButton(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GButton");
	tolua_cclass(tolua_S, "GButton", "fgui.GButton", "fgui.GComponent", nullptr);

	tolua_beginmodule(tolua_S, "GButton");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GButton_constructor);
		tolua_function(tolua_S, "getRelatedController", lua_cc_fairygui_GButton_getRelatedController);
		tolua_function(tolua_S, "getSelectedIcon", lua_cc_fairygui_GButton_getSelectedIcon);
		tolua_function(tolua_S, "getSelectedTitle", lua_cc_fairygui_GButton_getSelectedTitle);
		tolua_function(tolua_S, "getTextField", lua_cc_fairygui_GButton_getTextField);
		tolua_function(tolua_S, "getTitle", lua_cc_fairygui_GButton_getTitle);
		tolua_function(tolua_S, "getTitleColor", lua_cc_fairygui_GButton_getTitleColor);
		tolua_function(tolua_S, "getTitleFontSize", lua_cc_fairygui_GButton_getTitleFontSize);
		tolua_function(tolua_S, "isChangeStateOnClick", lua_cc_fairygui_GButton_isChangeStateOnClick);
		tolua_function(tolua_S, "isSelected", lua_cc_fairygui_GButton_isSelected);
		tolua_function(tolua_S, "setChangeStateOnClick", lua_cc_fairygui_GButton_setChangeStateOnClick);
		tolua_function(tolua_S, "setRelatedController", lua_cc_fairygui_GButton_setRelatedController);
		tolua_function(tolua_S, "setSelected", lua_cc_fairygui_GButton_setSelected);
		tolua_function(tolua_S, "setSelectedIcon", lua_cc_fairygui_GButton_setSelectedIcon);
		tolua_function(tolua_S, "setSelectedTitle", lua_cc_fairygui_GButton_setSelectedTitle);
		tolua_function(tolua_S, "setTitle", lua_cc_fairygui_GButton_setTitle);
		tolua_function(tolua_S, "setTitleColor", lua_cc_fairygui_GButton_setTitleColor);
		tolua_function(tolua_S, "setTitleFontSize", lua_cc_fairygui_GButton_setTitleFontSize);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GButton_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GButton).name();
	g_luaType[typeName] = "fgui.GButton";
	g_typeCast["GButton"] = "fgui.GButton";
	return 1;
}

int lua_cc_fairygui_GList_addItemFromPool(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:addItemFromPool";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 1) {
			std::string arg0;
			ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->addItemFromPool(arg0);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			auto ret = cobj->addItemFromPool();
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_addSelection(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:addSelection";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		int arg0;
		bool arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->addSelection(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GList_childIndexToItemIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:childIndexToItemIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->childIndexToItemIndex(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_clearSelection(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:clearSelection";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->clearSelection();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GList::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:getAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getAlign();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getAutoResizeItem(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:getAutoResizeItem";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getAutoResizeItem();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getColumnCount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:getColumnCount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColumnCount();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getColumnGap(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:getColumnGap";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColumnGap();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getDefaultItem(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:getDefaultItem";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getDefaultItem();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getFromPool(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:getFromPool";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 1) {
			std::string arg0;
			ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->getFromPool(arg0);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			auto ret = cobj->getFromPool();
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getItemPool(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:getItemPool";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getItemPool();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getLayout(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:getLayout";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getLayout();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getLineCount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:getLineCount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getLineCount();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getLineGap(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:getLineGap";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getLineGap();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getNumItems(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:getNumItems";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getNumItems();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getSelectedIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:getSelectedIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSelectedIndex();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getVerticalAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:getVerticalAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getVerticalAlign();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_handleArrowKey(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:handleArrowKey";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->handleArrowKey(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_isVirtual(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:isVirtual";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isVirtual();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_itemIndexToChildIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:itemIndexToChildIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->itemIndexToChildIndex(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_refreshVirtualList(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:refreshVirtualList";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->refreshVirtualList();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_removeChildToPool(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:removeChildToPool";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->removeChildToPool(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_removeChildToPoolAt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:removeChildToPoolAt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->removeChildToPoolAt(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_removeChildrenToPool(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:removeChildrenToPool";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			int arg1;
			ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->removeChildrenToPool(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			cobj->removeChildrenToPool();
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_removeSelection(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:removeSelection";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->removeSelection(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_resizeToFit(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:resizeToFit";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			int arg1;
			ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->resizeToFit(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cobj->resizeToFit(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_returnToPool(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:returnToPool";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->returnToPool(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_scrollToView(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:scrollToView";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollToView(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		int arg0;
		bool arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollToView(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) {
		int arg0;
		bool arg1;
		bool arg2;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->scrollToView(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 3");
}
int lua_cc_fairygui_GList_selectAll(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:selectAll";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->selectAll();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_selectReverse(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:selectReverse";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->selectReverse();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_setAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::TextHAlignment arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAlign(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_setAutoResizeItem(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setAutoResizeItem";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAutoResizeItem(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_setColumnCount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setColumnCount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setColumnCount(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_setColumnGap(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setColumnGap";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setColumnGap(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_setDefaultItem(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setDefaultItem";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setDefaultItem(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_setLayout(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setLayout";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::ListLayoutType arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setLayout(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_setLineCount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setLineCount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setLineCount(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_setLineGap(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setLineGap";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setLineGap(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_setNumItems(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setNumItems";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setNumItems(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_setSelectedIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setSelectedIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelectedIndex(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_setSelectionController(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setSelectionController";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GController* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelectionController(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_setSelectionMode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setSelectionMode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::ListSelectionMode arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelectionMode(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_setVerticalAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setVerticalAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::TextVAlignment arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVerticalAlign(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_setVirtual(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setVirtual";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVirtual();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_setVirtualAndLoop(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList:setVirtualAndLoop";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVirtualAndLoop();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GList_getitemRenderer(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList.itemRenderer getter";
	constexpr auto LUA_FIELDNAME = "fgui.GList.itemRenderer";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	handler_to_luafunction(tolua_S, query_luafunction_handler(tolua_S, 2, LUA_FIELDNAME));
	return 1;
}
int lua_cc_fairygui_GList_setitemRenderer(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList.itemRenderer setter";
	constexpr auto LUA_FIELDNAME = "fgui.GList.itemRenderer";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		std::function<void (int, fairygui::GObject *)> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FIELDNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->itemRenderer = arg0;
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_getitemProvider(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList.itemProvider getter";
	constexpr auto LUA_FIELDNAME = "fgui.GList.itemProvider";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	handler_to_luafunction(tolua_S, query_luafunction_handler(tolua_S, 2, LUA_FIELDNAME));
	return 1;
}
int lua_cc_fairygui_GList_setitemProvider(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList.itemProvider setter";
	constexpr auto LUA_FIELDNAME = "fgui.GList.itemProvider";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		std::function<std::string (int)> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FIELDNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->itemProvider = arg0;
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_getscrollItemToViewOnClick(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList.scrollItemToViewOnClick getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->scrollItemToViewOnClick);
	return 1;
}
int lua_cc_fairygui_GList_setscrollItemToViewOnClick(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList.scrollItemToViewOnClick setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->scrollItemToViewOnClick, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_getfoldInvisibleItems(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList.foldInvisibleItems getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->foldInvisibleItems);
	return 1;
}
int lua_cc_fairygui_GList_setfoldInvisibleItems(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList.foldInvisibleItems setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GList*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->foldInvisibleItems, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GList_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GList";
	constexpr auto LUA_FNAME = "fgui.GList constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GList();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GList_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GList(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GList");
	tolua_cclass(tolua_S, "GList", "fgui.GList", "fgui.GComponent", nullptr);

	tolua_beginmodule(tolua_S, "GList");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GList_constructor);
		tolua_function(tolua_S, "addItemFromPool", lua_cc_fairygui_GList_addItemFromPool);
		tolua_function(tolua_S, "addSelection", lua_cc_fairygui_GList_addSelection);
		tolua_function(tolua_S, "childIndexToItemIndex", lua_cc_fairygui_GList_childIndexToItemIndex);
		tolua_function(tolua_S, "clearSelection", lua_cc_fairygui_GList_clearSelection);
		tolua_function(tolua_S, "getAlign", lua_cc_fairygui_GList_getAlign);
		tolua_function(tolua_S, "getAutoResizeItem", lua_cc_fairygui_GList_getAutoResizeItem);
		tolua_function(tolua_S, "getColumnCount", lua_cc_fairygui_GList_getColumnCount);
		tolua_function(tolua_S, "getColumnGap", lua_cc_fairygui_GList_getColumnGap);
		tolua_function(tolua_S, "getDefaultItem", lua_cc_fairygui_GList_getDefaultItem);
		tolua_function(tolua_S, "getFromPool", lua_cc_fairygui_GList_getFromPool);
		tolua_function(tolua_S, "getItemPool", lua_cc_fairygui_GList_getItemPool);
		tolua_function(tolua_S, "getLayout", lua_cc_fairygui_GList_getLayout);
		tolua_function(tolua_S, "getLineCount", lua_cc_fairygui_GList_getLineCount);
		tolua_function(tolua_S, "getLineGap", lua_cc_fairygui_GList_getLineGap);
		tolua_function(tolua_S, "getNumItems", lua_cc_fairygui_GList_getNumItems);
		tolua_function(tolua_S, "getSelectedIndex", lua_cc_fairygui_GList_getSelectedIndex);
		tolua_function(tolua_S, "getVerticalAlign", lua_cc_fairygui_GList_getVerticalAlign);
		tolua_function(tolua_S, "handleArrowKey", lua_cc_fairygui_GList_handleArrowKey);
		tolua_function(tolua_S, "isVirtual", lua_cc_fairygui_GList_isVirtual);
		tolua_function(tolua_S, "itemIndexToChildIndex", lua_cc_fairygui_GList_itemIndexToChildIndex);
		tolua_function(tolua_S, "refreshVirtualList", lua_cc_fairygui_GList_refreshVirtualList);
		tolua_function(tolua_S, "removeChildToPool", lua_cc_fairygui_GList_removeChildToPool);
		tolua_function(tolua_S, "removeChildToPoolAt", lua_cc_fairygui_GList_removeChildToPoolAt);
		tolua_function(tolua_S, "removeChildrenToPool", lua_cc_fairygui_GList_removeChildrenToPool);
		tolua_function(tolua_S, "removeSelection", lua_cc_fairygui_GList_removeSelection);
		tolua_function(tolua_S, "resizeToFit", lua_cc_fairygui_GList_resizeToFit);
		tolua_function(tolua_S, "returnToPool", lua_cc_fairygui_GList_returnToPool);
		tolua_function(tolua_S, "scrollToView", lua_cc_fairygui_GList_scrollToView);
		tolua_function(tolua_S, "selectAll", lua_cc_fairygui_GList_selectAll);
		tolua_function(tolua_S, "selectReverse", lua_cc_fairygui_GList_selectReverse);
		tolua_function(tolua_S, "setAlign", lua_cc_fairygui_GList_setAlign);
		tolua_function(tolua_S, "setAutoResizeItem", lua_cc_fairygui_GList_setAutoResizeItem);
		tolua_function(tolua_S, "setColumnCount", lua_cc_fairygui_GList_setColumnCount);
		tolua_function(tolua_S, "setColumnGap", lua_cc_fairygui_GList_setColumnGap);
		tolua_function(tolua_S, "setDefaultItem", lua_cc_fairygui_GList_setDefaultItem);
		tolua_function(tolua_S, "setLayout", lua_cc_fairygui_GList_setLayout);
		tolua_function(tolua_S, "setLineCount", lua_cc_fairygui_GList_setLineCount);
		tolua_function(tolua_S, "setLineGap", lua_cc_fairygui_GList_setLineGap);
		tolua_function(tolua_S, "setNumItems", lua_cc_fairygui_GList_setNumItems);
		tolua_function(tolua_S, "setSelectedIndex", lua_cc_fairygui_GList_setSelectedIndex);
		tolua_function(tolua_S, "setSelectionController", lua_cc_fairygui_GList_setSelectionController);
		tolua_function(tolua_S, "setSelectionMode", lua_cc_fairygui_GList_setSelectionMode);
		tolua_function(tolua_S, "setVerticalAlign", lua_cc_fairygui_GList_setVerticalAlign);
		tolua_function(tolua_S, "setVirtual", lua_cc_fairygui_GList_setVirtual);
		tolua_function(tolua_S, "setVirtualAndLoop", lua_cc_fairygui_GList_setVirtualAndLoop);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GList_create);
		tolua_variable(tolua_S, "itemRenderer", lua_cc_fairygui_GList_getitemRenderer, lua_cc_fairygui_GList_setitemRenderer);
		tolua_variable(tolua_S, "itemProvider", lua_cc_fairygui_GList_getitemProvider, lua_cc_fairygui_GList_setitemProvider);
		tolua_variable(tolua_S, "scrollItemToViewOnClick", lua_cc_fairygui_GList_getscrollItemToViewOnClick, lua_cc_fairygui_GList_setscrollItemToViewOnClick);
		tolua_variable(tolua_S, "foldInvisibleItems", lua_cc_fairygui_GList_getfoldInvisibleItems, lua_cc_fairygui_GList_setfoldInvisibleItems);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GList).name();
	g_luaType[typeName] = "fgui.GList";
	g_typeCast["GList"] = "fgui.GList";
	return 1;
}

int lua_cc_fairygui_GComboBox_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GComboBox::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComboBox_getDropdown(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:getDropdown";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getDropdown();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComboBox_getIcons(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:getIcons";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getIcons();
		ccvector_std_string_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComboBox_getItems(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:getItems";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getItems();
		ccvector_std_string_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComboBox_getSelectedIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:getSelectedIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSelectedIndex();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComboBox_getSelectionController(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:getSelectionController";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSelectionController();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComboBox_getTextField(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:getTextField";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTextField();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComboBox_getTitle(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:getTitle";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTitle();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComboBox_getTitleColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:getTitleColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTitleColor();
		color3b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComboBox_getTitleFontSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:getTitleFontSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTitleFontSize();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComboBox_getValue(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:getValue";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getValue();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComboBox_getValues(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:getValues";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getValues();
		ccvector_std_string_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComboBox_refresh(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:refresh";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->refresh();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GComboBox_setSelectedIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:setSelectedIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelectedIndex(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComboBox_setSelectionController(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:setSelectionController";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GController* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSelectionController(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComboBox_setTitle(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:setTitle";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTitle(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComboBox_setTitleColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:setTitleColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= luaval_to_color3b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTitleColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComboBox_setTitleFontSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:setTitleFontSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTitleFontSize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComboBox_setValue(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox:setValue";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setValue(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComboBox_getvisibleItemCount(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox.visibleItemCount getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->visibleItemCount);
	return 1;
}
int lua_cc_fairygui_GComboBox_setvisibleItemCount(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox.visibleItemCount setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->visibleItemCount, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComboBox_getpopupDirection(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox.popupDirection getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->popupDirection);
	return 1;
}
int lua_cc_fairygui_GComboBox_setpopupDirection(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox.popupDirection setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GComboBox*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->popupDirection, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GComboBox_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GComboBox";
	constexpr auto LUA_FNAME = "fgui.GComboBox constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GComboBox();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GComboBox_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GComboBox(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GComboBox");
	tolua_cclass(tolua_S, "GComboBox", "fgui.GComboBox", "fgui.GComponent", nullptr);

	tolua_beginmodule(tolua_S, "GComboBox");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GComboBox_constructor);
		tolua_function(tolua_S, "getDropdown", lua_cc_fairygui_GComboBox_getDropdown);
		tolua_function(tolua_S, "getIcons", lua_cc_fairygui_GComboBox_getIcons);
		tolua_function(tolua_S, "getItems", lua_cc_fairygui_GComboBox_getItems);
		tolua_function(tolua_S, "getSelectedIndex", lua_cc_fairygui_GComboBox_getSelectedIndex);
		tolua_function(tolua_S, "getSelectionController", lua_cc_fairygui_GComboBox_getSelectionController);
		tolua_function(tolua_S, "getTextField", lua_cc_fairygui_GComboBox_getTextField);
		tolua_function(tolua_S, "getTitle", lua_cc_fairygui_GComboBox_getTitle);
		tolua_function(tolua_S, "getTitleColor", lua_cc_fairygui_GComboBox_getTitleColor);
		tolua_function(tolua_S, "getTitleFontSize", lua_cc_fairygui_GComboBox_getTitleFontSize);
		tolua_function(tolua_S, "getValue", lua_cc_fairygui_GComboBox_getValue);
		tolua_function(tolua_S, "getValues", lua_cc_fairygui_GComboBox_getValues);
		tolua_function(tolua_S, "refresh", lua_cc_fairygui_GComboBox_refresh);
		tolua_function(tolua_S, "setSelectedIndex", lua_cc_fairygui_GComboBox_setSelectedIndex);
		tolua_function(tolua_S, "setSelectionController", lua_cc_fairygui_GComboBox_setSelectionController);
		tolua_function(tolua_S, "setTitle", lua_cc_fairygui_GComboBox_setTitle);
		tolua_function(tolua_S, "setTitleColor", lua_cc_fairygui_GComboBox_setTitleColor);
		tolua_function(tolua_S, "setTitleFontSize", lua_cc_fairygui_GComboBox_setTitleFontSize);
		tolua_function(tolua_S, "setValue", lua_cc_fairygui_GComboBox_setValue);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GComboBox_create);
		tolua_variable(tolua_S, "visibleItemCount", lua_cc_fairygui_GComboBox_getvisibleItemCount, lua_cc_fairygui_GComboBox_setvisibleItemCount);
		tolua_variable(tolua_S, "popupDirection", lua_cc_fairygui_GComboBox_getpopupDirection, lua_cc_fairygui_GComboBox_setpopupDirection);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GComboBox).name();
	g_luaType[typeName] = "fgui.GComboBox";
	g_typeCast["GComboBox"] = "fgui.GComboBox";
	return 1;
}

int lua_cc_fairygui_GProgressBar_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GProgressBar";
	constexpr auto LUA_FNAME = "fgui.GProgressBar:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GProgressBar::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GProgressBar_getMax(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GProgressBar";
	constexpr auto LUA_FNAME = "fgui.GProgressBar:getMax";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getMax();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GProgressBar_getMin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GProgressBar";
	constexpr auto LUA_FNAME = "fgui.GProgressBar:getMin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getMin();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GProgressBar_getTitleType(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GProgressBar";
	constexpr auto LUA_FNAME = "fgui.GProgressBar:getTitleType";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTitleType();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GProgressBar_getValue(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GProgressBar";
	constexpr auto LUA_FNAME = "fgui.GProgressBar:getValue";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getValue();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GProgressBar_setMax(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GProgressBar";
	constexpr auto LUA_FNAME = "fgui.GProgressBar:setMax";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setMax(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GProgressBar_setMin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GProgressBar";
	constexpr auto LUA_FNAME = "fgui.GProgressBar:setMin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setMin(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GProgressBar_setTitleType(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GProgressBar";
	constexpr auto LUA_FNAME = "fgui.GProgressBar:setTitleType";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::ProgressTitleType arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTitleType(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GProgressBar_setValue(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GProgressBar";
	constexpr auto LUA_FNAME = "fgui.GProgressBar:setValue";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setValue(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GProgressBar_tweenValue(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GProgressBar";
	constexpr auto LUA_FNAME = "fgui.GProgressBar:tweenValue";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		double arg0;
		double arg1;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->tweenValue(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GProgressBar_update(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GProgressBar";
	constexpr auto LUA_FNAME = "fgui.GProgressBar:update";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GProgressBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->update(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GProgressBar_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GProgressBar";
	constexpr auto LUA_FNAME = "fgui.GProgressBar constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GProgressBar();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GProgressBar_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GProgressBar(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GProgressBar");
	tolua_cclass(tolua_S, "GProgressBar", "fgui.GProgressBar", "fgui.GComponent", nullptr);

	tolua_beginmodule(tolua_S, "GProgressBar");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GProgressBar_constructor);
		tolua_function(tolua_S, "getMax", lua_cc_fairygui_GProgressBar_getMax);
		tolua_function(tolua_S, "getMin", lua_cc_fairygui_GProgressBar_getMin);
		tolua_function(tolua_S, "getTitleType", lua_cc_fairygui_GProgressBar_getTitleType);
		tolua_function(tolua_S, "getValue", lua_cc_fairygui_GProgressBar_getValue);
		tolua_function(tolua_S, "setMax", lua_cc_fairygui_GProgressBar_setMax);
		tolua_function(tolua_S, "setMin", lua_cc_fairygui_GProgressBar_setMin);
		tolua_function(tolua_S, "setTitleType", lua_cc_fairygui_GProgressBar_setTitleType);
		tolua_function(tolua_S, "setValue", lua_cc_fairygui_GProgressBar_setValue);
		tolua_function(tolua_S, "tweenValue", lua_cc_fairygui_GProgressBar_tweenValue);
		tolua_function(tolua_S, "update", lua_cc_fairygui_GProgressBar_update);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GProgressBar_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GProgressBar).name();
	g_luaType[typeName] = "fgui.GProgressBar";
	g_typeCast["GProgressBar"] = "fgui.GProgressBar";
	return 1;
}

int lua_cc_fairygui_GSlider_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GSlider::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GSlider_getMax(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider:getMax";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getMax();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GSlider_getMin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider:getMin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getMin();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GSlider_getTitleType(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider:getTitleType";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTitleType();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GSlider_getValue(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider:getValue";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getValue();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GSlider_getWholeNumbers(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider:getWholeNumbers";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getWholeNumbers();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GSlider_setMax(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider:setMax";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setMax(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GSlider_setMin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider:setMin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setMin(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GSlider_setTitleType(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider:setTitleType";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::ProgressTitleType arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setTitleType(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GSlider_setValue(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider:setValue";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setValue(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GSlider_setWholeNumbers(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider:setWholeNumbers";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setWholeNumbers(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GSlider_getchangeOnClick(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider.changeOnClick getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->changeOnClick);
	return 1;
}
int lua_cc_fairygui_GSlider_setchangeOnClick(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider.changeOnClick setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->changeOnClick, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GSlider_getcanDrag(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider.canDrag getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->canDrag);
	return 1;
}
int lua_cc_fairygui_GSlider_setcanDrag(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider.canDrag setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GSlider*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->canDrag, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GSlider_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GSlider";
	constexpr auto LUA_FNAME = "fgui.GSlider constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GSlider();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GSlider_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GSlider(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GSlider");
	tolua_cclass(tolua_S, "GSlider", "fgui.GSlider", "fgui.GComponent", nullptr);

	tolua_beginmodule(tolua_S, "GSlider");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GSlider_constructor);
		tolua_function(tolua_S, "getMax", lua_cc_fairygui_GSlider_getMax);
		tolua_function(tolua_S, "getMin", lua_cc_fairygui_GSlider_getMin);
		tolua_function(tolua_S, "getTitleType", lua_cc_fairygui_GSlider_getTitleType);
		tolua_function(tolua_S, "getValue", lua_cc_fairygui_GSlider_getValue);
		tolua_function(tolua_S, "getWholeNumbers", lua_cc_fairygui_GSlider_getWholeNumbers);
		tolua_function(tolua_S, "setMax", lua_cc_fairygui_GSlider_setMax);
		tolua_function(tolua_S, "setMin", lua_cc_fairygui_GSlider_setMin);
		tolua_function(tolua_S, "setTitleType", lua_cc_fairygui_GSlider_setTitleType);
		tolua_function(tolua_S, "setValue", lua_cc_fairygui_GSlider_setValue);
		tolua_function(tolua_S, "setWholeNumbers", lua_cc_fairygui_GSlider_setWholeNumbers);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GSlider_create);
		tolua_variable(tolua_S, "changeOnClick", lua_cc_fairygui_GSlider_getchangeOnClick, lua_cc_fairygui_GSlider_setchangeOnClick);
		tolua_variable(tolua_S, "canDrag", lua_cc_fairygui_GSlider_getcanDrag, lua_cc_fairygui_GSlider_setcanDrag);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GSlider).name();
	g_luaType[typeName] = "fgui.GSlider";
	g_typeCast["GSlider"] = "fgui.GSlider";
	return 1;
}

int lua_cc_fairygui_GScrollBar_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GScrollBar";
	constexpr auto LUA_FNAME = "fgui.GScrollBar:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GScrollBar::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GScrollBar_getMinSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GScrollBar";
	constexpr auto LUA_FNAME = "fgui.GScrollBar:getMinSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GScrollBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getMinSize();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GScrollBar_setDisplayPerc(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GScrollBar";
	constexpr auto LUA_FNAME = "fgui.GScrollBar:setDisplayPerc";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GScrollBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setDisplayPerc(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GScrollBar_setScrollPane(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GScrollBar";
	constexpr auto LUA_FNAME = "fgui.GScrollBar:setScrollPane";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GScrollBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::ScrollPane* arg0;
		bool arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setScrollPane(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GScrollBar_setScrollPerc(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GScrollBar";
	constexpr auto LUA_FNAME = "fgui.GScrollBar:setScrollPerc";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GScrollBar*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setScrollPerc(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GScrollBar_get_gripDragging(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GScrollBar";
	constexpr auto LUA_FNAME = "fgui.GScrollBar._gripDragging getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GScrollBar*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->_gripDragging);
	return 1;
}
int lua_cc_fairygui_GScrollBar_set_gripDragging(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GScrollBar";
	constexpr auto LUA_FNAME = "fgui.GScrollBar._gripDragging setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GScrollBar*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->_gripDragging, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GScrollBar_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GScrollBar";
	constexpr auto LUA_FNAME = "fgui.GScrollBar constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GScrollBar();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GScrollBar_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GScrollBar(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GScrollBar");
	tolua_cclass(tolua_S, "GScrollBar", "fgui.GScrollBar", "fgui.GComponent", nullptr);

	tolua_beginmodule(tolua_S, "GScrollBar");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GScrollBar_constructor);
		tolua_function(tolua_S, "getMinSize", lua_cc_fairygui_GScrollBar_getMinSize);
		tolua_function(tolua_S, "setDisplayPerc", lua_cc_fairygui_GScrollBar_setDisplayPerc);
		tolua_function(tolua_S, "setScrollPane", lua_cc_fairygui_GScrollBar_setScrollPane);
		tolua_function(tolua_S, "setScrollPerc", lua_cc_fairygui_GScrollBar_setScrollPerc);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GScrollBar_create);
		tolua_variable(tolua_S, "_gripDragging", lua_cc_fairygui_GScrollBar_get_gripDragging, lua_cc_fairygui_GScrollBar_set_gripDragging);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GScrollBar).name();
	g_luaType[typeName] = "fgui.GScrollBar";
	g_typeCast["GScrollBar"] = "fgui.GScrollBar";
	return 1;
}

int lua_cc_fairygui_GTreeNode_addChild(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:addChild";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GTreeNode* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->addChild(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTreeNode_addChildAt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:addChildAt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GTreeNode* arg0;
		int arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->addChildAt(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GTreeNode_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GTreeNode::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GTreeNode::create(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	if (argc == 2) {
		bool arg0;
		std::string arg1;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GTreeNode::create(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 2");
}
int lua_cc_fairygui_GTreeNode_getCell(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:getCell";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getCell();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTreeNode_getChildAt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:getChildAt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getChildAt(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTreeNode_getChildIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:getChildIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		const fairygui::GTreeNode* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getChildIndex(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTreeNode_getData(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:getData";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getData();
		ccvalue_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTreeNode_getIcon(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:getIcon";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getIcon();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTreeNode_getNextSibling(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:getNextSibling";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getNextSibling();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTreeNode_getParent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:getParent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getParent();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTreeNode_getPrevSibling(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:getPrevSibling";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPrevSibling();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTreeNode_getText(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:getText";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getText();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTreeNode_getTree(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:getTree";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTree();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTreeNode_isExpanded(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:isExpanded";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isExpanded();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTreeNode_isFolder(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:isFolder";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isFolder();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTreeNode_numChildren(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:numChildren";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->numChildren();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTreeNode_removeChild(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:removeChild";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GTreeNode* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->removeChild(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTreeNode_removeChildAt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:removeChildAt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->removeChildAt(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTreeNode_removeChildren(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:removeChildren";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			int arg1;
			ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->removeChildren(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			cobj->removeChildren();
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTreeNode_setChildIndex(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:setChildIndex";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GTreeNode* arg0;
		int arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setChildIndex(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GTreeNode_setChildIndexBefore(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:setChildIndexBefore";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GTreeNode* arg0;
		int arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setChildIndexBefore(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GTreeNode_setData(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:setData";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Value arg0;
		ok &= luaval_to_ccvalue(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setData(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTreeNode_setExpaned(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:setExpaned";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setExpaned(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTreeNode_setIcon(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:setIcon";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setIcon(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTreeNode_setText(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:setText";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setText(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTreeNode_swapChildren(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:swapChildren";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GTreeNode* arg0;
		fairygui::GTreeNode* arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->swapChildren(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GTreeNode_swapChildrenAt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode:swapChildrenAt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTreeNode*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		int arg0;
		int arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->swapChildrenAt(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GTreeNode_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTreeNode";
	constexpr auto LUA_FNAME = "fgui.GTreeNode constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GTreeNode();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GTreeNode_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GTreeNode(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GTreeNode");
	tolua_cclass(tolua_S, "GTreeNode", "fgui.GTreeNode", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "GTreeNode");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GTreeNode_constructor);
		tolua_function(tolua_S, "addChild", lua_cc_fairygui_GTreeNode_addChild);
		tolua_function(tolua_S, "addChildAt", lua_cc_fairygui_GTreeNode_addChildAt);
		tolua_function(tolua_S, "getCell", lua_cc_fairygui_GTreeNode_getCell);
		tolua_function(tolua_S, "getChildAt", lua_cc_fairygui_GTreeNode_getChildAt);
		tolua_function(tolua_S, "getChildIndex", lua_cc_fairygui_GTreeNode_getChildIndex);
		tolua_function(tolua_S, "getData", lua_cc_fairygui_GTreeNode_getData);
		tolua_function(tolua_S, "getIcon", lua_cc_fairygui_GTreeNode_getIcon);
		tolua_function(tolua_S, "getNextSibling", lua_cc_fairygui_GTreeNode_getNextSibling);
		tolua_function(tolua_S, "getParent", lua_cc_fairygui_GTreeNode_getParent);
		tolua_function(tolua_S, "getPrevSibling", lua_cc_fairygui_GTreeNode_getPrevSibling);
		tolua_function(tolua_S, "getText", lua_cc_fairygui_GTreeNode_getText);
		tolua_function(tolua_S, "getTree", lua_cc_fairygui_GTreeNode_getTree);
		tolua_function(tolua_S, "isExpanded", lua_cc_fairygui_GTreeNode_isExpanded);
		tolua_function(tolua_S, "isFolder", lua_cc_fairygui_GTreeNode_isFolder);
		tolua_function(tolua_S, "numChildren", lua_cc_fairygui_GTreeNode_numChildren);
		tolua_function(tolua_S, "removeChild", lua_cc_fairygui_GTreeNode_removeChild);
		tolua_function(tolua_S, "removeChildAt", lua_cc_fairygui_GTreeNode_removeChildAt);
		tolua_function(tolua_S, "removeChildren", lua_cc_fairygui_GTreeNode_removeChildren);
		tolua_function(tolua_S, "setChildIndex", lua_cc_fairygui_GTreeNode_setChildIndex);
		tolua_function(tolua_S, "setChildIndexBefore", lua_cc_fairygui_GTreeNode_setChildIndexBefore);
		tolua_function(tolua_S, "setData", lua_cc_fairygui_GTreeNode_setData);
		tolua_function(tolua_S, "setExpaned", lua_cc_fairygui_GTreeNode_setExpaned);
		tolua_function(tolua_S, "setIcon", lua_cc_fairygui_GTreeNode_setIcon);
		tolua_function(tolua_S, "setText", lua_cc_fairygui_GTreeNode_setText);
		tolua_function(tolua_S, "swapChildren", lua_cc_fairygui_GTreeNode_swapChildren);
		tolua_function(tolua_S, "swapChildrenAt", lua_cc_fairygui_GTreeNode_swapChildrenAt);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GTreeNode_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GTreeNode).name();
	g_luaType[typeName] = "fgui.GTreeNode";
	g_typeCast["GTreeNode"] = "fgui.GTreeNode";
	return 1;
}

int lua_cc_fairygui_GTree_collapseAll(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree:collapseAll";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GTreeNode* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->collapseAll(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTree_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GTree::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTree_expandAll(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree:expandAll";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GTreeNode* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->expandAll(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTree_getClickToExpand(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree:getClickToExpand";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getClickToExpand();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTree_getIndent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree:getIndent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getIndent();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTree_getRootNode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree:getRootNode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getRootNode();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTree_getSelectedNode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree:getSelectedNode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSelectedNode();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTree_selectNode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree:selectNode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GTreeNode* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->selectNode(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		fairygui::GTreeNode* arg0;
		bool arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->selectNode(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_GTree_setClickToExpand(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree:setClickToExpand";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setClickToExpand(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTree_setIndent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree:setIndent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setIndent(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTree_unselectNode(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree:unselectNode";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GTreeNode* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->unselectNode(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTree_gettreeNodeRender(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree.treeNodeRender getter";
	constexpr auto LUA_FIELDNAME = "fgui.GTree.treeNodeRender";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	handler_to_luafunction(tolua_S, query_luafunction_handler(tolua_S, 2, LUA_FIELDNAME));
	return 1;
}
int lua_cc_fairygui_GTree_settreeNodeRender(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree.treeNodeRender setter";
	constexpr auto LUA_FIELDNAME = "fgui.GTree.treeNodeRender";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		std::function<void (fairygui::GTreeNode *, fairygui::GComponent *)> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FIELDNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->treeNodeRender = arg0;
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTree_gettreeNodeWillExpand(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree.treeNodeWillExpand getter";
	constexpr auto LUA_FIELDNAME = "fgui.GTree.treeNodeWillExpand";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	handler_to_luafunction(tolua_S, query_luafunction_handler(tolua_S, 2, LUA_FIELDNAME));
	return 1;
}
int lua_cc_fairygui_GTree_settreeNodeWillExpand(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree.treeNodeWillExpand setter";
	constexpr auto LUA_FIELDNAME = "fgui.GTree.treeNodeWillExpand";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTree*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		std::function<void (fairygui::GTreeNode *, bool)> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FIELDNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->treeNodeWillExpand = arg0;
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTree_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTree";
	constexpr auto LUA_FNAME = "fgui.GTree constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GTree();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GTree_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GTree(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GTree");
	tolua_cclass(tolua_S, "GTree", "fgui.GTree", "fgui.GList", nullptr);

	tolua_beginmodule(tolua_S, "GTree");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GTree_constructor);
		tolua_function(tolua_S, "collapseAll", lua_cc_fairygui_GTree_collapseAll);
		tolua_function(tolua_S, "expandAll", lua_cc_fairygui_GTree_expandAll);
		tolua_function(tolua_S, "getClickToExpand", lua_cc_fairygui_GTree_getClickToExpand);
		tolua_function(tolua_S, "getIndent", lua_cc_fairygui_GTree_getIndent);
		tolua_function(tolua_S, "getRootNode", lua_cc_fairygui_GTree_getRootNode);
		tolua_function(tolua_S, "getSelectedNode", lua_cc_fairygui_GTree_getSelectedNode);
		tolua_function(tolua_S, "selectNode", lua_cc_fairygui_GTree_selectNode);
		tolua_function(tolua_S, "setClickToExpand", lua_cc_fairygui_GTree_setClickToExpand);
		tolua_function(tolua_S, "setIndent", lua_cc_fairygui_GTree_setIndent);
		tolua_function(tolua_S, "unselectNode", lua_cc_fairygui_GTree_unselectNode);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GTree_create);
		tolua_variable(tolua_S, "treeNodeRender", lua_cc_fairygui_GTree_gettreeNodeRender, lua_cc_fairygui_GTree_settreeNodeRender);
		tolua_variable(tolua_S, "treeNodeWillExpand", lua_cc_fairygui_GTree_gettreeNodeWillExpand, lua_cc_fairygui_GTree_settreeNodeWillExpand);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GTree).name();
	g_luaType[typeName] = "fgui.GTree";
	g_typeCast["GTree"] = "fgui.GTree";
	return 1;
}

int lua_cc_fairygui_IUISource_getFileName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.IUISource";
	constexpr auto LUA_FNAME = "fgui.IUISource:getFileName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::IUISource*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFileName();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_IUISource_isLoaded(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.IUISource";
	constexpr auto LUA_FNAME = "fgui.IUISource:isLoaded";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::IUISource*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isLoaded();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_IUISource_load(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.IUISource";
	constexpr auto LUA_FNAME = "fgui.IUISource:load";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::IUISource*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::function<void ()> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		int handler2 = query_luafunction_handler(tolua_S, 2, LUA_FNAME);
		ok &= handler2 != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->load(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_IUISource_setFileName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.IUISource";
	constexpr auto LUA_FNAME = "fgui.IUISource:setFileName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::IUISource*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFileName(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
static int lua_cc_fairygui_IUISource_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_IUISource(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.IUISource");
	tolua_cclass(tolua_S, "IUISource", "fgui.IUISource", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "IUISource");
		tolua_function(tolua_S, "getFileName", lua_cc_fairygui_IUISource_getFileName);
		tolua_function(tolua_S, "isLoaded", lua_cc_fairygui_IUISource_isLoaded);
		tolua_function(tolua_S, "load", lua_cc_fairygui_IUISource_load);
		tolua_function(tolua_S, "setFileName", lua_cc_fairygui_IUISource_setFileName);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::IUISource).name();
	g_luaType[typeName] = "fgui.IUISource";
	g_typeCast["IUISource"] = "fgui.IUISource";
	return 1;
}

int lua_cc_fairygui_Window_addUISource(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:addUISource";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::IUISource* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->addUISource(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Window_bringToFront(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:bringToFront";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->bringToFront();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_closeModalWait(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:closeModalWait";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 1) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->closeModalWait(arg0);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			auto ret = cobj->closeModalWait();
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::Window::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_getCloseButton(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:getCloseButton";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getCloseButton();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_getContentArea(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:getContentArea";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getContentArea();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_getContentPane(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:getContentPane";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getContentPane();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_getDragArea(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:getDragArea";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getDragArea();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_getFrame(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:getFrame";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFrame();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_getModalWaitingPane(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:getModalWaitingPane";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getModalWaitingPane();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_hide(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:hide";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->hide();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_hideImmediately(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:hideImmediately";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->hideImmediately();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_initWindow(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:initWindow";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->initWindow();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_isBringToFrontOnClick(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:isBringToFrontOnClick";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isBringToFrontOnClick();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_isModal(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:isModal";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isModal();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_isShowing(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:isShowing";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isShowing();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_isTop(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:isTop";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isTop();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_setBringToFrontOnClick(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:setBringToFrontOnClick";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setBringToFrontOnClick(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Window_setCloseButton(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:setCloseButton";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setCloseButton(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Window_setContentArea(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:setContentArea";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setContentArea(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Window_setContentPane(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:setContentPane";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GComponent* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setContentPane(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Window_setDragArea(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:setDragArea";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setDragArea(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Window_setModal(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:setModal";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setModal(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_Window_show(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:show";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->show();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_showModalWait(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:showModalWait";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 1) {
			int arg0;
			ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cobj->showModalWait(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			cobj->showModalWait();
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_toggleStatus(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window:toggleStatus";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::Window*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->toggleStatus();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_Window_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.Window";
	constexpr auto LUA_FNAME = "fgui.Window constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::Window();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_Window_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_Window(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.Window");
	tolua_cclass(tolua_S, "Window", "fgui.Window", "fgui.GComponent", nullptr);

	tolua_beginmodule(tolua_S, "Window");
		tolua_function(tolua_S, "new", lua_cc_fairygui_Window_constructor);
		tolua_function(tolua_S, "addUISource", lua_cc_fairygui_Window_addUISource);
		tolua_function(tolua_S, "bringToFront", lua_cc_fairygui_Window_bringToFront);
		tolua_function(tolua_S, "closeModalWait", lua_cc_fairygui_Window_closeModalWait);
		tolua_function(tolua_S, "getCloseButton", lua_cc_fairygui_Window_getCloseButton);
		tolua_function(tolua_S, "getContentArea", lua_cc_fairygui_Window_getContentArea);
		tolua_function(tolua_S, "getContentPane", lua_cc_fairygui_Window_getContentPane);
		tolua_function(tolua_S, "getDragArea", lua_cc_fairygui_Window_getDragArea);
		tolua_function(tolua_S, "getFrame", lua_cc_fairygui_Window_getFrame);
		tolua_function(tolua_S, "getModalWaitingPane", lua_cc_fairygui_Window_getModalWaitingPane);
		tolua_function(tolua_S, "hide", lua_cc_fairygui_Window_hide);
		tolua_function(tolua_S, "hideImmediately", lua_cc_fairygui_Window_hideImmediately);
		tolua_function(tolua_S, "initWindow", lua_cc_fairygui_Window_initWindow);
		tolua_function(tolua_S, "isBringToFrontOnClick", lua_cc_fairygui_Window_isBringToFrontOnClick);
		tolua_function(tolua_S, "isModal", lua_cc_fairygui_Window_isModal);
		tolua_function(tolua_S, "isShowing", lua_cc_fairygui_Window_isShowing);
		tolua_function(tolua_S, "isTop", lua_cc_fairygui_Window_isTop);
		tolua_function(tolua_S, "setBringToFrontOnClick", lua_cc_fairygui_Window_setBringToFrontOnClick);
		tolua_function(tolua_S, "setCloseButton", lua_cc_fairygui_Window_setCloseButton);
		tolua_function(tolua_S, "setContentArea", lua_cc_fairygui_Window_setContentArea);
		tolua_function(tolua_S, "setContentPane", lua_cc_fairygui_Window_setContentPane);
		tolua_function(tolua_S, "setDragArea", lua_cc_fairygui_Window_setDragArea);
		tolua_function(tolua_S, "setModal", lua_cc_fairygui_Window_setModal);
		tolua_function(tolua_S, "show", lua_cc_fairygui_Window_show);
		tolua_function(tolua_S, "showModalWait", lua_cc_fairygui_Window_showModalWait);
		tolua_function(tolua_S, "toggleStatus", lua_cc_fairygui_Window_toggleStatus);
		tolua_function(tolua_S, "create", lua_cc_fairygui_Window_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::Window).name();
	g_luaType[typeName] = "fgui.Window";
	g_typeCast["Window"] = "fgui.Window";
	return 1;
}

int lua_cc_fairygui_InputProcessor_addTouchMonitor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputProcessor";
	constexpr auto LUA_FNAME = "fgui.InputProcessor:addTouchMonitor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputProcessor*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		int arg0;
		fairygui::GObject* arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->addTouchMonitor(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_InputProcessor_cancelClick(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputProcessor";
	constexpr auto LUA_FNAME = "fgui.InputProcessor:cancelClick";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputProcessor*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->cancelClick(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_InputProcessor_disableDefaultTouchEvent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputProcessor";
	constexpr auto LUA_FNAME = "fgui.InputProcessor:disableDefaultTouchEvent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputProcessor*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->disableDefaultTouchEvent();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputProcessor_getRecentInput(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputProcessor";
	constexpr auto LUA_FNAME = "fgui.InputProcessor:getRecentInput";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputProcessor*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getRecentInput();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputProcessor_getTouchPosition(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputProcessor";
	constexpr auto LUA_FNAME = "fgui.InputProcessor:getTouchPosition";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputProcessor*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTouchPosition(arg0);
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_InputProcessor_isTouchOnUI(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputProcessor";
	constexpr auto LUA_FNAME = "fgui.InputProcessor:isTouchOnUI";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::InputProcessor::isTouchOnUI();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_InputProcessor_removeTouchMonitor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputProcessor";
	constexpr auto LUA_FNAME = "fgui.InputProcessor:removeTouchMonitor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputProcessor*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->removeTouchMonitor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_InputProcessor_setCaptureCallback(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputProcessor";
	constexpr auto LUA_FNAME = "fgui.InputProcessor:setCaptureCallback";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputProcessor*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::function<void (int)> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		int handler2 = query_luafunction_handler(tolua_S, 2, LUA_FNAME);
		ok &= handler2 != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setCaptureCallback(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_InputProcessor_simulateClick(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputProcessor";
	constexpr auto LUA_FNAME = "fgui.InputProcessor:simulateClick";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputProcessor*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->simulateClick(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		fairygui::GObject* arg0;
		int arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->simulateClick(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_InputProcessor_touchDown(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputProcessor";
	constexpr auto LUA_FNAME = "fgui.InputProcessor:touchDown";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputProcessor*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		cocos2d::Touch* arg0;
		cocos2d::Event* arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->touchDown(arg0, arg1);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_InputProcessor_touchMove(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputProcessor";
	constexpr auto LUA_FNAME = "fgui.InputProcessor:touchMove";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputProcessor*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		cocos2d::Touch* arg0;
		cocos2d::Event* arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->touchMove(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_InputProcessor_touchUp(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputProcessor";
	constexpr auto LUA_FNAME = "fgui.InputProcessor:touchUp";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::InputProcessor*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		cocos2d::Touch* arg0;
		cocos2d::Event* arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->touchUp(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_InputProcessor_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.InputProcessor";
	constexpr auto LUA_FNAME = "fgui.InputProcessor constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GComponent* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::InputProcessor(arg0);
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}

static int lua_cc_fairygui_InputProcessor_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_InputProcessor(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.InputProcessor");
	tolua_cclass(tolua_S, "InputProcessor", "fgui.InputProcessor", "", nullptr);

	tolua_beginmodule(tolua_S, "InputProcessor");
		tolua_function(tolua_S, "new", lua_cc_fairygui_InputProcessor_constructor);
		tolua_function(tolua_S, "addTouchMonitor", lua_cc_fairygui_InputProcessor_addTouchMonitor);
		tolua_function(tolua_S, "cancelClick", lua_cc_fairygui_InputProcessor_cancelClick);
		tolua_function(tolua_S, "disableDefaultTouchEvent", lua_cc_fairygui_InputProcessor_disableDefaultTouchEvent);
		tolua_function(tolua_S, "getRecentInput", lua_cc_fairygui_InputProcessor_getRecentInput);
		tolua_function(tolua_S, "getTouchPosition", lua_cc_fairygui_InputProcessor_getTouchPosition);
		tolua_function(tolua_S, "removeTouchMonitor", lua_cc_fairygui_InputProcessor_removeTouchMonitor);
		tolua_function(tolua_S, "setCaptureCallback", lua_cc_fairygui_InputProcessor_setCaptureCallback);
		tolua_function(tolua_S, "simulateClick", lua_cc_fairygui_InputProcessor_simulateClick);
		tolua_function(tolua_S, "touchDown", lua_cc_fairygui_InputProcessor_touchDown);
		tolua_function(tolua_S, "touchMove", lua_cc_fairygui_InputProcessor_touchMove);
		tolua_function(tolua_S, "touchUp", lua_cc_fairygui_InputProcessor_touchUp);
		tolua_function(tolua_S, "isTouchOnUI", lua_cc_fairygui_InputProcessor_isTouchOnUI);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::InputProcessor).name();
	g_luaType[typeName] = "fgui.InputProcessor";
	g_typeCast["InputProcessor"] = "fgui.InputProcessor";
	return 1;
}

int lua_cc_fairygui_GRoot_bringToFront(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:bringToFront";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::Window* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->bringToFront(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRoot_closeAllExceptModals(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:closeAllExceptModals";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->closeAllExceptModals();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_closeAllWindows(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:closeAllWindows";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->closeAllWindows();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_closeModalWait(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:closeModalWait";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->closeModalWait();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Scene* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GRoot::create(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	if (argc == 2) {
		cocos2d::Scene* arg0;
		int arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GRoot::create(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_GRoot_getInputProcessor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:getInputProcessor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getInputProcessor();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_getInstance(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:getInstance";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GRoot::getInstance();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_getModalLayer(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:getModalLayer";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getModalLayer();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_getModalWaitingPane(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:getModalWaitingPane";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getModalWaitingPane();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_getPoupPosition(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:getPoupPosition";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		fairygui::GObject* arg0;
		fairygui::GObject* arg1;
		fairygui::PopupDirection arg2;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPoupPosition(arg0, arg1, arg2);
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_cc_fairygui_GRoot_getSoundVolumeScale(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:getSoundVolumeScale";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSoundVolumeScale();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_getTopWindow(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:getTopWindow";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTopWindow();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_getTouchPosition(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:getTouchPosition";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTouchPosition(arg0);
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRoot_getTouchTarget(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:getTouchTarget";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTouchTarget();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_hasAnyPopup(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:hasAnyPopup";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->hasAnyPopup();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_hasModalWindow(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:hasModalWindow";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->hasModalWindow();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_hidePopup(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:hidePopup";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 1) {
			fairygui::GObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cobj->hidePopup(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			cobj->hidePopup();
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_hideTooltips(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:hideTooltips";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->hideTooltips();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_hideWindow(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:hideWindow";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::Window* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->hideWindow(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRoot_hideWindowImmediately(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:hideWindowImmediately";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::Window* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->hideWindowImmediately(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRoot_isModalWaiting(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:isModalWaiting";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isModalWaiting();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_isSoundEnabled(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:isSoundEnabled";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isSoundEnabled();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_playSound(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:playSound";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->playSound(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		std::string arg0;
		double arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->playSound(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_GRoot_rootToWorld(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:rootToWorld";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->rootToWorld(arg0);
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRoot_setSoundEnabled(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:setSoundEnabled";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSoundEnabled(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRoot_setSoundVolumeScale(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:setSoundVolumeScale";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSoundVolumeScale(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRoot_showModalWait(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:showModalWait";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->showModalWait();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GRoot_showPopup(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:showPopup";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 3) {
			fairygui::GObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			fairygui::GObject* arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			fairygui::PopupDirection arg2;
			ok &= luaval_to_native(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			cobj->showPopup(arg0, arg1, arg2);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			fairygui::GObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cobj->showPopup(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRoot_showTooltips(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:showTooltips";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->showTooltips(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRoot_showTooltipsWin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:showTooltipsWin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GObject* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->showTooltipsWin(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRoot_showWindow(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:showWindow";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::Window* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->showWindow(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRoot_togglePopup(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:togglePopup";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 3) {
			fairygui::GObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			fairygui::GObject* arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			fairygui::PopupDirection arg2;
			ok &= luaval_to_native(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			cobj->togglePopup(arg0, arg1, arg2);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			fairygui::GObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cobj->togglePopup(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRoot_worldToRoot(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot:worldToRoot";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GRoot*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Vec2 arg0;
		ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->worldToRoot(arg0);
		vec2_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GRoot_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GRoot";
	constexpr auto LUA_FNAME = "fgui.GRoot constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GRoot();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GRoot_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GRoot(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GRoot");
	tolua_cclass(tolua_S, "GRoot", "fgui.GRoot", "fgui.GComponent", nullptr);

	tolua_beginmodule(tolua_S, "GRoot");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GRoot_constructor);
		tolua_function(tolua_S, "bringToFront", lua_cc_fairygui_GRoot_bringToFront);
		tolua_function(tolua_S, "closeAllExceptModals", lua_cc_fairygui_GRoot_closeAllExceptModals);
		tolua_function(tolua_S, "closeAllWindows", lua_cc_fairygui_GRoot_closeAllWindows);
		tolua_function(tolua_S, "closeModalWait", lua_cc_fairygui_GRoot_closeModalWait);
		tolua_function(tolua_S, "getInputProcessor", lua_cc_fairygui_GRoot_getInputProcessor);
		tolua_function(tolua_S, "getModalLayer", lua_cc_fairygui_GRoot_getModalLayer);
		tolua_function(tolua_S, "getModalWaitingPane", lua_cc_fairygui_GRoot_getModalWaitingPane);
		tolua_function(tolua_S, "getPoupPosition", lua_cc_fairygui_GRoot_getPoupPosition);
		tolua_function(tolua_S, "getSoundVolumeScale", lua_cc_fairygui_GRoot_getSoundVolumeScale);
		tolua_function(tolua_S, "getTopWindow", lua_cc_fairygui_GRoot_getTopWindow);
		tolua_function(tolua_S, "getTouchPosition", lua_cc_fairygui_GRoot_getTouchPosition);
		tolua_function(tolua_S, "getTouchTarget", lua_cc_fairygui_GRoot_getTouchTarget);
		tolua_function(tolua_S, "hasAnyPopup", lua_cc_fairygui_GRoot_hasAnyPopup);
		tolua_function(tolua_S, "hasModalWindow", lua_cc_fairygui_GRoot_hasModalWindow);
		tolua_function(tolua_S, "hidePopup", lua_cc_fairygui_GRoot_hidePopup);
		tolua_function(tolua_S, "hideTooltips", lua_cc_fairygui_GRoot_hideTooltips);
		tolua_function(tolua_S, "hideWindow", lua_cc_fairygui_GRoot_hideWindow);
		tolua_function(tolua_S, "hideWindowImmediately", lua_cc_fairygui_GRoot_hideWindowImmediately);
		tolua_function(tolua_S, "isModalWaiting", lua_cc_fairygui_GRoot_isModalWaiting);
		tolua_function(tolua_S, "isSoundEnabled", lua_cc_fairygui_GRoot_isSoundEnabled);
		tolua_function(tolua_S, "playSound", lua_cc_fairygui_GRoot_playSound);
		tolua_function(tolua_S, "rootToWorld", lua_cc_fairygui_GRoot_rootToWorld);
		tolua_function(tolua_S, "setSoundEnabled", lua_cc_fairygui_GRoot_setSoundEnabled);
		tolua_function(tolua_S, "setSoundVolumeScale", lua_cc_fairygui_GRoot_setSoundVolumeScale);
		tolua_function(tolua_S, "showModalWait", lua_cc_fairygui_GRoot_showModalWait);
		tolua_function(tolua_S, "showPopup", lua_cc_fairygui_GRoot_showPopup);
		tolua_function(tolua_S, "showTooltips", lua_cc_fairygui_GRoot_showTooltips);
		tolua_function(tolua_S, "showTooltipsWin", lua_cc_fairygui_GRoot_showTooltipsWin);
		tolua_function(tolua_S, "showWindow", lua_cc_fairygui_GRoot_showWindow);
		tolua_function(tolua_S, "togglePopup", lua_cc_fairygui_GRoot_togglePopup);
		tolua_function(tolua_S, "worldToRoot", lua_cc_fairygui_GRoot_worldToRoot);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GRoot_create);
		tolua_function(tolua_S, "getInstance", lua_cc_fairygui_GRoot_getInstance);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GRoot).name();
	g_luaType[typeName] = "fgui.GRoot";
	g_typeCast["GRoot"] = "fgui.GRoot";
	return 1;
}

int lua_cc_fairygui_PopupMenu_addItem(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:addItem";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::function<void (fairygui::EventContext *)> arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		int handler3 = query_luafunction_handler(tolua_S, 3, LUA_FNAME);
		ok &= handler3 != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->addItem(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_PopupMenu_addItemAt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:addItemAt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		std::string arg0;
		int arg1;
		std::function<void (fairygui::EventContext *)> arg2;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 4, &arg2, LUA_FNAME);
		int handler4 = query_luafunction_handler(tolua_S, 4, LUA_FNAME);
		ok &= handler4 != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->addItemAt(arg0, arg1, arg2);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_cc_fairygui_PopupMenu_addSeperator(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:addSeperator";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->addSeperator();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_PopupMenu_clearItems(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:clearItems";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->clearItems();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_PopupMenu_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 0) {
			auto ret = fairygui::PopupMenu::create();
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (0);
	ok = true;
	do {
		if (argc == 1) {
			std::string arg0;
			ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = fairygui::PopupMenu::create(arg0);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (0);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PopupMenu_getContentPane(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:getContentPane";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getContentPane();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_PopupMenu_getItemCount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:getItemCount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getItemCount();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_PopupMenu_getItemName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:getItemName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getItemName(arg0);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PopupMenu_getList(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:getList";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getList();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_PopupMenu_isItemChecked(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:isItemChecked";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isItemChecked(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PopupMenu_removeItem(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:removeItem";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->removeItem(arg0);
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_PopupMenu_setItemCheckable(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:setItemCheckable";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		bool arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setItemCheckable(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_PopupMenu_setItemChecked(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:setItemChecked";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		bool arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setItemChecked(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_PopupMenu_setItemGrayed(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:setItemGrayed";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		bool arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setItemGrayed(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_PopupMenu_setItemText(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:setItemText";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setItemText(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_PopupMenu_setItemVisible(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:setItemVisible";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		bool arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setItemVisible(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_PopupMenu_show(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu:show";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::PopupMenu*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			fairygui::GObject* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			fairygui::PopupDirection arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			cobj->show(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 0) {
			cobj->show();
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_PopupMenu_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.PopupMenu";
	constexpr auto LUA_FNAME = "fgui.PopupMenu constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::PopupMenu();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_PopupMenu_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_PopupMenu(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.PopupMenu");
	tolua_cclass(tolua_S, "PopupMenu", "fgui.PopupMenu", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "PopupMenu");
		tolua_function(tolua_S, "new", lua_cc_fairygui_PopupMenu_constructor);
		tolua_function(tolua_S, "addItem", lua_cc_fairygui_PopupMenu_addItem);
		tolua_function(tolua_S, "addItemAt", lua_cc_fairygui_PopupMenu_addItemAt);
		tolua_function(tolua_S, "addSeperator", lua_cc_fairygui_PopupMenu_addSeperator);
		tolua_function(tolua_S, "clearItems", lua_cc_fairygui_PopupMenu_clearItems);
		tolua_function(tolua_S, "getContentPane", lua_cc_fairygui_PopupMenu_getContentPane);
		tolua_function(tolua_S, "getItemCount", lua_cc_fairygui_PopupMenu_getItemCount);
		tolua_function(tolua_S, "getItemName", lua_cc_fairygui_PopupMenu_getItemName);
		tolua_function(tolua_S, "getList", lua_cc_fairygui_PopupMenu_getList);
		tolua_function(tolua_S, "isItemChecked", lua_cc_fairygui_PopupMenu_isItemChecked);
		tolua_function(tolua_S, "removeItem", lua_cc_fairygui_PopupMenu_removeItem);
		tolua_function(tolua_S, "setItemCheckable", lua_cc_fairygui_PopupMenu_setItemCheckable);
		tolua_function(tolua_S, "setItemChecked", lua_cc_fairygui_PopupMenu_setItemChecked);
		tolua_function(tolua_S, "setItemGrayed", lua_cc_fairygui_PopupMenu_setItemGrayed);
		tolua_function(tolua_S, "setItemText", lua_cc_fairygui_PopupMenu_setItemText);
		tolua_function(tolua_S, "setItemVisible", lua_cc_fairygui_PopupMenu_setItemVisible);
		tolua_function(tolua_S, "show", lua_cc_fairygui_PopupMenu_show);
		tolua_function(tolua_S, "create", lua_cc_fairygui_PopupMenu_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::PopupMenu).name();
	g_luaType[typeName] = "fgui.PopupMenu";
	g_typeCast["PopupMenu"] = "fgui.PopupMenu";
	return 1;
}

int lua_cc_fairygui_UIObjectFactory_newObject(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIObjectFactory";
	constexpr auto LUA_FNAME = "fgui.UIObjectFactory:newObject";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 1) {
			fairygui::ObjectType arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = fairygui::UIObjectFactory::newObject(arg0);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (0);
	ok = true;
	do {
		if (argc == 1) {
			fairygui::PackageItem* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = fairygui::UIObjectFactory::newObject(arg0);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (0);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIObjectFactory_setLoaderExtension(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIObjectFactory";
	constexpr auto LUA_FNAME = "fgui.UIObjectFactory:setLoaderExtension";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::function<fairygui::GLoader * ()> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		int handler2 = query_luafunction_handler(tolua_S, 2, LUA_FNAME);
		ok &= handler2 != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		fairygui::UIObjectFactory::setLoaderExtension(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_UIObjectFactory_setPackageItemExtension(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.UIObjectFactory";
	constexpr auto LUA_FNAME = "fgui.UIObjectFactory:setPackageItemExtension";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		std::string arg0;
		std::function<fairygui::GComponent * ()> arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		int handler3 = query_luafunction_handler(tolua_S, 3, LUA_FNAME);
		ok &= handler3 != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		fairygui::UIObjectFactory::setPackageItemExtension(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
static int lua_cc_fairygui_UIObjectFactory_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_UIObjectFactory(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.UIObjectFactory");
	tolua_cclass(tolua_S, "UIObjectFactory", "fgui.UIObjectFactory", "", nullptr);

	tolua_beginmodule(tolua_S, "UIObjectFactory");
		tolua_function(tolua_S, "newObject", lua_cc_fairygui_UIObjectFactory_newObject);
		tolua_function(tolua_S, "setLoaderExtension", lua_cc_fairygui_UIObjectFactory_setLoaderExtension);
		tolua_function(tolua_S, "setPackageItemExtension", lua_cc_fairygui_UIObjectFactory_setPackageItemExtension);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::UIObjectFactory).name();
	g_luaType[typeName] = "fgui.UIObjectFactory";
	g_typeCast["UIObjectFactory"] = "fgui.UIObjectFactory";
	return 1;
}

int lua_cc_fairygui_DragDropManager_cancel(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.DragDropManager";
	constexpr auto LUA_FNAME = "fgui.DragDropManager:cancel";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::DragDropManager*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->cancel();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_DragDropManager_getAgent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.DragDropManager";
	constexpr auto LUA_FNAME = "fgui.DragDropManager:getAgent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::DragDropManager*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getAgent();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_DragDropManager_getInstance(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.DragDropManager";
	constexpr auto LUA_FNAME = "fgui.DragDropManager:getInstance";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::DragDropManager::getInstance();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_DragDropManager_isDragging(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.DragDropManager";
	constexpr auto LUA_FNAME = "fgui.DragDropManager:isDragging";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::DragDropManager*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isDragging();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_DragDropManager_startDrag(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.DragDropManager";
	constexpr auto LUA_FNAME = "fgui.DragDropManager:startDrag";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::DragDropManager*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->startDrag(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		std::string arg0;
		cocos2d::Value arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_ccvalue(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->startDrag(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 3) {
		std::string arg0;
		cocos2d::Value arg1;
		int arg2;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_ccvalue(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->startDrag(arg0, arg1, arg2);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 3");
}
int lua_cc_fairygui_DragDropManager_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.DragDropManager";
	constexpr auto LUA_FNAME = "fgui.DragDropManager constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::DragDropManager();
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_DragDropManager_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_DragDropManager(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.DragDropManager");
	tolua_cclass(tolua_S, "DragDropManager", "fgui.DragDropManager", "", nullptr);

	tolua_beginmodule(tolua_S, "DragDropManager");
		tolua_function(tolua_S, "new", lua_cc_fairygui_DragDropManager_constructor);
		tolua_function(tolua_S, "cancel", lua_cc_fairygui_DragDropManager_cancel);
		tolua_function(tolua_S, "getAgent", lua_cc_fairygui_DragDropManager_getAgent);
		tolua_function(tolua_S, "isDragging", lua_cc_fairygui_DragDropManager_isDragging);
		tolua_function(tolua_S, "startDrag", lua_cc_fairygui_DragDropManager_startDrag);
		tolua_function(tolua_S, "getInstance", lua_cc_fairygui_DragDropManager_getInstance);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::DragDropManager).name();
	g_luaType[typeName] = "fgui.DragDropManager";
	g_typeCast["DragDropManager"] = "fgui.DragDropManager";
	return 1;
}

int lua_register_cc_fairygui_TweenPropType(lua_State* tolua_S)
{

	tolua_module(tolua_S, "TweenPropType", 0);
	tolua_beginmodule(tolua_S,"TweenPropType");
		tolua_constant(tolua_S, "None", (lua_Number)fairygui::TweenPropType::None);
		tolua_constant(tolua_S, "X", (lua_Number)fairygui::TweenPropType::X);
		tolua_constant(tolua_S, "Y", (lua_Number)fairygui::TweenPropType::Y);
		tolua_constant(tolua_S, "Position", (lua_Number)fairygui::TweenPropType::Position);
		tolua_constant(tolua_S, "Width", (lua_Number)fairygui::TweenPropType::Width);
		tolua_constant(tolua_S, "Height", (lua_Number)fairygui::TweenPropType::Height);
		tolua_constant(tolua_S, "Size", (lua_Number)fairygui::TweenPropType::Size);
		tolua_constant(tolua_S, "ScaleX", (lua_Number)fairygui::TweenPropType::ScaleX);
		tolua_constant(tolua_S, "ScaleY", (lua_Number)fairygui::TweenPropType::ScaleY);
		tolua_constant(tolua_S, "Scale", (lua_Number)fairygui::TweenPropType::Scale);
		tolua_constant(tolua_S, "Rotation", (lua_Number)fairygui::TweenPropType::Rotation);
		tolua_constant(tolua_S, "Alpha", (lua_Number)fairygui::TweenPropType::Alpha);
		tolua_constant(tolua_S, "Progress", (lua_Number)fairygui::TweenPropType::Progress);
	tolua_endmodule(tolua_S);

	return 1;
}

int lua_cc_fairygui_GTweener_allCompleted(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:allCompleted";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->allCompleted();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTweener_getDelay(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:getDelay";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getDelay();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTweener_getDuration(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:getDuration";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getDuration();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTweener_getNormalizedTime(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:getNormalizedTime";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getNormalizedTime();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTweener_getRepeat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:getRepeat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getRepeat();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTweener_getTarget(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:getTarget";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getTarget();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTweener_getUserData(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:getUserData";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getUserData();
		ccvalue_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTweener_isCompleted(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:isCompleted";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isCompleted();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTweener_kill(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:kill";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->kill();
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->kill(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0 to 1");
}
int lua_cc_fairygui_GTweener_onComplete(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:onComplete";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::function<void ()> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		int handler2 = query_luafunction_handler(tolua_S, 2, LUA_FNAME);
		ok &= handler2 != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->onComplete(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_onComplete1(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:onComplete1";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::function<void (fairygui::GTweener *)> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		int handler2 = query_luafunction_handler(tolua_S, 2, LUA_FNAME);
		ok &= handler2 != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->onComplete1(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_onStart(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:onStart";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::function<void (fairygui::GTweener *)> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		int handler2 = query_luafunction_handler(tolua_S, 2, LUA_FNAME);
		ok &= handler2 != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->onStart(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_onUpdate(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:onUpdate";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::function<void (fairygui::GTweener *)> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		int handler2 = query_luafunction_handler(tolua_S, 2, LUA_FNAME);
		ok &= handler2 != 0;
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->onUpdate(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_seek(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:seek";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->seek(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_setBreakpoint(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setBreakpoint";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setBreakpoint(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_setDelay(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setDelay";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setDelay(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_setDuration(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setDuration";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setDuration(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_setEase(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setEase";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::EaseType arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setEase(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_setEaseOvershootOrAmplitude(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setEaseOvershootOrAmplitude";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setEaseOvershootOrAmplitude(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_setEasePeriod(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setEasePeriod";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setEasePeriod(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_setPath(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setPath";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::GPath* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setPath(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_setPaused(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setPaused";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setPaused(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_setRepeat(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setRepeat";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setRepeat(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	if (argc == 2) {
		int arg0;
		bool arg1;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setRepeat(arg0, arg1);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_GTweener_setSnapping(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setSnapping";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setSnapping(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_setTarget(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setTarget";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			cocos2d::Ref* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			fairygui::TweenPropType arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->setTarget(arg0, arg1);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	do {
		if (argc == 1) {
			cocos2d::Ref* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = cobj->setTarget(arg0);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (false);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_setTargetAny(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setTargetAny";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		void* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, "LUA_FNAME");
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setTargetAny(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_setTimeScale(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setTimeScale";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setTimeScale(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_setUserData(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener:setUserData";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Value arg0;
		ok &= luaval_to_ccvalue(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->setUserData(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_getstartValue(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener.startValue getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->startValue);
	return 1;
}
int lua_cc_fairygui_GTweener_setstartValue(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener.startValue setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->startValue, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_getendValue(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener.endValue getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->endValue);
	return 1;
}
int lua_cc_fairygui_GTweener_setendValue(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener.endValue setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->endValue, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_getvalue(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener.value getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->value);
	return 1;
}
int lua_cc_fairygui_GTweener_setvalue(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener.value setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->value, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_getdeltaValue(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener.deltaValue getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->deltaValue);
	return 1;
}
int lua_cc_fairygui_GTweener_setdeltaValue(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener.deltaValue setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GTweener*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->deltaValue, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTweener_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTweener";
	constexpr auto LUA_FNAME = "fgui.GTweener constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GTweener();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GTweener_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GTweener(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GTweener");
	tolua_cclass(tolua_S, "GTweener", "fgui.GTweener", "cc.Ref", nullptr);

	tolua_beginmodule(tolua_S, "GTweener");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GTweener_constructor);
		tolua_function(tolua_S, "allCompleted", lua_cc_fairygui_GTweener_allCompleted);
		tolua_function(tolua_S, "getDelay", lua_cc_fairygui_GTweener_getDelay);
		tolua_function(tolua_S, "getDuration", lua_cc_fairygui_GTweener_getDuration);
		tolua_function(tolua_S, "getNormalizedTime", lua_cc_fairygui_GTweener_getNormalizedTime);
		tolua_function(tolua_S, "getRepeat", lua_cc_fairygui_GTweener_getRepeat);
		tolua_function(tolua_S, "getTarget", lua_cc_fairygui_GTweener_getTarget);
		tolua_function(tolua_S, "getUserData", lua_cc_fairygui_GTweener_getUserData);
		tolua_function(tolua_S, "isCompleted", lua_cc_fairygui_GTweener_isCompleted);
		tolua_function(tolua_S, "kill", lua_cc_fairygui_GTweener_kill);
		tolua_function(tolua_S, "onComplete", lua_cc_fairygui_GTweener_onComplete);
		tolua_function(tolua_S, "onComplete1", lua_cc_fairygui_GTweener_onComplete1);
		tolua_function(tolua_S, "onStart", lua_cc_fairygui_GTweener_onStart);
		tolua_function(tolua_S, "onUpdate", lua_cc_fairygui_GTweener_onUpdate);
		tolua_function(tolua_S, "seek", lua_cc_fairygui_GTweener_seek);
		tolua_function(tolua_S, "setBreakpoint", lua_cc_fairygui_GTweener_setBreakpoint);
		tolua_function(tolua_S, "setDelay", lua_cc_fairygui_GTweener_setDelay);
		tolua_function(tolua_S, "setDuration", lua_cc_fairygui_GTweener_setDuration);
		tolua_function(tolua_S, "setEase", lua_cc_fairygui_GTweener_setEase);
		tolua_function(tolua_S, "setEaseOvershootOrAmplitude", lua_cc_fairygui_GTweener_setEaseOvershootOrAmplitude);
		tolua_function(tolua_S, "setEasePeriod", lua_cc_fairygui_GTweener_setEasePeriod);
		tolua_function(tolua_S, "setPath", lua_cc_fairygui_GTweener_setPath);
		tolua_function(tolua_S, "setPaused", lua_cc_fairygui_GTweener_setPaused);
		tolua_function(tolua_S, "setRepeat", lua_cc_fairygui_GTweener_setRepeat);
		tolua_function(tolua_S, "setSnapping", lua_cc_fairygui_GTweener_setSnapping);
		tolua_function(tolua_S, "setTarget", lua_cc_fairygui_GTweener_setTarget);
		tolua_function(tolua_S, "setTargetAny", lua_cc_fairygui_GTweener_setTargetAny);
		tolua_function(tolua_S, "setTimeScale", lua_cc_fairygui_GTweener_setTimeScale);
		tolua_function(tolua_S, "setUserData", lua_cc_fairygui_GTweener_setUserData);
		tolua_variable(tolua_S, "startValue", lua_cc_fairygui_GTweener_getstartValue, lua_cc_fairygui_GTweener_setstartValue);
		tolua_variable(tolua_S, "endValue", lua_cc_fairygui_GTweener_getendValue, lua_cc_fairygui_GTweener_setendValue);
		tolua_variable(tolua_S, "value", lua_cc_fairygui_GTweener_getvalue, lua_cc_fairygui_GTweener_setvalue);
		tolua_variable(tolua_S, "deltaValue", lua_cc_fairygui_GTweener_getdeltaValue, lua_cc_fairygui_GTweener_setdeltaValue);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GTweener).name();
	g_luaType[typeName] = "fgui.GTweener";
	g_typeCast["GTweener"] = "fgui.GTweener";
	return 1;
}

int lua_cc_fairygui_GTween_clean(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTween";
	constexpr auto LUA_FNAME = "fgui.GTween:clean";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		fairygui::GTween::clean();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GTween_delayedCall(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTween";
	constexpr auto LUA_FNAME = "fgui.GTween:delayedCall";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GTween::delayedCall(arg0);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTween_getTween(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTween";
	constexpr auto LUA_FNAME = "fgui.GTween:getTween";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			cocos2d::Ref* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			fairygui::TweenPropType arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			auto ret = fairygui::GTween::getTween(arg0, arg1);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (0);
	ok = true;
	do {
		if (argc == 1) {
			cocos2d::Ref* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = fairygui::GTween::getTween(arg0);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (0);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTween_isTweening(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTween";
	constexpr auto LUA_FNAME = "fgui.GTween:isTweening";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			cocos2d::Ref* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			fairygui::TweenPropType arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			auto ret = fairygui::GTween::isTweening(arg0, arg1);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (0);
	ok = true;
	do {
		if (argc == 1) {
			cocos2d::Ref* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			auto ret = fairygui::GTween::isTweening(arg0);
			tolua_pushboolean(tolua_S, (bool)ret);
			return 1;
		}
	} while (0);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GTween_kill(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTween";
	constexpr auto LUA_FNAME = "fgui.GTween:kill";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 2) {
			cocos2d::Ref* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			bool arg1;
			ok &= luaval_to_boolean(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			fairygui::GTween::kill(arg0, arg1);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (0);
	ok = true;
	do {
		if (argc == 1) {
			cocos2d::Ref* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			fairygui::GTween::kill(arg0);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (0);
	ok = true;
	do {
		if (argc == 3) {
			cocos2d::Ref* arg0;
			ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			fairygui::TweenPropType arg1;
			ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			bool arg2;
			ok &= luaval_to_boolean(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			fairygui::GTween::kill(arg0, arg1, arg2);
			lua_settop(tolua_S, 1);
			return 1;
		}
	} while (0);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_cc_fairygui_GTween_shake(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTween";
	constexpr auto LUA_FNAME = "fgui.GTween:shake";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		cocos2d::Vec2 arg0;
		double arg1;
		double arg2;
		ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GTween::shake(arg0, arg1, arg2);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_cc_fairygui_GTween_to(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTween";
	constexpr auto LUA_FNAME = "fgui.GTween:to";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	do {
		if (argc == 3) {
			cocos2d::Vec2 arg0;
			ok &= luaval_to_vec2(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cocos2d::Vec2 arg1;
			ok &= luaval_to_vec2(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			double arg2;
			ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			auto ret = fairygui::GTween::to(arg0, arg1, arg2);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (0);
	ok = true;
	do {
		if (argc == 3) {
			double arg0;
			ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			double arg1;
			ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			double arg2;
			ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			auto ret = fairygui::GTween::to(arg0, arg1, arg2);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (0);
	ok = true;
	do {
		if (argc == 3) {
			cocos2d::Vec3 arg0;
			ok &= luaval_to_vec3(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cocos2d::Vec3 arg1;
			ok &= luaval_to_vec3(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			double arg2;
			ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			auto ret = fairygui::GTween::to(arg0, arg1, arg2);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (0);
	ok = true;
	do {
		if (argc == 3) {
			cocos2d::Vec4 arg0;
			ok &= luaval_to_vec4(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cocos2d::Vec4 arg1;
			ok &= luaval_to_vec4(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			double arg2;
			ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			auto ret = fairygui::GTween::to(arg0, arg1, arg2);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (0);
	ok = true;
	do {
		if (argc == 3) {
			cocos2d::Color4B arg0;
			ok &=luaval_to_color4b(tolua_S, 2, &arg0, LUA_FNAME);
			if (!ok) { break; }
			cocos2d::Color4B arg1;
			ok &=luaval_to_color4b(tolua_S, 3, &arg1, LUA_FNAME);
			if (!ok) { break; }
			double arg2;
			ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
			if (!ok) { break; }
			auto ret = fairygui::GTween::to(arg0, arg1, arg2);
			native_to_luaval(tolua_S, ret);
			return 1;
		}
	} while (0);
	ok = true;
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
int lua_cc_fairygui_GTween_toDouble(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GTween";
	constexpr auto LUA_FNAME = "fgui.GTween:toDouble";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 3) {
		double arg0;
		double arg1;
		double arg2;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GTween::toDouble(arg0, arg1, arg2);
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "3");
}
static int lua_cc_fairygui_GTween_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GTween(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GTween");
	tolua_cclass(tolua_S, "GTween", "fgui.GTween", "", nullptr);

	tolua_beginmodule(tolua_S, "GTween");
		tolua_function(tolua_S, "clean", lua_cc_fairygui_GTween_clean);
		tolua_function(tolua_S, "delayedCall", lua_cc_fairygui_GTween_delayedCall);
		tolua_function(tolua_S, "getTween", lua_cc_fairygui_GTween_getTween);
		tolua_function(tolua_S, "isTweening", lua_cc_fairygui_GTween_isTweening);
		tolua_function(tolua_S, "kill", lua_cc_fairygui_GTween_kill);
		tolua_function(tolua_S, "shake", lua_cc_fairygui_GTween_shake);
		tolua_function(tolua_S, "to", lua_cc_fairygui_GTween_to);
		tolua_function(tolua_S, "toDouble", lua_cc_fairygui_GTween_toDouble);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GTween).name();
	g_luaType[typeName] = "fgui.GTween";
	g_typeCast["GTween"] = "fgui.GTween";
	return 1;
}

int lua_cc_fairygui_GLoader3D_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::GLoader3D::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_getAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:getAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getAlign();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_getAnimationName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:getAnimationName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getAnimationName();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_getAutoSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:getAutoSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getAutoSize();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_getColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:getColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getColor();
		color3b_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_getContent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:getContent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getContent();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_getFill(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:getFill";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFill();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_getFrame(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:getFrame";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFrame();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_getLoop(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:getLoop";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getLoop();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_getSkinName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:getSkinName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSkinName();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_getURL(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:getURL";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getURL();
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_getVerticalAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:getVerticalAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getVerticalAlign();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_isPlaying(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:isPlaying";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isPlaying();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_isShrinkOnly(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:isShrinkOnly";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isShrinkOnly();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GLoader3D_setAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:setAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::TextHAlignment arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAlign(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader3D_setAnimationName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:setAnimationName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAnimationName(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader3D_setAutoSize(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:setAutoSize";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setAutoSize(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader3D_setColor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:setColor";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Color3B arg0;
		ok &= luaval_to_color3b(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setColor(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader3D_setContent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:setContent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Node* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setContent(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader3D_setFill(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:setFill";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::LoaderFillType arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFill(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader3D_setFrame(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:setFrame";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFrame(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader3D_setLoop(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:setLoop";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setLoop(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader3D_setPlaying(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:setPlaying";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setPlaying(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader3D_setShrinkOnly(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:setShrinkOnly";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setShrinkOnly(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader3D_setSkinName(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:setSkinName";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setSkinName(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader3D_setURL(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:setURL";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setURL(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader3D_setVerticalAlign(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D:setVerticalAlign";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GLoader3D*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::TextVAlignment arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setVerticalAlign(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GLoader3D_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GLoader3D";
	constexpr auto LUA_FNAME = "fgui.GLoader3D constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GLoader3D();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GLoader3D_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GLoader3D(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GLoader3D");
	tolua_cclass(tolua_S, "GLoader3D", "fgui.GLoader3D", "fgui.GObject", nullptr);

	tolua_beginmodule(tolua_S, "GLoader3D");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GLoader3D_constructor);
		tolua_function(tolua_S, "getAlign", lua_cc_fairygui_GLoader3D_getAlign);
		tolua_function(tolua_S, "getAnimationName", lua_cc_fairygui_GLoader3D_getAnimationName);
		tolua_function(tolua_S, "getAutoSize", lua_cc_fairygui_GLoader3D_getAutoSize);
		tolua_function(tolua_S, "getColor", lua_cc_fairygui_GLoader3D_getColor);
		tolua_function(tolua_S, "getContent", lua_cc_fairygui_GLoader3D_getContent);
		tolua_function(tolua_S, "getFill", lua_cc_fairygui_GLoader3D_getFill);
		tolua_function(tolua_S, "getFrame", lua_cc_fairygui_GLoader3D_getFrame);
		tolua_function(tolua_S, "getLoop", lua_cc_fairygui_GLoader3D_getLoop);
		tolua_function(tolua_S, "getSkinName", lua_cc_fairygui_GLoader3D_getSkinName);
		tolua_function(tolua_S, "getURL", lua_cc_fairygui_GLoader3D_getURL);
		tolua_function(tolua_S, "getVerticalAlign", lua_cc_fairygui_GLoader3D_getVerticalAlign);
		tolua_function(tolua_S, "isPlaying", lua_cc_fairygui_GLoader3D_isPlaying);
		tolua_function(tolua_S, "isShrinkOnly", lua_cc_fairygui_GLoader3D_isShrinkOnly);
		tolua_function(tolua_S, "setAlign", lua_cc_fairygui_GLoader3D_setAlign);
		tolua_function(tolua_S, "setAnimationName", lua_cc_fairygui_GLoader3D_setAnimationName);
		tolua_function(tolua_S, "setAutoSize", lua_cc_fairygui_GLoader3D_setAutoSize);
		tolua_function(tolua_S, "setColor", lua_cc_fairygui_GLoader3D_setColor);
		tolua_function(tolua_S, "setContent", lua_cc_fairygui_GLoader3D_setContent);
		tolua_function(tolua_S, "setFill", lua_cc_fairygui_GLoader3D_setFill);
		tolua_function(tolua_S, "setFrame", lua_cc_fairygui_GLoader3D_setFrame);
		tolua_function(tolua_S, "setLoop", lua_cc_fairygui_GLoader3D_setLoop);
		tolua_function(tolua_S, "setPlaying", lua_cc_fairygui_GLoader3D_setPlaying);
		tolua_function(tolua_S, "setShrinkOnly", lua_cc_fairygui_GLoader3D_setShrinkOnly);
		tolua_function(tolua_S, "setSkinName", lua_cc_fairygui_GLoader3D_setSkinName);
		tolua_function(tolua_S, "setURL", lua_cc_fairygui_GLoader3D_setURL);
		tolua_function(tolua_S, "setVerticalAlign", lua_cc_fairygui_GLoader3D_setVerticalAlign);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GLoader3D_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GLoader3D).name();
	g_luaType[typeName] = "fgui.GLoader3D";
	g_typeCast["GLoader3D"] = "fgui.GLoader3D";
	return 1;
}

int lua_cc_fairygui_EaseManager_evaluate(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.EaseManager";
	constexpr auto LUA_FNAME = "fgui.EaseManager:evaluate";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 5) {
		fairygui::EaseType arg0;
		double arg1;
		double arg2;
		double arg3;
		double arg4;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 6, &arg4, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::EaseManager::evaluate(arg0, arg1, arg2, arg3, arg4);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "5");
}
static int lua_cc_fairygui_EaseManager_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_EaseManager(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.EaseManager");
	tolua_cclass(tolua_S, "EaseManager", "fgui.EaseManager", "", nullptr);

	tolua_beginmodule(tolua_S, "EaseManager");
		tolua_function(tolua_S, "evaluate", lua_cc_fairygui_EaseManager_evaluate);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::EaseManager).name();
	g_luaType[typeName] = "fgui.EaseManager";
	g_typeCast["EaseManager"] = "fgui.EaseManager";
	return 1;
}

int lua_cc_fairygui_GPath_clear(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GPath";
	constexpr auto LUA_FNAME = "fgui.GPath:clear";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GPath*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->clear();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GPath_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GPath";
	constexpr auto LUA_FNAME = "fgui.GPath:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GPath*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::GPathPoint* arg0;
		int arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, "LUA_FNAME");
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->create(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_GPath_getAllPoints(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GPath";
	constexpr auto LUA_FNAME = "fgui.GPath:getAllPoints";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GPath*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::vector<cocos2d::Vec3> arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->getAllPoints(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 2) {
		std::vector<cocos2d::Vec3> arg0;
		double arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->getAllPoints(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_GPath_getLength(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GPath";
	constexpr auto LUA_FNAME = "fgui.GPath:getLength";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GPath*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getLength();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GPath_getPointAt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GPath";
	constexpr auto LUA_FNAME = "fgui.GPath:getPointAt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GPath*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getPointAt(arg0);
		vec3_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GPath_getPointsInSegment(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GPath";
	constexpr auto LUA_FNAME = "fgui.GPath:getPointsInSegment";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GPath*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 4) {
		int arg0;
		double arg1;
		double arg2;
		std::vector<cocos2d::Vec3> arg3;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 5, &arg3, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->getPointsInSegment(arg0, arg1, arg2, arg3);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 5) {
		int arg0;
		double arg1;
		double arg2;
		std::vector<cocos2d::Vec3> arg3;
		std::vector<float>* arg4;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 6, &arg4, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->getPointsInSegment(arg0, arg1, arg2, arg3, arg4);
		lua_settop(tolua_S, 1);
		return 1;
	}
	if (argc == 6) {
		int arg0;
		double arg1;
		double arg2;
		std::vector<cocos2d::Vec3> arg3;
		std::vector<float>* arg4;
		double arg5;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 3, &arg1, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 4, &arg2, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 5, &arg3, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 6, &arg4, LUA_FNAME);
		ok &= luaval_to_number(tolua_S, 7, &arg5, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->getPointsInSegment(arg0, arg1, arg2, arg3, arg4, arg5);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "4 to 6");
}
int lua_cc_fairygui_GPath_getSegmentCount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GPath";
	constexpr auto LUA_FNAME = "fgui.GPath:getSegmentCount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GPath*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSegmentCount();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_GPath_getSegmentLength(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GPath";
	constexpr auto LUA_FNAME = "fgui.GPath:getSegmentLength";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::GPath*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		int arg0;
		ok &= luaval_to_int32(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getSegmentLength(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_GPath_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.GPath";
	constexpr auto LUA_FNAME = "fgui.GPath constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::GPath();
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_GPath_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_GPath(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.GPath");
	tolua_cclass(tolua_S, "GPath", "fgui.GPath", "", nullptr);

	tolua_beginmodule(tolua_S, "GPath");
		tolua_function(tolua_S, "new", lua_cc_fairygui_GPath_constructor);
		tolua_function(tolua_S, "clear", lua_cc_fairygui_GPath_clear);
		tolua_function(tolua_S, "create", lua_cc_fairygui_GPath_create);
		tolua_function(tolua_S, "getAllPoints", lua_cc_fairygui_GPath_getAllPoints);
		tolua_function(tolua_S, "getLength", lua_cc_fairygui_GPath_getLength);
		tolua_function(tolua_S, "getPointAt", lua_cc_fairygui_GPath_getPointAt);
		tolua_function(tolua_S, "getPointsInSegment", lua_cc_fairygui_GPath_getPointsInSegment);
		tolua_function(tolua_S, "getSegmentCount", lua_cc_fairygui_GPath_getSegmentCount);
		tolua_function(tolua_S, "getSegmentLength", lua_cc_fairygui_GPath_getSegmentLength);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::GPath).name();
	g_luaType[typeName] = "fgui.GPath";
	g_typeCast["GPath"] = "fgui.GPath";
	return 1;
}

int lua_cc_fairygui_FUISprite_clearContent(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:clearContent";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUISprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->clearContent();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUISprite_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = fairygui::FUISprite::create();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUISprite_getFillAmount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:getFillAmount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUISprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFillAmount();
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUISprite_getFillMethod(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:getFillMethod";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUISprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFillMethod();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUISprite_getFillOrigin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:getFillOrigin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUISprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getFillOrigin();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUISprite_isFillClockwise(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:isFillClockwise";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUISprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isFillClockwise();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUISprite_isScaleByTile(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:isScaleByTile";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUISprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isScaleByTile();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_FUISprite_setFillAmount(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:setFillAmount";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUISprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		double arg0;
		ok &= luaval_to_number(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFillAmount(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUISprite_setFillClockwise(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:setFillClockwise";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUISprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFillClockwise(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUISprite_setFillMethod(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:setFillMethod";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUISprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::FillMethod arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFillMethod(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUISprite_setFillOrigin(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:setFillOrigin";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUISprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::FillOrigin arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setFillOrigin(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUISprite_setGrayed(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:setGrayed";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUISprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setGrayed(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUISprite_setScale9Grid(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:setScale9Grid";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUISprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		cocos2d::Rect* arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setScale9Grid(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUISprite_setScaleByTile(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite:setScaleByTile";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::FUISprite*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		bool arg0;
		ok &= luaval_to_boolean(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->setScaleByTile(arg0);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_FUISprite_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.FUISprite";
	constexpr auto LUA_FNAME = "fgui.FUISprite constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::FUISprite();
		cobj->autorelease();
		int ID = (int)cobj->_ID ;
		int* luaID = &cobj->_luaID ;
		toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj, LUA_OBJ_TYPE);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_FUISprite_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_FUISprite(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.FUISprite");
	tolua_cclass(tolua_S, "FUISprite", "fgui.FUISprite", "cc.Sprite", nullptr);

	tolua_beginmodule(tolua_S, "FUISprite");
		tolua_function(tolua_S, "new", lua_cc_fairygui_FUISprite_constructor);
		tolua_function(tolua_S, "clearContent", lua_cc_fairygui_FUISprite_clearContent);
		tolua_function(tolua_S, "getFillAmount", lua_cc_fairygui_FUISprite_getFillAmount);
		tolua_function(tolua_S, "getFillMethod", lua_cc_fairygui_FUISprite_getFillMethod);
		tolua_function(tolua_S, "getFillOrigin", lua_cc_fairygui_FUISprite_getFillOrigin);
		tolua_function(tolua_S, "isFillClockwise", lua_cc_fairygui_FUISprite_isFillClockwise);
		tolua_function(tolua_S, "isScaleByTile", lua_cc_fairygui_FUISprite_isScaleByTile);
		tolua_function(tolua_S, "setFillAmount", lua_cc_fairygui_FUISprite_setFillAmount);
		tolua_function(tolua_S, "setFillClockwise", lua_cc_fairygui_FUISprite_setFillClockwise);
		tolua_function(tolua_S, "setFillMethod", lua_cc_fairygui_FUISprite_setFillMethod);
		tolua_function(tolua_S, "setFillOrigin", lua_cc_fairygui_FUISprite_setFillOrigin);
		tolua_function(tolua_S, "setGrayed", lua_cc_fairygui_FUISprite_setGrayed);
		tolua_function(tolua_S, "setScale9Grid", lua_cc_fairygui_FUISprite_setScale9Grid);
		tolua_function(tolua_S, "setScaleByTile", lua_cc_fairygui_FUISprite_setScaleByTile);
		tolua_function(tolua_S, "create", lua_cc_fairygui_FUISprite_create);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::FUISprite).name();
	g_luaType[typeName] = "fgui.FUISprite";
	g_typeCast["FUISprite"] = "fgui.FUISprite";
	return 1;
}

int lua_cc_fairygui_HtmlElement_getArray(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement:getArray";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getArray(arg0);
		ccvaluevector_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_HtmlElement_getInt(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement:getInt";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getInt(arg0);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	if (argc == 2) {
		std::string arg0;
		int arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_int32(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getInt(arg0, arg1);
		tolua_pushnumber(tolua_S, (lua_Number)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_HtmlElement_getString(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement:getString";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		std::string arg0;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getString(arg0);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	if (argc == 2) {
		std::string arg0;
		std::string arg1;
		ok &= luaval_to_std_string(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_std_string(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getString(arg0, arg1);
		lua_pushlstring(tolua_S, ret.c_str(), ret.length());
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1 to 2");
}
int lua_cc_fairygui_HtmlElement_gettype(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.type getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->type);
	return 1;
}
int lua_cc_fairygui_HtmlElement_settype(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.type setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->type, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_HtmlElement_gettext(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.text getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->text);
	return 1;
}
int lua_cc_fairygui_HtmlElement_settext(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.text setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->text, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_HtmlElement_getformat(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.format getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->format);
	return 1;
}
int lua_cc_fairygui_HtmlElement_setformat(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.format setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->format, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_HtmlElement_getlink(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.link getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->link);
	return 1;
}
int lua_cc_fairygui_HtmlElement_setlink(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.link setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->link, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_HtmlElement_getobj(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.obj getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->obj);
	return 1;
}
int lua_cc_fairygui_HtmlElement_setobj(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.obj setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->obj, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_HtmlElement_getspace(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.space getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->space);
	return 1;
}
int lua_cc_fairygui_HtmlElement_setspace(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.space setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->space, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_HtmlElement_getattrs(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.attrs getter";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	native_to_luaval(tolua_S, cobj->attrs);
	return 1;
}
int lua_cc_fairygui_HtmlElement_setattrs(lua_State* tolua_S)
{
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement.attrs setter";
	bool ok = true;
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlElement*)tolua_tousertype(tolua_S, 1, 0);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (1 == argc) {
		ok &= luaval_to_native(tolua_S, 2, &cobj->attrs, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		return 0;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}
int lua_cc_fairygui_HtmlElement_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlElement";
	constexpr auto LUA_FNAME = "fgui.HtmlElement constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 1) {
		fairygui::HtmlElement::Type arg0;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::HtmlElement(arg0);
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}

static int lua_cc_fairygui_HtmlElement_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_HtmlElement(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.HtmlElement");
	tolua_cclass(tolua_S, "HtmlElement", "fgui.HtmlElement", "", nullptr);

	tolua_beginmodule(tolua_S, "HtmlElement");
		tolua_function(tolua_S, "new", lua_cc_fairygui_HtmlElement_constructor);
		tolua_function(tolua_S, "getArray", lua_cc_fairygui_HtmlElement_getArray);
		tolua_function(tolua_S, "getInt", lua_cc_fairygui_HtmlElement_getInt);
		tolua_function(tolua_S, "getString", lua_cc_fairygui_HtmlElement_getString);
		tolua_variable(tolua_S, "type", lua_cc_fairygui_HtmlElement_gettype, lua_cc_fairygui_HtmlElement_settype);
		tolua_variable(tolua_S, "text", lua_cc_fairygui_HtmlElement_gettext, lua_cc_fairygui_HtmlElement_settext);
		tolua_variable(tolua_S, "format", lua_cc_fairygui_HtmlElement_getformat, lua_cc_fairygui_HtmlElement_setformat);
		tolua_variable(tolua_S, "link", lua_cc_fairygui_HtmlElement_getlink, lua_cc_fairygui_HtmlElement_setlink);
		tolua_variable(tolua_S, "obj", lua_cc_fairygui_HtmlElement_getobj, lua_cc_fairygui_HtmlElement_setobj);
		tolua_variable(tolua_S, "space", lua_cc_fairygui_HtmlElement_getspace, lua_cc_fairygui_HtmlElement_setspace);
		tolua_variable(tolua_S, "attrs", lua_cc_fairygui_HtmlElement_getattrs, lua_cc_fairygui_HtmlElement_setattrs);
		{
			tolua_module(tolua_S, "Type", 0);
			tolua_beginmodule(tolua_S, "Type");
			{
				tolua_constant(tolua_S, "TEXT", (lua_Number)fairygui::HtmlElement::Type::TEXT);
				tolua_constant(tolua_S, "IMAGE", (lua_Number)fairygui::HtmlElement::Type::IMAGE);
				tolua_constant(tolua_S, "LINK", (lua_Number)fairygui::HtmlElement::Type::LINK);
				tolua_constant(tolua_S, "INPUT", (lua_Number)fairygui::HtmlElement::Type::INPUT);
				tolua_constant(tolua_S, "SELECT", (lua_Number)fairygui::HtmlElement::Type::SELECT);
				tolua_constant(tolua_S, "OBJECT", (lua_Number)fairygui::HtmlElement::Type::OBJECT);
			}
			tolua_endmodule(tolua_S);
		}
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::HtmlElement).name();
	g_luaType[typeName] = "fgui.HtmlElement";
	g_typeCast["HtmlElement"] = "fgui.HtmlElement";
	return 1;
}

int lua_cc_fairygui_HtmlObject_create(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlObject";
	constexpr auto LUA_FNAME = "fgui.HtmlObject:create";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 2) {
		fairygui::FUIRichText* arg0;
		fairygui::HtmlElement* arg1;
		ok &= luaval_to_native(tolua_S, 2, &arg0, LUA_FNAME);
		ok &= luaval_to_native(tolua_S, 3, &arg1, LUA_FNAME);
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->create(arg0, arg1);
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}
int lua_cc_fairygui_HtmlObject_destroy(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlObject";
	constexpr auto LUA_FNAME = "fgui.HtmlObject:destroy";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		cobj->destroy();
		lua_settop(tolua_S, 1);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_HtmlObject_getElement(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlObject";
	constexpr auto LUA_FNAME = "fgui.HtmlObject:getElement";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getElement();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_HtmlObject_getUI(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlObject";
	constexpr auto LUA_FNAME = "fgui.HtmlObject:getUI";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->getUI();
		native_to_luaval(tolua_S, ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_HtmlObject_isHidden(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlObject";
	constexpr auto LUA_FNAME = "fgui.HtmlObject:isHidden";
	LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
	auto cobj = (fairygui::HtmlObject*)tolua_tousertype(tolua_S, 1, nullptr);
	LUA_CHECK_COBJ(tolua_S, cobj, LUA_FNAME);
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto ret = cobj->isHidden();
		tolua_pushboolean(tolua_S, (bool)ret);
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}
int lua_cc_fairygui_HtmlObject_constructor(lua_State* tolua_S)
{
	bool ok = true;
	constexpr auto LUA_OBJ_TYPE = "fgui.HtmlObject";
	constexpr auto LUA_FNAME = "fgui.HtmlObject constructor";
	const int argc = lua_gettop(tolua_S) - 1;
	if (argc == 0) {
		LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
		auto cobj = new fairygui::HtmlObject();
		tolua_pushusertype(tolua_S, (void*)cobj, LUA_OBJ_TYPE);
		tolua_register_gc(tolua_S, lua_gettop(tolua_S));
		return 1;
	}
	LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int lua_cc_fairygui_HtmlObject_finalize(lua_State* tolua_S)
{
	return 0;
}

int lua_register_cc_fairygui_HtmlObject(lua_State* tolua_S)
{
	tolua_usertype(tolua_S, "fgui.HtmlObject");
	tolua_cclass(tolua_S, "HtmlObject", "fgui.HtmlObject", "", nullptr);

	tolua_beginmodule(tolua_S, "HtmlObject");
		tolua_function(tolua_S, "new", lua_cc_fairygui_HtmlObject_constructor);
		tolua_function(tolua_S, "create", lua_cc_fairygui_HtmlObject_create);
		tolua_function(tolua_S, "destroy", lua_cc_fairygui_HtmlObject_destroy);
		tolua_function(tolua_S, "getElement", lua_cc_fairygui_HtmlObject_getElement);
		tolua_function(tolua_S, "getUI", lua_cc_fairygui_HtmlObject_getUI);
		tolua_function(tolua_S, "isHidden", lua_cc_fairygui_HtmlObject_isHidden);
	tolua_endmodule(tolua_S);
	std::string typeName = typeid(fairygui::HtmlObject).name();
	g_luaType[typeName] = "fgui.HtmlObject";
	g_typeCast["HtmlObject"] = "fgui.HtmlObject";
	return 1;
}

int register_all_cc_fairygui(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	tolua_module(tolua_S, "fgui", 0);
	tolua_beginmodule(tolua_S, "fgui");

	lua_register_cc_fairygui_UIEventDispatcher(tolua_S);
	lua_register_cc_fairygui_GObject(tolua_S);
	lua_register_cc_fairygui_GComponent(tolua_S);
	lua_register_cc_fairygui_GList(tolua_S);
	lua_register_cc_fairygui_GTree(tolua_S);
	lua_register_cc_fairygui_FUIInput(tolua_S);
	lua_register_cc_fairygui_GComboBox(tolua_S);
	lua_register_cc_fairygui_IHitTest(tolua_S);
	lua_register_cc_fairygui_FUISprite(tolua_S);
	lua_register_cc_fairygui_ListSelectionMode(tolua_S);
	lua_register_cc_fairygui_ObjectType(tolua_S);
	lua_register_cc_fairygui_ObjectPropID(tolua_S);
	lua_register_cc_fairygui_GTween(tolua_S);
	lua_register_cc_fairygui_FUILabel(tolua_S);
	lua_register_cc_fairygui_GLoader(tolua_S);
	lua_register_cc_fairygui_GearBase(tolua_S);
	lua_register_cc_fairygui_IUISource(tolua_S);
	lua_register_cc_fairygui_PopupDirection(tolua_S);
	lua_register_cc_fairygui_PopupMenu(tolua_S);
	lua_register_cc_fairygui_TextFormat(tolua_S);
	lua_register_cc_fairygui_UIConfig(tolua_S);
	lua_register_cc_fairygui_GTreeNode(tolua_S);
	lua_register_cc_fairygui_ScrollBarDisplayType(tolua_S);
	lua_register_cc_fairygui_GGraph(tolua_S);
	lua_register_cc_fairygui_InputEvent(tolua_S);
	lua_register_cc_fairygui_UIObjectFactory(tolua_S);
	lua_register_cc_fairygui_RelationType(tolua_S);
	lua_register_cc_fairygui_UIEventType(tolua_S);
	lua_register_cc_fairygui_GSlider(tolua_S);
	lua_register_cc_fairygui_TransitionActionType(tolua_S);
	lua_register_cc_fairygui_EaseManager(tolua_S);
	lua_register_cc_fairygui_HtmlElement(tolua_S);
	lua_register_cc_fairygui_GLoader3D(tolua_S);
	lua_register_cc_fairygui_GImage(tolua_S);
	lua_register_cc_fairygui_GScrollBar(tolua_S);
	lua_register_cc_fairygui_GPath(tolua_S);
	lua_register_cc_fairygui_Relations(tolua_S);
	lua_register_cc_fairygui_PackageItem(tolua_S);
	lua_register_cc_fairygui_GroupLayoutType(tolua_S);
	lua_register_cc_fairygui_EaseType(tolua_S);
	lua_register_cc_fairygui_ButtonMode(tolua_S);
	lua_register_cc_fairygui_GMovieClip(tolua_S);
	lua_register_cc_fairygui_GTextField(tolua_S);
	lua_register_cc_fairygui_GRichTextField(tolua_S);
	lua_register_cc_fairygui_GRoot(tolua_S);
	lua_register_cc_fairygui_FillOrigin(tolua_S);
	lua_register_cc_fairygui_LoaderFillType(tolua_S);
	lua_register_cc_fairygui_GTweener(tolua_S);
	lua_register_cc_fairygui_Transition(tolua_S);
	lua_register_cc_fairygui_PixelHitTestData(tolua_S);
	lua_register_cc_fairygui_GController(tolua_S);
	lua_register_cc_fairygui_GLabel(tolua_S);
	lua_register_cc_fairygui_GTextInput(tolua_S);
	lua_register_cc_fairygui_InputProcessor(tolua_S);
	lua_register_cc_fairygui_ScrollPane(tolua_S);
	lua_register_cc_fairygui_GProgressBar(tolua_S);
	lua_register_cc_fairygui_ChildrenRenderOrder(tolua_S);
	lua_register_cc_fairygui_AutoSizeType(tolua_S);
	lua_register_cc_fairygui_OverflowType(tolua_S);
	lua_register_cc_fairygui_Window(tolua_S);
	lua_register_cc_fairygui_ScrollType(tolua_S);
	lua_register_cc_fairygui_GButton(tolua_S);
	lua_register_cc_fairygui_GGroup(tolua_S);
	lua_register_cc_fairygui_FUIContainer(tolua_S);
	lua_register_cc_fairygui_FillMethod(tolua_S);
	lua_register_cc_fairygui_PixelHitTest(tolua_S);
	lua_register_cc_fairygui_ListLayoutType(tolua_S);
	lua_register_cc_fairygui_FUIRichText(tolua_S);
	lua_register_cc_fairygui_EventContext(tolua_S);
	lua_register_cc_fairygui_UIPackage(tolua_S);
	lua_register_cc_fairygui_FlipType(tolua_S);
	lua_register_cc_fairygui_EventTag(tolua_S);
	lua_register_cc_fairygui_DragDropManager(tolua_S);
	lua_register_cc_fairygui_GBasicTextField(tolua_S);
	lua_register_cc_fairygui_PackageItemType(tolua_S);
	lua_register_cc_fairygui_HtmlObject(tolua_S);
	lua_register_cc_fairygui_RelationItem(tolua_S);
	lua_register_cc_fairygui_ProgressTitleType(tolua_S);
	lua_register_cc_fairygui_TweenPropType(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

