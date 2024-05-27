#pragma once

#include "Astro/Core.h"

#include <string>
#include <functional>

namespace Astro
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	class ASTRO_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(const EventCategory Category) const
		{
			return GetCategoryFlags() & Category;
		}

	protected:
		bool bIsHandled = false;
	};

	class EventDispatcher
	{
		template <typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(Event& InEvent)
			: Event(InEvent)
		{
		}

		template <typename T>
		bool Dispatch(EventFn<T> InFunc)
		{
			if (Event.GetEventType() != T::GetStaticType())
			{
				return false;
			}

			Event.bIsHandled = InFunc(*(T*)&Event);
			return true;
		}

	private:
		Event& Event;
	};

	inline std::ostream& operator<<(std::ostream& OutStream, const Event& InEvent)
	{
		return OutStream << InEvent.ToString();
	}
}
