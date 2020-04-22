//
// Created by wanderer on 4/22/20.
//

#ifndef IMGUI_OPENGL3_APP_H
#define IMGUI_OPENGL3_APP_H

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

class ImGuiOpenGL3App {
public:
    ImGuiOpenGL3App();
    ~ImGuiOpenGL3App();

    void Run();

private:
    GLFWwindow *glfw_window_;
    const char* glsl_version_;

    void Init();
    void MainLoop();
    void Cleanup();

protected:
    ImVec4 clear_color_;
    virtual void OnImGuiInit();
    virtual void OnImGui();

};


#endif //MAIN_IMGUI_OPENGL3_APP_H
