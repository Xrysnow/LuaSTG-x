#pragma once
#include "cocos2d.h"

namespace lstg
{
	class WindowHelper
	{
	public:
		enum Operation
		{
			SHOW,
			HIDE,
			FOCUS,	
			ICONIFY,
			RESTORE,
			MAXIMIZE
		};
		enum CursorType
		{
			ARROW,
			IBEAM,
			CROSSHAIR,
			HAND,
			HRESIZE,
			VRESIZE,
			CUSTOM
		};

		virtual ~WindowHelper() = default;
		static WindowHelper* getInstance();

		virtual void setVsync(bool b) {}
		virtual bool isVsync() { return true; }

		virtual void operate(Operation op) {}

		virtual void setClipboardString(const std::string& s) {}
		virtual std::string getClipboardString() { return {}; }

		virtual void hint(int hint, int value) {}
		virtual void resetHint() {}

		virtual void setTitle(const std::string& s) {}
		virtual std::string getTitle() { return {}; }

		virtual void setPosition(const cocos2d::Vec2& p) {}
		virtual cocos2d::Vec2 getPosition() { return {}; }

		virtual void setVisible(bool b) {}
		virtual bool isVisible() { return false; }

		virtual void setCursorVisible(bool b) {}
		virtual bool isCursorVisible() { return false; }

		virtual void setSize(const cocos2d::Size& size) {}
		virtual cocos2d::Size getSize() { return {}; }

		virtual void setFullscreen() {}
		virtual bool isFullscreen() { return false; }

		virtual void moveToCenter() {}

		virtual void setCustomCursor(const std::string& filename, const cocos2d::Vec2& hotspot) {}
		virtual void setDefaultCursor() {}
		virtual void setStandardCursor(CursorType type) {}

		virtual float getDpiScale() { return 1.0f; }

		virtual cocos2d::Vec2 getDisplayResolution() {
			return cocos2d::Vec2{};
		}

		virtual std::vector<cocos2d::Vec2> enumDisplayResolution() {
			return std::vector<cocos2d::Vec2>{};
		}

		virtual void setImeEnabled(bool enable) {}
		virtual bool isImeEnabled() { return false; }
	protected:
		std::string title;
		bool visible = true;
		bool cursorVisible = true;
		bool vsync = true;
		float gamma = 0.f;

		WindowHelper() = default;
	};
#ifdef CC_PLATFORM_PC
	class WindowHelperDesktop : public WindowHelper
	{
	public:
		explicit WindowHelperDesktop(cocos2d::GLViewImpl* view);
		struct VideoMode
		{
			int width = 0;
			int height = 0;
			bool windowed = true;
			bool vsync = true;
			VideoMode(int w, int h, bool windowed_, bool vsync_)
			:width(w), height(h), windowed(windowed_), vsync(vsync_)
			{
			}
		};

		static WindowHelperDesktop* getInstance();

		void setTitle(const std::string& s) override;
		std::string getTitle() override;

		void setPosition(const cocos2d::Vec2& p) override;
		cocos2d::Vec2 getPosition() override;

		void setVisible(bool b) override;
		bool isVisible() override;

		void setCursorVisible(bool b) override;
		bool isCursorVisible() override;

		void setSize(const cocos2d::Size& size) override;
		cocos2d::Size getSize() override;

		void setFullscreen() override;
		bool isFullscreen() override;

		void setVsync(bool b) override;
		bool isVsync() override;

		void setVideoMode(VideoMode v);
		VideoMode getVideoMode();

		void moveToCenter() override;

		void operate(Operation op) override;

		void setClipboardString(const std::string& s) override;
		std::string getClipboardString() override;

		void hint(int hint, int value) override;
		void resetHint() override;

		void setCustomCursor(const std::string& filename, const cocos2d::Vec2& hotspot) override;
		void setDefaultCursor() override;
		void setStandardCursor(CursorType type) override;

		float getDpiScale() override;

		cocos2d::Vec2 getDisplayResolution() override;
		std::vector<cocos2d::Vec2> enumDisplayResolution() override;

		void setImeEnabled(bool enabled) override;
		bool isImeEnabled() override;
	protected:
		// it's better to get window dynamicly
		GLFWwindow* getWindow();

		cocos2d::GLViewImpl* view;
		CursorType curType = ARROW;
		GLFWcursor* cur_cunstom = nullptr;
		GLFWcursor* cur_arrow = nullptr;
		GLFWcursor* cur_ibeam = nullptr;
		GLFWcursor* cur_crosshair = nullptr;
		GLFWcursor* cur_hand = nullptr;
		GLFWcursor* cur_hresize = nullptr;
		GLFWcursor* cur_vresize = nullptr;
	};
#endif // CC_PLATFORM_PC

	class MonitorHelper : public cocos2d::Ref
	{
	public:
		using GammaRamp = std::array<std::vector<unsigned short>, 3>;
		using VideoMode = std::array<int, 6>;

		static std::vector<MonitorHelper*> getMonitors();
		static MonitorHelper* getPrimaryMonitor();
		static MonitorHelper* getCurrentMonitor();

		virtual bool isValid() = 0;

		virtual cocos2d::Vec2 getPosition() = 0;
		virtual cocos2d::Rect getWorkarea() = 0;
		virtual cocos2d::Vec2 getPhysicalSize() = 0;
		virtual cocos2d::Vec2 getContentScale() = 0;
		virtual std::string getName() = 0;
		virtual std::vector<VideoMode> getVideoModes() = 0;
		virtual VideoMode getCurrentVideoMode() = 0;
		virtual void setGamma(float gamma) = 0;
		virtual GammaRamp getGammaRamp() = 0;
		virtual void setGammaRamp(const GammaRamp& ramp) = 0;
	protected:
		~MonitorHelper() override = default;
		static cocos2d::Map<void*, MonitorHelper*> instances;
	};
#ifdef CC_PLATFORM_PC
	class MonitorHelperDesktop : public MonitorHelper
	{
	public:
		bool isValid() override;
		cocos2d::Vec2 getPosition() override;
		cocos2d::Rect getWorkarea() override;
		cocos2d::Vec2 getPhysicalSize() override;
		cocos2d::Vec2 getContentScale() override;
		std::string getName() override;
		std::vector<VideoMode> getVideoModes() override;
		VideoMode getCurrentVideoMode() override;
		void setGamma(float gamma) override;
		GammaRamp getGammaRamp() override;
		void setGammaRamp(const GammaRamp& ramp) override;
	protected:
		MonitorHelperDesktop(GLFWmonitor* hdl);
		~MonitorHelperDesktop() override = default;
		GLFWmonitor* handle = nullptr;

		static MonitorHelperDesktop* getOrCreate(GLFWmonitor* handle);
		friend class MonitorHelper;
	};
#endif // CC_PLATFORM_PC
}
