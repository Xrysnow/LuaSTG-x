#include "InputManager.h"
#include "cocos2d.h"
#include "LogSystem.h"
#include "UtilLua.h"
#include "Utility.h"

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
		if (159 <= i && i <= 162)i = i - 133;// DPAD -> ARROW
		inputStateMap[i] = true;
		lastKey = i;
		//CCLOG("key %d pressed", i);
	};
	listenerK->onKeyReleased = [this](EventKeyboard::KeyCode keyCode, Event* event) {
		auto i = static_cast<TKeyCode>(keyCode);
		if (159 <= i && i <= 162)
			i = i - 133;
		inputStateMap[i] = false;
		if (lastKey == i)
			lastKey = 0;
		//CCLOG("key %d released", i);
	};
	//TODO: low priority may be better?
	e->addEventListenerWithFixedPriority(listenerK, 1);

#ifdef CC_PLATFORM_PC
	auto listenerM = EventListenerMouse::create();
	listenerM->onMouseDown = [this](EventMouse* event)
	{
		const auto i = static_cast<TMouseButton>(event->getMouseButton());
		if (0 <= i && i <= 2)
			mouseState[i] = true;// left, right, middle
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
	lastChar = 0;
	lastKey = 0;
	memset(KeyStateMap, 0, sizeof(KeyStateMap));
	memset(mouseState, 0, sizeof(mouseState));
	memset(inputStateMap, 0, sizeof(inputStateMap));
}

bool InputManager::getKeyState(int VKCode) noexcept
{
	if (0 < VKCode&&VKCode <= 255)
		return inputStateMap[VKCode];
	return false;
}

int InputManager::getLastChar(lua_State* L) noexcept
{
	if (lastChar)
	{
		try
		{
			wchar_t tBuf[2] = {lastChar, 0};
			lua_pushstring(L,
				util::WideCharToMultiByte_UTF8(tBuf).c_str());
		}
		catch (const bad_alloc&)
		{
			XERROR("OOM");
			return 0;
		}
	}
	else
		lua_pushstring(L, "");
	return 1;
}

bool InputManager::getMouseState(int button) noexcept
{
	if (button >= 0 && button < 3)
		return mouseState[button];
	return false;
}

void InputManager::updateInput() noexcept
{
	// todo: maybe this?
	//Director::getInstance()->getOpenGLView()->pollEvents();
}
