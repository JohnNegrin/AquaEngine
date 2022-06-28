#pragma once

#ifdef AQ_PLATFORM_WINDOWS

extern Aqua::Application* Aqua::CreateApplication();

int main(int argc, char** argv) 
{
	Aqua::Log::Init();
	AQ_CORE_WARN("Init");
	int a = 20;
	AQ_INFO("Hi! Var={0}", a);

	auto app = Aqua::CreateApplication();
	app->Run();
	delete app;
}

#endif