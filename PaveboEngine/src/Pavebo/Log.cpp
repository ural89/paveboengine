#include "Log.h"
namespace PaveboEngine
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	void Log::Init()
	{
		spdlog::set_pattern(" % ^[%T] %n: %v%$");
	}
}