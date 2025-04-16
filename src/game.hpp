#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <world/overworld.hpp>
#include <gfx/Window.hpp>

struct testComponent {
public:
    int x = 0;
    int b = 0;
    testComponent(int x, int b)
    {
        this->x = x;
        this->b = b;
    }
    testComponent(const testComponent &comp)
    {
        b = comp.b;
        x = comp.x;
    }


    void print()
    {
        std::cout << b << " " << x << '\n';;
    }
    
};

class Game {

public:
    Window window;

    Scene testScene;
    Entity testEnt;

    Game() {}
    void init(int width, int height, bool fullscreen, int GLversionMajor, int GLversionMinor)
    {
        glfwInit();
        window.create(width, height, fullscreen, "Game"); 
        window.setWindowHint(GLFW_CONTEXT_VERSION_MAJOR, GLversionMajor);
        window.setWindowHint(GLFW_CONTEXT_VERSION_MINOR, GLversionMinor);
        window.setWindowAttrib(GLFW_RESIZABLE, GLFW_FALSE);
        glfwMakeContextCurrent(window.getWindow());

        if (!gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress) )
        {
            std::cout << "GLAD Failed to load opengl! FATAL!\n";
        }
        glEnable(GL_DEPTH_TEST);

        window.setClearColor(0.1f, 0.2f, 0.4f, 1.0f);
    }
    void start()
    {
        testEnt = testScene.createEntity();
        testEnt.AddComponent<testComponent>(10,5);
        
        if (testEnt.HasComponent<testComponent>())
        { 
            testEnt.GetComponent<testComponent>().print();
        }
    }
    void onUpdate()
    {
             
    }
    
    bool shouldClose = false;
};

extern class Game game;
