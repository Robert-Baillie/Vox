#pragma once
#include "Core/Types.h"	
#include "Core/TypeMap.h"

namespace Vox {

	// Interface for the Component Type
	class IComponentType {
	public:
		IComponentType(TypeID id) { typeID = id; }
		virtual TypeID GetTypeID() { return typeID;  }

	private:
		TypeID typeID;
	};

	// Component Type <T> -- holds the ID of component
	template<typename T>
	class ComponentType : IComponentType {

	};
}