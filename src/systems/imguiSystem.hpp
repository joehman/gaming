#pragma once

#include <ecs/Scene.hpp>

#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

namespace Systems
{
    void imgui_init(char* shaderversion);
    void imgui_update();
}
