#include "EntityComponentManager.h"

namespace Vox {
	EntityComponentManager* EntityComponentManager::instance = nullptr;

	const EntityID EntityComponentManager::AddNewEntity()
	{
		// LOGIC FOR MAX ENTITY COUNT

		// Create an ID - for now this is size, replace with UUID logic
		

		// Fire off event to the system manager

	}

	void EntityComponentManager::DestroyEntity(const EntityID entity)
	{
		// LOGIC FOR CHEECKING ENTITY EXISTS

		// Delete from entity comp

		// Delete all components

		// Delete from entity list


		// Fire off event to the system manager
	}

	template<typename T> 
	inline T& EntityComponentManager::GetComponent(const EntityID entity)
	{
		// Check if the type has even been registered
		if(!componentTypeRegistered<T>())
		{
			VX_CORE_ERROR("The component you are searching for does not exist.");
			return nullptr;
		}

		// Get Type ID
		ComponentTypeID compID = getComponentTypeID<T>();
		
		// Find the entity in the entity components list - if found then get the container
		std::set<IComponentContainer> containers = entityComponents.find(entity)->second;
		
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
	void EntityComponentManager::AddComponent(const EntityID entity, T component)
	{
		// Blah blah blah
	}

	template<typename T>
	bool EntityComponentManager::HasComponent(const EntityID entity)
	{
		// Check if the type has even been registered
		if(!componentTypeRegistered<T>())
		{
			VX_CORE_ERROR("The component you are searching for does not exist.");
			return false;
		}

		// Get Type ID
		ComponentTypeID compID = getComponentTypeID<T>();
		
		// Find the entity in the entity components list - if found then get the container
		std::set<IComponentContainer> containers = entityComponents.find(entity)->second;
		
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
	void EntityComponentManager::RemoveComponent(const EntityID entity)
	{
		// Blah blah blah

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
		for(auto id : registeredComponents) {
  			if (id == componentTypeID) return true;
		} 

        return false;
    }

	template<typename T>
	void EntityComponentManager::registerComponentType(T componentType)
	{
		// Grab the ID and insert into the set
		ComponentTypeID id = getComponentTypeID<T>();
		registeredComponents.insert(id);
	}


}