#pragma once

#ifdef EX_PLATFORM_WINDOWS

extern exEngine::Application* exEngine::create_application();

int main(int argc, char** argv)
{
	exEngine::Log::init();

	EX_WARN("Initialized CLIENT Log!");
	EX_CORE_INFO("Initialized CORE Log!");

	auto app = exEngine::create_application();
	app->Run();
	delete app;
}

#endif
