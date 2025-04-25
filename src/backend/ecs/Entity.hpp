#pragma once
#include <backend/ecs/Scene.hpp>
#include <iostream>
#include <string>
class Entity
{
public:
    // use Scene::createEntity instead.    
    Entity() {}; 
    Entity(Scene *scene);
    Entity(const Entity &);

    void Destroy();
    
    //returns true if the entity still exists, false if it doesn't. 
    bool operator== (Entity const& ent)
    {
        return this->_pScene->entityExists(ent);
    }
    void operator= (Entity const& ent)
    {
        _pScene = ent._pScene;
        _Entity = ent._Entity;
    }

    // really wish I could put all of the Compnent functions into Entity.cpp, 
    // but the linker gets really mad when I try that.
    template<typename Type>
    void RemoveComponent()
    {
        if (!this->HasComponent<Type>())
        {
            std::cout << "Entity::RemoveComponent: Cannot remove a Component which the Entity does not have! IGNORED! "
                << this->getStringID() << '\n';
            return;
        }
        _pScene->Registry.erase<Type>(this->_Entity);
    }
    template<typename Type, typename ...Args>
    void AddComponent(Args ...args)
    {
        if (this->HasComponent<Type>())
        {
            std::cout << "Entity::AddComponent: Entity cannot have more than one Component of the same type! IGNORED! " 
                << this->getStringID() << "\n";
            return;
        }
        _pScene->Registry.emplace<Type>(this->_Entity, args...);    
    }
    template<typename Type>
    bool HasComponent()
    {
        return _pScene->Registry.all_of<Type>(this->_Entity);
    }
    template<typename Type>
    auto& GetComponent()
    {
        if (!this->HasComponent<Type>())
        {
            std::cout << "Entity::GetComponent: Cannot get a Component which an Entity does not have! UNDEFINED BEHAVIOUR!  "
                << this->getStringID() << '\n';
        }
        return _pScene->Registry.get<Type>(this->_Entity);
    }

    entt::entity getEntityID()
    {
        return _Entity;
    }
    void setEntityID(entt::entity ID)
    {
        _Entity = ID;
    }
    void setScene(Scene* scene)
    {
        this->_pScene = scene;
    }
private:

    std::string getStringID();

    entt::entity _Entity;
    Scene* _pScene;
};
