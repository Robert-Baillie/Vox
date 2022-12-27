#pragma once

#include "Window.h"
#include "Input.h"


#include "Scene/EntityComponentManager.h"	
#include "Scene/Entity.h"

#include "Scene/Systems/SystemManager.h"
#include "Scene/Systems/TestSystem.h"

namespace Vox {

	class VOX_API Application	// Assign the definition api - used in dll.
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		// Event Dispatchers
		EventDispatcher<VoxEvents> InputEventDispatcher;
		EventDispatcher<SystemEvents> SystemEventDispatcher;

		// Utility
		Window& GetWindow() { return *mainWindow; }
		static Application& GetApplication() { return *instance; }

		// Running
		virtual void Update() {};

	private:
		// ECS
		EntityComponentManager* entityComponentManager;
		SystemManager* systemManager;

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