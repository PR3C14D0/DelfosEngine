# CMakeList.txt: proyecto de CMake para DelfosEngine, incluya el origen y defina
# la lógica específica del proyecto aquí.
#
cmake_minimum_required (VERSION 3.8)

# Agregue un origen al ejecutable de este proyecto.
add_executable (DelfosEngine main.cpp "public/Core/Core.h" "private/Core/Core.cpp" "private/Math/Vector/Vector3.cpp" "private/Math/Vector/Vector3.cpp" "public/Engine/GameObject/GameObject.h" "public/Math/Transform/Transform.h"   "private/Math/Transform/Transform.cpp" "private/Engine/GameObject/GameObject.cpp"   "public/Engine/Project/ProjectManager.h" "private/Engine/Project/ProjectManager.cpp" "public/Math/Vector/Vector2.h" "private/Math/Vector/Vector2.cpp" "public/Engine/Scene/Scene.h" "private/Engine/Scene/Scene.cpp" "public/Engine/Scene/SceneManager.h" "private/Engine/Scene/SceneManager.cpp"      "public/IO/FileManager.h" "private/IO/FileManager.cpp" "public/Engine/Scene/Camera.h" "private/Engine/Scene/Camera.cpp" "public/Module/Input/Input.h" "private/Module/Input/Input.cpp" "private/Engine/Shader/Shader.cpp" "public/Engine/Shader/Shader.h" "public/Engine/Scene/EditorCamera.h" "private/Engine/Scene/EditorCamera.cpp" "public/Math/Quaternion/Quaternion.h" "private/Math/Quaternion/Quaternion.cpp" "private/Engine/Editor/Editor.cpp" "public/Engine/Editor/Editor.h")

add_library("DelfosLib" STATIC "private/Engine/Shader/Shader.cpp" "private/Engine/GameObject/GameObject.cpp" "private/Math/Vector/Vector3.cpp" "private/Math/Transform/Transform.cpp" "private/IO/FileManager.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DelfosEngine PROPERTY CXX_STANDARD 20)
  set_property(TARGET DelfosEngine PROPERTY WIN32_EXECUTABLE TRUE)
endif()

add_compile_definitions(NOMINMAX)
add_definitions(-Zm2000)

set(GLOBAL_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../include")
set(SOURCE_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/public")
set(SDL_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../lib/SDL/SDL2.lib;${CMAKE_CURRENT_SOURCE_DIR}/../lib/SDL/SDL2main.lib;${CMAKE_CURRENT_SOURCE_DIR}/../lib/SDL/SDL2_image.lib")
set(GL_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../lib/GL/OpenGL32.lib;${CMAKE_CURRENT_SOURCE_DIR}/../lib/GL/GlU32.lib;${CMAKE_CURRENT_SOURCE_DIR}/../lib/GL/glew32.lib")
set(FBX_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../lib/FBX/libfbxsdk.lib")
set(ASSIMP_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../lib/ASSIMP/assimp.lib")
set(IMGUI_PATH "${GLOBAL_INCLUDE_DIR}/ImGUI")
file(GLOB IMGUI_SOURCES 
		${IMGUI_PATH}/imgui.cpp
		${IMGUI_PATH}/imgui_draw.cpp
		${IMGUI_PATH}/imgui_tables.cpp
		${IMGUI_PATH}/imgui_widgets.cpp
		${IMGUI_PATH}/backends/imgui_impl_sdl.cpp
		${IMGUI_PATH}/backends/imgui_impl_opengl3.cpp)

add_library("ImGUI" STATIC "${IMGUI_SOURCES}")

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Shaders/GameObject.vert" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Assets/Shaders")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/Shaders/GameObject.frag" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Assets/Shaders")


set(DelfosLib_LOCAL_INCLUDES "public/Engine/Shader/Shader.h" "public/Engine/GameObject/GameObject.h" "public/Math/Vector/Vector3.h" "public/Math/Transform/Transform.h" "public/IO/FileManager.h")
file(COPY "${GLOBAL_INCLUDE_DIR}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Build")
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/private/Engine/Script" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Build")

foreach(DelfosLib_HEADER ${DelfosLib_LOCAL_INCLUDES})
add_custom_command(TARGET DelfosEngine POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${DelfosLib_HEADER}" "${CMAKE_CURRENT_BINARY_DIR}/Build/include/Delfos/${DelfosLib_HEADER}")
endforeach()

set(SCRIPT_TEMPLATE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/private/Engine/Script")
set(SCRIPT_TEMPLATE_FILES "${SCRIPT_TEMPLATE_PATH}/CMakeLists.txt" "${SCRIPT_TEMPLATE_PATH}/F16.h" "${SCRIPT_TEMPLATE_PATH}/F16.cpp" "${SCRIPT_TEMPLATE_PATH}/UserScripts.cpp")

foreach(SCRIPT_TEMPLATE ${SCRIPT_TEMPLATE_FILES})
add_custom_command(TARGET DelfosLib POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${SCRIPT_TEMPLATE}" "${CMAKE_CURRENT_BINARY_DIR}/Build/Script")
endforeach()

foreach(SDL_LIB ${SDL_LIBRARIES})
file(COPY "${SDL_LIB}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Build/lib/SDL")
endforeach()

foreach(GL_LIB ${GL_LIBRARIES})
file(COPY "${GL_LIB}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Build/lib/GL")
endforeach()

foreach(ASSIMP_LIB ${ASSIMP_LIBRARIES})
file(COPY "${ASSIMP_LIB}" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/Build/lib/ASSIMP")
endforeach()

add_custom_command(TARGET DelfosLib POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_BINARY_DIR}/DelfosLib.lib" "${CMAKE_CURRENT_BINARY_DIR}/Build/lib")
add_custom_command(TARGET DelfosLib POST_BUILD COMMAND ${CMAKE_COMMAND} -E remove "${CMAKE_CURRENT_BINARY_DIR}/DelfosLib.lib")

target_link_libraries(DelfosEngine ${GL_LIBRARIES})
target_link_libraries(DelfosEngine ${SDL_LIBRARIES})
target_link_libraries(DelfosEngine ${ASSIMP_LIBRARIES})
target_link_libraries(DelfosEngine ImGUI)
include_directories(${GLOBAL_INCLUDE_DIR})
include_directories(${SOURCE_INCLUDE_DIR})