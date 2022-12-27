#include <Vox.h>

class Sandbox : public Vox::Application
{
public:
	Vox::Entity t;
	Vox::Entity p;

	bool firstTime = true;
	bool firstTime2 = true;
	bool firstTime3 = true;

	

	Sandbox() 
	{
		
	}

	~Sandbox()
	{

	}

	void Update()
	{

		if (Vox::Input::IsKeyPressed(Vox::Key::SPACE) && firstTime)
		{
			t.DestroyEntity();
			p.DestroyEntity();
			t.GetComponent<Vox::TestComponent>();

			firstTime = false;
		}

		if (Vox::Input::IsKeyPressed(Vox::Key::W) && firstTime2)
		{


			Vox::TestComponent tc = Vox::TestComponent("One");
			Vox::TestComponent tc2 = Vox::TestComponent("Two");
			t.AddComponent(tc);
			p.AddComponent(tc2);
			firstTime2 = false;
			firstTime3 = true;
		}

		
		if (Vox::Input::IsKeyPressed(Vox::Key::S) && firstTime3)
		{
			t.RemoveComponent<Vox::TestComponent>();
			p.RemoveComponent<Vox::TestComponent>();
			firstTime3 = false;
			firstTime2 = true;
		}


	//	if (Vox::Input::IsKeyPressed(Vox::Key::A))
	//	{
	//		t.GetComponent<Vox::TestComponent>().Test();
	//	}
	}
};


Vox::Application* Vox::CreateApplication() 
{
	return new Sandbox();
}