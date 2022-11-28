# Set Minimum Version
cmake_minimum_required(VERSION 3.8)

# Set Project Settings
project(Vox)

# Add Components
add_subdirectory(Vox)
add_subdirectory(Sandbox)
#include <glad/glad.h>

add_subdirectory(Vox/External/spdlog)
add_subdirectory(Vox/External/glm)
add_subdirectory(Vox/External/glfw)
add_subdirectory(Vox/External/glad)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# USE_FOLDERS group cmake generated projects into one (CMakePredefinedTargets) folder
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Below line set Demo as startup application in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT VoxSandbox)

# Platform defines
if(WIN32)
	target_compile_definitions(VoxEngine PUBLIC VX_PLATFORM_WINDOWS)
endif()




