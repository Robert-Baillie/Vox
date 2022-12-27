#pragma once
#include <typeindex>
#include <unordered_map>

#include "Types.h"

namespace Vox {
	

	class TypeMap {
	public:
		TypeMap() = default;

		template<typename T>
		TypeID GetTypeID() {
			// Return int if already exists
			std::string typeName = typeid(T).name();


			if (type_map.find(typeName) != type_map.end()) return type_map[typeName];

			// Else Register and return
			type_map[typeName] = type_map.size() +1;
			return type_map[typeName];
		}

	private:
		std::unordered_map<std::string, TypeID> type_map;

	};


}