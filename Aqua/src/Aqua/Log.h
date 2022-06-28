#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"


namespace Aqua 
{
	class AQUA_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core Log Macros
#define AQ_CORE_TRACE(...) ::Aqua::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AQ_CORE_INFO(...)  ::Aqua::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AQ_CORE_WARN(...)  ::Aqua::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AQ_CORE_ERROR(...) ::Aqua::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AQ_CORE_FATAL(...) ::Aqua::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define AQ_TRACE(...) ::Aqua::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AQ_INFO(...)  ::Aqua::Log::GetClientLogger()->info(__VA_ARGS__)
#define AQ_WARN(...)  ::Aqua::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AQ_ERROR(...) ::Aqua::Log::GetClientLogger()->error(__VA_ARGS__)
#define AQ_FATAL(...) ::Aqua::Log::GetClientLogger()->fatal(__VA_ARGS__)