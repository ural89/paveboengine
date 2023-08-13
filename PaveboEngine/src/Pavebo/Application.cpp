#include "pvpch.h"
#include "Application.h"


#include "Event/ApplicatoinEvent.h"
#include "Platform/Windows/WindowsWindow.h"
#include <GLFW/glfw3.h>
namespace Pavebo
{
	Application::Application()
	{
		WindowProps winProps = WindowProps();
		winProps.Width = 1200;
		winProps.Height = 720;
		winProps.Title = "Game";
		
		m_Window = std::unique_ptr<Window>(Window::Create(winProps));
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
	
}