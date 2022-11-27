#pragma once

#include "Event.h"

namespace Vox
{

	// Event dispatcher holds a map of events to callback functions 
	// This map is populated via subscriptions
	// Subscribe via example like dispatcher.Subscribe(EventType::EVENT, std::bind(&Observer::HandleFunction, Observer, std::placehoilders::_1))
	template <typename T>
	class EventDispatcher
	{
	private:
		// Define a type Event Callback Fucnction  which returns a bool (will set the handled) the event of type T will be passed as a reference
		// dont need to use this to define - this is simply any fucntion that returns a bool and takes in an event reference
		using EventCallbackFn = std::function<bool(const Event<T>&)>;
		std::map<T, std::vector<EventCallbackFn>> observers;

	public:
		// Subscribe to an event - add the type in the map to the observers
		void Subscribe(T type, const EventCallbackFn& func)
		{
			observers[type].push_back(func);
		}


		// Dispatch an event
		void Dispatch(Event<T>& event)
		{
			// If we do not find the event (map.end gives a theoretical element past the map)
			if (observers.find(event.getType()) == observers.end())
				return;

			// Loop through all the observers of that event - if it is not handled then process it
			// Auto&& to do with lvalues and rvalues?
			// observer(event) callback is the func found, passing in the event as the parameter - event is type Event<T>&. callback is type EventCallbackFunc
			for (auto&& callback : observers.at(event.getType()))
			{
				if (!event.IsHandled) event.IsHandled = callback(event);
			}

		}


	

	};
}
