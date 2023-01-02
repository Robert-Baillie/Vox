#pragma once
#include "pch.h"
#include <glm/gtc/type_ptr.hpp>	


namespace Vox {

	/// <summary>
	/// All Purpose Shader class. Handles compilation from code with error checking
	/// Only holds the ID linked to GL.
	/// Hosts utility functions for setting all data types for openGL uniforms
	/// </summary>
	class Shader
	{
	public:
		// Constructor - simply assign starting id to 0
		Shader() { ShaderID = 0; }

		GLuint ShaderID;

		// Set the current shader as active
		// Returns this as a reference so we can call straight from Use()  i.e: GetShader("sprite").Use().SetInteger("image", 0)
		Shader& Use();

		// Compilation with a given source code - geometry is optional
		void Compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource = nullptr);

		// Utility Function
		void    SetFloat(const char* name, float value, bool useShader = false);
		void    SetInteger(const char* name, int value, bool useShader = false);
		void    SetVector2f(const char* name, float x, float y, bool useShader = false);
		void    SetVector2f(const char* name, const glm::vec2& value, bool useShader = false);
		void    SetVector3f(const char* name, float x, float y, float z, bool useShader = false);
		void    SetVector3f(const char* name, const glm::vec3& value, bool useShader = false);
		void    SetVector4f(const char* name, float x, float y, float z, float w, bool useShader = false);
		void    SetVector4f(const char* name, const glm::vec4& value, bool useShader = false);
		void    SetMatrix4(const char* name, const glm::mat4& matrix, bool useShader = false);

	private:
		// Add Shader
		GLuint addShader(GLuint id, const char* shaderCode, GLenum shaderType); // id is also referred to as a "program"

		// Error Checking
		bool checkCompileError(GLuint id, GLenum type, std::string programType = NULL);

	};


}
