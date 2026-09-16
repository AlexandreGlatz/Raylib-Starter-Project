#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "Component.h"

#include <Vec2.h>

class Transform2D;
class Collider : public Component
{
public:
	Collider();
	~Collider();

	void OnCollisionEnter(Collider& other);
	void OnCollisionExit(Collider& other);

private:
	Vec2f m_position;
	bool m_isTrigger;
};

#endif
