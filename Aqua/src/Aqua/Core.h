#pragma once

// Defines whether or not the Aqua DLL needs to be imported or exported.
#ifdef AQ_PLATFORM_WINDOWS
	#ifdef AQ_BUILD_DLL
		#define AQUA_API __declspec(dllexport)
	#else
		#define AQUA_API __declspec(dllimport)
	#endif
#else
	#error Aqua only supports Windows currently!
#endif