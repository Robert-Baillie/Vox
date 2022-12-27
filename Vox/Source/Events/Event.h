#pragma once

namespace Vox
{
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


	enum class SystemEvents
	{
		None,

		// Entity
		OnEntityAdded,
		OnEntityDestroyed,

		// Components
		OnComponentAdded,
		OnComponentRemoved
	};

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
		inline const T getType() const { return type; };
		inline const std::string getName() const { return name; };


	protected:
		T type;
		std::string name;
	};

	



}
