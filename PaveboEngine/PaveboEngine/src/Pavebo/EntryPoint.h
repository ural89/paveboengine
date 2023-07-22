#pragma once

//#ifdef PAVEBO_PLATFORM_WINDOWS
extern Pavebo::Application* Pavebo::CreateApplication(); //extern means definition is in another place

int main(int argc, char** argv)
{
	auto app = Pavebo::CreateApplication();
	app->Run();
	delete app;
}

//#endif