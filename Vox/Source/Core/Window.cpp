#include "Window.h"
#include "Application.h"

namespace Vox{
	// Declarations
	void windowSizeCallback(GLFWwindow* window, int width, int height);
	void windowCloseCallback(GLFWwindow* window);
	void framebufferSizeCallback(GLFWwindow* window, int width, int height);
	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
	void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
	void mousePosCallback(GLFWwindow* window, double xpos, double ypos);

	Window::Window(GLint windowWidth, GLint windowHeight) {
		width = windowWidth;
		height = windowHeight;
	}

	Window::~Window()
	{
		// Destroy and terminate
		glfwDestroyWindow(window);
		glfwTerminate();
	}

	void Window::Initialise()
	{
		

		// Initialise GLFW - print errors
		if (!glfwInit())
		{
			VX_CORE_ERROR("GLFW Initialisation Failed!");
			glfwTerminate();
			return;
		}

		// Set Up Standard GLFW Window properties
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Set Major Version to 3
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); // Set Minor Version to 3
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // No backwards compatability
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Allow Forward Compatiblity
		
	//	 glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_FALSE); // Frame limiter - disable to test

		// Create Window and return any errors
		window = glfwCreateWindow(width, height, "Vox Engine", NULL, NULL);

		if (!window)
		{
			VX_CORE_ERROR("GLFW window creation failed!");
			glfwTerminate();
			return;
		}

		// Assign buffer refferences
		glfwGetFramebufferSize(window, &bufferWidth, &bufferHeight);

		// Set Context
		glfwMakeContextCurrent(window);

		// Set Callbacks
		// Window
		glfwSetWindowSizeCallback(window, windowSizeCallback);
		glfwSetWindowCloseCallback(window, windowCloseCallback);

		glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

		// Key
		glfwSetKeyCallback(window, keyCallback);
		 
		// Mouse
		glfwSetMouseButtonCallback(window, mouseButtonCallback);
		glfwSetScrollCallback(window, mouseScrollCallback);
		glfwSetCursorPosCallback(window, mousePosCallback);

		// Open GL initialisation
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			VX_CORE_ERROR("Failed to initialise GLAD");
			glfwDestroyWindow(window);
			glfwTerminate();
			return;
		}

		// Enables
		glEnable(GL_BLEND);
	
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	

		// Viewport
		glViewport(0, 0, bufferWidth, bufferHeight);
	
		// Assign the user pointer
		glfwSetWindowUserPointer(window, this);

	}

	/* CALLBACK FUNCTIONS*/

	// Window
	void windowSizeCallback(GLFWwindow* window, int width, int height)
	{

		// Assign the main window
		Window* mainWindow = (Window*)glfwGetWindowUserPointer(window);
		mainWindow->SetWindowDimension(width, height); // CALLING THIS CRASHES

		// Dispatch event to subscribers
		WindowResizeEvent event(width, height);
		Application::GetApplication().InputEventDispatcher.Dispatch(event);
		//Vox::EventDispatcher<VoxEvents>().Dispatch(event);

	}

	void windowCloseCallback(GLFWwindow* window)
	{
		// Dispatch event to subscribers
		WindowClosedEvent event;
		Application::GetApplication().InputEventDispatcher.Dispatch(event);
		//Vox::EventDispatcher<VoxEvents>().Dispatch(event);
	}

	void framebufferSizeCallback(GLFWwindow* window, int width, int height)
	{
		// No event - set the viewport size - this may be needed for resizing
		glViewport(0, 0, width, height);
	}


	// Key
	void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		// For each action type do something

		if (action == GLFW_PRESS)
		{
			KeyPressedEvent event(key, 0);
			Application::GetApplication().InputEventDispatcher.Dispatch(event);
			//Vox::EventDispatcher<VoxEvents>().Dispatch(event);
			return;
		} 

		else if (action == GLFW_RELEASE)
		{
			KeyReleasedEvent event(key);
			Application::GetApplication().InputEventDispatcher.Dispatch(event);
			//Vox::EventDispatcher<VoxEvents>().Dispatch(event);
			return;
		}

		else if (action == GLFW_REPEAT)
		{
			KeyPressedEvent event(key, 1);
			Application::GetApplication().InputEventDispatcher.Dispatch(event);
			//Vox::EventDispatcher<VoxEvents>().Dispatch(event);
			return;
		}
	}

	// Mouse
	void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
	{
		if (action == GLFW_PRESS)
		{
			MouseButtonPressedEvent event(button);
			Application::GetApplication().InputEventDispatcher.Dispatch(event);
			//Vox::EventDispatcher<VoxEvents>().Dispatch(event);
			return;
		}

		else if (action == GLFW_RELEASE)
		{
			MouseButtonReleasedEvent event(button);
			Application::GetApplication().InputEventDispatcher.Dispatch(event);
			//Vox::EventDispatcher<VoxEvents>().Dispatch(event);
			return;
		}
	}

	void mouseScrollCallback(GLFWwindow* window, double xoffset, double yoffset)
	{
		MouseScrolledEvent event((float)xoffset, (float)yoffset);
		Application::GetApplication().InputEventDispatcher.Dispatch(event);
		//Vox::EventDispatcher<VoxEvents>().Dispatch(event);
	}

	void mousePosCallback(GLFWwindow* window, double xpos, double ypos)
	{
		MouseMovedEvent event((float)xpos, (float)ypos);
		Application::GetApplication().InputEventDispatcher.Dispatch(event);
		//Vox::EventDispatcher<VoxEvents>().Dispatch(event);
	}
}
