#pragma once

#include "Event.h"

namespace Vox
{
	enum class MouseEvents
	{
		MouseMoved,
		MouseScrolled,
		MouseButtonPressed,
		MouseButtonReleased
	};


	/// MOUSE MOVED EVENT - Holds utility and the amount the mouse moves
	class MouseMovedEvent : public Event<MouseEvents>
	{
	public:
		// Constructor - assign the mouse and assign the event type constrctor
		MouseMovedEvent(float x, float y) : Event<MouseEvents>(MouseEvents::MouseMoved, "MouseMoved"), mouseX(x), mouseY(y) {}


		// Get Mouse Positions
		float GetMouseX() const { return mouseX; }
		float GetMouseY() const { return mouseY;  }



	private:
		float mouseX;
		float mouseY;
	};

	/// MOUSE SCROLLED EVENT - Holds utility and the amount the mouse scrols
	class MouseScrolledEvent : public Event<MouseEvents>
	{
	public:
		// Constructor - assign the mouse and assign the event type constrctor
		MouseScrolledEvent(float x, float y) : Event<MouseEvents>(MouseEvents::MouseScrolled, "MouseScrolled"), xChange(x), yChange(y) {}


		// Get Mouse Changes
		float GetXChange() const { return xChange; }
		float GetYChange() const { return yChange; }



	private:
		float xChange;
		float yChange;
	};

	/// MOUSE BUTTON PRESSED EVENT - Holds the mouse button pressed
	class MouseButtonPressedEvent : public Event<MouseEvents>
	{
	public:
		// Constructor - assign the mouse code and construct event
		MouseButtonPressedEvent(int but) : Event<MouseEvents>(MouseEvents::MouseButtonPressed, "MouseButtonPressed"), buttonPressed(but) {}


		// Get Mouse Button Pressed - CHANGE FROM INT TO MOUSE CLASS
		float GetMousePressed() const { return buttonPressed; }


	private:
		int buttonPressed;
	};

	/// MOUSE BUTTON RELESED EVENT - Holds the mouse button released
	class MouseButtonReleasedEvent : public Event<MouseEvents>
	{
	public:
		// Constructor - assign the mouse code and construct event
		MouseButtonReleasedEvent(int but) : Event<MouseEvents>(MouseEvents::MouseButtonReleased, "MouseButtonReleased"), buttonReleased(but) {}


		// Get Mouse Button Released - CHANGE FROM INT TO MOUSE CLASS
		float GetMouseReleased() const { return buttonReleased; }


	private:
		int buttonReleased;
	};


}
