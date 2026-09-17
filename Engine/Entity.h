#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>
#include <vector>
#include <memory>
#include <optional>
#include <Action.h>

class Component;
class Entity
{
public:
	Entity();
	~Entity();

	void Update();

	template <typename T>
	std::shared_ptr<T> AddComponent();

	template <typename T>
	std::optional<std::shared_ptr<T>> GetComponent() const;

	Action<void()> OnUpdate;

protected:
	std::string m_name;
	std::vector<Component*> m_components;
};

#endif

