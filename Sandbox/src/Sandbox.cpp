#include <Pavebo.h>
#include <stdio.h>

class Sandbox : public Pavebo::Application
{
	void Run() override
	{
		PAVEBO_INFO("APP running");
		while (true)
		{

		}
	}
};
Pavebo::Application* Pavebo::CreateApplication()
{

	return new Sandbox();
}