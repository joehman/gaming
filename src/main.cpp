#include <world/overworld.hpp>
#include <game.hpp>

class Game game;

int main()
{
    
    game.init(1920,1080,false,3,3);

    game.start();
    while (!game.shouldClose)
    {
        game.window.updateWindow(); 

        game.onUpdate(); 
        

        game.window.clearWindow();
    }
}
