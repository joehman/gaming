#include <ecs/Scene.hpp>
#include <ecs/Entity.hpp>

class Overworld : public Scene {

    

public:
    Overworld()
    {
        Scene();
    }


    void update()
    {

    }
};

#include <iostream>
#include "gfx/Window.hpp"

struct testComponent {
    int number;

    testComponent() = default;
    testComponent(const testComponent&) = default;
};


int main()
{
    bool shouldClose;
    //Window window(1920, 1080, false, std::string("Hello, World!").c_str()); // TODO : load these settings from a file 
    // TODO : fix entity wrapper
    
    /*
    Overworld overworld;
    while (!shouldClose)
    {
        overworld.update();


    }

    */
}