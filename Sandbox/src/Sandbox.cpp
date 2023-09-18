#include <Pavebo.h>
#include <stdio.h>
#include "Pavebo/Event/KeyEvent.h"

class ExampleLayer : public Pavebo::Layer
{
	void OnUpdate() override
	{
		//PAVEBO_INFO("Updating layer");
	}
	void OnEvent(Pavebo::Event& event) override
	{
		PAVEBO_TRACE(event.ToString());
	}
	
};
class Sandbox : public Pavebo::Application
{
public:
	Sandbox()
	{
		PushOverlay(new Pavebo::DebugOverlayLayer());
	}
	~Sandbox(){}
	void Run() override
	{
		
		Application::Run();
		
	}

};
Pavebo::Application* Pavebo::CreateApplication()
{

	return new Sandbox();
}