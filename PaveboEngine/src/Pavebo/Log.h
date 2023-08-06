#pragma once
#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace PaveboEngine
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

#define PAVEBO_CORE_ERROR(...)	::PaveboEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PAVEBO_CORE_WARN(...)	::PaveboEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PAVEBO_CORE_INFO(...)   ::PaveboEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PAVEBO_CORE_TRACE(...)  ::PaveboEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PAVEBO_CORE_FATAL(...)  ::PaveboEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

#define PAVEBO_ERROR(...)	::PaveboEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define PAVEBO_WARN(...)	::PaveboEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PAVEBO_INFO(...)    ::PaveboEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define PAVEBO_TRACE(...)   ::PaveboEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PAVEBO_FATAL(...)   ::PaveboEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)