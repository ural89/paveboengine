#include <Pavebo.h>
#include <stdio.h>
#include "Pavebo/Event/KeyEvent.h"
class Sandbox : public Pavebo::Application
{

	void Run() override
	{
		Application::Run();
		PAVEBO_INFO("APP running");
		class Pavebo::KeyPressed kp(21);
		Pavebo::EventDispatcher dispatcher = Pavebo::EventDispatcher(kp);
		dispatcher.fn = std::bind(&Sandbox::OnKeyPressed, this);
		dispatcher.InvokeFN();
		//dispatcher.Dispatch<Pavebo::KeyPressed>(Sandbox::OnKeyPressed); //TODO: dispatch sample
		PAVEBO_TRACE(kp.ToString());
		while (true)
		{

		}
	}

	void OnKeyPressed() const
	{
		PAVEBO_INFO("Invoked fn");
	}
};
Pavebo::Application* Pavebo::CreateApplication()
{

	return new Sandbox();
}