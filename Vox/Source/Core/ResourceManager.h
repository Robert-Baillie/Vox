#pragma once
#include "pch.h"	

#include "Rendering/Shader.h"
#include "Rendering/Texture.h"

// Stolen from my learning project
namespace Vox {

	/// <summary>
	/// Resource Manager created - hosts several static functions to load files that can be called from anywhere
	/// Each file is stored in its specific map for ffuture reference
	/// </summary>
	class ResourceManager
	{
	public:
		// Constructor
		ResourceManager();
		// Deconstructor called by engine - clean delete everything
		~ResourceManager();

		// Initialise - Create Shaders, Load in any default textures etc..
		void Initialise();


		// Static Utility Functions
		// Shaders
		static Shader LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);
		static Shader GetShader(std::string name);

		// Textures
		static Texture  LoadTexture(const char* filePath, std::string name, bool isAlpha);
		static Texture  GetTexture(std::string name);

	private:
		// Maps for holding
		std::map <std::string, Shader> shaders;
		std::map <std::string, Texture> textures;

		// Helper methods
		// 
		// Loads and returns a shader from a file
		static Shader    loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);

		// Loads and returns a texture from a file
		static Texture loadTextureFromFile(const char* file, bool isAlpha);

		// Reads and individual file
		static std::string readFile(const char* fileLocation);
	};

	static ResourceManager Resources;
}

