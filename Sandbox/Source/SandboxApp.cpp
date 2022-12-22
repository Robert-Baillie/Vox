#include <Vox.h>

class Sandbox : public Vox::Application
{
public:
	Vox::Entity t;

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
			VX_TRACE("Test Entity ID: {0}", t.GetID());
			firstTime = false;
		}

		if (Vox::Input::IsKeyPressed(Vox::Key::W) && firstTime2)
		{
			Vox::TestComponent tc = Vox::TestComponent();
			Vox::TestComponentTwo tc2 = Vox::TestComponentTwo();
			t.AddComponent(tc);
			t.AddComponent(tc2);
			firstTime2 = false;
		}

		
		if (Vox::Input::IsKeyPressed(Vox::Key::S) && firstTime3)
		{
			t.GetComponent<Vox::TestComponent>().Test();
			t.GetComponent<Vox::TestComponentTwo>().Test();
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