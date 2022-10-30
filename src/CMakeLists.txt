# CMakeList.txt: proyecto de CMake para DelfosEngine, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.8)

# Agregue un origen al ejecutable de este proyecto.
add_executable (DelfosEngine main.cpp "public/Core/Core.h" "private/Core/Core.cpp" "private/Math/Vector/Vector3.cpp" "private/Math/Vector/Vector3.cpp" "public/Engine/GameObject/GameObject.h" "public/Math/Transform/Transform.h"   "private/Math/Transform/Transform.cpp" "private/Engine/GameObject/GameObject.cpp"   "public/Engine/Project/ProjectManager.h" "private/Engine/Project/ProjectManager.cpp" "public/Math/Vector/Vector2.h" "private/Math/Vector/Vector2.cpp" "public/Engine/Scene/Scene.h" "private/Engine/Scene/Scene.cpp" "public/Engine/Scene/SceneManager.h" "private/Engine/Scene/SceneManager.cpp"      "public/IO/FileManager.h" "private/IO/FileManager.cpp" "public/Engine/Scene/Camera.h" "private/Engine/Scene/Camera.cpp" "public/Module/Input/Input.h" "private/Module/Input/Input.cpp" "private/Engine/Shader/Shader.cpp" "public/Engine/Shader/Shader.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DelfosEngine PROPERTY CXX_STANDARD 20)
  set_property(TARGET DelfosEngine PROPERTY WIN32_EXECUTABLE TRUE)
endif()

add_compile_definitions(NOMINMAX)

# TODO: Agregue pruebas y destinos de instalación si es necesario.
set(GLOBAL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../include")
set(SOURCE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/public")
set(SDL_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../lib/SDL/SDL2.lib;${CMAKE_CURRENT_SOURCE_DIR}/../lib/SDL/SDL2main.lib;${CMAKE_CURRENT_SOURCE_DIR}/../lib/SDL/SDL2_image.lib")
set(GL_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../lib/GL/OpenGL32.lib;${CMAKE_CURRENT_SOURCE_DIR}/../lib/GL/GlU32.lib;${CMAKE_CURRENT_SOURCE_DIR}/../lib/GL/glew32.lib")
set(FBX_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../lib/FBX/libfbxsdk.lib")
set(ASSIMP_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../lib/ASSIMP/assimp.lib")
set(LIBPNG_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../lib/LibPNG/libpng16.lib")

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Shaders/GameObject.vert" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Assets/Shaders")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Shaders/GameObject.frag" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Assets/Shaders")

target_link_libraries(DelfosEngine ${GL_LIBRARIES})
target_link_libraries(DelfosEngine ${SDL_LIBRARIES})
target_link_libraries(DelfosEngine ${ASSIMP_LIBRARIES})
target_link_libraries(DelfosEngine ${LIBPNG_LIBRARIES})
#target_link_libraries(DelfosEngine ${FBX_LIBRARIES})
include_directories(${GLOBAL_INCLUDE_DIR})
include_directories(${SOURCE_INCLUDE_DIR})