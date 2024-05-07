#pragma once

#ifdef AST_PLATFORM_WINDOWS
#ifdef AST_BUILD_DLL
	#define ASTRO_API __declspec(dllexport)
#else
	#define ASTRO_API __declspec(dllimport)
#endif
#else
#define ASTRO_API
#endif
