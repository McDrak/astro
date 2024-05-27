#pragma once

#include "Event.h"

#include <sstream>

namespace Astro
{
	class ASTRO_API KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return KeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent(const int InKeyCode)
			: KeyCode(InKeyCode)
		{
		}

		int KeyCode;
	};

	class ASTRO_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const int InKeyCode, const int InRepeatCount)
			: KeyEvent(InKeyCode), RepeatCount(InRepeatCount)
		{
		}

		inline int GetRepeatCount() const { return RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream StringStream;
			StringStream << "KeyPressedEvent: " << KeyCode << " (" << RepeatCount << " repeats)";
			return StringStream.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)

	private:
		int RepeatCount;
	};

	class ASTRO_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const int InKeyCode)
			: KeyEvent(InKeyCode)
		{
		}

		std::string ToString() const override
		{
			std::stringstream StringStream;
			StringStream << "KeyReleasedEvent: " << KeyCode;
			return StringStream.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}
