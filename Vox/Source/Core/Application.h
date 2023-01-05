#pragma once

#include "Window.h"
#include "Input.h"


#include "Scene/EntityComponentManager.h"	
#include "Scene/Entity.h"

#include "Scene/Systems/SystemManager.h"
#include "Scene/Systems/SpriteRendererSystem.h"

#include "Core/Resource/ResourceManager.h"
#include "Rendering/Renderer2D.h"

#include "Rendering/Shader.h"



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
		//std::shared_ptr<Renderer2D> GetRenderer2D() { return renderer2D; }
		static Application& GetApplication() { return *instance; }

		// Running
		virtual void Update() {};

	private:
		// ECS
		EntityComponentManager* entityComponentManager = nullptr;
		SystemManager* systemManager = nullptr;

		// Window Pointer
		Window* mainWindow = nullptr;
		Input* input = nullptr;
		Renderer2D* spriteRenderer = nullptr;


		// Renderer
		ResourceManager* resources = nullptr;
		
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