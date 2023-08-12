#pragma once
#include "Core.h"
#include "Event/Event.h"
#include "Window.h"
namespace Pavebo
{
	class PAVEBO_API Application
	{
	public:
		Application();
		virtual ~Application();
		virtual void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};
	Application* CreateApplication();
}
