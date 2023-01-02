#include "Renderer2D.h"

namespace Vox {

	Renderer2D::Renderer2D(Shader& shader)
	{
		this->shader = shader;
		this->initRenderData();
	}

	Renderer2D::~Renderer2D()
	{
		glDeleteVertexArrays(1, &this->quadVAO);
	}


	void Renderer2D::DrawSprite(Transform& transform, SpriteRenderer& spriteRenderer)
	{
		// Set the uniform model and colour

		this->shader.Use();

		this->shader.SetMatrix4("model", GetTransformModel(transform));
		this->shader.SetVector3f("spriteColor", spriteRenderer.Colour);

		glActiveTexture(GL_TEXTURE0);
		Texture tex = ResourceManager::GetTexture(spriteRenderer.TextureName);
		tex.Bind();


	//	VX_CORE_TRACE("TRYING TO RENDER, ENTITY HAS TRANFORM X SIZE: {0} AND Pos.Y Pos: {1}", transform.Scale.x, transform.Position.y);
		

		// Bind the texture array
		glBindVertexArray(this->quadVAO);
		glDrawArrays(GL_TRIANGLES, 0, 6);

		// Unbind
		glBindVertexArray(0);
	}




	void Renderer2D::initRenderData()
	{
		// Configure the VBO
		GLuint VBO;

		// Vertices array
		float vertices[] = {
			// pos      // tex
			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f,
			0.0f, 0.0f, 0.0f, 0.0f,

			0.0f, 1.0f, 0.0f, 1.0f,
			1.0f, 1.0f, 1.0f, 1.0f,
			1.0f, 0.0f, 1.0f, 0.0f
		};

		// Only need one VAO - all sprites share vertex data
		glGenVertexArrays(1, &this->quadVAO);
		glGenBuffers(1, &VBO);

		// Bind the VBO
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// Bind VAO
		glBindVertexArray(this->quadVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
		glBindVertexArray(0);
	}




}