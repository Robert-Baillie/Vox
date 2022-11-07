#pragma once
#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Vox {

	class VOX_API Log
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
// Define error (...) passing in undetermined variables. When we do we want to call the core logger __VA_ARGS__ passing in the (...) from before
// Used to strip code out, core isn't needed in the client - so dont call functions
#define VX_CORE_TRACE(...) ::Vox::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define VX_CORE_INFO(...)  ::Vox::Log::GetCoreLogger()->info(__VA_ARGS__)
#define VX_CORE_WARN(...)  ::Vox::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define VX_CORE_ERROR(...) ::Vox::Log::GetCoreLogger()->error(__VA_ARGS__)
#define VX_CORE_FATAL(...) ::Vox::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Core Log Macros
// Define error (...) passing in undetermined variables. When we do we want to call the core logger __VA_ARGS__ passing in the (...) from before
#define VX_TRACE(...) ::Vox::Log::GetClientLogger()->trace(__VA_ARGS__)
#define VX_INFO(...)  ::Vox::Log::GetClientLogger()->info(__VA_ARGS__)
#define VX_WARN(...)  ::Vox::Log::GetClientLogger()->warn(__VA_ARGS__)
#define VX_ERROR(...) ::Vox::Log::GetClientLogger()->error(__VA_ARGS__)
#define VX_FATAL(...) ::Vox::Log::GetClientLogger()->fatal(__VA_ARGS__)