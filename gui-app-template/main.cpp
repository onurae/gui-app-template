#include "GuiApp.hpp"

class MyApp : public GuiApp
{
public:
    MyApp() : GuiApp("MyApp") {}
    ~MyApp() final = default;
    void Update() override
    {
        //ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());

        ImGui::ShowDemoWindow();
        ImGui::Begin("Frame Rate!");
        ImGuiStyle& style = ImGui::GetStyle();
        style.WindowMinSize = ImVec2(400, 75);
        style.Colors[ImGuiCol_TitleBg] = ImColor(100, 101, 53, 255);
        style.Colors[ImGuiCol_TitleBgActive] = ImColor(255, 101, 53, 255);
        style.Colors[ImGuiCol_TitleBgCollapsed] = ImColor(0, 0, 0, 130);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }
};

int main()
{
    MyApp myApp;
    myApp.Run();
    return 0;
}