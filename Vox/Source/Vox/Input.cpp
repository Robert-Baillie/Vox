#include "Input.h"

#include "Application.h"

namespace Vox {


	void Input::Initialise()
	{
		// Assign the bool keycode
		for (size_t i = 0; i < 1024; i++)
		{
			keys[i] = 0;
		}

		// Subscribe to necessary events
		// Key Events
		Application::GetApplication().VoxEventDispatcher.Subscribe(VoxEvents::KeyPressed, std::bind(&Input::OnKeyPressed, this, std::placeholders::_1));
	}










	/// Callback Events
	bool Input::OnKeyPressed(const KeyPressedEvent& event) {
		// Check event type for security and Assign the bool value
		keys[event.GetKeyCode()] = true;



		return true;
	}

}