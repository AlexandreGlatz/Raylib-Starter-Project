#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "Component.h"

#include <Vec2.h>
#include <Action.h>

class Transform2D;
class Collider : public Component
{
public:
	Collider(Entity const& Entity);
	~Collider();

	void CollisionEnter(Collider& other);
	void CollisionExit(Collider& other);

	Action<void(Collider&)> OnCollisionEnter;
	Action<void(Collider&)> OnCollisionExit;

protected:
	Vec2f m_position;
	bool m_isTrigger;

};

#endif
