# Set Minimum Version
cmake_minimum_required(VERSION 3.8)

# Set Project Settings
project(VoxDevEnv)

# Add Components
add_subdirectory(Vox)
add_subdirectory(Sandbox)

add_subdirectory(Vox/External/spdlog)

# USE_FOLDERS group cmake generated projects into one (CMakePredefinedTargets) folder
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# Below line set Demo as startup application in Visual Studio
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT VoxSandbox)

# Platform defines
if(WIN32)
	target_compile_definitions(VoxEngine PUBLIC VX_PLATFORM_WINDOWS)
endif()


