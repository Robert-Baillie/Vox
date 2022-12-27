#include "SystemManager.h"

#include "Core/Application.h"

namespace Vox {
	SystemManager* SystemManager::instance = nullptr;

	SystemManager::SystemManager() {

		instance = this;

		// Subscribe to events called by ECM
		Application::GetApplication().SystemEventDispatcher.Subscribe(SystemEvents::OnEntityAdded, std::bind(&SystemManager::OnEntityAdded, instance, std::placeholders::_1));
		Application::GetApplication().SystemEventDispatcher.Subscribe(SystemEvents::OnEntityDestroyed, std::bind(&SystemManager::OnEntityDestroyed, instance, std::placeholders::_1));
		Application::GetApplication().SystemEventDispatcher.Subscribe(SystemEvents::OnComponentAdded, std::bind(&SystemManager::OnComponentAdded, instance, std::placeholders::_1));
		Application::GetApplication().SystemEventDispatcher.Subscribe(SystemEvents::OnComponentRemoved, std::bind(&SystemManager::OnComponentRemoved, instance, std::placeholders::_1));

	};



	/// Callback Events
	bool SystemManager::OnEntityAdded(Event<SystemEvents>& event) {
		EntityAddedEvent* entityEvent = static_cast<EntityAddedEvent*>(&event);

		// Add to the Transform system - all Entities will exist at a set of coordinates
		/*for (std::shared_ptr<System> sys : systemList)
		{
			sys->AddEntity(entityEvent->GetEntityID());
			VX_TRACE("Entity {0} Added to system list: {1} which has type id: {2}", entityEvent->GetEntityID(), sys->GetName(), sys->GetTypeID());
		}*/

		return true;
	}

	bool SystemManager::OnEntityDestroyed(Event<SystemEvents>& event) {
		EntityRemovedEvent* entityEvent = static_cast<EntityRemovedEvent*>(&event);

		for (std::shared_ptr<System> sys : systemList)
		{
			sys->RemoveEntity(entityEvent->GetEntityID());
		}

		

		return true;
	}

	bool SystemManager::OnComponentAdded(Event<SystemEvents>& event) {
		ComponentAddedEvent* entityEvent = static_cast<ComponentAddedEvent*>(&event);

		VX_CORE_INFO("Searching for component id system: {0}", entityEvent->GetComponentTypeID());

		for (std::shared_ptr<System> sys : systemList)
		{
			if (sys->GetTypeID() == entityEvent->GetComponentTypeID())
			{
				VX_CORE_INFO("Found ID!");
				sys->AddEntity(entityEvent->GetEntityID());
				return true;
			}
		}
		
		return true;
	}

	bool SystemManager::OnComponentRemoved(Event<SystemEvents>& event) {
		// Upcast the event - is this slow (static cast at runtime) or is this done by the compiler
		ComponentRemovedEvent* entityEvent = static_cast<ComponentRemovedEvent*>(&event);


		VX_CORE_INFO("Searching for component id system: {0}", entityEvent->GetComponentTypeID());

		for (std::shared_ptr<System> sys : systemList)
		{
			if (sys->GetTypeID() == entityEvent->GetComponentTypeID())
			{
				VX_CORE_INFO("Found ID!");
				sys->RemoveEntity(entityEvent->GetEntityID());
				return true;
			}
		}
		return true;
	}

}
