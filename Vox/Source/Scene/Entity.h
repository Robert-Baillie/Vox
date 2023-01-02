#pragma once
#include "pch.h"

#include "Core/Components/Transform.h"	

namespace Vox {

	class VOX_API Entity
	{
	public:
		// Constructor - simply assigns an ID in the manager
		Entity() { 
			manager = EntityComponentManager::GetManager();
			ID = manager->AddNewEntity(); 

			// Create a Transform everytime
			
			AddComponent<Transform>(Transform());
		};

		~Entity()
		{
			manager = nullptr;

		}

		void DestroyEntity() { 
			manager->DestroyEntity(ID);
			//VX_CORE_ERROR("DESTROYING ENTITY");
			this->~Entity();
		};

		/// Component Utility Methods
		template<typename T>
		T* GetComponent() {
			if (manager != nullptr) { return manager->GetComponent<T>(ID); }

			VX_CORE_ERROR("This entity is/is being destroyed.");
			return nullptr;
		
		};

		template<typename T>
		void AddComponent(T component) {
			if (manager != nullptr) {
				manager->AddComponent<T>(ID, component);
				return;
			};
			VX_CORE_ERROR("This entity is/is being destroyed.");
		};

			

		template<typename T>
		bool HasComponent() { 
			if (manager != nullptr) { return manager->HasComponent<T>(ID); }
			VX_CORE_ERROR("This entity is/is being destroyed.");
			return false;
		};

		template<typename T>
		void RemoveComponent() {
			if (manager != nullptr) { manager->RemoveComponent<T>(ID); }
			VX_CORE_ERROR("This entity is/is being destroyed.");

		};
		
	


	private:
		EntityID ID = 0;	//TODO: EntityID - AS A UUID 
		EntityComponentManager* manager = nullptr;

		friend class EntityComponentManager;
	};

	


}
