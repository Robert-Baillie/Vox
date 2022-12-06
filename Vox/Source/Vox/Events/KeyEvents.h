#pragma once

#include "Event.h"

#include "Vox/Core/KeyCodes.h"

namespace Vox
{
	

	/// KEY PRESSED EVENT - Holds utility function for repeat and the code that is being used 
	class KeyPressedEvent : public  Event<VoxEvents>
	{
		public:
			// Constructor - assign the keycode and assign the event type constrctor
			KeyPressedEvent(const KeyCode keyCode, bool isRepeat = false) : Event<VoxEvents>(VoxEvents::KeyPressed, "KeyPressed"), keyCode(keyCode), isRepeat(isRepeat) {}

			// Ket the keycode pressed - TO CHANGE FROM INT TO A UNNIVERSAL KEYCODE CLASS
			KeyCode GetKeyCode() const { return keyCode; }

			//Get the 'repeatage'
			bool IsRepeat() { return isRepeat; }

		private:
			KeyCode keyCode;
			bool isRepeat;
	};

	/// KEY RELEASED EVENT - Holds Utility Funtion holding the key released
	class KeyReleasedEvent : public Event<VoxEvents>
	{
	public:
		// Constructor - assign the keycode and assign the event type constrctor
		KeyReleasedEvent(const KeyCode keyCode) : Event<VoxEvents>(VoxEvents::KeyReleased, "KeyReleased"), keyCode(keyCode) {}


		// Ket the keycode released - TO CHANGE FROM INT TO A UNNIVERSAL KEYCODE CLASS
		KeyCode GetKeyCode() const { return keyCode; }


	private:
		KeyCode keyCode;
	};

	
}
