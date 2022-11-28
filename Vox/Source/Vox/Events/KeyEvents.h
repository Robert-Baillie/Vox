#pragma once

#include "Event.h"

namespace Vox
{
	enum class KeyEvents
	{
		KeyPressed,
		KeyReleased,
		KeyRepeat
	};


	/// KEY PRESSED EVENT - Holds utility function for repeat and the code that is being used 
	class KeyPressedEvent : public Event<KeyEvents>
	{
		public:
			// Constructor - assign the keycode and assign the event type constrctor
			KeyPressedEvent(const int keyCode, bool isRepeat = false) : Event<KeyEvents>(KeyEvents::KeyPressed, "KeyPressed"), keyCode(keyCode), isRepeat(isRepeat) {}


			// Ket the keycode pressed - TO CHANGE FROM INT TO A UNNIVERSAL KEYCODE CLASS
			int GetKeyCode() const { return keyCode; }

			//Get the 'repeatage'
			bool IsRepeat() { return isRepeat; }

		private:
			int keyCode;
			bool isRepeat;
	};

	/// KEY RELEASED EVENT - Holds Utility Funtion holding the key released
	class KeyReleasedEvent : public Event<KeyEvents>
	{
	public:
		// Constructor - assign the keycode and assign the event type constrctor
		KeyReleasedEvent(const int keyCode) : Event<KeyEvents>(KeyEvents::KeyReleased, "KeyReleased"), keyCode(keyCode) {}


		// Ket the keycode released - TO CHANGE FROM INT TO A UNNIVERSAL KEYCODE CLASS
		int GetKeyCode() const { return keyCode; }


	private:
		int keyCode;
	};

	
}
