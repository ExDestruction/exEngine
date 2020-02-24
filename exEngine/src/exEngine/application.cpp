#include "application.h"
#include "exEngine/Log.h"
#include "exEngine/events/application_event.h"


namespace exEngine
{
	Application::Application()
	{
	}
	Application::~Application()
	{
	}

	void Application::Run()
	{
		window_resize_event event(1280, 720);
		EX_TRACE(event);
		

		while (true);
	}
}