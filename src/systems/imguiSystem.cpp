#include "imguiSystem.hpp"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include <components/imgui/imgui_base.hpp>

#include <game.hpp>

void Systems::imgui_init(const char* shaderversion = "#version 330")
{
    static bool hasCalled = false;
    if (hasCalled)
    {
        std::cout << "Imgui only needs to be initialized once!";
        return;
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(game.window.getWindow(), true);
    ImGui_ImplOpenGL3_Init(shaderversion);

    hasCalled = true;
}

void Systems::imgui_update(Scene *pScene)
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    //get all entities with the imgui_Base component
    auto entities = pScene->getEntitiesWithComponent<Components::imgui_base>();
    for (auto entity : entities) // loop through them
    {

        auto comp = entities.get<Components::imgui_base>(entity);
        
        // call imgui_base::update.
        comp.update_callback();

    }
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

