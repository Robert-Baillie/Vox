#pragma once
#include <glm/glm.hpp>
#include <glad/glad.h>


#include "Shader.h"
#include "Texture.h"

#include "Core/Components/Transform.h"
#include "Core/Components/SpriteRenderer.h"



namespace Vox {
	/// <summary>
	/// Sprite Renderer Component.
	/// Holds the Shader and VAO.
	/// 
	/// Draw Sprite called every update.
	/// </summary>
	class Renderer2D
	{
	public:
		// Constructor - Initialises shaders
		Renderer2D(); // Default

		Renderer2D(Shader& shader);

		// Deconstructor - Clears VAO
		~Renderer2D();

		// Draw Sprite-> Renders a defined quad texure with given sTexture
		// Default to a standard size/colour if not given
		void DrawSprite(Transform& transform, SpriteRenderer& spriteRenderer);


		
	private:
		// Render States - can it be a pointer
		Shader shader;
		GLuint quadVAO;

		// Initialise data - configure quad buffer and vertex attribute
		void initRenderData();



	};
}

