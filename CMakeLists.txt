cmake_minimum_required(VERSION 3.26)
project(3DEngine)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

set(output_name "3DEngine")

file(GLOB_RECURSE sources
    "src/main.cpp" # main file
    "src/renderEngine/*.cpp"
)

add_executable(${output_name} ${sources})

target_link_libraries(${output_name} GLEW glfw OpenGL)

add_custom_target(run
    COMMAND ${CMAKE_BINARY_DIR}/${output_name}
    DEPENDS ${output_name}
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    COMMENT "Running code"
)

add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E rm -r
        ${CMAKE_BINARY_DIR} CMakeFiles CMakeCache.txt cmake_install.cmake Makefile
    COMMENT "Cleaning all generated files"
)