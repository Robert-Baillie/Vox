#pragma once

#include "pch.h"
namespace Vox
{

	/// Window class - handles initialisation and holds utility functions
	/// NOTE - THIS SHOULD HAVE VIRTUALISED FUNCTIONS FOR SPECIFIC PLATFORMS TO THEN INHERIT THEIR OWN - FOR NOW IT IS WINDOWS ONLY
	class Window
	{
	public:
		// Constructor - defualt size
		Window(GLint windowWidth = 800, GLint windowHeight = 600);

		// Deconstructor - clean delete
		~Window();

		// Initialise - Handles GLFW Set Up - GLEW/GLAD will need to be initialised too.
		// Callback events held in nApplication
		void Initialise();

		// Uitility Functions
		GLint GetBufferWidth(){ return bufferWidth; }
		GLint GetBufferHeight(){ return bufferHeight; }

		void SetWindowDimension(GLint x, GLint y){ width = x; height = y; }
		void SetBufferDimensios(GLint x, GLint y){ bufferWidth = x; bufferHeight = y; }

		bool GetShouldClose() { return glfwWindowShouldClose(window); }

		// Swap Buffers - Called by engine/applicationn on each loop
		void SwapBuffers() { glfwSwapBuffers(window); }



	protected:
		// Properties
		GLFWwindow* window;
		GLint width, height;
		GLint bufferWidth, bufferHeight;

		
	};

}