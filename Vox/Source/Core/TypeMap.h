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
			if (type_map.count(typeid(T))) return type_map[typeid(T)];

			// Else Register and return
			type_map[typeid(T)] = type_map.size() +1;
			return type_map[typeid(T)];
		}

	private:
		std::unordered_map<std::type_index, TypeID> type_map;

	};


}