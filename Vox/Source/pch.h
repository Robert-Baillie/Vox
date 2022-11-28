#pragma once


// Standard Includes
#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

// Type Includes
//#include <sstream>
#include <string>
#include <vector>
#include <map>

// Platform Includes
#ifdef VX_PLATFORM_WINDOWS
	#include <Windows.h>
#endif


// Defined Includes
#include "Vox/Log.h"

// Engine Includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>


// Events
#include "Vox/Events/Event.h"
#include "Vox/Events/EventDispatcher.h"
#include "Vox/Events/KeyEvents.h"
#include "Vox/Events/MouseEvents.h"
#include "Vox/Events/WindowEvents.h"

// OTHERS - Maths, Physics, VoxEngine Types i.e: VXuint, VXbool etc...
