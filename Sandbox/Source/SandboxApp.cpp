#include <Vox.h>

class Sandbox : public Vox::Application
{
public:
	Sandbox() 
	{
		
	}

	~Sandbox()
	{

	}

	void OnUpdate()
	{
		if (Vox::Input::IsKeyPressed(65) == true || Vox::Input::IsKeyPressed(64) == true)
		{
			VX_TRACE("A KEY PRESSED");
		}

	}

};


Vox::Application* Vox::CreateApplication() 
{
	return new Sandbox();
}