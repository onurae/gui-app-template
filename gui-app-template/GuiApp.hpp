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
#include "imgui_internal.h"
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

#include "utility/RobotoMedium.cpp"
#include "utility/RobotoRegular.cpp"
#include "utility/MaterialIcons.cpp"

class GuiApp
{
public:
    explicit GuiApp(std::string_view name);
    virtual ~GuiApp();
    void Run();
    virtual void Update() = 0;
    
    void SetTitle(std::string_view name, bool asteriskFlag);
    std::string GetTitle() const { return title; }

private:
    std::string title{ "" };
    std::string appName{ "" };
    static void glfw_error_callback(int error, const char* description);
    GLFWwindow* window;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

protected:
    ImFont* fontRobotoMedium;
    ImFont* fontRobotoRegular;
    ImFont* fontMaterialIcons;
    ImFont* fontLarge;
    ImFont* iconLarge;
};

#endif /* GUIAPP_HPP */
