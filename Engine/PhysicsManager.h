#ifndef PHYSICS_MANAGER
#define PHYSICS_MANAGER

#include "Collider.h"

#include <vector>
#include <memory>

class PhysicsManager
{
public:
	PhysicsManager();
	~PhysicsManager();
	
	void Update();

private:
	std::vector<std::shared_ptr<Collider>> m_colliders;
	
};

#endif

