#pragma once
#include "ComponentType.h"

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
		const int AddNewEntity();
		void DestroyEntity(const int entity);

		// Component Functions
		template<typename T>
		T& GetComponent(const int entity);

		template<typename T>
		void AddComponent(const int entity, T component);

		template<typename T>
		bool HasComponent(const int entity);

		template<typename T>
		void RemoveComponent(const int entity);

	private:
		// Storage
		int entityCount;
		
		// Comps
		std::set<IComponentType> registeredComponents; // List of used components in scene

		// Entities
		std::set<int> activeEntities;


		// Helpers
		template <typename T>
		int getComponentTypeID(T componentType);

		// Singleton (Again...)
		static EntityComponentManager* instance;
	};


}

