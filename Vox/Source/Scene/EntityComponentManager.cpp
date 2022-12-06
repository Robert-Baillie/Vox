#include "EntityComponentManager.h"

namespace Vox {
	EntityComponentManager* EntityComponentManager::instance = nullptr;

	const int EntityComponentManager::AddNewEntity()
	{
		// LOGIC FOR MAX ENTITY COUNT

		// Create an ID - for now this is size, replace with UUID logic
		int entity = activeEntities.size();
		activeEntities.insert(entity);

		entityCount++;

		// Fire off event to the system manager
		return entity;

	}

	void EntityComponentManager::DestroyEntity(const int entity)
	{
		// LOGIC FOR CHEECKING ENTITY EXISTS

		// Delete from entity comp

		// Delete all components

		// Delete from entity list

		entityCount--;

		// Fire off event to the system manager
	}

	template<typename T> 
	inline T& EntityComponentManager::GetComponent(const int entity)
	{
		// Get the Component Type ID
		int id = getComponentTypeID<T>();


		// TODO: insert return statement here
	}

	template<typename T>
	void EntityComponentManager::AddComponent(const int entity, T component)
	{
		// Blah blah blah
	}

	template<typename T>
	bool EntityComponentManager::HasComponent(const int entity)
	{
		// Blah blah blah
		
		return false;
	}

	template<typename T>
	void EntityComponentManager::RemoveComponent(const int entity)
	{
		// Blah blah blah

	}

	template<typename T>
	int EntityComponentManager::getComponentTypeID(T componentType)
	{
		// Is this a design issue - a lot of staatic casting...
		IComponentType component = static_cast<IComponentType>(componentType);
		return component.GetComponentTypeID();
	}


}