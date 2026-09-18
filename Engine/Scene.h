#ifndef SCENE_H_
#define SCENE_H_

#include "Entity.h"

#include <vector>
#include <memory>
#include <string>

class Component;
class Scene
{
public:
	Scene();
	~Scene();

	void Load();
	void Update();
	void Unload();

	std::shared_ptr<Entity> CreateEntity();
	std::shared_ptr<Entity> CreateEntity(std::string name);

	template <typename T>
	std::shared_ptr<T> AddComponent(std::shared_ptr<Entity> const& pEntity);

private:
	std::vector<std::vector<std::shared_ptr<Component>>> m_components;
};


template<typename T>
inline std::shared_ptr<T> Scene::AddComponent(std::shared_ptr<Entity> const& pEntity)
{

	std::shared_ptr<T> newComponent = pEntity->AddComponent<T>();

	if (newComponent == nullptr)
		return nullptr;

	m_components[static_cast<uint8_t>(T::GetType())].push_back(dynamic_pointer_cast<Component>(newComponent));

	return newComponent;
}
#endif

