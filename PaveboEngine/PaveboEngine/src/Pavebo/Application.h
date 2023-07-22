#pragma once
#include "Core.h"
namespace Pavebo
{
	class PAVEBO_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

	};
	Application* CreateApplication();
}
