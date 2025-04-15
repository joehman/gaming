#pragma once

#include <entt.hpp>

class Scene {
public:
    Scene() {};
    Scene(const Scene &) {};
    Scene operator=(const Scene &);
    
    virtual void update() = 0;
    virtual void start() = 0;

    entt::registry Registry;
};
