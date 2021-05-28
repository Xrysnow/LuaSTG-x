#include "ControllerHelper.h"
#include "AppFrame.h"
//using namespace std;
using namespace lstg;
using namespace cocos2d;

ControllerHelper::ControllerHelper()
{
}

ControllerHelper* ControllerHelper::getInstance()
{
	static ControllerHelper ins;
	return &ins;
}

void ControllerHelper::init()
{
	auto controllers = Controller::getAllController();
	if (!controllers.empty())
	{
		for (auto c : controllers)
		{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
			//receive back key
			c->receiveExternalKeyEvent(4, true);
			//receive menu key
			c->receiveExternalKeyEvent(82, true);
#endif
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
			//TODO:
			// clear mapping
			//c->_buttonInputMap = {};
			//c->_axisInputMap = {};
#endif
		}
	}

	auto listener = EventListenerController::create();
	listener->onConnected = CC_CALLBACK_2(ControllerHelper::onConnectController, this);
	listener->onDisconnected = CC_CALLBACK_2(ControllerHelper::onDisconnectedController, this);
	listener->onKeyDown = CC_CALLBACK_3(ControllerHelper::onKeyDown, this);
	listener->onKeyUp = CC_CALLBACK_3(ControllerHelper::onKeyUp, this);
	listener->onAxisEvent = CC_CALLBACK_3(ControllerHelper::onAxisEvent, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
	Controller::startDiscoveryController();
}

void ControllerHelper::end()
{
	Controller::stopDiscoveryController();
}

void ControllerHelper::setOnKeyDown(const KeyCallBack &f)
{
	_onKeyDown = f;
}

void ControllerHelper::setOnKeyUp(const KeyCallBack& f)
{
	_onKeyUp = f;
}

void ControllerHelper::setOnAxisEvent(const KeyCallBack& f)
{
	_onAxisEvent = f;
}

void ControllerHelper::setOnConnect(const ConnectCallBack& f)
{
	_onConnect = f;
}

void ControllerHelper::setOnDisconnect(const ConnectCallBack& f)
{
	_onDisconnect = f;
}

void ControllerHelper::onKeyDown(Controller* controller, int keyCode, Event* /*event*/)
{
	if (_onKeyDown)
	{
		const auto& s = controller->getKeyStatus(keyCode);
		_onKeyDown(controller, keyCode, s.value, s.isPressed, s.isAnalog);
	}
}

void ControllerHelper::onKeyUp(Controller* controller, int keyCode, Event* /*event*/)
{
	if (_onKeyUp)
	{
		const auto& s = controller->getKeyStatus(keyCode);
		_onKeyUp(controller, keyCode, s.value, s.isPressed, s.isAnalog);
	}
}

void ControllerHelper::onAxisEvent(Controller* controller, int keyCode, Event* /*event*/)
{
	if (_onAxisEvent)
	{
		const auto& s = controller->getKeyStatus(keyCode);
		_onAxisEvent(controller, keyCode, s.value, s.isPressed, s.isAnalog);
	}
}

void ControllerHelper::onConnectController(Controller* controller, Event* /*event*/)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	//receive back key
	controller->receiveExternalKeyEvent(4, true);
	//receive menu key
	controller->receiveExternalKeyEvent(82, true);
#endif
#if ( CC_TARGET_PLATFORM == CC_PLATFORM_LINUX || CC_TARGET_PLATFORM == CC_PLATFORM_WIN32 )
	//TODO:
	// clear mapping
	//controller->_buttonInputMap = {};
	//controller->_axisInputMap = {};
#endif
	if (_onConnect)
	{
		_onConnect(controller);
	}
}

void ControllerHelper::onDisconnectedController(Controller* controller, Event* /*event*/)
{
	if (_onDisconnect)
	{
		_onDisconnect(controller);
	}
}
