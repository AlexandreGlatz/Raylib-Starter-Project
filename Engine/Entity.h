#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>
#include <vector>
#include <memory>
#include <optional>
#include <type_traits>

#include <Action.h>
#include <Logger.h>

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
	
private:
	bool IsComponentAdded(std::string type);
	template<typename T>
	bool IsComponent();

};

#endif

template<typename T>
inline std::shared_ptr<T> Entity::AddComponent()
{

	if (std::is_base_of(Component, T)::value == false)
	{
		Logger::Log(LOG_LEVEL::ERROR, "Can't add a non-component to an entity");
		return nullptr;
	}

	std::shared_ptr<T> pNewComponent = std::make_shared<T>(this);

	std::string newComponentType = pNewComponent.GetType();
	if (IsComponentAdded(newComponentType))
	{
		Logger::LogPrintf(LOG_LEVEL::ERROR, "Component of Type %s already exists in Entity of name %s", newComponentType.c_str(), m_name.c_str());
		return nullptr;
	}

	m_components.push_back(pNewComponent);
	return pNewComponent;
}

template<typename T>
inline std::optional<std::shared_ptr<T>> Entity::GetComponent() const
{
	if (IsComponent<T>() == false)
	{
		Logger::Log(LOG_LEVEL::ERROR, "Can't get a non-component class");
		return nullptr;
	}

	if (IsComponentAdded(T::GetType()) == false)
	{
		Logger::LogPrintf(LOG_LEVEL::ERROR, "Component of type %s doesnt exist in entity of name %s", T::GetType().c_str(), m_name.c_str());
	}

	return std::optional<std::shared_ptr<T>>();
}

template<typename T>
inline bool Entity::IsComponent()
{
	return std::is_base_of(Component, T)::value;
}
