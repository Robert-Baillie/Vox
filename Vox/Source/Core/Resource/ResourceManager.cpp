#include "ResourceManager.h"

#include <fstream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"





namespace Vox {
	ResourceManager* ResourceManager::instance = nullptr;



	ResourceManager::ResourceManager() {};

	ResourceManager::~ResourceManager()
	{
		// On Destroy, we have to destroy every resource correctly
		// Shader
		for (auto shaderMap : shaders)
		{
			// Shader no longer needed - should be marked for deletion already, so clear the program
			glDeleteProgram(shaderMap.second.ShaderID);
		}

		// Textures
		for (auto textureMap : textures)
		{
			glDeleteTextures(1, &textureMap.second.TextureID);
		}

		// Clear all maps
		shaders.clear();
		textures.clear();
	}


	void ResourceManager::Initialise()
	{
		if (instance) VX_CORE_ERROR("INSTANCE INSTANCE ALREADY EXISTS.");
		instance = this;

		/// Shaders
		LoadShader("C:/Development/Vox/Vox/Source/Core/Resource/SpriteShaderV.shader", "C:/Development/Vox/Vox/Source/Core/Resource/SpriteShaderF.shader", nullptr, "SPRITE"); // Works with full address...
		VX_CORE_INFO("Sprite Shader Loaded.");

		// Textures
		LoadTexture("C:/Development/Vox/Vox/Source/Core/Resource/awesomeface.png", "face", true);
		VX_CORE_INFO("Test Texture Loaded.");


	}


	// Shaders
	Shader ResourceManager::LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name)
	{

		instance->shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);

	
		return instance->shaders[name];
	}

	Shader ResourceManager::GetShader(std::string name) { return instance->shaders[name]; }


	// Textures
	Texture ResourceManager::LoadTexture(const char* filePath, std::string name, bool isAlpha)
	{
		instance->textures[name] = loadTextureFromFile(filePath, isAlpha);


		return instance->textures[name];
	}

	Texture ResourceManager::GetTexture(std::string name) { return instance->textures[name]; }


	// Loading
	Shader ResourceManager::loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile)
	{
		// Create the strings from the files
		std::string vertexString = readFile(vShaderFile);

		std::string fragmentString = readFile(fShaderFile);
		std::string geometryString = "";
		if (gShaderFile != nullptr) geometryString = readFile(gShaderFile);

		// Create the code
		const char* vertexCode = vertexString.c_str();
		const char* fragmentCode = fragmentString.c_str();
		const char* geometryCode = "";
		if (gShaderFile != nullptr) geometryCode = geometryString.c_str();


		// Create the shader, compile and return
		Shader shader;
		shader.Compile(vertexCode, fragmentCode, gShaderFile != nullptr ? geometryCode : nullptr);

		return shader;
	}

	Texture ResourceManager::loadTextureFromFile(const char* file, bool isAlpha)
	{
		// Create the texture
		Texture tex;

		// If alpha enabled, change the format of the texture
		if (isAlpha)
		{
			tex.InternalFormat = GL_RGBA;
			tex.ImageFormat = GL_RGBA;
		}

		// Load image via stbi
		int width, height, nrChannels;
		unsigned char* texData = stbi_load(file, &width, &height, &nrChannels, 0); // May need STBI_rgb to be 0
		// Error check
		

		if (!texData)
		{
			VX_CORE_ERROR("Failed to find {0}", file);
		}
		

		// Generate the texture
		tex.Generate(width, height, texData);
		VX_CORE_INFO("Texture Generate Done");

		// Free the image data
		stbi_image_free(texData);

		return tex;
	}


	std::string ResourceManager::readFile(const char* fileLocation)
	{
		std::string content;
		std::ifstream fileStream(fileLocation, std::ios::in);
		VX_CORE_ERROR("CURRENTLY LOOKING DIRECTLY FOR FULL ADDRESS - MUST CHANGE: {0}", fileLocation);

		if (!fileStream.is_open())
		{
			VX_CORE_ERROR("Failed to read {0}! File doesn't exist.", fileLocation);
			return "";
		}

		std::string line = "";
		while (!fileStream.eof()) // Whilst not the end of file
		{
			std::getline(fileStream, line);
			content.append(line + "\n");
		}

		fileStream.close();
		return content;

	}
}