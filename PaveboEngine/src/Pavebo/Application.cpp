#include "pvpch.h"
#include "Application.h"


#include "Event/ApplicatoinEvent.h"
#include "Platform/Windows/WindowsWindow.h"
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
			m_Window->OnUpdate();
		}
	}
	
}