# Minimum CMake version
cmake_minimum_required(VERSION 3.14)

# Name of the project
project(gui-app-template)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# imgui library
include(FetchContent)
FetchContent_Populate(
    imgui
    GIT_REPOSITORY https://github.com/ocornut/imgui.git
    GIT_TAG c191faf0ba478e9c58a69c63306986a21ebfb6e4 # docking Dec 8, 2022
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/libs/imgui-docking
)

# implot library
include(FetchContent)
FetchContent_Populate(
    implot
    GIT_REPOSITORY https://github.com/epezent/implot.git
    GIT_TAG 15e494b76a78b44ae2c1b76608ff9bc39a661409 # v0.14
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/libs/implot
)

# utility
include(FetchContent)
FetchContent_Populate(
    imgui-demo-binaries
    URL https://www.dearimgui.org/binaries/imgui-demo-binaries-20220504.zip
    SOURCE_DIR ${PROJECT_SOURCE_DIR}/libs/utility/imgui-demo-binaries
)

# Executable
file(GLOB SOURCES ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}/*.?pp)
file(GLOB SOURCES_IMGUI 
    ${PROJECT_SOURCE_DIR}/libs/imgui-docking/imconfig.h
    ${PROJECT_SOURCE_DIR}/libs/imgui-docking/imgui.h
    ${PROJECT_SOURCE_DIR}/libs/imgui-docking/imgui_internal.h
    ${PROJECT_SOURCE_DIR}/libs/imgui-docking/imgui.cpp
    ${PROJECT_SOURCE_DIR}/libs/imgui-docking/imgui_demo.cpp
    ${PROJECT_SOURCE_DIR}/libs/imgui-docking/imgui_draw.cpp
    ${PROJECT_SOURCE_DIR}/libs/imgui-docking/imgui_tables.cpp
    ${PROJECT_SOURCE_DIR}/libs/imgui-docking/imgui_widgets.cpp
)
file(GLOB SOURCES_IMGUI_IMPL
    ${PROJECT_SOURCE_DIR}/libs/imgui-docking/backends/imgui_impl_glfw.h
    ${PROJECT_SOURCE_DIR}/libs/imgui-docking/backends/imgui_impl_glfw.cpp
    ${PROJECT_SOURCE_DIR}/libs/imgui-docking/backends/imgui_impl_opengl3.h
    ${PROJECT_SOURCE_DIR}/libs/imgui-docking/backends/imgui_impl_opengl3.cpp
    ${PROJECT_SOURCE_DIR}/libs/imgui-docking/backends/imgui_impl_opengl3_loader.h
)
file(GLOB SOURCES_IMPLOT
    ${PROJECT_SOURCE_DIR}/libs/implot/implot.h
    ${PROJECT_SOURCE_DIR}/libs/implot/implot_internal.h
    ${PROJECT_SOURCE_DIR}/libs/implot/implot.cpp
    ${PROJECT_SOURCE_DIR}/libs/implot/implot_items.cpp
    ${PROJECT_SOURCE_DIR}/libs/implot/implot_demo.cpp
)
add_executable(GuiAppTemplate ${SOURCES_IMGUI} ${SOURCES_IMGUI_IMPL} ${SOURCES_IMPLOT} ${SOURCES})
set_target_properties(GuiAppTemplate
    PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE"
               LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
)
target_include_directories(GuiAppTemplate
    PRIVATE libs/imgui-docking
    PRIVATE libs/imgui-docking/backends
    PRIVATE libs/imgui-docking/examples/libs/glfw/include
    PRIVATE libs/implot
)
target_link_libraries(GuiAppTemplate
    PRIVATE ${PROJECT_SOURCE_DIR}/libs/imgui-docking/examples/libs/glfw/lib-vc2010-64/glfw3.lib
    PRIVATE opengl32.lib
)