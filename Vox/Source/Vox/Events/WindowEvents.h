#pragma once

#include "Event.h"

namespace Vox
{
	enum class WindowEvents
	{
		WindowResize,
		WindowClosed
	};


	/// WINDOW RESIZE EVENT- Holds utility function for resive
	class WindowResizeEvent : public Event<WindowEvents>
	{
	public:
		// Constructor - assign the new height and construct event
		WindowResizeEvent(unsigned int x, unsigned int y) : Event<WindowEvents>(WindowEvents::WindowResize, "WindowResize"), width(x), height(y) {}


		// Get the Height and Width
		unsigned int GetWidth() { return width; };
		unsigned int GetHeight() { return height; };
	private:
		unsigned int width;
		unsigned int height;
	};


	/// WINDOW CLOSE EVENT- 
	class WindowResizeEvent : public Event<WindowEvents>
	{
	public:
		// Constructor - construct event
		WindowResizeEvent() : Event<WindowEvents>(WindowEvents::WindowClosed, "WindowClosed"){}
			
	};
}
