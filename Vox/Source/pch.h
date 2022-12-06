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
#include <unordered_map>
#include <set>

// Platform Includes
#ifdef VX_PLATFORM_WINDOWS
#include <Windows.h>
#endif



// Engine Includes
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// Defined Includes
#include "Vox/Core/Log.h"
#include "Vox/Core/Window.h"

// Events
#include "Vox/Events/Event.h"
#include "Vox/Events/EventDispatcher.h"
#include "Vox/Events/KeyEvents.h"
#include "Vox/Events/MouseEvents.h"
#include "Vox/Events/WindowEvents.h"

#include "Vox/Core/KeyCodes.h"
#include "Vox/Core/MouseCodes.h"
#include "Vox/Core/Input.h"


// OTHERS - Maths, Physics, VoxEngine Types i.e: VXuint, VXbool etc...
