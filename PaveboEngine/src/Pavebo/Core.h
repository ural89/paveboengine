#pragma once
#ifdef PAVEBO_PLATFORM_WINDOWS
	#ifdef PV_BUILD_DLL
		#define PAVEBO_API __declspec(dllexport)
	#else
		#define PAVEBO_API __declspec(dllimport)
	#endif


#endif

#define BIT(x) (1 << x)