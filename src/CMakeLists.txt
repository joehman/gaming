
file(GLOB_RECURSE SRCS "*.cpp" "*.c")


add_executable(Game ${SRCS})

target_link_libraries(Game PRIVATE glfw)
target_link_libraries(Game PRIVATE imgui)
target_link_libraries(Game PRIVATE entt)

target_include_directories(Game PRIVATE dependencies)