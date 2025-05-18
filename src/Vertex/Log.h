#pragma once
#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Vertex {
	class VERTEX_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger> & GetCoreLogger() { return s_CoreLogger;}
		inline static std::shared_ptr<spdlog::logger> & GetClientLogger() { return s_ClientLogger;}

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core Logging macros
#define VX_CORE_TRACE(...)  ::Vertex::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VX_CORE_INFO(...)   ::Vertex::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VX_CORE_WARN(...)   ::Vertex::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VX_CORE_ERROR(...)  ::Vertex::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VX_CORE_FATAL(...)  ::Vertex::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Logging macros
#define VX_TRACE(...)       ::Vertex::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VX_INFO(...)        ::Vertex::Log::GetClientLogger()->info(__VA_ARGS__)
#define VX_WARN(...)        ::Vertex::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VX_ERROR(...)       ::Vertex::Log::GetClientLogger()->error(__VA_ARGS__)
#define VX_FATAL(...)       ::Vertex::Log::GetClientLogger()->fatal(__VA_ARGS__)

