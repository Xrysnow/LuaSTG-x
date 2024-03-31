#include "lua_Triangles_auto.hpp"
#include "XTriangles.h"

int lua_lstg_Triangles_clone(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Triangles", "lstg.Triangles:clone");
	LUA_TRY_INVOKE_R(0, &lstg::Triangles::clone);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Triangles_getIndexCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Triangles", "lstg.Triangles:getIndexCount");
	LUA_TRY_INVOKE_R(0, &lstg::Triangles::getIndexCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Triangles_getVertexCount(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Triangles", "lstg.Triangles:getVertexCount");
	LUA_TRY_INVOKE_R(0, &lstg::Triangles::getVertexCount);
	LUA_INVOKE_FOOTER("0");
}
int lua_lstg_Triangles_setAllVertexColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Triangles", "lstg.Triangles:setAllVertexColor");
	LUA_TRY_INVOKE(1, &lstg::Triangles::setAllVertexColor);
	LUA_INVOKE_FOOTER("1");
}
int lua_lstg_Triangles_setIndex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Triangles", "lstg.Triangles:setIndex");
	LUA_TRY_INVOKE(2, &lstg::Triangles::setIndex);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Triangles_setVertex(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Triangles", "lstg.Triangles:setVertex");
	LUA_TRY_INVOKE(7, &lstg::Triangles::setVertex);
	LUA_INVOKE_FOOTER("7");
}
int lua_lstg_Triangles_setVertexColor(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Triangles", "lstg.Triangles:setVertexColor");
	LUA_TRY_INVOKE(2, &lstg::Triangles::setVertexColor);
	LUA_INVOKE_FOOTER("2");
}
int lua_lstg_Triangles_setVertexCoords(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Triangles", "lstg.Triangles:setVertexCoords");
	LUA_TRY_INVOKE(3, &lstg::Triangles::setVertexCoords);
	LUA_INVOKE_FOOTER("3");
}
int lua_lstg_Triangles_setVertexPosition(lua_State* lua_S)
{
	LUA_INVOKE_HEADER("lstg.Triangles", "lstg.Triangles:setVertexPosition");
	LUA_TRY_INVOKE(4, &lstg::Triangles::setVertexPosition);
	LUA_INVOKE_FOOTER("4");
}
int lua_lstg_Triangles_create(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.Triangles", "lstg.Triangles:create");
	LUA_TRY_INVOKE_R(2, &lstg::Triangles::create);
	LUA_SINVOKE_FOOTER("2");
}
int lua_lstg_Triangles_createCircle(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.Triangles", "lstg.Triangles:createCircle");
	LUA_TRY_INVOKE_R(4, static_cast<lstg::Triangles*(*)(size_t, size_t, float, const cocos2d::Rect&)>(&lstg::Triangles::createCircle));
	LUA_TRY_INVOKE_R(3, [](size_t arg0,size_t arg1,float arg2){{return lstg::Triangles::createCircle(std::move(arg0),std::move(arg1),std::move(arg2));}});
	LUA_SINVOKE_FOOTER("3,4");
}
int lua_lstg_Triangles_createGrid(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.Triangles", "lstg.Triangles:createGrid");
	LUA_TRY_INVOKE_R(4, static_cast<lstg::Triangles*(*)(size_t, size_t, const cocos2d::Vec2&, const cocos2d::Rect&)>(&lstg::Triangles::createGrid));
	LUA_TRY_INVOKE_R(3, [](size_t arg0,size_t arg1,const cocos2d::Vec2& arg2){{return lstg::Triangles::createGrid(std::move(arg0),std::move(arg1),arg2);}});
	LUA_SINVOKE_FOOTER("3,4");
}
int lua_lstg_Triangles_createQuad(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.Triangles", "lstg.Triangles:createQuad");
	LUA_TRY_INVOKE_R(2, static_cast<lstg::Triangles*(*)(const cocos2d::Vec2&, const cocos2d::Rect&)>(&lstg::Triangles::createQuad));
	LUA_TRY_INVOKE_R(1, [](const cocos2d::Vec2& arg0){{return lstg::Triangles::createQuad(arg0);}});
	LUA_SINVOKE_FOOTER("1,2");
}
int lua_lstg_Triangles_createSector(lua_State* lua_S)
{
	LUA_SINVOKE_HEADER("lstg.Triangles", "lstg.Triangles:createSector");
	LUA_TRY_INVOKE_R(6, static_cast<lstg::Triangles*(*)(size_t, size_t, float, float, float, const cocos2d::Rect&)>(&lstg::Triangles::createSector));
	LUA_TRY_INVOKE_R(5, [](size_t arg0,size_t arg1,float arg2,float arg3,float arg4){{return lstg::Triangles::createSector(std::move(arg0),std::move(arg1),std::move(arg2),std::move(arg3),std::move(arg4));}});
	LUA_SINVOKE_FOOTER("5,6");
}
int luaReg_Triangles_lstgTriangles(lua_State* lua_S)
{
	LUA_ENTRY("lstg");
	LUA_CLS_DEF_BASE(lstg::Triangles, "Triangles", "lstg.Triangles",
		cocos2d::Ref, "cc.Ref",
		nullptr, nullptr);
	LUA_METHOD("clone", lua_lstg_Triangles_clone);
	LUA_METHOD("getIndexCount", lua_lstg_Triangles_getIndexCount);
	LUA_METHOD("getVertexCount", lua_lstg_Triangles_getVertexCount);
	LUA_METHOD("setAllVertexColor", lua_lstg_Triangles_setAllVertexColor);
	LUA_METHOD("setIndex", lua_lstg_Triangles_setIndex);
	LUA_METHOD("setVertex", lua_lstg_Triangles_setVertex);
	LUA_METHOD("setVertexColor", lua_lstg_Triangles_setVertexColor);
	LUA_METHOD("setVertexCoords", lua_lstg_Triangles_setVertexCoords);
	LUA_METHOD("setVertexPosition", lua_lstg_Triangles_setVertexPosition);
	LUA_METHOD("create", lua_lstg_Triangles_create);
	LUA_METHOD("createCircle", lua_lstg_Triangles_createCircle);
	LUA_METHOD("createGrid", lua_lstg_Triangles_createGrid);
	LUA_METHOD("createQuad", lua_lstg_Triangles_createQuad);
	LUA_METHOD("createSector", lua_lstg_Triangles_createSector);
	LUA_CLS_END();
	LUA_ENTRY_END(1);
	return 0;
}
