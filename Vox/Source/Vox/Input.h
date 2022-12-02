#pragma once

#include "pch.h"


namespace Vox { 

	// Like Window - this should be virtualised and made platform specific.
	// SUBSCRIBE TO CALLBACK EVENTS AND ASSIGN TO AN ARRAY
	class VOX_API Input
	{
	public:
		// API Functions
		static bool IsKeyPressed(const int key);

	private:
		// Initialise - assign the keys bools and subscribe to events;
		void Initialise();


		// Array to store the Keys - CREATE OWN KEYCODE CLASS
		bool keys[1024];


		// Callback functions to handle key assignment
		bool OnKeyPressed(Event<VoxEvents>& event);
		bool OnKeyReleased(Event<VoxEvents>& event);

		// Friend class - let app access these private functions
		friend class Application;

		// Singleton
		static Input* instance;

	};


}