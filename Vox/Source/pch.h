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
#include "Core/Log.h"
#include "Core/Window.h"

// Events


#include "Events/Event.h"
#include "Events/EventDispatcher.h"
#include "Events/KeyEvents.h"
#include "Events/MouseEvents.h"
#include "Events/WindowEvents.h"
#include "Events/SystemEvents.h"

#include "Core/KeyCodes.h"
#include "Core/MouseCodes.h"
#include "Core/Input.h"


// Components
#include "Core/Types.h"
#include "Scene/ComponentType.h"
#include "Scene/ComponentList.h"
