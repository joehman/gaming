#pragma once

#include <imgui.h>
#include <functional>
#include <iostream>

#include <backend/ecs/Entity.hpp>
#include <backend/ecs/Component.hpp>

// mainly so the system can find what function it needs to call to draw an imgui window.
struct imgui_base : public Component
{
	imgui_base(Entity* parent);

	std::function<void(void)> update_callback;
};

struct imgui_test : public Component
{
	imgui_test(Entity* parent);
	void init();

	void update();
};