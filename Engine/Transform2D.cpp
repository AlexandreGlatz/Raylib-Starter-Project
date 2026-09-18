#include "pch.h"
#include "Transform2D.h"

Transform2D::Transform2D(Entity const& entity) : 
	Component(entity),
	m_position({0.0f, 0.0f}),
	m_scale({ 1.0f, 1.0f }),
	m_size({100.0f, 100.0f}),
	m_rotation(0.0f)
{
}

Transform2D::Transform2D(Entity const& entity, Vec2f const& position, Vec2f const& scale, Vec2f const& size, float rotation)
	: Component(entity),
	m_rotation(rotation),
	m_position(position),
	m_scale(scale),
	m_size(size)
{
}

void Transform2D::Update()
{
}

Transform2D::~Transform2D()
{
}

void Transform2D::SetPosition(Vec2f const& position)
{
	m_position = position;
}

void Transform2D::SetScale(Vec2f const& scale)
{
	m_scale = scale;
}

void Transform2D::SetSize(Vec2f const& size)
{
	m_size = size;
}

void Transform2D::SetRotation(float rotation)
{
	m_rotation = rotation;
}

Vec2f Transform2D::GetPosition() const
{
	return m_position;
}

Vec2f Transform2D::GetScale() const
{
	return m_scale;
}

Vec2f Transform2D::GetSize() const
{
	return m_size;
}

float Transform2D::GetRotation() const
{
	return m_rotation;
}
