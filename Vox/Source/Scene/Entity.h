#pragma once
#include "pch.h"



namespace Vox {

	class VOX_API Entity
	{
	public:
		// Constructor - simply assigns an ID in the manager
		Entity() { 
			manager = EntityComponentManager::GetManager();
			ID = manager->AddNewEntity(); 

		};

		// Get ID
		EntityID GetID() const { return ID; };

		void DestroyEntity() { manager->DestroyEntity(ID); };

		/// Component Utility Methods
		template<typename T>
		T& GetComponent() { return manager->GetComponent<T>(ID); };

		template<typename T>
		void AddComponent(T component) { manager->AddComponent<T>(ID, component); };

		template<typename T>
		bool HasComponent() { return manager->GetComponent<T>(ID); };

		template<typename T>
		void RemoveComponent() { manager->GetComponent<T>(ID); };


	private:
		EntityID ID;	//TODO: EntityID - AS A UUID 
		EntityComponentManager* manager = nullptr;

	};

}
