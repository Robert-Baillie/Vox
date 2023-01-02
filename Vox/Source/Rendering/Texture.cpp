#include "Texture.h"



namespace Vox {
	Texture::Texture()
	{
		Width = 0;
		Height = 0;

		InternalFormat = GL_RGB;
		ImageFormat = GL_RGB;

		WrapS = GL_REPEAT;
		WrapT = GL_REPEAT;

		FilterMin = GL_LINEAR;
		FilterMax = GL_LINEAR;


		// Assign the id on construction
		glGenTextures(1, &this->TextureID);
		checkError("glGenTextures");

	}

	void Texture::Generate(GLuint width, GLuint height, unsigned char* data)
	{
		/// Assign the data
		this->Width = width;
		this->Height = height;

		// Create the textures
		glBindTexture(GL_TEXTURE_2D, this->TextureID);
		checkError("glBindTexture");

		glTexImage2D(GL_TEXTURE_2D, 0, this->InternalFormat, width, height, 0, this->ImageFormat, GL_UNSIGNED_BYTE, data);

		// Set Texture Wrap and Filter modes
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->WrapS);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->WrapT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->FilterMin);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->FilterMax);

		// Unbind texture 2D
		glBindTexture(GL_TEXTURE_2D, 0);
		
		checkError("glBindTexture");

	}

	GLuint Texture::checkError(const char* context)
	{
		GLuint err = glGetError();
		if (err > 0) {
			std::cout << "0x" << std::hex << err << " glGetError() in " << context
				<< std::endl;
		}
		return err;
	}

	void Texture::Bind()
	{

		glBindTexture(GL_TEXTURE_2D, this->TextureID);
		checkError("glBindTexture");

	}
}