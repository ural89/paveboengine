#include "pvpch.h"
#include "Application.h"


#include "Platform/Windows/WindowsWindow.h"
#include <GLFW/glfw3.h>
namespace Pavebo
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;
	Application::Application()
	{
		if (s_Instance != nullptr)
			PAVEBO_CORE_ERROR("More than one instance of application created!");
		s_Instance = this;

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

			OnUpdate();

			m_Window->OnUpdate();
		}
	}

	void Application::OnEvent(Pavebo::Event& e)
	{
		EventDispatcher ed = EventDispatcher(e);
		ed.Dispatch(BIND_EVENT_FN(OnApplicationQuit), EventType::WindowClose);
		
		//PAVEBO_CORE_TRACE(e.ToString());
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.IsHandled())
			{
				break;
			}
		}
	}

	void Application::OnUpdate()
	{
		for (auto layer : m_LayerStack)
		{
			layer->OnUpdate();
		}
	}

	void Application::PushLayer(Layer* layer)
	{

		m_LayerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
	}

	void Application::OnApplicationQuit(Event& e)
	{
		PAVEBO_ERROR("Application quit");
	}
	
}