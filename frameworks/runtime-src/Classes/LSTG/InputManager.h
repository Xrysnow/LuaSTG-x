#pragma once
#include "ControllerHelper.h"

#define LIM (*lstg::InputManager::getInstance())

namespace lstg
{
	class InputManager
	{
	private:
		InputManager();
		~InputManager();

		bool _init();
		bool _end();
	public:
		static InputManager* getInstance();

		static bool init();
		static bool end();

		void clearState();

		// if key is pressed
		bool getKeyState(int VKCode)noexcept;

		// last presesed key
		int getLastKey() const noexcept { return lastKey; }

		// last got char (UTF-8) TODO: remove?
		int getLastChar(lua_State* L)noexcept;

		// mouse position (to the left bottom)
		cocos2d::Vec2 getMousePosition() const noexcept { return mousePosition; }

		// if mouse button is pressed
		bool getMouseState(int button) noexcept;

		//ControllerHelper* getControllerHelper() { return &controllerHelper; }

		/** update input state immediately TODO: remove?*/
		void updateInput() noexcept;

	private:

		wchar_t lastChar = 0;//TODO: Use char?
		int32_t lastKey = 0;
		bool KeyStateMap[256];
		cocos2d::Vec2 mousePosition;
		bool mouseState[3];

		bool inputStateMap[256];
		//ControllerHelper controllerHelper;
	};
}
