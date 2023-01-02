#pragma once
#include "Core/Types.h"
#include "Scene/EntityComponentManager.h"


namespace Vox {

	// Base Class For All Components
	struct Component {
	public:
		Component() = default;
		~Component() = default;

		bool IsEnabled = true;


	};
}