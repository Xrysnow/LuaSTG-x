#include "LuaBindings.h"
#include "../Classes/XLuaModuleRegistry.h"

#include "lua_BentLaser_auto.hpp"
LUA_REGISTER_MODULE(x_BentLaser, register_all_x_BentLaser);
#include "lua_RenderMode_auto.hpp"
LUA_REGISTER_MODULE(x_RenderMode, register_all_x_RenderMode);
#include "lua_Buffer_auto.hpp"
LUA_REGISTER_MODULE(x_Buffer, register_all_x_Buffer);
#include "lua_cc_fix.h"
LUA_REGISTER_MODULE(cc_ui_fix, register_all_cocos2dx_fix);
#include "lua_CCImage_manual.hpp"
LUA_REGISTER_MODULE(cc_Image_ext, register_all_cc_ext);
#include "lua_FileDialog_auto.hpp"
LUA_REGISTER_MODULE(x_FileDialog, register_all_x_FileDialog);
#include "lua_Latex_auto.hpp"
LUA_REGISTER_MODULE(x_Latex, register_all_x_Latex);
#include "lua_LogSystem_auto.hpp"
LUA_REGISTER_MODULE(x_LogSystem, register_all_x_LogSystem);
#include "lua_ObjSym_auto.hpp"
LUA_REGISTER_MODULE(x_ObjSym, register_all_x_ObjSym);
#include "lua_ParticlePool_auto.hpp"
LUA_REGISTER_MODULE(x_ParticlePool, register_all_x_ParticlePool);
#include "lua_Random_auto.hpp"
LUA_REGISTER_MODULE(x_Random, register_all_x_Random);
#include "lua_Resource_auto.hpp"
LUA_REGISTER_MODULE(x_Resource, register_all_x_Resource);
#include "lua_ResourceMgr_auto.hpp"
LUA_REGISTER_MODULE(x_ResourceMgr, register_all_x_ResourceMgr);
#include "lua_Stream_auto.hpp"
LUA_REGISTER_MODULE(x_Stream, register_all_x_Stream);
#include "lua_Triangles_auto.hpp"
LUA_REGISTER_MODULE(x_Triangles, register_all_x_Triangles);
#include "lua_WindowHelper_auto.hpp"
LUA_REGISTER_MODULE(x_WindowHelper, register_all_x_WindowHelper);

#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID) && (CC_TARGET_PLATFORM != CC_PLATFORM_IOS)
#include "lua_cc_controller_auto.hpp"
LUA_REGISTER_MODULE(cc_controller, register_all_cocos2dx_controller);
#include "lua_cc_controller_manual.hpp"
LUA_REGISTER_MODULE(cc_controller_manual, register_all_cocos2dx_controller_manual);
#endif
