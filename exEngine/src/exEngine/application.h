#pragma once

#include "core.h"
#include "events/event.h"


namespace exEngine
{
	class EX_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};


	//to be defined in CLIENT
	Application* create_application();
}