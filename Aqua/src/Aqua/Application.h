#pragma once
#include "Core.h"

namespace Aqua {

	class AQUA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client.
	Application* CreateApplication();

}
