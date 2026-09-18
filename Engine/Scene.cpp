#include "pch.h"
#include "Scene.h"

Scene::Scene()
{
	m_components.resize(static_cast<uint8_t>(COMPONENT_TYPE::COMPONENT_COUNT));
}

Scene::~Scene()
{
}

void Scene::Load()
{
}

void Scene::Update()
{
	for (std::vector<std::shared_ptr<Component>> components : m_components)
	{
		for (std::shared_ptr<Component> component : components)
		{
			component->Update();
		}
	}
}

void Scene::Unload()
{
}

std::shared_ptr<Entity> Scene::CreateEntity()
{
	return std::make_shared<Entity>();
}

std::shared_ptr<Entity> Scene::CreateEntity(std::string name)
{
	return std::make_shared<Entity>(name);
}

