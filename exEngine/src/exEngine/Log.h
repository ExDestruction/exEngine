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



