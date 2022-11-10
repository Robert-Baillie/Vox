# Set Minimum Version
cmake_minimum_required(VERSION 3.8)

# Set Project Settings
project(VoxEngine)


# Add List of Static File
file(GLOB_RECURSE VoxEngineSources "Source/**.cpp" "Source/**.h")
add_library(VoxEngine SHARED ${VoxEngineSources})

# Target Source
target_include_directories(VoxEngine PUBLIC ${PROJECT_SOURCE_DIR}/Source)

# Libraries
target_link_libraries(VoxEngine spdlog)

# Add compile definitions
list(APPEND VoxCompDefs
	"VX_BUILD_DLL"
	"OpenGL"
)

target_compile_definitions(VoxEngine PRIVATE ${VoxCompDefs})

add_custom_command(
	TARGET VoxEngine
	POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${PROJECT_BINARY_DIR}/Vox/Vox.dll"
	"${PROJECT_BINARY_DIR}/Sandbox"
)



# Installs
#install(TARGETS VoxEngine DESTINATION bin)
#install(FILES Source/Vox.h DESTINATION lib)