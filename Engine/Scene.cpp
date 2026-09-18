#include "pch.h"
#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
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

std::shared_ptr<Entity> Scene::CreateEntity()
{
	return std::make_shared<Entity>();
}

std::shared_ptr<Entity> Scene::CreateEntity(std::string name)
{
	return std::make_shared<Entity>(name);
}

