#pragma once
#include "Global.h"
#include "XThreadPool.hpp"
#include "Object/GameObjectManager.h"

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
		static AppFrame* sharedInstance;
		static std::vector<std::string> cmdLineArgs;
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

		Status status = Status::NotInitialized;
		lua_State* L = nullptr;
		ThreadPool* threadPool = nullptr;
		std::unique_ptr<GameObjectManager> gameObjectPool;

		double targetFPS = 0.0;
		uint32_t dropCounter = 0;

	public:

		static const std::string PF_Schedule;
		static const std::string PF_Visit;
		static const std::string PF_Render;
		static const std::string PF_BeginScene;
		static const std::string PF_EndScene;
		
		static AppFrame* getInstance();
		static void destroyInstance();
		static void setCmdLineArgs(const std::vector<std::string>& args);
		static const char* getBuildDate();

		void initGLContextAttrs() override;

		bool applicationDidFinishLaunching() override;
		void applicationDidEnterBackground() override;
		void applicationWillEnterForeground() override;

		void setFPS(uint32_t v) noexcept;
		double getTargetFPS() const noexcept { return targetFPS; }
		double getFPS() noexcept;

		void loadScript(const std::string& path) noexcept;
		void snapShot(const std::string& path) noexcept;

		GameObjectManager& getGameObjectPool() const noexcept { return *gameObjectPool; }
		ThreadPool* getThreadPool() noexcept;

		uint32_t getDropCounter() const { return dropCounter; }
		void setDropCounter(uint32_t v) { dropCounter = v; }

		bool frameInit() noexcept;
		void frameShutdown() noexcept;
		bool frameReset() noexcept;
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
