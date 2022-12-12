#pragma once

#include "Core/Types.h"

namespace Vox {

	/// Interface for Component Type
	class IComponentContainer 
	{
	public:
		virtual ComponentTypeID GetComponentTypeID() { return typeID; };
		virtual ComponentID GetComponentID() { return compID; };

	private:
		ComponentTypeID typeID;
		ComponentID compID;
	};


	/// ComponentType<T> - holds the type of a component so that the ID for type can be called back
	template <typename T>
	class ComponentContainer : IComponentContainer
	{
	public:
		ComponentContainer<T>() { component = T; }
	  	T& GetComponent() { return *component; }

	private:
		T component;
	};
}