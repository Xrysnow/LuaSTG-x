#pragma once
#include "Global.h"
#include "GameObjectManager.h"
#include "MemPoolManager.h"
#include "XThreadPool.hpp"

// LSTG AppFrame
#define LAPP (*lstg::AppFrame::getInstance())
// LSTG GameObjectPool
#define LPOOL (LAPP.getGameObjectPool())
// LSTG ThreadPool
#define LTHP (*LAPP.getThreadPool())

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

		ThreadPool* threadPool = nullptr;

	public:
		void ShowSplashWindow(const char* imgPath = nullptr)noexcept; //TODO: remove?

		void setFPS(uint32_t v)noexcept;
		double getTargetFPS() const noexcept { return targetFPS; }
		double getFPS() noexcept;

		void loadScript(const char* path)noexcept;

		void snapShot(const char* path)noexcept;
	public:
		GameObjectManager& getGameObjectPool() const noexcept { return *gameObjectPool; }
		ThreadPool* getThreadPool() noexcept;

		uint32_t getDropCounter() const { return dropCounter; }
		void setDropCounter(uint32_t v) { dropCounter = v; }

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
