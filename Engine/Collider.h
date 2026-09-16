#ifndef COLLIDER_H_
#define COLLIDER_H_

#include "Component.h"

class Transform2D;
class Collider : public Component
{
public:
	Collider();
	~Collider();

	void OnCollisionEnter(Collider& other);
	void OnCollisionExit(Collider& other);

private:
	int x;
	int y;
};

#endif
