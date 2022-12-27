#pragma once
#include "pch.h"
#include "System.h"


#include "Core/Types.h"	

namespace Vox
{
	class TestSystem : public System
	{
	public:
		TestSystem() : System() {
			// Assign the ID straight from ECM - this is always created before systems so okay to call.
			name = "TestSystem";
			typeID = EntityComponentManager::GetManager()->GetCompTypeID<Vox::TestComponent>();
		}

		void Update()  {
			// test function - when this is called, loop through all the entities and simply print the id
			for (auto ent : entities)
			{
				EntityComponentManager::GetManager()->GetComponent<TestComponent>(ent)->Test();
			}
		}
	};
}