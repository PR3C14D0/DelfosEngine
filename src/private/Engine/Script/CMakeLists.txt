cmake_minimum_required(VERSION 3.8)

project("DelfosScript")

set(INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/../include")
set(LOCAL_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/../include/Delfos/public")

set(Delfos_LIBRARY "${CMAKE_CURRENT_SOURCE_DIR}/../lib/DelfosLib.lib")
set(SDL_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../lib/SDL/SDL2.lib;${CMAKE_CURRENT_SOURCE_DIR}/../lib/SDL/SDL2main.lib;${CMAKE_CURRENT_SOURCE_DIR}/../lib/SDL/SDL2_image.lib")
set(GL_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../lib/GL/OpenGL32.lib;${CMAKE_CURRENT_SOURCE_DIR}/../lib/GL/GlU32.lib;${CMAKE_CURRENT_SOURCE_DIR}/../lib/GL/glew32.lib")
set(ASSIMP_LIBRARIES "${CMAKE_CURRENT_SOURCE_DIR}/../lib/ASSIMP/assimp.lib")

add_library("DelfosScript" SHARED "UserScripts.cpp" "F16.h" "F16.cpp")

target_link_libraries(DelfosScript ${Delfos_LIBRARY})
target_link_libraries(DelfosScript ${SDL_LIBRARIES})
target_link_libraries(DelfosScript ${GL_LIBRARIES})
target_link_libraries(DelfosScript ${ASSIMP_LIBRARIES})
include_directories(${INCLUDES})
include_directories(${LOCAL_INCLUDES})