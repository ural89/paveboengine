#pragma once
#include "Core.h"
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