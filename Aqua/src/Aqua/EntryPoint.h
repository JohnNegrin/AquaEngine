#pragma once

#ifdef AQ_PLATFORM_WINDOWS

extern Aqua::Application* Aqua::CreateApplication();

int main(int argc, char** argv) 
{

	auto app = Aqua::CreateApplication();
	app->Run();
	delete app;
}

#endif