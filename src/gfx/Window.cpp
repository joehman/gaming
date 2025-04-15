#include "GLFW/glfw3.h"
#include <gfx/Window.hpp>

Window::~Window()
{
    glfwDestroyWindow(this->window);
}

void Window::create(int width, int height, bool fullscreen, const char* name)
{
    if (!fullscreen)
        this->window = glfwCreateWindow(width, height, name, nullptr, nullptr);
    else 
        this->window = glfwCreateWindow(width, height, name, glfwGetPrimaryMonitor(), nullptr);
}

// TODO : finish this once opengl is set up
void Window::clearWindow()
{
     
}

void Window::updateWindow()
{ 
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}
