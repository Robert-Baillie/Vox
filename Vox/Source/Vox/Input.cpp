#include "Input.h"

#include "Application.h"

namespace Vox {
	Input* Input::instance = nullptr;

	bool Input::IsKeyPressed(const int key)
	{
		return instance->keys[key];
	}

	void Input::Initialise()
	{
		// Check instance for singleton
		if (instance) VX_CORE_ERROR("INSTANCE INSTANCE ALREADY EXISTS.");
		instance = this;

		// Assign the bool keycode
		for (size_t i = 0; i < 1024; i++)
		{
			instance->keys[i] = false;
		}

		// Subscribe to necessary events
		// Key Events
		Application::GetApplication().VoxEventDispatcher.Subscribe(VoxEvents::KeyPressed, std::bind(&Input::OnKeyPressed, instance, std::placeholders::_1));
		Application::GetApplication().VoxEventDispatcher.Subscribe(VoxEvents::KeyReleased, std::bind(&Input::OnKeyReleased , instance, std::placeholders::_1));
	}


	




	/// Callback Events
	bool Input::OnKeyPressed(Event<VoxEvents>& event) {
		// Upcast the event
		KeyPressedEvent* keyEvent = dynamic_cast<KeyPressedEvent*>(&event);

		// No need to check for repeats
		if (keyEvent->IsRepeat()) return true; 
		instance->keys[keyEvent->GetKeyCode()] = true;
		return true;
	}

	bool Input::OnKeyReleased(Event<VoxEvents>& event) {
		// Upcast the event and assign the key
		KeyReleasedEvent* keyEvent = dynamic_cast<KeyReleasedEvent*>(&event);
		instance->keys[keyEvent->GetKeyCode()] = false;
		return true;
	}

}