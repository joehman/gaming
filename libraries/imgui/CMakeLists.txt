# custom made because Imgui doesn't use CMake.
set(IMGUI_DIR "${CMAKE_CURRENT_LIST_DIR}/DearImGui")


file(GLOB BACKEND_SRCS 
    "${IMGUI_DIR}/backends/imgui_impl_opengl*.cpp"
    "${IMGUI_DIR}/backends/imgui_impl_glfw*.cpp" )

file(GLOB SRCS "${IMGUI_DIR}/*.cpp")



IF(WIN32)

file(GLOB WIN32_SRCS 
    "${IMGUI_DIR}/backends/imgui_impl_win*.cpp")
add_library(imgui ${SRCS} ${BACKEND_SRCS} ${WIN32_SRCS})

ELSEIF(LINUX)

add_library(imgui ${SRCS} ${BACKEND_SRCS})

ENDIF()

target_include_directories(imgui PUBLIC DearImGui/)
target_include_directories(imgui PUBLIC DearImGui/backends)