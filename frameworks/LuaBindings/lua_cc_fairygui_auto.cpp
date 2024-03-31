#include "lua_cc_fairygui_auto.hpp"
#include "fairygui/FairyGUI.h"
#include "fairygui/GLoader3D.h"
#include "fairygui/tween/EaseManager.h"
#include "fairygui/tween/GPath.h"
#include "fairygui/display/FUISprite.h"
#include "fairygui/utils/ByteBuffer.h"
#include "fairygui/utils/html/HtmlElement.h"
#include "fairygui/utils/html/HtmlObject.h"
#include "fairygui/utils/html/HtmlParser.h"

int luaReg_fgui_fguiPackageItemType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("PackageItemType");
	LUA_ENUM_ENTRY("IMAGE", fairygui::PackageItemType::IMAGE);
	LUA_ENUM_ENTRY("MOVIECLIP", fairygui::PackageItemType::MOVIECLIP);
	LUA_ENUM_ENTRY("SOUND", fairygui::PackageItemType::SOUND);
	LUA_ENUM_ENTRY("COMPONENT", fairygui::PackageItemType::COMPONENT);
	LUA_ENUM_ENTRY("ATLAS", fairygui::PackageItemType::ATLAS);
	LUA_ENUM_ENTRY("FONT", fairygui::PackageItemType::FONT);
	LUA_ENUM_ENTRY("SWF", fairygui::PackageItemType::SWF);
	LUA_ENUM_ENTRY("MISC", fairygui::PackageItemType::MISC);
	LUA_ENUM_ENTRY("UNKNOWN", fairygui::PackageItemType::UNKNOWN);
	LUA_ENUM_ENTRY("SPINE", fairygui::PackageItemType::SPINE);
	LUA_ENUM_ENTRY("DRAGONBONES", fairygui::PackageItemType::DRAGONBONES);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiObjectType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("ObjectType");
	LUA_ENUM_ENTRY("IMAGE", fairygui::ObjectType::IMAGE);
	LUA_ENUM_ENTRY("MOVIECLIP", fairygui::ObjectType::MOVIECLIP);
	LUA_ENUM_ENTRY("SWF", fairygui::ObjectType::SWF);
	LUA_ENUM_ENTRY("GRAPH", fairygui::ObjectType::GRAPH);
	LUA_ENUM_ENTRY("LOADER", fairygui::ObjectType::LOADER);
	LUA_ENUM_ENTRY("GROUP", fairygui::ObjectType::GROUP);
	LUA_ENUM_ENTRY("TEXT", fairygui::ObjectType::TEXT);
	LUA_ENUM_ENTRY("RICHTEXT", fairygui::ObjectType::RICHTEXT);
	LUA_ENUM_ENTRY("INPUTTEXT", fairygui::ObjectType::INPUTTEXT);
	LUA_ENUM_ENTRY("COMPONENT", fairygui::ObjectType::COMPONENT);
	LUA_ENUM_ENTRY("LIST", fairygui::ObjectType::LIST);
	LUA_ENUM_ENTRY("LABEL", fairygui::ObjectType::LABEL);
	LUA_ENUM_ENTRY("BUTTON", fairygui::ObjectType::BUTTON);
	LUA_ENUM_ENTRY("COMBOBOX", fairygui::ObjectType::COMBOBOX);
	LUA_ENUM_ENTRY("PROGRESSBAR", fairygui::ObjectType::PROGRESSBAR);
	LUA_ENUM_ENTRY("SLIDER", fairygui::ObjectType::SLIDER);
	LUA_ENUM_ENTRY("SCROLLBAR", fairygui::ObjectType::SCROLLBAR);
	LUA_ENUM_ENTRY("TREE", fairygui::ObjectType::TREE);
	LUA_ENUM_ENTRY("LOADER3D", fairygui::ObjectType::LOADER3D);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiButtonMode(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("ButtonMode");
	LUA_ENUM_ENTRY("COMMON", fairygui::ButtonMode::COMMON);
	LUA_ENUM_ENTRY("CHECK", fairygui::ButtonMode::CHECK);
	LUA_ENUM_ENTRY("RADIO", fairygui::ButtonMode::RADIO);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiChildrenRenderOrder(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("ChildrenRenderOrder");
	LUA_ENUM_ENTRY("ASCENT", fairygui::ChildrenRenderOrder::ASCENT);
	LUA_ENUM_ENTRY("DESCENT", fairygui::ChildrenRenderOrder::DESCENT);
	LUA_ENUM_ENTRY("ARCH", fairygui::ChildrenRenderOrder::ARCH);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiOverflowType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("OverflowType");
	LUA_ENUM_ENTRY("VISIBLE", fairygui::OverflowType::VISIBLE);
	LUA_ENUM_ENTRY("HIDDEN", fairygui::OverflowType::HIDDEN);
	LUA_ENUM_ENTRY("SCROLL", fairygui::OverflowType::SCROLL);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiScrollType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("ScrollType");
	LUA_ENUM_ENTRY("HORIZONTAL", fairygui::ScrollType::HORIZONTAL);
	LUA_ENUM_ENTRY("VERTICAL", fairygui::ScrollType::VERTICAL);
	LUA_ENUM_ENTRY("BOTH", fairygui::ScrollType::BOTH);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiScrollBarDisplayType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("ScrollBarDisplayType");
	LUA_ENUM_ENTRY("DEFAULT", fairygui::ScrollBarDisplayType::DEFAULT);
	LUA_ENUM_ENTRY("VISIBLE", fairygui::ScrollBarDisplayType::VISIBLE);
	LUA_ENUM_ENTRY("AUTO", fairygui::ScrollBarDisplayType::AUTO);
	LUA_ENUM_ENTRY("HIDDEN", fairygui::ScrollBarDisplayType::HIDDEN);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiLoaderFillType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("LoaderFillType");
	LUA_ENUM_ENTRY("NONE", fairygui::LoaderFillType::NONE);
	LUA_ENUM_ENTRY("SCALE", fairygui::LoaderFillType::SCALE);
	LUA_ENUM_ENTRY("SCALE_MATCH_HEIGHT", fairygui::LoaderFillType::SCALE_MATCH_HEIGHT);
	LUA_ENUM_ENTRY("SCALE_MATCH_WIDTH", fairygui::LoaderFillType::SCALE_MATCH_WIDTH);
	LUA_ENUM_ENTRY("SCALE_FREE", fairygui::LoaderFillType::SCALE_FREE);
	LUA_ENUM_ENTRY("SCALE_NO_BORDER", fairygui::LoaderFillType::SCALE_NO_BORDER);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiProgressTitleType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("ProgressTitleType");
	LUA_ENUM_ENTRY("PERCENT", fairygui::ProgressTitleType::PERCENT);
	LUA_ENUM_ENTRY("VALUE_MAX", fairygui::ProgressTitleType::VALUE_MAX);
	LUA_ENUM_ENTRY("VALUE", fairygui::ProgressTitleType::VALUE);
	LUA_ENUM_ENTRY("MAX", fairygui::ProgressTitleType::MAX);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiListLayoutType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("ListLayoutType");
	LUA_ENUM_ENTRY("SINGLE_COLUMN", fairygui::ListLayoutType::SINGLE_COLUMN);
	LUA_ENUM_ENTRY("SINGLE_ROW", fairygui::ListLayoutType::SINGLE_ROW);
	LUA_ENUM_ENTRY("FLOW_HORIZONTAL", fairygui::ListLayoutType::FLOW_HORIZONTAL);
	LUA_ENUM_ENTRY("FLOW_VERTICAL", fairygui::ListLayoutType::FLOW_VERTICAL);
	LUA_ENUM_ENTRY("PAGINATION", fairygui::ListLayoutType::PAGINATION);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiListSelectionMode(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("ListSelectionMode");
	LUA_ENUM_ENTRY("SINGLE", fairygui::ListSelectionMode::SINGLE);
	LUA_ENUM_ENTRY("MULTIPLE", fairygui::ListSelectionMode::MULTIPLE);
	LUA_ENUM_ENTRY("MULTIPLE_SINGLECLICK", fairygui::ListSelectionMode::MULTIPLE_SINGLECLICK);
	LUA_ENUM_ENTRY("NONE", fairygui::ListSelectionMode::NONE);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiGroupLayoutType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("GroupLayoutType");
	LUA_ENUM_ENTRY("NONE", fairygui::GroupLayoutType::NONE);
	LUA_ENUM_ENTRY("HORIZONTAL", fairygui::GroupLayoutType::HORIZONTAL);
	LUA_ENUM_ENTRY("VERTICAL", fairygui::GroupLayoutType::VERTICAL);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiPopupDirection(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("PopupDirection");
	LUA_ENUM_ENTRY("AUTO", fairygui::PopupDirection::AUTO);
	LUA_ENUM_ENTRY("UP", fairygui::PopupDirection::UP);
	LUA_ENUM_ENTRY("DOWN", fairygui::PopupDirection::DOWN);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiAutoSizeType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("AutoSizeType");
	LUA_ENUM_ENTRY("NONE", fairygui::AutoSizeType::NONE);
	LUA_ENUM_ENTRY("BOTH", fairygui::AutoSizeType::BOTH);
	LUA_ENUM_ENTRY("HEIGHT", fairygui::AutoSizeType::HEIGHT);
	LUA_ENUM_ENTRY("SHRINK", fairygui::AutoSizeType::SHRINK);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiFlipType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("FlipType");
	LUA_ENUM_ENTRY("NONE", fairygui::FlipType::NONE);
	LUA_ENUM_ENTRY("HORIZONTAL", fairygui::FlipType::HORIZONTAL);
	LUA_ENUM_ENTRY("VERTICAL", fairygui::FlipType::VERTICAL);
	LUA_ENUM_ENTRY("BOTH", fairygui::FlipType::BOTH);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiTransitionActionType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("TransitionActionType");
	LUA_ENUM_ENTRY("XY", fairygui::TransitionActionType::XY);
	LUA_ENUM_ENTRY("Size", fairygui::TransitionActionType::Size);
	LUA_ENUM_ENTRY("Scale", fairygui::TransitionActionType::Scale);
	LUA_ENUM_ENTRY("Pivot", fairygui::TransitionActionType::Pivot);
	LUA_ENUM_ENTRY("Alpha", fairygui::TransitionActionType::Alpha);
	LUA_ENUM_ENTRY("Rotation", fairygui::TransitionActionType::Rotation);
	LUA_ENUM_ENTRY("Color", fairygui::TransitionActionType::Color);
	LUA_ENUM_ENTRY("Animation", fairygui::TransitionActionType::Animation);
	LUA_ENUM_ENTRY("Visible", fairygui::TransitionActionType::Visible);
	LUA_ENUM_ENTRY("Sound", fairygui::TransitionActionType::Sound);
	LUA_ENUM_ENTRY("Transition", fairygui::TransitionActionType::Transition);
	LUA_ENUM_ENTRY("Shake", fairygui::TransitionActionType::Shake);
	LUA_ENUM_ENTRY("ColorFilter", fairygui::TransitionActionType::ColorFilter);
	LUA_ENUM_ENTRY("Skew", fairygui::TransitionActionType::Skew);
	LUA_ENUM_ENTRY("Text", fairygui::TransitionActionType::Text);
	LUA_ENUM_ENTRY("Icon", fairygui::TransitionActionType::Icon);
	LUA_ENUM_ENTRY("Unknown", fairygui::TransitionActionType::Unknown);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiFillMethod(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("FillMethod");
	LUA_ENUM_ENTRY("None", fairygui::FillMethod::None);
	LUA_ENUM_ENTRY("Horizontal", fairygui::FillMethod::Horizontal);
	LUA_ENUM_ENTRY("Vertical", fairygui::FillMethod::Vertical);
	LUA_ENUM_ENTRY("Radial90", fairygui::FillMethod::Radial90);
	LUA_ENUM_ENTRY("Radial180", fairygui::FillMethod::Radial180);
	LUA_ENUM_ENTRY("Radial360", fairygui::FillMethod::Radial360);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiFillOrigin(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("FillOrigin");
	LUA_ENUM_ENTRY("Top", fairygui::FillOrigin::Top);
	LUA_ENUM_ENTRY("Bottom", fairygui::FillOrigin::Bottom);
	LUA_ENUM_ENTRY("Left", fairygui::FillOrigin::Left);
	LUA_ENUM_ENTRY("Right", fairygui::FillOrigin::Right);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiObjectPropID(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("ObjectPropID");
	LUA_ENUM_ENTRY("Text", fairygui::ObjectPropID::Text);
	LUA_ENUM_ENTRY("Icon", fairygui::ObjectPropID::Icon);
	LUA_ENUM_ENTRY("Color", fairygui::ObjectPropID::Color);
	LUA_ENUM_ENTRY("OutlineColor", fairygui::ObjectPropID::OutlineColor);
	LUA_ENUM_ENTRY("Playing", fairygui::ObjectPropID::Playing);
	LUA_ENUM_ENTRY("Frame", fairygui::ObjectPropID::Frame);
	LUA_ENUM_ENTRY("DeltaTime", fairygui::ObjectPropID::DeltaTime);
	LUA_ENUM_ENTRY("TimeScale", fairygui::ObjectPropID::TimeScale);
	LUA_ENUM_ENTRY("FontSize", fairygui::ObjectPropID::FontSize);
	LUA_ENUM_ENTRY("Selected", fairygui::ObjectPropID::Selected);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_UIConfig_bringWindowToFrontOnClick_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.bringWindowToFrontOnClick/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::bringWindowToFrontOnClick);
	return 1;
}
int lua_fairygui_UIConfig_bringWindowToFrontOnClick_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.bringWindowToFrontOnClick/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::bringWindowToFrontOnClick, 2);
	return 0;
}
int lua_fairygui_UIConfig_buttonSound_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.buttonSound/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::buttonSound);
	return 1;
}
int lua_fairygui_UIConfig_buttonSound_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.buttonSound/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::buttonSound, 2);
	return 0;
}
int lua_fairygui_UIConfig_buttonSoundVolumeScale_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.buttonSoundVolumeScale/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::buttonSoundVolumeScale);
	return 1;
}
int lua_fairygui_UIConfig_buttonSoundVolumeScale_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.buttonSoundVolumeScale/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::buttonSoundVolumeScale, 2);
	return 0;
}
int lua_fairygui_UIConfig_clickDragSensitivity_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.clickDragSensitivity/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::clickDragSensitivity);
	return 1;
}
int lua_fairygui_UIConfig_clickDragSensitivity_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.clickDragSensitivity/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::clickDragSensitivity, 2);
	return 0;
}
int lua_fairygui_UIConfig_defaultComboBoxVisibleItemCount_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultComboBoxVisibleItemCount/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::defaultComboBoxVisibleItemCount);
	return 1;
}
int lua_fairygui_UIConfig_defaultComboBoxVisibleItemCount_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultComboBoxVisibleItemCount/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::defaultComboBoxVisibleItemCount, 2);
	return 0;
}
int lua_fairygui_UIConfig_defaultFont_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultFont/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::defaultFont);
	return 1;
}
int lua_fairygui_UIConfig_defaultFont_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultFont/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::defaultFont, 2);
	return 0;
}
int lua_fairygui_UIConfig_defaultScrollBarDisplay_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultScrollBarDisplay/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::defaultScrollBarDisplay);
	return 1;
}
int lua_fairygui_UIConfig_defaultScrollBarDisplay_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultScrollBarDisplay/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::defaultScrollBarDisplay, 2);
	return 0;
}
int lua_fairygui_UIConfig_defaultScrollBounceEffect_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultScrollBounceEffect/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::defaultScrollBounceEffect);
	return 1;
}
int lua_fairygui_UIConfig_defaultScrollBounceEffect_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultScrollBounceEffect/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::defaultScrollBounceEffect, 2);
	return 0;
}
int lua_fairygui_UIConfig_defaultScrollDecelerationRate_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultScrollDecelerationRate/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::defaultScrollDecelerationRate);
	return 1;
}
int lua_fairygui_UIConfig_defaultScrollDecelerationRate_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultScrollDecelerationRate/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::defaultScrollDecelerationRate, 2);
	return 0;
}
int lua_fairygui_UIConfig_defaultScrollStep_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultScrollStep/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::defaultScrollStep);
	return 1;
}
int lua_fairygui_UIConfig_defaultScrollStep_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultScrollStep/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::defaultScrollStep, 2);
	return 0;
}
int lua_fairygui_UIConfig_defaultScrollTouchEffect_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultScrollTouchEffect/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::defaultScrollTouchEffect);
	return 1;
}
int lua_fairygui_UIConfig_defaultScrollTouchEffect_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.defaultScrollTouchEffect/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::defaultScrollTouchEffect, 2);
	return 0;
}
int lua_fairygui_UIConfig_globalModalWaiting_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.globalModalWaiting/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::globalModalWaiting);
	return 1;
}
int lua_fairygui_UIConfig_globalModalWaiting_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.globalModalWaiting/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::globalModalWaiting, 2);
	return 0;
}
int lua_fairygui_UIConfig_horizontalScrollBar_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.horizontalScrollBar/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::horizontalScrollBar);
	return 1;
}
int lua_fairygui_UIConfig_horizontalScrollBar_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.horizontalScrollBar/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::horizontalScrollBar, 2);
	return 0;
}
int lua_fairygui_UIConfig_modalLayerColor_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.modalLayerColor/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::modalLayerColor);
	return 1;
}
int lua_fairygui_UIConfig_modalLayerColor_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.modalLayerColor/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::modalLayerColor, 2);
	return 0;
}
int lua_fairygui_UIConfig_popupMenu_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.popupMenu/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::popupMenu);
	return 1;
}
int lua_fairygui_UIConfig_popupMenu_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.popupMenu/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::popupMenu, 2);
	return 0;
}
int lua_fairygui_UIConfig_popupMenu_seperator_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.popupMenu_seperator/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::popupMenu_seperator);
	return 1;
}
int lua_fairygui_UIConfig_popupMenu_seperator_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.popupMenu_seperator/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::popupMenu_seperator, 2);
	return 0;
}
int lua_fairygui_UIConfig_tooltipsWin_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.tooltipsWin/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::tooltipsWin);
	return 1;
}
int lua_fairygui_UIConfig_tooltipsWin_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.tooltipsWin/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::tooltipsWin, 2);
	return 0;
}
int lua_fairygui_UIConfig_touchDragSensitivity_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.touchDragSensitivity/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::touchDragSensitivity);
	return 1;
}
int lua_fairygui_UIConfig_touchDragSensitivity_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.touchDragSensitivity/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::touchDragSensitivity, 2);
	return 0;
}
int lua_fairygui_UIConfig_touchScrollSensitivity_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.touchScrollSensitivity/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::touchScrollSensitivity);
	return 1;
}
int lua_fairygui_UIConfig_touchScrollSensitivity_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.touchScrollSensitivity/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::touchScrollSensitivity, 2);
	return 0;
}
int lua_fairygui_UIConfig_verticalScrollBar_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.verticalScrollBar/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::verticalScrollBar);
	return 1;
}
int lua_fairygui_UIConfig_verticalScrollBar_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.verticalScrollBar/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::verticalScrollBar, 2);
	return 0;
}
int lua_fairygui_UIConfig_windowModalWaiting_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.windowModalWaiting/getter");
	LUA_PUSH_NATIVE(fairygui::UIConfig::windowModalWaiting);
	return 1;
}
int lua_fairygui_UIConfig_windowModalWaiting_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIConfig.windowModalWaiting/setter");
	LUA_NATIVE_SETTER(fairygui::UIConfig::windowModalWaiting, 2);
	return 0;
}
int lua_fairygui_UIConfig_getRealFontName(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIConfig", "fgui.UIConfig:getRealFontName");
	LUA_TRY_INVOKE_R(2, static_cast<const std::basic_string<char>&(*)(const std::string&, bool*)>(&fairygui::UIConfig::getRealFontName));
	LUA_TRY_INVOKE_R(1, [](const std::string& arg0){{return fairygui::UIConfig::getRealFontName(arg0);}});
	LUA_SINVOKE_FOOTER("1,2");
}
int lua_fairygui_UIConfig_registerFont(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIConfig", "fgui.UIConfig:registerFont");
	LUA_TRY_INVOKE(2, &fairygui::UIConfig::registerFont);
	LUA_SINVOKE_FOOTER("2");
}
int luaReg_fgui_fguiUIConfig(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::UIConfig, "UIConfig", "fgui.UIConfig",
		nullptr, nullptr);
	LUA_SFIELD("bringWindowToFrontOnClick", lua_fairygui_UIConfig_bringWindowToFrontOnClick_getter, lua_fairygui_UIConfig_bringWindowToFrontOnClick_setter);
	LUA_SFIELD("buttonSound", lua_fairygui_UIConfig_buttonSound_getter, lua_fairygui_UIConfig_buttonSound_setter);
	LUA_SFIELD("buttonSoundVolumeScale", lua_fairygui_UIConfig_buttonSoundVolumeScale_getter, lua_fairygui_UIConfig_buttonSoundVolumeScale_setter);
	LUA_SFIELD("clickDragSensitivity", lua_fairygui_UIConfig_clickDragSensitivity_getter, lua_fairygui_UIConfig_clickDragSensitivity_setter);
	LUA_SFIELD("defaultComboBoxVisibleItemCount", lua_fairygui_UIConfig_defaultComboBoxVisibleItemCount_getter, lua_fairygui_UIConfig_defaultComboBoxVisibleItemCount_setter);
	LUA_SFIELD("defaultFont", lua_fairygui_UIConfig_defaultFont_getter, lua_fairygui_UIConfig_defaultFont_setter);
	LUA_SFIELD("defaultScrollBarDisplay", lua_fairygui_UIConfig_defaultScrollBarDisplay_getter, lua_fairygui_UIConfig_defaultScrollBarDisplay_setter);
	LUA_SFIELD("defaultScrollBounceEffect", lua_fairygui_UIConfig_defaultScrollBounceEffect_getter, lua_fairygui_UIConfig_defaultScrollBounceEffect_setter);
	LUA_SFIELD("defaultScrollDecelerationRate", lua_fairygui_UIConfig_defaultScrollDecelerationRate_getter, lua_fairygui_UIConfig_defaultScrollDecelerationRate_setter);
	LUA_SFIELD("defaultScrollStep", lua_fairygui_UIConfig_defaultScrollStep_getter, lua_fairygui_UIConfig_defaultScrollStep_setter);
	LUA_SFIELD("defaultScrollTouchEffect", lua_fairygui_UIConfig_defaultScrollTouchEffect_getter, lua_fairygui_UIConfig_defaultScrollTouchEffect_setter);
	LUA_SFIELD("globalModalWaiting", lua_fairygui_UIConfig_globalModalWaiting_getter, lua_fairygui_UIConfig_globalModalWaiting_setter);
	LUA_SFIELD("horizontalScrollBar", lua_fairygui_UIConfig_horizontalScrollBar_getter, lua_fairygui_UIConfig_horizontalScrollBar_setter);
	LUA_SFIELD("modalLayerColor", lua_fairygui_UIConfig_modalLayerColor_getter, lua_fairygui_UIConfig_modalLayerColor_setter);
	LUA_SFIELD("popupMenu", lua_fairygui_UIConfig_popupMenu_getter, lua_fairygui_UIConfig_popupMenu_setter);
	LUA_SFIELD("popupMenu_seperator", lua_fairygui_UIConfig_popupMenu_seperator_getter, lua_fairygui_UIConfig_popupMenu_seperator_setter);
	LUA_SFIELD("tooltipsWin", lua_fairygui_UIConfig_tooltipsWin_getter, lua_fairygui_UIConfig_tooltipsWin_setter);
	LUA_SFIELD("touchDragSensitivity", lua_fairygui_UIConfig_touchDragSensitivity_getter, lua_fairygui_UIConfig_touchDragSensitivity_setter);
	LUA_SFIELD("touchScrollSensitivity", lua_fairygui_UIConfig_touchScrollSensitivity_getter, lua_fairygui_UIConfig_touchScrollSensitivity_setter);
	LUA_SFIELD("verticalScrollBar", lua_fairygui_UIConfig_verticalScrollBar_getter, lua_fairygui_UIConfig_verticalScrollBar_setter);
	LUA_SFIELD("windowModalWaiting", lua_fairygui_UIConfig_windowModalWaiting_getter, lua_fairygui_UIConfig_windowModalWaiting_setter);
	LUA_METHOD("getRealFontName", lua_fairygui_UIConfig_getRealFontName);
	LUA_METHOD("registerFont", lua_fairygui_UIConfig_registerFont);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_InputEvent_getButton(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:getButton");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::getButton);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputEvent_getKeyCode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:getKeyCode");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::getKeyCode);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputEvent_getMouseWheelDelta(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:getMouseWheelDelta");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::getMouseWheelDelta);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputEvent_getPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:getPosition");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::getPosition);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputEvent_getProcessor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:getProcessor");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::getProcessor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputEvent_getTarget(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:getTarget");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::getTarget);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputEvent_getTouch(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:getTouch");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::getTouch);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputEvent_getTouchId(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:getTouchId");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::getTouchId);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputEvent_getX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:getX");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::getX);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputEvent_getY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:getY");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::getY);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputEvent_isAltDown(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:isAltDown");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::isAltDown);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputEvent_isCtrlDown(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:isCtrlDown");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::isCtrlDown);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputEvent_isDoubleClick(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:isDoubleClick");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::isDoubleClick);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputEvent_isShiftDown(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputEvent", "fgui.InputEvent:isShiftDown");
	LUA_TRY_INVOKE_R(0, &fairygui::InputEvent::isShiftDown);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_fgui_fguiInputEvent(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::InputEvent, "InputEvent", "fgui.InputEvent",
		nullptr, nullptr);
	LUA_METHOD("getButton", lua_fairygui_InputEvent_getButton);
	LUA_METHOD("getKeyCode", lua_fairygui_InputEvent_getKeyCode);
	LUA_METHOD("getMouseWheelDelta", lua_fairygui_InputEvent_getMouseWheelDelta);
	LUA_METHOD("getPosition", lua_fairygui_InputEvent_getPosition);
	LUA_METHOD("getProcessor", lua_fairygui_InputEvent_getProcessor);
	LUA_METHOD("getTarget", lua_fairygui_InputEvent_getTarget);
	LUA_METHOD("getTouch", lua_fairygui_InputEvent_getTouch);
	LUA_METHOD("getTouchId", lua_fairygui_InputEvent_getTouchId);
	LUA_METHOD("getX", lua_fairygui_InputEvent_getX);
	LUA_METHOD("getY", lua_fairygui_InputEvent_getY);
	LUA_METHOD("isAltDown", lua_fairygui_InputEvent_isAltDown);
	LUA_METHOD("isCtrlDown", lua_fairygui_InputEvent_isCtrlDown);
	LUA_METHOD("isDoubleClick", lua_fairygui_InputEvent_isDoubleClick);
	LUA_METHOD("isShiftDown", lua_fairygui_InputEvent_isShiftDown);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_EventContext_captureTouch(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.EventContext", "fgui.EventContext:captureTouch");
	LUA_TRY_INVOKE(0, &fairygui::EventContext::captureTouch);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_EventContext_getData(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.EventContext", "fgui.EventContext:getData");
	LUA_TRY_INVOKE_R(0, &fairygui::EventContext::getData);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_EventContext_getDataValue(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.EventContext", "fgui.EventContext:getDataValue");
	LUA_TRY_INVOKE_R(0, &fairygui::EventContext::getDataValue);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_EventContext_getInput(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.EventContext", "fgui.EventContext:getInput");
	LUA_TRY_INVOKE_R(0, &fairygui::EventContext::getInput);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_EventContext_getSender(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.EventContext", "fgui.EventContext:getSender");
	LUA_TRY_INVOKE_R(0, &fairygui::EventContext::getSender);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_EventContext_getType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.EventContext", "fgui.EventContext:getType");
	LUA_TRY_INVOKE_R(0, &fairygui::EventContext::getType);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_EventContext_isDefaultPrevented(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.EventContext", "fgui.EventContext:isDefaultPrevented");
	LUA_TRY_INVOKE_R(0, &fairygui::EventContext::isDefaultPrevented);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_EventContext_preventDefault(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.EventContext", "fgui.EventContext:preventDefault");
	LUA_TRY_INVOKE(0, &fairygui::EventContext::preventDefault);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_EventContext_stopPropagation(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.EventContext", "fgui.EventContext:stopPropagation");
	LUA_TRY_INVOKE(0, &fairygui::EventContext::stopPropagation);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_EventContext_uncaptureTouch(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.EventContext", "fgui.EventContext:uncaptureTouch");
	LUA_TRY_INVOKE(0, &fairygui::EventContext::uncaptureTouch);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_fgui_fguiEventContext(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::EventContext, "EventContext", "fgui.EventContext",
		nullptr, nullptr);
	LUA_METHOD("captureTouch", lua_fairygui_EventContext_captureTouch);
	LUA_METHOD("getData", lua_fairygui_EventContext_getData);
	LUA_METHOD("getDataValue", lua_fairygui_EventContext_getDataValue);
	LUA_METHOD("getInput", lua_fairygui_EventContext_getInput);
	LUA_METHOD("getSender", lua_fairygui_EventContext_getSender);
	LUA_METHOD("getType", lua_fairygui_EventContext_getType);
	LUA_METHOD("isDefaultPrevented", lua_fairygui_EventContext_isDefaultPrevented);
	LUA_METHOD("preventDefault", lua_fairygui_EventContext_preventDefault);
	LUA_METHOD("stopPropagation", lua_fairygui_EventContext_stopPropagation);
	LUA_METHOD("uncaptureTouch", lua_fairygui_EventContext_uncaptureTouch);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_UIEventType_Changed_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.Changed/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::Changed);
	return 1;
}
int lua_fairygui_UIEventType_Click_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.Click/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::Click);
	return 1;
}
int lua_fairygui_UIEventType_ClickItem_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.ClickItem/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::ClickItem);
	return 1;
}
int lua_fairygui_UIEventType_ClickLink_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.ClickLink/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::ClickLink);
	return 1;
}
int lua_fairygui_UIEventType_ClickMenu_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.ClickMenu/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::ClickMenu);
	return 1;
}
int lua_fairygui_UIEventType_DragEnd_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.DragEnd/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::DragEnd);
	return 1;
}
int lua_fairygui_UIEventType_DragMove_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.DragMove/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::DragMove);
	return 1;
}
int lua_fairygui_UIEventType_DragStart_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.DragStart/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::DragStart);
	return 1;
}
int lua_fairygui_UIEventType_Drop_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.Drop/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::Drop);
	return 1;
}
int lua_fairygui_UIEventType_Enter_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.Enter/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::Enter);
	return 1;
}
int lua_fairygui_UIEventType_Exit_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.Exit/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::Exit);
	return 1;
}
int lua_fairygui_UIEventType_GearStop_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.GearStop/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::GearStop);
	return 1;
}
int lua_fairygui_UIEventType_KeyDown_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.KeyDown/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::KeyDown);
	return 1;
}
int lua_fairygui_UIEventType_KeyUp_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.KeyUp/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::KeyUp);
	return 1;
}
int lua_fairygui_UIEventType_MiddleClick_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.MiddleClick/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::MiddleClick);
	return 1;
}
int lua_fairygui_UIEventType_MouseWheel_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.MouseWheel/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::MouseWheel);
	return 1;
}
int lua_fairygui_UIEventType_PositionChange_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.PositionChange/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::PositionChange);
	return 1;
}
int lua_fairygui_UIEventType_PullDownRelease_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.PullDownRelease/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::PullDownRelease);
	return 1;
}
int lua_fairygui_UIEventType_PullUpRelease_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.PullUpRelease/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::PullUpRelease);
	return 1;
}
int lua_fairygui_UIEventType_RightClick_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.RightClick/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::RightClick);
	return 1;
}
int lua_fairygui_UIEventType_RightClickItem_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.RightClickItem/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::RightClickItem);
	return 1;
}
int lua_fairygui_UIEventType_RollOut_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.RollOut/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::RollOut);
	return 1;
}
int lua_fairygui_UIEventType_RollOver_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.RollOver/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::RollOver);
	return 1;
}
int lua_fairygui_UIEventType_Scroll_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.Scroll/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::Scroll);
	return 1;
}
int lua_fairygui_UIEventType_ScrollEnd_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.ScrollEnd/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::ScrollEnd);
	return 1;
}
int lua_fairygui_UIEventType_SizeChange_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.SizeChange/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::SizeChange);
	return 1;
}
int lua_fairygui_UIEventType_Submit_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.Submit/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::Submit);
	return 1;
}
int lua_fairygui_UIEventType_TouchBegin_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.TouchBegin/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::TouchBegin);
	return 1;
}
int lua_fairygui_UIEventType_TouchEnd_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.TouchEnd/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::TouchEnd);
	return 1;
}
int lua_fairygui_UIEventType_TouchMove_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIEventType.TouchMove/getter");
	LUA_PUSH_NATIVE(fairygui::UIEventType::TouchMove);
	return 1;
}
int luaReg_fgui_fguiUIEventType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::UIEventType, "UIEventType", "fgui.UIEventType",
		nullptr, nullptr);
	LUA_SFIELD("Changed", lua_fairygui_UIEventType_Changed_getter, nullptr);
	LUA_SFIELD("Click", lua_fairygui_UIEventType_Click_getter, nullptr);
	LUA_SFIELD("ClickItem", lua_fairygui_UIEventType_ClickItem_getter, nullptr);
	LUA_SFIELD("ClickLink", lua_fairygui_UIEventType_ClickLink_getter, nullptr);
	LUA_SFIELD("ClickMenu", lua_fairygui_UIEventType_ClickMenu_getter, nullptr);
	LUA_SFIELD("DragEnd", lua_fairygui_UIEventType_DragEnd_getter, nullptr);
	LUA_SFIELD("DragMove", lua_fairygui_UIEventType_DragMove_getter, nullptr);
	LUA_SFIELD("DragStart", lua_fairygui_UIEventType_DragStart_getter, nullptr);
	LUA_SFIELD("Drop", lua_fairygui_UIEventType_Drop_getter, nullptr);
	LUA_SFIELD("Enter", lua_fairygui_UIEventType_Enter_getter, nullptr);
	LUA_SFIELD("Exit", lua_fairygui_UIEventType_Exit_getter, nullptr);
	LUA_SFIELD("GearStop", lua_fairygui_UIEventType_GearStop_getter, nullptr);
	LUA_SFIELD("KeyDown", lua_fairygui_UIEventType_KeyDown_getter, nullptr);
	LUA_SFIELD("KeyUp", lua_fairygui_UIEventType_KeyUp_getter, nullptr);
	LUA_SFIELD("MiddleClick", lua_fairygui_UIEventType_MiddleClick_getter, nullptr);
	LUA_SFIELD("MouseWheel", lua_fairygui_UIEventType_MouseWheel_getter, nullptr);
	LUA_SFIELD("PositionChange", lua_fairygui_UIEventType_PositionChange_getter, nullptr);
	LUA_SFIELD("PullDownRelease", lua_fairygui_UIEventType_PullDownRelease_getter, nullptr);
	LUA_SFIELD("PullUpRelease", lua_fairygui_UIEventType_PullUpRelease_getter, nullptr);
	LUA_SFIELD("RightClick", lua_fairygui_UIEventType_RightClick_getter, nullptr);
	LUA_SFIELD("RightClickItem", lua_fairygui_UIEventType_RightClickItem_getter, nullptr);
	LUA_SFIELD("RollOut", lua_fairygui_UIEventType_RollOut_getter, nullptr);
	LUA_SFIELD("RollOver", lua_fairygui_UIEventType_RollOver_getter, nullptr);
	LUA_SFIELD("Scroll", lua_fairygui_UIEventType_Scroll_getter, nullptr);
	LUA_SFIELD("ScrollEnd", lua_fairygui_UIEventType_ScrollEnd_getter, nullptr);
	LUA_SFIELD("SizeChange", lua_fairygui_UIEventType_SizeChange_getter, nullptr);
	LUA_SFIELD("Submit", lua_fairygui_UIEventType_Submit_getter, nullptr);
	LUA_SFIELD("TouchBegin", lua_fairygui_UIEventType_TouchBegin_getter, nullptr);
	LUA_SFIELD("TouchEnd", lua_fairygui_UIEventType_TouchEnd_getter, nullptr);
	LUA_SFIELD("TouchMove", lua_fairygui_UIEventType_TouchMove_getter, nullptr);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_EventTag_new(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.EventTag", "fgui.EventTag:new");
	LUA_TRY_CTOR(1, [](fairygui::EventTag && arg0){{return new fairygui::EventTag(arg0);}});
	LUA_TRY_CTOR(1, [](const fairygui::EventTag& arg0){{return new fairygui::EventTag(arg0);}});
	LUA_TRY_CTOR(1, [](int arg0){{return new fairygui::EventTag(std::move(arg0));}});
	LUA_TRY_CTOR(1, [](void* arg0){{return new fairygui::EventTag(arg0);}});
	LUA_TRY_CTOR(0, [](){{return new fairygui::EventTag();}});
	LUA_SINVOKE_FOOTER("0,1");
}
int lua_fairygui_EventTag_delete(lua_State* lua_S)
{
	auto cobj = LUA_TO_COBJ(fairygui::EventTag*, 1);
	delete cobj;
	return 0;
}
int lua_fairygui_EventTag_None_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.EventTag.None/getter");
	LUA_PUSH_NATIVE(fairygui::EventTag::None);
	return 1;
}
int lua_fairygui_EventTag_isNone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.EventTag", "fgui.EventTag:isNone");
	LUA_TRY_INVOKE_R(0, &fairygui::EventTag::isNone);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_fgui_fguiEventTag(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::EventTag, "EventTag", "fgui.EventTag",
		lua_fairygui_EventTag_new, lua_fairygui_EventTag_delete);
	LUA_METHOD("new", lua_fairygui_EventTag_new);
	LUA_SFIELD("None", lua_fairygui_EventTag_None_getter, nullptr);
	LUA_METHOD("isNone", lua_fairygui_EventTag_isNone);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_UIEventDispatcher_addEventListener(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.UIEventDispatcher", "fgui.UIEventDispatcher:addEventListener");
	LUA_TRY_INVOKE(3, static_cast<void(fairygui::UIEventDispatcher::*)(int, const fairygui::EventCallback&, const fairygui::EventTag&)>(&fairygui::UIEventDispatcher::addEventListener));
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::UIEventDispatcher::*)(int, const fairygui::EventCallback&)>(&fairygui::UIEventDispatcher::addEventListener));
	LUA_INVOKE_FOOTER("2,3");
}
int lua_fairygui_UIEventDispatcher_hasEventListener(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.UIEventDispatcher", "fgui.UIEventDispatcher:hasEventListener");
	LUA_TRY_INVOKE_R(2, static_cast<bool(fairygui::UIEventDispatcher::*)(int, const fairygui::EventTag&)const>(&fairygui::UIEventDispatcher::hasEventListener));
	LUA_TRY_INVOKE_R(1, static_cast<bool(fairygui::UIEventDispatcher::*)(int)const>(&fairygui::UIEventDispatcher::hasEventListener));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_UIEventDispatcher_isDispatchingEvent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.UIEventDispatcher", "fgui.UIEventDispatcher:isDispatchingEvent");
	LUA_TRY_INVOKE_R(1, &fairygui::UIEventDispatcher::isDispatchingEvent);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_UIEventDispatcher_removeEventListener(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.UIEventDispatcher", "fgui.UIEventDispatcher:removeEventListener");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::UIEventDispatcher::*)(int, const fairygui::EventTag&)>(&fairygui::UIEventDispatcher::removeEventListener));
	LUA_TRY_INVOKE(1, static_cast<void(fairygui::UIEventDispatcher::*)(int)>(&fairygui::UIEventDispatcher::removeEventListener));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_UIEventDispatcher_removeEventListeners(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.UIEventDispatcher", "fgui.UIEventDispatcher:removeEventListeners");
	LUA_TRY_INVOKE(0, &fairygui::UIEventDispatcher::removeEventListeners);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_fgui_fguiUIEventDispatcher(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::UIEventDispatcher, "UIEventDispatcher", "fgui.UIEventDispatcher",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("addEventListener", lua_fairygui_UIEventDispatcher_addEventListener);
	LUA_METHOD("hasEventListener", lua_fairygui_UIEventDispatcher_hasEventListener);
	LUA_METHOD("isDispatchingEvent", lua_fairygui_UIEventDispatcher_isDispatchingEvent);
	LUA_METHOD("removeEventListener", lua_fairygui_UIEventDispatcher_removeEventListener);
	LUA_METHOD("removeEventListeners", lua_fairygui_UIEventDispatcher_removeEventListeners);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GController_autoRadioGroupDepth_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GController.autoRadioGroupDepth/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GController*, 1);
	LUA_PUSH_NATIVE(cobj->autoRadioGroupDepth);
	return 1;
}
int lua_fairygui_GController_autoRadioGroupDepth_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GController.autoRadioGroupDepth/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GController*, 1);
	LUA_NATIVE_SETTER(cobj->autoRadioGroupDepth, 2);
	return 0;
}
int lua_fairygui_GController_changing_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GController.changing/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GController*, 1);
	LUA_PUSH_NATIVE(cobj->changing);
	return 1;
}
int lua_fairygui_GController_changing_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GController.changing/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GController*, 1);
	LUA_NATIVE_SETTER(cobj->changing, 2);
	return 0;
}
int lua_fairygui_GController_name_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GController.name/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GController*, 1);
	LUA_PUSH_NATIVE(cobj->name);
	return 1;
}
int lua_fairygui_GController_name_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GController.name/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GController*, 1);
	LUA_NATIVE_SETTER(cobj->name, 2);
	return 0;
}
int lua_fairygui_GController_getPageCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:getPageCount");
	LUA_TRY_INVOKE_R(0, &fairygui::GController::getPageCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GController_getPageId(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:getPageId");
	LUA_TRY_INVOKE_R(1, &fairygui::GController::getPageId);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GController_getPageIndexById(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:getPageIndexById");
	LUA_TRY_INVOKE_R(1, &fairygui::GController::getPageIndexById);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GController_getPageNameById(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:getPageNameById");
	LUA_TRY_INVOKE_R(1, &fairygui::GController::getPageNameById);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GController_getParent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:getParent");
	LUA_TRY_INVOKE_R(0, &fairygui::GController::getParent);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GController_getPreviousPage(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:getPreviousPage");
	LUA_TRY_INVOKE_R(0, &fairygui::GController::getPreviousPage);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GController_getPreviousPageId(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:getPreviousPageId");
	LUA_TRY_INVOKE_R(0, &fairygui::GController::getPreviousPageId);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GController_getPrevisousIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:getPrevisousIndex");
	LUA_TRY_INVOKE_R(0, &fairygui::GController::getPrevisousIndex);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GController_getSelectedIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:getSelectedIndex");
	LUA_TRY_INVOKE_R(0, &fairygui::GController::getSelectedIndex);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GController_getSelectedPage(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:getSelectedPage");
	LUA_TRY_INVOKE_R(0, &fairygui::GController::getSelectedPage);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GController_getSelectedPageId(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:getSelectedPageId");
	LUA_TRY_INVOKE_R(0, &fairygui::GController::getSelectedPageId);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GController_hasPage(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:hasPage");
	LUA_TRY_INVOKE_R(1, &fairygui::GController::hasPage);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GController_runActions(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:runActions");
	LUA_TRY_INVOKE(0, &fairygui::GController::runActions);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GController_setOppositePageId(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:setOppositePageId");
	LUA_TRY_INVOKE(1, &fairygui::GController::setOppositePageId);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GController_setParent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:setParent");
	LUA_TRY_INVOKE(1, &fairygui::GController::setParent);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GController_setSelectedIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:setSelectedIndex");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::GController::*)(int, bool)>(&fairygui::GController::setSelectedIndex));
	LUA_TRY_INVOKE(1, [](fairygui::GController* obj, int arg0){{return obj->setSelectedIndex(std::move(arg0));}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_GController_setSelectedPage(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:setSelectedPage");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::GController::*)(const std::string&, bool)>(&fairygui::GController::setSelectedPage));
	LUA_TRY_INVOKE(1, [](fairygui::GController* obj, const std::string& arg0){{return obj->setSelectedPage(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_GController_setSelectedPageId(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:setSelectedPageId");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::GController::*)(const std::string&, bool)>(&fairygui::GController::setSelectedPageId));
	LUA_TRY_INVOKE(1, [](fairygui::GController* obj, const std::string& arg0){{return obj->setSelectedPageId(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_GController_setup(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GController", "fgui.GController:setup");
	LUA_TRY_INVOKE(1, &fairygui::GController::setup);
	LUA_INVOKE_FOOTER("1");
}
int luaReg_fgui_fguiGController(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GController, "GController", "fgui.GController",
		fairygui::UIEventDispatcher, "fgui.UIEventDispatcher",
		nullptr, nullptr);
	LUA_FIELD("autoRadioGroupDepth", lua_fairygui_GController_autoRadioGroupDepth_getter, lua_fairygui_GController_autoRadioGroupDepth_setter);
	LUA_FIELD("changing", lua_fairygui_GController_changing_getter, lua_fairygui_GController_changing_setter);
	LUA_FIELD("name", lua_fairygui_GController_name_getter, lua_fairygui_GController_name_setter);
	LUA_METHOD("getPageCount", lua_fairygui_GController_getPageCount);
	LUA_METHOD("getPageId", lua_fairygui_GController_getPageId);
	LUA_METHOD("getPageIndexById", lua_fairygui_GController_getPageIndexById);
	LUA_METHOD("getPageNameById", lua_fairygui_GController_getPageNameById);
	LUA_METHOD("getParent", lua_fairygui_GController_getParent);
	LUA_METHOD("getPreviousPage", lua_fairygui_GController_getPreviousPage);
	LUA_METHOD("getPreviousPageId", lua_fairygui_GController_getPreviousPageId);
	LUA_METHOD("getPrevisousIndex", lua_fairygui_GController_getPrevisousIndex);
	LUA_METHOD("getSelectedIndex", lua_fairygui_GController_getSelectedIndex);
	LUA_METHOD("getSelectedPage", lua_fairygui_GController_getSelectedPage);
	LUA_METHOD("getSelectedPageId", lua_fairygui_GController_getSelectedPageId);
	LUA_METHOD("hasPage", lua_fairygui_GController_hasPage);
	LUA_METHOD("runActions", lua_fairygui_GController_runActions);
	LUA_METHOD("setOppositePageId", lua_fairygui_GController_setOppositePageId);
	LUA_METHOD("setParent", lua_fairygui_GController_setParent);
	LUA_METHOD("setSelectedIndex", lua_fairygui_GController_setSelectedIndex);
	LUA_METHOD("setSelectedPage", lua_fairygui_GController_setSelectedPage);
	LUA_METHOD("setSelectedPageId", lua_fairygui_GController_setSelectedPageId);
	LUA_METHOD("setup", lua_fairygui_GController_setup);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiRelationType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("RelationType");
	LUA_ENUM_ENTRY("Left_Left", fairygui::RelationType::Left_Left);
	LUA_ENUM_ENTRY("Left_Center", fairygui::RelationType::Left_Center);
	LUA_ENUM_ENTRY("Left_Right", fairygui::RelationType::Left_Right);
	LUA_ENUM_ENTRY("Center_Center", fairygui::RelationType::Center_Center);
	LUA_ENUM_ENTRY("Right_Left", fairygui::RelationType::Right_Left);
	LUA_ENUM_ENTRY("Right_Center", fairygui::RelationType::Right_Center);
	LUA_ENUM_ENTRY("Right_Right", fairygui::RelationType::Right_Right);
	LUA_ENUM_ENTRY("Top_Top", fairygui::RelationType::Top_Top);
	LUA_ENUM_ENTRY("Top_Middle", fairygui::RelationType::Top_Middle);
	LUA_ENUM_ENTRY("Top_Bottom", fairygui::RelationType::Top_Bottom);
	LUA_ENUM_ENTRY("Middle_Middle", fairygui::RelationType::Middle_Middle);
	LUA_ENUM_ENTRY("Bottom_Top", fairygui::RelationType::Bottom_Top);
	LUA_ENUM_ENTRY("Bottom_Middle", fairygui::RelationType::Bottom_Middle);
	LUA_ENUM_ENTRY("Bottom_Bottom", fairygui::RelationType::Bottom_Bottom);
	LUA_ENUM_ENTRY("Width", fairygui::RelationType::Width);
	LUA_ENUM_ENTRY("Height", fairygui::RelationType::Height);
	LUA_ENUM_ENTRY("LeftExt_Left", fairygui::RelationType::LeftExt_Left);
	LUA_ENUM_ENTRY("LeftExt_Right", fairygui::RelationType::LeftExt_Right);
	LUA_ENUM_ENTRY("RightExt_Left", fairygui::RelationType::RightExt_Left);
	LUA_ENUM_ENTRY("RightExt_Right", fairygui::RelationType::RightExt_Right);
	LUA_ENUM_ENTRY("TopExt_Top", fairygui::RelationType::TopExt_Top);
	LUA_ENUM_ENTRY("TopExt_Bottom", fairygui::RelationType::TopExt_Bottom);
	LUA_ENUM_ENTRY("BottomExt_Top", fairygui::RelationType::BottomExt_Top);
	LUA_ENUM_ENTRY("BottomExt_Bottom", fairygui::RelationType::BottomExt_Bottom);
	LUA_ENUM_ENTRY("Size", fairygui::RelationType::Size);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_RelationItem_add(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.RelationItem", "fgui.RelationItem:add");
	LUA_TRY_INVOKE(2, &fairygui::RelationItem::add);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_RelationItem_applyOnSelfSizeChanged(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.RelationItem", "fgui.RelationItem:applyOnSelfSizeChanged");
	LUA_TRY_INVOKE(3, &fairygui::RelationItem::applyOnSelfSizeChanged);
	LUA_INVOKE_FOOTER("3");
}
int lua_fairygui_RelationItem_getTarget(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.RelationItem", "fgui.RelationItem:getTarget");
	LUA_TRY_INVOKE_R(0, &fairygui::RelationItem::getTarget);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_RelationItem_internalAdd(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.RelationItem", "fgui.RelationItem:internalAdd");
	LUA_TRY_INVOKE(2, &fairygui::RelationItem::internalAdd);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_RelationItem_isEmpty(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.RelationItem", "fgui.RelationItem:isEmpty");
	LUA_TRY_INVOKE_R(0, &fairygui::RelationItem::isEmpty);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_RelationItem_remove(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.RelationItem", "fgui.RelationItem:remove");
	LUA_TRY_INVOKE(1, &fairygui::RelationItem::remove);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_RelationItem_setTarget(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.RelationItem", "fgui.RelationItem:setTarget");
	LUA_TRY_INVOKE(1, &fairygui::RelationItem::setTarget);
	LUA_INVOKE_FOOTER("1");
}
int luaReg_fgui_fguiRelationItem(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::RelationItem, "RelationItem", "fgui.RelationItem",
		nullptr, nullptr);
	LUA_METHOD("add", lua_fairygui_RelationItem_add);
	LUA_METHOD("applyOnSelfSizeChanged", lua_fairygui_RelationItem_applyOnSelfSizeChanged);
	LUA_METHOD("getTarget", lua_fairygui_RelationItem_getTarget);
	LUA_METHOD("internalAdd", lua_fairygui_RelationItem_internalAdd);
	LUA_METHOD("isEmpty", lua_fairygui_RelationItem_isEmpty);
	LUA_METHOD("remove", lua_fairygui_RelationItem_remove);
	LUA_METHOD("setTarget", lua_fairygui_RelationItem_setTarget);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_Relations_handling_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.Relations.handling/getter");
	auto cobj = LUA_TO_COBJ(fairygui::Relations*, 1);
	LUA_PUSH_NATIVE(cobj->handling);
	return 1;
}
int lua_fairygui_Relations_handling_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.Relations.handling/setter");
	auto cobj = LUA_TO_COBJ(fairygui::Relations*, 1);
	LUA_NATIVE_SETTER(cobj->handling, 2);
	return 0;
}
int lua_fairygui_Relations_add(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Relations", "fgui.Relations:add");
	LUA_TRY_INVOKE(3, static_cast<void(fairygui::Relations::*)(fairygui::GObject*, fairygui::RelationType, bool)>(&fairygui::Relations::add));
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::Relations::*)(fairygui::GObject*, fairygui::RelationType)>(&fairygui::Relations::add));
	LUA_INVOKE_FOOTER("2,3");
}
int lua_fairygui_Relations_clearAll(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Relations", "fgui.Relations:clearAll");
	LUA_TRY_INVOKE(0, &fairygui::Relations::clearAll);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Relations_clearFor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Relations", "fgui.Relations:clearFor");
	LUA_TRY_INVOKE(1, &fairygui::Relations::clearFor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Relations_contains(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Relations", "fgui.Relations:contains");
	LUA_TRY_INVOKE_R(1, &fairygui::Relations::contains);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Relations_isEmpty(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Relations", "fgui.Relations:isEmpty");
	LUA_TRY_INVOKE_R(0, &fairygui::Relations::isEmpty);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Relations_onOwnerSizeChanged(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Relations", "fgui.Relations:onOwnerSizeChanged");
	LUA_TRY_INVOKE(3, &fairygui::Relations::onOwnerSizeChanged);
	LUA_INVOKE_FOOTER("3");
}
int lua_fairygui_Relations_remove(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Relations", "fgui.Relations:remove");
	LUA_TRY_INVOKE(2, &fairygui::Relations::remove);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_Relations_setup(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Relations", "fgui.Relations:setup");
	LUA_TRY_INVOKE(2, &fairygui::Relations::setup);
	LUA_INVOKE_FOOTER("2");
}
int luaReg_fgui_fguiRelations(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::Relations, "Relations", "fgui.Relations",
		nullptr, nullptr);
	LUA_FIELD("handling", lua_fairygui_Relations_handling_getter, lua_fairygui_Relations_handling_setter);
	LUA_METHOD("add", lua_fairygui_Relations_add);
	LUA_METHOD("clearAll", lua_fairygui_Relations_clearAll);
	LUA_METHOD("clearFor", lua_fairygui_Relations_clearFor);
	LUA_METHOD("contains", lua_fairygui_Relations_contains);
	LUA_METHOD("isEmpty", lua_fairygui_Relations_isEmpty);
	LUA_METHOD("onOwnerSizeChanged", lua_fairygui_Relations_onOwnerSizeChanged);
	LUA_METHOD("remove", lua_fairygui_Relations_remove);
	LUA_METHOD("setup", lua_fairygui_Relations_setup);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiEaseType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("EaseType");
	LUA_ENUM_ENTRY("Linear", fairygui::EaseType::Linear);
	LUA_ENUM_ENTRY("SineIn", fairygui::EaseType::SineIn);
	LUA_ENUM_ENTRY("SineOut", fairygui::EaseType::SineOut);
	LUA_ENUM_ENTRY("SineInOut", fairygui::EaseType::SineInOut);
	LUA_ENUM_ENTRY("QuadIn", fairygui::EaseType::QuadIn);
	LUA_ENUM_ENTRY("QuadOut", fairygui::EaseType::QuadOut);
	LUA_ENUM_ENTRY("QuadInOut", fairygui::EaseType::QuadInOut);
	LUA_ENUM_ENTRY("CubicIn", fairygui::EaseType::CubicIn);
	LUA_ENUM_ENTRY("CubicOut", fairygui::EaseType::CubicOut);
	LUA_ENUM_ENTRY("CubicInOut", fairygui::EaseType::CubicInOut);
	LUA_ENUM_ENTRY("QuartIn", fairygui::EaseType::QuartIn);
	LUA_ENUM_ENTRY("QuartOut", fairygui::EaseType::QuartOut);
	LUA_ENUM_ENTRY("QuartInOut", fairygui::EaseType::QuartInOut);
	LUA_ENUM_ENTRY("QuintIn", fairygui::EaseType::QuintIn);
	LUA_ENUM_ENTRY("QuintOut", fairygui::EaseType::QuintOut);
	LUA_ENUM_ENTRY("QuintInOut", fairygui::EaseType::QuintInOut);
	LUA_ENUM_ENTRY("ExpoIn", fairygui::EaseType::ExpoIn);
	LUA_ENUM_ENTRY("ExpoOut", fairygui::EaseType::ExpoOut);
	LUA_ENUM_ENTRY("ExpoInOut", fairygui::EaseType::ExpoInOut);
	LUA_ENUM_ENTRY("CircIn", fairygui::EaseType::CircIn);
	LUA_ENUM_ENTRY("CircOut", fairygui::EaseType::CircOut);
	LUA_ENUM_ENTRY("CircInOut", fairygui::EaseType::CircInOut);
	LUA_ENUM_ENTRY("ElasticIn", fairygui::EaseType::ElasticIn);
	LUA_ENUM_ENTRY("ElasticOut", fairygui::EaseType::ElasticOut);
	LUA_ENUM_ENTRY("ElasticInOut", fairygui::EaseType::ElasticInOut);
	LUA_ENUM_ENTRY("BackIn", fairygui::EaseType::BackIn);
	LUA_ENUM_ENTRY("BackOut", fairygui::EaseType::BackOut);
	LUA_ENUM_ENTRY("BackInOut", fairygui::EaseType::BackInOut);
	LUA_ENUM_ENTRY("BounceIn", fairygui::EaseType::BounceIn);
	LUA_ENUM_ENTRY("BounceOut", fairygui::EaseType::BounceOut);
	LUA_ENUM_ENTRY("BounceInOut", fairygui::EaseType::BounceInOut);
	LUA_ENUM_ENTRY("Custom", fairygui::EaseType::Custom);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GearBase_disableAllTweenEffect_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GearBase.disableAllTweenEffect/getter");
	LUA_PUSH_NATIVE(fairygui::GearBase::disableAllTweenEffect);
	return 1;
}
int lua_fairygui_GearBase_disableAllTweenEffect_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GearBase.disableAllTweenEffect/setter");
	LUA_NATIVE_SETTER(fairygui::GearBase::disableAllTweenEffect, 2);
	return 0;
}
int lua_fairygui_GearBase_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GearBase", "fgui.GearBase:create");
	LUA_TRY_INVOKE_R(2, &fairygui::GearBase::create);
	LUA_SINVOKE_FOOTER("2");
}
int luaReg_fgui_fguiGearBase(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::GearBase, "GearBase", "fgui.GearBase",
		nullptr, nullptr);
	LUA_SFIELD("disableAllTweenEffect", lua_fairygui_GearBase_disableAllTweenEffect_getter, lua_fairygui_GearBase_disableAllTweenEffect_setter);
	LUA_METHOD("create", lua_fairygui_GearBase_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GObject_id_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GObject.id/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GObject*, 1);
	LUA_PUSH_NATIVE(cobj->id);
	return 1;
}
int lua_fairygui_GObject_id_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GObject.id/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GObject*, 1);
	LUA_NATIVE_SETTER(cobj->id, 2);
	return 0;
}
int lua_fairygui_GObject_initSize_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GObject.initSize/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GObject*, 1);
	LUA_PUSH_NATIVE(cobj->initSize);
	return 1;
}
int lua_fairygui_GObject_initSize_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GObject.initSize/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GObject*, 1);
	LUA_NATIVE_SETTER(cobj->initSize, 2);
	return 0;
}
int lua_fairygui_GObject_maxSize_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GObject.maxSize/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GObject*, 1);
	LUA_PUSH_NATIVE(cobj->maxSize);
	return 1;
}
int lua_fairygui_GObject_maxSize_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GObject.maxSize/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GObject*, 1);
	LUA_NATIVE_SETTER(cobj->maxSize, 2);
	return 0;
}
int lua_fairygui_GObject_minSize_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GObject.minSize/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GObject*, 1);
	LUA_PUSH_NATIVE(cobj->minSize);
	return 1;
}
int lua_fairygui_GObject_minSize_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GObject.minSize/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GObject*, 1);
	LUA_NATIVE_SETTER(cobj->minSize, 2);
	return 0;
}
int lua_fairygui_GObject_name_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GObject.name/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GObject*, 1);
	LUA_PUSH_NATIVE(cobj->name);
	return 1;
}
int lua_fairygui_GObject_name_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GObject.name/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GObject*, 1);
	LUA_NATIVE_SETTER(cobj->name, 2);
	return 0;
}
int lua_fairygui_GObject_sourceSize_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GObject.sourceSize/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GObject*, 1);
	LUA_PUSH_NATIVE(cobj->sourceSize);
	return 1;
}
int lua_fairygui_GObject_sourceSize_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GObject.sourceSize/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GObject*, 1);
	LUA_NATIVE_SETTER(cobj->sourceSize, 2);
	return 0;
}
int lua_fairygui_GObject_addClickListener(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:addClickListener");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::GObject::*)(const fairygui::EventCallback&, const fairygui::EventTag&)>(&fairygui::GObject::addClickListener));
	LUA_TRY_INVOKE(1, static_cast<void(fairygui::GObject::*)(const fairygui::EventCallback&)>(&fairygui::GObject::addClickListener));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_GObject_addDisplayLock(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:addDisplayLock");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::addDisplayLock);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_addRelation(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:addRelation");
	LUA_TRY_INVOKE(3, static_cast<void(fairygui::GObject::*)(fairygui::GObject*, fairygui::RelationType, bool)>(&fairygui::GObject::addRelation));
	LUA_TRY_INVOKE(2, [](fairygui::GObject* obj, fairygui::GObject* arg0,fairygui::RelationType arg1){{return obj->addRelation(std::move(arg0),std::move(arg1));}});
	LUA_INVOKE_FOOTER("2,3");
}
int lua_fairygui_GObject_center(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:center");
	LUA_TRY_INVOKE(1, static_cast<void(fairygui::GObject::*)(bool)>(&fairygui::GObject::center));
	LUA_TRY_INVOKE(0, [](fairygui::GObject* obj){{return obj->center();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_fairygui_GObject_checkGearController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:checkGearController");
	LUA_TRY_INVOKE_R(2, &fairygui::GObject::checkGearController);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GObject_constructFromResource(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:constructFromResource");
	LUA_TRY_INVOKE(0, &fairygui::GObject::constructFromResource);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_displayObject(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:displayObject");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::displayObject);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_findParent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:findParent");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::findParent);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getAlpha(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getAlpha");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getAlpha);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getCustomData(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getCustomData");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getCustomData);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getGear(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getGear");
	LUA_TRY_INVOKE_R(1, &fairygui::GObject::getGear);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_getGroup(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getGroup");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getGroup);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getHeight(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getHeight");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getHeight);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getIcon(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getIcon");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getIcon);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getPackageItem(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getPackageItem");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getPackageItem);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getParent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getParent");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getParent);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getPivot(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getPivot");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getPivot);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getPosition");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getPosition);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getProp(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getProp");
	LUA_TRY_INVOKE_R(1, &fairygui::GObject::getProp);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_getResourceURL(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getResourceURL");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getResourceURL);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getRoot(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getRoot");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getRoot);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getRotation(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getRotation");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getRotation);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getScale(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getScale");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getScale);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getScaleX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getScaleX");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getScaleX);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getScaleY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getScaleY");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getScaleY);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getSize");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getSkewX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getSkewX");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getSkewX);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getSkewY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getSkewY");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getSkewY);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getSortingOrder(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getSortingOrder");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getSortingOrder);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getText");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getText);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getTooltips(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getTooltips");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getTooltips);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getWidth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getWidth");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getWidth);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getX");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getX);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getXMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getXMin");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getXMin);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getY");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getY);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getYMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:getYMin");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getYMin);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_globalToLocal(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:globalToLocal");
	LUA_TRY_INVOKE_R(1, static_cast<cocos2d::Rect(fairygui::GObject::*)(const cocos2d::Rect&)>(&fairygui::GObject::globalToLocal));
	LUA_TRY_INVOKE_R(1, static_cast<cocos2d::Vec2(fairygui::GObject::*)(const cocos2d::Vec2&)>(&fairygui::GObject::globalToLocal));
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_hitTest(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:hitTest");
	LUA_TRY_INVOKE_R(2, &fairygui::GObject::hitTest);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GObject_isDraggable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:isDraggable");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::isDraggable);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_isGrayed(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:isGrayed");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::isGrayed);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_isPivotAsAnchor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:isPivotAsAnchor");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::isPivotAsAnchor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_isPixelSnapping(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:isPixelSnapping");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::isPixelSnapping);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_isTouchable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:isTouchable");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::isTouchable);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_isVisible(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:isVisible");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::isVisible);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_localToGlobal(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:localToGlobal");
	LUA_TRY_INVOKE_R(1, static_cast<cocos2d::Rect(fairygui::GObject::*)(const cocos2d::Rect&)>(&fairygui::GObject::localToGlobal));
	LUA_TRY_INVOKE_R(1, static_cast<cocos2d::Vec2(fairygui::GObject::*)(const cocos2d::Vec2&)>(&fairygui::GObject::localToGlobal));
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_makeFullScreen(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:makeFullScreen");
	LUA_TRY_INVOKE(0, &fairygui::GObject::makeFullScreen);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_onStage(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:onStage");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::onStage);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_relations(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:relations");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::relations);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_releaseDisplayLock(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:releaseDisplayLock");
	LUA_TRY_INVOKE(1, &fairygui::GObject::releaseDisplayLock);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_removeClickListener(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:removeClickListener");
	LUA_TRY_INVOKE(1, &fairygui::GObject::removeClickListener);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_removeFromParent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:removeFromParent");
	LUA_TRY_INVOKE(0, &fairygui::GObject::removeFromParent);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_removeRelation(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:removeRelation");
	LUA_TRY_INVOKE(2, &fairygui::GObject::removeRelation);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GObject_setAlpha(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setAlpha");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setAlpha);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setCustomData(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setCustomData");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setCustomData);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setDragBounds(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setDragBounds");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setDragBounds);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setDraggable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setDraggable");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setDraggable);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setGrayed(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setGrayed");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setGrayed);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setGroup(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setGroup");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setGroup);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setHeight(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setHeight");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setHeight);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setIcon(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setIcon");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setIcon);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setPivot(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setPivot");
	LUA_TRY_INVOKE(3, static_cast<void(fairygui::GObject::*)(float, float, bool)>(&fairygui::GObject::setPivot));
	LUA_TRY_INVOKE(2, [](fairygui::GObject* obj, float arg0,float arg1){{return obj->setPivot(std::move(arg0),std::move(arg1));}});
	LUA_INVOKE_FOOTER("2,3");
}
int lua_fairygui_GObject_setPixelSnapping(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setPixelSnapping");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setPixelSnapping);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setPosition");
	LUA_TRY_INVOKE(2, &fairygui::GObject::setPosition);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GObject_setProp(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setProp");
	LUA_TRY_INVOKE(2, &fairygui::GObject::setProp);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GObject_setRotation(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setRotation");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setRotation);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setScale(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setScale");
	LUA_TRY_INVOKE(2, &fairygui::GObject::setScale);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GObject_setScaleX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setScaleX");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setScaleX);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setScaleY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setScaleY");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setScaleY);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setSize");
	LUA_TRY_INVOKE(3, static_cast<void(fairygui::GObject::*)(float, float, bool)>(&fairygui::GObject::setSize));
	LUA_TRY_INVOKE(2, [](fairygui::GObject* obj, float arg0,float arg1){{return obj->setSize(std::move(arg0),std::move(arg1));}});
	LUA_INVOKE_FOOTER("2,3");
}
int lua_fairygui_GObject_setSkewX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setSkewX");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setSkewX);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setSkewY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setSkewY");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setSkewY);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setSortingOrder(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setSortingOrder");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setSortingOrder);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setText");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setText);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setTooltips(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setTooltips");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setTooltips);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setTouchable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setTouchable");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setTouchable);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setVisible(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setVisible");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setVisible);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setWidth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setWidth");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setWidth);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setX");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setX);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setXMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setXMin");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setXMin);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setY");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setY);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_setYMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:setYMin");
	LUA_TRY_INVOKE(1, &fairygui::GObject::setYMin);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GObject_startDrag(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:startDrag");
	LUA_TRY_INVOKE(1, static_cast<void(fairygui::GObject::*)(int)>(&fairygui::GObject::startDrag));
	LUA_TRY_INVOKE(0, [](fairygui::GObject* obj){{return obj->startDrag();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_fairygui_GObject_stopDrag(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:stopDrag");
	LUA_TRY_INVOKE(0, &fairygui::GObject::stopDrag);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_transformRect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:transformRect");
	LUA_TRY_INVOKE_R(2, &fairygui::GObject::transformRect);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GObject_treeNode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GObject", "fgui.GObject:treeNode");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::treeNode);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GObject_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GObject", "fgui.GObject:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::create);
	LUA_SINVOKE_FOOTER("0");
}
int lua_fairygui_GObject_getDraggingObject(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GObject", "fgui.GObject:getDraggingObject");
	LUA_TRY_INVOKE_R(0, &fairygui::GObject::getDraggingObject);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGObject(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GObject, "GObject", "fgui.GObject",
		fairygui::UIEventDispatcher, "fgui.UIEventDispatcher",
		nullptr, nullptr);
	LUA_FIELD("id", lua_fairygui_GObject_id_getter, lua_fairygui_GObject_id_setter);
	LUA_FIELD("initSize", lua_fairygui_GObject_initSize_getter, lua_fairygui_GObject_initSize_setter);
	LUA_FIELD("maxSize", lua_fairygui_GObject_maxSize_getter, lua_fairygui_GObject_maxSize_setter);
	LUA_FIELD("minSize", lua_fairygui_GObject_minSize_getter, lua_fairygui_GObject_minSize_setter);
	LUA_FIELD("name", lua_fairygui_GObject_name_getter, lua_fairygui_GObject_name_setter);
	LUA_FIELD("sourceSize", lua_fairygui_GObject_sourceSize_getter, lua_fairygui_GObject_sourceSize_setter);
	LUA_METHOD("addClickListener", lua_fairygui_GObject_addClickListener);
	LUA_METHOD("addDisplayLock", lua_fairygui_GObject_addDisplayLock);
	LUA_METHOD("addRelation", lua_fairygui_GObject_addRelation);
	LUA_METHOD("center", lua_fairygui_GObject_center);
	LUA_METHOD("checkGearController", lua_fairygui_GObject_checkGearController);
	LUA_METHOD("constructFromResource", lua_fairygui_GObject_constructFromResource);
	LUA_METHOD("displayObject", lua_fairygui_GObject_displayObject);
	LUA_METHOD("findParent", lua_fairygui_GObject_findParent);
	LUA_METHOD("getAlpha", lua_fairygui_GObject_getAlpha);
	LUA_METHOD("getCustomData", lua_fairygui_GObject_getCustomData);
	LUA_METHOD("getGear", lua_fairygui_GObject_getGear);
	LUA_METHOD("getGroup", lua_fairygui_GObject_getGroup);
	LUA_METHOD("getHeight", lua_fairygui_GObject_getHeight);
	LUA_METHOD("getIcon", lua_fairygui_GObject_getIcon);
	LUA_METHOD("getPackageItem", lua_fairygui_GObject_getPackageItem);
	LUA_METHOD("getParent", lua_fairygui_GObject_getParent);
	LUA_METHOD("getPivot", lua_fairygui_GObject_getPivot);
	LUA_METHOD("getPosition", lua_fairygui_GObject_getPosition);
	LUA_METHOD("getProp", lua_fairygui_GObject_getProp);
	LUA_METHOD("getResourceURL", lua_fairygui_GObject_getResourceURL);
	LUA_METHOD("getRoot", lua_fairygui_GObject_getRoot);
	LUA_METHOD("getRotation", lua_fairygui_GObject_getRotation);
	LUA_METHOD("getScale", lua_fairygui_GObject_getScale);
	LUA_METHOD("getScaleX", lua_fairygui_GObject_getScaleX);
	LUA_METHOD("getScaleY", lua_fairygui_GObject_getScaleY);
	LUA_METHOD("getSize", lua_fairygui_GObject_getSize);
	LUA_METHOD("getSkewX", lua_fairygui_GObject_getSkewX);
	LUA_METHOD("getSkewY", lua_fairygui_GObject_getSkewY);
	LUA_METHOD("getSortingOrder", lua_fairygui_GObject_getSortingOrder);
	LUA_METHOD("getText", lua_fairygui_GObject_getText);
	LUA_METHOD("getTooltips", lua_fairygui_GObject_getTooltips);
	LUA_METHOD("getWidth", lua_fairygui_GObject_getWidth);
	LUA_METHOD("getX", lua_fairygui_GObject_getX);
	LUA_METHOD("getXMin", lua_fairygui_GObject_getXMin);
	LUA_METHOD("getY", lua_fairygui_GObject_getY);
	LUA_METHOD("getYMin", lua_fairygui_GObject_getYMin);
	LUA_METHOD("globalToLocal", lua_fairygui_GObject_globalToLocal);
	LUA_METHOD("hitTest", lua_fairygui_GObject_hitTest);
	LUA_METHOD("isDraggable", lua_fairygui_GObject_isDraggable);
	LUA_METHOD("isGrayed", lua_fairygui_GObject_isGrayed);
	LUA_METHOD("isPivotAsAnchor", lua_fairygui_GObject_isPivotAsAnchor);
	LUA_METHOD("isPixelSnapping", lua_fairygui_GObject_isPixelSnapping);
	LUA_METHOD("isTouchable", lua_fairygui_GObject_isTouchable);
	LUA_METHOD("isVisible", lua_fairygui_GObject_isVisible);
	LUA_METHOD("localToGlobal", lua_fairygui_GObject_localToGlobal);
	LUA_METHOD("makeFullScreen", lua_fairygui_GObject_makeFullScreen);
	LUA_METHOD("onStage", lua_fairygui_GObject_onStage);
	LUA_METHOD("relations", lua_fairygui_GObject_relations);
	LUA_METHOD("releaseDisplayLock", lua_fairygui_GObject_releaseDisplayLock);
	LUA_METHOD("removeClickListener", lua_fairygui_GObject_removeClickListener);
	LUA_METHOD("removeFromParent", lua_fairygui_GObject_removeFromParent);
	LUA_METHOD("removeRelation", lua_fairygui_GObject_removeRelation);
	LUA_METHOD("setAlpha", lua_fairygui_GObject_setAlpha);
	LUA_METHOD("setCustomData", lua_fairygui_GObject_setCustomData);
	LUA_METHOD("setDragBounds", lua_fairygui_GObject_setDragBounds);
	LUA_METHOD("setDraggable", lua_fairygui_GObject_setDraggable);
	LUA_METHOD("setGrayed", lua_fairygui_GObject_setGrayed);
	LUA_METHOD("setGroup", lua_fairygui_GObject_setGroup);
	LUA_METHOD("setHeight", lua_fairygui_GObject_setHeight);
	LUA_METHOD("setIcon", lua_fairygui_GObject_setIcon);
	LUA_METHOD("setPivot", lua_fairygui_GObject_setPivot);
	LUA_METHOD("setPixelSnapping", lua_fairygui_GObject_setPixelSnapping);
	LUA_METHOD("setPosition", lua_fairygui_GObject_setPosition);
	LUA_METHOD("setProp", lua_fairygui_GObject_setProp);
	LUA_METHOD("setRotation", lua_fairygui_GObject_setRotation);
	LUA_METHOD("setScale", lua_fairygui_GObject_setScale);
	LUA_METHOD("setScaleX", lua_fairygui_GObject_setScaleX);
	LUA_METHOD("setScaleY", lua_fairygui_GObject_setScaleY);
	LUA_METHOD("setSize", lua_fairygui_GObject_setSize);
	LUA_METHOD("setSkewX", lua_fairygui_GObject_setSkewX);
	LUA_METHOD("setSkewY", lua_fairygui_GObject_setSkewY);
	LUA_METHOD("setSortingOrder", lua_fairygui_GObject_setSortingOrder);
	LUA_METHOD("setText", lua_fairygui_GObject_setText);
	LUA_METHOD("setTooltips", lua_fairygui_GObject_setTooltips);
	LUA_METHOD("setTouchable", lua_fairygui_GObject_setTouchable);
	LUA_METHOD("setVisible", lua_fairygui_GObject_setVisible);
	LUA_METHOD("setWidth", lua_fairygui_GObject_setWidth);
	LUA_METHOD("setX", lua_fairygui_GObject_setX);
	LUA_METHOD("setXMin", lua_fairygui_GObject_setXMin);
	LUA_METHOD("setY", lua_fairygui_GObject_setY);
	LUA_METHOD("setYMin", lua_fairygui_GObject_setYMin);
	LUA_METHOD("startDrag", lua_fairygui_GObject_startDrag);
	LUA_METHOD("stopDrag", lua_fairygui_GObject_stopDrag);
	LUA_METHOD("transformRect", lua_fairygui_GObject_transformRect);
	LUA_METHOD("treeNode", lua_fairygui_GObject_treeNode);
	LUA_METHOD("create", lua_fairygui_GObject_create);
	LUA_METHOD("getDraggingObject", lua_fairygui_GObject_getDraggingObject);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_PackageItem_animation_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.animation/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->animation);
	return 1;
}
int lua_fairygui_PackageItem_animation_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.animation/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->animation, 2);
	return 0;
}
int lua_fairygui_PackageItem_delayPerUnit_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.delayPerUnit/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->delayPerUnit);
	return 1;
}
int lua_fairygui_PackageItem_delayPerUnit_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.delayPerUnit/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->delayPerUnit, 2);
	return 0;
}
int lua_fairygui_PackageItem_file_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.file/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->file);
	return 1;
}
int lua_fairygui_PackageItem_file_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.file/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->file, 2);
	return 0;
}
int lua_fairygui_PackageItem_height_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.height/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->height);
	return 1;
}
int lua_fairygui_PackageItem_height_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.height/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->height, 2);
	return 0;
}
int lua_fairygui_PackageItem_id_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.id/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->id);
	return 1;
}
int lua_fairygui_PackageItem_id_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.id/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->id, 2);
	return 0;
}
int lua_fairygui_PackageItem_name_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.name/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->name);
	return 1;
}
int lua_fairygui_PackageItem_name_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.name/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->name, 2);
	return 0;
}
int lua_fairygui_PackageItem_objectType_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.objectType/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->objectType);
	return 1;
}
int lua_fairygui_PackageItem_objectType_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.objectType/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->objectType, 2);
	return 0;
}
int lua_fairygui_PackageItem_owner_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.owner/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->owner);
	return 1;
}
int lua_fairygui_PackageItem_owner_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.owner/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->owner, 2);
	return 0;
}
int lua_fairygui_PackageItem_repeatDelay_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.repeatDelay/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->repeatDelay);
	return 1;
}
int lua_fairygui_PackageItem_repeatDelay_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.repeatDelay/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->repeatDelay, 2);
	return 0;
}
int lua_fairygui_PackageItem_scaleByTile_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.scaleByTile/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->scaleByTile);
	return 1;
}
int lua_fairygui_PackageItem_scaleByTile_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.scaleByTile/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->scaleByTile, 2);
	return 0;
}
int lua_fairygui_PackageItem_spriteFrame_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.spriteFrame/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->spriteFrame);
	return 1;
}
int lua_fairygui_PackageItem_spriteFrame_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.spriteFrame/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->spriteFrame, 2);
	return 0;
}
int lua_fairygui_PackageItem_swing_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.swing/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->swing);
	return 1;
}
int lua_fairygui_PackageItem_swing_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.swing/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->swing, 2);
	return 0;
}
int lua_fairygui_PackageItem_texture_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.texture/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->texture);
	return 1;
}
int lua_fairygui_PackageItem_texture_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.texture/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->texture, 2);
	return 0;
}
int lua_fairygui_PackageItem_tileGridIndice_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.tileGridIndice/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->tileGridIndice);
	return 1;
}
int lua_fairygui_PackageItem_tileGridIndice_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.tileGridIndice/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->tileGridIndice, 2);
	return 0;
}
int lua_fairygui_PackageItem_translated_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.translated/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->translated);
	return 1;
}
int lua_fairygui_PackageItem_translated_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.translated/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->translated, 2);
	return 0;
}
int lua_fairygui_PackageItem_type_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.type/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->type);
	return 1;
}
int lua_fairygui_PackageItem_type_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.type/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->type, 2);
	return 0;
}
int lua_fairygui_PackageItem_width_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.width/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_PUSH_NATIVE(cobj->width);
	return 1;
}
int lua_fairygui_PackageItem_width_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PackageItem.width/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PackageItem*, 1);
	LUA_NATIVE_SETTER(cobj->width, 2);
	return 0;
}
int lua_fairygui_PackageItem_getBranch(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PackageItem", "fgui.PackageItem:getBranch");
	LUA_TRY_INVOKE_R(0, &fairygui::PackageItem::getBranch);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_PackageItem_getHighResolution(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PackageItem", "fgui.PackageItem:getHighResolution");
	LUA_TRY_INVOKE_R(0, &fairygui::PackageItem::getHighResolution);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_PackageItem_load(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PackageItem", "fgui.PackageItem:load");
	LUA_TRY_INVOKE(0, &fairygui::PackageItem::load);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_fgui_fguiPackageItem(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::PackageItem, "PackageItem", "fgui.PackageItem",
		cocos2d::Ref, "fgui.cocos2d.Ref",
		nullptr, nullptr);
	LUA_FIELD("animation", lua_fairygui_PackageItem_animation_getter, lua_fairygui_PackageItem_animation_setter);
	LUA_FIELD("delayPerUnit", lua_fairygui_PackageItem_delayPerUnit_getter, lua_fairygui_PackageItem_delayPerUnit_setter);
	LUA_FIELD("file", lua_fairygui_PackageItem_file_getter, lua_fairygui_PackageItem_file_setter);
	LUA_FIELD("height", lua_fairygui_PackageItem_height_getter, lua_fairygui_PackageItem_height_setter);
	LUA_FIELD("id", lua_fairygui_PackageItem_id_getter, lua_fairygui_PackageItem_id_setter);
	LUA_FIELD("name", lua_fairygui_PackageItem_name_getter, lua_fairygui_PackageItem_name_setter);
	LUA_FIELD("objectType", lua_fairygui_PackageItem_objectType_getter, lua_fairygui_PackageItem_objectType_setter);
	LUA_FIELD("owner", lua_fairygui_PackageItem_owner_getter, lua_fairygui_PackageItem_owner_setter);
	LUA_FIELD("repeatDelay", lua_fairygui_PackageItem_repeatDelay_getter, lua_fairygui_PackageItem_repeatDelay_setter);
	LUA_FIELD("scaleByTile", lua_fairygui_PackageItem_scaleByTile_getter, lua_fairygui_PackageItem_scaleByTile_setter);
	LUA_FIELD("spriteFrame", lua_fairygui_PackageItem_spriteFrame_getter, lua_fairygui_PackageItem_spriteFrame_setter);
	LUA_FIELD("swing", lua_fairygui_PackageItem_swing_getter, lua_fairygui_PackageItem_swing_setter);
	LUA_FIELD("texture", lua_fairygui_PackageItem_texture_getter, lua_fairygui_PackageItem_texture_setter);
	LUA_FIELD("tileGridIndice", lua_fairygui_PackageItem_tileGridIndice_getter, lua_fairygui_PackageItem_tileGridIndice_setter);
	LUA_FIELD("translated", lua_fairygui_PackageItem_translated_getter, lua_fairygui_PackageItem_translated_setter);
	LUA_FIELD("type", lua_fairygui_PackageItem_type_getter, lua_fairygui_PackageItem_type_setter);
	LUA_FIELD("width", lua_fairygui_PackageItem_width_getter, lua_fairygui_PackageItem_width_setter);
	LUA_METHOD("getBranch", lua_fairygui_PackageItem_getBranch);
	LUA_METHOD("getHighResolution", lua_fairygui_PackageItem_getHighResolution);
	LUA_METHOD("load", lua_fairygui_PackageItem_load);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_UIPackage_URL_PREFIX_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIPackage.URL_PREFIX/getter");
	LUA_PUSH_NATIVE(fairygui::UIPackage::URL_PREFIX);
	return 1;
}
int lua_fairygui_UIPackage__constructing_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIPackage._constructing/getter");
	LUA_PUSH_NATIVE(fairygui::UIPackage::_constructing);
	return 1;
}
int lua_fairygui_UIPackage__constructing_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.UIPackage._constructing/setter");
	LUA_NATIVE_SETTER(fairygui::UIPackage::_constructing, 2);
	return 0;
}
int lua_fairygui_UIPackage_getId(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:getId");
	LUA_TRY_INVOKE_R(0, &fairygui::UIPackage::getId);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_UIPackage_getItem(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:getItem");
	LUA_TRY_INVOKE_R(1, &fairygui::UIPackage::getItem);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_UIPackage_getItemByName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:getItemByName");
	LUA_TRY_INVOKE_R(1, &fairygui::UIPackage::getItemByName);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_UIPackage_getName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:getName");
	LUA_TRY_INVOKE_R(0, &fairygui::UIPackage::getName);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_UIPackage_addPackage(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:addPackage");
	LUA_TRY_INVOKE_R(1, &fairygui::UIPackage::addPackage);
	LUA_SINVOKE_FOOTER("1");
}
int lua_fairygui_UIPackage_createObject(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:createObject");
	LUA_TRY_INVOKE_R(2, static_cast<fairygui::GObject*(*)(const std::string&, const std::string&)>(&fairygui::UIPackage::createObject));
	LUA_SINVOKE_FOOTER("2");
}
int lua_fairygui_UIPackage_createObjectFromURL(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:createObjectFromURL");
	LUA_TRY_INVOKE_R(1, &fairygui::UIPackage::createObjectFromURL);
	LUA_SINVOKE_FOOTER("1");
}
int lua_fairygui_UIPackage_getBranch(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:getBranch");
	LUA_TRY_INVOKE_R(0, &fairygui::UIPackage::getBranch);
	LUA_SINVOKE_FOOTER("0");
}
int lua_fairygui_UIPackage_getById(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:getById");
	LUA_TRY_INVOKE_R(1, &fairygui::UIPackage::getById);
	LUA_SINVOKE_FOOTER("1");
}
int lua_fairygui_UIPackage_getByName(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:getByName");
	LUA_TRY_INVOKE_R(1, &fairygui::UIPackage::getByName);
	LUA_SINVOKE_FOOTER("1");
}
int lua_fairygui_UIPackage_getEmptyTexture(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:getEmptyTexture");
	LUA_TRY_INVOKE_R(0, &fairygui::UIPackage::getEmptyTexture);
	LUA_SINVOKE_FOOTER("0");
}
int lua_fairygui_UIPackage_getItemByURL(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:getItemByURL");
	LUA_TRY_INVOKE_R(1, &fairygui::UIPackage::getItemByURL);
	LUA_SINVOKE_FOOTER("1");
}
int lua_fairygui_UIPackage_getItemURL(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:getItemURL");
	LUA_TRY_INVOKE_R(2, &fairygui::UIPackage::getItemURL);
	LUA_SINVOKE_FOOTER("2");
}
int lua_fairygui_UIPackage_getVar(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:getVar");
	LUA_TRY_INVOKE_R(1, &fairygui::UIPackage::getVar);
	LUA_SINVOKE_FOOTER("1");
}
int lua_fairygui_UIPackage_normalizeURL(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:normalizeURL");
	LUA_TRY_INVOKE_R(1, &fairygui::UIPackage::normalizeURL);
	LUA_SINVOKE_FOOTER("1");
}
int lua_fairygui_UIPackage_removeAllPackages(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:removeAllPackages");
	LUA_TRY_INVOKE(0, &fairygui::UIPackage::removeAllPackages);
	LUA_SINVOKE_FOOTER("0");
}
int lua_fairygui_UIPackage_removePackage(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:removePackage");
	LUA_TRY_INVOKE(1, &fairygui::UIPackage::removePackage);
	LUA_SINVOKE_FOOTER("1");
}
int lua_fairygui_UIPackage_setBranch(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:setBranch");
	LUA_TRY_INVOKE(1, &fairygui::UIPackage::setBranch);
	LUA_SINVOKE_FOOTER("1");
}
int lua_fairygui_UIPackage_setVar(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIPackage", "fgui.UIPackage:setVar");
	LUA_TRY_INVOKE(2, &fairygui::UIPackage::setVar);
	LUA_SINVOKE_FOOTER("2");
}
int luaReg_fgui_fguiUIPackage(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::UIPackage, "UIPackage", "fgui.UIPackage",
		cocos2d::Ref, "fgui.cocos2d.Ref",
		nullptr, nullptr);
	LUA_SFIELD("URL_PREFIX", lua_fairygui_UIPackage_URL_PREFIX_getter, nullptr);
	LUA_SFIELD("_constructing", lua_fairygui_UIPackage__constructing_getter, lua_fairygui_UIPackage__constructing_setter);
	LUA_METHOD("getId", lua_fairygui_UIPackage_getId);
	LUA_METHOD("getItem", lua_fairygui_UIPackage_getItem);
	LUA_METHOD("getItemByName", lua_fairygui_UIPackage_getItemByName);
	LUA_METHOD("getName", lua_fairygui_UIPackage_getName);
	LUA_METHOD("addPackage", lua_fairygui_UIPackage_addPackage);
	LUA_METHOD("createObject", lua_fairygui_UIPackage_createObject);
	LUA_METHOD("createObjectFromURL", lua_fairygui_UIPackage_createObjectFromURL);
	LUA_METHOD("getBranch", lua_fairygui_UIPackage_getBranch);
	LUA_METHOD("getById", lua_fairygui_UIPackage_getById);
	LUA_METHOD("getByName", lua_fairygui_UIPackage_getByName);
	LUA_METHOD("getEmptyTexture", lua_fairygui_UIPackage_getEmptyTexture);
	LUA_METHOD("getItemByURL", lua_fairygui_UIPackage_getItemByURL);
	LUA_METHOD("getItemURL", lua_fairygui_UIPackage_getItemURL);
	LUA_METHOD("getVar", lua_fairygui_UIPackage_getVar);
	LUA_METHOD("normalizeURL", lua_fairygui_UIPackage_normalizeURL);
	LUA_METHOD("removeAllPackages", lua_fairygui_UIPackage_removeAllPackages);
	LUA_METHOD("removePackage", lua_fairygui_UIPackage_removePackage);
	LUA_METHOD("setBranch", lua_fairygui_UIPackage_setBranch);
	LUA_METHOD("setVar", lua_fairygui_UIPackage_setVar);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GImage_getColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GImage", "fgui.GImage:getColor");
	LUA_TRY_INVOKE_R(0, &fairygui::GImage::getColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GImage_getFillAmount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GImage", "fgui.GImage:getFillAmount");
	LUA_TRY_INVOKE_R(0, &fairygui::GImage::getFillAmount);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GImage_getFillMethod(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GImage", "fgui.GImage:getFillMethod");
	LUA_TRY_INVOKE_R(0, &fairygui::GImage::getFillMethod);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GImage_getFillOrigin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GImage", "fgui.GImage:getFillOrigin");
	LUA_TRY_INVOKE_R(0, &fairygui::GImage::getFillOrigin);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GImage_getFlip(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GImage", "fgui.GImage:getFlip");
	LUA_TRY_INVOKE_R(0, &fairygui::GImage::getFlip);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GImage_isFillClockwise(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GImage", "fgui.GImage:isFillClockwise");
	LUA_TRY_INVOKE_R(0, &fairygui::GImage::isFillClockwise);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GImage_setColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GImage", "fgui.GImage:setColor");
	LUA_TRY_INVOKE(1, &fairygui::GImage::setColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GImage_setFillAmount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GImage", "fgui.GImage:setFillAmount");
	LUA_TRY_INVOKE(1, &fairygui::GImage::setFillAmount);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GImage_setFillClockwise(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GImage", "fgui.GImage:setFillClockwise");
	LUA_TRY_INVOKE(1, &fairygui::GImage::setFillClockwise);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GImage_setFillMethod(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GImage", "fgui.GImage:setFillMethod");
	LUA_TRY_INVOKE(1, &fairygui::GImage::setFillMethod);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GImage_setFillOrigin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GImage", "fgui.GImage:setFillOrigin");
	LUA_TRY_INVOKE(1, &fairygui::GImage::setFillOrigin);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GImage_setFlip(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GImage", "fgui.GImage:setFlip");
	LUA_TRY_INVOKE(1, &fairygui::GImage::setFlip);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GImage_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GImage", "fgui.GImage:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GImage::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGImage(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GImage, "GImage", "fgui.GImage",
		fairygui::GObject, "fgui.GObject",
		nullptr, nullptr);
	LUA_METHOD("getColor", lua_fairygui_GImage_getColor);
	LUA_METHOD("getFillAmount", lua_fairygui_GImage_getFillAmount);
	LUA_METHOD("getFillMethod", lua_fairygui_GImage_getFillMethod);
	LUA_METHOD("getFillOrigin", lua_fairygui_GImage_getFillOrigin);
	LUA_METHOD("getFlip", lua_fairygui_GImage_getFlip);
	LUA_METHOD("isFillClockwise", lua_fairygui_GImage_isFillClockwise);
	LUA_METHOD("setColor", lua_fairygui_GImage_setColor);
	LUA_METHOD("setFillAmount", lua_fairygui_GImage_setFillAmount);
	LUA_METHOD("setFillClockwise", lua_fairygui_GImage_setFillClockwise);
	LUA_METHOD("setFillMethod", lua_fairygui_GImage_setFillMethod);
	LUA_METHOD("setFillOrigin", lua_fairygui_GImage_setFillOrigin);
	LUA_METHOD("setFlip", lua_fairygui_GImage_setFlip);
	LUA_METHOD("create", lua_fairygui_GImage_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GMovieClip_advance(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GMovieClip", "fgui.GMovieClip:advance");
	LUA_TRY_INVOKE(1, &fairygui::GMovieClip::advance);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GMovieClip_getColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GMovieClip", "fgui.GMovieClip:getColor");
	LUA_TRY_INVOKE_R(0, &fairygui::GMovieClip::getColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GMovieClip_getFlip(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GMovieClip", "fgui.GMovieClip:getFlip");
	LUA_TRY_INVOKE_R(0, &fairygui::GMovieClip::getFlip);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GMovieClip_getFrame(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GMovieClip", "fgui.GMovieClip:getFrame");
	LUA_TRY_INVOKE_R(0, &fairygui::GMovieClip::getFrame);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GMovieClip_getTimeScale(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GMovieClip", "fgui.GMovieClip:getTimeScale");
	LUA_TRY_INVOKE_R(0, &fairygui::GMovieClip::getTimeScale);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GMovieClip_isPlaying(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GMovieClip", "fgui.GMovieClip:isPlaying");
	LUA_TRY_INVOKE_R(0, &fairygui::GMovieClip::isPlaying);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GMovieClip_setColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GMovieClip", "fgui.GMovieClip:setColor");
	LUA_TRY_INVOKE(1, &fairygui::GMovieClip::setColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GMovieClip_setFlip(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GMovieClip", "fgui.GMovieClip:setFlip");
	LUA_TRY_INVOKE(1, &fairygui::GMovieClip::setFlip);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GMovieClip_setFrame(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GMovieClip", "fgui.GMovieClip:setFrame");
	LUA_TRY_INVOKE(1, &fairygui::GMovieClip::setFrame);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GMovieClip_setPlaySettings(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GMovieClip", "fgui.GMovieClip:setPlaySettings");
	LUA_TRY_INVOKE(5, static_cast<void(fairygui::GMovieClip::*)(int, int, int, int, std::function<void ()>)>(&fairygui::GMovieClip::setPlaySettings));
	LUA_TRY_INVOKE(4, [](fairygui::GMovieClip* obj, int arg0,int arg1,int arg2,int arg3){{return obj->setPlaySettings(std::move(arg0),std::move(arg1),std::move(arg2),std::move(arg3));}});
	LUA_TRY_INVOKE(3, [](fairygui::GMovieClip* obj, int arg0,int arg1,int arg2){{return obj->setPlaySettings(std::move(arg0),std::move(arg1),std::move(arg2));}});
	LUA_TRY_INVOKE(2, [](fairygui::GMovieClip* obj, int arg0,int arg1){{return obj->setPlaySettings(std::move(arg0),std::move(arg1));}});
	LUA_TRY_INVOKE(1, [](fairygui::GMovieClip* obj, int arg0){{return obj->setPlaySettings(std::move(arg0));}});
	LUA_TRY_INVOKE(0, [](fairygui::GMovieClip* obj){{return obj->setPlaySettings();}});
	LUA_INVOKE_FOOTER("0,1,2,3,4,5");
}
int lua_fairygui_GMovieClip_setPlaying(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GMovieClip", "fgui.GMovieClip:setPlaying");
	LUA_TRY_INVOKE(1, &fairygui::GMovieClip::setPlaying);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GMovieClip_setTimeScale(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GMovieClip", "fgui.GMovieClip:setTimeScale");
	LUA_TRY_INVOKE(1, &fairygui::GMovieClip::setTimeScale);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GMovieClip_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GMovieClip", "fgui.GMovieClip:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GMovieClip::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGMovieClip(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GMovieClip, "GMovieClip", "fgui.GMovieClip",
		fairygui::GObject, "fgui.GObject",
		nullptr, nullptr);
	LUA_METHOD("advance", lua_fairygui_GMovieClip_advance);
	LUA_METHOD("getColor", lua_fairygui_GMovieClip_getColor);
	LUA_METHOD("getFlip", lua_fairygui_GMovieClip_getFlip);
	LUA_METHOD("getFrame", lua_fairygui_GMovieClip_getFrame);
	LUA_METHOD("getTimeScale", lua_fairygui_GMovieClip_getTimeScale);
	LUA_METHOD("isPlaying", lua_fairygui_GMovieClip_isPlaying);
	LUA_METHOD("setColor", lua_fairygui_GMovieClip_setColor);
	LUA_METHOD("setFlip", lua_fairygui_GMovieClip_setFlip);
	LUA_METHOD("setFrame", lua_fairygui_GMovieClip_setFrame);
	LUA_METHOD("setPlaySettings", lua_fairygui_GMovieClip_setPlaySettings);
	LUA_METHOD("setPlaying", lua_fairygui_GMovieClip_setPlaying);
	LUA_METHOD("setTimeScale", lua_fairygui_GMovieClip_setTimeScale);
	LUA_METHOD("create", lua_fairygui_GMovieClip_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_TextFormat_new(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.TextFormat", "fgui.TextFormat:new");
	LUA_TRY_CTOR(1, [](const fairygui::TextFormat& arg0){{return new fairygui::TextFormat(arg0);}});
	LUA_TRY_CTOR(0, [](){{return new fairygui::TextFormat();}});
	LUA_SINVOKE_FOOTER("0,1");
}
int lua_fairygui_TextFormat_delete(lua_State* lua_S)
{
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	delete cobj;
	return 0;
}
int lua_fairygui_TextFormat_GLOW_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.GLOW/getter");
	LUA_PUSH_NATIVE(fairygui::TextFormat::GLOW);
	return 1;
}
int lua_fairygui_TextFormat_OUTLINE_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.OUTLINE/getter");
	LUA_PUSH_NATIVE(fairygui::TextFormat::OUTLINE);
	return 1;
}
int lua_fairygui_TextFormat_SHADOW_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.SHADOW/getter");
	LUA_PUSH_NATIVE(fairygui::TextFormat::SHADOW);
	return 1;
}
int lua_fairygui_TextFormat__hasColor_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat._hasColor/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->_hasColor);
	return 1;
}
int lua_fairygui_TextFormat__hasColor_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat._hasColor/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->_hasColor, 2);
	return 0;
}
int lua_fairygui_TextFormat_align_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.align/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->align);
	return 1;
}
int lua_fairygui_TextFormat_align_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.align/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->align, 2);
	return 0;
}
int lua_fairygui_TextFormat_bold_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.bold/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->bold);
	return 1;
}
int lua_fairygui_TextFormat_bold_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.bold/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->bold, 2);
	return 0;
}
int lua_fairygui_TextFormat_color_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.color/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->color);
	return 1;
}
int lua_fairygui_TextFormat_color_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.color/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->color, 2);
	return 0;
}
int lua_fairygui_TextFormat_effect_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.effect/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->effect);
	return 1;
}
int lua_fairygui_TextFormat_effect_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.effect/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->effect, 2);
	return 0;
}
int lua_fairygui_TextFormat_face_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.face/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->face);
	return 1;
}
int lua_fairygui_TextFormat_face_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.face/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->face, 2);
	return 0;
}
int lua_fairygui_TextFormat_fontSize_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.fontSize/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->fontSize);
	return 1;
}
int lua_fairygui_TextFormat_fontSize_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.fontSize/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->fontSize, 2);
	return 0;
}
int lua_fairygui_TextFormat_glowColor_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.glowColor/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->glowColor);
	return 1;
}
int lua_fairygui_TextFormat_glowColor_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.glowColor/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->glowColor, 2);
	return 0;
}
int lua_fairygui_TextFormat_italics_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.italics/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->italics);
	return 1;
}
int lua_fairygui_TextFormat_italics_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.italics/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->italics, 2);
	return 0;
}
int lua_fairygui_TextFormat_letterSpacing_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.letterSpacing/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->letterSpacing);
	return 1;
}
int lua_fairygui_TextFormat_letterSpacing_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.letterSpacing/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->letterSpacing, 2);
	return 0;
}
int lua_fairygui_TextFormat_lineSpacing_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.lineSpacing/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->lineSpacing);
	return 1;
}
int lua_fairygui_TextFormat_lineSpacing_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.lineSpacing/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->lineSpacing, 2);
	return 0;
}
int lua_fairygui_TextFormat_outlineColor_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.outlineColor/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->outlineColor);
	return 1;
}
int lua_fairygui_TextFormat_outlineColor_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.outlineColor/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->outlineColor, 2);
	return 0;
}
int lua_fairygui_TextFormat_outlineSize_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.outlineSize/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->outlineSize);
	return 1;
}
int lua_fairygui_TextFormat_outlineSize_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.outlineSize/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->outlineSize, 2);
	return 0;
}
int lua_fairygui_TextFormat_shadowBlurRadius_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.shadowBlurRadius/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->shadowBlurRadius);
	return 1;
}
int lua_fairygui_TextFormat_shadowBlurRadius_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.shadowBlurRadius/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->shadowBlurRadius, 2);
	return 0;
}
int lua_fairygui_TextFormat_shadowColor_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.shadowColor/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->shadowColor);
	return 1;
}
int lua_fairygui_TextFormat_shadowColor_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.shadowColor/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->shadowColor, 2);
	return 0;
}
int lua_fairygui_TextFormat_shadowOffset_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.shadowOffset/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->shadowOffset);
	return 1;
}
int lua_fairygui_TextFormat_shadowOffset_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.shadowOffset/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->shadowOffset, 2);
	return 0;
}
int lua_fairygui_TextFormat_underline_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.underline/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->underline);
	return 1;
}
int lua_fairygui_TextFormat_underline_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.underline/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->underline, 2);
	return 0;
}
int lua_fairygui_TextFormat_verticalAlign_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.verticalAlign/getter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_PUSH_NATIVE(cobj->verticalAlign);
	return 1;
}
int lua_fairygui_TextFormat_verticalAlign_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.TextFormat.verticalAlign/setter");
	auto cobj = LUA_TO_COBJ(fairygui::TextFormat*, 1);
	LUA_NATIVE_SETTER(cobj->verticalAlign, 2);
	return 0;
}
int lua_fairygui_TextFormat_disableEffect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.TextFormat", "fgui.TextFormat:disableEffect");
	LUA_TRY_INVOKE(1, &fairygui::TextFormat::disableEffect);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_TextFormat_enableEffect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.TextFormat", "fgui.TextFormat:enableEffect");
	LUA_TRY_INVOKE(1, &fairygui::TextFormat::enableEffect);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_TextFormat_hasEffect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.TextFormat", "fgui.TextFormat:hasEffect");
	LUA_TRY_INVOKE_R(1, &fairygui::TextFormat::hasEffect);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_TextFormat_setFormat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.TextFormat", "fgui.TextFormat:setFormat");
	LUA_TRY_INVOKE(1, &fairygui::TextFormat::setFormat);
	LUA_INVOKE_FOOTER("1");
}
int luaReg_fgui_fguiTextFormat(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::TextFormat, "TextFormat", "fgui.TextFormat",
		lua_fairygui_TextFormat_new, lua_fairygui_TextFormat_delete);
	LUA_METHOD("new", lua_fairygui_TextFormat_new);
	LUA_SFIELD("GLOW", lua_fairygui_TextFormat_GLOW_getter, nullptr);
	LUA_SFIELD("OUTLINE", lua_fairygui_TextFormat_OUTLINE_getter, nullptr);
	LUA_SFIELD("SHADOW", lua_fairygui_TextFormat_SHADOW_getter, nullptr);
	LUA_FIELD("_hasColor", lua_fairygui_TextFormat__hasColor_getter, lua_fairygui_TextFormat__hasColor_setter);
	LUA_FIELD("align", lua_fairygui_TextFormat_align_getter, lua_fairygui_TextFormat_align_setter);
	LUA_FIELD("bold", lua_fairygui_TextFormat_bold_getter, lua_fairygui_TextFormat_bold_setter);
	LUA_FIELD("color", lua_fairygui_TextFormat_color_getter, lua_fairygui_TextFormat_color_setter);
	LUA_FIELD("effect", lua_fairygui_TextFormat_effect_getter, lua_fairygui_TextFormat_effect_setter);
	LUA_FIELD("face", lua_fairygui_TextFormat_face_getter, lua_fairygui_TextFormat_face_setter);
	LUA_FIELD("fontSize", lua_fairygui_TextFormat_fontSize_getter, lua_fairygui_TextFormat_fontSize_setter);
	LUA_FIELD("glowColor", lua_fairygui_TextFormat_glowColor_getter, lua_fairygui_TextFormat_glowColor_setter);
	LUA_FIELD("italics", lua_fairygui_TextFormat_italics_getter, lua_fairygui_TextFormat_italics_setter);
	LUA_FIELD("letterSpacing", lua_fairygui_TextFormat_letterSpacing_getter, lua_fairygui_TextFormat_letterSpacing_setter);
	LUA_FIELD("lineSpacing", lua_fairygui_TextFormat_lineSpacing_getter, lua_fairygui_TextFormat_lineSpacing_setter);
	LUA_FIELD("outlineColor", lua_fairygui_TextFormat_outlineColor_getter, lua_fairygui_TextFormat_outlineColor_setter);
	LUA_FIELD("outlineSize", lua_fairygui_TextFormat_outlineSize_getter, lua_fairygui_TextFormat_outlineSize_setter);
	LUA_FIELD("shadowBlurRadius", lua_fairygui_TextFormat_shadowBlurRadius_getter, lua_fairygui_TextFormat_shadowBlurRadius_setter);
	LUA_FIELD("shadowColor", lua_fairygui_TextFormat_shadowColor_getter, lua_fairygui_TextFormat_shadowColor_setter);
	LUA_FIELD("shadowOffset", lua_fairygui_TextFormat_shadowOffset_getter, lua_fairygui_TextFormat_shadowOffset_setter);
	LUA_FIELD("underline", lua_fairygui_TextFormat_underline_getter, lua_fairygui_TextFormat_underline_setter);
	LUA_FIELD("verticalAlign", lua_fairygui_TextFormat_verticalAlign_getter, lua_fairygui_TextFormat_verticalAlign_setter);
	LUA_METHOD("disableEffect", lua_fairygui_TextFormat_disableEffect);
	LUA_METHOD("enableEffect", lua_fairygui_TextFormat_enableEffect);
	LUA_METHOD("hasEffect", lua_fairygui_TextFormat_hasEffect);
	LUA_METHOD("setFormat", lua_fairygui_TextFormat_setFormat);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_FUILabel_applyTextFormat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUILabel", "fgui.FUILabel:applyTextFormat");
	LUA_TRY_INVOKE(0, &fairygui::FUILabel::applyTextFormat);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUILabel_getText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUILabel", "fgui.FUILabel:getText");
	LUA_TRY_INVOKE_R(0, &fairygui::FUILabel::getText);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUILabel_getTextFormat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUILabel", "fgui.FUILabel:getTextFormat");
	LUA_TRY_INVOKE_R(0, &fairygui::FUILabel::getTextFormat);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUILabel_setGrayed(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUILabel", "fgui.FUILabel:setGrayed");
	LUA_TRY_INVOKE(1, &fairygui::FUILabel::setGrayed);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUILabel_setText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUILabel", "fgui.FUILabel:setText");
	LUA_TRY_INVOKE(1, &fairygui::FUILabel::setText);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUILabel_setUnderlineColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUILabel", "fgui.FUILabel:setUnderlineColor");
	LUA_TRY_INVOKE(1, &fairygui::FUILabel::setUnderlineColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUILabel_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.FUILabel", "fgui.FUILabel:create");
	LUA_TRY_INVOKE_R(0, &fairygui::FUILabel::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiFUILabel(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::FUILabel, "FUILabel", "fgui.FUILabel",
		cocos2d::Label, "fgui.cocos2d.Label",
		nullptr, nullptr);
	LUA_METHOD("applyTextFormat", lua_fairygui_FUILabel_applyTextFormat);
	LUA_METHOD("getText", lua_fairygui_FUILabel_getText);
	LUA_METHOD("getTextFormat", lua_fairygui_FUILabel_getTextFormat);
	LUA_METHOD("setGrayed", lua_fairygui_FUILabel_setGrayed);
	LUA_METHOD("setText", lua_fairygui_FUILabel_setText);
	LUA_METHOD("setUnderlineColor", lua_fairygui_FUILabel_setUnderlineColor);
	LUA_METHOD("create", lua_fairygui_FUILabel_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GTextField_applyTextFormat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:applyTextFormat");
	LUA_TRY_INVOKE(0, &fairygui::GTextField::applyTextFormat);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTextField_flushVars(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:flushVars");
	LUA_TRY_INVOKE(0, &fairygui::GTextField::flushVars);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTextField_getAutoSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:getAutoSize");
	LUA_TRY_INVOKE_R(0, &fairygui::GTextField::getAutoSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTextField_getColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:getColor");
	LUA_TRY_INVOKE_R(0, &fairygui::GTextField::getColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTextField_getFontSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:getFontSize");
	LUA_TRY_INVOKE_R(0, &fairygui::GTextField::getFontSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTextField_getOutlineColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:getOutlineColor");
	LUA_TRY_INVOKE_R(0, &fairygui::GTextField::getOutlineColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTextField_getTextFormat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:getTextFormat");
	LUA_TRY_INVOKE_R(0, &fairygui::GTextField::getTextFormat);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTextField_getTextSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:getTextSize");
	LUA_TRY_INVOKE_R(0, &fairygui::GTextField::getTextSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTextField_isSingleLine(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:isSingleLine");
	LUA_TRY_INVOKE_R(0, &fairygui::GTextField::isSingleLine);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTextField_isUBBEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:isUBBEnabled");
	LUA_TRY_INVOKE_R(0, &fairygui::GTextField::isUBBEnabled);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTextField_setAutoSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:setAutoSize");
	LUA_TRY_INVOKE(1, &fairygui::GTextField::setAutoSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTextField_setColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:setColor");
	LUA_TRY_INVOKE(1, &fairygui::GTextField::setColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTextField_setFontSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:setFontSize");
	LUA_TRY_INVOKE(1, &fairygui::GTextField::setFontSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTextField_setOutlineColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:setOutlineColor");
	LUA_TRY_INVOKE(1, &fairygui::GTextField::setOutlineColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTextField_setSingleLine(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:setSingleLine");
	LUA_TRY_INVOKE(1, &fairygui::GTextField::setSingleLine);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTextField_setUBBEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:setUBBEnabled");
	LUA_TRY_INVOKE(1, &fairygui::GTextField::setUBBEnabled);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTextField_setVar(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextField", "fgui.GTextField:setVar");
	LUA_TRY_INVOKE_R(2, &fairygui::GTextField::setVar);
	LUA_INVOKE_FOOTER("2");
}
int luaReg_fgui_fguiGTextField(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GTextField, "GTextField", "fgui.GTextField",
		fairygui::GObject, "fgui.GObject",
		nullptr, nullptr);
	LUA_METHOD("applyTextFormat", lua_fairygui_GTextField_applyTextFormat);
	LUA_METHOD("flushVars", lua_fairygui_GTextField_flushVars);
	LUA_METHOD("getAutoSize", lua_fairygui_GTextField_getAutoSize);
	LUA_METHOD("getColor", lua_fairygui_GTextField_getColor);
	LUA_METHOD("getFontSize", lua_fairygui_GTextField_getFontSize);
	LUA_METHOD("getOutlineColor", lua_fairygui_GTextField_getOutlineColor);
	LUA_METHOD("getTextFormat", lua_fairygui_GTextField_getTextFormat);
	LUA_METHOD("getTextSize", lua_fairygui_GTextField_getTextSize);
	LUA_METHOD("isSingleLine", lua_fairygui_GTextField_isSingleLine);
	LUA_METHOD("isUBBEnabled", lua_fairygui_GTextField_isUBBEnabled);
	LUA_METHOD("setAutoSize", lua_fairygui_GTextField_setAutoSize);
	LUA_METHOD("setColor", lua_fairygui_GTextField_setColor);
	LUA_METHOD("setFontSize", lua_fairygui_GTextField_setFontSize);
	LUA_METHOD("setOutlineColor", lua_fairygui_GTextField_setOutlineColor);
	LUA_METHOD("setSingleLine", lua_fairygui_GTextField_setSingleLine);
	LUA_METHOD("setUBBEnabled", lua_fairygui_GTextField_setUBBEnabled);
	LUA_METHOD("setVar", lua_fairygui_GTextField_setVar);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GBasicTextField_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GBasicTextField", "fgui.GBasicTextField:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GBasicTextField::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGBasicTextField(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GBasicTextField, "GBasicTextField", "fgui.GBasicTextField",
		fairygui::GTextField, "fgui.GTextField",
		nullptr, nullptr);
	LUA_METHOD("create", lua_fairygui_GBasicTextField_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_FUIRichText_applyTextFormat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:applyTextFormat");
	LUA_TRY_INVOKE(0, &fairygui::FUIRichText::applyTextFormat);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIRichText_getAnchorFontColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:getAnchorFontColor");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIRichText::getAnchorFontColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIRichText_getControl(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:getControl");
	LUA_TRY_INVOKE_R(1, &fairygui::FUIRichText::getControl);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIRichText_getControls(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:getControls");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIRichText::getControls);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIRichText_getDimensions(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:getDimensions");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIRichText::getDimensions);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIRichText_getOverflow(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:getOverflow");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIRichText::getOverflow);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIRichText_getTextFormat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:getTextFormat");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIRichText::getTextFormat);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIRichText_hitTestLink(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:hitTestLink");
	LUA_TRY_INVOKE_R(1, &fairygui::FUIRichText::hitTestLink);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIRichText_isAnchorTextUnderline(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:isAnchorTextUnderline");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIRichText::isAnchorTextUnderline);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIRichText_parseOptions(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:parseOptions");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIRichText::parseOptions);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIRichText_setAnchorFontColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:setAnchorFontColor");
	LUA_TRY_INVOKE(1, &fairygui::FUIRichText::setAnchorFontColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIRichText_setAnchorTextUnderline(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:setAnchorTextUnderline");
	LUA_TRY_INVOKE(1, &fairygui::FUIRichText::setAnchorTextUnderline);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIRichText_setDimensions(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:setDimensions");
	LUA_TRY_INVOKE(2, &fairygui::FUIRichText::setDimensions);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_FUIRichText_setObjectFactory(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:setObjectFactory");
	LUA_TRY_INVOKE(1, &fairygui::FUIRichText::setObjectFactory);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIRichText_setOverflow(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:setOverflow");
	LUA_TRY_INVOKE(1, &fairygui::FUIRichText::setOverflow);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIRichText_setText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:setText");
	LUA_TRY_INVOKE(1, &fairygui::FUIRichText::setText);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIRichText_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.FUIRichText", "fgui.FUIRichText:create");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIRichText::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiFUIRichText(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::FUIRichText, "FUIRichText", "fgui.FUIRichText",
		cocos2d::Node, "fgui.cocos2d.Node",
		nullptr, nullptr);
	LUA_METHOD("applyTextFormat", lua_fairygui_FUIRichText_applyTextFormat);
	LUA_METHOD("getAnchorFontColor", lua_fairygui_FUIRichText_getAnchorFontColor);
	LUA_METHOD("getControl", lua_fairygui_FUIRichText_getControl);
	LUA_METHOD("getControls", lua_fairygui_FUIRichText_getControls);
	LUA_METHOD("getDimensions", lua_fairygui_FUIRichText_getDimensions);
	LUA_METHOD("getOverflow", lua_fairygui_FUIRichText_getOverflow);
	LUA_METHOD("getTextFormat", lua_fairygui_FUIRichText_getTextFormat);
	LUA_METHOD("hitTestLink", lua_fairygui_FUIRichText_hitTestLink);
	LUA_METHOD("isAnchorTextUnderline", lua_fairygui_FUIRichText_isAnchorTextUnderline);
	LUA_METHOD("parseOptions", lua_fairygui_FUIRichText_parseOptions);
	LUA_METHOD("setAnchorFontColor", lua_fairygui_FUIRichText_setAnchorFontColor);
	LUA_METHOD("setAnchorTextUnderline", lua_fairygui_FUIRichText_setAnchorTextUnderline);
	LUA_METHOD("setDimensions", lua_fairygui_FUIRichText_setDimensions);
	LUA_METHOD("setObjectFactory", lua_fairygui_FUIRichText_setObjectFactory);
	LUA_METHOD("setOverflow", lua_fairygui_FUIRichText_setOverflow);
	LUA_METHOD("setText", lua_fairygui_FUIRichText_setText);
	LUA_METHOD("create", lua_fairygui_FUIRichText_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GRichTextField_getControl(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRichTextField", "fgui.GRichTextField:getControl");
	LUA_TRY_INVOKE_R(1, &fairygui::GRichTextField::getControl);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GRichTextField_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GRichTextField", "fgui.GRichTextField:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GRichTextField::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGRichTextField(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GRichTextField, "GRichTextField", "fgui.GRichTextField",
		fairygui::GTextField, "fgui.GTextField",
		nullptr, nullptr);
	LUA_METHOD("getControl", lua_fairygui_GRichTextField_getControl);
	LUA_METHOD("create", lua_fairygui_GRichTextField_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_FUIInput_applyTextFormat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIInput", "fgui.FUIInput:applyTextFormat");
	LUA_TRY_INVOKE(0, &fairygui::FUIInput::applyTextFormat);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIInput_getText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIInput", "fgui.FUIInput:getText");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIInput::getText);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIInput_getTextFormat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIInput", "fgui.FUIInput:getTextFormat");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIInput::getTextFormat);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIInput_isPassword(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIInput", "fgui.FUIInput:isPassword");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIInput::isPassword);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIInput_isSingleLine(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIInput", "fgui.FUIInput:isSingleLine");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIInput::isSingleLine);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIInput_keyboardType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIInput", "fgui.FUIInput:keyboardType");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIInput::keyboardType);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIInput_openKeyboard(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIInput", "fgui.FUIInput:openKeyboard");
	LUA_TRY_INVOKE(0, &fairygui::FUIInput::openKeyboard);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIInput_setKeyboardType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIInput", "fgui.FUIInput:setKeyboardType");
	LUA_TRY_INVOKE(1, &fairygui::FUIInput::setKeyboardType);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIInput_setPassword(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIInput", "fgui.FUIInput:setPassword");
	LUA_TRY_INVOKE(1, &fairygui::FUIInput::setPassword);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIInput_setSingleLine(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIInput", "fgui.FUIInput:setSingleLine");
	LUA_TRY_INVOKE(1, &fairygui::FUIInput::setSingleLine);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIInput_setText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIInput", "fgui.FUIInput:setText");
	LUA_TRY_INVOKE(1, &fairygui::FUIInput::setText);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIInput_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.FUIInput", "fgui.FUIInput:create");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIInput::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiFUIInput(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::FUIInput, "FUIInput", "fgui.FUIInput",
		cocos2d::ui::EditBox, "fgui.cocos2d.ui.EditBox",
		nullptr, nullptr);
	LUA_METHOD("applyTextFormat", lua_fairygui_FUIInput_applyTextFormat);
	LUA_METHOD("getText", lua_fairygui_FUIInput_getText);
	LUA_METHOD("getTextFormat", lua_fairygui_FUIInput_getTextFormat);
	LUA_METHOD("isPassword", lua_fairygui_FUIInput_isPassword);
	LUA_METHOD("isSingleLine", lua_fairygui_FUIInput_isSingleLine);
	LUA_METHOD("keyboardType", lua_fairygui_FUIInput_keyboardType);
	LUA_METHOD("openKeyboard", lua_fairygui_FUIInput_openKeyboard);
	LUA_METHOD("setKeyboardType", lua_fairygui_FUIInput_setKeyboardType);
	LUA_METHOD("setPassword", lua_fairygui_FUIInput_setPassword);
	LUA_METHOD("setSingleLine", lua_fairygui_FUIInput_setSingleLine);
	LUA_METHOD("setText", lua_fairygui_FUIInput_setText);
	LUA_METHOD("create", lua_fairygui_FUIInput_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GTextInput_setKeyboardType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextInput", "fgui.GTextInput:setKeyboardType");
	LUA_TRY_INVOKE(1, &fairygui::GTextInput::setKeyboardType);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTextInput_setMaxLength(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextInput", "fgui.GTextInput:setMaxLength");
	LUA_TRY_INVOKE(1, &fairygui::GTextInput::setMaxLength);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTextInput_setPassword(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextInput", "fgui.GTextInput:setPassword");
	LUA_TRY_INVOKE(1, &fairygui::GTextInput::setPassword);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTextInput_setPrompt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextInput", "fgui.GTextInput:setPrompt");
	LUA_TRY_INVOKE(1, &fairygui::GTextInput::setPrompt);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTextInput_setRestrict(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTextInput", "fgui.GTextInput:setRestrict");
	LUA_TRY_INVOKE(1, &fairygui::GTextInput::setRestrict);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTextInput_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GTextInput", "fgui.GTextInput:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GTextInput::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGTextInput(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GTextInput, "GTextInput", "fgui.GTextInput",
		fairygui::GTextField, "fgui.GTextField",
		nullptr, nullptr);
	LUA_METHOD("setKeyboardType", lua_fairygui_GTextInput_setKeyboardType);
	LUA_METHOD("setMaxLength", lua_fairygui_GTextInput_setMaxLength);
	LUA_METHOD("setPassword", lua_fairygui_GTextInput_setPassword);
	LUA_METHOD("setPrompt", lua_fairygui_GTextInput_setPrompt);
	LUA_METHOD("setRestrict", lua_fairygui_GTextInput_setRestrict);
	LUA_METHOD("create", lua_fairygui_GTextInput_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GGraph_drawEllipse(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGraph", "fgui.GGraph:drawEllipse");
	LUA_TRY_INVOKE(5, &fairygui::GGraph::drawEllipse);
	LUA_INVOKE_FOOTER("5");
}
int lua_fairygui_GGraph_drawRect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGraph", "fgui.GGraph:drawRect");
	LUA_TRY_INVOKE(5, &fairygui::GGraph::drawRect);
	LUA_INVOKE_FOOTER("5");
}
int lua_fairygui_GGraph_getColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGraph", "fgui.GGraph:getColor");
	LUA_TRY_INVOKE_R(0, &fairygui::GGraph::getColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GGraph_isEmpty(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGraph", "fgui.GGraph:isEmpty");
	LUA_TRY_INVOKE_R(0, &fairygui::GGraph::isEmpty);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GGraph_setColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGraph", "fgui.GGraph:setColor");
	LUA_TRY_INVOKE(1, &fairygui::GGraph::setColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GGraph_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GGraph", "fgui.GGraph:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GGraph::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGGraph(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GGraph, "GGraph", "fgui.GGraph",
		fairygui::GObject, "fgui.GObject",
		nullptr, nullptr);
	LUA_METHOD("drawEllipse", lua_fairygui_GGraph_drawEllipse);
	LUA_METHOD("drawRect", lua_fairygui_GGraph_drawRect);
	LUA_METHOD("getColor", lua_fairygui_GGraph_getColor);
	LUA_METHOD("isEmpty", lua_fairygui_GGraph_isEmpty);
	LUA_METHOD("setColor", lua_fairygui_GGraph_setColor);
	LUA_METHOD("create", lua_fairygui_GGraph_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GLoader_getAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:getAlign");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::getAlign);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_getAutoSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:getAutoSize");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::getAutoSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_getColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:getColor");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::getColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_getComponent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:getComponent");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::getComponent);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_getContentSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:getContentSize");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::getContentSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_getFill(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:getFill");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::getFill);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_getFillAmount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:getFillAmount");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::getFillAmount);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_getFillMethod(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:getFillMethod");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::getFillMethod);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_getFillOrigin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:getFillOrigin");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::getFillOrigin);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_getFrame(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:getFrame");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::getFrame);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_getURL(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:getURL");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::getURL);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_getVerticalAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:getVerticalAlign");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::getVerticalAlign);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_isFillClockwise(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:isFillClockwise");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::isFillClockwise);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_isPlaying(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:isPlaying");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::isPlaying);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_isShrinkOnly(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:isShrinkOnly");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::isShrinkOnly);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader_setAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:setAlign");
	LUA_TRY_INVOKE(1, &fairygui::GLoader::setAlign);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader_setAutoSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:setAutoSize");
	LUA_TRY_INVOKE(1, &fairygui::GLoader::setAutoSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader_setColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:setColor");
	LUA_TRY_INVOKE(1, &fairygui::GLoader::setColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader_setFill(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:setFill");
	LUA_TRY_INVOKE(1, &fairygui::GLoader::setFill);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader_setFillAmount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:setFillAmount");
	LUA_TRY_INVOKE(1, &fairygui::GLoader::setFillAmount);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader_setFillClockwise(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:setFillClockwise");
	LUA_TRY_INVOKE(1, &fairygui::GLoader::setFillClockwise);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader_setFillMethod(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:setFillMethod");
	LUA_TRY_INVOKE(1, &fairygui::GLoader::setFillMethod);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader_setFillOrigin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:setFillOrigin");
	LUA_TRY_INVOKE(1, &fairygui::GLoader::setFillOrigin);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader_setFrame(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:setFrame");
	LUA_TRY_INVOKE(1, &fairygui::GLoader::setFrame);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader_setPlaying(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:setPlaying");
	LUA_TRY_INVOKE(1, &fairygui::GLoader::setPlaying);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader_setShrinkOnly(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:setShrinkOnly");
	LUA_TRY_INVOKE(1, &fairygui::GLoader::setShrinkOnly);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader_setURL(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:setURL");
	LUA_TRY_INVOKE(1, &fairygui::GLoader::setURL);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader_setVerticalAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader", "fgui.GLoader:setVerticalAlign");
	LUA_TRY_INVOKE(1, &fairygui::GLoader::setVerticalAlign);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GLoader", "fgui.GLoader:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGLoader(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GLoader, "GLoader", "fgui.GLoader",
		fairygui::GObject, "fgui.GObject",
		nullptr, nullptr);
	LUA_METHOD("getAlign", lua_fairygui_GLoader_getAlign);
	LUA_METHOD("getAutoSize", lua_fairygui_GLoader_getAutoSize);
	LUA_METHOD("getColor", lua_fairygui_GLoader_getColor);
	LUA_METHOD("getComponent", lua_fairygui_GLoader_getComponent);
	LUA_METHOD("getContentSize", lua_fairygui_GLoader_getContentSize);
	LUA_METHOD("getFill", lua_fairygui_GLoader_getFill);
	LUA_METHOD("getFillAmount", lua_fairygui_GLoader_getFillAmount);
	LUA_METHOD("getFillMethod", lua_fairygui_GLoader_getFillMethod);
	LUA_METHOD("getFillOrigin", lua_fairygui_GLoader_getFillOrigin);
	LUA_METHOD("getFrame", lua_fairygui_GLoader_getFrame);
	LUA_METHOD("getURL", lua_fairygui_GLoader_getURL);
	LUA_METHOD("getVerticalAlign", lua_fairygui_GLoader_getVerticalAlign);
	LUA_METHOD("isFillClockwise", lua_fairygui_GLoader_isFillClockwise);
	LUA_METHOD("isPlaying", lua_fairygui_GLoader_isPlaying);
	LUA_METHOD("isShrinkOnly", lua_fairygui_GLoader_isShrinkOnly);
	LUA_METHOD("setAlign", lua_fairygui_GLoader_setAlign);
	LUA_METHOD("setAutoSize", lua_fairygui_GLoader_setAutoSize);
	LUA_METHOD("setColor", lua_fairygui_GLoader_setColor);
	LUA_METHOD("setFill", lua_fairygui_GLoader_setFill);
	LUA_METHOD("setFillAmount", lua_fairygui_GLoader_setFillAmount);
	LUA_METHOD("setFillClockwise", lua_fairygui_GLoader_setFillClockwise);
	LUA_METHOD("setFillMethod", lua_fairygui_GLoader_setFillMethod);
	LUA_METHOD("setFillOrigin", lua_fairygui_GLoader_setFillOrigin);
	LUA_METHOD("setFrame", lua_fairygui_GLoader_setFrame);
	LUA_METHOD("setPlaying", lua_fairygui_GLoader_setPlaying);
	LUA_METHOD("setShrinkOnly", lua_fairygui_GLoader_setShrinkOnly);
	LUA_METHOD("setURL", lua_fairygui_GLoader_setURL);
	LUA_METHOD("setVerticalAlign", lua_fairygui_GLoader_setVerticalAlign);
	LUA_METHOD("create", lua_fairygui_GLoader_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GGroup__updating_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GGroup._updating/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GGroup*, 1);
	LUA_PUSH_NATIVE(cobj->_updating);
	return 1;
}
int lua_fairygui_GGroup__updating_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GGroup._updating/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GGroup*, 1);
	LUA_NATIVE_SETTER(cobj->_updating, 2);
	return 0;
}
int lua_fairygui_GGroup_getColumnGap(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:getColumnGap");
	LUA_TRY_INVOKE_R(0, &fairygui::GGroup::getColumnGap);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GGroup_getLayout(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:getLayout");
	LUA_TRY_INVOKE_R(0, &fairygui::GGroup::getLayout);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GGroup_getLineGap(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:getLineGap");
	LUA_TRY_INVOKE_R(0, &fairygui::GGroup::getLineGap);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GGroup_getMainGridIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:getMainGridIndex");
	LUA_TRY_INVOKE_R(0, &fairygui::GGroup::getMainGridIndex);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GGroup_getMainGridMinSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:getMainGridMinSize");
	LUA_TRY_INVOKE_R(0, &fairygui::GGroup::getMainGridMinSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GGroup_isAutoSizeDisabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:isAutoSizeDisabled");
	LUA_TRY_INVOKE_R(0, &fairygui::GGroup::isAutoSizeDisabled);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GGroup_isExcludeInvisibles(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:isExcludeInvisibles");
	LUA_TRY_INVOKE_R(0, &fairygui::GGroup::isExcludeInvisibles);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GGroup_moveChildren(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:moveChildren");
	LUA_TRY_INVOKE(2, &fairygui::GGroup::moveChildren);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GGroup_resizeChildren(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:resizeChildren");
	LUA_TRY_INVOKE(2, &fairygui::GGroup::resizeChildren);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GGroup_setAutoSizeDisabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:setAutoSizeDisabled");
	LUA_TRY_INVOKE(1, &fairygui::GGroup::setAutoSizeDisabled);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GGroup_setBoundsChangedFlag(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:setBoundsChangedFlag");
	LUA_TRY_INVOKE(1, static_cast<void(fairygui::GGroup::*)(bool)>(&fairygui::GGroup::setBoundsChangedFlag));
	LUA_TRY_INVOKE(0, [](fairygui::GGroup* obj){{return obj->setBoundsChangedFlag();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_fairygui_GGroup_setColumnGap(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:setColumnGap");
	LUA_TRY_INVOKE(1, &fairygui::GGroup::setColumnGap);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GGroup_setExcludeInvisibles(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:setExcludeInvisibles");
	LUA_TRY_INVOKE(1, &fairygui::GGroup::setExcludeInvisibles);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GGroup_setLayout(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:setLayout");
	LUA_TRY_INVOKE(1, &fairygui::GGroup::setLayout);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GGroup_setLineGap(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:setLineGap");
	LUA_TRY_INVOKE(1, &fairygui::GGroup::setLineGap);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GGroup_setMainGridIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:setMainGridIndex");
	LUA_TRY_INVOKE(1, &fairygui::GGroup::setMainGridIndex);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GGroup_setMainGridMinSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GGroup", "fgui.GGroup:setMainGridMinSize");
	LUA_TRY_INVOKE(1, &fairygui::GGroup::setMainGridMinSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GGroup_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GGroup", "fgui.GGroup:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GGroup::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGGroup(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GGroup, "GGroup", "fgui.GGroup",
		fairygui::GObject, "fgui.GObject",
		nullptr, nullptr);
	LUA_FIELD("_updating", lua_fairygui_GGroup__updating_getter, lua_fairygui_GGroup__updating_setter);
	LUA_METHOD("getColumnGap", lua_fairygui_GGroup_getColumnGap);
	LUA_METHOD("getLayout", lua_fairygui_GGroup_getLayout);
	LUA_METHOD("getLineGap", lua_fairygui_GGroup_getLineGap);
	LUA_METHOD("getMainGridIndex", lua_fairygui_GGroup_getMainGridIndex);
	LUA_METHOD("getMainGridMinSize", lua_fairygui_GGroup_getMainGridMinSize);
	LUA_METHOD("isAutoSizeDisabled", lua_fairygui_GGroup_isAutoSizeDisabled);
	LUA_METHOD("isExcludeInvisibles", lua_fairygui_GGroup_isExcludeInvisibles);
	LUA_METHOD("moveChildren", lua_fairygui_GGroup_moveChildren);
	LUA_METHOD("resizeChildren", lua_fairygui_GGroup_resizeChildren);
	LUA_METHOD("setAutoSizeDisabled", lua_fairygui_GGroup_setAutoSizeDisabled);
	LUA_METHOD("setBoundsChangedFlag", lua_fairygui_GGroup_setBoundsChangedFlag);
	LUA_METHOD("setColumnGap", lua_fairygui_GGroup_setColumnGap);
	LUA_METHOD("setExcludeInvisibles", lua_fairygui_GGroup_setExcludeInvisibles);
	LUA_METHOD("setLayout", lua_fairygui_GGroup_setLayout);
	LUA_METHOD("setLineGap", lua_fairygui_GGroup_setLineGap);
	LUA_METHOD("setMainGridIndex", lua_fairygui_GGroup_setMainGridIndex);
	LUA_METHOD("setMainGridMinSize", lua_fairygui_GGroup_setMainGridMinSize);
	LUA_METHOD("create", lua_fairygui_GGroup_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_ScrollPane_cancelDragging(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:cancelDragging");
	LUA_TRY_INVOKE(0, &fairygui::ScrollPane::cancelDragging);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getContentSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getContentSize");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getContentSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getDecelerationRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getDecelerationRate");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getDecelerationRate);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getFooter(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getFooter");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getFooter);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getHeader(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getHeader");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getHeader);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getHzScrollBar(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getHzScrollBar");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getHzScrollBar);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getOwner(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getOwner");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getOwner);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getPageController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getPageController");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getPageController);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getPageX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getPageX");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getPageX);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getPageY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getPageY");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getPageY);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getPercX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getPercX");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getPercX);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getPercY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getPercY");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getPercY);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getPosX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getPosX");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getPosX);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getPosY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getPosY");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getPosY);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getScrollStep(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getScrollStep");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getScrollStep);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getScrollingPosX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getScrollingPosX");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getScrollingPosX);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getScrollingPosY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getScrollingPosY");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getScrollingPosY);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getViewSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getViewSize");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getViewSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_getVtScrollBar(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getVtScrollBar");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getVtScrollBar);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_isBottomMost(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:isBottomMost");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::isBottomMost);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_isBouncebackEffect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:isBouncebackEffect");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::isBouncebackEffect);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_isChildInView(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:isChildInView");
	LUA_TRY_INVOKE_R(1, &fairygui::ScrollPane::isChildInView);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_ScrollPane_isInertiaDisabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:isInertiaDisabled");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::isInertiaDisabled);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_isMouseWheelEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:isMouseWheelEnabled");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::isMouseWheelEnabled);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_isPageMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:isPageMode");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::isPageMode);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_isRightMost(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:isRightMost");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::isRightMost);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_isSnapToItem(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:isSnapToItem");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::isSnapToItem);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_isTouchEffect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:isTouchEffect");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::isTouchEffect);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_ScrollPane_lockFooter(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:lockFooter");
	LUA_TRY_INVOKE(1, &fairygui::ScrollPane::lockFooter);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_ScrollPane_lockHeader(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:lockHeader");
	LUA_TRY_INVOKE(1, &fairygui::ScrollPane::lockHeader);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_ScrollPane_scrollBottom(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:scrollBottom");
	LUA_TRY_INVOKE(1, static_cast<void(fairygui::ScrollPane::*)(bool)>(&fairygui::ScrollPane::scrollBottom));
	LUA_TRY_INVOKE(0, [](fairygui::ScrollPane* obj){{return obj->scrollBottom();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_fairygui_ScrollPane_scrollDown(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:scrollDown");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::ScrollPane::*)(float, bool)>(&fairygui::ScrollPane::scrollDown));
	LUA_TRY_INVOKE(1, [](fairygui::ScrollPane* obj, float arg0){{return obj->scrollDown(std::move(arg0));}});
	LUA_TRY_INVOKE(0, [](fairygui::ScrollPane* obj){{return obj->scrollDown();}});
	LUA_INVOKE_FOOTER("0,1,2");
}
int lua_fairygui_ScrollPane_scrollLeft(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:scrollLeft");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::ScrollPane::*)(float, bool)>(&fairygui::ScrollPane::scrollLeft));
	LUA_TRY_INVOKE(1, [](fairygui::ScrollPane* obj, float arg0){{return obj->scrollLeft(std::move(arg0));}});
	LUA_TRY_INVOKE(0, [](fairygui::ScrollPane* obj){{return obj->scrollLeft();}});
	LUA_INVOKE_FOOTER("0,1,2");
}
int lua_fairygui_ScrollPane_scrollRight(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:scrollRight");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::ScrollPane::*)(float, bool)>(&fairygui::ScrollPane::scrollRight));
	LUA_TRY_INVOKE(1, [](fairygui::ScrollPane* obj, float arg0){{return obj->scrollRight(std::move(arg0));}});
	LUA_TRY_INVOKE(0, [](fairygui::ScrollPane* obj){{return obj->scrollRight();}});
	LUA_INVOKE_FOOTER("0,1,2");
}
int lua_fairygui_ScrollPane_scrollToView(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:scrollToView");
	LUA_TRY_INVOKE(3, static_cast<void(fairygui::ScrollPane::*)(const cocos2d::Rect&, bool, bool)>(&fairygui::ScrollPane::scrollToView));
	LUA_TRY_INVOKE(3, [](fairygui::ScrollPane* obj, fairygui::GObject* arg0,bool arg1,bool arg2){{return obj->scrollToView(std::move(arg0),std::move(arg1),std::move(arg2));}});
	LUA_TRY_INVOKE(2, [](fairygui::ScrollPane* obj, const cocos2d::Rect& arg0,bool arg1){{return obj->scrollToView(std::move(arg0),std::move(arg1));}});
	LUA_TRY_INVOKE(2, [](fairygui::ScrollPane* obj, fairygui::GObject* arg0,bool arg1){{return obj->scrollToView(std::move(arg0),std::move(arg1));}});
	LUA_TRY_INVOKE(1, [](fairygui::ScrollPane* obj, const cocos2d::Rect& arg0){{return obj->scrollToView(arg0);}});
	LUA_TRY_INVOKE(1, [](fairygui::ScrollPane* obj, fairygui::GObject* arg0){{return obj->scrollToView(arg0);}});
	LUA_INVOKE_FOOTER("1,2,3");
}
int lua_fairygui_ScrollPane_scrollTop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:scrollTop");
	LUA_TRY_INVOKE(1, static_cast<void(fairygui::ScrollPane::*)(bool)>(&fairygui::ScrollPane::scrollTop));
	LUA_TRY_INVOKE(0, [](fairygui::ScrollPane* obj){{return obj->scrollTop();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_fairygui_ScrollPane_scrollUp(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:scrollUp");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::ScrollPane::*)(float, bool)>(&fairygui::ScrollPane::scrollUp));
	LUA_TRY_INVOKE(1, [](fairygui::ScrollPane* obj, float arg0){{return obj->scrollUp(std::move(arg0));}});
	LUA_TRY_INVOKE(0, [](fairygui::ScrollPane* obj){{return obj->scrollUp();}});
	LUA_INVOKE_FOOTER("0,1,2");
}
int lua_fairygui_ScrollPane_setBouncebackEffect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setBouncebackEffect");
	LUA_TRY_INVOKE(1, &fairygui::ScrollPane::setBouncebackEffect);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_ScrollPane_setDecelerationRate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setDecelerationRate");
	LUA_TRY_INVOKE(1, &fairygui::ScrollPane::setDecelerationRate);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_ScrollPane_setInertiaDisabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setInertiaDisabled");
	LUA_TRY_INVOKE(1, &fairygui::ScrollPane::setInertiaDisabled);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_ScrollPane_setMouseWheelEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setMouseWheelEnabled");
	LUA_TRY_INVOKE(1, &fairygui::ScrollPane::setMouseWheelEnabled);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_ScrollPane_setPageController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setPageController");
	LUA_TRY_INVOKE(1, &fairygui::ScrollPane::setPageController);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_ScrollPane_setPageMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setPageMode");
	LUA_TRY_INVOKE(1, &fairygui::ScrollPane::setPageMode);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_ScrollPane_setPageX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setPageX");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::ScrollPane::*)(int, bool)>(&fairygui::ScrollPane::setPageX));
	LUA_TRY_INVOKE(1, [](fairygui::ScrollPane* obj, int arg0){{return obj->setPageX(std::move(arg0));}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_ScrollPane_setPageY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setPageY");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::ScrollPane::*)(int, bool)>(&fairygui::ScrollPane::setPageY));
	LUA_TRY_INVOKE(1, [](fairygui::ScrollPane* obj, int arg0){{return obj->setPageY(std::move(arg0));}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_ScrollPane_setPercX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setPercX");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::ScrollPane::*)(float, bool)>(&fairygui::ScrollPane::setPercX));
	LUA_TRY_INVOKE(1, [](fairygui::ScrollPane* obj, float arg0){{return obj->setPercX(std::move(arg0));}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_ScrollPane_setPercY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setPercY");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::ScrollPane::*)(float, bool)>(&fairygui::ScrollPane::setPercY));
	LUA_TRY_INVOKE(1, [](fairygui::ScrollPane* obj, float arg0){{return obj->setPercY(std::move(arg0));}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_ScrollPane_setPosX(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setPosX");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::ScrollPane::*)(float, bool)>(&fairygui::ScrollPane::setPosX));
	LUA_TRY_INVOKE(1, [](fairygui::ScrollPane* obj, float arg0){{return obj->setPosX(std::move(arg0));}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_ScrollPane_setPosY(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setPosY");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::ScrollPane::*)(float, bool)>(&fairygui::ScrollPane::setPosY));
	LUA_TRY_INVOKE(1, [](fairygui::ScrollPane* obj, float arg0){{return obj->setPosY(std::move(arg0));}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_ScrollPane_setScrollStep(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setScrollStep");
	LUA_TRY_INVOKE(1, &fairygui::ScrollPane::setScrollStep);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_ScrollPane_setSnapToItem(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setSnapToItem");
	LUA_TRY_INVOKE(1, &fairygui::ScrollPane::setSnapToItem);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_ScrollPane_setTouchEffect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setTouchEffect");
	LUA_TRY_INVOKE(1, &fairygui::ScrollPane::setTouchEffect);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_ScrollPane_setup(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:setup");
	LUA_TRY_INVOKE(1, &fairygui::ScrollPane::setup);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_ScrollPane_getDraggingPane(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.ScrollPane", "fgui.ScrollPane:getDraggingPane");
	LUA_TRY_INVOKE_R(0, &fairygui::ScrollPane::getDraggingPane);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiScrollPane(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::ScrollPane, "ScrollPane", "fgui.ScrollPane",
		cocos2d::Ref, "fgui.cocos2d.Ref",
		nullptr, nullptr);
	LUA_METHOD("cancelDragging", lua_fairygui_ScrollPane_cancelDragging);
	LUA_METHOD("getContentSize", lua_fairygui_ScrollPane_getContentSize);
	LUA_METHOD("getDecelerationRate", lua_fairygui_ScrollPane_getDecelerationRate);
	LUA_METHOD("getFooter", lua_fairygui_ScrollPane_getFooter);
	LUA_METHOD("getHeader", lua_fairygui_ScrollPane_getHeader);
	LUA_METHOD("getHzScrollBar", lua_fairygui_ScrollPane_getHzScrollBar);
	LUA_METHOD("getOwner", lua_fairygui_ScrollPane_getOwner);
	LUA_METHOD("getPageController", lua_fairygui_ScrollPane_getPageController);
	LUA_METHOD("getPageX", lua_fairygui_ScrollPane_getPageX);
	LUA_METHOD("getPageY", lua_fairygui_ScrollPane_getPageY);
	LUA_METHOD("getPercX", lua_fairygui_ScrollPane_getPercX);
	LUA_METHOD("getPercY", lua_fairygui_ScrollPane_getPercY);
	LUA_METHOD("getPosX", lua_fairygui_ScrollPane_getPosX);
	LUA_METHOD("getPosY", lua_fairygui_ScrollPane_getPosY);
	LUA_METHOD("getScrollStep", lua_fairygui_ScrollPane_getScrollStep);
	LUA_METHOD("getScrollingPosX", lua_fairygui_ScrollPane_getScrollingPosX);
	LUA_METHOD("getScrollingPosY", lua_fairygui_ScrollPane_getScrollingPosY);
	LUA_METHOD("getViewSize", lua_fairygui_ScrollPane_getViewSize);
	LUA_METHOD("getVtScrollBar", lua_fairygui_ScrollPane_getVtScrollBar);
	LUA_METHOD("isBottomMost", lua_fairygui_ScrollPane_isBottomMost);
	LUA_METHOD("isBouncebackEffect", lua_fairygui_ScrollPane_isBouncebackEffect);
	LUA_METHOD("isChildInView", lua_fairygui_ScrollPane_isChildInView);
	LUA_METHOD("isInertiaDisabled", lua_fairygui_ScrollPane_isInertiaDisabled);
	LUA_METHOD("isMouseWheelEnabled", lua_fairygui_ScrollPane_isMouseWheelEnabled);
	LUA_METHOD("isPageMode", lua_fairygui_ScrollPane_isPageMode);
	LUA_METHOD("isRightMost", lua_fairygui_ScrollPane_isRightMost);
	LUA_METHOD("isSnapToItem", lua_fairygui_ScrollPane_isSnapToItem);
	LUA_METHOD("isTouchEffect", lua_fairygui_ScrollPane_isTouchEffect);
	LUA_METHOD("lockFooter", lua_fairygui_ScrollPane_lockFooter);
	LUA_METHOD("lockHeader", lua_fairygui_ScrollPane_lockHeader);
	LUA_METHOD("scrollBottom", lua_fairygui_ScrollPane_scrollBottom);
	LUA_METHOD("scrollDown", lua_fairygui_ScrollPane_scrollDown);
	LUA_METHOD("scrollLeft", lua_fairygui_ScrollPane_scrollLeft);
	LUA_METHOD("scrollRight", lua_fairygui_ScrollPane_scrollRight);
	LUA_METHOD("scrollToView", lua_fairygui_ScrollPane_scrollToView);
	LUA_METHOD("scrollTop", lua_fairygui_ScrollPane_scrollTop);
	LUA_METHOD("scrollUp", lua_fairygui_ScrollPane_scrollUp);
	LUA_METHOD("setBouncebackEffect", lua_fairygui_ScrollPane_setBouncebackEffect);
	LUA_METHOD("setDecelerationRate", lua_fairygui_ScrollPane_setDecelerationRate);
	LUA_METHOD("setInertiaDisabled", lua_fairygui_ScrollPane_setInertiaDisabled);
	LUA_METHOD("setMouseWheelEnabled", lua_fairygui_ScrollPane_setMouseWheelEnabled);
	LUA_METHOD("setPageController", lua_fairygui_ScrollPane_setPageController);
	LUA_METHOD("setPageMode", lua_fairygui_ScrollPane_setPageMode);
	LUA_METHOD("setPageX", lua_fairygui_ScrollPane_setPageX);
	LUA_METHOD("setPageY", lua_fairygui_ScrollPane_setPageY);
	LUA_METHOD("setPercX", lua_fairygui_ScrollPane_setPercX);
	LUA_METHOD("setPercY", lua_fairygui_ScrollPane_setPercY);
	LUA_METHOD("setPosX", lua_fairygui_ScrollPane_setPosX);
	LUA_METHOD("setPosY", lua_fairygui_ScrollPane_setPosY);
	LUA_METHOD("setScrollStep", lua_fairygui_ScrollPane_setScrollStep);
	LUA_METHOD("setSnapToItem", lua_fairygui_ScrollPane_setSnapToItem);
	LUA_METHOD("setTouchEffect", lua_fairygui_ScrollPane_setTouchEffect);
	LUA_METHOD("setup", lua_fairygui_ScrollPane_setup);
	LUA_METHOD("getDraggingPane", lua_fairygui_ScrollPane_getDraggingPane);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_Transition_name_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.Transition.name/getter");
	auto cobj = LUA_TO_COBJ(fairygui::Transition*, 1);
	LUA_PUSH_NATIVE(cobj->name);
	return 1;
}
int lua_fairygui_Transition_name_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.Transition.name/setter");
	auto cobj = LUA_TO_COBJ(fairygui::Transition*, 1);
	LUA_NATIVE_SETTER(cobj->name, 2);
	return 0;
}
int lua_fairygui_Transition_changePlayTimes(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:changePlayTimes");
	LUA_TRY_INVOKE(1, &fairygui::Transition::changePlayTimes);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Transition_clearHooks(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:clearHooks");
	LUA_TRY_INVOKE(0, &fairygui::Transition::clearHooks);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Transition_getLabelTime(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:getLabelTime");
	LUA_TRY_INVOKE_R(1, &fairygui::Transition::getLabelTime);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Transition_getOwner(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:getOwner");
	LUA_TRY_INVOKE_R(0, &fairygui::Transition::getOwner);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Transition_getTimeScale(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:getTimeScale");
	LUA_TRY_INVOKE_R(0, &fairygui::Transition::getTimeScale);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Transition_isPlaying(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:isPlaying");
	LUA_TRY_INVOKE_R(0, &fairygui::Transition::isPlaying);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Transition_onOwnerAddedToStage(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:onOwnerAddedToStage");
	LUA_TRY_INVOKE(0, &fairygui::Transition::onOwnerAddedToStage);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Transition_onOwnerRemovedFromStage(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:onOwnerRemovedFromStage");
	LUA_TRY_INVOKE(0, &fairygui::Transition::onOwnerRemovedFromStage);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Transition_play(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:play");
	LUA_TRY_INVOKE(5, static_cast<void(fairygui::Transition::*)(int, float, float, float, fairygui::Transition::PlayCompleteCallback)>(&fairygui::Transition::play));
	LUA_TRY_INVOKE(4, [](fairygui::Transition* obj, int arg0,float arg1,float arg2,float arg3){{return obj->play(std::move(arg0),std::move(arg1),std::move(arg2),std::move(arg3));}});
	LUA_TRY_INVOKE(3, [](fairygui::Transition* obj, int arg0,float arg1,fairygui::Transition::PlayCompleteCallback arg2){{return obj->play(std::move(arg0),std::move(arg1),std::move(arg2));}});
	LUA_TRY_INVOKE(2, [](fairygui::Transition* obj, int arg0,float arg1){{return obj->play(std::move(arg0),std::move(arg1));}});
	LUA_TRY_INVOKE(1, [](fairygui::Transition* obj, fairygui::Transition::PlayCompleteCallback arg0){{return obj->play(std::move(arg0));}});
	LUA_TRY_INVOKE(0, [](fairygui::Transition* obj){{return obj->play();}});
	LUA_INVOKE_FOOTER("0,1,2,3,4,5");
}
int lua_fairygui_Transition_playReverse(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:playReverse");
	LUA_TRY_INVOKE(3, static_cast<void(fairygui::Transition::*)(int, float, fairygui::Transition::PlayCompleteCallback)>(&fairygui::Transition::playReverse));
	LUA_TRY_INVOKE(2, [](fairygui::Transition* obj, int arg0,float arg1){{return obj->playReverse(std::move(arg0),std::move(arg1));}});
	LUA_TRY_INVOKE(1, [](fairygui::Transition* obj, fairygui::Transition::PlayCompleteCallback arg0){{return obj->playReverse(std::move(arg0));}});
	LUA_TRY_INVOKE(0, [](fairygui::Transition* obj){{return obj->playReverse();}});
	LUA_INVOKE_FOOTER("0,1,2,3");
}
int lua_fairygui_Transition_setAutoPlay(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:setAutoPlay");
	LUA_TRY_INVOKE(3, &fairygui::Transition::setAutoPlay);
	LUA_INVOKE_FOOTER("3");
}
int lua_fairygui_Transition_setDuration(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:setDuration");
	LUA_TRY_INVOKE(2, &fairygui::Transition::setDuration);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_Transition_setHook(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:setHook");
	LUA_TRY_INVOKE(2, &fairygui::Transition::setHook);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_Transition_setPaused(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:setPaused");
	LUA_TRY_INVOKE(1, &fairygui::Transition::setPaused);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Transition_setTarget(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:setTarget");
	LUA_TRY_INVOKE(2, &fairygui::Transition::setTarget);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_Transition_setTimeScale(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:setTimeScale");
	LUA_TRY_INVOKE(1, &fairygui::Transition::setTimeScale);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Transition_setValue(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:setValue");
	LUA_TRY_INVOKE(2, &fairygui::Transition::setValue);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_Transition_setup(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:setup");
	LUA_TRY_INVOKE(1, &fairygui::Transition::setup);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Transition_stop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:stop");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::Transition::*)(bool, bool)>(&fairygui::Transition::stop));
	LUA_TRY_INVOKE(0, static_cast<void(fairygui::Transition::*)()>(&fairygui::Transition::stop));
	LUA_INVOKE_FOOTER("0,2");
}
int lua_fairygui_Transition_updateFromRelations(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Transition", "fgui.Transition:updateFromRelations");
	LUA_TRY_INVOKE(3, &fairygui::Transition::updateFromRelations);
	LUA_INVOKE_FOOTER("3");
}
int luaReg_fgui_fguiTransition(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::Transition, "Transition", "fgui.Transition",
		cocos2d::Ref, "fgui.cocos2d.Ref",
		nullptr, nullptr);
	LUA_FIELD("name", lua_fairygui_Transition_name_getter, lua_fairygui_Transition_name_setter);
	LUA_METHOD("changePlayTimes", lua_fairygui_Transition_changePlayTimes);
	LUA_METHOD("clearHooks", lua_fairygui_Transition_clearHooks);
	LUA_METHOD("getLabelTime", lua_fairygui_Transition_getLabelTime);
	LUA_METHOD("getOwner", lua_fairygui_Transition_getOwner);
	LUA_METHOD("getTimeScale", lua_fairygui_Transition_getTimeScale);
	LUA_METHOD("isPlaying", lua_fairygui_Transition_isPlaying);
	LUA_METHOD("onOwnerAddedToStage", lua_fairygui_Transition_onOwnerAddedToStage);
	LUA_METHOD("onOwnerRemovedFromStage", lua_fairygui_Transition_onOwnerRemovedFromStage);
	LUA_METHOD("play", lua_fairygui_Transition_play);
	LUA_METHOD("playReverse", lua_fairygui_Transition_playReverse);
	LUA_METHOD("setAutoPlay", lua_fairygui_Transition_setAutoPlay);
	LUA_METHOD("setDuration", lua_fairygui_Transition_setDuration);
	LUA_METHOD("setHook", lua_fairygui_Transition_setHook);
	LUA_METHOD("setPaused", lua_fairygui_Transition_setPaused);
	LUA_METHOD("setTarget", lua_fairygui_Transition_setTarget);
	LUA_METHOD("setTimeScale", lua_fairygui_Transition_setTimeScale);
	LUA_METHOD("setValue", lua_fairygui_Transition_setValue);
	LUA_METHOD("setup", lua_fairygui_Transition_setup);
	LUA_METHOD("stop", lua_fairygui_Transition_stop);
	LUA_METHOD("updateFromRelations", lua_fairygui_Transition_updateFromRelations);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_FUIContainer_gOwner_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.FUIContainer.gOwner/getter");
	auto cobj = LUA_TO_COBJ(fairygui::FUIContainer*, 1);
	LUA_PUSH_NATIVE(cobj->gOwner);
	return 1;
}
int lua_fairygui_FUIContainer_gOwner_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.FUIContainer.gOwner/setter");
	auto cobj = LUA_TO_COBJ(fairygui::FUIContainer*, 1);
	LUA_NATIVE_SETTER(cobj->gOwner, 2);
	return 0;
}
int lua_fairygui_FUIContainer_getAlphaThreshold(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIContainer", "fgui.FUIContainer:getAlphaThreshold");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIContainer::getAlphaThreshold);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIContainer_getClippingRegion(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIContainer", "fgui.FUIContainer:getClippingRegion");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIContainer::getClippingRegion);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIContainer_getStencil(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIContainer", "fgui.FUIContainer:getStencil");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIContainer::getStencil);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIContainer_isClippingEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIContainer", "fgui.FUIContainer:isClippingEnabled");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIContainer::isClippingEnabled);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIContainer_isInverted(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIContainer", "fgui.FUIContainer:isInverted");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIContainer::isInverted);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUIContainer_setAlphaThreshold(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIContainer", "fgui.FUIContainer:setAlphaThreshold");
	LUA_TRY_INVOKE(1, &fairygui::FUIContainer::setAlphaThreshold);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIContainer_setClippingEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIContainer", "fgui.FUIContainer:setClippingEnabled");
	LUA_TRY_INVOKE(1, &fairygui::FUIContainer::setClippingEnabled);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIContainer_setClippingRegion(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIContainer", "fgui.FUIContainer:setClippingRegion");
	LUA_TRY_INVOKE(1, &fairygui::FUIContainer::setClippingRegion);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIContainer_setInverted(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIContainer", "fgui.FUIContainer:setInverted");
	LUA_TRY_INVOKE(1, &fairygui::FUIContainer::setInverted);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIContainer_setStencil(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUIContainer", "fgui.FUIContainer:setStencil");
	LUA_TRY_INVOKE(1, &fairygui::FUIContainer::setStencil);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUIContainer_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.FUIContainer", "fgui.FUIContainer:create");
	LUA_TRY_INVOKE_R(0, &fairygui::FUIContainer::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiFUIContainer(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::FUIContainer, "FUIContainer", "fgui.FUIContainer",
		cocos2d::Node, "fgui.cocos2d.Node",
		nullptr, nullptr);
	LUA_FIELD("gOwner", lua_fairygui_FUIContainer_gOwner_getter, lua_fairygui_FUIContainer_gOwner_setter);
	LUA_METHOD("getAlphaThreshold", lua_fairygui_FUIContainer_getAlphaThreshold);
	LUA_METHOD("getClippingRegion", lua_fairygui_FUIContainer_getClippingRegion);
	LUA_METHOD("getStencil", lua_fairygui_FUIContainer_getStencil);
	LUA_METHOD("isClippingEnabled", lua_fairygui_FUIContainer_isClippingEnabled);
	LUA_METHOD("isInverted", lua_fairygui_FUIContainer_isInverted);
	LUA_METHOD("setAlphaThreshold", lua_fairygui_FUIContainer_setAlphaThreshold);
	LUA_METHOD("setClippingEnabled", lua_fairygui_FUIContainer_setClippingEnabled);
	LUA_METHOD("setClippingRegion", lua_fairygui_FUIContainer_setClippingRegion);
	LUA_METHOD("setInverted", lua_fairygui_FUIContainer_setInverted);
	LUA_METHOD("setStencil", lua_fairygui_FUIContainer_setStencil);
	LUA_METHOD("create", lua_fairygui_FUIContainer_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_IHitTest_hitTest(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.IHitTest", "fgui.IHitTest:hitTest");
	LUA_TRY_INVOKE_R(2, &fairygui::IHitTest::hitTest);
	LUA_INVOKE_FOOTER("2");
}
int luaReg_fgui_fguiIHitTest(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::IHitTest, "IHitTest", "fgui.IHitTest",
		nullptr, nullptr);
	LUA_METHOD("hitTest", lua_fairygui_IHitTest_hitTest);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_PixelHitTestData_pixelWidth_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTestData.pixelWidth/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTestData*, 1);
	LUA_PUSH_NATIVE(cobj->pixelWidth);
	return 1;
}
int lua_fairygui_PixelHitTestData_pixelWidth_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTestData.pixelWidth/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTestData*, 1);
	LUA_NATIVE_SETTER(cobj->pixelWidth, 2);
	return 0;
}
int lua_fairygui_PixelHitTestData_pixels_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTestData.pixels/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTestData*, 1);
	LUA_PUSH_NATIVE(cobj->pixels);
	return 1;
}
int lua_fairygui_PixelHitTestData_pixels_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTestData.pixels/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTestData*, 1);
	LUA_NATIVE_SETTER(cobj->pixels, 2);
	return 0;
}
int lua_fairygui_PixelHitTestData_pixelsLength_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTestData.pixelsLength/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTestData*, 1);
	LUA_PUSH_NATIVE(cobj->pixelsLength);
	return 1;
}
int lua_fairygui_PixelHitTestData_pixelsLength_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTestData.pixelsLength/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTestData*, 1);
	LUA_NATIVE_SETTER(cobj->pixelsLength, 2);
	return 0;
}
int lua_fairygui_PixelHitTestData_scale_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTestData.scale/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTestData*, 1);
	LUA_PUSH_NATIVE(cobj->scale);
	return 1;
}
int lua_fairygui_PixelHitTestData_scale_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTestData.scale/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTestData*, 1);
	LUA_NATIVE_SETTER(cobj->scale, 2);
	return 0;
}
int lua_fairygui_PixelHitTestData_load(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PixelHitTestData", "fgui.PixelHitTestData:load");
	LUA_TRY_INVOKE(1, &fairygui::PixelHitTestData::load);
	LUA_INVOKE_FOOTER("1");
}
int luaReg_fgui_fguiPixelHitTestData(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::PixelHitTestData, "PixelHitTestData", "fgui.PixelHitTestData",
		nullptr, nullptr);
	LUA_FIELD("pixelWidth", lua_fairygui_PixelHitTestData_pixelWidth_getter, lua_fairygui_PixelHitTestData_pixelWidth_setter);
	LUA_FIELD("pixels", lua_fairygui_PixelHitTestData_pixels_getter, lua_fairygui_PixelHitTestData_pixels_setter);
	LUA_FIELD("pixelsLength", lua_fairygui_PixelHitTestData_pixelsLength_getter, lua_fairygui_PixelHitTestData_pixelsLength_setter);
	LUA_FIELD("scale", lua_fairygui_PixelHitTestData_scale_getter, lua_fairygui_PixelHitTestData_scale_setter);
	LUA_METHOD("load", lua_fairygui_PixelHitTestData_load);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_PixelHitTest_offsetX_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTest.offsetX/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTest*, 1);
	LUA_PUSH_NATIVE(cobj->offsetX);
	return 1;
}
int lua_fairygui_PixelHitTest_offsetX_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTest.offsetX/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTest*, 1);
	LUA_NATIVE_SETTER(cobj->offsetX, 2);
	return 0;
}
int lua_fairygui_PixelHitTest_offsetY_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTest.offsetY/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTest*, 1);
	LUA_PUSH_NATIVE(cobj->offsetY);
	return 1;
}
int lua_fairygui_PixelHitTest_offsetY_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTest.offsetY/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTest*, 1);
	LUA_NATIVE_SETTER(cobj->offsetY, 2);
	return 0;
}
int lua_fairygui_PixelHitTest_scaleX_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTest.scaleX/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTest*, 1);
	LUA_PUSH_NATIVE(cobj->scaleX);
	return 1;
}
int lua_fairygui_PixelHitTest_scaleX_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTest.scaleX/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTest*, 1);
	LUA_NATIVE_SETTER(cobj->scaleX, 2);
	return 0;
}
int lua_fairygui_PixelHitTest_scaleY_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTest.scaleY/getter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTest*, 1);
	LUA_PUSH_NATIVE(cobj->scaleY);
	return 1;
}
int lua_fairygui_PixelHitTest_scaleY_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.PixelHitTest.scaleY/setter");
	auto cobj = LUA_TO_COBJ(fairygui::PixelHitTest*, 1);
	LUA_NATIVE_SETTER(cobj->scaleY, 2);
	return 0;
}
int luaReg_fgui_fguiPixelHitTest(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::PixelHitTest, "PixelHitTest", "fgui.PixelHitTest",
		fairygui::IHitTest, "fgui.IHitTest",
		nullptr, nullptr);
	LUA_FIELD("offsetX", lua_fairygui_PixelHitTest_offsetX_getter, lua_fairygui_PixelHitTest_offsetX_setter);
	LUA_FIELD("offsetY", lua_fairygui_PixelHitTest_offsetY_getter, lua_fairygui_PixelHitTest_offsetY_setter);
	LUA_FIELD("scaleX", lua_fairygui_PixelHitTest_scaleX_getter, lua_fairygui_PixelHitTest_scaleX_setter);
	LUA_FIELD("scaleY", lua_fairygui_PixelHitTest_scaleY_getter, lua_fairygui_PixelHitTest_scaleY_setter);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GComponent__buildingDisplayList_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GComponent._buildingDisplayList/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GComponent*, 1);
	LUA_PUSH_NATIVE(cobj->_buildingDisplayList);
	return 1;
}
int lua_fairygui_GComponent__buildingDisplayList_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GComponent._buildingDisplayList/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GComponent*, 1);
	LUA_NATIVE_SETTER(cobj->_buildingDisplayList, 2);
	return 0;
}
int lua_fairygui_GComponent_addChild(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:addChild");
	LUA_TRY_INVOKE_R(1, &fairygui::GComponent::addChild);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_addChildAt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:addChildAt");
	LUA_TRY_INVOKE_R(2, &fairygui::GComponent::addChildAt);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GComponent_addController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:addController");
	LUA_TRY_INVOKE(1, &fairygui::GComponent::addController);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_adjustRadioGroupDepth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:adjustRadioGroupDepth");
	LUA_TRY_INVOKE(2, &fairygui::GComponent::adjustRadioGroupDepth);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GComponent_applyAllControllers(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:applyAllControllers");
	LUA_TRY_INVOKE(0, &fairygui::GComponent::applyAllControllers);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_applyController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:applyController");
	LUA_TRY_INVOKE(1, &fairygui::GComponent::applyController);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_childSortingOrderChanged(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:childSortingOrderChanged");
	LUA_TRY_INVOKE(3, &fairygui::GComponent::childSortingOrderChanged);
	LUA_INVOKE_FOOTER("3");
}
int lua_fairygui_GComponent_childStateChanged(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:childStateChanged");
	LUA_TRY_INVOKE(1, &fairygui::GComponent::childStateChanged);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_constructFromResource(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:constructFromResource");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::GComponent::*)(std::vector<fairygui::GObject *>*, int)>(&fairygui::GComponent::constructFromResource));
	LUA_TRY_INVOKE(0, static_cast<void(fairygui::GComponent::*)()>(&fairygui::GComponent::constructFromResource));
	LUA_INVOKE_FOOTER("0,2");
}
int lua_fairygui_GComponent_ensureBoundsCorrect(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:ensureBoundsCorrect");
	LUA_TRY_INVOKE(0, &fairygui::GComponent::ensureBoundsCorrect);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_getApexIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getApexIndex");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::getApexIndex);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_getChild(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getChild");
	LUA_TRY_INVOKE_R(1, &fairygui::GComponent::getChild);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_getChildAt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getChildAt");
	LUA_TRY_INVOKE_R(1, &fairygui::GComponent::getChildAt);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_getChildById(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getChildById");
	LUA_TRY_INVOKE_R(1, &fairygui::GComponent::getChildById);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_getChildInGroup(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getChildInGroup");
	LUA_TRY_INVOKE_R(2, &fairygui::GComponent::getChildInGroup);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GComponent_getChildIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getChildIndex");
	LUA_TRY_INVOKE_R(1, &fairygui::GComponent::getChildIndex);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_getChildren(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getChildren");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::getChildren);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_getChildrenRenderOrder(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getChildrenRenderOrder");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::getChildrenRenderOrder);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_getController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getController");
	LUA_TRY_INVOKE_R(1, &fairygui::GComponent::getController);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_getControllerAt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getControllerAt");
	LUA_TRY_INVOKE_R(1, &fairygui::GComponent::getControllerAt);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_getControllers(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getControllers");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::getControllers);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_getFirstChildInView(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getFirstChildInView");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::getFirstChildInView);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_getHitArea(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getHitArea");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::getHitArea);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_getMargin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getMargin");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::getMargin);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_getMask(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getMask");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::getMask);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_getOpaque(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getOpaque");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::getOpaque);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_getScrollPane(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getScrollPane");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::getScrollPane);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_getSnappingPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getSnappingPosition");
	LUA_TRY_INVOKE_R(1, &fairygui::GComponent::getSnappingPosition);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_getTransition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getTransition");
	LUA_TRY_INVOKE_R(1, &fairygui::GComponent::getTransition);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_getTransitionAt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getTransitionAt");
	LUA_TRY_INVOKE_R(1, &fairygui::GComponent::getTransitionAt);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_getTransitions(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getTransitions");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::getTransitions);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_getViewHeight(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getViewHeight");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::getViewHeight);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_getViewWidth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:getViewWidth");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::getViewWidth);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_isAncestorOf(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:isAncestorOf");
	LUA_TRY_INVOKE_R(1, &fairygui::GComponent::isAncestorOf);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_isChildInView(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:isChildInView");
	LUA_TRY_INVOKE_R(1, &fairygui::GComponent::isChildInView);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_numChildren(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:numChildren");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::numChildren);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_removeChild(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:removeChild");
	LUA_TRY_INVOKE(1, &fairygui::GComponent::removeChild);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_removeChildAt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:removeChildAt");
	LUA_TRY_INVOKE(1, &fairygui::GComponent::removeChildAt);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_removeChildren(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:removeChildren");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::GComponent::*)(int, int)>(&fairygui::GComponent::removeChildren));
	LUA_TRY_INVOKE(0, static_cast<void(fairygui::GComponent::*)()>(&fairygui::GComponent::removeChildren));
	LUA_INVOKE_FOOTER("0,2");
}
int lua_fairygui_GComponent_removeController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:removeController");
	LUA_TRY_INVOKE(1, &fairygui::GComponent::removeController);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_setApexIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:setApexIndex");
	LUA_TRY_INVOKE(1, &fairygui::GComponent::setApexIndex);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_setBoundsChangedFlag(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:setBoundsChangedFlag");
	LUA_TRY_INVOKE(0, &fairygui::GComponent::setBoundsChangedFlag);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComponent_setChildIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:setChildIndex");
	LUA_TRY_INVOKE(2, &fairygui::GComponent::setChildIndex);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GComponent_setChildIndexBefore(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:setChildIndexBefore");
	LUA_TRY_INVOKE_R(2, &fairygui::GComponent::setChildIndexBefore);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GComponent_setChildrenRenderOrder(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:setChildrenRenderOrder");
	LUA_TRY_INVOKE(1, &fairygui::GComponent::setChildrenRenderOrder);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_setHitArea(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:setHitArea");
	LUA_TRY_INVOKE(1, &fairygui::GComponent::setHitArea);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_setMargin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:setMargin");
	LUA_TRY_INVOKE(1, &fairygui::GComponent::setMargin);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_setMask(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:setMask");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::GComponent::*)(cocos2d::Node*, bool)>(&fairygui::GComponent::setMask));
	LUA_TRY_INVOKE(1, [](fairygui::GComponent* obj, cocos2d::Node* arg0){{return obj->setMask(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_GComponent_setOpaque(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:setOpaque");
	LUA_TRY_INVOKE(1, &fairygui::GComponent::setOpaque);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_setViewHeight(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:setViewHeight");
	LUA_TRY_INVOKE(1, &fairygui::GComponent::setViewHeight);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_setViewWidth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:setViewWidth");
	LUA_TRY_INVOKE(1, &fairygui::GComponent::setViewWidth);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComponent_swapChildren(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:swapChildren");
	LUA_TRY_INVOKE(2, &fairygui::GComponent::swapChildren);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GComponent_swapChildrenAt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComponent", "fgui.GComponent:swapChildrenAt");
	LUA_TRY_INVOKE(2, &fairygui::GComponent::swapChildrenAt);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GComponent_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GComponent", "fgui.GComponent:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GComponent::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGComponent(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GComponent, "GComponent", "fgui.GComponent",
		fairygui::GObject, "fgui.GObject",
		nullptr, nullptr);
	LUA_FIELD("_buildingDisplayList", lua_fairygui_GComponent__buildingDisplayList_getter, lua_fairygui_GComponent__buildingDisplayList_setter);
	LUA_METHOD("addChild", lua_fairygui_GComponent_addChild);
	LUA_METHOD("addChildAt", lua_fairygui_GComponent_addChildAt);
	LUA_METHOD("addController", lua_fairygui_GComponent_addController);
	LUA_METHOD("adjustRadioGroupDepth", lua_fairygui_GComponent_adjustRadioGroupDepth);
	LUA_METHOD("applyAllControllers", lua_fairygui_GComponent_applyAllControllers);
	LUA_METHOD("applyController", lua_fairygui_GComponent_applyController);
	LUA_METHOD("childSortingOrderChanged", lua_fairygui_GComponent_childSortingOrderChanged);
	LUA_METHOD("childStateChanged", lua_fairygui_GComponent_childStateChanged);
	LUA_METHOD("constructFromResource", lua_fairygui_GComponent_constructFromResource);
	LUA_METHOD("ensureBoundsCorrect", lua_fairygui_GComponent_ensureBoundsCorrect);
	LUA_METHOD("getApexIndex", lua_fairygui_GComponent_getApexIndex);
	LUA_METHOD("getChild", lua_fairygui_GComponent_getChild);
	LUA_METHOD("getChildAt", lua_fairygui_GComponent_getChildAt);
	LUA_METHOD("getChildById", lua_fairygui_GComponent_getChildById);
	LUA_METHOD("getChildInGroup", lua_fairygui_GComponent_getChildInGroup);
	LUA_METHOD("getChildIndex", lua_fairygui_GComponent_getChildIndex);
	LUA_METHOD("getChildren", lua_fairygui_GComponent_getChildren);
	LUA_METHOD("getChildrenRenderOrder", lua_fairygui_GComponent_getChildrenRenderOrder);
	LUA_METHOD("getController", lua_fairygui_GComponent_getController);
	LUA_METHOD("getControllerAt", lua_fairygui_GComponent_getControllerAt);
	LUA_METHOD("getControllers", lua_fairygui_GComponent_getControllers);
	LUA_METHOD("getFirstChildInView", lua_fairygui_GComponent_getFirstChildInView);
	LUA_METHOD("getHitArea", lua_fairygui_GComponent_getHitArea);
	LUA_METHOD("getMargin", lua_fairygui_GComponent_getMargin);
	LUA_METHOD("getMask", lua_fairygui_GComponent_getMask);
	LUA_METHOD("getOpaque", lua_fairygui_GComponent_getOpaque);
	LUA_METHOD("getScrollPane", lua_fairygui_GComponent_getScrollPane);
	LUA_METHOD("getSnappingPosition", lua_fairygui_GComponent_getSnappingPosition);
	LUA_METHOD("getTransition", lua_fairygui_GComponent_getTransition);
	LUA_METHOD("getTransitionAt", lua_fairygui_GComponent_getTransitionAt);
	LUA_METHOD("getTransitions", lua_fairygui_GComponent_getTransitions);
	LUA_METHOD("getViewHeight", lua_fairygui_GComponent_getViewHeight);
	LUA_METHOD("getViewWidth", lua_fairygui_GComponent_getViewWidth);
	LUA_METHOD("isAncestorOf", lua_fairygui_GComponent_isAncestorOf);
	LUA_METHOD("isChildInView", lua_fairygui_GComponent_isChildInView);
	LUA_METHOD("numChildren", lua_fairygui_GComponent_numChildren);
	LUA_METHOD("removeChild", lua_fairygui_GComponent_removeChild);
	LUA_METHOD("removeChildAt", lua_fairygui_GComponent_removeChildAt);
	LUA_METHOD("removeChildren", lua_fairygui_GComponent_removeChildren);
	LUA_METHOD("removeController", lua_fairygui_GComponent_removeController);
	LUA_METHOD("setApexIndex", lua_fairygui_GComponent_setApexIndex);
	LUA_METHOD("setBoundsChangedFlag", lua_fairygui_GComponent_setBoundsChangedFlag);
	LUA_METHOD("setChildIndex", lua_fairygui_GComponent_setChildIndex);
	LUA_METHOD("setChildIndexBefore", lua_fairygui_GComponent_setChildIndexBefore);
	LUA_METHOD("setChildrenRenderOrder", lua_fairygui_GComponent_setChildrenRenderOrder);
	LUA_METHOD("setHitArea", lua_fairygui_GComponent_setHitArea);
	LUA_METHOD("setMargin", lua_fairygui_GComponent_setMargin);
	LUA_METHOD("setMask", lua_fairygui_GComponent_setMask);
	LUA_METHOD("setOpaque", lua_fairygui_GComponent_setOpaque);
	LUA_METHOD("setViewHeight", lua_fairygui_GComponent_setViewHeight);
	LUA_METHOD("setViewWidth", lua_fairygui_GComponent_setViewWidth);
	LUA_METHOD("swapChildren", lua_fairygui_GComponent_swapChildren);
	LUA_METHOD("swapChildrenAt", lua_fairygui_GComponent_swapChildrenAt);
	LUA_METHOD("create", lua_fairygui_GComponent_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GLabel_getTextField(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLabel", "fgui.GLabel:getTextField");
	LUA_TRY_INVOKE_R(0, &fairygui::GLabel::getTextField);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLabel_getTitle(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLabel", "fgui.GLabel:getTitle");
	LUA_TRY_INVOKE_R(0, &fairygui::GLabel::getTitle);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLabel_getTitleColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLabel", "fgui.GLabel:getTitleColor");
	LUA_TRY_INVOKE_R(0, &fairygui::GLabel::getTitleColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLabel_getTitleFontSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLabel", "fgui.GLabel:getTitleFontSize");
	LUA_TRY_INVOKE_R(0, &fairygui::GLabel::getTitleFontSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLabel_setTitle(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLabel", "fgui.GLabel:setTitle");
	LUA_TRY_INVOKE(1, &fairygui::GLabel::setTitle);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLabel_setTitleColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLabel", "fgui.GLabel:setTitleColor");
	LUA_TRY_INVOKE(1, &fairygui::GLabel::setTitleColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLabel_setTitleFontSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLabel", "fgui.GLabel:setTitleFontSize");
	LUA_TRY_INVOKE(1, &fairygui::GLabel::setTitleFontSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLabel_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GLabel", "fgui.GLabel:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GLabel::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGLabel(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GLabel, "GLabel", "fgui.GLabel",
		fairygui::GComponent, "fgui.GComponent",
		nullptr, nullptr);
	LUA_METHOD("getTextField", lua_fairygui_GLabel_getTextField);
	LUA_METHOD("getTitle", lua_fairygui_GLabel_getTitle);
	LUA_METHOD("getTitleColor", lua_fairygui_GLabel_getTitleColor);
	LUA_METHOD("getTitleFontSize", lua_fairygui_GLabel_getTitleFontSize);
	LUA_METHOD("setTitle", lua_fairygui_GLabel_setTitle);
	LUA_METHOD("setTitleColor", lua_fairygui_GLabel_setTitleColor);
	LUA_METHOD("setTitleFontSize", lua_fairygui_GLabel_setTitleFontSize);
	LUA_METHOD("create", lua_fairygui_GLabel_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GButton_DISABLED_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GButton.DISABLED/getter");
	LUA_PUSH_NATIVE(fairygui::GButton::DISABLED);
	return 1;
}
int lua_fairygui_GButton_DOWN_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GButton.DOWN/getter");
	LUA_PUSH_NATIVE(fairygui::GButton::DOWN);
	return 1;
}
int lua_fairygui_GButton_OVER_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GButton.OVER/getter");
	LUA_PUSH_NATIVE(fairygui::GButton::OVER);
	return 1;
}
int lua_fairygui_GButton_SELECTED_DISABLED_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GButton.SELECTED_DISABLED/getter");
	LUA_PUSH_NATIVE(fairygui::GButton::SELECTED_DISABLED);
	return 1;
}
int lua_fairygui_GButton_SELECTED_OVER_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GButton.SELECTED_OVER/getter");
	LUA_PUSH_NATIVE(fairygui::GButton::SELECTED_OVER);
	return 1;
}
int lua_fairygui_GButton_UP_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GButton.UP/getter");
	LUA_PUSH_NATIVE(fairygui::GButton::UP);
	return 1;
}
int lua_fairygui_GButton_getRelatedController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:getRelatedController");
	LUA_TRY_INVOKE_R(0, &fairygui::GButton::getRelatedController);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GButton_getSelectedIcon(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:getSelectedIcon");
	LUA_TRY_INVOKE_R(0, &fairygui::GButton::getSelectedIcon);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GButton_getSelectedTitle(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:getSelectedTitle");
	LUA_TRY_INVOKE_R(0, &fairygui::GButton::getSelectedTitle);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GButton_getTextField(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:getTextField");
	LUA_TRY_INVOKE_R(0, &fairygui::GButton::getTextField);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GButton_getTitle(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:getTitle");
	LUA_TRY_INVOKE_R(0, &fairygui::GButton::getTitle);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GButton_getTitleColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:getTitleColor");
	LUA_TRY_INVOKE_R(0, &fairygui::GButton::getTitleColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GButton_getTitleFontSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:getTitleFontSize");
	LUA_TRY_INVOKE_R(0, &fairygui::GButton::getTitleFontSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GButton_isChangeStateOnClick(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:isChangeStateOnClick");
	LUA_TRY_INVOKE_R(0, &fairygui::GButton::isChangeStateOnClick);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GButton_isSelected(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:isSelected");
	LUA_TRY_INVOKE_R(0, &fairygui::GButton::isSelected);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GButton_setChangeStateOnClick(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:setChangeStateOnClick");
	LUA_TRY_INVOKE(1, &fairygui::GButton::setChangeStateOnClick);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GButton_setRelatedController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:setRelatedController");
	LUA_TRY_INVOKE(1, &fairygui::GButton::setRelatedController);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GButton_setSelected(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:setSelected");
	LUA_TRY_INVOKE(1, &fairygui::GButton::setSelected);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GButton_setSelectedIcon(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:setSelectedIcon");
	LUA_TRY_INVOKE(1, &fairygui::GButton::setSelectedIcon);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GButton_setSelectedTitle(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:setSelectedTitle");
	LUA_TRY_INVOKE(1, &fairygui::GButton::setSelectedTitle);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GButton_setTitle(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:setTitle");
	LUA_TRY_INVOKE(1, &fairygui::GButton::setTitle);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GButton_setTitleColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:setTitleColor");
	LUA_TRY_INVOKE(1, &fairygui::GButton::setTitleColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GButton_setTitleFontSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GButton", "fgui.GButton:setTitleFontSize");
	LUA_TRY_INVOKE(1, &fairygui::GButton::setTitleFontSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GButton_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GButton", "fgui.GButton:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GButton::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGButton(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GButton, "GButton", "fgui.GButton",
		fairygui::GComponent, "fgui.GComponent",
		nullptr, nullptr);
	LUA_SFIELD("DISABLED", lua_fairygui_GButton_DISABLED_getter, nullptr);
	LUA_SFIELD("DOWN", lua_fairygui_GButton_DOWN_getter, nullptr);
	LUA_SFIELD("OVER", lua_fairygui_GButton_OVER_getter, nullptr);
	LUA_SFIELD("SELECTED_DISABLED", lua_fairygui_GButton_SELECTED_DISABLED_getter, nullptr);
	LUA_SFIELD("SELECTED_OVER", lua_fairygui_GButton_SELECTED_OVER_getter, nullptr);
	LUA_SFIELD("UP", lua_fairygui_GButton_UP_getter, nullptr);
	LUA_METHOD("getRelatedController", lua_fairygui_GButton_getRelatedController);
	LUA_METHOD("getSelectedIcon", lua_fairygui_GButton_getSelectedIcon);
	LUA_METHOD("getSelectedTitle", lua_fairygui_GButton_getSelectedTitle);
	LUA_METHOD("getTextField", lua_fairygui_GButton_getTextField);
	LUA_METHOD("getTitle", lua_fairygui_GButton_getTitle);
	LUA_METHOD("getTitleColor", lua_fairygui_GButton_getTitleColor);
	LUA_METHOD("getTitleFontSize", lua_fairygui_GButton_getTitleFontSize);
	LUA_METHOD("isChangeStateOnClick", lua_fairygui_GButton_isChangeStateOnClick);
	LUA_METHOD("isSelected", lua_fairygui_GButton_isSelected);
	LUA_METHOD("setChangeStateOnClick", lua_fairygui_GButton_setChangeStateOnClick);
	LUA_METHOD("setRelatedController", lua_fairygui_GButton_setRelatedController);
	LUA_METHOD("setSelected", lua_fairygui_GButton_setSelected);
	LUA_METHOD("setSelectedIcon", lua_fairygui_GButton_setSelectedIcon);
	LUA_METHOD("setSelectedTitle", lua_fairygui_GButton_setSelectedTitle);
	LUA_METHOD("setTitle", lua_fairygui_GButton_setTitle);
	LUA_METHOD("setTitleColor", lua_fairygui_GButton_setTitleColor);
	LUA_METHOD("setTitleFontSize", lua_fairygui_GButton_setTitleFontSize);
	LUA_METHOD("create", lua_fairygui_GButton_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GList_foldInvisibleItems_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GList.foldInvisibleItems/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GList*, 1);
	LUA_PUSH_NATIVE(cobj->foldInvisibleItems);
	return 1;
}
int lua_fairygui_GList_foldInvisibleItems_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GList.foldInvisibleItems/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GList*, 1);
	LUA_NATIVE_SETTER(cobj->foldInvisibleItems, 2);
	return 0;
}
int lua_fairygui_GList_itemProvider_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GList.itemProvider/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GList*, 1);
	LUA_PUSH_NATIVE(cobj->itemProvider);
	return 1;
}
int lua_fairygui_GList_itemProvider_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GList.itemProvider/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GList*, 1);
	LUA_NATIVE_SETTER(cobj->itemProvider, 2);
	return 0;
}
int lua_fairygui_GList_itemRenderer_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GList.itemRenderer/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GList*, 1);
	LUA_PUSH_NATIVE(cobj->itemRenderer);
	return 1;
}
int lua_fairygui_GList_itemRenderer_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GList.itemRenderer/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GList*, 1);
	LUA_NATIVE_SETTER(cobj->itemRenderer, 2);
	return 0;
}
int lua_fairygui_GList_scrollItemToViewOnClick_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GList.scrollItemToViewOnClick/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GList*, 1);
	LUA_PUSH_NATIVE(cobj->scrollItemToViewOnClick);
	return 1;
}
int lua_fairygui_GList_scrollItemToViewOnClick_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GList.scrollItemToViewOnClick/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GList*, 1);
	LUA_NATIVE_SETTER(cobj->scrollItemToViewOnClick, 2);
	return 0;
}
int lua_fairygui_GList_addItemFromPool(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:addItemFromPool");
	LUA_TRY_INVOKE_R(1, static_cast<fairygui::GObject*(fairygui::GList::*)(const std::string&)>(&fairygui::GList::addItemFromPool));
	LUA_TRY_INVOKE_R(0, static_cast<fairygui::GObject*(fairygui::GList::*)()>(&fairygui::GList::addItemFromPool));
	LUA_INVOKE_FOOTER("0,1");
}
int lua_fairygui_GList_addSelection(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:addSelection");
	LUA_TRY_INVOKE(2, &fairygui::GList::addSelection);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GList_childIndexToItemIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:childIndexToItemIndex");
	LUA_TRY_INVOKE_R(1, &fairygui::GList::childIndexToItemIndex);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_clearSelection(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:clearSelection");
	LUA_TRY_INVOKE(0, &fairygui::GList::clearSelection);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getAlign");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getAlign);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getAutoResizeItem(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getAutoResizeItem");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getAutoResizeItem);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getColumnCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getColumnCount");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getColumnCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getColumnGap(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getColumnGap");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getColumnGap);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getDefaultItem(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getDefaultItem");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getDefaultItem);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getFromPool(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getFromPool");
	LUA_TRY_INVOKE_R(1, static_cast<fairygui::GObject*(fairygui::GList::*)(const std::string&)>(&fairygui::GList::getFromPool));
	LUA_TRY_INVOKE_R(0, static_cast<fairygui::GObject*(fairygui::GList::*)()>(&fairygui::GList::getFromPool));
	LUA_INVOKE_FOOTER("0,1");
}
int lua_fairygui_GList_getItemPool(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getItemPool");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getItemPool);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getLayout(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getLayout");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getLayout);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getLineCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getLineCount");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getLineCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getLineGap(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getLineGap");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getLineGap);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getNumItems(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getNumItems");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getNumItems);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getSelectedIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getSelectedIndex");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getSelectedIndex);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getSelectionController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getSelectionController");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getSelectionController);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getSelectionMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getSelectionMode");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getSelectionMode);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_getVerticalAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:getVerticalAlign");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::getVerticalAlign);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_handleArrowKey(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:handleArrowKey");
	LUA_TRY_INVOKE(1, &fairygui::GList::handleArrowKey);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_isVirtual(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:isVirtual");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::isVirtual);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_itemIndexToChildIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:itemIndexToChildIndex");
	LUA_TRY_INVOKE_R(1, &fairygui::GList::itemIndexToChildIndex);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_refreshVirtualList(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:refreshVirtualList");
	LUA_TRY_INVOKE(0, &fairygui::GList::refreshVirtualList);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_removeChildToPool(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:removeChildToPool");
	LUA_TRY_INVOKE(1, &fairygui::GList::removeChildToPool);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_removeChildToPoolAt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:removeChildToPoolAt");
	LUA_TRY_INVOKE(1, &fairygui::GList::removeChildToPoolAt);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_removeChildrenToPool(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:removeChildrenToPool");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::GList::*)(int, int)>(&fairygui::GList::removeChildrenToPool));
	LUA_TRY_INVOKE(0, static_cast<void(fairygui::GList::*)()>(&fairygui::GList::removeChildrenToPool));
	LUA_INVOKE_FOOTER("0,2");
}
int lua_fairygui_GList_removeSelection(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:removeSelection");
	LUA_TRY_INVOKE(1, &fairygui::GList::removeSelection);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_resizeToFit(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:resizeToFit");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::GList::*)(int, int)>(&fairygui::GList::resizeToFit));
	LUA_TRY_INVOKE(1, static_cast<void(fairygui::GList::*)(int)>(&fairygui::GList::resizeToFit));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_GList_returnToPool(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:returnToPool");
	LUA_TRY_INVOKE(1, &fairygui::GList::returnToPool);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_scrollToView(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:scrollToView");
	LUA_TRY_INVOKE(3, static_cast<void(fairygui::GList::*)(int, bool, bool)>(&fairygui::GList::scrollToView));
	LUA_TRY_INVOKE(2, [](fairygui::GList* obj, int arg0,bool arg1){{return obj->scrollToView(std::move(arg0),std::move(arg1));}});
	LUA_TRY_INVOKE(1, [](fairygui::GList* obj, int arg0){{return obj->scrollToView(std::move(arg0));}});
	LUA_INVOKE_FOOTER("1,2,3");
}
int lua_fairygui_GList_selectAll(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:selectAll");
	LUA_TRY_INVOKE(0, &fairygui::GList::selectAll);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_selectReverse(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:selectReverse");
	LUA_TRY_INVOKE(0, &fairygui::GList::selectReverse);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_setAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setAlign");
	LUA_TRY_INVOKE(1, &fairygui::GList::setAlign);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_setAutoResizeItem(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setAutoResizeItem");
	LUA_TRY_INVOKE(1, &fairygui::GList::setAutoResizeItem);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_setColumnCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setColumnCount");
	LUA_TRY_INVOKE(1, &fairygui::GList::setColumnCount);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_setColumnGap(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setColumnGap");
	LUA_TRY_INVOKE(1, &fairygui::GList::setColumnGap);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_setDefaultItem(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setDefaultItem");
	LUA_TRY_INVOKE(1, &fairygui::GList::setDefaultItem);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_setLayout(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setLayout");
	LUA_TRY_INVOKE(1, &fairygui::GList::setLayout);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_setLineCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setLineCount");
	LUA_TRY_INVOKE(1, &fairygui::GList::setLineCount);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_setLineGap(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setLineGap");
	LUA_TRY_INVOKE(1, &fairygui::GList::setLineGap);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_setNumItems(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setNumItems");
	LUA_TRY_INVOKE(1, &fairygui::GList::setNumItems);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_setSelectedIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setSelectedIndex");
	LUA_TRY_INVOKE(1, &fairygui::GList::setSelectedIndex);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_setSelectionController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setSelectionController");
	LUA_TRY_INVOKE(1, &fairygui::GList::setSelectionController);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_setSelectionMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setSelectionMode");
	LUA_TRY_INVOKE(1, &fairygui::GList::setSelectionMode);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_setVerticalAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setVerticalAlign");
	LUA_TRY_INVOKE(1, &fairygui::GList::setVerticalAlign);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GList_setVirtual(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setVirtual");
	LUA_TRY_INVOKE(0, static_cast<void(fairygui::GList::*)()>(&fairygui::GList::setVirtual));
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_setVirtualAndLoop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GList", "fgui.GList:setVirtualAndLoop");
	LUA_TRY_INVOKE(0, &fairygui::GList::setVirtualAndLoop);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GList_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GList", "fgui.GList:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GList::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGList(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GList, "GList", "fgui.GList",
		fairygui::GComponent, "fgui.GComponent",
		nullptr, nullptr);
	LUA_FIELD("foldInvisibleItems", lua_fairygui_GList_foldInvisibleItems_getter, lua_fairygui_GList_foldInvisibleItems_setter);
	LUA_FIELD("itemProvider", lua_fairygui_GList_itemProvider_getter, lua_fairygui_GList_itemProvider_setter);
	LUA_FIELD("itemRenderer", lua_fairygui_GList_itemRenderer_getter, lua_fairygui_GList_itemRenderer_setter);
	LUA_FIELD("scrollItemToViewOnClick", lua_fairygui_GList_scrollItemToViewOnClick_getter, lua_fairygui_GList_scrollItemToViewOnClick_setter);
	LUA_METHOD("addItemFromPool", lua_fairygui_GList_addItemFromPool);
	LUA_METHOD("addSelection", lua_fairygui_GList_addSelection);
	LUA_METHOD("childIndexToItemIndex", lua_fairygui_GList_childIndexToItemIndex);
	LUA_METHOD("clearSelection", lua_fairygui_GList_clearSelection);
	LUA_METHOD("getAlign", lua_fairygui_GList_getAlign);
	LUA_METHOD("getAutoResizeItem", lua_fairygui_GList_getAutoResizeItem);
	LUA_METHOD("getColumnCount", lua_fairygui_GList_getColumnCount);
	LUA_METHOD("getColumnGap", lua_fairygui_GList_getColumnGap);
	LUA_METHOD("getDefaultItem", lua_fairygui_GList_getDefaultItem);
	LUA_METHOD("getFromPool", lua_fairygui_GList_getFromPool);
	LUA_METHOD("getItemPool", lua_fairygui_GList_getItemPool);
	LUA_METHOD("getLayout", lua_fairygui_GList_getLayout);
	LUA_METHOD("getLineCount", lua_fairygui_GList_getLineCount);
	LUA_METHOD("getLineGap", lua_fairygui_GList_getLineGap);
	LUA_METHOD("getNumItems", lua_fairygui_GList_getNumItems);
	LUA_METHOD("getSelectedIndex", lua_fairygui_GList_getSelectedIndex);
	LUA_METHOD("getSelectionController", lua_fairygui_GList_getSelectionController);
	LUA_METHOD("getSelectionMode", lua_fairygui_GList_getSelectionMode);
	LUA_METHOD("getVerticalAlign", lua_fairygui_GList_getVerticalAlign);
	LUA_METHOD("handleArrowKey", lua_fairygui_GList_handleArrowKey);
	LUA_METHOD("isVirtual", lua_fairygui_GList_isVirtual);
	LUA_METHOD("itemIndexToChildIndex", lua_fairygui_GList_itemIndexToChildIndex);
	LUA_METHOD("refreshVirtualList", lua_fairygui_GList_refreshVirtualList);
	LUA_METHOD("removeChildToPool", lua_fairygui_GList_removeChildToPool);
	LUA_METHOD("removeChildToPoolAt", lua_fairygui_GList_removeChildToPoolAt);
	LUA_METHOD("removeChildrenToPool", lua_fairygui_GList_removeChildrenToPool);
	LUA_METHOD("removeSelection", lua_fairygui_GList_removeSelection);
	LUA_METHOD("resizeToFit", lua_fairygui_GList_resizeToFit);
	LUA_METHOD("returnToPool", lua_fairygui_GList_returnToPool);
	LUA_METHOD("scrollToView", lua_fairygui_GList_scrollToView);
	LUA_METHOD("selectAll", lua_fairygui_GList_selectAll);
	LUA_METHOD("selectReverse", lua_fairygui_GList_selectReverse);
	LUA_METHOD("setAlign", lua_fairygui_GList_setAlign);
	LUA_METHOD("setAutoResizeItem", lua_fairygui_GList_setAutoResizeItem);
	LUA_METHOD("setColumnCount", lua_fairygui_GList_setColumnCount);
	LUA_METHOD("setColumnGap", lua_fairygui_GList_setColumnGap);
	LUA_METHOD("setDefaultItem", lua_fairygui_GList_setDefaultItem);
	LUA_METHOD("setLayout", lua_fairygui_GList_setLayout);
	LUA_METHOD("setLineCount", lua_fairygui_GList_setLineCount);
	LUA_METHOD("setLineGap", lua_fairygui_GList_setLineGap);
	LUA_METHOD("setNumItems", lua_fairygui_GList_setNumItems);
	LUA_METHOD("setSelectedIndex", lua_fairygui_GList_setSelectedIndex);
	LUA_METHOD("setSelectionController", lua_fairygui_GList_setSelectionController);
	LUA_METHOD("setSelectionMode", lua_fairygui_GList_setSelectionMode);
	LUA_METHOD("setVerticalAlign", lua_fairygui_GList_setVerticalAlign);
	LUA_METHOD("setVirtual", lua_fairygui_GList_setVirtual);
	LUA_METHOD("setVirtualAndLoop", lua_fairygui_GList_setVirtualAndLoop);
	LUA_METHOD("create", lua_fairygui_GList_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GComboBox_popupDirection_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GComboBox.popupDirection/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GComboBox*, 1);
	LUA_PUSH_NATIVE(cobj->popupDirection);
	return 1;
}
int lua_fairygui_GComboBox_popupDirection_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GComboBox.popupDirection/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GComboBox*, 1);
	LUA_NATIVE_SETTER(cobj->popupDirection, 2);
	return 0;
}
int lua_fairygui_GComboBox_visibleItemCount_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GComboBox.visibleItemCount/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GComboBox*, 1);
	LUA_PUSH_NATIVE(cobj->visibleItemCount);
	return 1;
}
int lua_fairygui_GComboBox_visibleItemCount_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GComboBox.visibleItemCount/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GComboBox*, 1);
	LUA_NATIVE_SETTER(cobj->visibleItemCount, 2);
	return 0;
}
int lua_fairygui_GComboBox_getDropdown(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:getDropdown");
	LUA_TRY_INVOKE_R(0, &fairygui::GComboBox::getDropdown);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComboBox_getIcons(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:getIcons");
	LUA_TRY_INVOKE_R(0, &fairygui::GComboBox::getIcons);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComboBox_getItems(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:getItems");
	LUA_TRY_INVOKE_R(0, &fairygui::GComboBox::getItems);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComboBox_getSelectedIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:getSelectedIndex");
	LUA_TRY_INVOKE_R(0, &fairygui::GComboBox::getSelectedIndex);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComboBox_getSelectionController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:getSelectionController");
	LUA_TRY_INVOKE_R(0, &fairygui::GComboBox::getSelectionController);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComboBox_getTextField(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:getTextField");
	LUA_TRY_INVOKE_R(0, &fairygui::GComboBox::getTextField);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComboBox_getTitle(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:getTitle");
	LUA_TRY_INVOKE_R(0, &fairygui::GComboBox::getTitle);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComboBox_getTitleColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:getTitleColor");
	LUA_TRY_INVOKE_R(0, &fairygui::GComboBox::getTitleColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComboBox_getTitleFontSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:getTitleFontSize");
	LUA_TRY_INVOKE_R(0, &fairygui::GComboBox::getTitleFontSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComboBox_getValue(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:getValue");
	LUA_TRY_INVOKE_R(0, &fairygui::GComboBox::getValue);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComboBox_getValues(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:getValues");
	LUA_TRY_INVOKE_R(0, &fairygui::GComboBox::getValues);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComboBox_refresh(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:refresh");
	LUA_TRY_INVOKE(0, &fairygui::GComboBox::refresh);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GComboBox_setSelectedIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:setSelectedIndex");
	LUA_TRY_INVOKE(1, &fairygui::GComboBox::setSelectedIndex);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComboBox_setSelectionController(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:setSelectionController");
	LUA_TRY_INVOKE(1, &fairygui::GComboBox::setSelectionController);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComboBox_setTitle(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:setTitle");
	LUA_TRY_INVOKE(1, &fairygui::GComboBox::setTitle);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComboBox_setTitleColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:setTitleColor");
	LUA_TRY_INVOKE(1, &fairygui::GComboBox::setTitleColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComboBox_setTitleFontSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:setTitleFontSize");
	LUA_TRY_INVOKE(1, &fairygui::GComboBox::setTitleFontSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComboBox_setValue(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:setValue");
	LUA_TRY_INVOKE(1, &fairygui::GComboBox::setValue);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GComboBox_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GComboBox", "fgui.GComboBox:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GComboBox::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGComboBox(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GComboBox, "GComboBox", "fgui.GComboBox",
		fairygui::GComponent, "fgui.GComponent",
		nullptr, nullptr);
	LUA_FIELD("popupDirection", lua_fairygui_GComboBox_popupDirection_getter, lua_fairygui_GComboBox_popupDirection_setter);
	LUA_FIELD("visibleItemCount", lua_fairygui_GComboBox_visibleItemCount_getter, lua_fairygui_GComboBox_visibleItemCount_setter);
	LUA_METHOD("getDropdown", lua_fairygui_GComboBox_getDropdown);
	LUA_METHOD("getIcons", lua_fairygui_GComboBox_getIcons);
	LUA_METHOD("getItems", lua_fairygui_GComboBox_getItems);
	LUA_METHOD("getSelectedIndex", lua_fairygui_GComboBox_getSelectedIndex);
	LUA_METHOD("getSelectionController", lua_fairygui_GComboBox_getSelectionController);
	LUA_METHOD("getTextField", lua_fairygui_GComboBox_getTextField);
	LUA_METHOD("getTitle", lua_fairygui_GComboBox_getTitle);
	LUA_METHOD("getTitleColor", lua_fairygui_GComboBox_getTitleColor);
	LUA_METHOD("getTitleFontSize", lua_fairygui_GComboBox_getTitleFontSize);
	LUA_METHOD("getValue", lua_fairygui_GComboBox_getValue);
	LUA_METHOD("getValues", lua_fairygui_GComboBox_getValues);
	LUA_METHOD("refresh", lua_fairygui_GComboBox_refresh);
	LUA_METHOD("setSelectedIndex", lua_fairygui_GComboBox_setSelectedIndex);
	LUA_METHOD("setSelectionController", lua_fairygui_GComboBox_setSelectionController);
	LUA_METHOD("setTitle", lua_fairygui_GComboBox_setTitle);
	LUA_METHOD("setTitleColor", lua_fairygui_GComboBox_setTitleColor);
	LUA_METHOD("setTitleFontSize", lua_fairygui_GComboBox_setTitleFontSize);
	LUA_METHOD("setValue", lua_fairygui_GComboBox_setValue);
	LUA_METHOD("create", lua_fairygui_GComboBox_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GProgressBar_getMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GProgressBar", "fgui.GProgressBar:getMax");
	LUA_TRY_INVOKE_R(0, &fairygui::GProgressBar::getMax);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GProgressBar_getMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GProgressBar", "fgui.GProgressBar:getMin");
	LUA_TRY_INVOKE_R(0, &fairygui::GProgressBar::getMin);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GProgressBar_getTitleType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GProgressBar", "fgui.GProgressBar:getTitleType");
	LUA_TRY_INVOKE_R(0, &fairygui::GProgressBar::getTitleType);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GProgressBar_getValue(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GProgressBar", "fgui.GProgressBar:getValue");
	LUA_TRY_INVOKE_R(0, &fairygui::GProgressBar::getValue);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GProgressBar_setMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GProgressBar", "fgui.GProgressBar:setMax");
	LUA_TRY_INVOKE(1, &fairygui::GProgressBar::setMax);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GProgressBar_setMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GProgressBar", "fgui.GProgressBar:setMin");
	LUA_TRY_INVOKE(1, &fairygui::GProgressBar::setMin);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GProgressBar_setTitleType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GProgressBar", "fgui.GProgressBar:setTitleType");
	LUA_TRY_INVOKE(1, &fairygui::GProgressBar::setTitleType);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GProgressBar_setValue(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GProgressBar", "fgui.GProgressBar:setValue");
	LUA_TRY_INVOKE(1, &fairygui::GProgressBar::setValue);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GProgressBar_tweenValue(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GProgressBar", "fgui.GProgressBar:tweenValue");
	LUA_TRY_INVOKE(2, &fairygui::GProgressBar::tweenValue);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GProgressBar_update(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GProgressBar", "fgui.GProgressBar:update");
	LUA_TRY_INVOKE(1, &fairygui::GProgressBar::update);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GProgressBar_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GProgressBar", "fgui.GProgressBar:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GProgressBar::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGProgressBar(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GProgressBar, "GProgressBar", "fgui.GProgressBar",
		fairygui::GComponent, "fgui.GComponent",
		nullptr, nullptr);
	LUA_METHOD("getMax", lua_fairygui_GProgressBar_getMax);
	LUA_METHOD("getMin", lua_fairygui_GProgressBar_getMin);
	LUA_METHOD("getTitleType", lua_fairygui_GProgressBar_getTitleType);
	LUA_METHOD("getValue", lua_fairygui_GProgressBar_getValue);
	LUA_METHOD("setMax", lua_fairygui_GProgressBar_setMax);
	LUA_METHOD("setMin", lua_fairygui_GProgressBar_setMin);
	LUA_METHOD("setTitleType", lua_fairygui_GProgressBar_setTitleType);
	LUA_METHOD("setValue", lua_fairygui_GProgressBar_setValue);
	LUA_METHOD("tweenValue", lua_fairygui_GProgressBar_tweenValue);
	LUA_METHOD("update", lua_fairygui_GProgressBar_update);
	LUA_METHOD("create", lua_fairygui_GProgressBar_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GSlider_canDrag_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GSlider.canDrag/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GSlider*, 1);
	LUA_PUSH_NATIVE(cobj->canDrag);
	return 1;
}
int lua_fairygui_GSlider_canDrag_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GSlider.canDrag/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GSlider*, 1);
	LUA_NATIVE_SETTER(cobj->canDrag, 2);
	return 0;
}
int lua_fairygui_GSlider_changeOnClick_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GSlider.changeOnClick/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GSlider*, 1);
	LUA_PUSH_NATIVE(cobj->changeOnClick);
	return 1;
}
int lua_fairygui_GSlider_changeOnClick_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GSlider.changeOnClick/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GSlider*, 1);
	LUA_NATIVE_SETTER(cobj->changeOnClick, 2);
	return 0;
}
int lua_fairygui_GSlider_getMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GSlider", "fgui.GSlider:getMax");
	LUA_TRY_INVOKE_R(0, &fairygui::GSlider::getMax);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GSlider_getMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GSlider", "fgui.GSlider:getMin");
	LUA_TRY_INVOKE_R(0, &fairygui::GSlider::getMin);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GSlider_getTitleType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GSlider", "fgui.GSlider:getTitleType");
	LUA_TRY_INVOKE_R(0, &fairygui::GSlider::getTitleType);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GSlider_getValue(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GSlider", "fgui.GSlider:getValue");
	LUA_TRY_INVOKE_R(0, &fairygui::GSlider::getValue);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GSlider_getWholeNumbers(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GSlider", "fgui.GSlider:getWholeNumbers");
	LUA_TRY_INVOKE_R(0, &fairygui::GSlider::getWholeNumbers);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GSlider_setMax(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GSlider", "fgui.GSlider:setMax");
	LUA_TRY_INVOKE(1, &fairygui::GSlider::setMax);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GSlider_setMin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GSlider", "fgui.GSlider:setMin");
	LUA_TRY_INVOKE(1, &fairygui::GSlider::setMin);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GSlider_setTitleType(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GSlider", "fgui.GSlider:setTitleType");
	LUA_TRY_INVOKE(1, &fairygui::GSlider::setTitleType);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GSlider_setValue(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GSlider", "fgui.GSlider:setValue");
	LUA_TRY_INVOKE(1, &fairygui::GSlider::setValue);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GSlider_setWholeNumbers(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GSlider", "fgui.GSlider:setWholeNumbers");
	LUA_TRY_INVOKE(1, &fairygui::GSlider::setWholeNumbers);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GSlider_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GSlider", "fgui.GSlider:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GSlider::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGSlider(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GSlider, "GSlider", "fgui.GSlider",
		fairygui::GComponent, "fgui.GComponent",
		nullptr, nullptr);
	LUA_FIELD("canDrag", lua_fairygui_GSlider_canDrag_getter, lua_fairygui_GSlider_canDrag_setter);
	LUA_FIELD("changeOnClick", lua_fairygui_GSlider_changeOnClick_getter, lua_fairygui_GSlider_changeOnClick_setter);
	LUA_METHOD("getMax", lua_fairygui_GSlider_getMax);
	LUA_METHOD("getMin", lua_fairygui_GSlider_getMin);
	LUA_METHOD("getTitleType", lua_fairygui_GSlider_getTitleType);
	LUA_METHOD("getValue", lua_fairygui_GSlider_getValue);
	LUA_METHOD("getWholeNumbers", lua_fairygui_GSlider_getWholeNumbers);
	LUA_METHOD("setMax", lua_fairygui_GSlider_setMax);
	LUA_METHOD("setMin", lua_fairygui_GSlider_setMin);
	LUA_METHOD("setTitleType", lua_fairygui_GSlider_setTitleType);
	LUA_METHOD("setValue", lua_fairygui_GSlider_setValue);
	LUA_METHOD("setWholeNumbers", lua_fairygui_GSlider_setWholeNumbers);
	LUA_METHOD("create", lua_fairygui_GSlider_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GScrollBar__gripDragging_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GScrollBar._gripDragging/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GScrollBar*, 1);
	LUA_PUSH_NATIVE(cobj->_gripDragging);
	return 1;
}
int lua_fairygui_GScrollBar__gripDragging_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GScrollBar._gripDragging/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GScrollBar*, 1);
	LUA_NATIVE_SETTER(cobj->_gripDragging, 2);
	return 0;
}
int lua_fairygui_GScrollBar_getMinSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GScrollBar", "fgui.GScrollBar:getMinSize");
	LUA_TRY_INVOKE_R(0, &fairygui::GScrollBar::getMinSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GScrollBar_setDisplayPerc(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GScrollBar", "fgui.GScrollBar:setDisplayPerc");
	LUA_TRY_INVOKE(1, &fairygui::GScrollBar::setDisplayPerc);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GScrollBar_setScrollPane(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GScrollBar", "fgui.GScrollBar:setScrollPane");
	LUA_TRY_INVOKE(2, &fairygui::GScrollBar::setScrollPane);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GScrollBar_setScrollPerc(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GScrollBar", "fgui.GScrollBar:setScrollPerc");
	LUA_TRY_INVOKE(1, &fairygui::GScrollBar::setScrollPerc);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GScrollBar_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GScrollBar", "fgui.GScrollBar:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GScrollBar::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGScrollBar(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GScrollBar, "GScrollBar", "fgui.GScrollBar",
		fairygui::GComponent, "fgui.GComponent",
		nullptr, nullptr);
	LUA_FIELD("_gripDragging", lua_fairygui_GScrollBar__gripDragging_getter, lua_fairygui_GScrollBar__gripDragging_setter);
	LUA_METHOD("getMinSize", lua_fairygui_GScrollBar_getMinSize);
	LUA_METHOD("setDisplayPerc", lua_fairygui_GScrollBar_setDisplayPerc);
	LUA_METHOD("setScrollPane", lua_fairygui_GScrollBar_setScrollPane);
	LUA_METHOD("setScrollPerc", lua_fairygui_GScrollBar_setScrollPerc);
	LUA_METHOD("create", lua_fairygui_GScrollBar_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GTreeNode_addChild(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:addChild");
	LUA_TRY_INVOKE_R(1, &fairygui::GTreeNode::addChild);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTreeNode_addChildAt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:addChildAt");
	LUA_TRY_INVOKE_R(2, &fairygui::GTreeNode::addChildAt);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GTreeNode_getCell(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:getCell");
	LUA_TRY_INVOKE_R(0, &fairygui::GTreeNode::getCell);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTreeNode_getChildAt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:getChildAt");
	LUA_TRY_INVOKE_R(1, &fairygui::GTreeNode::getChildAt);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTreeNode_getChildIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:getChildIndex");
	LUA_TRY_INVOKE_R(1, &fairygui::GTreeNode::getChildIndex);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTreeNode_getData(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:getData");
	LUA_TRY_INVOKE_R(0, &fairygui::GTreeNode::getData);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTreeNode_getIcon(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:getIcon");
	LUA_TRY_INVOKE_R(0, &fairygui::GTreeNode::getIcon);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTreeNode_getNextSibling(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:getNextSibling");
	LUA_TRY_INVOKE_R(0, &fairygui::GTreeNode::getNextSibling);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTreeNode_getParent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:getParent");
	LUA_TRY_INVOKE_R(0, &fairygui::GTreeNode::getParent);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTreeNode_getPrevSibling(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:getPrevSibling");
	LUA_TRY_INVOKE_R(0, &fairygui::GTreeNode::getPrevSibling);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTreeNode_getText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:getText");
	LUA_TRY_INVOKE_R(0, &fairygui::GTreeNode::getText);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTreeNode_getTree(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:getTree");
	LUA_TRY_INVOKE_R(0, &fairygui::GTreeNode::getTree);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTreeNode_isExpanded(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:isExpanded");
	LUA_TRY_INVOKE_R(0, &fairygui::GTreeNode::isExpanded);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTreeNode_isFolder(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:isFolder");
	LUA_TRY_INVOKE_R(0, &fairygui::GTreeNode::isFolder);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTreeNode_numChildren(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:numChildren");
	LUA_TRY_INVOKE_R(0, &fairygui::GTreeNode::numChildren);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTreeNode_removeChild(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:removeChild");
	LUA_TRY_INVOKE(1, &fairygui::GTreeNode::removeChild);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTreeNode_removeChildAt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:removeChildAt");
	LUA_TRY_INVOKE(1, &fairygui::GTreeNode::removeChildAt);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTreeNode_removeChildren(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:removeChildren");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::GTreeNode::*)(int, int)>(&fairygui::GTreeNode::removeChildren));
	LUA_TRY_INVOKE(0, static_cast<void(fairygui::GTreeNode::*)()>(&fairygui::GTreeNode::removeChildren));
	LUA_INVOKE_FOOTER("0,2");
}
int lua_fairygui_GTreeNode_setChildIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:setChildIndex");
	LUA_TRY_INVOKE(2, &fairygui::GTreeNode::setChildIndex);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GTreeNode_setChildIndexBefore(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:setChildIndexBefore");
	LUA_TRY_INVOKE_R(2, &fairygui::GTreeNode::setChildIndexBefore);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GTreeNode_setData(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:setData");
	LUA_TRY_INVOKE(1, &fairygui::GTreeNode::setData);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTreeNode_setExpaned(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:setExpaned");
	LUA_TRY_INVOKE(1, &fairygui::GTreeNode::setExpaned);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTreeNode_setIcon(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:setIcon");
	LUA_TRY_INVOKE(1, &fairygui::GTreeNode::setIcon);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTreeNode_setText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:setText");
	LUA_TRY_INVOKE(1, &fairygui::GTreeNode::setText);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTreeNode_swapChildren(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:swapChildren");
	LUA_TRY_INVOKE(2, &fairygui::GTreeNode::swapChildren);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GTreeNode_swapChildrenAt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:swapChildrenAt");
	LUA_TRY_INVOKE(2, &fairygui::GTreeNode::swapChildrenAt);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GTreeNode_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GTreeNode", "fgui.GTreeNode:create");
	LUA_TRY_INVOKE_R(2, static_cast<fairygui::GTreeNode*(*)(bool, const std::string&)>(&fairygui::GTreeNode::create));
	LUA_TRY_INVOKE_R(1, [](bool arg0){{return fairygui::GTreeNode::create(std::move(arg0));}});
	LUA_TRY_INVOKE_R(0, [](){{return fairygui::GTreeNode::create();}});
	LUA_SINVOKE_FOOTER("0,1,2");
}
int luaReg_fgui_fguiGTreeNode(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GTreeNode, "GTreeNode", "fgui.GTreeNode",
		cocos2d::Ref, "fgui.cocos2d.Ref",
		nullptr, nullptr);
	LUA_METHOD("addChild", lua_fairygui_GTreeNode_addChild);
	LUA_METHOD("addChildAt", lua_fairygui_GTreeNode_addChildAt);
	LUA_METHOD("getCell", lua_fairygui_GTreeNode_getCell);
	LUA_METHOD("getChildAt", lua_fairygui_GTreeNode_getChildAt);
	LUA_METHOD("getChildIndex", lua_fairygui_GTreeNode_getChildIndex);
	LUA_METHOD("getData", lua_fairygui_GTreeNode_getData);
	LUA_METHOD("getIcon", lua_fairygui_GTreeNode_getIcon);
	LUA_METHOD("getNextSibling", lua_fairygui_GTreeNode_getNextSibling);
	LUA_METHOD("getParent", lua_fairygui_GTreeNode_getParent);
	LUA_METHOD("getPrevSibling", lua_fairygui_GTreeNode_getPrevSibling);
	LUA_METHOD("getText", lua_fairygui_GTreeNode_getText);
	LUA_METHOD("getTree", lua_fairygui_GTreeNode_getTree);
	LUA_METHOD("isExpanded", lua_fairygui_GTreeNode_isExpanded);
	LUA_METHOD("isFolder", lua_fairygui_GTreeNode_isFolder);
	LUA_METHOD("numChildren", lua_fairygui_GTreeNode_numChildren);
	LUA_METHOD("removeChild", lua_fairygui_GTreeNode_removeChild);
	LUA_METHOD("removeChildAt", lua_fairygui_GTreeNode_removeChildAt);
	LUA_METHOD("removeChildren", lua_fairygui_GTreeNode_removeChildren);
	LUA_METHOD("setChildIndex", lua_fairygui_GTreeNode_setChildIndex);
	LUA_METHOD("setChildIndexBefore", lua_fairygui_GTreeNode_setChildIndexBefore);
	LUA_METHOD("setData", lua_fairygui_GTreeNode_setData);
	LUA_METHOD("setExpaned", lua_fairygui_GTreeNode_setExpaned);
	LUA_METHOD("setIcon", lua_fairygui_GTreeNode_setIcon);
	LUA_METHOD("setText", lua_fairygui_GTreeNode_setText);
	LUA_METHOD("swapChildren", lua_fairygui_GTreeNode_swapChildren);
	LUA_METHOD("swapChildrenAt", lua_fairygui_GTreeNode_swapChildrenAt);
	LUA_METHOD("create", lua_fairygui_GTreeNode_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GTree_treeNodeRender_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GTree.treeNodeRender/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GTree*, 1);
	LUA_PUSH_NATIVE(cobj->treeNodeRender);
	return 1;
}
int lua_fairygui_GTree_treeNodeRender_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GTree.treeNodeRender/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GTree*, 1);
	LUA_NATIVE_SETTER(cobj->treeNodeRender, 2);
	return 0;
}
int lua_fairygui_GTree_treeNodeWillExpand_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GTree.treeNodeWillExpand/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GTree*, 1);
	LUA_PUSH_NATIVE(cobj->treeNodeWillExpand);
	return 1;
}
int lua_fairygui_GTree_treeNodeWillExpand_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GTree.treeNodeWillExpand/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GTree*, 1);
	LUA_NATIVE_SETTER(cobj->treeNodeWillExpand, 2);
	return 0;
}
int lua_fairygui_GTree_collapseAll(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTree", "fgui.GTree:collapseAll");
	LUA_TRY_INVOKE(1, &fairygui::GTree::collapseAll);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTree_expandAll(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTree", "fgui.GTree:expandAll");
	LUA_TRY_INVOKE(1, &fairygui::GTree::expandAll);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTree_getClickToExpand(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTree", "fgui.GTree:getClickToExpand");
	LUA_TRY_INVOKE_R(0, &fairygui::GTree::getClickToExpand);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTree_getIndent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTree", "fgui.GTree:getIndent");
	LUA_TRY_INVOKE_R(0, &fairygui::GTree::getIndent);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTree_getRootNode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTree", "fgui.GTree:getRootNode");
	LUA_TRY_INVOKE_R(0, &fairygui::GTree::getRootNode);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTree_getSelectedNode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTree", "fgui.GTree:getSelectedNode");
	LUA_TRY_INVOKE_R(0, &fairygui::GTree::getSelectedNode);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTree_selectNode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTree", "fgui.GTree:selectNode");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::GTree::*)(fairygui::GTreeNode*, bool)>(&fairygui::GTree::selectNode));
	LUA_TRY_INVOKE(1, [](fairygui::GTree* obj, fairygui::GTreeNode* arg0){{return obj->selectNode(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_GTree_setClickToExpand(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTree", "fgui.GTree:setClickToExpand");
	LUA_TRY_INVOKE(1, &fairygui::GTree::setClickToExpand);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTree_setIndent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTree", "fgui.GTree:setIndent");
	LUA_TRY_INVOKE(1, &fairygui::GTree::setIndent);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTree_unselectNode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTree", "fgui.GTree:unselectNode");
	LUA_TRY_INVOKE(1, &fairygui::GTree::unselectNode);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTree_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GTree", "fgui.GTree:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GTree::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGTree(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GTree, "GTree", "fgui.GTree",
		fairygui::GList, "fgui.GList",
		nullptr, nullptr);
	LUA_FIELD("treeNodeRender", lua_fairygui_GTree_treeNodeRender_getter, lua_fairygui_GTree_treeNodeRender_setter);
	LUA_FIELD("treeNodeWillExpand", lua_fairygui_GTree_treeNodeWillExpand_getter, lua_fairygui_GTree_treeNodeWillExpand_setter);
	LUA_METHOD("collapseAll", lua_fairygui_GTree_collapseAll);
	LUA_METHOD("expandAll", lua_fairygui_GTree_expandAll);
	LUA_METHOD("getClickToExpand", lua_fairygui_GTree_getClickToExpand);
	LUA_METHOD("getIndent", lua_fairygui_GTree_getIndent);
	LUA_METHOD("getRootNode", lua_fairygui_GTree_getRootNode);
	LUA_METHOD("getSelectedNode", lua_fairygui_GTree_getSelectedNode);
	LUA_METHOD("selectNode", lua_fairygui_GTree_selectNode);
	LUA_METHOD("setClickToExpand", lua_fairygui_GTree_setClickToExpand);
	LUA_METHOD("setIndent", lua_fairygui_GTree_setIndent);
	LUA_METHOD("unselectNode", lua_fairygui_GTree_unselectNode);
	LUA_METHOD("create", lua_fairygui_GTree_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_IUISource_getFileName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.IUISource", "fgui.IUISource:getFileName");
	LUA_TRY_INVOKE_R(0, &fairygui::IUISource::getFileName);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_IUISource_isLoaded(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.IUISource", "fgui.IUISource:isLoaded");
	LUA_TRY_INVOKE_R(0, &fairygui::IUISource::isLoaded);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_IUISource_load(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.IUISource", "fgui.IUISource:load");
	LUA_TRY_INVOKE(1, &fairygui::IUISource::load);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_IUISource_setFileName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.IUISource", "fgui.IUISource:setFileName");
	LUA_TRY_INVOKE(1, &fairygui::IUISource::setFileName);
	LUA_INVOKE_FOOTER("1");
}
int luaReg_fgui_fguiIUISource(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::IUISource, "IUISource", "fgui.IUISource",
		cocos2d::Ref, "fgui.cocos2d.Ref",
		nullptr, nullptr);
	LUA_METHOD("getFileName", lua_fairygui_IUISource_getFileName);
	LUA_METHOD("isLoaded", lua_fairygui_IUISource_isLoaded);
	LUA_METHOD("load", lua_fairygui_IUISource_load);
	LUA_METHOD("setFileName", lua_fairygui_IUISource_setFileName);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_Window_addUISource(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:addUISource");
	LUA_TRY_INVOKE(1, &fairygui::Window::addUISource);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Window_bringToFront(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:bringToFront");
	LUA_TRY_INVOKE(0, &fairygui::Window::bringToFront);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_closeModalWait(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:closeModalWait");
	LUA_TRY_INVOKE_R(1, static_cast<bool(fairygui::Window::*)(int)>(&fairygui::Window::closeModalWait));
	LUA_TRY_INVOKE_R(0, static_cast<bool(fairygui::Window::*)()>(&fairygui::Window::closeModalWait));
	LUA_INVOKE_FOOTER("0,1");
}
int lua_fairygui_Window_getCloseButton(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:getCloseButton");
	LUA_TRY_INVOKE_R(0, &fairygui::Window::getCloseButton);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_getContentArea(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:getContentArea");
	LUA_TRY_INVOKE_R(0, &fairygui::Window::getContentArea);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_getContentPane(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:getContentPane");
	LUA_TRY_INVOKE_R(0, &fairygui::Window::getContentPane);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_getDragArea(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:getDragArea");
	LUA_TRY_INVOKE_R(0, &fairygui::Window::getDragArea);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_getFrame(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:getFrame");
	LUA_TRY_INVOKE_R(0, &fairygui::Window::getFrame);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_getModalWaitingPane(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:getModalWaitingPane");
	LUA_TRY_INVOKE_R(0, &fairygui::Window::getModalWaitingPane);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_hide(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:hide");
	LUA_TRY_INVOKE(0, &fairygui::Window::hide);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_hideImmediately(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:hideImmediately");
	LUA_TRY_INVOKE(0, &fairygui::Window::hideImmediately);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_initWindow(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:initWindow");
	LUA_TRY_INVOKE(0, &fairygui::Window::initWindow);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_isBringToFrontOnClick(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:isBringToFrontOnClick");
	LUA_TRY_INVOKE_R(0, &fairygui::Window::isBringToFrontOnClick);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_isModal(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:isModal");
	LUA_TRY_INVOKE_R(0, &fairygui::Window::isModal);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_isShowing(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:isShowing");
	LUA_TRY_INVOKE_R(0, &fairygui::Window::isShowing);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_isTop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:isTop");
	LUA_TRY_INVOKE_R(0, &fairygui::Window::isTop);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_setBringToFrontOnClick(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:setBringToFrontOnClick");
	LUA_TRY_INVOKE(1, &fairygui::Window::setBringToFrontOnClick);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Window_setCloseButton(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:setCloseButton");
	LUA_TRY_INVOKE(1, &fairygui::Window::setCloseButton);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Window_setContentArea(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:setContentArea");
	LUA_TRY_INVOKE(1, &fairygui::Window::setContentArea);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Window_setContentPane(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:setContentPane");
	LUA_TRY_INVOKE(1, &fairygui::Window::setContentPane);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Window_setDragArea(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:setDragArea");
	LUA_TRY_INVOKE(1, &fairygui::Window::setDragArea);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Window_setModal(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:setModal");
	LUA_TRY_INVOKE(1, &fairygui::Window::setModal);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_Window_show(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:show");
	LUA_TRY_INVOKE(0, &fairygui::Window::show);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_showModalWait(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:showModalWait");
	LUA_TRY_INVOKE(1, static_cast<void(fairygui::Window::*)(int)>(&fairygui::Window::showModalWait));
	LUA_TRY_INVOKE(0, static_cast<void(fairygui::Window::*)()>(&fairygui::Window::showModalWait));
	LUA_INVOKE_FOOTER("0,1");
}
int lua_fairygui_Window_toggleStatus(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.Window", "fgui.Window:toggleStatus");
	LUA_TRY_INVOKE(0, &fairygui::Window::toggleStatus);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_Window_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.Window", "fgui.Window:create");
	LUA_TRY_INVOKE_R(0, &fairygui::Window::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiWindow(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::Window, "Window", "fgui.Window",
		fairygui::GComponent, "fgui.GComponent",
		nullptr, nullptr);
	LUA_METHOD("addUISource", lua_fairygui_Window_addUISource);
	LUA_METHOD("bringToFront", lua_fairygui_Window_bringToFront);
	LUA_METHOD("closeModalWait", lua_fairygui_Window_closeModalWait);
	LUA_METHOD("getCloseButton", lua_fairygui_Window_getCloseButton);
	LUA_METHOD("getContentArea", lua_fairygui_Window_getContentArea);
	LUA_METHOD("getContentPane", lua_fairygui_Window_getContentPane);
	LUA_METHOD("getDragArea", lua_fairygui_Window_getDragArea);
	LUA_METHOD("getFrame", lua_fairygui_Window_getFrame);
	LUA_METHOD("getModalWaitingPane", lua_fairygui_Window_getModalWaitingPane);
	LUA_METHOD("hide", lua_fairygui_Window_hide);
	LUA_METHOD("hideImmediately", lua_fairygui_Window_hideImmediately);
	LUA_METHOD("initWindow", lua_fairygui_Window_initWindow);
	LUA_METHOD("isBringToFrontOnClick", lua_fairygui_Window_isBringToFrontOnClick);
	LUA_METHOD("isModal", lua_fairygui_Window_isModal);
	LUA_METHOD("isShowing", lua_fairygui_Window_isShowing);
	LUA_METHOD("isTop", lua_fairygui_Window_isTop);
	LUA_METHOD("setBringToFrontOnClick", lua_fairygui_Window_setBringToFrontOnClick);
	LUA_METHOD("setCloseButton", lua_fairygui_Window_setCloseButton);
	LUA_METHOD("setContentArea", lua_fairygui_Window_setContentArea);
	LUA_METHOD("setContentPane", lua_fairygui_Window_setContentPane);
	LUA_METHOD("setDragArea", lua_fairygui_Window_setDragArea);
	LUA_METHOD("setModal", lua_fairygui_Window_setModal);
	LUA_METHOD("show", lua_fairygui_Window_show);
	LUA_METHOD("showModalWait", lua_fairygui_Window_showModalWait);
	LUA_METHOD("toggleStatus", lua_fairygui_Window_toggleStatus);
	LUA_METHOD("create", lua_fairygui_Window_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_InputProcessor_addTouchMonitor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputProcessor", "fgui.InputProcessor:addTouchMonitor");
	LUA_TRY_INVOKE(2, &fairygui::InputProcessor::addTouchMonitor);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_InputProcessor_cancelClick(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputProcessor", "fgui.InputProcessor:cancelClick");
	LUA_TRY_INVOKE(1, &fairygui::InputProcessor::cancelClick);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_InputProcessor_disableDefaultTouchEvent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputProcessor", "fgui.InputProcessor:disableDefaultTouchEvent");
	LUA_TRY_INVOKE(0, &fairygui::InputProcessor::disableDefaultTouchEvent);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputProcessor_getRecentInput(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputProcessor", "fgui.InputProcessor:getRecentInput");
	LUA_TRY_INVOKE_R(0, &fairygui::InputProcessor::getRecentInput);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_InputProcessor_getTouchPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputProcessor", "fgui.InputProcessor:getTouchPosition");
	LUA_TRY_INVOKE_R(1, &fairygui::InputProcessor::getTouchPosition);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_InputProcessor_removeTouchMonitor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputProcessor", "fgui.InputProcessor:removeTouchMonitor");
	LUA_TRY_INVOKE(1, &fairygui::InputProcessor::removeTouchMonitor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_InputProcessor_setCaptureCallback(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputProcessor", "fgui.InputProcessor:setCaptureCallback");
	LUA_TRY_INVOKE(1, &fairygui::InputProcessor::setCaptureCallback);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_InputProcessor_simulateClick(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputProcessor", "fgui.InputProcessor:simulateClick");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::InputProcessor::*)(fairygui::GObject*, int)>(&fairygui::InputProcessor::simulateClick));
	LUA_TRY_INVOKE(1, [](fairygui::InputProcessor* obj, fairygui::GObject* arg0){{return obj->simulateClick(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_InputProcessor_touchDown(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputProcessor", "fgui.InputProcessor:touchDown");
	LUA_TRY_INVOKE_R(2, &fairygui::InputProcessor::touchDown);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_InputProcessor_touchMove(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputProcessor", "fgui.InputProcessor:touchMove");
	LUA_TRY_INVOKE(2, &fairygui::InputProcessor::touchMove);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_InputProcessor_touchUp(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.InputProcessor", "fgui.InputProcessor:touchUp");
	LUA_TRY_INVOKE(2, &fairygui::InputProcessor::touchUp);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_InputProcessor_isTouchOnUI(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.InputProcessor", "fgui.InputProcessor:isTouchOnUI");
	LUA_TRY_INVOKE_R(0, &fairygui::InputProcessor::isTouchOnUI);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiInputProcessor(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::InputProcessor, "InputProcessor", "fgui.InputProcessor",
		nullptr, nullptr);
	LUA_METHOD("addTouchMonitor", lua_fairygui_InputProcessor_addTouchMonitor);
	LUA_METHOD("cancelClick", lua_fairygui_InputProcessor_cancelClick);
	LUA_METHOD("disableDefaultTouchEvent", lua_fairygui_InputProcessor_disableDefaultTouchEvent);
	LUA_METHOD("getRecentInput", lua_fairygui_InputProcessor_getRecentInput);
	LUA_METHOD("getTouchPosition", lua_fairygui_InputProcessor_getTouchPosition);
	LUA_METHOD("removeTouchMonitor", lua_fairygui_InputProcessor_removeTouchMonitor);
	LUA_METHOD("setCaptureCallback", lua_fairygui_InputProcessor_setCaptureCallback);
	LUA_METHOD("simulateClick", lua_fairygui_InputProcessor_simulateClick);
	LUA_METHOD("touchDown", lua_fairygui_InputProcessor_touchDown);
	LUA_METHOD("touchMove", lua_fairygui_InputProcessor_touchMove);
	LUA_METHOD("touchUp", lua_fairygui_InputProcessor_touchUp);
	LUA_METHOD("isTouchOnUI", lua_fairygui_InputProcessor_isTouchOnUI);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GRoot_contentScaleLevel_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GRoot.contentScaleLevel/getter");
	LUA_PUSH_NATIVE(fairygui::GRoot::contentScaleLevel);
	return 1;
}
int lua_fairygui_GRoot_contentScaleLevel_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GRoot.contentScaleLevel/setter");
	LUA_NATIVE_SETTER(fairygui::GRoot::contentScaleLevel, 2);
	return 0;
}
int lua_fairygui_GRoot_bringToFront(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:bringToFront");
	LUA_TRY_INVOKE(1, &fairygui::GRoot::bringToFront);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GRoot_closeAllExceptModals(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:closeAllExceptModals");
	LUA_TRY_INVOKE(0, &fairygui::GRoot::closeAllExceptModals);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_closeAllWindows(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:closeAllWindows");
	LUA_TRY_INVOKE(0, &fairygui::GRoot::closeAllWindows);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_closeModalWait(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:closeModalWait");
	LUA_TRY_INVOKE(0, &fairygui::GRoot::closeModalWait);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_getInputProcessor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:getInputProcessor");
	LUA_TRY_INVOKE_R(0, &fairygui::GRoot::getInputProcessor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_getModalLayer(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:getModalLayer");
	LUA_TRY_INVOKE_R(0, &fairygui::GRoot::getModalLayer);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_getModalWaitingPane(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:getModalWaitingPane");
	LUA_TRY_INVOKE_R(0, &fairygui::GRoot::getModalWaitingPane);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_getPoupPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:getPoupPosition");
	LUA_TRY_INVOKE_R(3, &fairygui::GRoot::getPoupPosition);
	LUA_INVOKE_FOOTER("3");
}
int lua_fairygui_GRoot_getSoundVolumeScale(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:getSoundVolumeScale");
	LUA_TRY_INVOKE_R(0, &fairygui::GRoot::getSoundVolumeScale);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_getTopWindow(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:getTopWindow");
	LUA_TRY_INVOKE_R(0, &fairygui::GRoot::getTopWindow);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_getTouchPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:getTouchPosition");
	LUA_TRY_INVOKE_R(1, &fairygui::GRoot::getTouchPosition);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GRoot_getTouchTarget(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:getTouchTarget");
	LUA_TRY_INVOKE_R(0, &fairygui::GRoot::getTouchTarget);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_hasAnyPopup(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:hasAnyPopup");
	LUA_TRY_INVOKE_R(0, &fairygui::GRoot::hasAnyPopup);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_hasModalWindow(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:hasModalWindow");
	LUA_TRY_INVOKE_R(0, &fairygui::GRoot::hasModalWindow);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_hidePopup(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:hidePopup");
	LUA_TRY_INVOKE(1, static_cast<void(fairygui::GRoot::*)(fairygui::GObject*)>(&fairygui::GRoot::hidePopup));
	LUA_TRY_INVOKE(0, static_cast<void(fairygui::GRoot::*)()>(&fairygui::GRoot::hidePopup));
	LUA_INVOKE_FOOTER("0,1");
}
int lua_fairygui_GRoot_hideTooltips(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:hideTooltips");
	LUA_TRY_INVOKE(0, &fairygui::GRoot::hideTooltips);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_hideWindow(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:hideWindow");
	LUA_TRY_INVOKE(1, &fairygui::GRoot::hideWindow);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GRoot_hideWindowImmediately(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:hideWindowImmediately");
	LUA_TRY_INVOKE(1, &fairygui::GRoot::hideWindowImmediately);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GRoot_isModalWaiting(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:isModalWaiting");
	LUA_TRY_INVOKE_R(0, &fairygui::GRoot::isModalWaiting);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_isSoundEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:isSoundEnabled");
	LUA_TRY_INVOKE_R(0, &fairygui::GRoot::isSoundEnabled);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_playSound(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:playSound");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::GRoot::*)(const std::string&, float)>(&fairygui::GRoot::playSound));
	LUA_TRY_INVOKE(1, [](fairygui::GRoot* obj, const std::string& arg0){{return obj->playSound(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_GRoot_rootToWorld(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:rootToWorld");
	LUA_TRY_INVOKE_R(1, &fairygui::GRoot::rootToWorld);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GRoot_setSoundEnabled(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:setSoundEnabled");
	LUA_TRY_INVOKE(1, &fairygui::GRoot::setSoundEnabled);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GRoot_setSoundVolumeScale(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:setSoundVolumeScale");
	LUA_TRY_INVOKE(1, &fairygui::GRoot::setSoundVolumeScale);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GRoot_showModalWait(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:showModalWait");
	LUA_TRY_INVOKE(0, &fairygui::GRoot::showModalWait);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GRoot_showPopup(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:showPopup");
	LUA_TRY_INVOKE(3, static_cast<void(fairygui::GRoot::*)(fairygui::GObject*, fairygui::GObject*, fairygui::PopupDirection)>(&fairygui::GRoot::showPopup));
	LUA_TRY_INVOKE(1, static_cast<void(fairygui::GRoot::*)(fairygui::GObject*)>(&fairygui::GRoot::showPopup));
	LUA_INVOKE_FOOTER("1,3");
}
int lua_fairygui_GRoot_showTooltips(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:showTooltips");
	LUA_TRY_INVOKE(1, &fairygui::GRoot::showTooltips);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GRoot_showTooltipsWin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:showTooltipsWin");
	LUA_TRY_INVOKE(1, &fairygui::GRoot::showTooltipsWin);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GRoot_showWindow(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:showWindow");
	LUA_TRY_INVOKE(1, &fairygui::GRoot::showWindow);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GRoot_togglePopup(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:togglePopup");
	LUA_TRY_INVOKE(3, static_cast<void(fairygui::GRoot::*)(fairygui::GObject*, fairygui::GObject*, fairygui::PopupDirection)>(&fairygui::GRoot::togglePopup));
	LUA_TRY_INVOKE(1, static_cast<void(fairygui::GRoot::*)(fairygui::GObject*)>(&fairygui::GRoot::togglePopup));
	LUA_INVOKE_FOOTER("1,3");
}
int lua_fairygui_GRoot_worldToRoot(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GRoot", "fgui.GRoot:worldToRoot");
	LUA_TRY_INVOKE_R(1, &fairygui::GRoot::worldToRoot);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GRoot_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GRoot", "fgui.GRoot:create");
	LUA_TRY_INVOKE_R(2, static_cast<fairygui::GRoot*(*)(cocos2d::Scene*, int)>(&fairygui::GRoot::create));
	LUA_TRY_INVOKE_R(1, [](cocos2d::Scene* arg0){{return fairygui::GRoot::create(arg0);}});
	LUA_SINVOKE_FOOTER("1,2");
}
int lua_fairygui_GRoot_getInstance(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GRoot", "fgui.GRoot:getInstance");
	LUA_TRY_INVOKE_R(0, &fairygui::GRoot::getInstance);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGRoot(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GRoot, "GRoot", "fgui.GRoot",
		fairygui::GComponent, "fgui.GComponent",
		nullptr, nullptr);
	LUA_SFIELD("contentScaleLevel", lua_fairygui_GRoot_contentScaleLevel_getter, lua_fairygui_GRoot_contentScaleLevel_setter);
	LUA_METHOD("bringToFront", lua_fairygui_GRoot_bringToFront);
	LUA_METHOD("closeAllExceptModals", lua_fairygui_GRoot_closeAllExceptModals);
	LUA_METHOD("closeAllWindows", lua_fairygui_GRoot_closeAllWindows);
	LUA_METHOD("closeModalWait", lua_fairygui_GRoot_closeModalWait);
	LUA_METHOD("getInputProcessor", lua_fairygui_GRoot_getInputProcessor);
	LUA_METHOD("getModalLayer", lua_fairygui_GRoot_getModalLayer);
	LUA_METHOD("getModalWaitingPane", lua_fairygui_GRoot_getModalWaitingPane);
	LUA_METHOD("getPoupPosition", lua_fairygui_GRoot_getPoupPosition);
	LUA_METHOD("getSoundVolumeScale", lua_fairygui_GRoot_getSoundVolumeScale);
	LUA_METHOD("getTopWindow", lua_fairygui_GRoot_getTopWindow);
	LUA_METHOD("getTouchPosition", lua_fairygui_GRoot_getTouchPosition);
	LUA_METHOD("getTouchTarget", lua_fairygui_GRoot_getTouchTarget);
	LUA_METHOD("hasAnyPopup", lua_fairygui_GRoot_hasAnyPopup);
	LUA_METHOD("hasModalWindow", lua_fairygui_GRoot_hasModalWindow);
	LUA_METHOD("hidePopup", lua_fairygui_GRoot_hidePopup);
	LUA_METHOD("hideTooltips", lua_fairygui_GRoot_hideTooltips);
	LUA_METHOD("hideWindow", lua_fairygui_GRoot_hideWindow);
	LUA_METHOD("hideWindowImmediately", lua_fairygui_GRoot_hideWindowImmediately);
	LUA_METHOD("isModalWaiting", lua_fairygui_GRoot_isModalWaiting);
	LUA_METHOD("isSoundEnabled", lua_fairygui_GRoot_isSoundEnabled);
	LUA_METHOD("playSound", lua_fairygui_GRoot_playSound);
	LUA_METHOD("rootToWorld", lua_fairygui_GRoot_rootToWorld);
	LUA_METHOD("setSoundEnabled", lua_fairygui_GRoot_setSoundEnabled);
	LUA_METHOD("setSoundVolumeScale", lua_fairygui_GRoot_setSoundVolumeScale);
	LUA_METHOD("showModalWait", lua_fairygui_GRoot_showModalWait);
	LUA_METHOD("showPopup", lua_fairygui_GRoot_showPopup);
	LUA_METHOD("showTooltips", lua_fairygui_GRoot_showTooltips);
	LUA_METHOD("showTooltipsWin", lua_fairygui_GRoot_showTooltipsWin);
	LUA_METHOD("showWindow", lua_fairygui_GRoot_showWindow);
	LUA_METHOD("togglePopup", lua_fairygui_GRoot_togglePopup);
	LUA_METHOD("worldToRoot", lua_fairygui_GRoot_worldToRoot);
	LUA_METHOD("create", lua_fairygui_GRoot_create);
	LUA_METHOD("getInstance", lua_fairygui_GRoot_getInstance);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_PopupMenu_addItem(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:addItem");
	LUA_TRY_INVOKE_R(2, &fairygui::PopupMenu::addItem);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_PopupMenu_addItemAt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:addItemAt");
	LUA_TRY_INVOKE_R(3, &fairygui::PopupMenu::addItemAt);
	LUA_INVOKE_FOOTER("3");
}
int lua_fairygui_PopupMenu_addSeperator(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:addSeperator");
	LUA_TRY_INVOKE(0, &fairygui::PopupMenu::addSeperator);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_PopupMenu_clearItems(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:clearItems");
	LUA_TRY_INVOKE(0, &fairygui::PopupMenu::clearItems);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_PopupMenu_getContentPane(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:getContentPane");
	LUA_TRY_INVOKE_R(0, &fairygui::PopupMenu::getContentPane);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_PopupMenu_getItemCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:getItemCount");
	LUA_TRY_INVOKE_R(0, &fairygui::PopupMenu::getItemCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_PopupMenu_getItemName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:getItemName");
	LUA_TRY_INVOKE_R(1, &fairygui::PopupMenu::getItemName);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_PopupMenu_getList(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:getList");
	LUA_TRY_INVOKE_R(0, &fairygui::PopupMenu::getList);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_PopupMenu_isItemChecked(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:isItemChecked");
	LUA_TRY_INVOKE_R(1, &fairygui::PopupMenu::isItemChecked);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_PopupMenu_removeItem(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:removeItem");
	LUA_TRY_INVOKE_R(1, &fairygui::PopupMenu::removeItem);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_PopupMenu_setItemCheckable(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:setItemCheckable");
	LUA_TRY_INVOKE(2, &fairygui::PopupMenu::setItemCheckable);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_PopupMenu_setItemChecked(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:setItemChecked");
	LUA_TRY_INVOKE(2, &fairygui::PopupMenu::setItemChecked);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_PopupMenu_setItemGrayed(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:setItemGrayed");
	LUA_TRY_INVOKE(2, &fairygui::PopupMenu::setItemGrayed);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_PopupMenu_setItemText(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:setItemText");
	LUA_TRY_INVOKE(2, &fairygui::PopupMenu::setItemText);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_PopupMenu_setItemVisible(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:setItemVisible");
	LUA_TRY_INVOKE(2, &fairygui::PopupMenu::setItemVisible);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_PopupMenu_show(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:show");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::PopupMenu::*)(fairygui::GObject*, fairygui::PopupDirection)>(&fairygui::PopupMenu::show));
	LUA_TRY_INVOKE(0, static_cast<void(fairygui::PopupMenu::*)()>(&fairygui::PopupMenu::show));
	LUA_INVOKE_FOOTER("0,2");
}
int lua_fairygui_PopupMenu_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.PopupMenu", "fgui.PopupMenu:create");
	LUA_TRY_INVOKE_R(1, static_cast<fairygui::PopupMenu*(*)(const std::string&)>(&fairygui::PopupMenu::create));
	LUA_TRY_INVOKE_R(0, static_cast<fairygui::PopupMenu*(*)()>(&fairygui::PopupMenu::create));
	LUA_SINVOKE_FOOTER("0,1");
}
int luaReg_fgui_fguiPopupMenu(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::PopupMenu, "PopupMenu", "fgui.PopupMenu",
		cocos2d::Ref, "fgui.cocos2d.Ref",
		nullptr, nullptr);
	LUA_METHOD("addItem", lua_fairygui_PopupMenu_addItem);
	LUA_METHOD("addItemAt", lua_fairygui_PopupMenu_addItemAt);
	LUA_METHOD("addSeperator", lua_fairygui_PopupMenu_addSeperator);
	LUA_METHOD("clearItems", lua_fairygui_PopupMenu_clearItems);
	LUA_METHOD("getContentPane", lua_fairygui_PopupMenu_getContentPane);
	LUA_METHOD("getItemCount", lua_fairygui_PopupMenu_getItemCount);
	LUA_METHOD("getItemName", lua_fairygui_PopupMenu_getItemName);
	LUA_METHOD("getList", lua_fairygui_PopupMenu_getList);
	LUA_METHOD("isItemChecked", lua_fairygui_PopupMenu_isItemChecked);
	LUA_METHOD("removeItem", lua_fairygui_PopupMenu_removeItem);
	LUA_METHOD("setItemCheckable", lua_fairygui_PopupMenu_setItemCheckable);
	LUA_METHOD("setItemChecked", lua_fairygui_PopupMenu_setItemChecked);
	LUA_METHOD("setItemGrayed", lua_fairygui_PopupMenu_setItemGrayed);
	LUA_METHOD("setItemText", lua_fairygui_PopupMenu_setItemText);
	LUA_METHOD("setItemVisible", lua_fairygui_PopupMenu_setItemVisible);
	LUA_METHOD("show", lua_fairygui_PopupMenu_show);
	LUA_METHOD("create", lua_fairygui_PopupMenu_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_UIObjectFactory_newObject(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIObjectFactory", "fgui.UIObjectFactory:newObject");
	LUA_TRY_INVOKE_R(1, static_cast<fairygui::GObject*(*)(fairygui::ObjectType)>(&fairygui::UIObjectFactory::newObject));
	LUA_TRY_INVOKE_R(1, static_cast<fairygui::GObject*(*)(fairygui::PackageItem*)>(&fairygui::UIObjectFactory::newObject));
	LUA_SINVOKE_FOOTER("1");
}
int lua_fairygui_UIObjectFactory_setLoaderExtension(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIObjectFactory", "fgui.UIObjectFactory:setLoaderExtension");
	LUA_TRY_INVOKE(1, &fairygui::UIObjectFactory::setLoaderExtension);
	LUA_SINVOKE_FOOTER("1");
}
int lua_fairygui_UIObjectFactory_setPackageItemExtension(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.UIObjectFactory", "fgui.UIObjectFactory:setPackageItemExtension");
	LUA_TRY_INVOKE(2, &fairygui::UIObjectFactory::setPackageItemExtension);
	LUA_SINVOKE_FOOTER("2");
}
int luaReg_fgui_fguiUIObjectFactory(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::UIObjectFactory, "UIObjectFactory", "fgui.UIObjectFactory",
		nullptr, nullptr);
	LUA_METHOD("newObject", lua_fairygui_UIObjectFactory_newObject);
	LUA_METHOD("setLoaderExtension", lua_fairygui_UIObjectFactory_setLoaderExtension);
	LUA_METHOD("setPackageItemExtension", lua_fairygui_UIObjectFactory_setPackageItemExtension);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_DragDropManager_cancel(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.DragDropManager", "fgui.DragDropManager:cancel");
	LUA_TRY_INVOKE(0, &fairygui::DragDropManager::cancel);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_DragDropManager_getAgent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.DragDropManager", "fgui.DragDropManager:getAgent");
	LUA_TRY_INVOKE_R(0, &fairygui::DragDropManager::getAgent);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_DragDropManager_isDragging(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.DragDropManager", "fgui.DragDropManager:isDragging");
	LUA_TRY_INVOKE_R(0, &fairygui::DragDropManager::isDragging);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_DragDropManager_startDrag(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.DragDropManager", "fgui.DragDropManager:startDrag");
	LUA_TRY_INVOKE(3, static_cast<void(fairygui::DragDropManager::*)(const std::string&, const cocos2d::Value&, int)>(&fairygui::DragDropManager::startDrag));
	LUA_TRY_INVOKE(2, [](fairygui::DragDropManager* obj, const std::string& arg0,const cocos2d::Value& arg1){{return obj->startDrag(arg0,arg1);}});
	LUA_TRY_INVOKE(1, [](fairygui::DragDropManager* obj, const std::string& arg0){{return obj->startDrag(arg0);}});
	LUA_INVOKE_FOOTER("1,2,3");
}
int lua_fairygui_DragDropManager_getInstance(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.DragDropManager", "fgui.DragDropManager:getInstance");
	LUA_TRY_INVOKE_R(0, &fairygui::DragDropManager::getInstance);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiDragDropManager(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::DragDropManager, "DragDropManager", "fgui.DragDropManager",
		nullptr, nullptr);
	LUA_METHOD("cancel", lua_fairygui_DragDropManager_cancel);
	LUA_METHOD("getAgent", lua_fairygui_DragDropManager_getAgent);
	LUA_METHOD("isDragging", lua_fairygui_DragDropManager_isDragging);
	LUA_METHOD("startDrag", lua_fairygui_DragDropManager_startDrag);
	LUA_METHOD("getInstance", lua_fairygui_DragDropManager_getInstance);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiTweenPropType(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_ENUM_DEF("TweenPropType");
	LUA_ENUM_ENTRY("None", fairygui::TweenPropType::None);
	LUA_ENUM_ENTRY("X", fairygui::TweenPropType::X);
	LUA_ENUM_ENTRY("Y", fairygui::TweenPropType::Y);
	LUA_ENUM_ENTRY("Position", fairygui::TweenPropType::Position);
	LUA_ENUM_ENTRY("Width", fairygui::TweenPropType::Width);
	LUA_ENUM_ENTRY("Height", fairygui::TweenPropType::Height);
	LUA_ENUM_ENTRY("Size", fairygui::TweenPropType::Size);
	LUA_ENUM_ENTRY("ScaleX", fairygui::TweenPropType::ScaleX);
	LUA_ENUM_ENTRY("ScaleY", fairygui::TweenPropType::ScaleY);
	LUA_ENUM_ENTRY("Scale", fairygui::TweenPropType::Scale);
	LUA_ENUM_ENTRY("Rotation", fairygui::TweenPropType::Rotation);
	LUA_ENUM_ENTRY("Alpha", fairygui::TweenPropType::Alpha);
	LUA_ENUM_ENTRY("Progress", fairygui::TweenPropType::Progress);
	LUA_ENUM_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GTweener_deltaValue_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GTweener.deltaValue/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GTweener*, 1);
	LUA_PUSH_NATIVE(cobj->deltaValue);
	return 1;
}
int lua_fairygui_GTweener_deltaValue_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GTweener.deltaValue/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GTweener*, 1);
	LUA_NATIVE_SETTER(cobj->deltaValue, 2);
	return 0;
}
int lua_fairygui_GTweener_endValue_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GTweener.endValue/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GTweener*, 1);
	LUA_PUSH_NATIVE(cobj->endValue);
	return 1;
}
int lua_fairygui_GTweener_endValue_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GTweener.endValue/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GTweener*, 1);
	LUA_NATIVE_SETTER(cobj->endValue, 2);
	return 0;
}
int lua_fairygui_GTweener_startValue_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GTweener.startValue/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GTweener*, 1);
	LUA_PUSH_NATIVE(cobj->startValue);
	return 1;
}
int lua_fairygui_GTweener_startValue_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GTweener.startValue/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GTweener*, 1);
	LUA_NATIVE_SETTER(cobj->startValue, 2);
	return 0;
}
int lua_fairygui_GTweener_value_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GTweener.value/getter");
	auto cobj = LUA_TO_COBJ(fairygui::GTweener*, 1);
	LUA_PUSH_NATIVE(cobj->value);
	return 1;
}
int lua_fairygui_GTweener_value_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.GTweener.value/setter");
	auto cobj = LUA_TO_COBJ(fairygui::GTweener*, 1);
	LUA_NATIVE_SETTER(cobj->value, 2);
	return 0;
}
int lua_fairygui_GTweener_allCompleted(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:allCompleted");
	LUA_TRY_INVOKE_R(0, &fairygui::GTweener::allCompleted);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTweener_getDelay(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:getDelay");
	LUA_TRY_INVOKE_R(0, &fairygui::GTweener::getDelay);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTweener_getDuration(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:getDuration");
	LUA_TRY_INVOKE_R(0, &fairygui::GTweener::getDuration);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTweener_getNormalizedTime(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:getNormalizedTime");
	LUA_TRY_INVOKE_R(0, &fairygui::GTweener::getNormalizedTime);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTweener_getRepeat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:getRepeat");
	LUA_TRY_INVOKE_R(0, &fairygui::GTweener::getRepeat);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTweener_getTarget(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:getTarget");
	LUA_TRY_INVOKE_R(0, &fairygui::GTweener::getTarget);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTweener_getUserData(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:getUserData");
	LUA_TRY_INVOKE_R(0, &fairygui::GTweener::getUserData);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTweener_isCompleted(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:isCompleted");
	LUA_TRY_INVOKE_R(0, &fairygui::GTweener::isCompleted);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GTweener_kill(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:kill");
	LUA_TRY_INVOKE(1, static_cast<void(fairygui::GTweener::*)(bool)>(&fairygui::GTweener::kill));
	LUA_TRY_INVOKE(0, [](fairygui::GTweener* obj){{return obj->kill();}});
	LUA_INVOKE_FOOTER("0,1");
}
int lua_fairygui_GTweener_onComplete(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:onComplete");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::onComplete);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_onComplete1(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:onComplete1");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::onComplete1);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_onStart(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:onStart");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::onStart);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_onUpdate(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:onUpdate");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::onUpdate);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_seek(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:seek");
	LUA_TRY_INVOKE(1, &fairygui::GTweener::seek);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_setBreakpoint(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setBreakpoint");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::setBreakpoint);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_setDelay(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setDelay");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::setDelay);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_setDuration(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setDuration");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::setDuration);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_setEase(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setEase");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::setEase);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_setEaseOvershootOrAmplitude(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setEaseOvershootOrAmplitude");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::setEaseOvershootOrAmplitude);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_setEasePeriod(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setEasePeriod");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::setEasePeriod);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_setPath(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setPath");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::setPath);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_setPaused(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setPaused");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::setPaused);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_setRepeat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setRepeat");
	LUA_TRY_INVOKE_R(2, static_cast<fairygui::GTweener*(fairygui::GTweener::*)(int, bool)>(&fairygui::GTweener::setRepeat));
	LUA_TRY_INVOKE_R(1, [](fairygui::GTweener* obj, int arg0){{return obj->setRepeat(std::move(arg0));}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_GTweener_setSnapping(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setSnapping");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::setSnapping);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_setTarget(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setTarget");
	LUA_TRY_INVOKE_R(2, static_cast<fairygui::GTweener*(fairygui::GTweener::*)(cocos2d::Ref*, fairygui::TweenPropType)>(&fairygui::GTweener::setTarget));
	LUA_TRY_INVOKE_R(1, static_cast<fairygui::GTweener*(fairygui::GTweener::*)(cocos2d::Ref*)>(&fairygui::GTweener::setTarget));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_GTweener_setTargetAny(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setTargetAny");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::setTargetAny);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_setTimeScale(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setTimeScale");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::setTimeScale);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GTweener_setUserData(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GTweener", "fgui.GTweener:setUserData");
	LUA_TRY_INVOKE_R(1, &fairygui::GTweener::setUserData);
	LUA_INVOKE_FOOTER("1");
}
int luaReg_fgui_fguiGTweener(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GTweener, "GTweener", "fgui.GTweener",
		cocos2d::Ref, "fgui.cocos2d.Ref",
		nullptr, nullptr);
	LUA_FIELD("deltaValue", lua_fairygui_GTweener_deltaValue_getter, lua_fairygui_GTweener_deltaValue_setter);
	LUA_FIELD("endValue", lua_fairygui_GTweener_endValue_getter, lua_fairygui_GTweener_endValue_setter);
	LUA_FIELD("startValue", lua_fairygui_GTweener_startValue_getter, lua_fairygui_GTweener_startValue_setter);
	LUA_FIELD("value", lua_fairygui_GTweener_value_getter, lua_fairygui_GTweener_value_setter);
	LUA_METHOD("allCompleted", lua_fairygui_GTweener_allCompleted);
	LUA_METHOD("getDelay", lua_fairygui_GTweener_getDelay);
	LUA_METHOD("getDuration", lua_fairygui_GTweener_getDuration);
	LUA_METHOD("getNormalizedTime", lua_fairygui_GTweener_getNormalizedTime);
	LUA_METHOD("getRepeat", lua_fairygui_GTweener_getRepeat);
	LUA_METHOD("getTarget", lua_fairygui_GTweener_getTarget);
	LUA_METHOD("getUserData", lua_fairygui_GTweener_getUserData);
	LUA_METHOD("isCompleted", lua_fairygui_GTweener_isCompleted);
	LUA_METHOD("kill", lua_fairygui_GTweener_kill);
	LUA_METHOD("onComplete", lua_fairygui_GTweener_onComplete);
	LUA_METHOD("onComplete1", lua_fairygui_GTweener_onComplete1);
	LUA_METHOD("onStart", lua_fairygui_GTweener_onStart);
	LUA_METHOD("onUpdate", lua_fairygui_GTweener_onUpdate);
	LUA_METHOD("seek", lua_fairygui_GTweener_seek);
	LUA_METHOD("setBreakpoint", lua_fairygui_GTweener_setBreakpoint);
	LUA_METHOD("setDelay", lua_fairygui_GTweener_setDelay);
	LUA_METHOD("setDuration", lua_fairygui_GTweener_setDuration);
	LUA_METHOD("setEase", lua_fairygui_GTweener_setEase);
	LUA_METHOD("setEaseOvershootOrAmplitude", lua_fairygui_GTweener_setEaseOvershootOrAmplitude);
	LUA_METHOD("setEasePeriod", lua_fairygui_GTweener_setEasePeriod);
	LUA_METHOD("setPath", lua_fairygui_GTweener_setPath);
	LUA_METHOD("setPaused", lua_fairygui_GTweener_setPaused);
	LUA_METHOD("setRepeat", lua_fairygui_GTweener_setRepeat);
	LUA_METHOD("setSnapping", lua_fairygui_GTweener_setSnapping);
	LUA_METHOD("setTarget", lua_fairygui_GTweener_setTarget);
	LUA_METHOD("setTargetAny", lua_fairygui_GTweener_setTargetAny);
	LUA_METHOD("setTimeScale", lua_fairygui_GTweener_setTimeScale);
	LUA_METHOD("setUserData", lua_fairygui_GTweener_setUserData);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GTween_clean(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GTween", "fgui.GTween:clean");
	LUA_TRY_INVOKE(0, &fairygui::GTween::clean);
	LUA_SINVOKE_FOOTER("0");
}
int lua_fairygui_GTween_delayedCall(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GTween", "fgui.GTween:delayedCall");
	LUA_TRY_INVOKE_R(1, &fairygui::GTween::delayedCall);
	LUA_SINVOKE_FOOTER("1");
}
int lua_fairygui_GTween_getTween(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GTween", "fgui.GTween:getTween");
	LUA_TRY_INVOKE_R(2, static_cast<fairygui::GTweener*(*)(cocos2d::Ref*, fairygui::TweenPropType)>(&fairygui::GTween::getTween));
	LUA_TRY_INVOKE_R(1, static_cast<fairygui::GTweener*(*)(cocos2d::Ref*)>(&fairygui::GTween::getTween));
	LUA_SINVOKE_FOOTER("1,2");
}
int lua_fairygui_GTween_isTweening(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GTween", "fgui.GTween:isTweening");
	LUA_TRY_INVOKE_R(2, static_cast<bool(*)(cocos2d::Ref*, fairygui::TweenPropType)>(&fairygui::GTween::isTweening));
	LUA_TRY_INVOKE_R(1, static_cast<bool(*)(cocos2d::Ref*)>(&fairygui::GTween::isTweening));
	LUA_SINVOKE_FOOTER("1,2");
}
int lua_fairygui_GTween_kill(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GTween", "fgui.GTween:kill");
	LUA_TRY_INVOKE(3, static_cast<void(*)(cocos2d::Ref*, fairygui::TweenPropType, bool)>(&fairygui::GTween::kill));
	LUA_TRY_INVOKE(2, static_cast<void(*)(cocos2d::Ref*, bool)>(&fairygui::GTween::kill));
	LUA_TRY_INVOKE(1, static_cast<void(*)(cocos2d::Ref*)>(&fairygui::GTween::kill));
	LUA_SINVOKE_FOOTER("1,2,3");
}
int lua_fairygui_GTween_shake(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GTween", "fgui.GTween:shake");
	LUA_TRY_INVOKE_R(3, &fairygui::GTween::shake);
	LUA_SINVOKE_FOOTER("3");
}
int lua_fairygui_GTween_to(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GTween", "fgui.GTween:to");
	LUA_TRY_INVOKE_R(3, static_cast<fairygui::GTweener*(*)(const cocos2d::Color4B&, const cocos2d::Color4B&, float)>(&fairygui::GTween::to));
	LUA_TRY_INVOKE_R(3, static_cast<fairygui::GTweener*(*)(const cocos2d::Vec4&, const cocos2d::Vec4&, float)>(&fairygui::GTween::to));
	LUA_TRY_INVOKE_R(3, static_cast<fairygui::GTweener*(*)(const cocos2d::Vec3&, const cocos2d::Vec3&, float)>(&fairygui::GTween::to));
	LUA_TRY_INVOKE_R(3, static_cast<fairygui::GTweener*(*)(const cocos2d::Vec2&, const cocos2d::Vec2&, float)>(&fairygui::GTween::to));
	LUA_TRY_INVOKE_R(3, static_cast<fairygui::GTweener*(*)(float, float, float)>(&fairygui::GTween::to));
	LUA_SINVOKE_FOOTER("3");
}
int lua_fairygui_GTween_toDouble(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GTween", "fgui.GTween:toDouble");
	LUA_TRY_INVOKE_R(3, &fairygui::GTween::toDouble);
	LUA_SINVOKE_FOOTER("3");
}
int luaReg_fgui_fguiGTween(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::GTween, "GTween", "fgui.GTween",
		nullptr, nullptr);
	LUA_METHOD("clean", lua_fairygui_GTween_clean);
	LUA_METHOD("delayedCall", lua_fairygui_GTween_delayedCall);
	LUA_METHOD("getTween", lua_fairygui_GTween_getTween);
	LUA_METHOD("isTweening", lua_fairygui_GTween_isTweening);
	LUA_METHOD("kill", lua_fairygui_GTween_kill);
	LUA_METHOD("shake", lua_fairygui_GTween_shake);
	LUA_METHOD("to", lua_fairygui_GTween_to);
	LUA_METHOD("toDouble", lua_fairygui_GTween_toDouble);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GLoader3D_getAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:getAlign");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::getAlign);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader3D_getAnimationName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:getAnimationName");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::getAnimationName);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader3D_getAutoSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:getAutoSize");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::getAutoSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader3D_getColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:getColor");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::getColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader3D_getContent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:getContent");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::getContent);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader3D_getFill(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:getFill");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::getFill);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader3D_getFrame(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:getFrame");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::getFrame);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader3D_getLoop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:getLoop");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::getLoop);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader3D_getSkinName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:getSkinName");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::getSkinName);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader3D_getURL(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:getURL");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::getURL);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader3D_getVerticalAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:getVerticalAlign");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::getVerticalAlign);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader3D_isPlaying(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:isPlaying");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::isPlaying);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader3D_isShrinkOnly(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:isShrinkOnly");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::isShrinkOnly);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GLoader3D_setAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:setAlign");
	LUA_TRY_INVOKE(1, &fairygui::GLoader3D::setAlign);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader3D_setAnimationName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:setAnimationName");
	LUA_TRY_INVOKE(1, &fairygui::GLoader3D::setAnimationName);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader3D_setAutoSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:setAutoSize");
	LUA_TRY_INVOKE(1, &fairygui::GLoader3D::setAutoSize);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader3D_setColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:setColor");
	LUA_TRY_INVOKE(1, &fairygui::GLoader3D::setColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader3D_setContent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:setContent");
	LUA_TRY_INVOKE(1, &fairygui::GLoader3D::setContent);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader3D_setFill(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:setFill");
	LUA_TRY_INVOKE(1, &fairygui::GLoader3D::setFill);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader3D_setFrame(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:setFrame");
	LUA_TRY_INVOKE(1, &fairygui::GLoader3D::setFrame);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader3D_setLoop(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:setLoop");
	LUA_TRY_INVOKE(1, &fairygui::GLoader3D::setLoop);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader3D_setPlaying(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:setPlaying");
	LUA_TRY_INVOKE(1, &fairygui::GLoader3D::setPlaying);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader3D_setShrinkOnly(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:setShrinkOnly");
	LUA_TRY_INVOKE(1, &fairygui::GLoader3D::setShrinkOnly);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader3D_setSkinName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:setSkinName");
	LUA_TRY_INVOKE(1, &fairygui::GLoader3D::setSkinName);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader3D_setURL(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:setURL");
	LUA_TRY_INVOKE(1, &fairygui::GLoader3D::setURL);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader3D_setVerticalAlign(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:setVerticalAlign");
	LUA_TRY_INVOKE(1, &fairygui::GLoader3D::setVerticalAlign);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GLoader3D_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.GLoader3D", "fgui.GLoader3D:create");
	LUA_TRY_INVOKE_R(0, &fairygui::GLoader3D::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiGLoader3D(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::GLoader3D, "GLoader3D", "fgui.GLoader3D",
		fairygui::GObject, "fgui.GObject",
		nullptr, nullptr);
	LUA_METHOD("getAlign", lua_fairygui_GLoader3D_getAlign);
	LUA_METHOD("getAnimationName", lua_fairygui_GLoader3D_getAnimationName);
	LUA_METHOD("getAutoSize", lua_fairygui_GLoader3D_getAutoSize);
	LUA_METHOD("getColor", lua_fairygui_GLoader3D_getColor);
	LUA_METHOD("getContent", lua_fairygui_GLoader3D_getContent);
	LUA_METHOD("getFill", lua_fairygui_GLoader3D_getFill);
	LUA_METHOD("getFrame", lua_fairygui_GLoader3D_getFrame);
	LUA_METHOD("getLoop", lua_fairygui_GLoader3D_getLoop);
	LUA_METHOD("getSkinName", lua_fairygui_GLoader3D_getSkinName);
	LUA_METHOD("getURL", lua_fairygui_GLoader3D_getURL);
	LUA_METHOD("getVerticalAlign", lua_fairygui_GLoader3D_getVerticalAlign);
	LUA_METHOD("isPlaying", lua_fairygui_GLoader3D_isPlaying);
	LUA_METHOD("isShrinkOnly", lua_fairygui_GLoader3D_isShrinkOnly);
	LUA_METHOD("setAlign", lua_fairygui_GLoader3D_setAlign);
	LUA_METHOD("setAnimationName", lua_fairygui_GLoader3D_setAnimationName);
	LUA_METHOD("setAutoSize", lua_fairygui_GLoader3D_setAutoSize);
	LUA_METHOD("setColor", lua_fairygui_GLoader3D_setColor);
	LUA_METHOD("setContent", lua_fairygui_GLoader3D_setContent);
	LUA_METHOD("setFill", lua_fairygui_GLoader3D_setFill);
	LUA_METHOD("setFrame", lua_fairygui_GLoader3D_setFrame);
	LUA_METHOD("setLoop", lua_fairygui_GLoader3D_setLoop);
	LUA_METHOD("setPlaying", lua_fairygui_GLoader3D_setPlaying);
	LUA_METHOD("setShrinkOnly", lua_fairygui_GLoader3D_setShrinkOnly);
	LUA_METHOD("setSkinName", lua_fairygui_GLoader3D_setSkinName);
	LUA_METHOD("setURL", lua_fairygui_GLoader3D_setURL);
	LUA_METHOD("setVerticalAlign", lua_fairygui_GLoader3D_setVerticalAlign);
	LUA_METHOD("create", lua_fairygui_GLoader3D_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_EaseManager_evaluate(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.EaseManager", "fgui.EaseManager:evaluate");
	LUA_TRY_INVOKE_R(5, &fairygui::EaseManager::evaluate);
	LUA_SINVOKE_FOOTER("5");
}
int luaReg_fgui_fguiEaseManager(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::EaseManager, "EaseManager", "fgui.EaseManager",
		nullptr, nullptr);
	LUA_METHOD("evaluate", lua_fairygui_EaseManager_evaluate);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_GPath_clear(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GPath", "fgui.GPath:clear");
	LUA_TRY_INVOKE(0, &fairygui::GPath::clear);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GPath_create(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GPath", "fgui.GPath:create");
	LUA_TRY_INVOKE(2, &fairygui::GPath::create);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_GPath_getAllPoints(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GPath", "fgui.GPath:getAllPoints");
	LUA_TRY_INVOKE(2, static_cast<void(fairygui::GPath::*)(std::vector<cocos2d::Vec3>&, float)>(&fairygui::GPath::getAllPoints));
	LUA_TRY_INVOKE(1, [](fairygui::GPath* obj, std::vector<cocos2d::Vec3>& arg0){{return obj->getAllPoints(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_GPath_getLength(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GPath", "fgui.GPath:getLength");
	LUA_TRY_INVOKE_R(0, &fairygui::GPath::getLength);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GPath_getPointAt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GPath", "fgui.GPath:getPointAt");
	LUA_TRY_INVOKE_R(1, &fairygui::GPath::getPointAt);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_GPath_getPointsInSegment(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GPath", "fgui.GPath:getPointsInSegment");
	LUA_TRY_INVOKE(6, static_cast<void(fairygui::GPath::*)(int, float, float, std::vector<cocos2d::Vec3>&, std::vector<float>*, float)>(&fairygui::GPath::getPointsInSegment));
	LUA_TRY_INVOKE(5, [](fairygui::GPath* obj, int arg0,float arg1,float arg2,std::vector<cocos2d::Vec3>& arg3,std::vector<float>* arg4){{return obj->getPointsInSegment(arg0,arg1,arg2,arg3,arg4);}});
	LUA_INVOKE_FOOTER("5,6");
}
int lua_fairygui_GPath_getSegmentCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GPath", "fgui.GPath:getSegmentCount");
	LUA_TRY_INVOKE_R(0, &fairygui::GPath::getSegmentCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_GPath_getSegmentLength(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.GPath", "fgui.GPath:getSegmentLength");
	LUA_TRY_INVOKE_R(1, &fairygui::GPath::getSegmentLength);
	LUA_INVOKE_FOOTER("1");
}
int luaReg_fgui_fguiGPath(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::GPath, "GPath", "fgui.GPath",
		nullptr, nullptr);
	LUA_METHOD("clear", lua_fairygui_GPath_clear);
	LUA_METHOD("create", lua_fairygui_GPath_create);
	LUA_METHOD("getAllPoints", lua_fairygui_GPath_getAllPoints);
	LUA_METHOD("getLength", lua_fairygui_GPath_getLength);
	LUA_METHOD("getPointAt", lua_fairygui_GPath_getPointAt);
	LUA_METHOD("getPointsInSegment", lua_fairygui_GPath_getPointsInSegment);
	LUA_METHOD("getSegmentCount", lua_fairygui_GPath_getSegmentCount);
	LUA_METHOD("getSegmentLength", lua_fairygui_GPath_getSegmentLength);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_FUISprite_clearContent(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:clearContent");
	LUA_TRY_INVOKE(0, &fairygui::FUISprite::clearContent);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUISprite_getFillAmount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:getFillAmount");
	LUA_TRY_INVOKE_R(0, &fairygui::FUISprite::getFillAmount);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUISprite_getFillMethod(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:getFillMethod");
	LUA_TRY_INVOKE_R(0, &fairygui::FUISprite::getFillMethod);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUISprite_getFillOrigin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:getFillOrigin");
	LUA_TRY_INVOKE_R(0, &fairygui::FUISprite::getFillOrigin);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUISprite_isFillClockwise(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:isFillClockwise");
	LUA_TRY_INVOKE_R(0, &fairygui::FUISprite::isFillClockwise);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUISprite_isScaleByTile(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:isScaleByTile");
	LUA_TRY_INVOKE_R(0, &fairygui::FUISprite::isScaleByTile);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_FUISprite_setFillAmount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:setFillAmount");
	LUA_TRY_INVOKE(1, &fairygui::FUISprite::setFillAmount);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUISprite_setFillClockwise(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:setFillClockwise");
	LUA_TRY_INVOKE(1, &fairygui::FUISprite::setFillClockwise);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUISprite_setFillMethod(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:setFillMethod");
	LUA_TRY_INVOKE(1, &fairygui::FUISprite::setFillMethod);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUISprite_setFillOrigin(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:setFillOrigin");
	LUA_TRY_INVOKE(1, &fairygui::FUISprite::setFillOrigin);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUISprite_setGrayed(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:setGrayed");
	LUA_TRY_INVOKE(1, &fairygui::FUISprite::setGrayed);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUISprite_setScale9Grid(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:setScale9Grid");
	LUA_TRY_INVOKE(1, &fairygui::FUISprite::setScale9Grid);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUISprite_setScaleByTile(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:setScaleByTile");
	LUA_TRY_INVOKE(1, &fairygui::FUISprite::setScaleByTile);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_FUISprite_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("fgui.FUISprite", "fgui.FUISprite:create");
	LUA_TRY_INVOKE_R(0, &fairygui::FUISprite::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_fgui_fguiFUISprite(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF_BASE(fairygui::FUISprite, "FUISprite", "fgui.FUISprite",
		cocos2d::Sprite, "fgui.cocos2d.Sprite",
		nullptr, nullptr);
	LUA_METHOD("clearContent", lua_fairygui_FUISprite_clearContent);
	LUA_METHOD("getFillAmount", lua_fairygui_FUISprite_getFillAmount);
	LUA_METHOD("getFillMethod", lua_fairygui_FUISprite_getFillMethod);
	LUA_METHOD("getFillOrigin", lua_fairygui_FUISprite_getFillOrigin);
	LUA_METHOD("isFillClockwise", lua_fairygui_FUISprite_isFillClockwise);
	LUA_METHOD("isScaleByTile", lua_fairygui_FUISprite_isScaleByTile);
	LUA_METHOD("setFillAmount", lua_fairygui_FUISprite_setFillAmount);
	LUA_METHOD("setFillClockwise", lua_fairygui_FUISprite_setFillClockwise);
	LUA_METHOD("setFillMethod", lua_fairygui_FUISprite_setFillMethod);
	LUA_METHOD("setFillOrigin", lua_fairygui_FUISprite_setFillOrigin);
	LUA_METHOD("setGrayed", lua_fairygui_FUISprite_setGrayed);
	LUA_METHOD("setScale9Grid", lua_fairygui_FUISprite_setScale9Grid);
	LUA_METHOD("setScaleByTile", lua_fairygui_FUISprite_setScaleByTile);
	LUA_METHOD("create", lua_fairygui_FUISprite_create);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int luaReg_fgui_fguiHtmlElementType(lua_State* lua_S)
{
	LUA_ENUM_DEF("Type");
	LUA_ENUM_ENTRY("TEXT", fairygui::HtmlElement::Type::TEXT);
	LUA_ENUM_ENTRY("IMAGE", fairygui::HtmlElement::Type::IMAGE);
	LUA_ENUM_ENTRY("LINK", fairygui::HtmlElement::Type::LINK);
	LUA_ENUM_ENTRY("INPUT", fairygui::HtmlElement::Type::INPUT);
	LUA_ENUM_ENTRY("SELECT", fairygui::HtmlElement::Type::SELECT);
	LUA_ENUM_ENTRY("OBJECT", fairygui::HtmlElement::Type::OBJECT);
	LUA_ENUM_END();
	return 0;
}
int lua_fairygui_HtmlElement_attrs_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.attrs/getter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_PUSH_NATIVE(cobj->attrs);
	return 1;
}
int lua_fairygui_HtmlElement_attrs_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.attrs/setter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_NATIVE_SETTER(cobj->attrs, 2);
	return 0;
}
int lua_fairygui_HtmlElement_format_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.format/getter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_PUSH_NATIVE(cobj->format);
	return 1;
}
int lua_fairygui_HtmlElement_format_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.format/setter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_NATIVE_SETTER(cobj->format, 2);
	return 0;
}
int lua_fairygui_HtmlElement_link_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.link/getter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_PUSH_NATIVE(cobj->link);
	return 1;
}
int lua_fairygui_HtmlElement_link_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.link/setter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_NATIVE_SETTER(cobj->link, 2);
	return 0;
}
int lua_fairygui_HtmlElement_obj_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.obj/getter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_PUSH_NATIVE(cobj->obj);
	return 1;
}
int lua_fairygui_HtmlElement_obj_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.obj/setter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_NATIVE_SETTER(cobj->obj, 2);
	return 0;
}
int lua_fairygui_HtmlElement_space_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.space/getter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_PUSH_NATIVE(cobj->space);
	return 1;
}
int lua_fairygui_HtmlElement_space_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.space/setter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_NATIVE_SETTER(cobj->space, 2);
	return 0;
}
int lua_fairygui_HtmlElement_text_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.text/getter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_PUSH_NATIVE(cobj->text);
	return 1;
}
int lua_fairygui_HtmlElement_text_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.text/setter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_NATIVE_SETTER(cobj->text, 2);
	return 0;
}
int lua_fairygui_HtmlElement_type_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.type/getter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_PUSH_NATIVE(cobj->type);
	return 1;
}
int lua_fairygui_HtmlElement_type_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlElement.type/setter");
	auto cobj = LUA_TO_COBJ(fairygui::HtmlElement*, 1);
	LUA_NATIVE_SETTER(cobj->type, 2);
	return 0;
}
int lua_fairygui_HtmlElement_getArray(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.HtmlElement", "fgui.HtmlElement:getArray");
	LUA_TRY_INVOKE_R(1, &fairygui::HtmlElement::getArray);
	LUA_INVOKE_FOOTER("1");
}
int lua_fairygui_HtmlElement_getInt(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.HtmlElement", "fgui.HtmlElement:getInt");
	LUA_TRY_INVOKE_R(2, static_cast<int(fairygui::HtmlElement::*)(const std::string&, int)>(&fairygui::HtmlElement::getInt));
	LUA_TRY_INVOKE_R(1, [](fairygui::HtmlElement* obj, const std::string& arg0){{return obj->getInt(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_fairygui_HtmlElement_getString(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.HtmlElement", "fgui.HtmlElement:getString");
	LUA_TRY_INVOKE_R(2, static_cast<std::basic_string<char>(fairygui::HtmlElement::*)(const std::string&, const std::string&)>(&fairygui::HtmlElement::getString));
	LUA_TRY_INVOKE_R(1, [](fairygui::HtmlElement* obj, const std::string& arg0){{return obj->getString(arg0);}});
	LUA_INVOKE_FOOTER("1,2");
}
int luaReg_fgui_fguiHtmlElement(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::HtmlElement, "HtmlElement", "fgui.HtmlElement",
		nullptr, nullptr);
	LUA_FIELD("attrs", lua_fairygui_HtmlElement_attrs_getter, lua_fairygui_HtmlElement_attrs_setter);
	LUA_FIELD("format", lua_fairygui_HtmlElement_format_getter, lua_fairygui_HtmlElement_format_setter);
	LUA_FIELD("link", lua_fairygui_HtmlElement_link_getter, lua_fairygui_HtmlElement_link_setter);
	LUA_FIELD("obj", lua_fairygui_HtmlElement_obj_getter, lua_fairygui_HtmlElement_obj_setter);
	LUA_FIELD("space", lua_fairygui_HtmlElement_space_getter, lua_fairygui_HtmlElement_space_setter);
	LUA_FIELD("text", lua_fairygui_HtmlElement_text_getter, lua_fairygui_HtmlElement_text_setter);
	LUA_FIELD("type", lua_fairygui_HtmlElement_type_getter, lua_fairygui_HtmlElement_type_setter);
	LUA_METHOD("getArray", lua_fairygui_HtmlElement_getArray);
	LUA_METHOD("getInt", lua_fairygui_HtmlElement_getInt);
	LUA_METHOD("getString", lua_fairygui_HtmlElement_getString);
	luaReg_fgui_fguiHtmlElementType(lua_S);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
int lua_fairygui_HtmlObject_buttonResource_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlObject.buttonResource/getter");
	LUA_PUSH_NATIVE(fairygui::HtmlObject::buttonResource);
	return 1;
}
int lua_fairygui_HtmlObject_buttonResource_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlObject.buttonResource/setter");
	LUA_NATIVE_SETTER(fairygui::HtmlObject::buttonResource, 2);
	return 0;
}
int lua_fairygui_HtmlObject_inputResource_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlObject.inputResource/getter");
	LUA_PUSH_NATIVE(fairygui::HtmlObject::inputResource);
	return 1;
}
int lua_fairygui_HtmlObject_inputResource_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlObject.inputResource/setter");
	LUA_NATIVE_SETTER(fairygui::HtmlObject::inputResource, 2);
	return 0;
}
int lua_fairygui_HtmlObject_loaderPool_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlObject.loaderPool/getter");
	LUA_PUSH_NATIVE(fairygui::HtmlObject::loaderPool);
	return 1;
}
int lua_fairygui_HtmlObject_loaderPool_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlObject.loaderPool/setter");
	LUA_NATIVE_SETTER(fairygui::HtmlObject::loaderPool, 2);
	return 0;
}
int lua_fairygui_HtmlObject_selectResource_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlObject.selectResource/getter");
	LUA_PUSH_NATIVE(fairygui::HtmlObject::selectResource);
	return 1;
}
int lua_fairygui_HtmlObject_selectResource_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlObject.selectResource/setter");
	LUA_NATIVE_SETTER(fairygui::HtmlObject::selectResource, 2);
	return 0;
}
int lua_fairygui_HtmlObject_usePool_getter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlObject.usePool/getter");
	LUA_PUSH_NATIVE(fairygui::HtmlObject::usePool);
	return 1;
}
int lua_fairygui_HtmlObject_usePool_setter(lua_State* lua_S)
{
	LUA_CUR_FNAME("fgui.HtmlObject.usePool/setter");
	LUA_NATIVE_SETTER(fairygui::HtmlObject::usePool, 2);
	return 0;
}
int lua_fairygui_HtmlObject_create(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.HtmlObject", "fgui.HtmlObject:create");
	LUA_TRY_INVOKE(2, &fairygui::HtmlObject::create);
	LUA_INVOKE_FOOTER("2");
}
int lua_fairygui_HtmlObject_destroy(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.HtmlObject", "fgui.HtmlObject:destroy");
	LUA_TRY_INVOKE(0, &fairygui::HtmlObject::destroy);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_HtmlObject_getElement(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.HtmlObject", "fgui.HtmlObject:getElement");
	LUA_TRY_INVOKE_R(0, &fairygui::HtmlObject::getElement);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_HtmlObject_getUI(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.HtmlObject", "fgui.HtmlObject:getUI");
	LUA_TRY_INVOKE_R(0, &fairygui::HtmlObject::getUI);
	LUA_INVOKE_FOOTER("0");
}
int lua_fairygui_HtmlObject_isHidden(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("fgui.HtmlObject", "fgui.HtmlObject:isHidden");
	LUA_TRY_INVOKE_R(0, &fairygui::HtmlObject::isHidden);
	LUA_INVOKE_FOOTER("0");
}
int luaReg_fgui_fguiHtmlObject(lua_State* lua_S)
{
	LUA_ENTRY("fgui");
	LUA_CLS_DEF(fairygui::HtmlObject, "HtmlObject", "fgui.HtmlObject",
		nullptr, nullptr);
	LUA_SFIELD("buttonResource", lua_fairygui_HtmlObject_buttonResource_getter, lua_fairygui_HtmlObject_buttonResource_setter);
	LUA_SFIELD("inputResource", lua_fairygui_HtmlObject_inputResource_getter, lua_fairygui_HtmlObject_inputResource_setter);
	LUA_SFIELD("loaderPool", lua_fairygui_HtmlObject_loaderPool_getter, lua_fairygui_HtmlObject_loaderPool_setter);
	LUA_SFIELD("selectResource", lua_fairygui_HtmlObject_selectResource_getter, lua_fairygui_HtmlObject_selectResource_setter);
	LUA_SFIELD("usePool", lua_fairygui_HtmlObject_usePool_getter, lua_fairygui_HtmlObject_usePool_setter);
	LUA_METHOD("create", lua_fairygui_HtmlObject_create);
	LUA_METHOD("destroy", lua_fairygui_HtmlObject_destroy);
	LUA_METHOD("getElement", lua_fairygui_HtmlObject_getElement);
	LUA_METHOD("getUI", lua_fairygui_HtmlObject_getUI);
	LUA_METHOD("isHidden", lua_fairygui_HtmlObject_isHidden);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
