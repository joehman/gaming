cmake_minimum_required(VERSION 3.10)


project(Minecraft LANGUAGES C CXX)

set(BIN_DIR ${CMAKE_CURRENT_LIST_DIR}/bin)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

add_subdirectory(libraries/glm)
add_subdirectory(libraries/glfw)
add_subdirectory(libraries/imgui)
add_subdirectory(libraries/entt)

add_subdirectory(src)