#pragma once

#include "Event.h"

namespace Vox
{

	/// WINDOW RESIZE EVENT- Holds utility function for resive
	class WindowResizeEvent : public Event<VoxEvents>
	{
	public:
		// Constructor - assign the new height and construct event
		WindowResizeEvent(unsigned int x, unsigned int y) : Event<VoxEvents>(VoxEvents::WindowResize, "WindowResize"), width(x), height(y) {}


		// Get the Height and Width
		unsigned int GetWidth() { return width; };
		unsigned int GetHeight() { return height; };
	private:
		unsigned int width;
		unsigned int height;
	};


	/// WINDOW CLOSE EVENT- 
	class WindowClosedEvent : public Event<VoxEvents>
	{
	public:
		// Constructor - construct event
		WindowClosedEvent() : Event<VoxEvents>(VoxEvents::WindowClosed, "WindowClosed"){}
			
	};
}
