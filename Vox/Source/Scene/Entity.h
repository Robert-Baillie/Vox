#pragma once

#include "EntityComponentManager.h"


namespace Vox {

	class Entity
	{
	public:
		// Constructor - simply assigns an ID in the manager
		Entity() { 
			manager = EntityComponentManager::GetManager();
			ID = manager->AddNewEntity(); 
		};

		// Get ID
		const int GetID() const { return ID; };

		void DestroyEntity() { manager->DestroyEntity(ID); };

		/// Component Utility Methods
		template<typename T>
		T& GetComponent() { return manager->GetComponent<T>(ID); };

		template<typename T>
		void AddComponent(T component) { manager->AddComponent<T>(ID, T); };

		template<typename T>
		bool HasComponent() { return manager->GetComponent<T>(ID); };

		template<typename T>
		void RemoveComponent() { manager->GetComponent<T>(ID); };


	private:
		int ID;	//TODO: EntityID - AS A UUID - CREATE TYPE CLASS --- -ID List (wrapper for a set)
		EntityComponentManager* manager = nullptr;

	};

}
