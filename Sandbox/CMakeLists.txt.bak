# Set Minimum Version
cmake_minimum_required(VERSION 3.8)

# Set Project Settings
project(VoxSandbox)

# Set the binary folder
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${Vox_BINARY_DIR}/bin)


# include_directories(${CMAKE_CURRENT_BINARY_DIR})


add_executable(VoxSandbox Source/SandboxApp.cpp)

target_link_libraries(VoxSandbox
	PUBLIC VoxEngine
)


# Copy DLL
add_custom_command(
	TARGET VoxSandbox
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${VoxEngine_BINARY_DIR}/VoxEngine.dll"
	"${VoxSandbox_BINARY_DIR}/VoxEngine.dll"
)
