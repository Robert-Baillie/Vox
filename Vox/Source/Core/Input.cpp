#include "Input.h"

#include "Application.h"

namespace Vox {
	Input* Input::instance = nullptr;

	bool Input::IsKeyPressed(const KeyCode key)
	{
		return instance->keys[key];
	}

	bool Input::IsMouseButtonPressed(const MouseCode button)
	{
		return instance->mouse[button];
	}

	glm::vec2 Vox::Input::GetMousePos()
	{
		return glm::vec2(instance->mousePosX, instance->mousePosY);
	}

	float Vox::Input::GetMouseX()
	{
		return instance->mousePosX;
	}

	float Vox::Input::GetMouseY()
	{
		return instance->mousePosY;
	}


	void Input::Initialise()
	{
		// Check instance for singleton
		if (instance) VX_CORE_ERROR("INSTANCE INSTANCE ALREADY EXISTS.");
		instance = this;

		// Assign the key and mouse bools
		for (size_t i = 0; i < 350; i++)
		{
			instance->keys[i] = false;
		}

		for (size_t i = 0; i < 8; i++)
		{
			instance->mouse[i] = false;
		}

		// Subscribe to necessary events
		// Key Events
		Application::GetApplication().VoxEventDispatcher.Subscribe(VoxEvents::KeyPressed, std::bind(&Input::OnKeyPressed, instance, std::placeholders::_1));
		Application::GetApplication().VoxEventDispatcher.Subscribe(VoxEvents::KeyReleased, std::bind(&Input::OnKeyReleased , instance, std::placeholders::_1));

		// Mouse Events
		// Buttons
		Application::GetApplication().VoxEventDispatcher.Subscribe(VoxEvents::MouseButtonPressed, std::bind(&Input::OnMouseButtonPressed, instance, std::placeholders::_1));
		Application::GetApplication().VoxEventDispatcher.Subscribe(VoxEvents::MouseButtonReleased, std::bind(&Input::OnMouseButtonReleased, instance, std::placeholders::_1));

		// Moving
		Application::GetApplication().VoxEventDispatcher.Subscribe(VoxEvents::MouseMoved, std::bind(&Input::OnMouseMoved, instance, std::placeholders::_1));

		// Scrolling
		Application::GetApplication().VoxEventDispatcher.Subscribe(VoxEvents::MouseScrolled, std::bind(&Input::OnMouseScrolled, instance, std::placeholders::_1));

	}


	




	/// Callback Events
	bool Input::OnKeyPressed(Event<VoxEvents>& event) {
		// Upcast the event - is this slow (static cast at runtime) or is this done by the compiler
		KeyPressedEvent* keyEvent = static_cast<KeyPressedEvent*>(&event);

		// No need to check for repeats
		if (keyEvent->IsRepeat()) return true; 
		instance->keys[keyEvent->GetKeyCode()] = true;
		return true;
	}

	bool Input::OnKeyReleased(Event<VoxEvents>& event) {
		// Upcast the event and assign the key
		KeyReleasedEvent* keyEvent = static_cast<KeyReleasedEvent*>(&event);
		instance->keys[keyEvent->GetKeyCode()] = false;
		return true;
	}

	bool Input::OnMouseButtonPressed(Event<VoxEvents>& event) {
		// Upcast the event
		MouseButtonPressedEvent* mouseEvent = static_cast<MouseButtonPressedEvent*>(&event);

		instance->mouse[mouseEvent->GetMousePressed()] = true;
		return true;
	}

	bool Input::OnMouseButtonReleased(Event<VoxEvents>& event) {
		// Upcast the event
		MouseButtonReleasedEvent* mouseEvent = static_cast<MouseButtonReleasedEvent*>(&event);
		instance->mouse[mouseEvent->GetMouseReleased()] = false;
		return true;
	}

	bool Input::OnMouseMoved(Event<VoxEvents>& event)
	{
		MouseMovedEvent* mouseEvent = static_cast<MouseMovedEvent*>(&event);

		instance->mousePosX = mouseEvent->GetMouseX();
		instance->mousePosY = mouseEvent->GetMouseY();
		return true;
	}

	bool Input::OnMouseScrolled(Event<VoxEvents>& event)
	{
		MouseScrolledEvent* mouseEvent = static_cast<MouseScrolledEvent*>(&event);

		instance->scrollXChange = mouseEvent->GetXChange();
		instance->scrollYChange = mouseEvent->GetYChange();
		return true;
	}

}