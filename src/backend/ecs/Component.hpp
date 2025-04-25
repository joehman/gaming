#pragma once

#include <backend/ecs/Entity.hpp>

//this is a base class for all components. Other Components will inhereit from this Component.
// All components need to store some kind of variable for their constructor to be called.
// I've chosen to make this variable a pointer to the entity which owns that Component.

// In reality, this is almost definetely unnecessary, but to avoid repeating code, 
// it's included anyway.

// DO NOT use this component on it's own. It isn't fatal, there's simply just no point.


struct Component
{
	Entity* parent;
	Component(Entity* parent);
};