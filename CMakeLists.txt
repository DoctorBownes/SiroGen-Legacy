# CMake entry point
cmake_minimum_required (VERSION 3.12)
project (SiroGen)

if( CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR )
	message( FATAL_ERROR "Please select another Build Directory ! (and give it a clever name, like 'build')" )
endif()
if( CMAKE_SOURCE_DIR MATCHES " " )
	message( "Your Source Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()
if( CMAKE_BINARY_DIR MATCHES " " )
	message( "Your Build Directory contains spaces. If you experience problems when compiling, this can be the cause." )
endif()

# Compile external dependencies
set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

if(UNIX)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++11 -O2")

	# For leak-checking and profiling, add '-pg' to CXX flags
	# set(CMAKE_CXX_FLAGS "-Wall -pg -std=c++11 -O2")
	# valgrind --leak-check=full ./demo
	# ./demo # creates cmon.out
	# gprof demo gmon.out > analysis.txt
endif(UNIX)

if(WIN32)
	# suppress pedantic warnings
	add_definitions( "/W1 /D_CRT_SECURE_NO_WARNINGS /wd4514 /nologo" )
endif(WIN32)

add_definitions( # g++ -Dxxx
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

# Compile external dependencies
add_subdirectory (external)

include_directories( # g++ -Ipath/to/headerfiles
	external/glfw-3.3.5/include/
	external/glm-0.9.9.8/
	external/glew-2.1.0/include/
	.
)

link_directories( # g++ -Lpath/to/library
)

set(ALL_GRAPHICS_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_210
	SiroGen
)

# SiroGen (libSiroGen.a)
add_library(SiroGen # ar rcs libSiroGen.a
	SiroGen/camera.h
	SiroGen/camera.cpp
	SiroGen/renderer.h
	SiroGen/renderer.cpp
	SiroGen/scene.h
	SiroGen/scene.cpp
	SiroGen/sprite.h
	SiroGen/sprite.cpp
	SiroGen/component.h
	SiroGen/component.cpp
	SiroGen/model.h
	SiroGen/model.cpp
	SiroGen/entity.h
	SiroGen/entity.cpp
	SiroGen/core.h
	SiroGen/core.cpp
	SiroGen/texture.h
	SiroGen/texture.cpp
	SiroGen/transform.h
	SiroGen/transform.cpp
	SiroGen/vector3.h
	SiroGen/vector3.cpp
	SiroGen/color.h
	SiroGen/color.cpp
	SiroGen/spriteanimation.h
	SiroGen/spriteanimation.cpp
	SiroGen/animation.h
	SiroGen/animation.cpp
	SiroGen/input.h
	SiroGen/input.cpp
	SiroGen/text.h
	SiroGen/text.cpp
	SiroGen/collider.h
	SiroGen/collider.cpp
	SiroGen/resourcemanager.h
	SiroGen/resourcemanager.cpp
	SiroGen/update.cpp
	SiroGen/update.h
)

# Test
add_executable(Test # g++ Test/test.cpp -o Test
	Test/test.cpp
	Test/test.h
	Test/main.cpp
	Test/player.cpp
	Test/player.h
	Test/whackem.cpp
	Test/whackem.h
	Test/gangster.cpp
	Test/gangster.h
)
target_link_libraries(Test # g++ -lSiroGen
	${ALL_GRAPHICS_LIBS}
)
	target_link_libraries(Test
		${ALL_GRAPHICS_LIBS}
	)

# ShootOut
add_executable(ShootOut # g++ ShootOut/shootout.cpp -o ShootOut
	ShootOut/shootout.cpp
	ShootOut/shootout.h
	ShootOut/main.cpp
	ShootOut/player.cpp
	ShootOut/player.h
)
target_link_libraries(ShootOut # g++ -lSiroGen
	${ALL_GRAPHICS_LIBS}
)
	target_link_libraries(ShootOut
		${ALL_GRAPHICS_LIBS}
	)

# DnG
add_executable(DnG # g++ DnG/main.cpp -o DnG
	DnG/floor.cpp
	DnG/floor.h
	DnG/main.cpp
	DnG/player.cpp
	DnG/player.h
	DnG/tile.cpp
	DnG/tile.h
	DnG/ground.cpp
	DnG/ground.h
	DnG/wall.cpp
	DnG/wall.h
)
target_link_libraries(DnG # g++ -lSiroGen
	${ALL_GRAPHICS_LIBS}
)
	target_link_libraries(DnG
		${ALL_GRAPHICS_LIBS}
	)

# Copy assets and shaders to the build directory
# (In Visual Studio, copy these directories to either 'Release' or 'Build')
file(
	COPY Test/assets
	DESTINATION ${CMAKE_BINARY_DIR}
)
file(
	COPY SiroGen/shaders
	DESTINATION ${CMAKE_BINARY_DIR}
)
