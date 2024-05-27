#pragma once

#include "Event.h"

#include <sstream>

namespace Astro
{
	class ASTRO_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(const unsigned int InWidth, const unsigned int InHeight)
			: Width(InWidth), Height(InHeight)
		{
		}

		inline unsigned int GetWidth() const { return Width; }
		inline unsigned int GetHeight() const { return Height; }

		std::string ToString() const override
		{
			std::stringstream StringStream;
			StringStream << "WindowResizeEvent: " << Width << ", " << Height;
			return StringStream.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)

	private:
		unsigned int Width, Height;
	};

	class ASTRO_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent()
		{
		}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ASTRO_API AppTickEvent : public Event
	{
	public:
		AppTickEvent()
		{
		}

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};


	class ASTRO_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent()
		{
		}

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class ASTRO_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent()
		{
		}

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}
