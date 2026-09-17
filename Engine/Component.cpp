#include "pch.h"
#include "Component.h"
#include "Entity.h"

Component::Component(Entity const& entity)
{
	m_pEntity = std::make_shared<Entity>(entity);
}

Component::~Component()
{
}

std::shared_ptr<Entity const> Component::GetEntity() const
{
	return m_pEntity;
}

void Component::Update()
{
	OnUpdate.Execute();
}


