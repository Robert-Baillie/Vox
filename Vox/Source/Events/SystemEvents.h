#pragma once
#include "Event.h"

#include "Core/Types.h"

namespace Vox
{

	// Entity Added - pass the ID
	class EntityAddedEvent : public  Event<SystemEvents>
	{
	public:
		// Constructor - assign the keycode and assign the event type constrctor
		EntityAddedEvent(EntityID entity) : Event<SystemEvents>(SystemEvents::OnEntityAdded, "EntityAdded"), ID(entity) {}

		EntityID GetEntityID() { return ID; }

	private:
		EntityID ID;
	};

	// Entity Removed - Pass the id
	class EntityRemovedEvent : public  Event<SystemEvents>
	{
	public:
		// Constructor - assign the keycode and assign the event type constrctor
		EntityRemovedEvent(EntityID entity) : Event<SystemEvents>(SystemEvents::OnEntityDestroyed, "EntityRemoved"), ID(entity) {}

		EntityID GetEntityID() { return ID; }

	private:
		EntityID ID;
	};


	// Comp added - pass the entity and type
	class ComponentAddedEvent : public  Event<SystemEvents>
	{
	public:
		// Constructor - assign the keycode and assign the event type constrctor
		ComponentAddedEvent(EntityID entity, TypeID typeID) : Event<SystemEvents>(SystemEvents::OnComponentAdded, "ComponentAdded"), entityID(entity), componentTypeID(typeID) {}

		EntityID GetEntityID() { return entityID; }
		TypeID GetComponentTypeID() { return componentTypeID; }

	private:
		EntityID entityID;
		TypeID componentTypeID;
	};

	// Comp removed - pass the entity and type
	class ComponentRemovedEvent : public  Event<SystemEvents>
	{
	public:
		// Constructor - assign the keycode and assign the event type constrctor
		ComponentRemovedEvent(EntityID entity, TypeID typeID) : Event<SystemEvents>(SystemEvents::OnComponentRemoved, "ComponentRemoved"), entityID(entity), componentTypeID(typeID) {}

		EntityID GetEntityID() { return entityID; }
		TypeID GetComponentTypeID() { return componentTypeID; }

	private:
		EntityID entityID;
		TypeID componentTypeID;
	};

}
