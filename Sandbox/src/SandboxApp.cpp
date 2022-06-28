#include <Aqua.h>

class Sandbox : public Aqua::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}


};




Aqua::Application* Aqua::CreateApplication()
{
	return new Sandbox();
}