/******************************************************************************************
*                                                                                         *
*    GUI Application Base                                                                 *
*                                                                                         *
*    Copyright (c) 2023 Onur AKIN <https://github.com/onurae>                             *
*    Licensed under the MIT License.                                                      *
*                                                                                         *
******************************************************************************************/

#ifndef GUIAPP_HPP
#define GUIAPP_HPP

#include <cstdlib>
#include <string>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "implot.h"
#include <stdio.h>
#define GL_SILENCE_DEPRECATION
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h>
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

class GuiApp
{
public:
    explicit GuiApp(const std::string& name);
    virtual ~GuiApp();
    void Run();
    virtual void Update() = 0;

private:
    static void glfw_error_callback(int error, const char* description);
    GLFWwindow* window;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

protected:
    ImFont* font1;
    ImFont* font2;
};

#endif /* GUIAPP_HPP */
