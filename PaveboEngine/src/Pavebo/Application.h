#pragma once
#include "Core.h"
#include "Event/Event.h"
#include "Layer/LayerStack.h"
#include "Event/ApplicatoinEvent.h"
#include "Window.h"
namespace Pavebo
{
	class PAVEBO_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		virtual void Run();

		void OnEvent(Event &e);

		void OnUpdate();
		
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& GetApplication()  { return *s_Instance; }
		inline Window& GetWindow()  { return *m_Window; }
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
		void OnApplicationQuit(Event& e);
	private:
		static Application* s_Instance;
	};
	Application* CreateApplication();
}
