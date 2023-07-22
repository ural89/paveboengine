#pragma once
#include <stdio.h>
//#ifdef PAVEBO_PLATFORM_WINDOWS
extern Pavebo::Application* Pavebo::CreateApplication(); //extern means definition is in another place

int main(int argc, char** argv)
{
	printf("Starting app\n");
	auto app = Pavebo::CreateApplication();
	app->Run();
	delete app;
}

//#endif