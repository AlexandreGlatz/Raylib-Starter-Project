#include "pch.h"
#include "Component.h"
#include "Entity.h"

Component::Component(Entity* pEntity)
{
	m_pEntity = pEntity;
}

Component::~Component()
{
	m_pEntity = nullptr;
}

Entity* Component::GetEntity() const
{
	return m_pEntity;
}

void Component::Update()
{
}

std::string Component::GetTypeStr(COMPONENT_TYPE type)
{
	switch (type)
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
	return COMPONENT_TYPE::NONE;
}

void Component::DisplayDependencyError(std::string type)
{
	Logger::LogPrintf(LOG_LEVEL::ERROR, "%s cannot be created without a %s Component", GetTypeStr(GetType()).c_str(), type.c_str());
}


