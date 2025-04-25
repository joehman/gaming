
file(GLOB_RECURSE SRCS "*.cpp" "*.c")

add_executable(Game ${SRCS})

target_link_libraries(Game PRIVATE glfw)
target_link_libraries(Game PRIVATE imgui)
target_link_libraries(Game PRIVATE entt)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
    target_include_directories(Game PRIVATE OpenGL::GL) 
    target_link_libraries(Game PRIVATE ${OPENGL_LIBRARIES})
else()
    message("OPENGL WAS NOT FOUND ON THE SYSTEM! FATAL!")
endif()

target_include_directories(Game PRIVATE backend/dependencies)
target_include_directories(Game PRIVATE .)
