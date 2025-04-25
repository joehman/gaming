
#define _CRT_SECURE_NO_WARNINGS

#include <game.hpp>

#include <systems/imguiSystem.hpp>

#include <components/imgui/imgui_component.hpp>

class Game game;

void imgui()
{
    std::cout << "imgui()\n";
    ImGui::ShowDemoWindow();
}

int main()
{
    game.init(1920,1080,false,3,3);
    Systems::imgui_init("#version 330");

    Scene scen;
    Entity ent(&scen);
    
    ent.AddComponent<imgui_base>();
    //ent.AddComponent<imgui_test>();



    ent.GetComponent<imgui_base>().update_callback = [] {
            imgui();
        };

    
    game.start();
    
    while (!game.shouldClose)
    {

        game.window.updateWindow(); 

        game.onUpdate(); 
        
        Systems::imgui_update(&scen);
        game.window.clearWindow();
    }
}
