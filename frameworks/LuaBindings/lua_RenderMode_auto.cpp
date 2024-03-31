#include "lua_RenderMode_auto.hpp"
#include "RenderMode.h"

int lua_lstg_RenderMode_clone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:clone");
	LUA_TRY_INVOKE_R(1, &lstg::RenderMode::clone);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_RenderMode_getBlendDescriptor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:getBlendDescriptor");
	LUA_TRY_INVOKE_R(0, &lstg::RenderMode::getBlendDescriptor);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_RenderMode_getBlendFunc(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:getBlendFunc");
	LUA_TRY_INVOKE_R(0, &lstg::RenderMode::getBlendFunc);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_RenderMode_getDefaultProgramState(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:getDefaultProgramState");
	LUA_TRY_INVOKE_R(0, &lstg::RenderMode::getDefaultProgramState);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_RenderMode_getID(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:getID");
	LUA_TRY_INVOKE_R(0, &lstg::RenderMode::getID);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_RenderMode_getName(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:getName");
	LUA_TRY_INVOKE_R(0, &lstg::RenderMode::getName);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_RenderMode_getProgram(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:getProgram");
	LUA_TRY_INVOKE_R(0, &lstg::RenderMode::getProgram);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_RenderMode_getUniformBuffer(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:getUniformBuffer");
	LUA_TRY_INVOKE_R(0, &lstg::RenderMode::getUniformBuffer);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_RenderMode_getUniformNames(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:getUniformNames");
	LUA_TRY_INVOKE_R(0, &lstg::RenderMode::getUniformNames);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_RenderMode_newProgramState(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:newProgramState");
	LUA_TRY_INVOKE_R(0, &lstg::RenderMode::newProgramState);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_RenderMode_setColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:setColor");
	LUA_TRY_INVOKE(2, &lstg::RenderMode::setColor);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_RenderMode_setFloat(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:setFloat");
	LUA_TRY_INVOKE(2, &lstg::RenderMode::setFloat);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_RenderMode_setMat4(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:setMat4");
	LUA_TRY_INVOKE(2, &lstg::RenderMode::setMat4);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_RenderMode_setProgram(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:setProgram");
	LUA_TRY_INVOKE(1, &lstg::RenderMode::setProgram);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_RenderMode_setTexture(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:setTexture");
	LUA_TRY_INVOKE(3, static_cast<void(lstg::RenderMode::*)(const std::string&, cocos2d::Texture2D*, uint32_t)>(&lstg::RenderMode::setTexture));
	LUA_TRY_INVOKE(2, [](lstg::RenderMode* obj, const std::string& arg0,cocos2d::Texture2D* arg1){{return obj->setTexture(arg0,arg1);}});
	LUA_INVOKE_FOOTER("2,3");
}
int lua_lstg_RenderMode_setUniformBuffer(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:setUniformBuffer");
	LUA_TRY_INVOKE(1, &lstg::RenderMode::setUniformBuffer);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_RenderMode_setVec2(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:setVec2");
	LUA_TRY_INVOKE(2, &lstg::RenderMode::setVec2);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_RenderMode_setVec3(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:setVec3");
	LUA_TRY_INVOKE(2, &lstg::RenderMode::setVec3);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_RenderMode_setVec4(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:setVec4");
	LUA_TRY_INVOKE(2, &lstg::RenderMode::setVec4);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_RenderMode_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:create");
	LUA_TRY_INVOKE_R(5, static_cast<lstg::RenderMode*(*)(const std::string&, cocos2d::backend::BlendOperation, cocos2d::backend::BlendFactor, cocos2d::backend::BlendFactor, cocos2d::backend::Program*)>(&lstg::RenderMode::create));
	LUA_TRY_INVOKE_R(2, static_cast<lstg::RenderMode*(*)(const std::string&, cocos2d::backend::Program*)>(&lstg::RenderMode::create));
	LUA_SINVOKE_FOOTER("2,5");
}
int lua_lstg_RenderMode_getByID(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:getByID");
	LUA_TRY_INVOKE_R(1, &lstg::RenderMode::getByID);
	LUA_SINVOKE_FOOTER("1");
}
int lua_lstg_RenderMode_getByName(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:getByName");
	LUA_TRY_INVOKE_R(1, &lstg::RenderMode::getByName);
	LUA_SINVOKE_FOOTER("1");
}
int lua_lstg_RenderMode_getDefault(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:getDefault");
	LUA_TRY_INVOKE_R(0, &lstg::RenderMode::getDefault);
	LUA_SINVOKE_FOOTER("0");
}
int lua_lstg_RenderMode_getIDByName(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:getIDByName");
	LUA_TRY_INVOKE_R(1, &lstg::RenderMode::getIDByName);
	LUA_SINVOKE_FOOTER("1");
}
int lua_lstg_RenderMode_listRenderModes(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.RenderMode", "lstg.RenderMode:listRenderModes");
	LUA_TRY_INVOKE_R(0, &lstg::RenderMode::listRenderModes);
	LUA_SINVOKE_FOOTER("0");
}
int luaReg_RenderMode_lstgRenderMode(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::RenderMode, "RenderMode", "lstg.RenderMode",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("clone", lua_lstg_RenderMode_clone);
	LUA_METHOD("getBlendDescriptor", lua_lstg_RenderMode_getBlendDescriptor);
	LUA_METHOD("getBlendFunc", lua_lstg_RenderMode_getBlendFunc);
	LUA_METHOD("getDefaultProgramState", lua_lstg_RenderMode_getDefaultProgramState);
	LUA_METHOD("getID", lua_lstg_RenderMode_getID);
	LUA_METHOD("getName", lua_lstg_RenderMode_getName);
	LUA_METHOD("getProgram", lua_lstg_RenderMode_getProgram);
	LUA_METHOD("getUniformBuffer", lua_lstg_RenderMode_getUniformBuffer);
	LUA_METHOD("getUniformNames", lua_lstg_RenderMode_getUniformNames);
	LUA_METHOD("newProgramState", lua_lstg_RenderMode_newProgramState);
	LUA_METHOD("setColor", lua_lstg_RenderMode_setColor);
	LUA_METHOD("setFloat", lua_lstg_RenderMode_setFloat);
	LUA_METHOD("setMat4", lua_lstg_RenderMode_setMat4);
	LUA_METHOD("setProgram", lua_lstg_RenderMode_setProgram);
	LUA_METHOD("setTexture", lua_lstg_RenderMode_setTexture);
	LUA_METHOD("setUniformBuffer", lua_lstg_RenderMode_setUniformBuffer);
	LUA_METHOD("setVec2", lua_lstg_RenderMode_setVec2);
	LUA_METHOD("setVec3", lua_lstg_RenderMode_setVec3);
	LUA_METHOD("setVec4", lua_lstg_RenderMode_setVec4);
	LUA_METHOD("create", lua_lstg_RenderMode_create);
	LUA_METHOD("getByID", lua_lstg_RenderMode_getByID);
	LUA_METHOD("getByName", lua_lstg_RenderMode_getByName);
	LUA_METHOD("getDefault", lua_lstg_RenderMode_getDefault);
	LUA_METHOD("getIDByName", lua_lstg_RenderMode_getIDByName);
	LUA_METHOD("listRenderModes", lua_lstg_RenderMode_listRenderModes);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
