#include "Application.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Vox {
	Application* Application::instance = nullptr;

	Application::Application()
	{
		// Check instance for singleton
		if (instance) VX_CORE_ERROR("APP INSTANCE ALREADY EXISTS.");
		instance = this;


		// Initiate Window
		VX_CORE_INFO("Starting Window Initialisation");
		mainWindow = new Window();
		mainWindow->Initialise();
		VX_CORE_INFO("Window Initialisation Complete");


		// Initilise Input
		VX_CORE_INFO("Starting Input Initialisation");
		input = new Input;
		input->Initialise();
		VX_CORE_INFO("Input Initilation Complete");


		// Initialise Resources 
		VX_CORE_INFO("Starting Resource Initialisation");
		resources = new ResourceManager;
		resources->Initialise();
		VX_CORE_INFO("Resource Initilation Complete");



		// SHADERS
		VX_CORE_INFO("Starting Renderer Initialisation");

		// TEST - SHOULD BE CAMERA
		glm::mat4 projection = glm::ortho(0.0f, static_cast<float>(mainWindow->GetBufferWidth()), static_cast<float>(mainWindow->GetBufferHeight()),
			0.0f, -1.0f, 1.0f);

		ResourceManager::GetShader("SPRITE").Use().SetInteger("image", 0);
		ResourceManager::GetShader("SPRITE").SetMatrix4("projection", projection);

		Shader spriteShader = ResourceManager::GetShader("SPRITE");
		Renderer2D render = Renderer2D(spriteShader);
		renderer2D = std::make_shared<Renderer2D>(render); 
		VX_CORE_INFO("Renderer Initilation Complete");



		// Initialise ECS
		VX_CORE_INFO("Starting ECS Initialisation");
		entityComponentManager = new EntityComponentManager;
		systemManager = new SystemManager;

		// Initialising all Systems
		systemManager->RegisterSystem<SpriteRendererSystem>();


		// Update the Renderer on All
		for (std::shared_ptr<System> sys : systemManager->GetSystemList()) {
			sys->AssignRenderer(renderer2D);
		}
		VX_CORE_INFO("ECS Initilation Complete");



		


		// TEST 
		
		ResourceManager::LoadTexture("C:/Development/Vox/Vox/Source/Core/Resource/awesomeface.png", "face", true);

		
	}

	Application::~Application()
	{
		mainWindow->~Window();
	}



	void Application::Run()
	{
		// Get Frames
		lastTime = glfwGetTime();
		nbFrames = 0;


		while (!mainWindow->GetShouldClose())
		{
			// Get user inputs
			glfwPollEvents();
			// User Defined Update
			Update();

			// Assign Updates
			systemManager->Update();


			// Render Changes
			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			systemManager->Render();

			mainWindow->SwapBuffers();


			printFrameCount();
		}
	}

	
	

	void Application::printFrameCount()
	{
		// Measure speed
		double currentTime = glfwGetTime();
		nbFrames++;
		if (currentTime - lastTime >= 1.0) { // If last prinf() was more than 1 sec ago
			// printf and reset timer
			VX_CORE_TRACE("Frame Rate: {0}", nbFrames);
			//printf("%f ms/frame\n", 1000.0 / double(nbFrames));
			nbFrames = 0;
			lastTime += 1.0;

		}
	}

}