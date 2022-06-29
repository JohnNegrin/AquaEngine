#include "Application.h"

#include "Aqua/Events//ApplicationEvent.h"
#include "Aqua/Log.h"

namespace Aqua {

	Application::Application()
	{
	}

	Application::~Application() 
	{
	}

	void Application::Run() 
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication)) 
		{
			AQ_TRACE(e);
		}

		if (e.IsInCategory(EventCategoryInput))
		{
			AQ_TRACE(e);
		}

		while (true);
	}


}