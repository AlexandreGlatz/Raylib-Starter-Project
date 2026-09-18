#include "pch.h"
#include "Entity.h"
#include "Component.h"


Entity::Entity() : m_name("Entity" + std::to_string(id))
{
	id++;
}

Entity::Entity(std::string name) : m_name(name)
{
}

Entity::~Entity()
{
}

void Entity::SetName(std::string name)
{
	m_name = name;
}

std::string Entity::GetName() const
{
	return m_name;
}

bool Entity::IsComponentAdded(std::string type) const
{
	auto it = std::find_if(m_components.begin(), m_components.end(), 
		[&type](std::shared_ptr<Component> currentComponent)
		{ if (currentComponent == nullptr) return false; return currentComponent->GetTypeStr() == type; }

	);

	return it == m_components.end();
}

