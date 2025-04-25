
#define _CRT_SECURE_NO_WARNINGS

#include <game.hpp>

#include <systems/imguiSystem.hpp>

class Game game;

#include <components/imgui/imgui_base.hpp>




int main()
{
    game.init(1920,1080,false,3,3);
    //Systems::imgui_init("#version 330");

    Scene test;
    Entity ent(&test);

    ent.AddComponent<Components::imgui_test>();

    


    game.start();
    
    while (!game.shouldClose)
    {

        game.window.updateWindow(); 

        game.onUpdate(); 
        
        //Systems::imgui_update(&test);
        game.window.clearWindow();
    }
}
