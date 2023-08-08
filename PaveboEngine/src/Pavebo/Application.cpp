#include "pvpch.h"
#include "Application.h"

#include "Pavebo/Log.h"
#include "Event/ApplicatoinEvent.h"
#include "Event/KeyEvent.h"
namespace Pavebo
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1200, 720);
		class KeyPressed kp(14);

		if (e.IsInCategory(EventCategoryApplication))
		{
			PAVEBO_TRACE(e.ToString());
		}
		PAVEBO_WARN(kp.ToString());
	}
	
}