#include "WindowHelper.h"
#include "../LSTG/Global.h"
#include "../LSTG/LogSystem.h"
#include "../LSTG/Renderer.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#include "../runtime-src/proj.win32/WindowHelperWin32.h"
#endif

using namespace std;
using namespace lstg;
using namespace cocos2d;

WindowHelper* WindowHelper::getInstance()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	auto view = dynamic_cast<GLViewImpl*>(Director::getInstance()->getOpenGLView());
	CC_ASSERT(view);
	static WindowHelperWin32 instance(
		view,
		view->getWin32Window());
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)||(CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
	auto view = dynamic_cast<GLViewImpl*>(Director::getInstance()->getOpenGLView());
	assert(view);
	static WindowHelperDesktop instance(view);
#else
	static WindowHelper instance;
#endif
	return &instance;
}

#ifdef CC_PLATFORM_PC

WindowHelperDesktop::WindowHelperDesktop(GLViewImpl* view): view(view)
{
	cur_arrow = glfwCreateStandardCursor(GLFW_ARROW_CURSOR);
	cur_ibeam = glfwCreateStandardCursor(GLFW_IBEAM_CURSOR);
	cur_crosshair = glfwCreateStandardCursor(GLFW_CROSSHAIR_CURSOR);
	cur_hand = glfwCreateStandardCursor(GLFW_HAND_CURSOR);
	cur_hresize = glfwCreateStandardCursor(GLFW_HRESIZE_CURSOR);
	cur_vresize = glfwCreateStandardCursor(GLFW_VRESIZE_CURSOR);
}

WindowHelperDesktop* WindowHelperDesktop::getInstance()
{
	return dynamic_cast<WindowHelperDesktop*>(WindowHelper::getInstance());
}

void WindowHelperDesktop::setTitle(const std::string& s)
{
	title = s;
	glfwSetWindowTitle(getWindow(), s.c_str());
}

std::string WindowHelperDesktop::getTitle()
{
	return title;
}

void WindowHelperDesktop::setPosition(const Vec2& p)
{
	glfwSetWindowPos(getWindow(), p.x, p.y);
}

Vec2 WindowHelperDesktop::getPosition()
{
	int x, y;
	glfwGetWindowPos(getWindow(), &x, &y);
	return {float(x), float(y)};
}

void WindowHelperDesktop::setVisible(bool b)
{
	if (b)
		operate(SHOW);
	else
		operate(HIDE);
	visible = b;
}

bool WindowHelperDesktop::isVisible()
{
	return visible;
}

void WindowHelperDesktop::setCursorVisible(bool b)
{
	view->setCursorVisible(b);
	cursorVisible = b;
}

bool WindowHelperDesktop::isCursorVisible()
{
	return cursorVisible;
}

void WindowHelperDesktop::setSize(const Size& size)
{
	//if (!isFullscreen()){
	view->setWindowed(size.width, size.height);
	//}else
	//	view->setFrameSize(size.width, size.height);
}

Size WindowHelperDesktop::getSize()
{
	return view->getFrameSize();
}

void WindowHelperDesktop::setFullscreen()
{
	view->setFullscreen();
}

bool WindowHelperDesktop::isFullscreen()
{
	return view->isFullscreen();
}

void WindowHelperDesktop::setVsync(bool b)
{
	if (b == vsync)return;
	vsync = b;
	LRR.setVsync(b);
}

bool WindowHelperDesktop::isVsync()
{
	return vsync;
}

void WindowHelperDesktop::setVideoMode(VideoMode v)
{
	if (v.windowed)
	{
		setSize(Size(v.width, v.height));
	}
	else
	{
		setFullscreen();
	}
	setVsync(v.vsync);
}

WindowHelperDesktop::VideoMode WindowHelperDesktop::getVideoMode()
{
	const auto size = getSize();
	return { int(size.width), int(size.height), !isFullscreen(), isVsync() };
}

void WindowHelperDesktop::moveToCenter()
{
	if (isFullscreen())
		return;
	int xpos = 0, ypos = 0;
	glfwGetMonitorPos(view->getMonitor(), &xpos, &ypos);
	const auto s = (view->getMonitorSize() - getSize()) / 2 + Vec2(xpos, ypos);
	setPosition(Vec2(s.width, s.height));
}

void WindowHelperDesktop::operate(Operation op)
{
	switch (op)
	{
	case SHOW:
		glfwShowWindow(getWindow());
		break;
	case HIDE:
		glfwHideWindow(getWindow());
		break;
	case FOCUS:
		glfwFocusWindow(getWindow());
		break;
	case ICONIFY:
		glfwIconifyWindow(getWindow());
		break;
	case RESTORE:
		glfwRestoreWindow(getWindow());
		break;
	case MAXIMIZE:
		glfwMaximizeWindow(getWindow());
		break;
	default:;
	}
}

void WindowHelperDesktop::setClipboardString(const std::string& s)
{
	glfwSetClipboardString(getWindow(), s.c_str());
}

std::string WindowHelperDesktop::getClipboardString()
{
	return glfwGetClipboardString(getWindow());
}

void WindowHelperDesktop::hint(int hint, int value)
{
    // glfwInit is required
	glfwInit();
	glfwWindowHint(hint, value);
}

void WindowHelperDesktop::resetHint()
{
	glfwDefaultWindowHints();
}

void WindowHelperDesktop::setCustomCursor(const std::string& filename, const Vec2& hotspot)
{
	if (cur_cunstom) {
		glfwDestroyCursor(cur_cunstom);
		cur_cunstom = nullptr;
	}
	Image* ccImage = new (std::nothrow) Image();
	if (ccImage && ccImage->initWithImageFile(filename)) {
		GLFWimage image;
		image.width = ccImage->getWidth();
		image.height = ccImage->getHeight();
		image.pixels = ccImage->getData();
		cur_cunstom = glfwCreateCursor(
			&image, (int)(hotspot.x * image.width), (int)((1.0f - hotspot.y) * image.height));
		if (cur_cunstom) {
			glfwSetCursor(getWindow(), cur_cunstom);
			curType = CUSTOM;
		}
	}
	CC_SAFE_DELETE(ccImage);
}

void WindowHelperDesktop::setDefaultCursor()
{
	setStandardCursor(ARROW);
}

void WindowHelperDesktop::setStandardCursor(CursorType type)
{
	if (curType == type)
		return;
	curType = type;
	switch (type) {
	case ARROW: glfwSetCursor(getWindow(), cur_arrow); break;
	case IBEAM: glfwSetCursor(getWindow(), cur_ibeam); break;
	case CROSSHAIR: glfwSetCursor(getWindow(), cur_crosshair); break;
	case HAND: glfwSetCursor(getWindow(), cur_hand); break;
	case HRESIZE: glfwSetCursor(getWindow(), cur_hresize); break;
	case VRESIZE: glfwSetCursor(getWindow(), cur_vresize); break;
	case CUSTOM: break;
	default: ;
	}
}

float WindowHelperDesktop::getDpiScale()
{
	float xscale = 1;
	float yscale = 1;
	glfwGetWindowContentScale(getWindow(), &xscale, &yscale);
	return (xscale + yscale) / 2;
}

cocos2d::Vec2 WindowHelperDesktop::getDisplayResolution()
{
	return view->getMonitorSize();
}

std::vector<cocos2d::Vec2> WindowHelperDesktop::enumDisplayResolution()
{
	std::vector<cocos2d::Vec2> res{};
	GLFWmonitor* monitor = view->getMonitor();
	int count;
	const GLFWvidmode* modes = glfwGetVideoModes(monitor, &count);
	for (int i = 0; i < count; i++)
	{
		const auto& mode = modes[i];
		bool duplicate = false;
		for (const auto& r : res)
		{
			if (int(r.x) == mode.width && int(r.y) == mode.height)
			{
				duplicate = true;
				break;
			}
		}
		if (duplicate)
			continue;
		res.emplace_back(float(mode.width), float(mode.height));
	}
	return res;
}

void WindowHelperDesktop::setImeEnabled(bool enabled)
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	HWND hwnd = Director::getInstance()->getOpenGLView()->getWin32Window();
	HIMC hIMC = ImmGetContext(hwnd);
	if (hIMC)
	{
		ImmSetOpenStatus(hIMC, enabled);
		ImmReleaseContext(hwnd, hIMC);
	}
#endif
}

bool WindowHelperDesktop::isImeEnabled()
{
#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
	HWND hwnd = Director::getInstance()->getOpenGLView()->getWin32Window();
	HIMC hIMC = ImmGetContext(hwnd);
	if (hIMC)
	{
		bool b = ImmGetOpenStatus(hIMC);
		ImmReleaseContext(hwnd, hIMC);
		return b;
	}
#endif
	return false;
}

GLFWwindow* WindowHelperDesktop::getWindow()
{
	return view->getWindow();
}

#endif // CC_PLATFORM_PC

cocos2d::Map<void*, MonitorHelper*> MonitorHelper::instances;

std::vector<MonitorHelper*> MonitorHelper::getMonitors()
{
#ifdef CC_PLATFORM_PC
	std::vector<MonitorHelper*> ret;
	int count = 0;
	const auto arr = glfwGetMonitors(&count);
	ret.reserve(count);
	for (int i = 0; i < count; ++i)
		ret.push_back(MonitorHelperDesktop::getOrCreate(arr[i]));
	return ret;
#else
	return {};
#endif
}

MonitorHelper* MonitorHelper::getPrimaryMonitor()
{
#ifdef CC_PLATFORM_PC
	const auto p = glfwGetPrimaryMonitor();
	return MonitorHelperDesktop::getOrCreate(p);
#else
	return nullptr;
#endif
}

MonitorHelper* MonitorHelper::getCurrentMonitor()
{
#ifdef CC_PLATFORM_PC
	const auto view = dynamic_cast<GLViewImpl*>(Director::getInstance()->getOpenGLView());
	const auto p = view->getMonitor();
	return MonitorHelperDesktop::getOrCreate(p);
#else
	return nullptr;
#endif
}

#ifdef CC_PLATFORM_PC

bool MonitorHelperDesktop::isValid()
{
	int count = 0;
	const auto arr = glfwGetMonitors(&count);
	for (int i = 0; i < count; ++i)
	{
		if (arr[i] == handle)
			return true;
	}
	return false;
}

cocos2d::Vec2 MonitorHelperDesktop::getPosition()
{
	int x = 0;
	int y = 0;
	glfwGetMonitorPos(handle, &x, &y);
	return { float(x),float(y) };
}

cocos2d::Rect MonitorHelperDesktop::getWorkarea()
{
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
	glfwGetMonitorWorkarea(handle, &x, &y, &w, &h);
	return { float(x),float(y),float(w),float(h) };
}

cocos2d::Vec2 MonitorHelperDesktop::getPhysicalSize()
{
	int w = 0;
	int h = 0;
	glfwGetMonitorPhysicalSize(handle, &w, &h);
	return { float(w),float(h) };
}

cocos2d::Vec2 MonitorHelperDesktop::getContentScale()
{
	float x = 0;
	float y = 0;
	glfwGetMonitorContentScale(handle, &x, &y);
	return { x,y };
}

std::string MonitorHelperDesktop::getName()
{
	const auto s = glfwGetMonitorName(handle);
	return s ? s : "";
}

std::vector<MonitorHelper::VideoMode> MonitorHelperDesktop::getVideoModes()
{
	std::vector<VideoMode> ret;
	int count = 0;
	const auto arr = glfwGetVideoModes(handle, &count);
	for (int i = 0; i < count; ++i)
	{
		auto& v = arr[i];
		ret.emplace_back(VideoMode{ v.width,v.height,v.redBits,v.greenBits,v.blueBits,v.refreshRate });
	}
	return ret;
}

MonitorHelper::VideoMode MonitorHelperDesktop::getCurrentVideoMode()
{
	const auto v = glfwGetVideoMode(handle);
	if (!v)
		return {};
	return { v->width,v->height,v->redBits,v->greenBits,v->blueBits,v->refreshRate };
}

void MonitorHelperDesktop::setGamma(float gamma)
{
	glfwSetGamma(handle, gamma);
}

MonitorHelper::GammaRamp MonitorHelperDesktop::getGammaRamp()
{
	const auto ramp = glfwGetGammaRamp(handle);
	if (!ramp)
		return {};
	GammaRamp v;
	v[0].insert(v[0].end(), ramp->red, ramp->red + ramp->size);
	v[1].insert(v[1].end(), ramp->green, ramp->red + ramp->size);
	v[2].insert(v[2].end(), ramp->blue, ramp->red + ramp->size);
	return v;
}

void MonitorHelperDesktop::setGammaRamp(const GammaRamp& ramp)
{
	const auto size = std::min({ ramp[0].size(),ramp[1].size(),ramp[2].size() });
	const GLFWgammaramp v = {
		const_cast<unsigned short*>(ramp[0].data()),
		const_cast<unsigned short*>(ramp[1].data()),
		const_cast<unsigned short*>(ramp[2].data()),
		(unsigned int)size
	};
	glfwSetGammaRamp(handle, &v);
}

MonitorHelperDesktop::MonitorHelperDesktop(GLFWmonitor* hdl)
	: handle(hdl)
{
}

MonitorHelperDesktop* MonitorHelperDesktop::getOrCreate(GLFWmonitor* handle)
{
	if (!handle)
		return nullptr;
	const auto it = instances.find(handle);
	if (it != instances.end())
		return (MonitorHelperDesktop*)it->second;
	const auto instance = new MonitorHelperDesktop(handle);
	instance->autorelease();
	return instance;
}

#endif
