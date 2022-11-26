# Set Minimum Version
cmake_minimum_required(VERSION 3.8)

# Set Project Settings
project(VoxEngine)


# Add List of Static File
# SHOULD CHANGE FROM GLOB.
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

# Pre Compiled Headers
set(HEADER_FILES Source/pch.h)
target_precompile_headers(VoxEngine PRIVATE ${HEADER_FILES})

