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
	assert_ptr(view);
	static WindowHelperWin32 instance(
		view,
		view->getWin32Window());
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_MAC)||(CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
	auto view = dynamic_cast<GLViewImpl*>(Director::getInstance()->getOpenGLView());
	assert_ptr(view);
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
	const auto s = (view->getMonitorSize() - getSize()) / 2;
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

void WindowHelperDesktop::setGamma(float v)
{
	const auto m = glfwGetWindowMonitor(view->getWindow());
	if(m)
		glfwSetGamma(m, v);
	gamma = v;
}

float WindowHelperDesktop::getGamma()
{
	return gamma;
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

GLFWwindow* WindowHelperDesktop::getWindow()
{
	return view->getWindow();
}

#endif // CC_PLATFORM_PC
