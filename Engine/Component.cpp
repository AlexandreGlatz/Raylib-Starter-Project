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
}

std::string Component::GetTypeStr()
{
	switch (m_type)
	{
	case COMPONENT_TYPE::BOX_COLLIDER:
		return "BOX_COLLIDER";
	case COMPONENT_TYPE::SPRITE_2D:
		return "SPRITE_2D";
	case COMPONENT_TYPE::TRANSFORM_2D:
		return "TRANSFORM_2D";
	}

	return "UKNOWN";
}

COMPONENT_TYPE Component::GetType()
{
	return m_type;
}

void Component::SetType(COMPONENT_TYPE type)
{
	m_type = type;
}

void Component::DisplayDependencyError(std::string type)
{
	Logger::LogPrintf(LOG_LEVEL::ERROR, "%s cannot be created without a %s Component", GetTypeStr().c_str(), type.c_str());
}


