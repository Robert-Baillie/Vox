#include <Vox.h>

class Sandbox : public Vox::Application
{
public:
	Vox::Entity t;
	Vox::Entity t2;

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
			Vox::SpriteRenderer sr = Vox::SpriteRenderer("face");
			t.AddComponent<Vox::SpriteRenderer>(sr);

			t.GetComponent<Vox::Transform>()->Position = glm::vec3(200.0f, 200.0f, 0.0f);
			t.GetComponent<Vox::Transform>()->Scale = glm::vec3(300.0f, 400.0f, 0.0f);
			t.GetComponent<Vox::Transform>()->Rotation = glm::vec3(0, 0, 45.0);
			
			Vox::SpriteRenderer sr2 = Vox::SpriteRenderer("face2");
			t2.AddComponent<Vox::SpriteRenderer>(sr2);

			t2.GetComponent<Vox::Transform>()->Position = glm::vec3(-200.0f, 200.0f, 0.0f);
			t2.GetComponent<Vox::Transform>()->Scale = glm::vec3(300.0f, 400.0f, 0.0f);
			t2.GetComponent<Vox::Transform>()->Rotation = glm::vec3(0, 0, 45.0);
			
			firstTime = false;
		}

		if (Vox::Input::IsKeyPressed(Vox::Key::W) && firstTime2)
		{
			t.GetComponent<Vox::SpriteRenderer>();

		}

		
		if (Vox::Input::IsKeyPressed(Vox::Key::S) && firstTime3)
		{
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