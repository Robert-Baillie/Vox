#include "EntityComponentManager.h"

#include "Core/Application.h"

namespace Vox {


	EntityComponentManager* EntityComponentManager::instance = nullptr;

	EntityID EntityComponentManager::AddNewEntity()
	{
		// LOGIC FOR MAX ENTITY COUNT
		// TEST

		instance->entityCount++;

		instance->entities.push_back(entityCount);

		EntityAddedEvent event(entityCount);
		Vox::Application::GetApplication().SystemEventDispatcher.Dispatch(event);

		return entityCount;
	}


	void EntityComponentManager::DestroyEntity(EntityID entity)
	{
		// Removal Logic

		for (std::shared_ptr<IComponentList> compList : componentLists)
		{
			compList->Remove(entity);
		}


		// Send out Event
		EntityRemovedEvent event(entityCount);
		Vox::Application::GetApplication().SystemEventDispatcher.Dispatch(event);

		// Erase 
		std::vector<int>::iterator position = std::find(entities.begin(), entities.end(), entity);
		if (position != entities.end())  entities.erase(position); // == myVector.end() means the element was not found
		
	}

	

}
