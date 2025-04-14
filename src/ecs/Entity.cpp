#include <ecs/Entity.hpp>

Entity::Entity(Scene scene)
{
    _Scene = &scene;
    this->_Entity = _Scene->Registry.create();
}


template<typename Type, typename ...Args>
void Entity::AddComponent(Args &&...args)
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
