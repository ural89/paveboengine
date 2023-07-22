#include <Pavebo.h>

class Sandbox : public Pavebo::Application
{
};
Pavebo::Application* Pavebo::CreateApplication()
{

	return new Sandbox();
}