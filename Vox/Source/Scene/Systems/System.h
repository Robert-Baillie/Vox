#pragma once
#include <vector>
#include <algorithm>

#include "Core/Types.h"

// To be inherited by other systems i.e ScriptSystem : System
namespace Vox
{

	class System {
	public:
		System(){};
		virtual ~System() = default;

		TypeID GetTypeID() { return typeID; }
		std::string GetName() { return name; }


		void AddEntity(EntityID entity) { entities.push_back(entity); }

		void RemoveEntity(EntityID entity) { 

			// If the Entity Exists, Remove It
			std::vector<int>::iterator position = std::find(entities.begin(), entities.end(), entity);
			if (position != entities.end())  entities.erase(position); // == myVector.end() means the element was not found
				
		}

		virtual void Stop() {};
		virtual void Start() {};
		virtual void Awake() {};
		virtual void Update() {};
		virtual void Render() {};
	protected:
		std::string name;
		TypeID typeID;
		std::vector<EntityID> entities;
	};
}