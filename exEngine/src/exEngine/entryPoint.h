#pragma once

#ifdef EX_PLATFORM_WINDOWS

extern exEngine::Application* exEngine::create_application();

int main(int argc, char** argv)
{
	auto app = exEngine::create_application();
	app->Run();
	delete app;
}

#endif
