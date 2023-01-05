#include "Renderer2D.h"

namespace Vox {
	Renderer2D::Renderer2D()
	{
		// Default -> is called at start but should be overwritten
	}


	Renderer2D::Renderer2D(Shader& shader)
	{
		this->shader = shader;
		this->initRenderData();
		//VX_TRACE("The quadVAO now: {0}", this->quadVAO);

	}

	Renderer2D::~Renderer2D()
	{
		VX_TRACE("The quadVAO: {0}", this->quadVAO);	
		glDeleteVertexArrays(1, &this->quadVAO);
	}


	void Renderer2D::DrawSprite(Transform& transform, SpriteRenderer& spriteRenderer)
	{
		// TO IMPLEMENT - BATCHING (Currenlty having a draw call per sprite)
		
		// Set the uniform model and colour

		this->shader.Use();

		glm::mat4 model(1.0f);
		model = glm::translate(model, transform.Position); // Translate First

		model = glm::translate(model, glm::vec3(0.5f * transform.Scale.x, 0.5f * transform.Scale.y, 0.0f));  // Move origin

		model = glm::rotate(model, glm::radians(transform.Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); // then rotate
		model = glm::rotate(model, glm::radians(transform.Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); // then rotate
		model = glm::rotate(model, glm::radians(transform.Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)); // then rotate

		model = glm::translate(model, glm::vec3(-0.5f * transform.Scale.x, -0.5f * transform.Scale.y, -0.0f)); // move origin back

		model = glm::scale(model, transform.Scale); // last scale

		this->shader.SetMatrix4("model", model);


		this->shader.SetVector3f("spriteColor", spriteRenderer.Colour);

		glActiveTexture(GL_TEXTURE0);
		ResourceManager::GetTexture(spriteRenderer.TextureName).Bind();

	//	VX_CORE_TRACE("TRYING TO RENDER, ENTITY HAS TRANFORM X SIZE: {0} AND Pos.Y Pos: {1}", transform.Scale.x, transform.Position.y);
		

		// Bind the texture array
		glBindVertexArray(this->quadVAO);
		Texture::CheckError("glBindVertexArray");
		glDrawArrays(GL_TRIANGLES, 0, 6);
		Texture::CheckError("glDrawArrays");

		glBindVertexArray(0);
		Texture::CheckError("glBindVertexArray");

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