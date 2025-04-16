#pragma once
#include <GLFW/glfw3.h>

class Window {
public:
    //use window::create instead.
    Window() {}

    Window(int width, int height, bool fullscreen, const char* name)
    {
        this->create(width, height, fullscreen, name);
    }

    void create(int width, int height, bool fullscreen, const char* name);
    
    ~Window();
  
    GLFWwindow* getWindow() {return window;}
    void setWindowAttrib(int attrib, int value);
    void setWindowHint(int hint, int value);

    bool shouldClose();
    
    int getWidth() { return width;}
    int getHeight() { return height; }
   
    void setClearColor(float r, float g, float b, float a);
    void clearWindow();
    void updateWindow();
private:
    GLFWwindow *window;
    int width, height;
};
