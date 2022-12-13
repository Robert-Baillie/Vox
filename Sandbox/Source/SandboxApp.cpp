#include <Vox.h>


class Sandbox : public Vox::Application
{
public:
	Vox::Entity t;

	bool firstTime = true;
	

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

		if (Vox::Input::IsKeyPressed(Vox::Key::W))
		{
			Vox::TestComponent tc = Vox::TestComponent();
			t.AddComponent(tc);
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