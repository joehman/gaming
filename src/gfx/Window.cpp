#include "GLFW/glfw3.h"
#include <GL/gl.h>
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

void Window::setClearColor(float r, float g, float b, float a)
{
   glClearColor(r,g,b,a); 
}
void Window::clearWindow()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
void Window::updateWindow()
{ 
    glfwSwapBuffers(this->window);
    glfwPollEvents();
}
void Window::setWindowAttrib(int attrib, int value)            
{
    glfwSetWindowAttrib(this->window, attrib, value);
}
void Window::setWindowHint(int hint, int value)
{
    glfwWindowHint(hint, value);
}
bool Window::shouldClose() 
{
    return glfwWindowShouldClose(this->window);
}
