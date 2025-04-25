#include <components/imgui/imgui_base.hpp>

namespace Components
{
	imgui_test::imgui_test()
	{
		std::cout << "imgui_test()" << '\n';
	}
	void imgui_test::update()
	{

	}
}



//std::cout << "imgui_demo_window()";
/*
if (self.HasComponent<Components::imgui_base>())
{
	auto comp = self.GetComponent<Components::imgui_base>();
	comp.update_callback = std::bind(&imgui_demo_window::update, this);

	return;
}
*/