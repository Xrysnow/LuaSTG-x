#include "InputManager.h"
#include "cocos2d.h"
#include "LogSystem.h"
#include "Util/UtilLua.h"
#include "Util/Utility.h"

#if CC_TARGET_PLATFORM == CC_PLATFORM_WIN32
#define LSTGX_USE_KEYBOARD_HOOK
#endif

#ifdef LSTGX_USE_KEYBOARD_HOOK
LRESULT CALLBACK LowLevelKeyboardProc(
	_In_ int nCode,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam);
#endif

using namespace std;
using namespace lstg;
using namespace cocos2d;
using TKeyCode = underlying_type<EventKeyboard::KeyCode>::type;
using TMouseButton = underlying_type<EventMouse::MouseButton>::type;

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

bool InputManager::_init()
{
	clearState();
	ControllerHelper::getInstance()->init();
	const auto director = Director::getInstance();
	auto e = director->getEventDispatcher();
	// note: EventKeyboard is sent in GLView::pollEvents (called in Director::drawScene),
	// which is before EVENT_BEFORE_UPDATE
	e->addCustomEventListener(Director::EVENT_AFTER_UPDATE,
		[this](EventCustom* event)
	{
		// clear before being set in listener
		lastKey = 0;
	});
	auto listenerK = EventListenerKeyboard::create();
	listenerK->onKeyPressed = [this](EventKeyboard::KeyCode keyCode, Event* event) {
		// cast to int
		auto i = static_cast<TKeyCode>(keyCode);
		// DPAD -> ARROW
		if (159 <= i && i <= 162)
			i = i - 133;
		inputStateMap[i] = true;
		lastKey = i;
	};
	listenerK->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event* event) {
		auto i = static_cast<TKeyCode>(keyCode);
		if (159 <= i && i <= 162)
			i = i - 133;
		inputStateMap[i] = false;
		if (lastKey == i)
			lastKey = 0;
	};
	e->addEventListenerWithFixedPriority(listenerK, 1);

#ifdef CC_PLATFORM_PC
	auto listenerM = EventListenerMouse::create();
	listenerM->onMouseDown = [this](EventMouse* event)
	{
		const auto i = static_cast<TMouseButton>(event->getMouseButton());
		// left, right, middle
		if (0 <= i && i <= 2)
			mouseState[i] = true;
	};
	listenerM->onMouseUp = [this](EventMouse* event)
	{
		const auto i = static_cast<TMouseButton>(event->getMouseButton());
		if (0 <= i && i <= 2)
			mouseState[i] = false;
	};
	listenerM->onMouseMove = [this](EventMouse* event)
	{
		mousePosition = event->getLocation();
	};
	e->addEventListenerWithFixedPriority(listenerM, 1);
#endif
	return true;
}

bool InputManager::_end()
{
	ControllerHelper::getInstance()->end();
	setKeyboardHookEnabled(false);
	return true;
}

InputManager* InputManager::getInstance()
{
	static InputManager instance;
	return &instance;
}

bool InputManager::init()
{
	return getInstance()->_init();
}

bool InputManager::end()
{
	return getInstance()->_end();
}

void InputManager::clearState()
{
	lastKey = 0;
	memset(KeyStateMap, 0, sizeof(KeyStateMap));
	memset(mouseState, 0, sizeof(mouseState));
	memset(inputStateMap, 0, sizeof(inputStateMap));
}

bool InputManager::getKeyState(int code)
{
	if (0 < code && code <= 255)
		return inputStateMap[code];
	return false;
}

void InputManager::setKeyState(int code, bool value)
{
	if (0 < code && code <= 255)
	{
		inputStateMap[code] = value;
		if (value)
			lastKey = code;
		else if (lastKey == code)
			lastKey = 0;
	}
}

bool InputManager::getMouseState(int button)
{
	if (button >= 0 && button < 3)
		return mouseState[button];
	return false;
}

void InputManager::setKeyboardHookEnabled(bool enabled)
{
#ifdef LSTGX_USE_KEYBOARD_HOOK
	if (enabled == static_cast<bool>(keyboardHook))
		return;
	if (keyboardHook)
	{
		UnhookWindowsHookEx((HHOOK)keyboardHook);
		keyboardHook = nullptr;
	}
	else
	{
		// NOTE: glfw/WH_KEYBOARD are slower than WH_KEYBOARD_LL
		keyboardHook = SetWindowsHookEx(
			WH_KEYBOARD_LL,
			LowLevelKeyboardProc,
			GetModuleHandleA(NULL),
			NULL);
		if (!keyboardHook)
		{
			LWARNING("failed to install keyboard hook");
		}
	}
#endif
}

#ifdef LSTGX_USE_KEYBOARD_HOOK

using KeyCode = EventKeyboard::KeyCode;
static std::unordered_map<int, KeyCode> KeyCodeMap = {
	{0, KeyCode::KEY_NONE},
	{VK_CANCEL, KeyCode::KEY_BREAK},
	{VK_BACK, KeyCode::KEY_BACKSPACE},
	{VK_TAB, KeyCode::KEY_TAB},
	{VK_RETURN, KeyCode::KEY_ENTER},

	{VK_SHIFT, KeyCode::KEY_SHIFT},
	{VK_LSHIFT, KeyCode::KEY_LEFT_SHIFT},
	{VK_RSHIFT, KeyCode::KEY_RIGHT_SHIFT},

	{VK_CONTROL, KeyCode::KEY_CTRL},
	{VK_LCONTROL, KeyCode::KEY_LEFT_CTRL},
	{VK_RCONTROL, KeyCode::KEY_RIGHT_CTRL},

	{VK_MENU, KeyCode::KEY_ALT},
	{VK_LMENU, KeyCode::KEY_LEFT_ALT},
	{VK_RMENU, KeyCode::KEY_RIGHT_ALT},

	{VK_PAUSE, KeyCode::KEY_PAUSE},
	{VK_CAPITAL, KeyCode::KEY_CAPS_LOCK},
	{VK_ESCAPE, KeyCode::KEY_ESCAPE}, // KEY_BACK = KEY_ESCAPE

	{VK_SPACE, KeyCode::KEY_SPACE},
	{VK_PRIOR, KeyCode::KEY_PG_UP},
	{VK_NEXT, KeyCode::KEY_PG_DOWN},
	{VK_END, KeyCode::KEY_END},
	{VK_HOME, KeyCode::KEY_HOME},

	{VK_LEFT, KeyCode::KEY_LEFT_ARROW},
	{VK_UP, KeyCode::KEY_UP_ARROW},
	{VK_RIGHT, KeyCode::KEY_RIGHT_ARROW},
	{VK_DOWN, KeyCode::KEY_DOWN_ARROW},


	//{VK_SELECT, KeyCode::KEY_SELECT},
	{VK_PRINT, KeyCode::KEY_PRINT},
	//{VK_EXECUTE, KeyCode::KEY_EXECUTE},
	//{VK_SNAPSHOT, KeyCode::KEY_SNAPSHOT},
	{VK_INSERT, KeyCode::KEY_INSERT},
	{VK_DELETE, KeyCode::KEY_DELETE},
	//{VK_HELP, KeyCode::KEY_HELP},

	{VK_LWIN, KeyCode::KEY_HYPER},
	{VK_RWIN, KeyCode::KEY_HYPER},
	//{VK_APPS, KeyCode::KEY_APPS},
	//{VK_SLEEP, KeyCode::KEY_SLEEP},

	{VK_NUMPAD0, KeyCode::KEY_0},
	{VK_NUMPAD1, KeyCode::KEY_1},
	{VK_NUMPAD2, KeyCode::KEY_2},
	{VK_NUMPAD3, KeyCode::KEY_3},
	{VK_NUMPAD4, KeyCode::KEY_4},
	{VK_NUMPAD5, KeyCode::KEY_5},
	{VK_NUMPAD6, KeyCode::KEY_6},
	{VK_NUMPAD7, KeyCode::KEY_7},
	{VK_NUMPAD8, KeyCode::KEY_8},
	{VK_NUMPAD9, KeyCode::KEY_9},

	{VK_MULTIPLY, KeyCode::KEY_KP_MULTIPLY},
	{VK_ADD, KeyCode::KEY_KP_PLUS},
	{VK_SEPARATOR, KeyCode::KEY_KP_ENTER},
	{VK_SUBTRACT, KeyCode::KEY_KP_MINUS},
	//{VK_DECIMAL, KeyCode::KEY_KP_},
	{VK_DIVIDE, KeyCode::KEY_KP_DIVIDE},

	{VK_F1, KeyCode::KEY_F1},
	{VK_F2, KeyCode::KEY_F2},
	{VK_F3, KeyCode::KEY_F3},
	{VK_F4, KeyCode::KEY_F4},
	{VK_F5, KeyCode::KEY_F5},
	{VK_F6, KeyCode::KEY_F6},
	{VK_F7, KeyCode::KEY_F7},
	{VK_F8, KeyCode::KEY_F8},
	{VK_F9, KeyCode::KEY_F9},
	{VK_F10, KeyCode::KEY_F10},
	{VK_F11, KeyCode::KEY_F11},
	{VK_F12, KeyCode::KEY_F12},

	{VK_NUMLOCK, KeyCode::KEY_NUM_LOCK},
	{VK_SCROLL, KeyCode::KEY_SCROLL_LOCK},

	{VK_OEM_1, KeyCode::KEY_COLON},
	{VK_OEM_PLUS, KeyCode::KEY_PLUS},
	{VK_OEM_COMMA, KeyCode::KEY_COMMA},
	{VK_OEM_MINUS, KeyCode::KEY_MINUS},
	{VK_OEM_PERIOD, KeyCode::KEY_PERIOD},
	{VK_OEM_2, KeyCode::KEY_SLASH},
	{VK_OEM_3, KeyCode::KEY_GRAVE},
	{VK_OEM_4, KeyCode::KEY_LEFT_BRACKET},
	{VK_OEM_5, KeyCode::KEY_BACK_SLASH},
	{VK_OEM_6, KeyCode::KEY_RIGHT_BRACKET},
	{VK_OEM_7, KeyCode::KEY_QUOTE},

	{VK_PLAY, KeyCode::KEY_PLAY},

	/*
	 * VK_0 - VK_9 are the same as ASCII '0' - '9' (0x30 - 0x39)
	 * 0x3A - 0x40 : unassigned
	 * VK_A - VK_Z are the same as ASCII 'A' - 'Z' (0x41 - 0x5A)
	 */
	{'0', KeyCode::KEY_0},
	{'1', KeyCode::KEY_1},
	{'2', KeyCode::KEY_2},
	{'3', KeyCode::KEY_3},
	{'4', KeyCode::KEY_4},
	{'5', KeyCode::KEY_5},
	{'6', KeyCode::KEY_6},
	{'7', KeyCode::KEY_7},
	{'8', KeyCode::KEY_8},
	{'9', KeyCode::KEY_9},

	{'A', KeyCode::KEY_A},
	{'B', KeyCode::KEY_B},
	{'C', KeyCode::KEY_C},
	{'D', KeyCode::KEY_D},
	{'E', KeyCode::KEY_E},
	{'F', KeyCode::KEY_F},
	{'G', KeyCode::KEY_G},
	{'H', KeyCode::KEY_H},
	{'I', KeyCode::KEY_I},
	{'J', KeyCode::KEY_J},
	{'K', KeyCode::KEY_K},
	{'L', KeyCode::KEY_L},
	{'M', KeyCode::KEY_M},
	{'N', KeyCode::KEY_N},
	{'O', KeyCode::KEY_O},
	{'P', KeyCode::KEY_P},
	{'Q', KeyCode::KEY_Q},
	{'R', KeyCode::KEY_R},
	{'S', KeyCode::KEY_S},
	{'T', KeyCode::KEY_T},
	{'U', KeyCode::KEY_U},
	{'V', KeyCode::KEY_V},
	{'W', KeyCode::KEY_W},
	{'X', KeyCode::KEY_X},
	{'Y', KeyCode::KEY_Y},
	{'Z', KeyCode::KEY_Z},
};

LRESULT CALLBACK LowLevelKeyboardProc(
	_In_ int nCode,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
) {
	do
	{
		if (nCode != HC_ACTION)
			break;
		const auto view = dynamic_cast<GLViewImpl*>(Director::getInstance()->getOpenGLView());
		CC_ASSERT(view);
		if(view->getWindowHandle() != GetForegroundWindow())
			break;
		const auto ks = reinterpret_cast<KBDLLHOOKSTRUCT*>(lParam);
		const auto it = KeyCodeMap.find((int)ks->vkCode);
		if (it == KeyCodeMap.end())
			break;
		const auto keyCode = (int)it->second;
		const auto status = !static_cast<bool>(ks->flags & LLKHF_UP);
		InputManager::getInstance()->setKeyState(keyCode, status);
	}
	while (false);
	return CallNextHookEx(NULL, nCode, wParam, lParam);
}
#endif
