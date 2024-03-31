#include "lua_BentLaser_auto.hpp"
#include "Object/GameObjectBentLaser.h"

int luaReg_BentLaser_lstgGameObjectBentLaserColorMode(lua_State* lua_S)
{
	LUA_ENUM_DEF("ColorMode");
	LUA_ENUM_ENTRY("Normal", lstg::GameObjectBentLaser::ColorMode::Normal);
	LUA_ENUM_ENTRY("Node", lstg::GameObjectBentLaser::ColorMode::Node);
	LUA_ENUM_ENTRY("NodeSmooth", lstg::GameObjectBentLaser::ColorMode::NodeSmooth);
	LUA_ENUM_ENTRY("ColorModeNum", lstg::GameObjectBentLaser::ColorMode::ColorModeNum);
	LUA_ENUM_END();
	return 0;
}
int luaReg_BentLaser_lstgGameObjectBentLaserColorMixMode(lua_State* lua_S)
{
	LUA_ENUM_DEF("ColorMixMode");
	LUA_ENUM_ENTRY("None", lstg::GameObjectBentLaser::ColorMixMode::None);
	LUA_ENUM_ENTRY("Multi", lstg::GameObjectBentLaser::ColorMixMode::Multi);
	LUA_ENUM_ENTRY("Add", lstg::GameObjectBentLaser::ColorMixMode::Add);
	LUA_ENUM_ENTRY("ColorMixModeNum", lstg::GameObjectBentLaser::ColorMixMode::ColorMixModeNum);
	LUA_ENUM_END();
	return 0;
}
int lua_lstg_GameObjectBentLaser_boundCheck(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:boundCheck");
	LUA_TRY_INVOKE_R(0, &lstg::GameObjectBentLaser::boundCheck);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_GameObjectBentLaser_clear(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:clear");
	LUA_TRY_INVOKE(0, &lstg::GameObjectBentLaser::clear);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_GameObjectBentLaser_collisionCheck(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:collisionCheck");
	LUA_TRY_INVOKE_R(2, static_cast<bool(lstg::GameObjectBentLaser::*)(float, float)>(&lstg::GameObjectBentLaser::collisionCheck));
	LUA_TRY_INVOKE_R(1, static_cast<bool(lstg::GameObjectBentLaser::*)(lstg::GameObject*)>(&lstg::GameObjectBentLaser::collisionCheck));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_GameObjectBentLaser_collisionCheckExtendWidth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:collisionCheckExtendWidth");
	LUA_TRY_INVOKE_R(3, static_cast<bool(lstg::GameObjectBentLaser::*)(float, float, float)>(&lstg::GameObjectBentLaser::collisionCheckExtendWidth));
	LUA_TRY_INVOKE_R(2, static_cast<bool(lstg::GameObjectBentLaser::*)(lstg::GameObject*, float)>(&lstg::GameObjectBentLaser::collisionCheckExtendWidth));
	LUA_INVOKE_FOOTER("2,3");
}
int lua_lstg_GameObjectBentLaser_getColorMixMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:getColorMixMode");
	LUA_TRY_INVOKE_R(0, &lstg::GameObjectBentLaser::getColorMixMode);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_GameObjectBentLaser_getColorMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:getColorMode");
	LUA_TRY_INVOKE_R(0, &lstg::GameObjectBentLaser::getColorMode);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_GameObjectBentLaser_getDefaultColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:getDefaultColor");
	LUA_TRY_INVOKE_R(0, &lstg::GameObjectBentLaser::getDefaultColor);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_GameObjectBentLaser_getDefaultWidth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:getDefaultWidth");
	LUA_TRY_INVOKE_R(0, &lstg::GameObjectBentLaser::getDefaultWidth);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_GameObjectBentLaser_getLength(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:getLength");
	LUA_TRY_INVOKE_R(0, &lstg::GameObjectBentLaser::getLength);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_GameObjectBentLaser_getLengthLimit(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:getLengthLimit");
	LUA_TRY_INVOKE_R(0, &lstg::GameObjectBentLaser::getLengthLimit);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_GameObjectBentLaser_getNodeColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:getNodeColor");
	LUA_TRY_INVOKE_R(1, &lstg::GameObjectBentLaser::getNodeColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_GameObjectBentLaser_getNodeCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:getNodeCount");
	LUA_TRY_INVOKE_R(0, &lstg::GameObjectBentLaser::getNodeCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_GameObjectBentLaser_getNodeLength(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:getNodeLength");
	LUA_TRY_INVOKE_R(1, &lstg::GameObjectBentLaser::getNodeLength);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_GameObjectBentLaser_getNodeLimit(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:getNodeLimit");
	LUA_TRY_INVOKE_R(0, &lstg::GameObjectBentLaser::getNodeLimit);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_GameObjectBentLaser_getNodePosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:getNodePosition");
	LUA_TRY_INVOKE_R(1, &lstg::GameObjectBentLaser::getNodePosition);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_GameObjectBentLaser_getNodeWidth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:getNodeWidth");
	LUA_TRY_INVOKE_R(1, &lstg::GameObjectBentLaser::getNodeWidth);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_GameObjectBentLaser_getRenderScale(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:getRenderScale");
	LUA_TRY_INVOKE_R(0, &lstg::GameObjectBentLaser::getRenderScale);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_GameObjectBentLaser_popHead(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:popHead");
	LUA_TRY_INVOKE(1, static_cast<void(lstg::GameObjectBentLaser::*)(size_t)>(&lstg::GameObjectBentLaser::popHead));
	LUA_TRY_INVOKE(0, static_cast<void(lstg::GameObjectBentLaser::*)()>(&lstg::GameObjectBentLaser::popHead));
	LUA_INVOKE_FOOTER("0,1");
}
int lua_lstg_GameObjectBentLaser_popTail(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:popTail");
	LUA_TRY_INVOKE(1, static_cast<void(lstg::GameObjectBentLaser::*)(size_t)>(&lstg::GameObjectBentLaser::popTail));
	LUA_TRY_INVOKE(0, static_cast<void(lstg::GameObjectBentLaser::*)()>(&lstg::GameObjectBentLaser::popTail));
	LUA_INVOKE_FOOTER("0,1");
}
int lua_lstg_GameObjectBentLaser_pushHead(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:pushHead");
	LUA_TRY_INVOKE(4, static_cast<void(lstg::GameObjectBentLaser::*)(float, float, float, const cocos2d::Color4B&)>(&lstg::GameObjectBentLaser::pushHead));
	LUA_TRY_INVOKE(3, static_cast<void(lstg::GameObjectBentLaser::*)(float, float, float)>(&lstg::GameObjectBentLaser::pushHead));
	LUA_TRY_INVOKE(2, static_cast<void(lstg::GameObjectBentLaser::*)(float, float)>(&lstg::GameObjectBentLaser::pushHead));
	LUA_INVOKE_FOOTER("2,3,4");
}
int lua_lstg_GameObjectBentLaser_pushTail(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:pushTail");
	LUA_TRY_INVOKE(4, static_cast<void(lstg::GameObjectBentLaser::*)(float, float, float, const cocos2d::Color4B&)>(&lstg::GameObjectBentLaser::pushTail));
	LUA_TRY_INVOKE(3, static_cast<void(lstg::GameObjectBentLaser::*)(float, float, float)>(&lstg::GameObjectBentLaser::pushTail));
	LUA_TRY_INVOKE(2, static_cast<void(lstg::GameObjectBentLaser::*)(float, float)>(&lstg::GameObjectBentLaser::pushTail));
	LUA_INVOKE_FOOTER("2,3,4");
}
int lua_lstg_GameObjectBentLaser_render(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:render");
	LUA_TRY_INVOKE(7, static_cast<void(lstg::GameObjectBentLaser::*)(lstg::ResTexture*, lstg::RenderMode*, const cocos2d::Color4B&, float, float, float, float)>(&lstg::GameObjectBentLaser::render));
	LUA_TRY_INVOKE(1, static_cast<void(lstg::GameObjectBentLaser::*)(lstg::ResSprite*)>(&lstg::GameObjectBentLaser::render));
	LUA_INVOKE_FOOTER("1,7");
}
int lua_lstg_GameObjectBentLaser_reset(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:reset");
	LUA_TRY_INVOKE(0, &lstg::GameObjectBentLaser::reset);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_GameObjectBentLaser_setAllColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:setAllColor");
	LUA_TRY_INVOKE(1, &lstg::GameObjectBentLaser::setAllColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_GameObjectBentLaser_setAllWidth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:setAllWidth");
	LUA_TRY_INVOKE(1, &lstg::GameObjectBentLaser::setAllWidth);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_GameObjectBentLaser_setColorMode(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:setColorMode");
	LUA_TRY_INVOKE(2, static_cast<void(lstg::GameObjectBentLaser::*)(lstg::GameObjectBentLaser::ColorMode, lstg::GameObjectBentLaser::ColorMixMode)>(&lstg::GameObjectBentLaser::setColorMode));
	LUA_TRY_INVOKE(1, [](lstg::GameObjectBentLaser* obj, lstg::GameObjectBentLaser::ColorMode arg0){{return obj->setColorMode(std::move(arg0));}});
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_GameObjectBentLaser_setDefaultColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:setDefaultColor");
	LUA_TRY_INVOKE(1, &lstg::GameObjectBentLaser::setDefaultColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_GameObjectBentLaser_setDefaultWidth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:setDefaultWidth");
	LUA_TRY_INVOKE(1, &lstg::GameObjectBentLaser::setDefaultWidth);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_GameObjectBentLaser_setLengthLimit(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:setLengthLimit");
	LUA_TRY_INVOKE(1, &lstg::GameObjectBentLaser::setLengthLimit);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_GameObjectBentLaser_setNodeColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:setNodeColor");
	LUA_TRY_INVOKE(2, &lstg::GameObjectBentLaser::setNodeColor);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_GameObjectBentLaser_setNodeLimit(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:setNodeLimit");
	LUA_TRY_INVOKE(1, &lstg::GameObjectBentLaser::setNodeLimit);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_GameObjectBentLaser_setNodePosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:setNodePosition");
	LUA_TRY_INVOKE(3, &lstg::GameObjectBentLaser::setNodePosition);
	LUA_INVOKE_FOOTER("3");
}
int lua_lstg_GameObjectBentLaser_setNodeWidth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:setNodeWidth");
	LUA_TRY_INVOKE(2, &lstg::GameObjectBentLaser::setNodeWidth);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_GameObjectBentLaser_setRenderScale(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:setRenderScale");
	LUA_TRY_INVOKE(1, &lstg::GameObjectBentLaser::setRenderScale);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_GameObjectBentLaser_strictCollisionCheck(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:strictCollisionCheck");
	LUA_TRY_INVOKE_R(2, static_cast<bool(lstg::GameObjectBentLaser::*)(float, float)>(&lstg::GameObjectBentLaser::strictCollisionCheck));
	LUA_TRY_INVOKE_R(1, static_cast<bool(lstg::GameObjectBentLaser::*)(lstg::GameObject*)>(&lstg::GameObjectBentLaser::strictCollisionCheck));
	LUA_INVOKE_FOOTER("1,2");
}
int lua_lstg_GameObjectBentLaser_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.GameObjectBentLaser", "lstg.GameObjectBentLaser:create");
	LUA_TRY_INVOKE_R(0, &lstg::GameObjectBentLaser::create);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_BentLaser_lstgGameObjectBentLaser(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::GameObjectBentLaser, "GameObjectBentLaser", "lstg.GameObjectBentLaser",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("boundCheck", lua_lstg_GameObjectBentLaser_boundCheck);
	LUA_METHOD("clear", lua_lstg_GameObjectBentLaser_clear);
	LUA_METHOD("collisionCheck", lua_lstg_GameObjectBentLaser_collisionCheck);
	LUA_METHOD("collisionCheckExtendWidth", lua_lstg_GameObjectBentLaser_collisionCheckExtendWidth);
	LUA_METHOD("getColorMixMode", lua_lstg_GameObjectBentLaser_getColorMixMode);
	LUA_METHOD("getColorMode", lua_lstg_GameObjectBentLaser_getColorMode);
	LUA_METHOD("getDefaultColor", lua_lstg_GameObjectBentLaser_getDefaultColor);
	LUA_METHOD("getDefaultWidth", lua_lstg_GameObjectBentLaser_getDefaultWidth);
	LUA_METHOD("getLength", lua_lstg_GameObjectBentLaser_getLength);
	LUA_METHOD("getLengthLimit", lua_lstg_GameObjectBentLaser_getLengthLimit);
	LUA_METHOD("getNodeColor", lua_lstg_GameObjectBentLaser_getNodeColor);
	LUA_METHOD("getNodeCount", lua_lstg_GameObjectBentLaser_getNodeCount);
	LUA_METHOD("getNodeLength", lua_lstg_GameObjectBentLaser_getNodeLength);
	LUA_METHOD("getNodeLimit", lua_lstg_GameObjectBentLaser_getNodeLimit);
	LUA_METHOD("getNodePosition", lua_lstg_GameObjectBentLaser_getNodePosition);
	LUA_METHOD("getNodeWidth", lua_lstg_GameObjectBentLaser_getNodeWidth);
	LUA_METHOD("getRenderScale", lua_lstg_GameObjectBentLaser_getRenderScale);
	LUA_METHOD("popHead", lua_lstg_GameObjectBentLaser_popHead);
	LUA_METHOD("popTail", lua_lstg_GameObjectBentLaser_popTail);
	LUA_METHOD("pushHead", lua_lstg_GameObjectBentLaser_pushHead);
	LUA_METHOD("pushTail", lua_lstg_GameObjectBentLaser_pushTail);
	LUA_METHOD("render", lua_lstg_GameObjectBentLaser_render);
	LUA_METHOD("reset", lua_lstg_GameObjectBentLaser_reset);
	LUA_METHOD("setAllColor", lua_lstg_GameObjectBentLaser_setAllColor);
	LUA_METHOD("setAllWidth", lua_lstg_GameObjectBentLaser_setAllWidth);
	LUA_METHOD("setColorMode", lua_lstg_GameObjectBentLaser_setColorMode);
	LUA_METHOD("setDefaultColor", lua_lstg_GameObjectBentLaser_setDefaultColor);
	LUA_METHOD("setDefaultWidth", lua_lstg_GameObjectBentLaser_setDefaultWidth);
	LUA_METHOD("setLengthLimit", lua_lstg_GameObjectBentLaser_setLengthLimit);
	LUA_METHOD("setNodeColor", lua_lstg_GameObjectBentLaser_setNodeColor);
	LUA_METHOD("setNodeLimit", lua_lstg_GameObjectBentLaser_setNodeLimit);
	LUA_METHOD("setNodePosition", lua_lstg_GameObjectBentLaser_setNodePosition);
	LUA_METHOD("setNodeWidth", lua_lstg_GameObjectBentLaser_setNodeWidth);
	LUA_METHOD("setRenderScale", lua_lstg_GameObjectBentLaser_setRenderScale);
	LUA_METHOD("strictCollisionCheck", lua_lstg_GameObjectBentLaser_strictCollisionCheck);
	LUA_METHOD("create", lua_lstg_GameObjectBentLaser_create);
	luaReg_BentLaser_lstgGameObjectBentLaserColorMixMode(lua_S);
	luaReg_BentLaser_lstgGameObjectBentLaserColorMode(lua_S);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
