#include "pch.h"
#include "Collider.h"
#include "Entity.h"
#include "Transform2D.h"

#include <Logger.h>
#include <memory>

Collider::Collider(Entity const& entity) : Component(entity)
{
	std::optional<std::shared_ptr<Transform2D>> transform = entity.GetComponent<Transform2D>();
	if (transform.has_value() == false)
	{
		Logger::Log(LOG_LEVEL::ERROR, "Collider cannot be created without a Transform2D Component");
	}

	m_position = transform.value()->GetPosition();

}

Collider::~Collider()
{
}

void Collider::CollisionEnter(Collider& other)
{
	OnCollisionEnter.Execute(other);
}

void Collider::CollisionExit(Collider& other)
{
	OnCollisionExit.Execute(other);
}
