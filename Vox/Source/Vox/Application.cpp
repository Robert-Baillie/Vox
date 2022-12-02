
#include "Application.h"
#include <stdio.h>
#include <iostream>

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

	

	}

	Application::~Application()
	{
		mainWindow->~Window();
	}


	void Application::Run()
	{
		while (!mainWindow->GetShouldClose())
		{
			// Get user inputs
			glfwPollEvents();

			glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);


			mainWindow->SwapBuffers();

			OnUpdate();
		}
	}

	void Application::OnUpdate()
	{
		
	}
}