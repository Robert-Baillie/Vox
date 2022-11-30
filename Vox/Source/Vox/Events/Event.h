#pragma once

namespace Vox
{

	// Class that holds the bease construction for an event
	// Events must inherit from this class
	// Events must hold a type T to identify the event.

	template <typename T>
	class Event {
	public:
		// Constructor
		Event(T type, std::string name = "") : type(type), name(name) {};
		Event() = default;
		virtual ~Event() = default;


		bool IsHandled = false;

		// Utility functions to get name, type 
		inline const T getType() { return type; };
		inline const std::string getName() { return name; };


	private:
		T type;
		std::string name;
	};

	enum class VoxEvents
	{
		None,

		// Key
		KeyPressed,
		KeyReleased,
		KeyRepeat,

		// Mouse
		MouseMoved,
		MouseScrolled,
		MouseButtonPressed,
		MouseButtonReleased,

		// Windows
		WindowResize,
		WindowClosed
	};



}
