#pragma once
#include "pch.h"
#include "Core/TypeMap.h"
#include "System.h"



namespace Vox {
	class SystemManager {
		
	public:
		static SystemManager* GetManager() { return instance; };

		// Constructor (Initialises)
		SystemManager();


		template <typename T>
		void RegisterSystem() {
			std::shared_ptr<System> sys = std::make_shared<T>();
			systemList.push_back(sys);
		}

		void Update()
		{
			for (std::shared_ptr<System> sys : systemList)
			{
				sys->Update();
			}
		}

		void Awake()
		{
			for (std::shared_ptr<System> sys : systemList)
			{
				sys->Awake();
			}
		}

		void Stop()
		{
			for (std::shared_ptr<System> sys : systemList)
			{
				sys->Stop();
			}
		}

		void Start()
		{
			for (std::shared_ptr<System> sys : systemList)
			{
				sys->Start();
			}
		}

		void Render()
		{
			for (std::shared_ptr<System> sys : systemList)
			{
				sys->Render();
			}
		}


	private: 
		// List of Systems
		std::vector<std::shared_ptr<System>> systemList;


		TypeMap typeMap;

		// Event Methods
		bool OnEntityAdded(Event<SystemEvents>& event);
		bool OnEntityDestroyed(Event<SystemEvents>& event);
		bool OnComponentAdded(Event<SystemEvents>& event);
		bool OnComponentRemoved(Event<SystemEvents>& event);

		// MORE SINGLETONS LETS GOOOO
		static SystemManager* instance;
	};
}