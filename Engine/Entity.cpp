#include "pch.h"
#include "Entity.h"
#include "Component.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::Update()
{
	OnUpdate.Execute();

	for (int i = 0; i < m_components.size(); ++i)
	{
		m_components[i]->Update();
	}
}

bool Entity::IsComponentAdded(std::string type) const
{
	auto it = std::find_if(m_components.begin(), m_components.end(), 
		[&type](std::shared_ptr<Component> currentComponent)
		{ return currentComponent->GetType()== type; }
	);

	return it == m_components.end();
}

