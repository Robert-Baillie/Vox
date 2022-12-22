#pragma once

#include "Window.h"
#include "Input.h"

#include "Scene/EntityComponentManager.h"
#include "Scene/Entity.h"


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

		// Running
		virtual void Update() {};

	private:
		// ECS
		EntityComponentManager* ecs;


		// Window Pointer
		Window* mainWindow;
		Input* input;

		
		// Singleton
		static Application* instance;

		// Helpers
		// FPS
		void printFrameCount();
		double lastTime;
		int nbFrames;

	};

	// To be defined in the game application
	Application* CreateApplication();

}