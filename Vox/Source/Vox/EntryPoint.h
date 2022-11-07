#pragma once

#ifdef VX_PLATFORM_WINDOWS

// We will have something that returns a pointer to a Vox Engine application
// Function defined somewhere else (in the Sandbox app)
extern Vox::Application* Vox::CreateApplication();

int main(int argc, char** argv)
{
	
	// Create application by calling the create application function on whatever found by the extern
	auto app = Vox::CreateApplication();
	app->Run();
	delete app;
}

#endif