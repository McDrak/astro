﻿#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Astro
{
	class ASTRO_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> CoreLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;
	};
}

// Core Log Macros
#define AST_CORE_TRACE(...)		::Astro::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AST_CORE_INFO(...)		::Astro::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AST_CORE_WARN(...)		::Astro::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AST_CORE_ERROR(...)		::Astro::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AST_CORE_FATAL(...)		::Astro::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define AST_TRACE(...)		::Astro::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AST_INFO(...)		::Astro::Log::GetClientLogger()->info(__VA_ARGS__)
#define AST_WARN(...)		::Astro::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AST_ERROR(...)		::Astro::Log::GetClientLogger()->error(__VA_ARGS__)
#define AST_FATAL(...)		::Astro::Log::GetClientLogger()->fatal(__VA_ARGS__)
