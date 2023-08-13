#include "pvpch.h"
#include "Application.h"


#include "Event/ApplicatoinEvent.h"
#include "Platform/Windows/WindowsWindow.h"
#include <GLFW/glfw3.h>
namespace Pavebo
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)
	Application::Application()
	{
		/*WindowProps winProps = WindowProps();
		winProps.Width = 1200;
		winProps.Height = 720;
		winProps.Title = "Game";*/
		m_Window = std::unique_ptr<Window>(Window::Create());

		
		std::function<void(Pavebo::Event&) > eventCallback = BIND_EVENT_FN(OnEvent);
		
		m_Window->SetEventCallback(eventCallback);

	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Pavebo::Event& e)
	{
		PAVEBO_INFO(e.ToString());
	}
	
}