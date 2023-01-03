#include "Texture.h"



namespace Vox {
	Texture::Texture() : Width(0), Height(0),
		InternalFormat(GL_RGB), ImageFormat(GL_RGB),
		WrapS(GL_REPEAT), WrapT(GL_REPEAT),
		FilterMin(GL_LINEAR), FilterMax(GL_LINEAR)
	{
		VX_TRACE("Texture ID Before: {0}", this->TextureID);
		glGenTextures(1, &this->TextureID); // Reference to this pointer (simply the ID???)
		VX_TRACE("Texture ID After: {0}", this->TextureID);

	}


	void Texture::Generate(unsigned int width, unsigned int height, unsigned char* data)
	{
		this->Width = width;
		this->Height = height;

		// Create the textures
		glBindTexture(GL_TEXTURE_2D, this->TextureID);
		glTexImage2D(GL_TEXTURE_2D, 0, this->InternalFormat, width, height, 0, this->ImageFormat, GL_UNSIGNED_BYTE, data);

		// Set texture wrap and filter modes
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, this->WrapS);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, this->WrapT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, this->FilterMin);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, this->FilterMax);

		// Unbind
		glBindTexture(GL_TEXTURE_2D, 0);

	}

	void Texture::Bind() 
	{
		glBindTexture(GL_TEXTURE_2D, this->TextureID);
		checkError("glBindTexture");
	}

	GLuint Texture::checkError(const char* context)
	{
		GLuint err = glGetError();
		if (err > 0) {
			VX_CORE_ERROR("0x{0} glGetError() in {1}", err, context);

		}
		return err;
	}
}
