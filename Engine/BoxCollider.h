#ifndef BOX_COLLIDER_H_
#define BOX_COLLIDER_H_

#include "Collider.h"

#include <Vec2.h>

class BoxCollider: public Collider
{
public:
	BoxCollider(Entity const& entity);
	~BoxCollider();
	
	bool CheckCollision(BoxCollider const& other);

protected:
	Vec2f m_size;
};

#endif

