#include "pch.h"
#include "Collider.h"
#include "Entity.h"
#include "Transform2D.h"

#include <Logger.h>
#include <memory>

Collider::Collider(Entity const& entity) : Component(entity), m_isTrigger(false)
{
	m_pEntity->CheckDependencies<0, Transform2D>(m_type);
	std::shared_ptr<Transform2D> transform = entity.GetComponent<Transform2D>();

	m_position = transform->GetPosition();
}

Collider::~Collider()
{
}

void Collider::Update()
{
	Component::Update();
}

void Collider::CollisionEnter(Collider& other)
{
	OnCollisionEnter.Execute(other);
}

void Collider::CollisionExit(Collider& other)
{
	OnCollisionExit.Execute(other);
}
