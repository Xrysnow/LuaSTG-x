#include "AppFrame.h"
#include "Global.h"
#include "../Classes/XProfiler.h"
#include "../Classes/XLuaModuleRegistry.h"
#include "../Classes/XFileUtils.h"
#include "../Classes/XInfoware.h"
#include "../Classes/XAudioIO.h"
#include "cocos/audio/AudioEngine.h"
#include "input/gamepad/private/PlatformGamepadBackend.h"
#ifdef CC_ENABLE_VIDEO_TEXTURE
	#include "video/VideoCommon.h"
#endif
#ifndef LSTGX_NO_LIVE2D
	#include "../Live2D/L2DFramework.h"
#endif
#include "LuaWrapper/LuaWrapper.h"
#include "../LuaBindings/lua_TextInput_manual.hpp"
#include "Renderer.h"
#include "InputManager.h"
#include "WindowHelper.h"
#include "Util/Utility.h"
#include "Util/UtilLua.h"
#include "LogSystem.h"
#include "scripting/lua-bindings/manual/LuaEngine.h"
#include "scripting/lua-bindings/manual/lua_module_register.h"
#include <memory>
#include <iostream>

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "timeapi.h"
#ifdef LSTGX_HP_GPU
extern "C"
{
	// Prefer the higher performance GPU on Windows systems that use nvidia Optimus.
	// http://developer.download.nvidia.com/devzone/devcenter/gamegraphics/files/OptimusRenderingPolicies.pdf
	_declspec(dllexport) DWORD NvOptimusEnablement = 1;
	// Same with AMD GPUs.
	// https://community.amd.com/thread/169965
	_declspec(dllexport) DWORD AmdPowerXpressRequestHighPerformance = 1;
}
#endif
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

using namespace std;
using namespace lstg;
using namespace cc;

AppFrame* AppFrame::sharedInstance = nullptr;
std::vector<std::string> AppFrame::cmdLineArgs;
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
}

void AppFrame::destroyInstance()
{
	if (sharedInstance)
		CC_SAFE_DELETE(sharedInstance);
}

void AppFrame::setCmdLineArgs(const std::vector<std::string>& args)
{
	cmdLineArgs = args;
}

const char* AppFrame::getBuildDate()
{
	return __DATE__;
}

void AppFrame::initGLContextAttrs()
{
	// set OpenGL context attributes: red,green,blue,alpha,depth,stencil,msaa
	GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8, 0 };
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
#if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
	XFileUtils::start();
#endif
	// Install before any launch script can call the audio file factories.
	installAudioFileOpener();

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	if (!FileUtils::getInstance()->setWritablePath("./"))
	{
		ccMessageBox("Could not resolve the working directory for writable files.", "LuaSTG-x");
		return false;
	}
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
	const auto defaultWritablePath = FileUtils::getInstance()->getWritablePath();
	if (defaultWritablePath.empty())
	{
		ccMessageBox("The default writable directory is unavailable.", "LuaSTG-x");
		return false;
	}
	const auto wp = defaultWritablePath + "lstg/";
	if (FileUtils::getInstance()->isDirectoryExist(wp) &&
		!FileUtils::getInstance()->setWritablePath(wp))
	{
		ccMessageBox("Could not configure the writable directory.", "LuaSTG-x");
		return false;
	}
#elif CC_TARGET_PLATFORM == CC_PLATFORM_LINUX
#endif

	LLOGGER.setConsoleLevel(3);

	auto t = ::time(nullptr);
	char tmp[32];
	::strftime(tmp, sizeof(tmp), "%H:%M:%S", ::localtime(&t));
	LINFO("=== Application start at: %s ===", tmp);
	LINFO("Build date: %s", getBuildDate());
	LINFO("CPU name: %s", infoware::cpu::model_name().c_str());
	const auto mem_info = infoware::system::memory();
	constexpr uint64_t mem_factor = 1024 * 1024;
	LINFO("Memory: %ldMB / %ldMB", mem_info.physical_available / mem_factor, mem_info.physical_total / mem_factor);
	const auto os_info = infoware::system::os_info();
	LINFO("OS name: %s", os_info.full_name.c_str());

	// default FPS is set in lua
	//Director::getInstance()->setAnimationInterval(1.0 / 60.0f);

	// register lua module
	auto engine = LuaEngine::getInstance();
	auto stack = engine->getLuaStack();
	L = stack->getLuaState();
	if (!L)
	{
		LERROR("can't start Lua VM");
		return false;
	}
	LINFO("Lua VM version: %s", LUAJIT_VERSION);
	lua_module_register(L);
	LuaModuleRegistry::registerModules(L);
	LuaModuleRegistry::registerFunctions(L);
	register_all_packages();
#ifndef CC_VERSION
	stack->setXXTEAKeyAndSign("2dxLua", strlen("2dxLua"), "XXTEA", strlen("XXTEA"));
#endif // !CC_VERSION
	{
		lua_newtable(L);
		int i = 1;
		for (auto& arg : cmdLineArgs)
		{
			lua_pushlstring(L, arg.c_str(), arg.size());
			lua_rawseti(L, -2, i);
			++i;
		}
		lua_setglobal(L, "_ARGS");
	}

	InitGameObjectPropertyHash(L);
	CC_SAFE_DELETE(threadPool);
	// note: on android, this is usually the number of current activated cores
	const int nThr = std::thread::hardware_concurrency();
	threadPool = new ThreadPool(std::max(1, std::min(nThr - 1, 3)));
	if (nThr > 0)
	{
		LINFO("ThreadPool size: %d (core count: %d)", threadPool->size(), nThr);
	}
	else
	{
		LINFO("ThreadPool size: %d", threadPool->size());
	}

	auto FU = FileUtils::getInstance();

	const auto root = FU->getDefaultResourceRootPath();
	const string postfix = "Resources/";
	const auto pos = root.find(postfix);
	if (pos == root.size() - postfix.size())
		FU->setDefaultResourceRootPath(root.substr(0, pos));

	FU->addSearchPath("src");
	FU->addSearchPath("res");

#ifdef CC_VERSION
	engine->executeString(R"__(
cc = cc or {}
ccb = ccb or {}
ccui = ccui or {}
ccexp = ccexp or {}
)__");
#endif // CC_VERSION

	const auto fullPath = FU->fullPathForFilename(LLAUNCH_SCRIPT);
	const auto data = FU->getDataFromFile(fullPath);
	if(data.isNull())
	{
		XERROR("can't find launch script %s", LLAUNCH_SCRIPT);
		return false;
	}
	XINFO("\n    execute %s", fullPath.c_str());

	engine->executeScriptFile(LLAUNCH_SCRIPT);
	if (!Director::getInstance()->getOpenGLView())
	{
		XERROR("no view created");
		// this will give error message
		loadScript(LLAUNCH_SCRIPT);
		return false;
	}
	return true;
}

void AppFrame::applicationDidEnterBackground()
{
	//TODO: should be mutex to framefunc
	LuaEngine::getInstance()->executeGlobalFunction(LFUNC_LOSEFOCUS);
	AudioEngine::onEnterBackground();

	Director::getInstance()->stopAnimation();

	// note: clear keys
	InputManager::getInstance()->clearState();
}

void AppFrame::applicationWillEnterForeground()
{
	// note: pop message here may cause dead loop, make sure no error is thrown
	LuaEngine::getInstance()->executeGlobalFunction(LFUNC_GAINFOCUS);
	AudioEngine::onEnterForeground();
	Director::getInstance()->startAnimation();
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
		frameShutdown(true);
	}
	// Also covers launch failures before frameInit changed the status.
	clearAudioFileOpener();
	CC_SAFE_DELETE(threadPool);
}

void AppFrame::setFPS(uint32_t v)
{
	targetFPS = v;
	Director::getInstance()->setAnimationInterval(1.0 / v);
}

double AppFrame::getFPS()
{
	return Director::getInstance()->getFrameRate();
}

void AppFrame::loadScript(const std::string& path)
{
	string err;
	auto data = LRES.getFileData(path);
	if (!data)
	{
		err = string("can't load script [") + path + "]";
		LERROR("%s", err.c_str());
		luaL_error(L, err.c_str());
		return;
	}
	// LUA_MULTRET will return the result
	//if ((luaL_loadstring(L, s.c_str()) || lua_pcall(L, 0, LUA_MULTRET, 0)))
	const auto loadResult = luaL_loadbuffer(L, (const char*)data->data(), (size_t)data->size(), path.c_str());
	// Do not hold a C++ snapshot across Lua execution or luaL_error/longjmp.
	data.reset();
	if (loadResult || lua_pcall(L, 0, LUA_MULTRET, 0))
	{
		err = string("failed to compile [") + string(path) + "]:\n" + string(lua_tostring(L, -1));
		LERROR("%s", err.c_str());
		luaL_error(L, err.c_str());
	}
}

void AppFrame::snapShot(const std::string& path)
{
	utils::captureScreen(nullptr, path);
}

ThreadPool* AppFrame::getThreadPool()
{
	if (!threadPool)
		threadPool = new ThreadPool{ 0 };
	return threadPool;
}

bool AppFrame::frameInit()
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
		gameObjectPool = std::unique_ptr<GameObjectManager>(new GameObjectManager(L));
	}
	catch (const bad_alloc&)
	{
		LERROR("can't alloc GameObjectPool");
		return false;
	}

#ifdef CC_PLATFORM_PC
	WindowHelperDesktop::getInstance()->setTitle("LuaSTG-x");
#endif

	AudioEngine::setLoggingFunction([](const std::string& s)
	{
		LLOGGER.Log(LogType::Information, "%s", s.c_str());
	});
#ifdef CC_ENABLE_VIDEO_TEXTURE
	video::setLoggingFunction([](const std::string& s)
	{
		LLOGGER.Log(LogType::Information, "%s", s.c_str());
	});
#endif

	// audio engine
	cc::input::detail::primeGamepadAudioPolicy();
	if (!AudioEngine::init())
	{
		LERROR("Audio engine initialization failed: %s", AudioEngine::getLastError().c_str());
		//return false;
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
		frameShutdown(true);
	});
	e->addEventListenerWithFixedPriority(listener, 1);

	// profiler
	e->addCustomEventListener(Director::EVENT_BEFORE_UPDATE, [](EventCustom*) {
		XProfiler::getInstance()->tic(PF_Schedule);
	});
	e->addCustomEventListener(Director::EVENT_AFTER_UPDATE, [](EventCustom*) {
		XProfiler::getInstance()->toc(PF_Schedule);
	});
	e->addCustomEventListener(Director::EVENT_BEFORE_DRAW, [](EventCustom*) {
		XProfiler::getInstance()->tic(PF_Visit);
	});
	e->addCustomEventListener(Director::EVENT_AFTER_VISIT, [](EventCustom*) {
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
		InputManager::getInstance()->clearState();
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

void AppFrame::frameShutdown(bool fromNative)
{
	if (status == Status::NotInitialized || status == Status::Destroyed)
		return;
	if (fromNative)
	{
		LuaEngine::getInstance()->executeGlobalFunction("GameExit");
		// return if GameExit called this method
		if (status == Status::Destroyed)
			return;
	}

	resetLuaTextInput(L);
	XRenderer::end();

	gameObjectPool = nullptr;
	LINFO("clear GameObjectPool");

	LRES.clear();
	LINFO("clear all file resources");

	Resource::destroyInstances();
	LINFO("destroy all resources");

#ifndef LSTGX_NO_LIVE2D
	l2d::Framework::end();
#endif

	// note: must be after resources cleared
	AudioEngine::end();
	// The worker has stopped and resource cleanup can no longer open audio files.
	clearAudioFileOpener();

	InputManager::end();

	status = Status::Destroyed;
	LINFO("cleared successfully");
}

bool AppFrame::frameReset()
{
	status = Status::Initializing;
	resetLuaTextInput(L);

	gameObjectPool->ResetPool();
	LINFO("clear GameObjectPool");

	L = LuaEngine::getInstance()->getLuaStack()->getLuaState();
	gameObjectPool->ResetLua(L);
	RenderMode::clearModes();
	AudioEngine::stop();
	InputManager::getInstance()->clearState();
	LRES.clearLocalFileCache();
	LMP.clear();
	status = Status::Initialized;
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

namespace
{
LONGLONG performanceTicks()
{
	LARGE_INTEGER ticks;
	QueryPerformanceCounter(&ticks);
	return ticks.QuadPart;
}

class Win32FramePacer
{
public:
	explicit Win32FramePacer(LONGLONG frequency) : _frequency(frequency) {}

	bool beforePoll(LONGLONG interval, bool previousFrameDrawn)
	{
		auto now = performanceTicks();
		if (interval <= 0 || !previousFrameDrawn || interval != _interval)
		{
			_interval = interval;
			_deadline = now + interval;
			return false;
		}
		const bool late = now > _deadline;
		if (!late)
		{
			const auto remainingMs = (_deadline - now) * 1000 / _frequency;
			if (remainingMs > 1)
				Sleep(static_cast<DWORD>(remainingMs - 1));
			while ((now = performanceTicks()) < _deadline)
				YieldProcessor();
		}
		_deadline += interval;
		if (_deadline <= now)
			_deadline = now + interval;
		return late;
	}

private:
	LONGLONG _frequency;
	LONGLONG _interval = 0;
	LONGLONG _deadline = 0;
};
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
		if (timeBeginPeriod(wTimerRes) != TIMERR_NOERROR)
			wTimerRes = 0;
	}
	initGLContextAttrs();
	if (!applicationDidFinishLaunching())
	{
		if (wTimerRes)
			timeEndPeriod(wTimerRes);
		return 1;
	}

	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	glview->retain();
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	Win32FramePacer pacer(freq.QuadPart);
	bool drewFrame = false;
	auto e = director->getEventDispatcher();
	const auto listener = EventListenerCustom::create(Director::EVENT_AFTER_DRAW, [&](EventCustom*) {
		drewFrame = true;
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
		if (pacer.beforePoll(_animationInterval.QuadPart, drewFrame))
			++dropCounter;
		drewFrame = false;
		XProfiler::getInstance()->tic("pullEvents");
		director->mainLoop();

		if (!glview->windowShouldClose() && !director->isValid())
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
#endif
