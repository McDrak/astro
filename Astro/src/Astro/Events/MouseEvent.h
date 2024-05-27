#pragma once

#include "Event.h"

#include <sstream>

namespace Astro
{
	class ASTRO_API MouseMovedEvent : Event
	{
	public:
		MouseMovedEvent(const float X, const float Y)
			: MouseX(X), MouseY(Y)
		{
		}

		inline float GetX() const { return MouseX; }
		inline float GetY() const { return MouseY; }

		std::string ToString() const override
		{
			std::stringstream StringStream;
			StringStream << "MouseMovedEvent: " << MouseX << ", " << MouseY;
			return StringStream.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float MouseX, MouseY;
	};

	class ASTRO_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const float InXOffset, const float InYOffset)
			: XOffset(InXOffset), YOffset(InYOffset)
		{
		}

		inline float GetXOffset() const { return XOffset; }
		inline float GetYOffset() const { return YOffset; }

		std::string ToString() const override
		{
			std::stringstream StringStream;
			StringStream << "MouseScrolledEvent: " << XOffset << ", " << YOffset;
			return StringStream.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	private:
		float XOffset, YOffset;
	};

	class ASTRO_API MouseButtonEvent : public Event
	{
	public:
		inline int GetButton() const { return Button; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

	protected:
		MouseButtonEvent(const int InButton)
			: Button(InButton)
		{
		}

		int Button;
	};

	class ASTRO_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const int InButton)
			: MouseButtonEvent(InButton)
		{
		}

		std::string ToString() const override
		{
			std::stringstream StringStream;
			StringStream << "MouseButtonPressedEvent: " << Button;
			return StringStream.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class ASTRO_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(const int InButton)
			: MouseButtonEvent(InButton)
		{
		}

		std::string ToString() const override
		{
			std::stringstream StringStream;
			StringStream << "MouseButtonReleasedEvent: " << Button;
			return StringStream.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
