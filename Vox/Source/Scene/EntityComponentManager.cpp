#include "EntityComponentManager.h"

namespace Vox {
	EntityComponentManager* EntityComponentManager::instance = nullptr;

	EntityID EntityComponentManager::AddNewEntity()
	{
		// LOGIC FOR MAX ENTITY COUNT
		// TEST

		instance->entityCount++;

		instance->entityComponents[entityCount] = std::set<IComponentContainer>();
		return entityCount;
	}

	void EntityComponentManager::DestroyEntity( EntityID entity)
	{
		// LOGIC FOR CHEECKING ENTITY EXISTS

		// Delete from entity comp

		// Delete all components

		// Delete from entity list


		// Fire off event to the system manager
	}

	template<typename T> 
	T& EntityComponentManager::GetComponent( EntityID entity)
	{
		// Check if the type has even been registered
		if(componentTypeRegistered<T>(T) == false)
		{
			VX_CORE_ERROR("The component you are searching for does not exist.");
			return nullptr;
		}

		// Get Type ID
		ComponentTypeID compID = getComponentTypeID<T>();
		
		// Find the entity in the entity components list - if found then get the container
		std::set<IComponentContainer> containers = instance->entityComponents.find(entity)->second;
		
		// Loop through the containers - if you find the type id then return the component (unfortunately have to static cast again)
		for(IComponentContainer container : containers)
		{
			if(container.GetComponentTypeID() == compID){
				return static_cast<ComponentContainer>(container).GetComponent();
			}

		}


		// Doesn't exist - return an error.
		VX_CORE_ERROR("The component you are searching for does not exist.");
		return nullptr;

	}

	template<typename T>
	void EntityComponentManager::AddComponent( EntityID entity, T component)
	{
		// Register Component if not already
		if (componentTypeRegistered<T>(T) == false) { registerComponentType<T>(T); }

		//  Create a ComponentContainer
		IComponentContainer component = static_cast<IComponentContainer>(component);
		instance->entityComponents[entity].insert(component);

		
	}

	template<typename T>
	bool EntityComponentManager::HasComponent( EntityID entity)
	{
		// Check if the type has even been registered
		if(componentTypeRegistered<T>(T) == false)
		{
			VX_CORE_ERROR("The component you are searching for does not exist.");
			return false;
		}

		// Get Type ID
		ComponentTypeID compID = getComponentTypeID<T>();
		
		// Find the entity in the entity components list - if found then get the container
		std::set<IComponentContainer> containers = instance->entityComponents.find(entity)->second;
		
		// Loop through the containers - if you find the type id then return true
		for(IComponentContainer container : containers)
		{
			if(container.GetComponentTypeID() == compID) return true;
		}


		// Doesn't exist - return an error.
		VX_CORE_ERROR("The component you are searching for does not exist.");
		return false;
	}

	template<typename T>
	void EntityComponentManager::RemoveComponent( EntityID entity)
	{
		// Check if the type has even been registered
		if (componentTypeRegistered<T>(T) == false && HasComponent<T>(entity) == false)
		{
			VX_CORE_ERROR("The component you are searching for does not exist.");
			return nullptr;
		}

		//  Get the container and delete
		IComponentContainer component = static_cast<IComponentContainer>(component);
		instance->entityComponents[entity].erase(component);

	}

	template<typename T>
	int EntityComponentManager::getComponentTypeID(T componentType)
	{
		// Is this a design issue - a lot of staatic casting...
		IComponentContainer component = static_cast<IComponentContainer>(componentType);
		return component.GetComponentTypeID();
	}

    bool EntityComponentManager::componentTypeRegistered(ComponentTypeID componentTypeID)
    {
		// Loop over registered componenets, return if found
		for(auto id : instance->registeredComponents) {
  			if (id == componentTypeID) return true;
		} 

        return false;
    }

	template<typename T>
	void EntityComponentManager::registerComponentType(T componentType)
	{
		// Grab the ID and insert into the set
		ComponentTypeID id = getComponentTypeID<T>();
		instance->registeredComponents.insert(id);
	}


}