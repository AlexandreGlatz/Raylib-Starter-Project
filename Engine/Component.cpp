#include "pch.h"
#include "Component.h"
#include "Entity.h"

#include "BoxCollider.h"
#include "Transform2D.h"

Component::Component(Entity const& entity)
{
	m_pEntity = std::make_shared<Entity>(entity);

	//#TODO Put it in GameManager Initialization
	BoxCollider::m_type = "BoxCollider";
	Transform2D::m_type = "Transform 2D";
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
}

std::string Component::GetType()
{
	return m_type;
}

void Component::DisplayDependencyError(std::string type)
{
	Logger::LogPrintf(LOG_LEVEL::ERROR, "%s cannot be created without a %s Component", m_type.c_str(), type.c_str());
}


