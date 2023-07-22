#include <Pavebo.h>
#include <stdio.h>
class Sandbox : public Pavebo::Application
{
	void Run() override
	{
		printf("running app");
		while (true)
		{

		}
	}
};
Pavebo::Application* Pavebo::CreateApplication()
{

	return new Sandbox();
}