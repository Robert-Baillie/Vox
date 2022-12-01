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

		// Event Dispatchers
		EventDispatcher<VoxEvents> VoxEventDispatcher;

		// Utility
		Window& GetWindow() { return *mainWindow; }
		static Application& GetApplication() { return *instance; }


		virtual void OnUpdate();

	private:
		// Window Pointer
		Window* mainWindow;


		// Singleton
		static Application* instance;


	};

	// To be defined in the game application
	Application* CreateApplication();

}