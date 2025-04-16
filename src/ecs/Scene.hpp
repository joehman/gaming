#pragma once

class Entity;

#include <entt.hpp>
class Scene {
public:
    Scene() {};
    Scene(const Scene &) {};
    Scene operator=(const Scene &);
    
    // the scene will have different functions which allow
    // you to add/remove and also get entities. Should also
    // have some kind of ID system so  

    bool entityExists(Entity ent);
    void destroyEntity(Entity ent);
    Entity createEntity();

    entt::registry Registry;
};
