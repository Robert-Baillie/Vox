#pragma once

#include "pch.h"


namespace Vox { 

	// Like Window - this should be virtualised and made platform specific.
	// SUBSCRIBE TO CALLBACK EVENTS AND ASSIGN TO AN ARRAY
	class VOX_API Input
	{
	public:
		// API Functions
		static bool IsKeyPressed(const KeyCode key);
		static bool IsMouseButtonPressed(const MouseCode button);

		static glm::vec2 GetMousePos();
		static float GetMouseX();
		static float GetMouseY();

	private:
		// Initialise - assign the keys bools and subscribe to events;
		void Initialise();


		// Array to store the Keys - CREATE OWN KEYCODE CLASS
		bool keys[350];
		bool mouse[8];
		int t = 0;

		// mouse
		float mousePosX, mousePosY;
		float scrollXChange, scrollYChange;

		// Callback functions to handle key assignment
		bool OnKeyPressed(Event<VoxEvents>& event);
		bool OnKeyReleased(Event<VoxEvents>& event);

		bool OnMouseButtonPressed(Event<VoxEvents>& event);
		bool OnMouseButtonReleased(Event<VoxEvents>& event);

		bool OnMouseMoved(Event<VoxEvents>& event);
		bool OnMouseScrolled(Event<VoxEvents>& event);


		// Friend class - let app access these private functions
		friend class Application;

		// Singleton
		static Input* instance;

	};


}