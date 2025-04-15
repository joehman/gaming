#include <cstdio>
#include <ecs/Entity.hpp>
#include <string>

/*
template<typename Type, typename ...Args>
void Entity::AddComponent(Args ...args)
{
    _Scene->Registry.emplace<Type>(this->_Entity, args...);    
}
template<typename Type>
bool Entity::HasComponent()
{
    return _Scene->Registry.all_of<Type>(this->_Entity);
}

template<typename Type>
auto Entity::GetComponent()
{
    return _Scene->Registry.get<Type>(this->_Entity);
}
*/
Entity::Entity(Scene *scene)
{
    _pScene = scene;
    this->_Entity = _pScene->Registry.create();
}

void Entity::Destroy()
{
    this->_pScene->Registry.destroy(this->_Entity);
}

std::string Entity::getStringID()
{
    return std::to_string((int)this->_Entity);
}
