#include "pch.h"
#include "Transform2D.h"

Transform2D::Transform2D(Entity const& entity) : Component(entity)
{
	m_position = { 0.0f, 0.0f };
	Transform2D::m_type = "Transform2D";
}

Transform2D::Transform2D(Entity const& entity, Vec2f position, Vec2f scale) : Component(entity)
{
	m_position = position, m_scale = scale;
}

Transform2D::~Transform2D()
{
}

Vec2f Transform2D::GetPosition() const
{
	return m_position;
}

Vec2f Transform2D::GetScale() const
{
	return m_scale;
}
