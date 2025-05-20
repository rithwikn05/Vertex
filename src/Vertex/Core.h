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

#ifdef VX_ENABLE_ASSERTS
	#define VX_ASSERT(x, ...) {if (!x) {VX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define VX_CORE_ASSERT(x, ...) {if (!x) {VX_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define VX_ASSERT(x, ...)
	#define VX_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)