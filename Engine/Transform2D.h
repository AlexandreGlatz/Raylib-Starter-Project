#ifndef TRANSFORM_2D_H_
#define TRANSFORM_2D_H_

#include "Component.h"

#include <Vec2.h>

class Transform2D : public Component
{
public:
	Transform2D(Entity const& entity);
	Transform2D(Entity const& entity, Vec2f position, Vec2f scale);
	~Transform2D();

	Vec2f GetPosition() const;
	Vec2f GetScale() const;

protected:
	Vec2f m_position;
	Vec2f m_scale;
};

#endif
