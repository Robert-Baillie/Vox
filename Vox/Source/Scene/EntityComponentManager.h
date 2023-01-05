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
		EntityID AddNewEntity();
		void DestroyEntity(EntityID entity);

		
		// Component Functions
		template<typename T>
		T* GetComponent(EntityID entity) {
			if (!(std::find(entities.begin(), entities.end(), entity) != entities.end())) return nullptr;


			// Find the component list
			std::shared_ptr<ComponentList<T>> compList = FindComponentList<T>();

			// Return
			return compList->Get(entity);

		}

		template<typename T>
		void AddComponent( EntityID entity, T component) {

			if (!(std::find(entities.begin(), entities.end(), entity) != entities.end())) return;
			// Find the component list
			std::shared_ptr<ComponentList<T>> compList = FindComponentList<T>();
			
			// Insert
			compList->Insert(entity, component);
			// Launch Event
			// Logic for adding already handled, simply send the event
			ComponentAddedEvent event(entity, compList->GetTypeID());
			Vox::Application::GetApplication().SystemEventDispatcher.Dispatch(event);
		}

		template<typename T>
		bool HasComponent(EntityID entity) {

			if (!(std::find(entities.begin(), entities.end(), entity) != entities.end())) return false;


			std::shared_ptr<ComponentList<T>> compList = FindComponentList<T>();

			return compList->Has(entity);
		}

		template<typename T>
		void RemoveComponent(EntityID entity) {

			if (!(std::find(entities.begin(), entities.end(), entity) != entities.end())) return;

			std::shared_ptr<ComponentList<T>> compList = FindComponentList<T>();

			compList->Remove(entity);


			ComponentRemovedEvent event(entity, compList->GetTypeID());
			Vox::Application::GetApplication().SystemEventDispatcher.Dispatch(event);

		}

		template<typename T>
		TypeID GetCompTypeID()
		{
			return instance->typeMap.GetTypeID<T>();
		}



		int GetEntityCount() {return entityCount;}
	private:
		// Storage
		int entityCount = 0;
		
		// List of Components
		std::vector<std::shared_ptr<IComponentList>> componentLists;;
		std::vector<EntityID> entities;

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


		bool EntityExists(EntityID entity);
		

		// Singleton (Again...)
		static EntityComponentManager* instance;


	};



	
}

