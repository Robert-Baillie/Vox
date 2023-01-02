#pragma once
#include "pch.h"
#include "System.h"

#include "Core/Types.h"	

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

		void Render()  {
			// Render the sprite
			for (auto ent : entities)
			{
				// Get The Transform and Set uniform 
				EntityComponentManager::GetManager()->GetComponent<Transform>(ent);
				EntityComponentManager::GetManager()->GetComponent<SpriteRenderer>(ent);
			}
		}
	};
}