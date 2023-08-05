#pragma once
#include "Event.h"

namespace Pavebo
{

	class KeyEvent :public Event
	{
	public:
		int GetKeycode() const { return m_keycode; }
		
	protected:
		KeyEvent(int keycode) : m_keycode(keycode) {}

	private:
		int m_keycode;

	};

	class KeyPressed : public KeyEvent
	{
	public:
		KeyPressed(int keycode, bool isRepeat = false) : KeyEvent(keycode), m_isRepeat(isRepeat) {}
		std::string ToString() const override { return "Key pressed"; }

	private:
		bool m_isRepeat;
	};

	class KeyReleased : public KeyEvent
	{
	public:

	};
}