#pragma once

//#ifdef PAVEBO_PLATFORM_WINDOWS
extern Pavebo::Application* Pavebo::CreateApplication(); //extern means definition is in another place

int main(int argc, char** argv)
{
	Pavebo::Log::Init();
	PAVEBO_CORE_WARN("Logger initialized!!!");
	Pavebo::Application* app = Pavebo::CreateApplication();
	app->Run();
	delete app;
}

//#endif