#include "Application.h"
#include "Pavebo/Log.h"
#include "Event/ApplicatoinEvent.h"
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
		PAVEBO_TRACE(e);
	}
	
}