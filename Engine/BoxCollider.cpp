#include "pch.h"
#include "BoxCollider.h"

BoxCollider::BoxCollider(Entity const& entity) : Collider(entity)
{
	m_size = { 10.0f, 10.0f };
}

BoxCollider::~BoxCollider()
{
}

void BoxCollider::Update()
{
	Collider::Update();
}

bool BoxCollider::CheckCollision(BoxCollider const& other)
{
	return m_position.x < other.m_position.x + other.m_size.x &&
		m_position.x + m_size.x > other.m_position.x &&
		m_position.y < other.m_position.y + other.m_size.y &&
		m_position.y + m_size.y > other.m_position.y;
}
