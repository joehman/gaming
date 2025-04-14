cmake_minimum_required(VERSION 3.10)

# Project name
project(MyApp CXX)


# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -g")

# Directories
set(SRC_DIR src)
set(BIN_DIR bin)
set(LIB_DIR 
    libraries/glfw
    libraries/cglm
)
set(INCLDS 
    libraries/glm/include
    libraries/glfw/include
    ${SRC_DIR}
    ${SRC_DIR}/dependencies
)

# Find source files
file(GLOB_RECURSE SRCS "${SRC_DIR}/*.c")

# Create output directory
file(MAKE_DIRECTORY ${BIN_DIR})

# Include directories
include_directories(${INCLDS})

# Link libraries
IF (WIN32)
set(LIBS 
    glfw3
    opengl32
    glm
)
ELSE()

set(LIBS 
    glfw3
    GL
    glm
    m
)

ENDIF()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DIR})

link_directories(${LIB_DIR})

# Create the executable
add_executable(app ${SRCS})

# Link libraries to the executable
target_link_libraries(app ${LIBS})

