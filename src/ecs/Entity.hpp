#pragma once

#include <ecs/Scene.hpp>

class Entity
{
public:
    Entity(Scene scene);
    ~Entity() {};


    template<typename Type, typename... Args>
    void AddComponent(Args &&...args);

    template<typename Type>
    bool HasComponent();    

    template<typename Type>
    auto GetComponent();


private:

    entt::entity _Entity;    
    Scene* _Scene;
};