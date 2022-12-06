#pragma once
 
// If are on windows define, on build define api to export, else use to import
#ifdef VX_PLATFORM_WINDOWS
	#ifdef VX_BUILD_DLL
		#define VOX_API __declspec(dllexport) // Building library this is active
	#else 
		#define VOX_API __declspec(dllimport) // In Sandbox (any other app call) this is active
	#endif
#else
	#error Vox only supports Windows.
#endif


