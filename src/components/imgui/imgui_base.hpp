#pragma once

#include <imgui.h>
#include <functional>
#include <iostream>

namespace Components
{
	struct imgui_base
	{
		std::function<void(void)> update_callback;
	};

	struct imgui_test
	{
		imgui_test();

		void update();
	};


}

