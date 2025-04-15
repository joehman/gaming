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
   
    void setWindowAttrib(int attrib, int value) 
    {
        glfwSetWindowAttrib(this->window, attrib, value);
    }
    bool shouldClose() 
    {
        return glfwWindowShouldClose(this->window);
    }
    
    int getWidth() { return width;}
    int getHeight() { return height; }
    
    void clearWindow();
    void updateWindow();
private:
    GLFWwindow *window;
    int width, height;
};
