#ifndef TRANSFORM_2D_H_
#define TRANSFORM_2D_H_

#include "Component.h"

#include <Vec2.h>

class Transform2D : public Component
{
public:

	Transform2D(Entity* pEntity);
	Transform2D(Entity* pEntity, Vec2f const& position, Vec2f const& scale, Vec2f const& size, float rotation);
	~Transform2D();

	void Update() override;

	void SetPosition(Vec2f const& position);
	void SetScale(Vec2f const& scale);
	void SetSize(Vec2f const& size);
	void SetRotation(float rotation);

	Vec2f GetPosition() const;
	Vec2f GetScale() const;
	Vec2f GetSize() const;
	float GetRotation() const;

protected:
	Vec2f m_position;
	Vec2f m_scale;
	Vec2f m_size;
	float m_rotation;

};

#endif
