#pragma once


#include "Core/Log.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"



namespace Vox {

	/// <summary>
	/// Texture to store and configure openGL
	/// Utility functions for easy setup and management
	/// </summary>
	class Texture
	{
	public:
		// Constructor - assign all values
		Texture();

		// Texture Variables
		// ID for texture operations
		GLuint TextureID;

		// Image dimensions
		GLuint Width, Height;

		// Formatting
		GLuint InternalFormat, ImageFormat;

		// Configuration
		GLuint WrapS, WrapT;
		GLuint FilterMin, FilterMax;

		// Generate the texture from the configuration and image data (used with stb)
		void Generate(GLuint width, GLuint height, unsigned char* data);

		// Texture binding - binds to active GL_TEXTURE_2D object
		 void Bind() ;


		static GLuint CheckError(const char* context);

	};

}
