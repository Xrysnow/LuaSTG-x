#include "lua_RenderMode_auto.hpp"
#include "../LSTG/RenderMode.h"
#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
#include "Util/UtilLuaConversion.h"
#define color4b_to_luaval lstg::lua::_color4b_to_luaval
#define luaval_to_color4b lstg::lua::_luaval_to_color4b

int lua_x_RenderMode_RenderMode_clone(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_clone'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.RenderMode:clone");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_clone'", nullptr);
            return 0;
        }
        lstg::RenderMode* ret = cobj->clone(arg0);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:clone",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_clone'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_setMat4(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_setMat4'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Mat4 arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.RenderMode:setMat4");

        ok &= luaval_to_mat4(tolua_S, 3, &arg1, "lstg.RenderMode:setMat4");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_setMat4'", nullptr);
            return 0;
        }
        cobj->setMat4(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:setMat4",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_setMat4'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_getBlendFunc(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_getBlendFunc'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_getBlendFunc'", nullptr);
            return 0;
        }
        cocos2d::BlendFunc ret = cobj->getBlendFunc();
        blendfunc_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:getBlendFunc",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_getBlendFunc'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_setColor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_setColor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Color4B arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.RenderMode:setColor");

        ok &=luaval_to_color4b(tolua_S, 3, &arg1, "lstg.RenderMode:setColor");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_setColor'", nullptr);
            return 0;
        }
        cobj->setColor(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:setColor",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_setColor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_setFloat(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_setFloat'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        double arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.RenderMode:setFloat");

        ok &= luaval_to_number(tolua_S, 3,&arg1, "lstg.RenderMode:setFloat");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_setFloat'", nullptr);
            return 0;
        }
        cobj->setFloat(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:setFloat",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_setFloat'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_setVec4(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_setVec4'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Vec4 arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.RenderMode:setVec4");

        ok &= luaval_to_vec4(tolua_S, 3, &arg1, "lstg.RenderMode:setVec4");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_setVec4'", nullptr);
            return 0;
        }
        cobj->setVec4(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:setVec4",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_setVec4'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_getBlendDescriptor(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_getBlendDescriptor'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_getBlendDescriptor'", nullptr);
            return 0;
        }
        cocos2d::backend::BlendDescriptor ret = cobj->getBlendDescriptor();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:getBlendDescriptor",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_getBlendDescriptor'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_getName(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_getName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_getName'", nullptr);
            return 0;
        }
        std::string ret = cobj->getName();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:getName",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_getName'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_getID(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_getID'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_getID'", nullptr);
            return 0;
        }
        unsigned int ret = cobj->getID();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:getID",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_getID'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_newProgramState(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_newProgramState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_newProgramState'", nullptr);
            return 0;
        }
        cocos2d::backend::ProgramState* ret = cobj->newProgramState();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:newProgramState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_newProgramState'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_getProgram(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_getProgram'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_getProgram'", nullptr);
            return 0;
        }
        cocos2d::backend::Program* ret = cobj->getProgram();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:getProgram",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_getProgram'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_getUniformNames(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_getUniformNames'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_getUniformNames'", nullptr);
            return 0;
        }
        std::vector<std::string> ret = cobj->getUniformNames();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:getUniformNames",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_getUniformNames'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_setTexture(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_setTexture'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Texture2D* arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.RenderMode:setTexture");

        ok &= lstg::lua::luaval_to_native(tolua_S, 3, &arg1, "lstg.RenderMode:setTexture");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_setTexture'", nullptr);
            return 0;
        }
        cobj->setTexture(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:setTexture",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_setTexture'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_getDefaultProgramState(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_getDefaultProgramState'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_getDefaultProgramState'", nullptr);
            return 0;
        }
        cocos2d::backend::ProgramState* ret = cobj->getDefaultProgramState();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:getDefaultProgramState",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_getDefaultProgramState'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_setVec3(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_setVec3'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Vec3 arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.RenderMode:setVec3");

        ok &= luaval_to_vec3(tolua_S, 3, &arg1, "lstg.RenderMode:setVec3");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_setVec3'", nullptr);
            return 0;
        }
        cobj->setVec3(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:setVec3",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_setVec3'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_setVec2(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_setVec2'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2) 
    {
        std::string arg0;
        cocos2d::Vec2 arg1;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.RenderMode:setVec2");

        ok &= luaval_to_vec2(tolua_S, 3, &arg1, "lstg.RenderMode:setVec2");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_setVec2'", nullptr);
            return 0;
        }
        cobj->setVec2(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:setVec2",argc, 2);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_setVec2'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_setUniformBuffer(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_setUniformBuffer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        std::string arg0;

        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.RenderMode:setUniformBuffer");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_setUniformBuffer'", nullptr);
            return 0;
        }
        cobj->setUniformBuffer(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:setUniformBuffer",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_setUniformBuffer'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_getUniformBuffer(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_getUniformBuffer'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0) 
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_getUniformBuffer'", nullptr);
            return 0;
        }
        std::string ret = cobj->getUniformBuffer();
        lua_pushlstring(tolua_S,ret.c_str(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:getUniformBuffer",argc, 0);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_getUniformBuffer'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_setProgram(lua_State* tolua_S)
{
    int argc = 0;
    lstg::RenderMode* cobj = nullptr;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (lstg::RenderMode*)tolua_tousertype(tolua_S,1,0);

#if COCOS2D_DEBUG >= 1
    if (!cobj) 
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_x_RenderMode_RenderMode_setProgram'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1) 
    {
        cocos2d::backend::Program* arg0;

        ok &= lstg::lua::luaval_to_native(tolua_S, 2, &arg0, "lstg.RenderMode:setProgram");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_setProgram'", nullptr);
            return 0;
        }
        cobj->setProgram(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "lstg.RenderMode:setProgram",argc, 1);
    return 0;

#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_setProgram'.",&tolua_err);
#endif

    return 0;
}
int lua_x_RenderMode_RenderMode_listRenderModes(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_listRenderModes'", nullptr);
            return 0;
        }
        std::vector<lstg::RenderMode *> ret = lstg::RenderMode::listRenderModes();
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.RenderMode:listRenderModes",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_listRenderModes'.",&tolua_err);
#endif
    return 0;
}
int lua_x_RenderMode_RenderMode_create(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 2)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.RenderMode:create");
            if (!ok) { break; }
            cocos2d::backend::Program* arg1;
            ok &= lstg::lua::luaval_to_native(tolua_S, 3, &arg1, "lstg.RenderMode:create");
            if (!ok) { break; }
            lstg::RenderMode* ret = lstg::RenderMode::create(arg0, arg1);
            lstg::lua::native_to_luaval(tolua_S, ret);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 5)
        {
            std::string arg0;
            ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.RenderMode:create");
            if (!ok) { break; }
            cocos2d::backend::BlendOperation arg1;
            ok &= luaval_to_int32(tolua_S, 3,(int *)&arg1, "lstg.RenderMode:create");
            if (!ok) { break; }
            cocos2d::backend::BlendFactor arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "lstg.RenderMode:create");
            if (!ok) { break; }
            cocos2d::backend::BlendFactor arg3;
            ok &= luaval_to_int32(tolua_S, 5,(int *)&arg3, "lstg.RenderMode:create");
            if (!ok) { break; }
            cocos2d::backend::Program* arg4;
            ok &= lstg::lua::luaval_to_native(tolua_S, 6, &arg4, "lstg.RenderMode:create");
            if (!ok) { break; }
            lstg::RenderMode* ret = lstg::RenderMode::create(arg0, arg1, arg2, arg3, arg4);
            lstg::lua::native_to_luaval(tolua_S, ret);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "lstg.RenderMode:create",argc, 5);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_create'.",&tolua_err);
#endif
    return 0;
}
int lua_x_RenderMode_RenderMode_getByID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        unsigned int arg0;
        ok &= luaval_to_uint32(tolua_S, 2,&arg0, "lstg.RenderMode:getByID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_getByID'", nullptr);
            return 0;
        }
        lstg::RenderMode* ret = lstg::RenderMode::getByID(arg0);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.RenderMode:getByID",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_getByID'.",&tolua_err);
#endif
    return 0;
}
int lua_x_RenderMode_RenderMode_getIDByName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.RenderMode:getIDByName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_getIDByName'", nullptr);
            return 0;
        }
        unsigned int ret = lstg::RenderMode::getIDByName(arg0);
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.RenderMode:getIDByName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_getIDByName'.",&tolua_err);
#endif
    return 0;
}
int lua_x_RenderMode_RenderMode_getByName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"lstg.RenderMode",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "lstg.RenderMode:getByName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_x_RenderMode_RenderMode_getByName'", nullptr);
            return 0;
        }
        lstg::RenderMode* ret = lstg::RenderMode::getByName(arg0);
        lstg::lua::native_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "lstg.RenderMode:getByName",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_x_RenderMode_RenderMode_getByName'.",&tolua_err);
#endif
    return 0;
}
static int lua_x_RenderMode_RenderMode_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (RenderMode)");
    return 0;
}

int lua_register_x_RenderMode_RenderMode(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"lstg.RenderMode");
    tolua_cclass(tolua_S,"RenderMode","lstg.RenderMode","cc.Ref",nullptr);

    tolua_beginmodule(tolua_S,"RenderMode");
        tolua_function(tolua_S,"clone",lua_x_RenderMode_RenderMode_clone);
        tolua_function(tolua_S,"setMat4",lua_x_RenderMode_RenderMode_setMat4);
        tolua_function(tolua_S,"getBlendFunc",lua_x_RenderMode_RenderMode_getBlendFunc);
        tolua_function(tolua_S,"setColor",lua_x_RenderMode_RenderMode_setColor);
        tolua_function(tolua_S,"setFloat",lua_x_RenderMode_RenderMode_setFloat);
        tolua_function(tolua_S,"setVec4",lua_x_RenderMode_RenderMode_setVec4);
        tolua_function(tolua_S,"getBlendDescriptor",lua_x_RenderMode_RenderMode_getBlendDescriptor);
        tolua_function(tolua_S,"getName",lua_x_RenderMode_RenderMode_getName);
        tolua_function(tolua_S,"getID",lua_x_RenderMode_RenderMode_getID);
        tolua_function(tolua_S,"newProgramState",lua_x_RenderMode_RenderMode_newProgramState);
        tolua_function(tolua_S,"getProgram",lua_x_RenderMode_RenderMode_getProgram);
        tolua_function(tolua_S,"getUniformNames",lua_x_RenderMode_RenderMode_getUniformNames);
        tolua_function(tolua_S,"setTexture",lua_x_RenderMode_RenderMode_setTexture);
        tolua_function(tolua_S,"getDefaultProgramState",lua_x_RenderMode_RenderMode_getDefaultProgramState);
        tolua_function(tolua_S,"setVec3",lua_x_RenderMode_RenderMode_setVec3);
        tolua_function(tolua_S,"setVec2",lua_x_RenderMode_RenderMode_setVec2);
        tolua_function(tolua_S,"setUniformBuffer",lua_x_RenderMode_RenderMode_setUniformBuffer);
        tolua_function(tolua_S,"getUniformBuffer",lua_x_RenderMode_RenderMode_getUniformBuffer);
        tolua_function(tolua_S,"setProgram",lua_x_RenderMode_RenderMode_setProgram);
        tolua_function(tolua_S,"listRenderModes", lua_x_RenderMode_RenderMode_listRenderModes);
        tolua_function(tolua_S,"create", lua_x_RenderMode_RenderMode_create);
        tolua_function(tolua_S,"getByID", lua_x_RenderMode_RenderMode_getByID);
        tolua_function(tolua_S,"getIDByName", lua_x_RenderMode_RenderMode_getIDByName);
        tolua_function(tolua_S,"getByName", lua_x_RenderMode_RenderMode_getByName);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(lstg::RenderMode).name();
    g_luaType[typeName] = "lstg.RenderMode";
    g_typeCast["RenderMode"] = "lstg.RenderMode";
    return 1;
}
TOLUA_API int register_all_x_RenderMode(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"lstg",0);
	tolua_beginmodule(tolua_S,"lstg");

	lua_register_x_RenderMode_RenderMode(tolua_S);

	tolua_endmodule(tolua_S);
	return 1;
}

