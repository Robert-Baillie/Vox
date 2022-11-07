#pragma once

#include "Core.h"

namespace Vox {

	class VOX_API Application	// Assign the definition api - used in dll.
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in the game application
	Application* CreateApplication();

}