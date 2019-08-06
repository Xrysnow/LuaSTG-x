#include "lua_Resource_auto.hpp"
#include "../LSTG/GameResources.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "UtilLuaConversion.h"
#define printf(...)
#define color4b_to_luaval lstg::lua::_color4b_to_luaval
#define luaval_to_color4b lstg::lua::_luaval_to_color4b
using lstg::lua::luaval_to_BlendMode;
using lstg::lua::BlendMode_to_luaval;
using lstg::lua::luaval_to_V3F_C4B_T2F_Quad;
using lstg::lua::V3F_C4B_T2F_Quad_to_luaval;

int lua_x_Resource_Resource_getInfo(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_Resource_getInfo'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_Resource_getInfo'", nullptr);
            return 0;
        }
        std::string ret = cobj->getInfo();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Resource:getInfo",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_Resource_getInfo'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_Resource_getName(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_Resource_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_Resource_getName'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getName();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Resource:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_Resource_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_Resource_getType(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_Resource_getType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_Resource_getType'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Resource:getType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_Resource_getType'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_Resource_getPath(lua_State* tolua_S)
{
    int argc = 0;
    lstg::Resource* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.Resource",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::Resource*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_Resource_getPath'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_Resource_getPath'", nullptr);
            return 0;
        }
        const std::string& ret = cobj->getPath();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.Resource:getPath",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_Resource_getPath'.",&tolua_err);
#endif

    return 0;
}
static int lua_x_Resource_Resource_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Resource)");
    return 0;
}

int lua_register_x_Resource_Resource(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.Resource");
    tolua_cclass(tolua_S,"Resource","lstg.Resource","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"Resource");
        tolua_function(tolua_S,"getInfo",lua_x_Resource_Resource_getInfo);
        tolua_function(tolua_S,"getName",lua_x_Resource_Resource_getName);
        tolua_function(tolua_S,"getType",lua_x_Resource_Resource_getType);
        tolua_function(tolua_S,"getPath",lua_x_Resource_Resource_getPath);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::Resource).name();
    g_luaType[typeName] = "lstg.Resource";
    g_typeCast["Resource"] = "lstg.Resource";
    return 1;
}

int lua_x_Resource_ResourceColliable_getHalfSizeX(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceColliable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceColliable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceColliable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResourceColliable_getHalfSizeX'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResourceColliable_getHalfSizeX'", nullptr);
            return 0;
        }
        double ret = cobj->getHalfSizeX();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceColliable:getHalfSizeX",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResourceColliable_getHalfSizeX'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResourceColliable_getHalfSizeY(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceColliable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceColliable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceColliable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResourceColliable_getHalfSizeY'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResourceColliable_getHalfSizeY'", nullptr);
            return 0;
        }
        double ret = cobj->getHalfSizeY();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceColliable:getHalfSizeY",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResourceColliable_getHalfSizeY'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResourceColliable_getColliderType(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceColliable* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceColliable",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceColliable*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResourceColliable_getColliderType'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResourceColliable_getColliderType'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getColliderType();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceColliable:getColliderType",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResourceColliable_getColliderType'.",&tolua_err);
#endif

    return 0;
}
static int lua_x_Resource_ResourceColliable_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResourceColliable)");
    return 0;
}

int lua_register_x_Resource_ResourceColliable(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResourceColliable");
    tolua_cclass(tolua_S,"ResourceColliable","lstg.ResourceColliable","lstg.Resource",nullptr);

    tolua_beginmodule(tolua_S,"ResourceColliable");
        tolua_function(tolua_S,"getHalfSizeX",lua_x_Resource_ResourceColliable_getHalfSizeX);
        tolua_function(tolua_S,"getHalfSizeY",lua_x_Resource_ResourceColliable_getHalfSizeY);
        tolua_function(tolua_S,"getColliderType",lua_x_Resource_ResourceColliable_getColliderType);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResourceColliable).name();
    g_luaType[typeName] = "lstg.ResourceColliable";
    g_typeCast["ResourceColliable"] = "lstg.ResourceColliable";
    return 1;
}

int lua_x_Resource_ResourceQuad_setVertex(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceQuad* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceQuad",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResourceQuad_setVertex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::V3F_C4B_T2F_Quad arg0;

        ok &= luaval_to_V3F_C4B_T2F_Quad(tolua_S, 2, &arg0, "lstg.ResourceQuad:setVertex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResourceQuad_setVertex'", nullptr);
            return 0;
        }
        cobj->setVertex(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceQuad:setVertex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResourceQuad_setVertex'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResourceQuad_setColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceQuad* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceQuad",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResourceQuad_setColor'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            cocos2d::Color4B arg0;
            ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.ResourceQuad:setColor");

            if (!ok) { break; }
            int arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.ResourceQuad:setColor");

            if (!ok) { break; }
            cobj->setColor(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::Color4B arg0;
            ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.ResourceQuad:setColor");

            if (!ok) { break; }
            cobj->setColor(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.ResourceQuad:setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResourceQuad_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResourceQuad_getColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceQuad* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceQuad",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResourceQuad_getColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResourceQuad_getColor'", nullptr);
            return 0;
        }
        cocos2d::Color4B ret = cobj->getColor();
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.ResourceQuad:getColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResourceQuad_getColor'", nullptr);
            return 0;
        }
        cocos2d::Color4B ret = cobj->getColor(arg0);
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceQuad:getColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResourceQuad_getColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResourceQuad_setBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceQuad* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceQuad",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResourceQuad_setBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::BlendMode* arg0;

        ok &= luaval_to_BlendMode(tolua_S, 2, &arg0, "lstg.ResourceQuad:setBlendMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResourceQuad_setBlendMode'", nullptr);
            return 0;
        }
        cobj->setBlendMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceQuad:setBlendMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResourceQuad_setBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResourceQuad_getBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceQuad* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceQuad",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResourceQuad_getBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResourceQuad_getBlendMode'", nullptr);
            return 0;
        }
        lstg::BlendMode* ret = cobj->getBlendMode();
        BlendMode_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceQuad:getBlendMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResourceQuad_getBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResourceQuad_getVertex(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceQuad* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceQuad",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResourceQuad_getVertex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResourceQuad_getVertex'", nullptr);
            return 0;
        }
        cocos2d::V3F_C4B_T2F_Quad& ret = cobj->getVertex();
        V3F_C4B_T2F_Quad_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceQuad:getVertex",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResourceQuad_getVertex'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResourceQuad_setAlpha(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResourceQuad* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResourceQuad",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResourceQuad*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResourceQuad_setAlpha'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        uint16_t arg0;

        ok &= luaval_to_uint16(tolua_S, 2,&arg0, "lstg.ResourceQuad:setAlpha");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResourceQuad_setAlpha'", nullptr);
            return 0;
        }
        cobj->setAlpha(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResourceQuad:setAlpha",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResourceQuad_setAlpha'.",&tolua_err);
#endif

    return 0;
}
static int lua_x_Resource_ResourceQuad_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResourceQuad)");
    return 0;
}

int lua_register_x_Resource_ResourceQuad(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResourceQuad");
    tolua_cclass(tolua_S,"ResourceQuad","lstg.ResourceQuad","lstg.ResourceColliable",nullptr);

    tolua_beginmodule(tolua_S,"ResourceQuad");
        tolua_function(tolua_S,"setVertex",lua_x_Resource_ResourceQuad_setVertex);
        tolua_function(tolua_S,"setColor",lua_x_Resource_ResourceQuad_setColor);
        tolua_function(tolua_S,"getColor",lua_x_Resource_ResourceQuad_getColor);
        tolua_function(tolua_S,"setBlendMode",lua_x_Resource_ResourceQuad_setBlendMode);
        tolua_function(tolua_S,"getBlendMode",lua_x_Resource_ResourceQuad_getBlendMode);
        tolua_function(tolua_S,"getVertex",lua_x_Resource_ResourceQuad_getVertex);
        tolua_function(tolua_S,"setAlpha",lua_x_Resource_ResourceQuad_setAlpha);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResourceQuad).name();
    g_luaType[typeName] = "lstg.ResourceQuad";
    g_typeCast["ResourceQuad"] = "lstg.ResourceQuad";
    return 1;
}

int lua_x_Resource_ResTexture_getTriangles(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResTexture* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResTexture",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResTexture*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResTexture_getTriangles'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResTexture_getTriangles'", nullptr);
            return 0;
        }
        lstg::Triangles* ret = cobj->getTriangles();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResTexture:getTriangles",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResTexture_getTriangles'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResTexture_setTriangles(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResTexture* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResTexture",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResTexture*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResTexture_setTriangles'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::Triangles* arg0;

        ok &= lstg::lua::luaval_to_native(tolua_S, 2, &arg0, "lstg.ResTexture:setTriangles");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResTexture_setTriangles'", nullptr);
            return 0;
        }
        cobj->setTriangles(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResTexture:setTriangles",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResTexture_setTriangles'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResTexture_render(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResTexture* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResTexture",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ResTexture*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResTexture_render'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 2) {
            lstg::BlendMode* arg0;
            ok &= luaval_to_BlendMode(tolua_S, 2, &arg0, "lstg.ResTexture:render");

            if (!ok) { break; }
            cocos2d::V3F_C4B_T2F_Quad arg1;
            ok &= luaval_to_V3F_C4B_T2F_Quad(tolua_S, 3, &arg1, "lstg.ResTexture:render");

            if (!ok) { break; }
            bool ret = cobj->render(arg0, arg1);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 1) {
            cocos2d::V3F_C4B_T2F_Quad arg0;
            ok &= luaval_to_V3F_C4B_T2F_Quad(tolua_S, 2, &arg0, "lstg.ResTexture:render");

            if (!ok) { break; }
            bool ret = cobj->render(arg0);
            tolua_pushboolean(tolua_S,(bool)ret);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.ResTexture:render",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResTexture_render'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResTexture_getTexture(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResTexture* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResTexture",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResTexture*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResTexture_getTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResTexture_getTexture'", nullptr);
            return 0;
        }
        cocos2d::Texture2D* ret = cobj->getTexture();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResTexture:getTexture",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResTexture_getTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResTexture_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResTexture",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResTexture:create");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ResTexture:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResTexture_create'", nullptr);
            return 0;
        }
        lstg::ResTexture* ret = lstg::ResTexture::create(arg0, arg1);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResTexture:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResTexture_create'.",&tolua_err);
#endif
    return 0;
}
int lua_x_Resource_ResTexture_createWithTexture(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResTexture",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        cocos2d::Texture2D* arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResTexture:createWithTexture");
        ok &= lstg::lua::luaval_to_native(tolua_S, 3, &arg1, "lstg.ResTexture:createWithTexture");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResTexture_createWithTexture'", nullptr);
            return 0;
        }
        lstg::ResTexture* ret = lstg::ResTexture::createWithTexture(arg0, arg1);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResTexture:createWithTexture",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResTexture_createWithTexture'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Resource_ResTexture_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResTexture)");
    return 0;
}

int lua_register_x_Resource_ResTexture(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResTexture");
    tolua_cclass(tolua_S,"ResTexture","lstg.ResTexture","lstg.Resource",nullptr);

    tolua_beginmodule(tolua_S,"ResTexture");
        tolua_function(tolua_S,"getTriangles",lua_x_Resource_ResTexture_getTriangles);
        tolua_function(tolua_S,"setTriangles",lua_x_Resource_ResTexture_setTriangles);
        tolua_function(tolua_S,"render",lua_x_Resource_ResTexture_render);
        tolua_function(tolua_S,"getTexture",lua_x_Resource_ResTexture_getTexture);
        tolua_function(tolua_S,"create", lua_x_Resource_ResTexture_create);
        tolua_function(tolua_S,"createWithTexture", lua_x_Resource_ResTexture_createWithTexture);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResTexture).name();
    g_luaType[typeName] = "lstg.ResTexture";
    g_typeCast["ResTexture"] = "lstg.ResTexture";
    return 1;
}

int lua_x_Resource_ResAnimation_setVertex(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAnimation_setVertex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        cocos2d::V3F_C4B_T2F_Quad arg0;
        unsigned int arg1;

        ok &= luaval_to_V3F_C4B_T2F_Quad(tolua_S, 2, &arg0, "lstg.ResAnimation:setVertex");

        ok &= luaval_to_uint32(tolua_S, 3,&arg1, "lstg.ResAnimation:setVertex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAnimation_setVertex'", nullptr);
            return 0;
        }
        cobj->setVertex(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAnimation:setVertex",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAnimation_setVertex'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAnimation_getInterval(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAnimation_getInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAnimation_getInterval'", nullptr);
            return 0;
        }
        double ret = cobj->getInterval();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAnimation:getInterval",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAnimation_getInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAnimation_render(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAnimation_render'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 3) 
    {
        int arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResAnimation:render");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAnimation_render'", nullptr);
            return 0;
        }
        bool ret = cobj->render(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 4) 
    {
        int arg0;
        double arg1;
        double arg2;
        double arg3;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.ResAnimation:render");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAnimation_render'", nullptr);
            return 0;
        }
        bool ret = cobj->render(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 5) 
    {
        int arg0;
        double arg1;
        double arg2;
        double arg3;
        double arg4;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "lstg.ResAnimation:render");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAnimation_render'", nullptr);
            return 0;
        }
        bool ret = cobj->render(arg0, arg1, arg2, arg3, arg4);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 6) 
    {
        int arg0;
        double arg1;
        double arg2;
        double arg3;
        double arg4;
        double arg5;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "lstg.ResAnimation:render");

        ok &= luaval_to_number(tolua_S, 7,&arg5, "lstg.ResAnimation:render");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAnimation_render'", nullptr);
            return 0;
        }
        bool ret = cobj->render(arg0, arg1, arg2, arg3, arg4, arg5);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAnimation:render",argc, 3);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAnimation_render'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAnimation_setInterval(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAnimation_setInterval'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        double arg0;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResAnimation:setInterval");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAnimation_setInterval'", nullptr);
            return 0;
        }
        cobj->setInterval(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAnimation:setInterval",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAnimation_setInterval'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAnimation_getSprite(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAnimation_getSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.ResAnimation:getSprite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAnimation_getSprite'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->getSprite(arg0);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAnimation:getSprite",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAnimation_getSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAnimation_getVertex(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAnimation_getVertex'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        unsigned int arg0;

        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.ResAnimation:getVertex");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAnimation_getVertex'", nullptr);
            return 0;
        }
        cocos2d::V3F_C4B_T2F_Quad& ret = cobj->getVertex(arg0);
        V3F_C4B_T2F_Quad_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAnimation:getVertex",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAnimation_getVertex'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAnimation_getCount(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAnimation* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAnimation*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAnimation_getCount'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAnimation_getCount'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getCount();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAnimation:getCount",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAnimation_getCount'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAnimation_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResAnimation",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 12)
    {
        std::string arg0;
        lstg::ResTexture* arg1;
        double arg2;
        double arg3;
        double arg4;
        double arg5;
        int arg6;
        int arg7;
        int arg8;
        double arg9;
        double arg10;
        xmath::collision::ColliderType arg11;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResAnimation:create");
        ok &= lstg::lua::luaval_to_native(tolua_S, 3, &arg1, "lstg.ResAnimation:create");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResAnimation:create");
        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.ResAnimation:create");
        ok &= luaval_to_number(tolua_S, 6,&arg4, "lstg.ResAnimation:create");
        ok &= luaval_to_number(tolua_S, 7,&arg5, "lstg.ResAnimation:create");
        ok &= luaval_to_int32(tolua_S, 8,(int *)&arg6, "lstg.ResAnimation:create");
        ok &= luaval_to_int32(tolua_S, 9,(int *)&arg7, "lstg.ResAnimation:create");
        ok &= luaval_to_int32(tolua_S, 10,(int *)&arg8, "lstg.ResAnimation:create");
        ok &= luaval_to_number(tolua_S, 11,&arg9, "lstg.ResAnimation:create");
        ok &= luaval_to_number(tolua_S, 12,&arg10, "lstg.ResAnimation:create");
        ok &= luaval_to_int32(tolua_S, 13,(int *)&arg11, "lstg.ResAnimation:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAnimation_create'", nullptr);
            return 0;
        }
        lstg::ResAnimation* ret = lstg::ResAnimation::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResAnimation:create",argc, 12);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAnimation_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Resource_ResAnimation_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResAnimation)");
    return 0;
}

int lua_register_x_Resource_ResAnimation(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResAnimation");
    tolua_cclass(tolua_S,"ResAnimation","lstg.ResAnimation","lstg.ResourceQuad",nullptr);

    tolua_beginmodule(tolua_S,"ResAnimation");
        tolua_function(tolua_S,"setVertex",lua_x_Resource_ResAnimation_setVertex);
        tolua_function(tolua_S,"getInterval",lua_x_Resource_ResAnimation_getInterval);
        tolua_function(tolua_S,"render",lua_x_Resource_ResAnimation_render);
        tolua_function(tolua_S,"setInterval",lua_x_Resource_ResAnimation_setInterval);
        tolua_function(tolua_S,"getSprite",lua_x_Resource_ResAnimation_getSprite);
        tolua_function(tolua_S,"getVertex",lua_x_Resource_ResAnimation_getVertex);
        tolua_function(tolua_S,"getCount",lua_x_Resource_ResAnimation_getCount);
        tolua_function(tolua_S,"create", lua_x_Resource_ResAnimation_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResAnimation).name();
    g_luaType[typeName] = "lstg.ResAnimation";
    g_typeCast["ResAnimation"] = "lstg.ResAnimation";
    return 1;
}

int lua_x_Resource_ResSprite_render4v(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResSprite_render4v'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 12) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;
        double arg4;
        double arg5;
        double arg6;
        double arg7;
        double arg8;
        double arg9;
        double arg10;
        double arg11;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResSprite:render4v");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.ResSprite:render4v");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResSprite:render4v");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.ResSprite:render4v");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "lstg.ResSprite:render4v");

        ok &= luaval_to_number(tolua_S, 7,&arg5, "lstg.ResSprite:render4v");

        ok &= luaval_to_number(tolua_S, 8,&arg6, "lstg.ResSprite:render4v");

        ok &= luaval_to_number(tolua_S, 9,&arg7, "lstg.ResSprite:render4v");

        ok &= luaval_to_number(tolua_S, 10,&arg8, "lstg.ResSprite:render4v");

        ok &= luaval_to_number(tolua_S, 11,&arg9, "lstg.ResSprite:render4v");

        ok &= luaval_to_number(tolua_S, 12,&arg10, "lstg.ResSprite:render4v");

        ok &= luaval_to_number(tolua_S, 13,&arg11, "lstg.ResSprite:render4v");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_render4v'", nullptr);
            return 0;
        }
        bool ret = cobj->render4v(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResSprite:render4v",argc, 12);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResSprite_render4v'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResSprite_render(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResSprite_render'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        double arg0;
        double arg1;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.ResSprite:render");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_render'", nullptr);
            return 0;
        }
        bool ret = cobj->render(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 3) 
    {
        double arg0;
        double arg1;
        double arg2;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResSprite:render");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_render'", nullptr);
            return 0;
        }
        bool ret = cobj->render(arg0, arg1, arg2);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 4) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.ResSprite:render");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_render'", nullptr);
            return 0;
        }
        bool ret = cobj->render(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 5) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;
        double arg4;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "lstg.ResSprite:render");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_render'", nullptr);
            return 0;
        }
        bool ret = cobj->render(arg0, arg1, arg2, arg3, arg4);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    if (argc == 6) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;
        double arg4;
        double arg5;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 6,&arg4, "lstg.ResSprite:render");

        ok &= luaval_to_number(tolua_S, 7,&arg5, "lstg.ResSprite:render");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_render'", nullptr);
            return 0;
        }
        bool ret = cobj->render(arg0, arg1, arg2, arg3, arg4, arg5);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResSprite:render",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResSprite_render'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResSprite_getTexture(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResSprite_getTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_getTexture'", nullptr);
            return 0;
        }
        cocos2d::Texture2D* ret = cobj->getTexture();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResSprite:getTexture",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResSprite_getTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResSprite_getNormalMap(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResSprite_getNormalMap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_getNormalMap'", nullptr);
            return 0;
        }
        cocos2d::Texture2D* ret = cobj->getNormalMap();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResSprite:getNormalMap",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResSprite_getNormalMap'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResSprite_clone(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResSprite_clone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResSprite:clone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_clone'", nullptr);
            return 0;
        }
        lstg::ResSprite* ret = cobj->clone(arg0);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResSprite:clone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResSprite_clone'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResSprite_getSprite(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResSprite_getSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_getSprite'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->getSprite();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResSprite:getSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResSprite_getSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResSprite_renderRect(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResSprite_renderRect'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 4) 
    {
        double arg0;
        double arg1;
        double arg2;
        double arg3;

        ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResSprite:renderRect");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.ResSprite:renderRect");

        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResSprite:renderRect");

        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.ResSprite:renderRect");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_renderRect'", nullptr);
            return 0;
        }
        bool ret = cobj->renderRect(arg0, arg1, arg2, arg3);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResSprite:renderRect",argc, 4);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResSprite_renderRect'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResSprite_setNormalMap(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResSprite* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResSprite*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResSprite_setNormalMap'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Texture2D* arg0;

        ok &= lstg::lua::luaval_to_native(tolua_S, 2, &arg0, "lstg.ResSprite:setNormalMap");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_setNormalMap'", nullptr);
            return 0;
        }
        cobj->setNormalMap(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResSprite:setNormalMap",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResSprite_setNormalMap'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResSprite_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 9)
    {
        std::string arg0;
        lstg::ResTexture* arg1;
        double arg2;
        double arg3;
        double arg4;
        double arg5;
        double arg6;
        double arg7;
        xmath::collision::ColliderType arg8;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResSprite:create");
        ok &= lstg::lua::luaval_to_native(tolua_S, 3, &arg1, "lstg.ResSprite:create");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResSprite:create");
        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.ResSprite:create");
        ok &= luaval_to_number(tolua_S, 6,&arg4, "lstg.ResSprite:create");
        ok &= luaval_to_number(tolua_S, 7,&arg5, "lstg.ResSprite:create");
        ok &= luaval_to_number(tolua_S, 8,&arg6, "lstg.ResSprite:create");
        ok &= luaval_to_number(tolua_S, 9,&arg7, "lstg.ResSprite:create");
        ok &= luaval_to_int32(tolua_S, 10,(int *)&arg8, "lstg.ResSprite:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_create'", nullptr);
            return 0;
        }
        lstg::ResSprite* ret = lstg::ResSprite::create(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResSprite:create",argc, 9);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResSprite_create'.",&tolua_err);
#endif
    return 0;
}
int lua_x_Resource_ResSprite_createWithSprite(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResSprite",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 5)
    {
        std::string arg0;
        cocos2d::Sprite* arg1;
        double arg2;
        double arg3;
        xmath::collision::ColliderType arg4;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResSprite:createWithSprite");
        ok &= lstg::lua::luaval_to_native(tolua_S, 3, &arg1, "lstg.ResSprite:createWithSprite");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResSprite:createWithSprite");
        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.ResSprite:createWithSprite");
        ok &= luaval_to_int32(tolua_S, 6,(int *)&arg4, "lstg.ResSprite:createWithSprite");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSprite_createWithSprite'", nullptr);
            return 0;
        }
        lstg::ResSprite* ret = lstg::ResSprite::createWithSprite(arg0, arg1, arg2, arg3, arg4);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResSprite:createWithSprite",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResSprite_createWithSprite'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Resource_ResSprite_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResSprite)");
    return 0;
}

int lua_register_x_Resource_ResSprite(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResSprite");
    tolua_cclass(tolua_S,"ResSprite","lstg.ResSprite","lstg.ResourceQuad",nullptr);

    tolua_beginmodule(tolua_S,"ResSprite");
        tolua_function(tolua_S,"render4v",lua_x_Resource_ResSprite_render4v);
        tolua_function(tolua_S,"render",lua_x_Resource_ResSprite_render);
        tolua_function(tolua_S,"getTexture",lua_x_Resource_ResSprite_getTexture);
        tolua_function(tolua_S,"getNormalMap",lua_x_Resource_ResSprite_getNormalMap);
        tolua_function(tolua_S,"clone",lua_x_Resource_ResSprite_clone);
        tolua_function(tolua_S,"getSprite",lua_x_Resource_ResSprite_getSprite);
        tolua_function(tolua_S,"renderRect",lua_x_Resource_ResSprite_renderRect);
        tolua_function(tolua_S,"setNormalMap",lua_x_Resource_ResSprite_setNormalMap);
        tolua_function(tolua_S,"create", lua_x_Resource_ResSprite_create);
        tolua_function(tolua_S,"createWithSprite", lua_x_Resource_ResSprite_createWithSprite);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResSprite).name();
    g_luaType[typeName] = "lstg.ResSprite";
    g_typeCast["ResSprite"] = "lstg.ResSprite";
    return 1;
}

int lua_x_Resource_ResParticle_getBindSprite(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResParticle_getBindSprite'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResParticle_getBindSprite'", nullptr);
            return 0;
        }
        cocos2d::Sprite* ret = cobj->getBindSprite();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle:getBindSprite",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResParticle_getBindSprite'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResParticle_getBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResParticle* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResParticle",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResParticle*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResParticle_getBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResParticle_getBlendMode'", nullptr);
            return 0;
        }
        lstg::BlendMode* ret = cobj->getBlendMode();
        BlendMode_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResParticle:getBlendMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResParticle_getBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResParticle_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResParticle",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 6)
    {
        std::string arg0;
        std::string arg1;
        lstg::ResSprite* arg2;
        double arg3;
        double arg4;
        xmath::collision::ColliderType arg5;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResParticle:create");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ResParticle:create");
        ok &= lstg::lua::luaval_to_native(tolua_S, 4, &arg2, "lstg.ResParticle:create");
        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.ResParticle:create");
        ok &= luaval_to_number(tolua_S, 6,&arg4, "lstg.ResParticle:create");
        ok &= luaval_to_int32(tolua_S, 7,(int *)&arg5, "lstg.ResParticle:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResParticle_create'", nullptr);
            return 0;
        }
        lstg::ResParticle* ret = lstg::ResParticle::create(arg0, arg1, arg2, arg3, arg4, arg5);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResParticle:create",argc, 6);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResParticle_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Resource_ResParticle_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResParticle)");
    return 0;
}

int lua_register_x_Resource_ResParticle(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResParticle");
    tolua_cclass(tolua_S,"ResParticle","lstg.ResParticle","lstg.ResourceColliable",nullptr);

    tolua_beginmodule(tolua_S,"ResParticle");
        tolua_function(tolua_S,"getBindSprite",lua_x_Resource_ResParticle_getBindSprite);
        tolua_function(tolua_S,"getBlendMode",lua_x_Resource_ResParticle_getBlendMode);
        tolua_function(tolua_S,"create", lua_x_Resource_ResParticle_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResParticle).name();
    g_luaType[typeName] = "lstg.ResParticle";
    g_typeCast["ResParticle"] = "lstg.ResParticle";
    return 1;
}

int lua_x_Resource_ResFont_disableOutline(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_disableOutline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_disableOutline'", nullptr);
            return 0;
        }
        cobj->disableOutline();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:disableOutline",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_disableOutline'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_enableShadow(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_enableShadow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_enableShadow'", nullptr);
            return 0;
        }
        cobj->enableShadow();
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.ResFont:enableShadow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_enableShadow'", nullptr);
            return 0;
        }
        cobj->enableShadow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        cocos2d::Color4B arg0;
        cocos2d::Size arg1;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.ResFont:enableShadow");

        ok &= luaval_to_size(tolua_S, 3, &arg1, "lstg.ResFont:enableShadow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_enableShadow'", nullptr);
            return 0;
        }
        cobj->enableShadow(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 3) 
    {
        cocos2d::Color4B arg0;
        cocos2d::Size arg1;
        int arg2;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.ResFont:enableShadow");

        ok &= luaval_to_size(tolua_S, 3, &arg1, "lstg.ResFont:enableShadow");

        ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "lstg.ResFont:enableShadow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_enableShadow'", nullptr);
            return 0;
        }
        cobj->enableShadow(arg0, arg1, arg2);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:enableShadow",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_enableShadow'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_isBold(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_isBold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_isBold'", nullptr);
            return 0;
        }
        bool ret = cobj->isBold();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:isBold",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_isBold'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_setTTFConfig(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_setTTFConfig'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::_ttfConfig arg0;

        ok &= luaval_to_ttfconfig(tolua_S, 2, &arg0, "lstg.ResFont:setTTFConfig");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_setTTFConfig'", nullptr);
            return 0;
        }
        cobj->setTTFConfig(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:setTTFConfig",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_setTTFConfig'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_disableGlow(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_disableGlow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_disableGlow'", nullptr);
            return 0;
        }
        cobj->disableGlow();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:disableGlow",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_disableGlow'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_getHAlign(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_getHAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_getHAlign'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getHAlign();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:getHAlign",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_getHAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_isItalics(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_isItalics'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_isItalics'", nullptr);
            return 0;
        }
        bool ret = cobj->isItalics();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:isItalics",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_isItalics'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_getShadowOffset(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_getShadowOffset'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_getShadowOffset'", nullptr);
            return 0;
        }
        cocos2d::Size ret = cobj->getShadowOffset();
        size_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:getShadowOffset",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_getShadowOffset'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_isGlowed(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_isGlowed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_isGlowed'", nullptr);
            return 0;
        }
        bool ret = cobj->isGlowed();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:isGlowed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_isGlowed'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_getTTFConfig(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_getTTFConfig'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_getTTFConfig'", nullptr);
            return 0;
        }
        cocos2d::_ttfConfig& ret = cobj->getTTFConfig();
        ttfconfig_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:getTTFConfig",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_getTTFConfig'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_getGlowColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_getGlowColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_getGlowColor'", nullptr);
            return 0;
        }
        cocos2d::Color4B ret = cobj->getGlowColor();
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:getGlowColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_getGlowColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_getOutlineSize(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_getOutlineSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_getOutlineSize'", nullptr);
            return 0;
        }
        int ret = cobj->getOutlineSize();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:getOutlineSize",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_getOutlineSize'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_getOutlineColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_getOutlineColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_getOutlineColor'", nullptr);
            return 0;
        }
        cocos2d::Color4B ret = cobj->getOutlineColor();
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:getOutlineColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_getOutlineColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_disableItalics(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_disableItalics'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_disableItalics'", nullptr);
            return 0;
        }
        cobj->disableItalics();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:disableItalics",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_disableItalics'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_getShadowBlurRadius(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_getShadowBlurRadius'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_getShadowBlurRadius'", nullptr);
            return 0;
        }
        int ret = cobj->getShadowBlurRadius();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:getShadowBlurRadius",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_getShadowBlurRadius'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_enableUnderline(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_enableUnderline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_enableUnderline'", nullptr);
            return 0;
        }
        cobj->enableUnderline();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:enableUnderline",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_enableUnderline'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_enableStrikethrough(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_enableStrikethrough'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_enableStrikethrough'", nullptr);
            return 0;
        }
        cobj->enableStrikethrough();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:enableStrikethrough",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_enableStrikethrough'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_setHAlign(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_setHAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextHAlignment arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.ResFont:setHAlign");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_setHAlign'", nullptr);
            return 0;
        }
        cobj->setHAlign(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:setHAlign",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_setHAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_isShadowed(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_isShadowed'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_isShadowed'", nullptr);
            return 0;
        }
        bool ret = cobj->isShadowed();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:isShadowed",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_isShadowed'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_isOutlined(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_isOutlined'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_isOutlined'", nullptr);
            return 0;
        }
        bool ret = cobj->isOutlined();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:isOutlined",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_isOutlined'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_createLabel(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_createLabel'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_createLabel'", nullptr);
            return 0;
        }
        cocos2d::Label* ret = cobj->createLabel();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:createLabel",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_createLabel'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_setOutlineSize(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_setOutlineSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.ResFont:setOutlineSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_setOutlineSize'", nullptr);
            return 0;
        }
        cobj->setOutlineSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:setOutlineSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_setOutlineSize'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_enableOutline(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_enableOutline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.ResFont:enableOutline");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_enableOutline'", nullptr);
            return 0;
        }
        cobj->enableOutline(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    if (argc == 2) 
    {
        cocos2d::Color4B arg0;
        int arg1;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.ResFont:enableOutline");

        ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.ResFont:enableOutline");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_enableOutline'", nullptr);
            return 0;
        }
        cobj->enableOutline(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:enableOutline",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_enableOutline'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_disableUnderline(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_disableUnderline'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_disableUnderline'", nullptr);
            return 0;
        }
        cobj->disableUnderline();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:disableUnderline",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_disableUnderline'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_getColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_getColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_getColor'", nullptr);
            return 0;
        }
        cocos2d::Color4B ret = cobj->getColor();
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:getColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_getColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_isUnderlined(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_isUnderlined'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_isUnderlined'", nullptr);
            return 0;
        }
        bool ret = cobj->isUnderlined();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:isUnderlined",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_isUnderlined'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_setBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_setBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        lstg::BlendMode* arg0;

        ok &= luaval_to_BlendMode(tolua_S, 2, &arg0, "lstg.ResFont:setBlendMode");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_setBlendMode'", nullptr);
            return 0;
        }
        cobj->setBlendMode(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:setBlendMode",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_setBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_disableBold(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_disableBold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_disableBold'", nullptr);
            return 0;
        }
        cobj->disableBold();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:disableBold",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_disableBold'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_getShadowColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_getShadowColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_getShadowColor'", nullptr);
            return 0;
        }
        cocos2d::Color4B ret = cobj->getShadowColor();
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:getShadowColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_getShadowColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_setOutlineColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_setOutlineColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.ResFont:setOutlineColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_setOutlineColor'", nullptr);
            return 0;
        }
        cobj->setOutlineColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:setOutlineColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_setOutlineColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_enableItalics(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_enableItalics'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_enableItalics'", nullptr);
            return 0;
        }
        cobj->enableItalics();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:enableItalics",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_enableItalics'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_calcSize(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_calcSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResFont:calcSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_calcSize'", nullptr);
            return 0;
        }
        cocos2d::Vec2 ret = cobj->calcSize(arg0);
        vec2_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:calcSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_calcSize'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_disableAllEffects(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_disableAllEffects'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_disableAllEffects'", nullptr);
            return 0;
        }
        cobj->disableAllEffects();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:disableAllEffects",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_disableAllEffects'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_enableGlow(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_enableGlow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.ResFont:enableGlow");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_enableGlow'", nullptr);
            return 0;
        }
        cobj->enableGlow(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:enableGlow",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_enableGlow'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_setColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.ResFont:setColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_setColor'", nullptr);
            return 0;
        }
        cobj->setColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:setColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_isStrikethrough(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_isStrikethrough'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_isStrikethrough'", nullptr);
            return 0;
        }
        bool ret = cobj->isStrikethrough();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:isStrikethrough",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_isStrikethrough'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_getVAlign(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_getVAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_getVAlign'", nullptr);
            return 0;
        }
        int ret = (int)cobj->getVAlign();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:getVAlign",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_getVAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_enableBold(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_enableBold'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_enableBold'", nullptr);
            return 0;
        }
        cobj->enableBold();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:enableBold",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_enableBold'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_getBlendMode(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_getBlendMode'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_getBlendMode'", nullptr);
            return 0;
        }
        lstg::BlendMode* ret = cobj->getBlendMode();
        BlendMode_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:getBlendMode",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_getBlendMode'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_disableShadow(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_disableShadow'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_disableShadow'", nullptr);
            return 0;
        }
        cobj->disableShadow();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:disableShadow",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_disableShadow'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_setVAlign(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_setVAlign'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::TextVAlignment arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "lstg.ResFont:setVAlign");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_setVAlign'", nullptr);
            return 0;
        }
        cobj->setVAlign(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:setVAlign",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_setVAlign'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_disableStrikethrough(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFont* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFont*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFont_disableStrikethrough'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_disableStrikethrough'", nullptr);
            return 0;
        }
        cobj->disableStrikethrough();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFont:disableStrikethrough",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_disableStrikethrough'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFont_createTTF(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        std::string arg1;
        double arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResFont:createTTF");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ResFont:createTTF");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResFont:createTTF");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_createTTF'", nullptr);
            return 0;
        }
        lstg::ResFont* ret = lstg::ResFont::createTTF(arg0, arg1, arg2);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResFont:createTTF",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_createTTF'.",&tolua_err);
#endif
    return 0;
}
int lua_x_Resource_ResFont_createHGE(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResFont:createHGE");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ResFont:createHGE");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_createHGE'", nullptr);
            return 0;
        }
        lstg::ResFont* ret = lstg::ResFont::createHGE(arg0, arg1);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResFont:createHGE",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_createHGE'.",&tolua_err);
#endif
    return 0;
}
int lua_x_Resource_ResFont_createBMF(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResFont:createBMF");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ResFont:createBMF");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_createBMF'", nullptr);
            return 0;
        }
        lstg::ResFont* ret = lstg::ResFont::createBMF(arg0, arg1);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResFont:createBMF",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_createBMF'.",&tolua_err);
#endif
    return 0;
}
int lua_x_Resource_ResFont_syncLabelSetting(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        XLabel* arg0;
        cocos2d::Label* arg1;
        ok &= lstg::lua::luaval_to_native(tolua_S, 2, &arg0, "lstg.ResFont:syncLabelSetting");
        ok &= lstg::lua::luaval_to_native(tolua_S, 3, &arg1, "lstg.ResFont:syncLabelSetting");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_syncLabelSetting'", nullptr);
            return 0;
        }
        lstg::ResFont::syncLabelSetting(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResFont:syncLabelSetting",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_syncLabelSetting'.",&tolua_err);
#endif
    return 0;
}
int lua_x_Resource_ResFont_HGE2BMF(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResFont",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResFont:HGE2BMF");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ResFont:HGE2BMF");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFont_HGE2BMF'", nullptr);
            return 0;
        }
        std::string ret = lstg::ResFont::HGE2BMF(arg0, arg1);
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResFont:HGE2BMF",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFont_HGE2BMF'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Resource_ResFont_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResFont)");
    return 0;
}

int lua_register_x_Resource_ResFont(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResFont");
    tolua_cclass(tolua_S,"ResFont","lstg.ResFont","lstg.Resource",nullptr);

    tolua_beginmodule(tolua_S,"ResFont");
        tolua_function(tolua_S,"disableOutline",lua_x_Resource_ResFont_disableOutline);
        tolua_function(tolua_S,"enableShadow",lua_x_Resource_ResFont_enableShadow);
        tolua_function(tolua_S,"isBold",lua_x_Resource_ResFont_isBold);
        tolua_function(tolua_S,"setTTFConfig",lua_x_Resource_ResFont_setTTFConfig);
        tolua_function(tolua_S,"disableGlow",lua_x_Resource_ResFont_disableGlow);
        tolua_function(tolua_S,"getHAlign",lua_x_Resource_ResFont_getHAlign);
        tolua_function(tolua_S,"isItalics",lua_x_Resource_ResFont_isItalics);
        tolua_function(tolua_S,"getShadowOffset",lua_x_Resource_ResFont_getShadowOffset);
        tolua_function(tolua_S,"isGlowed",lua_x_Resource_ResFont_isGlowed);
        tolua_function(tolua_S,"getTTFConfig",lua_x_Resource_ResFont_getTTFConfig);
        tolua_function(tolua_S,"getGlowColor",lua_x_Resource_ResFont_getGlowColor);
        tolua_function(tolua_S,"getOutlineSize",lua_x_Resource_ResFont_getOutlineSize);
        tolua_function(tolua_S,"getOutlineColor",lua_x_Resource_ResFont_getOutlineColor);
        tolua_function(tolua_S,"disableItalics",lua_x_Resource_ResFont_disableItalics);
        tolua_function(tolua_S,"getShadowBlurRadius",lua_x_Resource_ResFont_getShadowBlurRadius);
        tolua_function(tolua_S,"enableUnderline",lua_x_Resource_ResFont_enableUnderline);
        tolua_function(tolua_S,"enableStrikethrough",lua_x_Resource_ResFont_enableStrikethrough);
        tolua_function(tolua_S,"setHAlign",lua_x_Resource_ResFont_setHAlign);
        tolua_function(tolua_S,"isShadowed",lua_x_Resource_ResFont_isShadowed);
        tolua_function(tolua_S,"isOutlined",lua_x_Resource_ResFont_isOutlined);
        tolua_function(tolua_S,"createLabel",lua_x_Resource_ResFont_createLabel);
        tolua_function(tolua_S,"setOutlineSize",lua_x_Resource_ResFont_setOutlineSize);
        tolua_function(tolua_S,"enableOutline",lua_x_Resource_ResFont_enableOutline);
        tolua_function(tolua_S,"disableUnderline",lua_x_Resource_ResFont_disableUnderline);
        tolua_function(tolua_S,"getColor",lua_x_Resource_ResFont_getColor);
        tolua_function(tolua_S,"isUnderlined",lua_x_Resource_ResFont_isUnderlined);
        tolua_function(tolua_S,"setBlendMode",lua_x_Resource_ResFont_setBlendMode);
        tolua_function(tolua_S,"disableBold",lua_x_Resource_ResFont_disableBold);
        tolua_function(tolua_S,"getShadowColor",lua_x_Resource_ResFont_getShadowColor);
        tolua_function(tolua_S,"setOutlineColor",lua_x_Resource_ResFont_setOutlineColor);
        tolua_function(tolua_S,"enableItalics",lua_x_Resource_ResFont_enableItalics);
        tolua_function(tolua_S,"calcSize",lua_x_Resource_ResFont_calcSize);
        tolua_function(tolua_S,"disableAllEffects",lua_x_Resource_ResFont_disableAllEffects);
        tolua_function(tolua_S,"enableGlow",lua_x_Resource_ResFont_enableGlow);
        tolua_function(tolua_S,"setColor",lua_x_Resource_ResFont_setColor);
        tolua_function(tolua_S,"isStrikethrough",lua_x_Resource_ResFont_isStrikethrough);
        tolua_function(tolua_S,"getVAlign",lua_x_Resource_ResFont_getVAlign);
        tolua_function(tolua_S,"enableBold",lua_x_Resource_ResFont_enableBold);
        tolua_function(tolua_S,"getBlendMode",lua_x_Resource_ResFont_getBlendMode);
        tolua_function(tolua_S,"disableShadow",lua_x_Resource_ResFont_disableShadow);
        tolua_function(tolua_S,"setVAlign",lua_x_Resource_ResFont_setVAlign);
        tolua_function(tolua_S,"disableStrikethrough",lua_x_Resource_ResFont_disableStrikethrough);
        tolua_function(tolua_S,"createTTF", lua_x_Resource_ResFont_createTTF);
        tolua_function(tolua_S,"createHGE", lua_x_Resource_ResFont_createHGE);
        tolua_function(tolua_S,"createBMF", lua_x_Resource_ResFont_createBMF);
        tolua_function(tolua_S,"syncLabelSetting", lua_x_Resource_ResFont_syncLabelSetting);
        tolua_function(tolua_S,"HGE2BMF", lua_x_Resource_ResFont_HGE2BMF);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResFont).name();
    g_luaType[typeName] = "lstg.ResFont";
    g_typeCast["ResFont"] = "lstg.ResFont";
    return 1;
}

int lua_x_Resource_ResAudio_play(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAudio* cobj = nullptr;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAudio",0,&tolua_err)) goto tolua_lerror;
#endif
    cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S,1,0);
#if COCOS2D_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAudio_play'", nullptr);
        return 0;
    }
#endif
    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 1) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResAudio:play");

            if (!ok) { break; }
            cobj->play(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 2) {
            double arg0;
            ok &= luaval_to_number(tolua_S, 2,&arg0, "lstg.ResAudio:play");

            if (!ok) { break; }
            double arg1;
            ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.ResAudio:play");

            if (!ok) { break; }
            cobj->play(arg0, arg1);
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 0) {
            cobj->play();
            lua_settop(tolua_S, 1);
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "lstg.ResAudio:play",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAudio_play'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAudio_pause(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAudio_pause'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAudio_pause'", nullptr);
            return 0;
        }
        cobj->pause();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAudio:pause",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAudio_pause'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAudio_resume(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAudio_resume'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAudio_resume'", nullptr);
            return 0;
        }
        cobj->resume();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAudio:resume",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAudio_resume'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAudio_stop(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAudio_stop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAudio_stop'", nullptr);
            return 0;
        }
        cobj->stop();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAudio:stop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAudio_stop'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAudio_isStopped(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAudio_isStopped'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAudio_isStopped'", nullptr);
            return 0;
        }
        bool ret = cobj->isStopped();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAudio:isStopped",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAudio_isStopped'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAudio_getStream(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAudio_getStream'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAudio_getStream'", nullptr);
            return 0;
        }
        lstg::StreamMemory* ret = cobj->getStream();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAudio:getStream",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAudio_getStream'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAudio_getSource(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAudio_getSource'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAudio_getSource'", nullptr);
            return 0;
        }
        audio::Source* ret = cobj->getSource();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAudio:getSource",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAudio_getSource'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResAudio_isPlaying(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResAudio* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResAudio",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResAudio*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResAudio_isPlaying'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResAudio_isPlaying'", nullptr);
            return 0;
        }
        bool ret = cobj->isPlaying();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResAudio:isPlaying",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResAudio_isPlaying'.",&tolua_err);
#endif

    return 0;
}
static int lua_x_Resource_ResAudio_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResAudio)");
    return 0;
}

int lua_register_x_Resource_ResAudio(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResAudio");
    tolua_cclass(tolua_S,"ResAudio","lstg.ResAudio","lstg.Resource",nullptr);

    tolua_beginmodule(tolua_S,"ResAudio");
        tolua_function(tolua_S,"play",lua_x_Resource_ResAudio_play);
        tolua_function(tolua_S,"pause",lua_x_Resource_ResAudio_pause);
        tolua_function(tolua_S,"resume",lua_x_Resource_ResAudio_resume);
        tolua_function(tolua_S,"stop",lua_x_Resource_ResAudio_stop);
        tolua_function(tolua_S,"isStopped",lua_x_Resource_ResAudio_isStopped);
        tolua_function(tolua_S,"getStream",lua_x_Resource_ResAudio_getStream);
        tolua_function(tolua_S,"getSource",lua_x_Resource_ResAudio_getSource);
        tolua_function(tolua_S,"isPlaying",lua_x_Resource_ResAudio_isPlaying);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResAudio).name();
    g_luaType[typeName] = "lstg.ResAudio";
    g_typeCast["ResAudio"] = "lstg.ResAudio";
    return 1;
}

int lua_x_Resource_ResSound_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResSound",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResSound:create");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ResSound:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResSound_create'", nullptr);
            return 0;
        }
        lstg::ResSound* ret = lstg::ResSound::create(arg0, arg1);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResSound:create",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResSound_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Resource_ResSound_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResSound)");
    return 0;
}

int lua_register_x_Resource_ResSound(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResSound");
    tolua_cclass(tolua_S,"ResSound","lstg.ResSound","lstg.ResAudio",nullptr);

    tolua_beginmodule(tolua_S,"ResSound");
        tolua_function(tolua_S,"create", lua_x_Resource_ResSound_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResSound).name();
    g_luaType[typeName] = "lstg.ResSound";
    g_typeCast["ResSound"] = "lstg.ResSound";
    return 1;
}

int lua_x_Resource_ResMusic_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResMusic",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        std::string arg0;
        std::string arg1;
        double arg2;
        double arg3;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResMusic:create");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ResMusic:create");
        ok &= luaval_to_number(tolua_S, 4,&arg2, "lstg.ResMusic:create");
        ok &= luaval_to_number(tolua_S, 5,&arg3, "lstg.ResMusic:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResMusic_create'", nullptr);
            return 0;
        }
        lstg::ResMusic* ret = lstg::ResMusic::create(arg0, arg1, arg2, arg3);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResMusic:create",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResMusic_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Resource_ResMusic_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResMusic)");
    return 0;
}

int lua_register_x_Resource_ResMusic(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResMusic");
    tolua_cclass(tolua_S,"ResMusic","lstg.ResMusic","lstg.ResAudio",nullptr);

    tolua_beginmodule(tolua_S,"ResMusic");
        tolua_function(tolua_S,"create", lua_x_Resource_ResMusic_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResMusic).name();
    g_luaType[typeName] = "lstg.ResMusic";
    g_typeCast["ResMusic"] = "lstg.ResMusic";
    return 1;
}

int lua_x_Resource_ResFX_setValue(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFX_setValue'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        double arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "lstg.ResFX:setValue"); arg0 = arg0_tmp.c_str();

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.ResFX:setValue");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFX_setValue'", nullptr);
            return 0;
        }
        cobj->setValue(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFX:setValue",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFX_setValue'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFX_setColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFX_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocos2d::Color4B arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "lstg.ResFX:setColor"); arg0 = arg0_tmp.c_str();

        ok &=luaval_to_color4b(tolua_S, 3, &arg1, "lstg.ResFX:setColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFX_setColor'", nullptr);
            return 0;
        }
        cobj->setColor(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFX:setColor",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFX_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFX_setScreenSize(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFX_setScreenSize'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Vec2 arg0;

        ok &= luaval_to_vec2(tolua_S, 2, &arg0, "lstg.ResFX:setScreenSize");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFX_setScreenSize'", nullptr);
            return 0;
        }
        cobj->setScreenSize(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFX:setScreenSize",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFX_setScreenSize'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFX_getProgramState(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFX_getProgramState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFX_getProgramState'", nullptr);
            return 0;
        }
        cocos2d::GLProgramState* ret = cobj->getProgramState();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFX:getProgramState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFX_getProgramState'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFX_getProgram(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFX_getProgram'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFX_getProgram'", nullptr);
            return 0;
        }
        cocos2d::GLProgram* ret = cobj->getProgram();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFX:getProgram",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFX_getProgram'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFX_setTexture(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFX_setTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        const char* arg0;
        cocos2d::Texture2D* arg1;

        std::string arg0_tmp; ok &= luaval_to_std_string(tolua_S, 2, &arg0_tmp, "lstg.ResFX:setTexture"); arg0 = arg0_tmp.c_str();

        ok &= lstg::lua::luaval_to_native(tolua_S, 3, &arg1, "lstg.ResFX:setTexture");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFX_setTexture'", nullptr);
            return 0;
        }
        cobj->setTexture(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFX:setTexture",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFX_setTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFX_setViewport(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResFX* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResFX",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResFX*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResFX_setViewport'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Rect arg0;

        ok &= luaval_to_rect(tolua_S, 2, &arg0, "lstg.ResFX:setViewport");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFX_setViewport'", nullptr);
            return 0;
        }
        cobj->setViewport(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResFX:setViewport",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFX_setViewport'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResFX_createWithGLProgram(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResFX",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        cocos2d::GLProgram* arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResFX:createWithGLProgram");
        ok &= lstg::lua::luaval_to_native(tolua_S, 3, &arg1, "lstg.ResFX:createWithGLProgram");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFX_createWithGLProgram'", nullptr);
            return 0;
        }
        lstg::ResFX* ret = lstg::ResFX::createWithGLProgram(arg0, arg1);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResFX:createWithGLProgram",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFX_createWithGLProgram'.",&tolua_err);
#endif
    return 0;
}
int lua_x_Resource_ResFX_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResFX",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResFX:create");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ResFX:create");
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "lstg.ResFX:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFX_create'", nullptr);
            return 0;
        }
        lstg::ResFX* ret = lstg::ResFX::create(arg0, arg1, arg2);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResFX:create",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFX_create'.",&tolua_err);
#endif
    return 0;
}
int lua_x_Resource_ResFX_createWithString(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResFX",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 3)
    {
        std::string arg0;
        std::string arg1;
        std::string arg2;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResFX:createWithString");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "lstg.ResFX:createWithString");
        ok &= luaval_to_std_string(tolua_S, 4,&arg2, "lstg.ResFX:createWithString");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResFX_createWithString'", nullptr);
            return 0;
        }
        lstg::ResFX* ret = lstg::ResFX::createWithString(arg0, arg1, arg2);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResFX:createWithString",argc, 3);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResFX_createWithString'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Resource_ResFX_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResFX)");
    return 0;
}

int lua_register_x_Resource_ResFX(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResFX");
    tolua_cclass(tolua_S,"ResFX","lstg.ResFX","lstg.Resource",nullptr);

    tolua_beginmodule(tolua_S,"ResFX");
        tolua_function(tolua_S,"setValue",lua_x_Resource_ResFX_setValue);
        tolua_function(tolua_S,"setColor",lua_x_Resource_ResFX_setColor);
        tolua_function(tolua_S,"setScreenSize",lua_x_Resource_ResFX_setScreenSize);
        tolua_function(tolua_S,"getProgramState",lua_x_Resource_ResFX_getProgramState);
        tolua_function(tolua_S,"getProgram",lua_x_Resource_ResFX_getProgram);
        tolua_function(tolua_S,"setTexture",lua_x_Resource_ResFX_setTexture);
        tolua_function(tolua_S,"setViewport",lua_x_Resource_ResFX_setViewport);
        tolua_function(tolua_S,"createWithGLProgram", lua_x_Resource_ResFX_createWithGLProgram);
        tolua_function(tolua_S,"create", lua_x_Resource_ResFX_create);
        tolua_function(tolua_S,"createWithString", lua_x_Resource_ResFX_createWithString);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResFX).name();
    g_luaType[typeName] = "lstg.ResFX";
    g_typeCast["ResFX"] = "lstg.ResFX";
    return 1;
}

int lua_x_Resource_ResRenderTarget_getClearColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResRenderTarget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResRenderTarget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResRenderTarget_getClearColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResRenderTarget_getClearColor'", nullptr);
            return 0;
        }
        cocos2d::Color4B ret = cobj->getClearColor();
        color4b_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResRenderTarget:getClearColor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResRenderTarget_getClearColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResRenderTarget_render(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResRenderTarget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResRenderTarget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResRenderTarget_render'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        lstg::ResFX* arg0;
        lstg::BlendMode* arg1;

        ok &= lstg::lua::luaval_to_native(tolua_S, 2, &arg0, "lstg.ResRenderTarget:render");

        ok &= luaval_to_BlendMode(tolua_S, 3, &arg1, "lstg.ResRenderTarget:render");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResRenderTarget_render'", nullptr);
            return 0;
        }
        bool ret = cobj->render(arg0, arg1);
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResRenderTarget:render",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResRenderTarget_render'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResRenderTarget_getTexture(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResRenderTarget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResRenderTarget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResRenderTarget_getTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResRenderTarget_getTexture'", nullptr);
            return 0;
        }
        cocos2d::Texture2D* ret = cobj->getTexture();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResRenderTarget:getTexture",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResRenderTarget_getTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResRenderTarget_setNeedBlendFix(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResRenderTarget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResRenderTarget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResRenderTarget_setNeedBlendFix'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        bool arg0;

        ok &= luaval_to_boolean(tolua_S, 2,&arg0, "lstg.ResRenderTarget:setNeedBlendFix");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResRenderTarget_setNeedBlendFix'", nullptr);
            return 0;
        }
        cobj->setNeedBlendFix(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResRenderTarget:setNeedBlendFix",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResRenderTarget_setNeedBlendFix'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResRenderTarget_setClearColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResRenderTarget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResRenderTarget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResRenderTarget_setClearColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::Color4B arg0;

        ok &=luaval_to_color4b(tolua_S, 2, &arg0, "lstg.ResRenderTarget:setClearColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResRenderTarget_setClearColor'", nullptr);
            return 0;
        }
        cobj->setClearColor(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResRenderTarget:setClearColor",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResRenderTarget_setClearColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResRenderTarget_getTarget(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResRenderTarget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResRenderTarget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResRenderTarget_getTarget'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResRenderTarget_getTarget'", nullptr);
            return 0;
        }
        cocos2d::RenderTexture* ret = cobj->getTarget();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResRenderTarget:getTarget",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResRenderTarget_getTarget'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResRenderTarget_isNeedBlendFix(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResRenderTarget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResRenderTarget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResRenderTarget_isNeedBlendFix'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResRenderTarget_isNeedBlendFix'", nullptr);
            return 0;
        }
        bool ret = cobj->isNeedBlendFix();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResRenderTarget:isNeedBlendFix",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResRenderTarget_isNeedBlendFix'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResRenderTarget_pop(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResRenderTarget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResRenderTarget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResRenderTarget_pop'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResRenderTarget_pop'", nullptr);
            return 0;
        }
        bool ret = cobj->pop();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResRenderTarget:pop",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResRenderTarget_pop'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResRenderTarget_push(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResRenderTarget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResRenderTarget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResRenderTarget_push'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResRenderTarget_push'", nullptr);
            return 0;
        }
        bool ret = cobj->push();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResRenderTarget:push",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResRenderTarget_push'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResRenderTarget_copyTexture(lua_State* tolua_S)
{
    int argc = 0;
    lstg::ResRenderTarget* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.ResRenderTarget",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::ResRenderTarget*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_Resource_ResRenderTarget_copyTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResRenderTarget_copyTexture'", nullptr);
            return 0;
        }
        cocos2d::Texture2D* ret = cobj->copyTexture();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.ResRenderTarget:copyTexture",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResRenderTarget_copyTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_x_Resource_ResRenderTarget_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.ResRenderTarget",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.ResRenderTarget:create");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_Resource_ResRenderTarget_create'", nullptr);
            return 0;
        }
        lstg::ResRenderTarget* ret = lstg::ResRenderTarget::create(arg0);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.ResRenderTarget:create",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_Resource_ResRenderTarget_create'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_Resource_ResRenderTarget_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (ResRenderTarget)");
    return 0;
}

int lua_register_x_Resource_ResRenderTarget(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.ResRenderTarget");
    tolua_cclass(tolua_S,"ResRenderTarget","lstg.ResRenderTarget","lstg.Resource",nullptr);

    tolua_beginmodule(tolua_S,"ResRenderTarget");
        tolua_function(tolua_S,"getClearColor",lua_x_Resource_ResRenderTarget_getClearColor);
        tolua_function(tolua_S,"render",lua_x_Resource_ResRenderTarget_render);
        tolua_function(tolua_S,"getTexture",lua_x_Resource_ResRenderTarget_getTexture);
        tolua_function(tolua_S,"setNeedBlendFix",lua_x_Resource_ResRenderTarget_setNeedBlendFix);
        tolua_function(tolua_S,"setClearColor",lua_x_Resource_ResRenderTarget_setClearColor);
        tolua_function(tolua_S,"getTarget",lua_x_Resource_ResRenderTarget_getTarget);
        tolua_function(tolua_S,"isNeedBlendFix",lua_x_Resource_ResRenderTarget_isNeedBlendFix);
        tolua_function(tolua_S,"pop",lua_x_Resource_ResRenderTarget_pop);
        tolua_function(tolua_S,"push",lua_x_Resource_ResRenderTarget_push);
        tolua_function(tolua_S,"copyTexture",lua_x_Resource_ResRenderTarget_copyTexture);
        tolua_function(tolua_S,"create", lua_x_Resource_ResRenderTarget_create);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::ResRenderTarget).name();
    g_luaType[typeName] = "lstg.ResRenderTarget";
    g_typeCast["ResRenderTarget"] = "lstg.ResRenderTarget";
    return 1;
}
TOLUA_API int register_all_x_Resource(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_Resource_Resource(tolua_S);
	lua_register_x_Resource_ResTexture(tolua_S);
	lua_register_x_Resource_ResFont(tolua_S);
	lua_register_x_Resource_ResourceColliable(tolua_S);
	lua_register_x_Resource_ResourceQuad(tolua_S);
	lua_register_x_Resource_ResAnimation(tolua_S);
	lua_register_x_Resource_ResSprite(tolua_S);
	lua_register_x_Resource_ResParticle(tolua_S);
	lua_register_x_Resource_ResRenderTarget(tolua_S);
	lua_register_x_Resource_ResAudio(tolua_S);
	lua_register_x_Resource_ResMusic(tolua_S);
	lua_register_x_Resource_ResSound(tolua_S);
	lua_register_x_Resource_ResFX(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

