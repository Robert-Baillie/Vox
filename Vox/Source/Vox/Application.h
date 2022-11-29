#pragma once

#include "Core.h"
#include "pch.h"

namespace Vox {

	class VOX_API Application	// Assign the definition api - used in dll.
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		Window* mainWindow;

		static Application* instance;
	};

	// To be defined in the game application
	Application* CreateApplication();

}