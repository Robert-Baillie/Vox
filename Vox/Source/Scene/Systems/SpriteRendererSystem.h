#pragma once

#include "System.h"

#include "Rendering/Renderer2D.h"

#include "Core/Components/Transform.h"
#include "Core/Components/SpriteRenderer.h"


#include "glm/glm.hpp"
namespace Vox
{
	class SpriteRendererSystem : public System
	{
	public:
		SpriteRendererSystem() : System() {
			// Assign the ID straight from ECM - this is always created before systems so okay to call.
			name = "SpriteRendererSystem";
			typeID = EntityComponentManager::GetManager()->GetCompTypeID<Vox::SpriteRenderer>();
		}
		
		void Render() override  {

			
			// Render the sprite
			for (auto ent : entities)
			{
				// Get The Transform and Set uniform 
				Transform& transform = *EntityComponentManager::GetManager()->GetComponent<Transform>(ent);
				SpriteRenderer& sr = *EntityComponentManager::GetManager()->GetComponent<SpriteRenderer>(ent);

				if (renderer == nullptr) { VX_CORE_ERROR("RENDERER 2D NOT ASSIGNED"); }
			
				renderer->DrawSprite(transform, sr); //  Should be assigned in App initialisation
				
				

			}

		}

	
	};

	

}