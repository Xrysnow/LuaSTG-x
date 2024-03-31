#include "lua_Latex_auto.hpp"
#include "XLatex.h"

int lua_lstg_Latex_getBaseline(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Latex", "lstg.Latex:getBaseline");
	LUA_TRY_INVOKE_R(0, &lstg::Latex::getBaseline);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Latex_getDepth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Latex", "lstg.Latex:getDepth");
	LUA_TRY_INVOKE_R(0, &lstg::Latex::getDepth);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Latex_getHeight(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Latex", "lstg.Latex:getHeight");
	LUA_TRY_INVOKE_R(0, &lstg::Latex::getHeight);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Latex_getInsets(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Latex", "lstg.Latex:getInsets");
	LUA_TRY_INVOKE_R(0, &lstg::Latex::getInsets);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Latex_getTextSize(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Latex", "lstg.Latex:getTextSize");
	LUA_TRY_INVOKE_R(0, &lstg::Latex::getTextSize);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Latex_getWidth(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Latex", "lstg.Latex:getWidth");
	LUA_TRY_INVOKE_R(0, &lstg::Latex::getWidth);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Latex_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.Latex", "lstg.Latex:create");
	LUA_TRY_INVOKE_R(5, static_cast<lstg::Latex*(*)(const std::string&, int, float, float, const cocos2d::Color4B&)>(&lstg::Latex::create));
	LUA_TRY_INVOKE_R(4, [](const std::string& arg0,int arg1,float arg2,float arg3){{return lstg::Latex::create(arg0,std::move(arg1),std::move(arg2),std::move(arg3));}});
	LUA_SINVOKE_FOOTER("4,5");
}
int lua_lstg_Latex_setDebug(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.Latex", "lstg.Latex:setDebug");
	LUA_TRY_INVOKE(1, &lstg::Latex::setDebug);
	LUA_SINVOKE_FOOTER("1");
}
int luaReg_Latex_lstgLatex(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::Latex, "Latex", "lstg.Latex",
		cocos2d::Node, "cc.Node",
		nullptr, nullptr);
	LUA_METHOD("getBaseline", lua_lstg_Latex_getBaseline);
	LUA_METHOD("getDepth", lua_lstg_Latex_getDepth);
	LUA_METHOD("getHeight", lua_lstg_Latex_getHeight);
	LUA_METHOD("getInsets", lua_lstg_Latex_getInsets);
	LUA_METHOD("getTextSize", lua_lstg_Latex_getTextSize);
	LUA_METHOD("getWidth", lua_lstg_Latex_getWidth);
	LUA_METHOD("create", lua_lstg_Latex_create);
	LUA_METHOD("setDebug", lua_lstg_Latex_setDebug);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
