#pragma once
#include "Core/Types.h"	

#include <unordered_map>

namespace Vox {

	// Interface for the Component Type
	class IComponentList {
	public:
		IComponentList(TypeID id) { typeID = id; }
		TypeID GetTypeID() { return typeID; }

	private:
		TypeID typeID;
	};

	// Component Type <T> -- holds all the components in a map
	template<typename T>
	class ComponentList : public IComponentList {
	public:
		ComponentList(TypeID id) : IComponentList(id) {};

		void Insert(EntityID entity, T component) {
			entityMap[entity].push_back(component);
		}

		void Remove(EntityID entity, T component) {

			// Loop through and erase what is needed
			int indx = 0;

			for (T comp : entityMap[entity])
			{
				if (comp == component) entityMap[entity].erase(indx);

				indx++;
			}

			VX_CORE_ERROR("Trying To Delete a component that does not exist.");
		}

		// Getting a Component
		T* Get(EntityID entity) {
			// If we do not find the key, return an error, else
			if (entityMap.find(entity) == entityMap.end())
			{
				VX_CORE_ERROR("The component you are looking for does not exist!");
				return nullptr;
			}

			return &entityMap[entity][0];

			

		}


	private:
		std::unordered_map<EntityID, std::vector<T>> entityMap;
	};
}