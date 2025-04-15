
#include "GLFW/glfw3.h"

#include "gfx/Window.hpp"

#include <world/overworld.hpp>

int main()
{
    glfwInit();
    
    OverWorld world;

    bool shouldClose = false;
   
    Window window(1920,1080, false, "Game");

    world.start();
    while (!shouldClose)
    {
        window.updateWindow(); 
        window.clearWindow();
        
        world.update(); 
        
            
    }
}
