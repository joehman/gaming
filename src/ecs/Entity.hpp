#pragma once
#include <ecs/Scene.hpp>
#include <iostream>
#include <string>
class Entity
{
public:
    Entity(Scene *scene);
    ~Entity() {};

    void Destroy();
    
    // really wish I could put all of the Compnent functions into Entity.cpp, 
    // but the linker gets really mad when I try this.
    template<typename Type>
    void RemoveComponent()
    {
        if (!this->HasComponent<Type>())
        {
            std::cout << "Entity::RemoveComponent: Cannot remove a Component which the Entity does not have! IGNORED! "
                << this->getStringID() << '\n';
        }
    }
    template<typename Type, typename ...Args>
    void AddComponent(Args ...args)
    {
        if (this->HasComponent<Type>())
        {
            std::cout << "Entity::AddComponent: Entity cannot have more than one Component of the same type! IGNORED! " 
                << this->getStringID() << "\n";
        }
        _pScene->Registry.emplace<Type>(this->_Entity, args...);    
    }
    template<typename Type>
    bool HasComponent()
    {
        return _pScene->Registry.all_of<Type>(this->_Entity);
    }
    template<typename Type>
    auto GetComponent()
    {
        if (!this->HasComponent<Type>())
        {
            std::cout << "Entity::GetComponent: Cannot get a Component which an Entity does not have! RETURNING NULL! "
                << this->getStringID() << '\n';
         
            return nullptr;
        }
        return _pScene->Registry.get<Type>(this->_Entity);
    }
private:

    std::string getStringID();

    entt::entity _Entity;
    Scene* _pScene;
};
