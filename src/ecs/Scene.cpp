#include <ecs/Scene.hpp>
#include <ecs/Entity.hpp>

bool Scene::entityExists(Entity ent)
{
    if (this->Registry.valid(ent.getEntityID()))
    {
        return true;
    }
    return false;
}
void Scene::destroyEntity(Entity ent)
{
    if (entityExists(ent))
    {
        Registry.destroy(ent.getEntityID());
        
        //std::cout << "Destroyed Entity: "
        //    << std::to_string((int)ent.getEntityID()) << '\n';
        
        return;
    }
    std::cout << "Cannot destroy an Entity which does not exist! IGNORED! " 
        << std::to_string((int)ent.getEntityID()) << '\n';
}
Entity Scene::createEntity()
{
    Entity ent;
    
    ent.setScene(this);
    ent.setEntityID(this->Registry.create());
    return ent;
}

