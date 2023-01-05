#include <Vox.h>

class Sandbox : public Vox::Application
{
public:

	Vox::Entity t;
	float moveSpeed = 2.5f;
	float scaleSpeed = 5.0f;
	float rotSpeed = 5.0f;

	Sandbox() 
	{
		float randX = rand() % 800 + 0;
		float randY = rand() % 600 + 0;

		float scaleStart = 50.0f;

		Vox::SpriteRenderer sr = Vox::SpriteRenderer("face");
		t.AddComponent<Vox::SpriteRenderer>(sr);

		t.GetComponent<Vox::Transform>()->Position = glm::vec3(randX, randY, 0.0f);
		t.GetComponent<Vox::Transform>()->Scale = glm::vec3(scaleStart, scaleStart, 0.0f);
		t.GetComponent<Vox::Transform>()->Rotation = glm::vec3(0, 0, 0);
	}

	~Sandbox()
	{

	}

	void Update()
	{
		// Moving
		float moveDifX = 0.0f;
		float moveDifY = 0.0f;

		if (Vox::Input::IsKeyPressed(Vox::Key::A)) moveDifX -= moveSpeed;
		if (Vox::Input::IsKeyPressed(Vox::Key::D)) moveDifX += moveSpeed;

		if (Vox::Input::IsKeyPressed(Vox::Key::W)) moveDifY -= moveSpeed;
		if (Vox::Input::IsKeyPressed(Vox::Key::S)) moveDifY += moveSpeed;

		if (Vox::Input::IsKeyPressed(Vox::Key::LEFT_SHIFT)) { moveDifX *= 2; moveDifY *= 2; }


		t.GetComponent<Vox::Transform>()->Position += glm::vec3(moveDifX, moveDifY, 0.0f);


		// Scale
		float scaleDif = 0.0f;
		if (Vox::Input::IsKeyPressed(Vox::Key::SPACE)) scaleDif += scaleSpeed;
		if (Vox::Input::IsKeyPressed(Vox::Key::LEFT_CONTROL)) scaleDif -= scaleSpeed;
		t.GetComponent<Vox::Transform>()->Scale += glm::vec3(scaleDif,scaleDif, 0.0f);

		// Rot
		float rotDif = 0.0f;
		if (Vox::Input::IsKeyPressed(Vox::Key::E)) rotDif += rotSpeed;
		if (Vox::Input::IsKeyPressed(Vox::Key::Q)) rotDif -= rotSpeed;
		t.GetComponent<Vox::Transform>()->Rotation += glm::vec3(0, 0, rotDif);

	}
};


Vox::Application* Vox::CreateApplication() 
{
	return new Sandbox();
}