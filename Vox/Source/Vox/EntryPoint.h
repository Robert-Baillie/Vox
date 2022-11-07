#pragma once

#ifdef VX_PLATFORM_WINDOWS

// We will have something that returns a pointer to a Vox Engine application
// Function defined somewhere else (in the Sandbox app)
extern Vox::Application* Vox::CreateApplication();

int main(int argc, char** argv)
{
	// For now - this is included into sandbox
	Vox::Log::Init();
	VX_CORE_WARN("Initialised Log!");
	int test = 5;
	VX_INFO("Oh no! Var = {0}", test);
	
	// Create application by calling the create application function on whatever found by the extern
	auto app = Vox::CreateApplication();
	app->Run();
	delete app;
}

#endif