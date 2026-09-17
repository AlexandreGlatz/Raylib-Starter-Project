#include "pch.h"
#include "Collider.h"
#include "Entity.h"
#include "Transform2D.h"

#include <Logger.h>
#include <memory>

Collider::Collider(Entity const& entity) : Component(entity), m_isTrigger(false)
{
	std::shared_ptr<Transform2D> transform = entity.GetComponent<Transform2D>();
	if (transform == nullptr)
	{
		Logger::Log(LOG_LEVEL::ERROR, "Collider cannot be created without a Transform2D Component");
		return;
	}

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
