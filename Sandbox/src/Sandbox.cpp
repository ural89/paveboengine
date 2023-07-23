#include <Pavebo.h>
#include <stdio.h>

class Sandbox : public Pavebo::Application
{
	void Run() override
	{
		PaveboEngine::Log::GetClientLogger()->warn("app initialized!");
		while (true)
		{

		}
	}
};
Pavebo::Application* Pavebo::CreateApplication()
{

	return new Sandbox();
}