#include <cstdio>
#include <backend/ecs/Entity.hpp>
#include <string>

Entity::Entity(const Entity& ent)
{
    this->_Entity = ent._Entity;
    this->_pScene = ent._pScene;
}
Entity::Entity(Scene *scene)
{
    _pScene = scene;
    this->_Entity = _pScene->createEntity()._Entity;
}
void Entity::Destroy()
{
    this->_pScene->destroyEntity(*this);
}


//private
std::string Entity::getStringID()
{
    return std::to_string((int)this->_Entity);
}
