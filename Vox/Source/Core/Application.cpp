#include "Application.h"


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
		input = new Input;
		input->Initialise();

	
#include "spdlog/sinks/stdout_color_sinks.h"

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

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


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