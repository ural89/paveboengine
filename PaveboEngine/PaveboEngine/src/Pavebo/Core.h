#pragma once
#ifdef PAVEBO_PLATFORM_WINDOWS
	#ifdef DLL_EXPORT
		#define PAVEBO_API __declspec(dllexport)
	#else
		#define PAVEBO_API __declspec(dllimport)
	#endif


#endif