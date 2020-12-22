cmake_minimum_required(VERSION 3.3)

project(libimgui)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(sdl)

include_directories(imgui
        imgui/backends
        sdl/include
        library/glew-2.2.0/include)

if(WIN32)
    message("windows operation system")
   # link_directories(library/glew-2.2.0/lib/Release/x64)
   set(glew32-lib-dir ${CMAKE_CURRENT_SOURCE_DIR}/library/glew-2.2.0/lib/Release/x64)
   set(lib opengl32 ${glew32-lib-dir}/glew32.lib)
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
        imgui/imgui_tables.cpp
        imgui/backends/imgui_impl_sdl.cpp
        imgui/backends/imgui_impl_opengl3.cpp )


add_library(${PROJECT_NAME} imgui_app.cpp ${imgui_src})

target_link_libraries(${PROJECT_NAME} ${lib} SDL2 SDL2main)