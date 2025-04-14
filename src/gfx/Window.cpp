#include <gfx/Window.hpp>

Window::~Window()
{
    glfwDestroyWindow(this->window);
}
Window::Window(int width, int height, bool fullscreen, const char* name)
{
    this->create(width, height, fullscreen, name);
}

void Window::create(int width, int height, bool fullscreen, const char* name)
{
    if (!fullscreen)
        this->window = glfwCreateWindow(width, height, name, nullptr, nullptr);
    else 
        this->window = glfwCreateWindow(width, height, name, glfwGetPrimaryMonitor(), nullptr);

}
