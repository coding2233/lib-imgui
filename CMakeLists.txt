cmake_minimum_required(VERSION 3.3)

project(lib-imgui)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(glfw)

include_directories(imgui imgui/examples)
include_directories(glfw/include)

find_library(opengl-lib NAMES OpenGL GL)
message(${opengl-lib})

find_library(glew-lib NAMES GLEW)
message(${glew-lib})

set( imgui_src imgui/imgui.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_demo.cpp
        imgui/examples/imgui_impl_glfw.cpp
        imgui/examples/imgui_impl_opengl3.cpp )

add_executable(${PROJECT_NAME} imgui_opengl3_app.cpp ${imgui_src})

target_link_libraries(${PROJECT_NAME} glfw ${opengl-lib} ${glew-lib})