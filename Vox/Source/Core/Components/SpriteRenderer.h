#pragma once
#include "Component.h"
#include "Rendering/Texture.h"
#include "Core/Resource/ResourceManager.h"

#include "glm/glm.hpp"

namespace Vox {
	struct VOX_API SpriteRenderer : public Component {

		SpriteRenderer(std::string name) : Component() {
			TextureName = name;
		};
		~SpriteRenderer() {};

		glm::vec3 Colour{ 1.0f, 1.0f, 1.0f };
		std::string TextureName = "";
		

	};

}
