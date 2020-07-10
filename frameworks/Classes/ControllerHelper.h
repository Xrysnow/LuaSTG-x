#pragma once
#include "cocos2d.h"

namespace lstg
{	
	class ControllerHelper
	{
		ControllerHelper();
	public:
		static ControllerHelper* getInstance();

		void init();
		void end();

		// controller, keyCode, value, isPressed, isAnalog
		using KeyCallBack = std::function<void(cocos2d::Controller*, int, float, bool, bool)>;
		using ConnectCallBack = std::function<void(cocos2d::Controller*)>;
	private:

		KeyCallBack _onKeyDown;
		KeyCallBack _onKeyUp;
		KeyCallBack _onAxisEvent;
		ConnectCallBack _onConnect;
		ConnectCallBack _onDisconnect;
	public:

		void setOnKeyDown(KeyCallBack f);
		void setOnKeyUp(KeyCallBack f);
		void setOnAxisEvent(KeyCallBack f);
		void setOnConnect(ConnectCallBack f);
		void setOnDisconnect(ConnectCallBack f);
	protected:

		void onKeyDown(cocos2d::Controller* controller, int keyCode, cocos2d::Event* event);
		void onKeyUp(cocos2d::Controller* controller, int keyCode, cocos2d::Event* event);
		void onAxisEvent(cocos2d::Controller* controller, int keyCode, cocos2d::Event* event);
		void onConnectController(cocos2d::Controller* controller, cocos2d::Event* event);
		void onDisconnectedController(cocos2d::Controller* controller, cocos2d::Event* event);
	public:
		CC_DISALLOW_COPY_AND_ASSIGN(ControllerHelper);
	};
}
