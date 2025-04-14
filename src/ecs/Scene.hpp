#pragma once


#include <entt.hpp>

class Scene {
public:
    Scene() {};
    Scene(const Scene &) {};

    entt::registry Registry;

    Scene operator=(const Scene &);

};