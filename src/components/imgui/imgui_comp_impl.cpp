#include <components/imgui/imgui_component.hpp>
#include <backend/ecs/Entity.hpp>

imgui_base::imgui_base(Entity* parent) : Component(parent)
{
	// does nothing
}

imgui_test::imgui_test(Entity* parent) : Component(parent)
{

}

void imgui_test::init()
{
	if ((*parent).HasComponent<imgui_base>())
	{
		std::cout << "found";
		auto comp = (*parent).GetComponent<imgui_base>();
		
		comp.update_callback = [this](){
			this->update();
		};

		return;
	}

	std::cout << "IMGUI_BASE COMPONENT IS NEEDED FOR IMGUI COMPONENTS TO WORK!\n";
}

void imgui_test::update()
{
	std::cout << "update()\n";
	ImGui::ShowDemoWindow();
}




