#pragma once
namespace Pavebo
{
	class MouseEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);
		MouseEvent() {};
	
	};

	class MouseButtonPressedEvent : public MouseEvent
	{
	public:
		MouseButtonPressedEvent(int button) : m_Button(button) {};
		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse button pressed " << m_Button;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseButtonPressed)
	private:
		int m_Button;
	};
	class MouseButtonReleasedEvent : public MouseEvent
	{
	public:
		MouseButtonReleasedEvent(int button) : m_Button(button) {};
		EVENT_CLASS_TYPE(MouseButtonReleased);
		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse button released " << m_Button;
			return ss.str();
		}
	private:
		int m_Button;
	};
	class MouseMovedEvent : public MouseEvent
	{
	public:
		MouseMovedEvent(int x, int y)  : m_X(x), m_Y(y)  {};
		virtual std::string ToString() const override
		{
			std::stringstream ss;
			ss << "Mouse moved " << m_X << " " << m_Y;
			return ss.str();
		}
		EVENT_CLASS_TYPE(MouseMoved);
	private:
		int m_X;
		int m_Y;
	};
}