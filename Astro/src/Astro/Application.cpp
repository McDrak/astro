#include "Application.h"

#include "Log.h"
#include "Events/ApplicationEvent.h"

namespace Astro
{
	//------------------------------------------------------------------------------------------------------------------
	Application::Application()
	{
	}

	//------------------------------------------------------------------------------------------------------------------
	Application::~Application()
	{
	}

	//------------------------------------------------------------------------------------------------------------------
	void Application::Run()
	{
		const WindowResizeEvent Event(1280, 720);
		AST_TRACE(Event.ToString());

		while (true);
	}
}
