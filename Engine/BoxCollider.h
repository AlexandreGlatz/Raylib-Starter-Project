#ifndef BOX_COLLIDER_H_
#define BOX_COLLIDER_H_

#include "Collider.h"

#include <Vec2.h>

class BoxCollider: public Collider
{
public:
	BoxCollider();
	~BoxCollider();
	
	void CheckCollision(BoxCollider const& other);

private:
	Vec2f size;
};

#endif

