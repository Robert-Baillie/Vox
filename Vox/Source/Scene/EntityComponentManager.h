#pragma once
#include "ComponentContainer.h"

#include <unordered_map>
#include <set>

namespace Vox {

	class EntityComponentManager
	{
	public:
		static EntityComponentManager* GetManager() { return instance; };

		// Constructor (Initialises)
		EntityComponentManager() { instance = this; };

		// Entity Functions
		const EntityID AddNewEntity();
		void DestroyEntity(const EntityID entity);

		// Component Functions
		template<typename T>
		T& GetComponent(const EntityID entity);

		template<typename T>
		void AddComponent(const EntityID entity, T component);

		template<typename T>
		bool HasComponent(const EntityID entity);

		template<typename T>
		void RemoveComponent(const EntityID entity);

	private:
		// Storage
		int entityCount;
		
		// Comps
		std::set<ComponentTypeID> registeredComponents; // List of used components in scene

		// Entities
		std::unordered_map<EntityID, std::set<IComponentContainer>> entityComponents;


		// Helpers
		template <typename T>
		int getComponentTypeID(T componentType);

		bool componentTypeRegistered(ComponentTypeID componentTypeID);

		template <typename T>
		void registerComponentType(T componentType);

		// Singleton (Again...)
		static EntityComponentManager* instance;
	};


}

