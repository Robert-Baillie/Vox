#include "Texture.h"
#include <iostream> // Only for hex printing



namespace Vox {
	Texture::Texture() : Width(0), Height(0),
		InternalFormat(GL_RGB), ImageFormat(GL_RGB),
		WrapS(GL_REPEAT), WrapT(GL_REPEAT),
		FilterMin(GL_LINEAR), FilterMax(GL_LINEAR)
	{
		glGenTextures(1, &this->TextureID); // Reference to this pointer (simply the ID???)

	}


	void Texture::Generate(unsigned int width, unsigned int height, unsigned char* data)
	{
		this->Width = width;
		this->Height = height;
		if (data == nullptr) VX_TRACE("NO DATA GENERATED.");


		// Create the textures
		glBindTexture(GL_TEXTURE_2D, this->TextureID);
		glTexImage2D(GL_TEXTURE_2D, 0, this->InternalFormat, width, height, 0, this->ImageFormat, GL_UNSIGNED_BYTE, data);
		CheckError("glTexImage2D");


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

	/*	DWORD threadId = GetCurrentThreadId();
		VX_TRACE("Thread ID on Texture Bind: {0}", threadId);*/


		// Check Open GL Context on WIndow, App and this:
	/*	HGLRC hglrc = wglGetCurrentContext();
		if (hglrc) {
			VX_CORE_INFO("The GL Context Exists");
		}
		else {
			VX_CORE_WARN("The GL Context Does Not Exists");
		}
		*/
		// Check Texture Exists
		//if (glIsTexture(this->TextureID)) VX_CORE_INFO("The Texture ID {0} exists", this->TextureID);
		//else VX_CORE_INFO("The Texture ID {0} does not exist", this->TextureID);
	
		// Bind
		glBindTexture(GL_TEXTURE_2D, this->TextureID);
		CheckError("glBindTexture");
	}

	GLuint Texture::CheckError(const char* context)
	{
		GLuint err = glGetError();
		if (err > 0) {
			std::cout << "0x" << std::hex << err << " glGetError() in " << context
				<< std::endl;

		}
		return err;
	}
}
