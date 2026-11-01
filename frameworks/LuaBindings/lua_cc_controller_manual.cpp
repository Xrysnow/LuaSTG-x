#include "lua_cc_controller_manual.hpp"

// #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

#include "scripting/lua-bindings/manual/tolua_fix.h"
#include "scripting/lua-bindings/manual/LuaBasicConversions.h"
//#include "scripting/lua-bindings/manual/cocos2d/LuaScriptHandlerMgr.h"
#include "scripting/lua-bindings/manual/CCLuaValue.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "base/CCGameController.h"

#ifndef LUA_CHECK_COBJ_TYPE
#ifdef LUA_DEBUG
#define LUA_CHECK_COBJ_TYPE(L, TYPE, NAME) tolua_Error controller_type_error; if(!tolua_isusertype((L), 1, (TYPE), 0, &controller_type_error)) { return luaL_error((L), "invalid 'cobj' in '%s': '%s', expects '%s'", NAME, tolua_typename((L), 1), (TYPE)); }
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

static void cloneEventListenerControllerHandler(const cocos2d::EventListenerController* src,cocos2d::EventListenerController* dst,  ScriptHandlerMgr::HandlerType type)
{
    if (nullptr == src || nullptr == dst)
        return;

    LUA_FUNCTION handler = ScriptHandlerMgr::getInstance()->getObjectHandler((void*)src, type);
    if (0 != handler)
    {
        int newscriptHandler = ScriptEngineManager::getInstance()->getScriptEngine()->reallocateScriptHandler(handler);

        ScriptHandlerMgr::getInstance()->addObjectHandler((void*)dst, newscriptHandler, type);
        switch (type)
        {
            case ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_CONNECTED:
                {
                    dst->onConnected = [=](cocos2d::Controller* controller, Event* event){

                    };
                }
                break;
            case ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_DISCONNECTED:
                {
                    dst->onDisconnected = [=](cocos2d::Controller* controller, Event* event){

                    };
                }
                break;
            case ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_KEYDOWN:
                {
                    dst->onKeyDown = [=](cocos2d::Controller* controller, int keyCode, Event* event){

                    };
                }
                break;
            case ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_KEYUP:
                {
                    dst->onKeyUp = [=](cocos2d::Controller* controller, int keyCode, Event* event){

                    };
                }
                break;
            case ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_KEYREPEAT:
                {
                    dst->onKeyRepeat = [=](cocos2d::Controller* controller, int keyCode, Event* event){
                    };
                }
                break;
            case ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_AXIS:
                {
                    dst->onAxisEvent = [=](cocos2d::Controller* controller, int keyCode, Event* event){
                    };
                }
                break;
            default:
                break;
        }
    }
}

static int tolua_cocos2dx_EventListenerController_clone(lua_State* tolua_S)
{
    if (nullptr == tolua_S)
        return 0;
    constexpr auto LUA_OBJ_TYPE = "cc.EventListenerController";
    constexpr auto LUA_FNAME = "cc.EventListenerController:clone";
    LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
    auto self = (cocos2d::EventListenerController*)tolua_tousertype(tolua_S, 1, nullptr);
    LUA_CHECK_COBJ(tolua_S, self, LUA_FNAME);
    const int argc = lua_gettop(tolua_S) - 1;
    if (argc == 0)
    {
        cocos2d::EventListenerController* tolua_ret = cocos2d::EventListenerController::create();
        if(nullptr == tolua_ret)
            return 0;

        cloneEventListenerControllerHandler(self, tolua_ret, ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_CONNECTED);
        cloneEventListenerControllerHandler(self, tolua_ret, ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_DISCONNECTED);
        cloneEventListenerControllerHandler(self, tolua_ret, ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_KEYDOWN);
        cloneEventListenerControllerHandler(self, tolua_ret, ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_KEYUP);
        cloneEventListenerControllerHandler(self, tolua_ret, ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_KEYREPEAT);
        cloneEventListenerControllerHandler(self, tolua_ret, ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_AXIS);

        int ID = (tolua_ret) ? (int)tolua_ret->_ID : -1;
        int* luaID = (tolua_ret) ? &tolua_ret->_luaID : NULL;
        toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)tolua_ret,"cc.EventListenerController");
        return 1;
    }
    LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "0");
}

static int tolua_cocos2dx_EventListenerController_registerScriptHandler(lua_State* tolua_S)
{
    if (nullptr == tolua_S)
        return 0;
    bool ok = true;
    constexpr auto LUA_OBJ_TYPE = "cc.EventListenerController";
    constexpr auto LUA_FNAME = "cc.EventListenerController:registerScriptHandler";
    LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
    auto self = (cocos2d::EventListenerController*)tolua_tousertype(tolua_S, 1, nullptr);
    LUA_CHECK_COBJ(tolua_S, self, LUA_FNAME);
    const int argc = lua_gettop(tolua_S) - 1;
    if (argc == 2)
    {
        tolua_Error parameter_error;
        ok &= toluafix_isfunction(tolua_S, 2, "LUA_FUNCTION", 0, &parameter_error);
        ok &= tolua_isnumber(tolua_S, 3, 0, &parameter_error);
        LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
        LUA_FUNCTION handler = toluafix_ref_function(tolua_S, 2, 0);
        ScriptHandlerMgr::HandlerType type = static_cast<ScriptHandlerMgr::HandlerType>((int)tolua_tonumber(tolua_S, 3, 0));        
        switch (type)
        {
            case ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_CONNECTED:
                {
                    ScriptHandlerMgr::getInstance()->addObjectHandler((void*)self, handler, type);

                    self->onConnected = [=](cocos2d::Controller* controller, Event* event){
                        auto* callbackStack = LuaEngine::getInstance()->getLuaStack();
                        callbackStack->executeCallback([=]() mutable -> int {
                            auto* tolua_S = callbackStack->getLuaState();
                            tolua_pushusertype(tolua_S, (void*)controller, "cc.Controller");
                            int ID = (event) ? (int)event->_ID : -1;
                            int* luaID = (event) ? &event->_luaID : NULL;
                            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)event,"cc.event");
                            LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 2);

                            return 0;
                        });
                    };
                }
                break;
            case ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_DISCONNECTED:
                {
                    ScriptHandlerMgr::getInstance()->addObjectHandler((void*)self, handler, type);

                    self->onDisconnected = [=](cocos2d::Controller* controller, Event* event){
                        auto* callbackStack = LuaEngine::getInstance()->getLuaStack();
                        callbackStack->executeCallback([=]() mutable -> int {
                            auto* tolua_S = callbackStack->getLuaState();
                            tolua_pushusertype(tolua_S, (void*)controller, "cc.Controller");
                            int ID = (event) ? (int)event->_ID : -1;
                            int* luaID = (event) ? &event->_luaID : NULL;
                            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)event,"cc.event");
                            LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 2);

                            return 0;
                        });
                    };
                }
                break;
            case ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_KEYDOWN:
                {

                    ScriptHandlerMgr::getInstance()->addObjectHandler((void*)self, handler, type);

                    self->onKeyDown = [=](cocos2d::Controller* controller, int keyCode, Event* event){
                        auto* callbackStack = LuaEngine::getInstance()->getLuaStack();
                        callbackStack->executeCallback([=]() mutable -> int {
                            auto* tolua_S = callbackStack->getLuaState();
                            tolua_pushusertype(tolua_S, (void*)controller, "cc.Controller");
                            tolua_pushnumber(tolua_S, (lua_Number) keyCode);
                            int ID = (event) ? (int)event->_ID : -1;
                            int* luaID = (event) ? &event->_luaID : NULL;
                            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)event,"cc.event");
                            LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 3);

                            return 0;
                        });
                    };
                }
                break;
            case ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_KEYUP:
                {
                    ScriptHandlerMgr::getInstance()->addObjectHandler((void*)self, handler, type);

                    self->onKeyUp = [=](cocos2d::Controller* controller, int keyCode, Event* event){
                        auto* callbackStack = LuaEngine::getInstance()->getLuaStack();
                        callbackStack->executeCallback([=]() mutable -> int {
                            auto* tolua_S = callbackStack->getLuaState();
                            tolua_pushusertype(tolua_S, (void*)controller, "cc.Controller");
                            tolua_pushnumber(tolua_S, (lua_Number) keyCode);
                            int ID = (event) ? (int)event->_ID : -1;
                            int* luaID = (event) ? &event->_luaID : NULL;
                            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)event,"cc.event");
                            LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 3);

                            return 0;
                        });
                    };
                }
                break;
            case ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_KEYREPEAT:
                {
                    ScriptHandlerMgr::getInstance()->addObjectHandler((void*)self, handler, type);

                    self->onKeyRepeat = [=](cocos2d::Controller* controller, int keyCode, Event* event){
                        auto* callbackStack = LuaEngine::getInstance()->getLuaStack();
                        callbackStack->executeCallback([=]() mutable -> int {
                            auto* tolua_S = callbackStack->getLuaState();
                            tolua_pushusertype(tolua_S, (void*)controller, "cc.Controller");
                            tolua_pushnumber(tolua_S, (lua_Number) keyCode);
                            int ID = (event) ? (int)event->_ID : -1;
                            int* luaID = (event) ? &event->_luaID : NULL;
                            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)event,"cc.event");
                            LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 3);

                            return 0;
                        });
                    };
                }
                break;
            case ScriptHandlerMgr::HandlerType::EVENT_CONTROLLER_AXIS:
                {
                    ScriptHandlerMgr::getInstance()->addObjectHandler((void*)self, handler, type);

                    self->onAxisEvent = [=](cocos2d::Controller* controller, int keyCode, Event* event){
                        auto* callbackStack = LuaEngine::getInstance()->getLuaStack();
                        callbackStack->executeCallback([=]() mutable -> int {
                            auto* tolua_S = callbackStack->getLuaState();
                            tolua_pushusertype(tolua_S, (void*)controller, "cc.Controller");
                            tolua_pushnumber(tolua_S, (lua_Number) keyCode);
                            int ID = (event) ? (int)event->_ID : -1;
                            int* luaID = (event) ? &event->_luaID : NULL;
                            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)event,"cc.event");
                            LuaEngine::getInstance()->getLuaStack()->executeFunctionByHandler(handler, 3);

                            return 0;
                        });
                    };
                }
                break;
            default:
                break;
        }
        return 0;
    }
    LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "2");
}

static void extendEventListenerController(lua_State* L)
{
    lua_pushstring(L, "cc.EventListenerController");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L, "clone", tolua_cocos2dx_EventListenerController_clone);
        tolua_function(L, "registerScriptHandler", tolua_cocos2dx_EventListenerController_registerScriptHandler);
    }
    lua_pop(L, 1);
}

static int tolua_cocos2dx_Controller_getKeyStatus(lua_State* tolua_S)
{
    if (nullptr == tolua_S)
        return 0;
    bool ok = true;
    constexpr auto LUA_OBJ_TYPE = "cc.Controller";
    constexpr auto LUA_FNAME = "cc.Controller:getKeyStatus";
    LUA_CHECK_COBJ_TYPE(tolua_S, LUA_OBJ_TYPE, LUA_FNAME);
    auto self = (cocos2d::Controller*)tolua_tousertype(tolua_S, 1, nullptr);
    LUA_CHECK_COBJ(tolua_S, self, LUA_FNAME);
    const int argc = lua_gettop(tolua_S) - 1;
    if (argc == 1)
    {
        tolua_Error parameter_error;
        ok &= tolua_isnumber(tolua_S, 2, 0, &parameter_error);
        LUA_CHECK_PARAMETER(tolua_S, ok, LUA_FNAME);
        int keyCode = (int)tolua_tonumber(tolua_S, 2, 0);
        cocos2d::Controller::KeyStatus keyStatus = self->getKeyStatus(keyCode);
        lua_newtable(tolua_S);                                    /* L: table */
        lua_pushstring(tolua_S, "isPressed");                     /* L: table key */
        lua_pushboolean(tolua_S, (int)keyStatus.isPressed);            /* L: table key value*/
        lua_rawset(tolua_S, -3);                                  /* table[key] = value, L: table */
        lua_pushstring(tolua_S, "value");                         /* L: table key */
        lua_pushnumber(tolua_S, (lua_Number) keyStatus.value);    /* L: table key value*/
        lua_rawset(tolua_S, -3);                                  /* table[key] = value, L: table */
        lua_pushstring(tolua_S, "isAnalog");                         /* L: table key */
        lua_pushnumber(tolua_S, (int) keyStatus.isAnalog);           /* L: table key value*/
        lua_rawset(tolua_S, -3);                                  /* table[key] = value, L: table */
        return 1;
    }
    LUA_PARAMETER_ERROR(tolua_S, LUA_FNAME, argc, "1");
}

static void extendController(lua_State* L)
{
    lua_pushstring(L, "cc.Controller");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L, "getKeyStatus", tolua_cocos2dx_Controller_getKeyStatus);
    }
    lua_pop(L, 1);
}


#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
// Device-specific success paths retain their old wrappers pending hardware acceptance.
int lua_cocos2dx_controller_Controller_getDeviceId(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Controller* cobj = nullptr;
    bool ok  = true;

#if CC_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if CC_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Controller",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Controller*)tolua_tousertype(tolua_S,1,0);

#if CC_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_controller_Controller_getDeviceId'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_controller_Controller_getDeviceId'", nullptr);
            return 0;
        }
        int ret = cobj->getDeviceId();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Controller:getDeviceId",argc, 0);
    return 0;

#if CC_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_controller_Controller_getDeviceId'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_controller_Controller_getDeviceName(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Controller* cobj = nullptr;
    bool ok  = true;

#if CC_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if CC_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Controller",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Controller*)tolua_tousertype(tolua_S,1,0);

#if CC_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_controller_Controller_getDeviceName'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_controller_Controller_getDeviceName'", nullptr);
            return 0;
        }
        const auto& ret = cobj->getDeviceName();
        lua_pushlstring(tolua_S,ret.data(),ret.length());
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Controller:getDeviceName",argc, 0);
    return 0;

#if CC_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_controller_Controller_getDeviceName'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_controller_Controller_getTag(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Controller* cobj = nullptr;
    bool ok  = true;

#if CC_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if CC_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Controller",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Controller*)tolua_tousertype(tolua_S,1,0);

#if CC_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_controller_Controller_getTag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_controller_Controller_getTag'", nullptr);
            return 0;
        }
        int ret = cobj->getTag();
        tolua_pushnumber(tolua_S,(lua_Number)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Controller:getTag",argc, 0);
    return 0;

#if CC_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_controller_Controller_getTag'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_controller_Controller_isConnected(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Controller* cobj = nullptr;
    bool ok  = true;

#if CC_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if CC_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Controller",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Controller*)tolua_tousertype(tolua_S,1,0);

#if CC_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_controller_Controller_isConnected'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_controller_Controller_isConnected'", nullptr);
            return 0;
        }
        bool ret = cobj->isConnected();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Controller:isConnected",argc, 0);
    return 0;

#if CC_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_controller_Controller_isConnected'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_controller_Controller_setTag(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Controller* cobj = nullptr;
    bool ok  = true;

#if CC_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if CC_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Controller",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Controller*)tolua_tousertype(tolua_S,1,0);

#if CC_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_controller_Controller_setTag'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 1)
    {
        int arg0;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.Controller:setTag");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_controller_Controller_setTag'", nullptr);
            return 0;
        }
        cobj->setTag(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Controller:setTag",argc, 1);
    return 0;

#if CC_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_controller_Controller_setTag'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_controller_Controller_receiveExternalKeyEvent(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::Controller* cobj = nullptr;
    bool ok  = true;

#if CC_DEBUG >= 1
    tolua_Error tolua_err;
#endif


#if CC_DEBUG >= 1
    if (!tolua_isusertype(tolua_S,1,"cc.Controller",0,&tolua_err)) goto tolua_lerror;
#endif

    cobj = (cocos2d::Controller*)tolua_tousertype(tolua_S,1,0);

#if CC_DEBUG >= 1
    if (!cobj)
    {
        tolua_error(tolua_S,"invalid 'cobj' in function 'lua_cocos2dx_controller_Controller_receiveExternalKeyEvent'", nullptr);
        return 0;
    }
#endif

    argc = lua_gettop(tolua_S)-1;
    if (argc == 2)
    {
        int arg0;
        bool arg1;

        ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.Controller:receiveExternalKeyEvent");

        ok &= luaval_to_boolean(tolua_S, 3,&arg1, "cc.Controller:receiveExternalKeyEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_cocos2dx_controller_Controller_receiveExternalKeyEvent'", nullptr);
            return 0;
        }
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		cobj->receiveExternalKeyEvent(arg0, arg1);
#endif
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n", "cc.Controller:receiveExternalKeyEvent",argc, 2);
    return 0;

#if CC_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_controller_Controller_receiveExternalKeyEvent'.",&tolua_err);
#endif

    return 0;
}

int lua_cocos2dx_controller_EventController_constructor(lua_State* tolua_S)
{
    int argc = 0;
    cocos2d::EventController* cobj = nullptr;
    bool ok  = true;
#if CC_DEBUG >= 1
    tolua_Error tolua_err;
#endif

    argc = lua_gettop(tolua_S)-1;
    do{
        if (argc == 3) {
            cocos2d::EventController::ControllerEventType arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.EventController:EventController");

            if (!ok) { break; }
            cocos2d::Controller* arg1;
            ok &= luaval_to_object<cocos2d::Controller>(tolua_S, 3, "cc.Controller",&arg1, "cc.EventController:EventController");

            if (!ok) { break; }
            bool arg2;
            ok &= luaval_to_boolean(tolua_S, 4,&arg2, "cc.EventController:EventController");

            if (!ok) { break; }
            cobj = new cocos2d::EventController(arg0, arg1, arg2);
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.EventController");
            return 1;
        }
    }while(0);
    ok  = true;
    do{
        if (argc == 3) {
            cocos2d::EventController::ControllerEventType arg0;
            ok &= luaval_to_int32(tolua_S, 2,(int *)&arg0, "cc.EventController:EventController");

            if (!ok) { break; }
            cocos2d::Controller* arg1;
            ok &= luaval_to_object<cocos2d::Controller>(tolua_S, 3, "cc.Controller",&arg1, "cc.EventController:EventController");

            if (!ok) { break; }
            int arg2;
            ok &= luaval_to_int32(tolua_S, 4,(int *)&arg2, "cc.EventController:EventController");

            if (!ok) { break; }
            cobj = new cocos2d::EventController(arg0, arg1, arg2);
            cobj->autorelease();
            int ID =  (int)cobj->_ID ;
            int* luaID =  &cobj->_luaID ;
            toluafix_pushusertype_ccobject(tolua_S, ID, luaID, (void*)cobj,"cc.EventController");
            return 1;
        }
    }while(0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d \n",  "cc.EventController:EventController",argc, 3);
    return 0;

#if CC_DEBUG >= 1
    tolua_error(tolua_S,"#ferror in function 'lua_cocos2dx_controller_EventController_constructor'.",&tolua_err);
#endif

    return 0;
}

static void extendControllerLegacyAdapters(lua_State* L)
{
    lua_getfield(L, LUA_REGISTRYINDEX, "cc.Controller");
    if (lua_istable(L, -1))
    {
        tolua_function(L, "receiveExternalKeyEvent", lua_cocos2dx_controller_Controller_receiveExternalKeyEvent);
        tolua_function(L, "getDeviceId", lua_cocos2dx_controller_Controller_getDeviceId);
        tolua_function(L, "getDeviceName", lua_cocos2dx_controller_Controller_getDeviceName);
        tolua_function(L, "getTag", lua_cocos2dx_controller_Controller_getTag);
        tolua_function(L, "isConnected", lua_cocos2dx_controller_Controller_isConnected);
        tolua_function(L, "setTag", lua_cocos2dx_controller_Controller_setTag);
    }
    lua_pop(L, 1);
    lua_getfield(L, LUA_REGISTRYINDEX, "cc.EventController");
    if (lua_istable(L, -1))
        tolua_function(L, "new", lua_cocos2dx_controller_EventController_constructor);
    lua_pop(L, 1);
}
#endif

int register_all_cocos2dx_controller_manual(lua_State* L)
{
    if (nullptr == L)
        return 0;

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
    extendControllerLegacyAdapters(L);
#endif
    extendEventListenerController(L);
    extendController(L);

    return 0;
}

// #endif //#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
