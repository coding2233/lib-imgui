cmake_minimum_required(VERSION 3.3)

project(libimgui)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(glfw)

include_directories(imgui
        imgui/examples
        glfw/include
        library/glew-2.2.0/include)

if(WIN32)
    message("windows operation system")
    link_directories(library/glew-2.2.0/lib/Release/x64)
    set(lib glew32 opengl32)
elseif(UNIX)
    message("like unix operation system")
    find_library(opengl-lib NAMES OpenGL GL)
    message(${opengl-lib})

    find_library(glew-lib NAMES GLEW)
    message(${glew-lib})
    set(lib ${opengl-lib} ${glew-lib})
endif()

set( imgui_src imgui/imgui.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_widgets.cpp
        imgui/imgui_demo.cpp
        imgui/examples/imgui_impl_glfw.cpp
        imgui/examples/imgui_impl_opengl3.cpp )

add_library(${PROJECT_NAME} imgui_app.cpp ${imgui_src})

target_link_libraries(${PROJECT_NAME} glfw ${lib})