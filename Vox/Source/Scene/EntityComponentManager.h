#pragma once
#include "pch.h"
#include "Core/TypeMap.h"

namespace Vox {



	class EntityComponentManager
	{
	public:
		static EntityComponentManager* GetManager() { return instance; };

		// Constructor (Initialises)
		EntityComponentManager() {
			instance = this;
		};



		// Entity Functions
		EntityID AddNewEntity()
		{
			// LOGIC FOR MAX ENTITY COUNT
			// TEST

			instance->entityCount++;

			//instance->entityComponents[entityCount] = std::unordered_set<IComponentContainer>();
			return entityCount;
		}



		void DestroyEntity(EntityID entity) {}

		// Component Functions
		template<typename T>
		T& GetComponent(EntityID entity) {
			// Find the component list
			std::shared_ptr<ComponentList<T>> compList = FindComponentList<T>();

			// Return
			return *compList->Get(entity);

		}

		template<typename T>
		void AddComponent( EntityID entity, T component) {
			// Find the component list
			std::shared_ptr<ComponentList<T>> compList = FindComponentList<T>();
			
			// Insert
			compList->Insert(entity, component);

		}

		//template<typename T>
		//bool HasComponent(EntityID entity) {}

		//template<typename T>
		//void RemoveComponent(EntityID entity) {}
#
		

	private:
		// Storage
		int entityCount = 0;
		
		// List of Components
		std::vector<std::shared_ptr<IComponentList>> componentLists;


		TypeMap typeMap;


		// Helper Functions
		template <typename T>
		std::shared_ptr<ComponentList<T>> FindComponentList() {
			// Get the ID
			TypeID id = typeMap.GetTypeID<T>();

			// If the type is already register, then return the list
			for (std::shared_ptr<IComponentList> list : componentLists)
			{
				if (list->GetTypeID() == id)
				{
					// The type is registered - find the corresponding component list
					return std::static_pointer_cast<ComponentList<T>>(list);
				}
			}

			// List does not exist Register
			return RegisterComponentList<T>(id);
		}

		template <typename T>
		std::shared_ptr<ComponentList<T>> RegisterComponentList(TypeID id) {
			// Does not exist - create in component lists
			std::shared_ptr<ComponentList<T>> newCompList = std::make_shared<ComponentList<T>>(id);
			componentLists.push_back(std::dynamic_pointer_cast<IComponentList>(newCompList));
			return newCompList;

		}

		// Singleton (Again...)
		static EntityComponentManager* instance;
	};



	
}

