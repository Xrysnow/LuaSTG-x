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
		using KeyCallBack = std::function<void(cc::Controller*, int, float, bool, bool)>;
		using ConnectCallBack = std::function<void(cc::Controller*)>;
	private:

		KeyCallBack _onKeyDown;
		KeyCallBack _onKeyUp;
		KeyCallBack _onAxisEvent;
		ConnectCallBack _onConnect;
		ConnectCallBack _onDisconnect;
	public:

		void setOnKeyDown(const KeyCallBack& f);
		void setOnKeyUp(const KeyCallBack& f);
		void setOnAxisEvent(const KeyCallBack& f);
		void setOnConnect(const ConnectCallBack& f);
		void setOnDisconnect(const ConnectCallBack& f);
	protected:

		void onKeyDown(cc::Controller* controller, int keyCode, cc::Event* event);
		void onKeyUp(cc::Controller* controller, int keyCode, cc::Event* event);
		void onAxisEvent(cc::Controller* controller, int keyCode, cc::Event* event);
		void onConnectController(cc::Controller* controller, cc::Event* event);
		void onDisconnectedController(cc::Controller* controller, cc::Event* event);
	public:
		CC_DISALLOW_COPY_AND_ASSIGN(ControllerHelper);
	};
}
