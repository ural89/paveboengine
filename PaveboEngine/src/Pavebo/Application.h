#pragma once
#include "Core.h"
#include "Event/Event.h"
namespace Pavebo
{
	class PAVEBO_API Application
	{
	public:
		Application();
		virtual ~Application();
		virtual void Run();

	};
	Application* CreateApplication();
}
