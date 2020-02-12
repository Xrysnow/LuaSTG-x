#include "LuaWrapperEx.h"
#include "Global.h"
#include "AppFrame.h"
#include "LuaWrapper.h"
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "platform/win32/CCUtils-win32.h"
#define UTF8ToMB cocos2d::UTF8StringToMultiByte
#else
#define UTF8ToMB(s) s 
#endif
#include "../Video/SpriteVideo.h"
#include "Renderer.h"
#include "../fcyLib/fcyMisc/fcyStopWatch.h"
#include "../Classes/XLuaModuleRegistry.h"

#ifdef MessageBox
#undef MessageBox
#endif

using namespace std;
using namespace lstg;

#pragma warning( disable : 4244 )

LUA_REGISTER_MODULE_DEF(lstg_ex)
{
	static fcyStopWatch sw0;
	static fcyStopWatch sw;

	struct WrapperImpl
	{
		static int QueryTimeMS(lua_State* L)noexcept
		{
			lua_pushnumber(L, sw0.GetElapsed() * 1000);
			return 1;
		}
		static int Tic(lua_State* L)noexcept
		{
			lua_pushnumber(L, sw.GetElapsed() * 1000);
			sw.Reset();
			return 1;
		}
		static int SetFactor(lua_State* L)noexcept
		{
			//LRR.SetFactor(luaL_checknumber(L, 1));
			return 0;
		}
		static int SetAALevel(lua_State* L)noexcept
		{
			LRR.setAALevel(luaL_checkinteger(L, 1));
			return 0;
		}
		static int SetUseFrameBuffer(lua_State* L)noexcept
		{
			LRR.setUseFrameBuffer(lua_toboolean(L, 1) != 0);
			return 0;
		}
		static int UTF8ToMultiByte(lua_State* L)noexcept
		{
			// only process on windows
			string s = luaL_checkstring(L, 1);
			lua_pushstring(L, UTF8ToMB(s).c_str());
			return 1;
		}
		static int MessageBox(lua_State* L)noexcept
		{
			cocos2d::ccMessageBox(luaL_checkstring(L, 1), luaL_checkstring(L, 2));
			return 0;
		}
		static int GetOSName(lua_State* L)noexcept
		{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
			lua_pushstring(L, "windows");
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
			lua_pushstring(L, "mac");
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
			lua_pushstring(L, "linux");
#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
			lua_pushstring(L, "android");
#elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
			lua_pushstring(L, "ios");
#else
			lua_pushstring(L, "others");
#endif
			return 1;
		}
		//////////////////////////////////////////////
		static int OnExit(lua_State* L)noexcept
		{
			LAPP.Shutdown();
			// crash, because it's already ended
//			Director::getInstance()->end();
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//			exit(0);
//#endif
			return 0;
		}
		static int Reset(lua_State* L)noexcept
		{
			LAPP.Reset();
			return 0;
		}
		static int Test(lua_State* L)noexcept
		{
			auto s = xVideo::SpriteVideo::create(luaL_checkstring(L, 1),1280,548);
			if (s)
			{
				cocos2d::Director::getInstance()->getRunningScene()->addChild(s);
				//s->setPlayMode();
				s->vplay();
				auto size = s->getContentSize();
				s->setPosition(cocos2d::Vec2(size.width, size.height) / 2);
				//s->setScale(0.25);
				LINFO("test started");
			}
			else
			{
				LINFO("test failed");
			}
			return 0;
		}
	};
	luaL_Reg tFunctions[] = {
		{ "QueryTimeMS", &WrapperImpl::QueryTimeMS },
		{ "Tic", &WrapperImpl::Tic },
		{ "SetFactor", &WrapperImpl::SetFactor },
		{ "SetAALevel", &WrapperImpl::SetAALevel },
		{ "SetUseFrameBuffer", &WrapperImpl::SetUseFrameBuffer },
		{ "UTF8ToMultiByte", &WrapperImpl::UTF8ToMultiByte },
		{ "MessageBox", &WrapperImpl::MessageBox },
		{ "GetOSName", &WrapperImpl::GetOSName },
		{ "OnExit", &WrapperImpl::OnExit },
		//{ "Reset", &WrapperImplement::Reset },

		//{ "Test", &WrapperImpl::Test },
		{ nullptr, nullptr }
	};
	luaL_register(L, "ex", tFunctions);
	lua_pop(L, 1);
	return 0;
}
