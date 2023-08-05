#pragma once
#include "../Core.h"

#include <functional>
#include <sstream>
namespace Pavebo
{
	enum EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	enum EventCategory //To filter events
	{
		
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType(){return EventType::type;} \
	virtual EventType GetEventType() const override { return GetStaticType(); }\
	virtual const char* GetName() const override {return #type;}
	class PAVEBO_API Event
	{
	public:
		virtual ~Event() = default;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }
	};
}