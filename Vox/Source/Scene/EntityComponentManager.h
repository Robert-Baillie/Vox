#pragma once
#include "pch.h"

namespace Vox {

		class VOX_API TestComponent {
		public:
			TestComponent() = default;
			void Test() { VX_TRACE("Test Works"); }
		};
	

	class EntityComponentManager
	{
	public:
		static EntityComponentManager* GetManager() { return instance; };

		// Constructor (Initialises)
		EntityComponentManager()  { 
			instance = this; 
		};

		// Entity Functions
		EntityID AddNewEntity();
		void DestroyEntity( EntityID entity);

		// Component Functions
		template<typename T>
		T& GetComponent( EntityID entity);

		template<typename T>
		void AddComponent( EntityID entity, T component);

		template<typename T>
		bool HasComponent( EntityID entity);

		template<typename T>
		void RemoveComponent( EntityID entity);

	private:
		// Storage
		int entityCount = 0;
		
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

