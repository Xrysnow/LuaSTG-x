#pragma once
#include "Global.h"
#include "ResourceMgr.h"
#include "GameObjectManager.h"
#include "MemPoolManager.h"
#include "XThreadPool.hpp"

// LSTG AppFrame
#define LAPP (*lstg::AppFrame::getInstance())
// LSTG GameObjectPool
#define LPOOL (LAPP.GetGameObjectPool())
// LSTG ThreadPool
#define LTHP (*LAPP.GetThreadPool())

namespace lstg
{
	// main frame
	class AppFrame :
		public cocos2d::Application
	{
	private:
		static AppFrame* sharedInstance;
		// inner status
		enum class Status
		{
			NotInitialized,
			Initializing,
			Initialized,
			Running,
			Aborted,
			Destroyed
		};
	public:
		static AppFrame* getInstance();
		static void destroyInstance();

		void initGLContextAttrs() override;

		bool applicationDidFinishLaunching() override;
		void applicationDidEnterBackground() override;
		void applicationWillEnterForeground() override;

		static const std::string PF_Schedule;
		static const std::string PF_Visit;
		static const std::string PF_Render;
		static const std::string PF_BeginScene;
		static const std::string PF_EndScene;
	private:
		Status status = Status::NotInitialized;

		std::unique_ptr<GameObjectManager> gameObjectPool;
		lua_State* L = nullptr;

		bool optSplashWindow = false;
		double targetFPS = 0.;
		uint32_t dropCounter = 0;

		XThreadPool* threadPool = nullptr;

	public:
		void SetWindowed(bool v)noexcept;
		void ShowSplashWindow(const char* imgPath = nullptr)noexcept; //TODO: remove?

		void SetFPS(uint32_t v)noexcept;
		double GetTargetFPS() const noexcept { return targetFPS; }
		double GetFPS() noexcept;

		void LoadScript(const char* path)noexcept;

		void SnapShot(const char* path)noexcept;
	public:
		GameObjectManager& GetGameObjectPool() const noexcept { return *gameObjectPool; }
		XThreadPool* GetThreadPool() const noexcept { return threadPool; }

		uint32_t GetDropCounter() const { return dropCounter; }
		void SetDropCounter(uint32_t v) { dropCounter = v; }

		bool Init()noexcept;
		void Shutdown()noexcept;
		bool Reset()noexcept;
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
		int run() override;
#endif

	private:
		AppFrame();
	public:
		~AppFrame();
	};
}

using AppDelegate = lstg::AppFrame;
