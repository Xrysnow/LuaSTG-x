#include "AppFrame.h"
#include "Global.h"
#include "scripting/lua-bindings/manual/CCLuaEngine.h"
#include "scripting/lua-bindings/manual/lua_module_register.h"
#include "XFileUtils.h"
#include "Utility.h"
#include "LuaWrapper.h"
#include "LuaWrapperEx.h"
#include "../Audio/AudioEngine.h"
#include "../Classes/XProfiler.h"
#include "platform/CCGL.h"
#include "reader/lua-bindings/creator_reader_bindings.hpp"
#include "Renderer.h"
#include "InputManager.h"
#include "WindowHelper.h"
#include <memory>
#include "XLive2D.h"
#include "lua_x_L2D_auto.hpp"
#include "../LuaBindings/lua_Resource_auto.hpp"
#include "../LuaBindings/lua_BlendMode_auto.hpp"
#include "../LuaBindings/lua_LogSystem_auto.hpp"
#include "../LuaBindings/lua_BentLaser_auto.hpp"
#include "../LuaBindings/lua_Random_auto.hpp"
#include "../LuaBindings/lua_ObjSym_auto.hpp"
#include "../LuaBindings/lua_WindowHelper_auto.hpp"
#include "../LuaBindings/lua_FileDialog_auto.hpp"
#include "../LuaBindings/lua_ParticlePool_auto.hpp"
#include "../LuaBindings/lua_ResourceMgr_auto.hpp"
#include "../LuaBindings/lua_XTriangles_auto.hpp"
#include "../LuaBindings/lua_cc_ui_fix.h"
#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID) && (CC_TARGET_PLATFORM != CC_PLATFORM_IOS)
#include "../LuaBindings/lua_cc_controller_auto.hpp"
#include "../LuaBindings/lua_cc_controller_manual.hpp"
#endif
#include "UtilLua.h"
#include <iostream>

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "../../proj.win32/SimulatorWin.h"
#include "../../proj.win32/WindowHelperWin32.h"
#endif

#ifdef max
#undef max
#endif
#ifdef min
#undef min
#endif

#ifdef LERROR
#undef LERROR
#define LERROR(info, ...) LLOGGER.Log(lstg::LogType::Error, "[APP] " info, ##__VA_ARGS__)
#endif
#ifdef LWARNING
#undef LWARNING
#define LWARNING(info, ...) LLOGGER.Log(lstg::LogType::Warning, "[APP] " info, ##__VA_ARGS__)
#endif
#ifdef LINFO
#undef LINFO
#define LINFO(info, ...) LLOGGER.Log(lstg::LogType::Information, "[APP] " info, ##__VA_ARGS__)
#endif

// 内置lua扩展
extern "C" int luaopen_lfs(lua_State *L);

using namespace std;
using namespace lstg;
using namespace cocos2d;

AppFrame* AppFrame::sharedInstance = nullptr;
const string AppFrame::PF_Schedule = "AppFrame::PF_Schedule";
const string AppFrame::PF_Visit = "AppFrame::PF_Visit";
const string AppFrame::PF_Render = "AppFrame::PF_Render";
const string AppFrame::PF_BeginScene = "AppFrame::PF_BeginScene";
const string AppFrame::PF_EndScene = "AppFrame::PF_EndScene";

AppFrame* AppFrame::getInstance()
{
	if (sharedInstance == nullptr)
		sharedInstance = new AppFrame();
	return sharedInstance;
	//static AppFrame s_Instance;
	//return &s_Instance;
}

void AppFrame::destroyInstance()
{
	if(sharedInstance)
		CC_SAFE_DELETE(sharedInstance);
}

void AppFrame::initGLContextAttrs()
{
	// set OpenGL context attributes: red,green,blue,alpha,depth,stencil,msaa
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8, 0 };//TODO: AALevel
	GLView::setGLContextAttrs(glContextAttrs);
}
// if you want to use the package manager to install more packages, 
// don't modify or remove this function
static int register_all_packages()
{
	return 0; //flag for packages manager
}
bool AppFrame::applicationDidFinishLaunching()
{
	auto t = ::time(nullptr);
	char tmp[32];
	::strftime(tmp, sizeof(tmp), "%H:%M:%S", ::localtime(&t));
	LINFO("=== AppFrame start at: %s ===", tmp);
	// default FPS is set in lua
	//Director::getInstance()->setAnimationInterval(1.0 / 60.0f);
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	XFileUtils::start();
#endif
	// register lua module
	auto engine = LuaEngine::getInstance();
	auto stack = engine->getLuaStack();
	L = stack->getLuaState();
	if (!L)
	{
		LERROR("can't start Lua VM");
		return false;
	}
	LINFO("Lua VM version: %s", LVERSION_LUA);
	lua_module_register(L);

#if (CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID) && (CC_TARGET_PLATFORM != CC_PLATFORM_IOS)
	register_all_cocos2dx_controller(L);
	register_all_cocos2dx_controller_manual(L);
#endif

	register_creator_reader_module(L);
	register_all_x_BlendMode(L);
	register_all_x_LogSystem(L);
	register_all_x_Resource(L);
	register_all_x_ParticlePool(L);
	register_all_x_L2D(L);
	register_all_x_BentLaser(L);
	register_all_x_Random(L);
	register_all_x_ObjSym(L);
	register_all_x_WindowHelper(L);
	register_all_x_FileDialog(L);
	register_all_x_ResourceMgr(L);
	register_all_x_XTriangles(L);
	register_all_cocos2dx_ui_fix(L);

	register_all_packages();
	stack->setXXTEAKeyAndSign("2dxLua", strlen("2dxLua"), "XXTEA", strlen("XXTEA"));
	luaopen_lfs(L);
	RegistWrapper(L);

	InitGameObjectPropertyHash();
	CC_SAFE_DELETE(threadPool);
	// note: on android, this is the number of currently activated cores
	const int nThr = std::thread::hardware_concurrency();
	threadPool = new XThreadPool(std::max(1, std::min(nThr - 1, 3)));
	if (nThr > 0)
	{
		LINFO("ThreadPool size: %d (core count: %d)", threadPool->size(), nThr);
	}
	else
	{
		LINFO("ThreadPool size: %d", threadPool->size());
	}

	auto FU = FileUtils::getInstance();
	FU->addSearchPath("src");
	FU->addSearchPath("res");
//#if CC_64BITS
//	FU->addSearchPath("src/64bit");
//#endif
	engine->executeScriptFile("main.lua");
	return true;
}

void AppFrame::applicationDidEnterBackground()
{
	//TODO: should be mutex to framefunc
	LuaEngine::getInstance()->executeGlobalFunction(LFUNC_LOSEFOCUS);
	XAudioEngine::pauseTemp();
	Director::getInstance()->stopAnimation();

	// note: clear keys
	InputManager::getInstance()->clearState();
}

void AppFrame::applicationWillEnterForeground()
{
	LuaEngine::getInstance()->executeGlobalFunction(LFUNC_GAINFOCUS);
	XAudioEngine::resumeTemp();
	Director::getInstance()->startAnimation();
	// note: pop message here will cause forever loop
	//if (!SafeCallGlobalFunction(LFUNC_GAINFOCUS))
	//	LERROR("AppFrame: call LFUNC_GAINFOCUS failed");
}

AppFrame::AppFrame()
{
	// LuaEngine
	auto engine = LuaEngine::getInstance();
	ScriptEngineManager::getInstance()->setScriptEngine(engine);
#if CC_TARGET_PLATFORM != CC_PLATFORM_ANDROID
	XFileUtils::start();
#endif
}

AppFrame::~AppFrame()
{
	if (status != Status::NotInitialized && status != Status::Destroyed)
	{
		Shutdown();
	}
	CC_SAFE_DELETE(threadPool);
}

void AppFrame::ShowSplashWindow(const char* imgPath)noexcept
{
	if (status == Status::Initializing)
	{
#ifdef CC_PLATFORM_PC
		//TODO:
#endif
		optSplashWindow = true;
	}
	else
		LWARNING("ShowSplashWindow: can't load at this moment");
}

void AppFrame::setFPS(uint32_t v) noexcept
{
	targetFPS = v;
	Director::getInstance()->setAnimationInterval(1.0 / v);
}

double AppFrame::getFPS() noexcept
{
	// TODO: Smooth
	return Director::getInstance()->getFrameRate();
}

void AppFrame::loadScript(const char* path)noexcept
{
	string err;
	auto data = LRES.getBufferFromFile(path);
	if (!data)
	{
		err = string("can't load script [") + path + "]";
		LERROR("%s", err.c_str());
		luaL_error(L, err.c_str());
		return;
	}
	// LUA_MULTRET will return the result
	//if ((luaL_loadstring(L, s.c_str()) || lua_pcall(L, 0, LUA_MULTRET, 0)))
	if (luaL_loadbuffer(L, (const char*)data->data(), (size_t)data->size(), luaL_checkstring(L, 1))
		|| lua_pcall(L, 0, LUA_MULTRET, 0))
	{
		err = string("failed to compile [") + string(path) + "]:\n" + string(lua_tostring(L, -1));
		LERROR("%s", err.c_str());
		luaL_error(L, err.c_str());
	}
}

void AppFrame::snapShot(const char* path)noexcept
{
	utils::captureScreen(nullptr, path);//TODO: CHECK
}

XThreadPool* AppFrame::GetThreadPool() noexcept
{
	if (!threadPool)
		threadPool = new XThreadPool{ 0 };
	return threadPool;
}

bool AppFrame::Init()noexcept
{
	if (status != Status::NotInitialized)
	{
		LERROR("AppFrame has been initialized");
		CCASSERT(false, "");
		return false;
	}
	status = Status::Initializing;

	// GameObjectPool
	LINFO("initializing GameObjectPool (%u)", LGOBJ_MAXCNT);
	try
	{
		gameObjectPool = make_unique<GameObjectManager>(L);
	}
	catch (const bad_alloc&)
	{
		LERROR("can't alloc GameObjectPool");
		return false;
	}

	const auto wHelper = WindowHelper::getInstance();
	//TODO: Mac & Linux
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	FileUtils::getInstance()->setWritablePath("./");
	auto winhelper = (WindowHelperWin32*)wHelper;
	winhelper->SetHideIME(true);
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
#endif
#ifdef CC_PLATFORM_PC
	WindowHelperDesktop::getInstance()->setTitle("LuaSTG-x");
#endif

	// configuration info
	//LINFO("Cocos2dx Configuration Info:%s", Configuration::getInstance()->getInfo().c_str());

	// audio engine
	if (!XAudioEngine::lazyInit())
	{
		LERROR("AudioEngine initialization failed");
		return false;
	}

	auto director = Director::getInstance();
	auto glv = director->getOpenGLView();
	if (!glv)
	{
		LERROR("OpenGLView not initialized");
		return false;
	}

	if (!XRenderer::init())
	{
		LERROR("Renderer initialization failed");
		return false;
	}

	if (!InputManager::init())
	{
		LERROR("InputManager initialization failed");
		return false;
	}

	// events

	auto e = director->getEventDispatcher();
	// note: Shutdown must be called before Director::end is called.
	// EVENT_RESET will be sent in Director::end.
	auto listener = EventListenerCustom::create(Director::EVENT_RESET, [this](EventCustom* event)
	{
		Shutdown();
	});
	e->addEventListenerWithFixedPriority(listener, 1);

	// profiler
	e->addCustomEventListener(Director::EVENT_BEFORE_UPDATE, [](EventCustom*) {
		XProfiler::getInstance()->tic(PF_Schedule);
	});
	e->addCustomEventListener(Director::EVENT_AFTER_UPDATE, [](EventCustom*) {
		XProfiler::getInstance()->toc(PF_Schedule);
		XProfiler::getInstance()->tic(PF_Visit);
	});
	e->addCustomEventListener(Director::EVENT_BEFORE_DRAW, [](EventCustom*) {
		XProfiler::getInstance()->toc(PF_Visit);
		XProfiler::getInstance()->tic(PF_Render);
	});
	e->addCustomEventListener(Director::EVENT_AFTER_DRAW, [](EventCustom*) {
		XProfiler::getInstance()->toc(PF_Render);
	});

	// focus callback
#ifdef CC_PLATFORM_PC
	e->addCustomEventListener(GLViewImpl::EVENT_WINDOW_FOCUSED, [](EventCustom*) {
		LuaEngine::getInstance()->executeGlobalFunction(LFUNC_GAINFOCUS);
	});
	e->addCustomEventListener(GLViewImpl::EVENT_WINDOW_UNFOCUSED, [](EventCustom*) {
		LuaEngine::getInstance()->executeGlobalFunction(LFUNC_LOSEFOCUS);
	});

	//e->addCustomEventListener(GLViewImpl::EVENT_WINDOW_RESIZED, [](EventCustom*) {
	//	LINFO("glview_window_resized");
	//});
#endif

	status = Status::Initialized;
	LINFO("initialized successfully");
	return true;
}

void AppFrame::Shutdown()noexcept
{
	if (status == Status::NotInitialized || status == Status::Destroyed)
		return;
	
	XRenderer::end();

	gameObjectPool = nullptr;
	LINFO("clear GameObjectPool");

	LRES.clear();
	LINFO("clear all resources");

	LRES.unloadAllResourcePacks();
	LINFO("unload all packs");

	l2d::XLive2D::end();

	// note: XAudioEngine::end must be called after ClearAllResource
	XAudioEngine::end();

	InputManager::end();

	status = Status::Destroyed;
	LINFO("cleared successfully");
}

bool AppFrame::Reset()noexcept
{
	status = Status::Initializing;

	gameObjectPool->ResetPool();
	LINFO("clear GameObjectPool");

	L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	gameObjectPool->ResetLua(L);
	XAudioEngine::stopAll();
	InputManager::getInstance()->clearState();

	LRES.clearLocalFileCache();

	status = Status::NotInitialized;
	LuaEngine::getInstance()->executeScriptFile("main.lua");
	LINFO("reset successfully");
	return true;
}

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
static void PVRFrameEnableControlWindow(bool bEnable)
{
	HKEY hKey = 0;

	// Open PVRFrame control key, if not exist create it.
	if (ERROR_SUCCESS != RegCreateKeyExW(HKEY_CURRENT_USER,
		L"Software\\Imagination Technologies\\PVRVFRame\\STARTUP\\",
		0,
		0,
		REG_OPTION_NON_VOLATILE,
		KEY_ALL_ACCESS,
		0,
		&hKey,
		nullptr))
	{
		return;
	}

	const WCHAR* wszValue = L"hide_gui";
	const WCHAR* wszNewData = (bEnable) ? L"NO" : L"YES";
	WCHAR wszOldData[256] = { 0 };
	DWORD   dwSize = sizeof(wszOldData);
	LSTATUS status = RegQueryValueExW(hKey, wszValue, 0, nullptr, (LPBYTE)wszOldData, &dwSize);
	if (ERROR_FILE_NOT_FOUND == status              // the key not exist
		|| (ERROR_SUCCESS == status                 // or the hide_gui value is exist
			&& 0 != wcscmp(wszNewData, wszOldData)))    // but new data and old data not equal
	{
		dwSize = sizeof(WCHAR) * (wcslen(wszNewData) + 1);
		RegSetValueEx(hKey, wszValue, 0, REG_SZ, (const BYTE *)wszNewData, dwSize);
	}

	RegCloseKey(hKey);
}

int AppFrame::run()
{
	PVRFrameEnableControlWindow(false);
	// highest priority
	SetThreadPriority(GetCurrentThread(), THREAD_PRIORITY_TIME_CRITICAL);
	UINT TARGET_RESOLUTION = 1; // 1 ms target resolution
	TIMECAPS tc;
	UINT wTimerRes = 0;
	if (TIMERR_NOERROR == timeGetDevCaps(&tc, sizeof(TIMECAPS)))
	{
		wTimerRes = std::min(std::max(tc.wPeriodMin, TARGET_RESOLUTION), tc.wPeriodMax);
		timeBeginPeriod(wTimerRes);
	}
	LARGE_INTEGER nLast;
	LARGE_INTEGER nNow;
	QueryPerformanceCounter(&nLast);
	initGLContextAttrs();
	if (!applicationDidFinishLaunching())
	{
		return 1;
	}

	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	glview->retain();
	LONG waitMS = 0L;
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	//uint32_t timer = 0;
	//double pe_t1 = 0;
	fcyStopWatch sw, sw2;
	LONGLONG sleep_skip = 0LL;
	auto hdc = wglGetCurrentDC();

	auto e = director->getEventDispatcher();
	const auto listener = EventListenerCustom::create(Director::EVENT_AFTER_DRAW, [&](EventCustom* event)
	{
		// there will be strange frame drop on screen without this, although frame time is steady
		glFinish();

		//if (glview->windowShouldClose())
		//	return;

		//const auto waitMS_max = _animationInterval.QuadPart * 1000LL / freq.QuadPart;
		//LINFO("waitMS_max = %d, _animationInterval = %d", waitMS_max, _animationInterval.QuadPart);
		QueryPerformanceCounter(&nNow);
		LONGLONG interval = nNow.QuadPart - nLast.QuadPart;
		const auto delta = interval - _animationInterval.QuadPart;
		if (delta < 0LL)
		{
			const auto last = nLast.QuadPart + sleep_skip;
			waitMS = (-delta - sleep_skip) * 1000LL / freq.QuadPart - 1L;
			if (waitMS > 1L)
				Sleep(waitMS);
			//if (sleep_skip > 0LL)
			//{
			//	LINFO("skip %f, slept %d", double(sleep_skip) / freq.QuadPart * 1000, waitMS);
			//}
			sleep_skip = 0LL;

			QueryPerformanceCounter(&nNow);
			interval = nNow.QuadPart - last;
			// note: interval may overflow sometime
			if (interval < _animationInterval.QuadPart && interval > 0)
			{
				while (interval < _animationInterval.QuadPart)
				{
					QueryPerformanceCounter(&nNow);
					interval = nNow.QuadPart - last;
				}
			}
			nLast.QuadPart = nNow.QuadPart;
			//else
			//{
			//	double got = double(interval) / freq.QuadPart * 1000;
			//	double target = double(_animationInterval.QuadPart) / freq.QuadPart * 1000;
			//	LINFO("oversleep %d, t: %d, %f / %f", timer, waitMS, got, target);
			//}
		}
		else
		{
			sleep_skip = delta;
			//if (double(delta) / freq.QuadPart > 2e-3)
			//{
			//	auto times = XProfiler::getInstance()->getAllLast();
			//	string inf = "\n";
			//	for(auto& it : times)
			//	{
			//		inf += StringUtils::format("%s = %.2f\n", it.first.c_str(), it.second * 1000);
			//	}
			//	LINFO("%s", inf.c_str());
			//}
			dropCounter++;
			QueryPerformanceCounter(&nNow);
			nLast.QuadPart = nNow.QuadPart;
		}

		wglSwapLayerBuffers(hdc, WGL_SWAP_MAIN_PLANE);
		// Sleep here to make swapbuffer steady?
		//Sleep(1);
	});
	e->addEventListenerWithFixedPriority(listener, 9);
	const auto listener2 = EventListenerCustom::create(
		Director::EVENT_BEFORE_UPDATE, [&](EventCustom* event)
	{
		XProfiler::getInstance()->toc("pullEvents");
	});
	e->addEventListenerWithFixedPriority(listener2, 1);
	// TODO: why glfwPollEvents become slow sometimes?

	while (!glview->windowShouldClose())
	{
		XProfiler::getInstance()->tic("pullEvents");
		director->mainLoop();

		if (!director->isValid())
		{
			glview->pollEvents();
		}
	}
	if (glview->isOpenGLReady())
	{
		director->end();
		director->mainLoop();
		director = nullptr;
	}
	glview->release();
	if (wTimerRes != 0)
	{
		timeEndPeriod(wTimerRes);
	}
	return 0;
}
//#else
//int AppFrame::run()
//{
//	return Application::run();
//}
#endif
