#include "Shader.h"


namespace Vox {
	Shader& Shader::Use()
	{
		glUseProgram(this->ShaderID);
		return *this;
	}


	void Shader::Compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource)
	{
		GLuint vert, frag, geom;

		// Assign the shader ID

		this->ShaderID = glCreateProgram();

		if (!this->ShaderID)
		{
			VX_CORE_ERROR("Error creating shader program!");
			return;
		}


		// Add all shaders
		vert = addShader(this->ShaderID, vertexSource, GL_VERTEX_SHADER);
		frag = addShader(this->ShaderID, fragmentSource, GL_FRAGMENT_SHADER);
		if (geometrySource != nullptr)  geom = addShader(this->ShaderID, geometrySource, GL_GEOMETRY_SHADER);


		// Link and check error
		glLinkProgram(this->ShaderID);
		checkCompileError(this->ShaderID, NULL, "LINK");

		// Validate and check error
		glValidateProgram(this->ShaderID);
		checkCompileError(this->ShaderID, NULL, "VALIDATE");


		// Shaders have been linked, so set ready for deletion
		glDeleteShader(vert);
		glDeleteShader(frag);
		if (geometrySource != nullptr)
			glDeleteShader(geom);
	}



	GLuint Shader::addShader(GLuint id, const char* shaderCode, GLenum shaderType)
	{
		// Creates an empty shader of type passed
		GLuint theShader = glCreateShader(shaderType);


		// Pass the shadercode into the first element
		const GLchar* theCode[1];
		theCode[0] = shaderCode;

		GLint codeLength[1];
		codeLength[0] = strlen(shaderCode);

		// Set the shader source code
		glShaderSource(theShader, 1, theCode, codeLength);
		glCompileShader(theShader);

		if (!checkCompileError(theShader, shaderType, ""))
			return 0;

		glAttachShader(id, theShader);

		return theShader;
	}


	bool Shader::checkCompileError(GLuint object, GLenum type, std::string programType)
	{
		GLint result = 0;
		GLchar eLog[1024] = { 0 };

		if (type != NULL)
		{
			glGetShaderiv(object, GL_COMPILE_STATUS, &result);
			if (!result)
			{
				glGetShaderInfoLog(object, sizeof(eLog), NULL, eLog);
				VX_CORE_ERROR("Error compiling the {0} shader: {1}", type, eLog);
				return false;
			}
		}
		else
		{
			if (programType == "LINK")
			{
				glGetProgramiv(object, GL_LINK_STATUS, &result);
				if (!result)
				{
					glGetProgramInfoLog(object, sizeof(eLog), NULL, eLog);
					VX_CORE_ERROR("Error linking program: {0}", eLog);
					return false;
				}
			}
			else if (programType == "VALIDATE")
			{
				glGetProgramiv(object, GL_VALIDATE_STATUS, &result);
				if (!result)
				{
					glGetProgramInfoLog(object, sizeof(eLog), NULL, eLog);
					VX_CORE_ERROR("Error validating program: {0}", eLog);
					return false;
				}
			}
		}

		return true;
	}


	/// UTILITY FUNNCTIONS
	// These will Get the uniform location of the name in the shader and assign a value in one method

	void Shader::SetFloat(const char* name, float value, bool useShader)
	{
		if (useShader)
			this->Use();
		glUniform1f(glGetUniformLocation(this->ShaderID, name), value);
	}
	void Shader::SetInteger(const char* name, int value, bool useShader)
	{
		if (useShader)
			this->Use();
		glUniform1i(glGetUniformLocation(this->ShaderID, name), value);
	}
	void Shader::SetVector2f(const char* name, float x, float y, bool useShader)
	{
		if (useShader)
			this->Use();
		glUniform2f(glGetUniformLocation(this->ShaderID, name), x, y);
	}
	void Shader::SetVector2f(const char* name, const glm::vec2& value, bool useShader)
	{
		if (useShader)
			this->Use();
		glUniform2f(glGetUniformLocation(this->ShaderID, name), value.x, value.y);
	}
	void Shader::SetVector3f(const char* name, float x, float y, float z, bool useShader)
	{
		if (useShader)
			this->Use();
		glUniform3f(glGetUniformLocation(this->ShaderID, name), x, y, z);
	}
	void Shader::SetVector3f(const char* name, const glm::vec3& value, bool useShader)
	{
		if (useShader)
			this->Use();
		glUniform3f(glGetUniformLocation(this->ShaderID, name), value.x, value.y, value.z);
	}
	void Shader::SetVector4f(const char* name, float x, float y, float z, float w, bool useShader)
	{
		if (useShader)
			this->Use();
		glUniform4f(glGetUniformLocation(this->ShaderID, name), x, y, z, w);
	}
	void Shader::SetVector4f(const char* name, const glm::vec4& value, bool useShader)
	{
		if (useShader)
			this->Use();
		glUniform4f(glGetUniformLocation(this->ShaderID, name), value.x, value.y, value.z, value.w);
	}
	void Shader::SetMatrix4(const char* name, const glm::mat4& matrix, bool useShader)
	{
		if (useShader)
			this->Use();
		glUniformMatrix4fv(glGetUniformLocation(this->ShaderID, name), 1, false, glm::value_ptr(matrix));
	}
}