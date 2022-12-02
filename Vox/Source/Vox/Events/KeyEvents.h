#pragma once

#include "Event.h"

namespace Vox
{
	

	/// KEY PRESSED EVENT - Holds utility function for repeat and the code that is being used 
	class KeyPressedEvent : public virtual Event<VoxEvents>
	{
		public:
			// Constructor - assign the keycode and assign the event type constrctor
			KeyPressedEvent(const int keyCode, bool isRepeat = false) : Event<VoxEvents>(VoxEvents::KeyPressed, "KeyPressed"), keyCode(keyCode), isRepeat(isRepeat) {}


			// Ket the keycode pressed - TO CHANGE FROM INT TO A UNNIVERSAL KEYCODE CLASS
			int GetKeyCode() const { return keyCode; }

			//Get the 'repeatage'
			bool IsRepeat() { return isRepeat; }

		private:
			int keyCode;
			bool isRepeat;
	};

	/// KEY RELEASED EVENT - Holds Utility Funtion holding the key released
	class KeyReleasedEvent : public Event<VoxEvents>
	{
	public:
		// Constructor - assign the keycode and assign the event type constrctor
		KeyReleasedEvent(const int keyCode) : Event<VoxEvents>(VoxEvents::KeyReleased, "KeyReleased"), keyCode(keyCode) {}


		// Ket the keycode released - TO CHANGE FROM INT TO A UNNIVERSAL KEYCODE CLASS
		int GetKeyCode() const { return keyCode; }


	private:
		int keyCode;
	};

	
}
