#pragma once
#include "ControllerHelper.h"

#define LIM (*lstg::InputManager::getInstance())

namespace lstg
{
	class InputManager
	{
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
		bool getKeyState(int code);
		void setKeyState(int code, bool value);

		// get last presesed key
		int getLastKey() const { return lastKey; }

		// get mouse position (to the left bottom)
		cocos2d::Vec2 getMousePosition() const { return mousePosition; }

		// if mouse button is pressed
		bool getMouseState(int button);

		/**
		 * \brief (windows only) enable/disable keyboard hook
		 *
		 * Enable keyboard hook will reduce input latency, but will affect the whole system. It is recommended to disable it when the game is paused.
		 * \param enabled enable/disable
		 */
		void setKeyboardHookEnabled(bool enabled);

	private:
		int32_t lastKey = 0;
		bool KeyStateMap[256];
		cocos2d::Vec2 mousePosition;
		bool mouseState[3];
		bool inputStateMap[256];

		void* keyboardHook = nullptr;
	};
}
