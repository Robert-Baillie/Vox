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
		
	}

};


Vox::Application* Vox::CreateApplication() 
{
	return new Sandbox();
}