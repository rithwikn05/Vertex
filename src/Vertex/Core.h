#pragma once

#ifdef VX_PLATFORM_WINDOWS
	#ifdef VX_BUILD_DLL
		#define VERTEX_API __declspec(dllexport)
	#else
		#define VERTEX_API __declspec(dllimport)

	#endif
#else
	#error Vertex only support Windows!
#endif

#define BIT(x) (1 << x)