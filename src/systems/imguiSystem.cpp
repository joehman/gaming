#include "imguiSystem.hpp"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"


#include <game.hpp>

void Systems::imgui_init(char* shaderversion)
{
    static bool hasCalled = false;
    if (hasCalled)
        return;

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(game.window.getWindow(), true);
    ImGui_ImplOpenGL3_Init();

    hasCalled = true;
}


void Systems::imgui_update()
{

}
