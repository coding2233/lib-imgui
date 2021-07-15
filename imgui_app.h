//
// Created by wanderer on 4/22/20.
//

#if WIN32
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif


#ifndef IMGUI_APP_H
#define IMGUI_APP_H

#include <GL/glew.h>
#include <SDL.h>
#include <stdio.h>

#include "imgui.h"
#include "imgui_impl_sdl.h"
#include "imgui_impl_opengl3.h"

// #if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
// #pragma comment(lib, "legacy_stdio_definitions")
// #endif

class ImGuiApp
{
public:
    ImGuiApp();
    ~ImGuiApp();

    void Run();

private:
    SDL_Window *sdl_window_;
    const char *glsl_version_;

    void Init();
    void MainLoop();
    void Cleanup();

protected:
    SDL_GLContext gl_context_;
    ImVec4 clear_color_;
    bool is_done_;
    virtual void OnImGuiInit();
    virtual void OnImGui();
    virtual void OnImGuiCleanup();
};

#endif //MAIN_IMGUI_OPENGL3_APP_H
