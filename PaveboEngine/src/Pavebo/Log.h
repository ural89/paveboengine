#pragma once
#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Pavebo
{
	class PAVEBO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger(){ return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger(){ return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define PAVEBO_CORE_ERROR(...)	::Pavebo::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PAVEBO_CORE_WARN(...)	::Pavebo::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PAVEBO_CORE_INFO(...)   ::Pavebo::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PAVEBO_CORE_TRACE(...)  ::Pavebo::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PAVEBO_CORE_FATAL(...)  ::Pavebo::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define PAVEBO_ERROR(...)	::Pavebo::Log::GetClientLogger()->error(__VA_ARGS__)
#define PAVEBO_WARN(...)	::Pavebo::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PAVEBO_INFO(...)    ::Pavebo::Log::GetClientLogger()->info(__VA_ARGS__)
#define PAVEBO_TRACE(...)   ::Pavebo::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PAVEBO_FATAL(...)   ::Pavebo::Log::GetClientLogger()->fatal(__VA_ARGS__)