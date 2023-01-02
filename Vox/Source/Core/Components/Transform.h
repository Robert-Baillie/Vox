#pragma once
#include "Component.h"
#include "Rendering/Shader.h"

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace Vox {
	struct VOX_API Transform  : public Component {

		Transform() : Component() {};
		~Transform() {};

		// Properties of Transform
		glm::vec3 Position = glm::vec3(0.0f);
		glm::vec3 Rotation = glm::vec3(0.0f);
		glm::vec3 Scale = glm::vec3(1.0f);

		// Additional Constructors (For potential serialization)
		
	};


	static glm::mat4 GetTransformModel(Transform& transform)
	{
		// prepare the transformations - order is reveresed (matrix multiplacation)
		// we want to rotate around the center, so we will adjust for this
		glm::mat4 model(1.0f);
		model = glm::translate(model, glm::vec3(transform.Position)); // Translate First

		model = glm::translate(model, glm::vec3(0.5f * transform.Scale.x, 0.5f * transform.Scale.y, 0.0f));  // Move origin

		model = glm::rotate(model, glm::radians(transform.Rotation.x), glm::vec3(1.0f, 0.0f, 0.0f)); // then rotate
		model = glm::rotate(model, glm::radians(transform.Rotation.y), glm::vec3(0.0f, 1.0f, 0.0f)); // then rotate
		model = glm::rotate(model, glm::radians(transform.Rotation.z), glm::vec3(0.0f, 0.0f, 1.0f)); // then rotate

		model = glm::translate(model, glm::vec3(-0.5f * transform.Scale.x, -0.5f * transform.Scale.y, -0.0f)); // move origin back

		model = glm::scale(model, glm::vec3(transform.Scale)); // last scale

		return model;
	}
	
}