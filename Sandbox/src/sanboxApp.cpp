#include <exEngine.h>

class Sandbox : public exEngine::Application
{
public:
	Sandbox()
	{

	}
	~Sandbox()
	{

	}
};


exEngine::Application* exEngine::create_application()
{
	return new Sandbox();
}


