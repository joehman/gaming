#include <GLFW/glfw3.h>

class Window {
public:
    //use window::create instead.
    Window() {}

    Window(int width, int height, bool fullscreen, const char* name);
    void create(int width, int height, bool fullscreen, const char* name);
    
    ~Window();
    
    int getWidth() { return width; }
    int getHeight() { return height; }

private:
    GLFWwindow *window;
    int width, height;
};