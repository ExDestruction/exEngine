#pragma once


#include <memory>

#include "core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace exEngine 
{
	class EX_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& get_core_logger() { return s_core_logger; }
		inline static std::shared_ptr<spdlog::logger>& get_client_logger() { return s_client_logger; }
	private:
		static std::shared_ptr<spdlog::logger> s_client_logger;
		static std::shared_ptr<spdlog::logger> s_core_logger;

	};
}

//Macroses for core logs
#define EX_CORE_TRACE(...)    ::exEngine::Log::get_core_logger()->trace(__VA_ARGS__)
#define EX_CORE_INFO(...)     ::exEngine::Log::get_core_logger()->info(__VA_ARGS__)
#define EX_CORE_WARN(...)     ::exEngine::Log::get_core_logger()->warn(__VA_ARGS__)
#define EX_CORE_ERROR(...)    ::exEngine::Log::get_core_logger()->error(__VA_ARGS__)
#define EX_CORE_FATAL(...)    ::exEngine::Log::get_core_logger()->fatal(__VA_ARGS__)


//Macroses for client logs
#define EX_TRACE(...)		  ::exEngine::Log::get_client_logger()->trace(__VA_ARGS__)
#define EX_INFO(...)		  ::exEngine::Log::get_client_logger()->info(__VA_ARGS__)
#define EX_WARN(...)		  ::exEngine::Log::get_client_logger()->warn(__VA_ARGS__)
#define EX_ERROR(...)		  ::exEngine::Log::get_client_logger()->error(__VA_ARGS__)
#define EX_FATAL(...)		  ::exEngine::Log::get_client_logger()->fatal(__VA_ARGS__)

