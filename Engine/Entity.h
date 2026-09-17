#ifndef ENTITY_H_
#define ENTITY_H_

#include "Component.h"

#include <string>
#include <vector>
#include <memory>
#include <optional>
#include <type_traits>

#include <Action.h>
#include <Logger.h>


class Entity
{
public:
	Entity();
	~Entity();

	void Update();

	template <typename T>
	std::shared_ptr<T> AddComponent();

	template <typename T>
	std::shared_ptr<T> GetComponent() const;

	Action<void()> OnUpdate;

protected:
	std::string m_name;
	std::vector<std::shared_ptr<Component>> m_components;
	
private:
	bool IsComponentAdded(std::string type) const;
	template<typename T>
	bool IsComponent() const;

};

template<typename T>
inline std::shared_ptr<T> Entity::AddComponent()
{

	if (IsComponent<T>())
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
inline std::shared_ptr<T> Entity::GetComponent() const
{
	if (IsComponent<T>() == false)
	{
		Logger::Log(LOG_LEVEL::ERROR, "Can't get a non-component class");
		return nullptr;
	}

	std::string type = T::GetType();
	if (IsComponentAdded(type) == false)
	{
		Logger::LogPrintf(LOG_LEVEL::ERROR, "Component of type %s doesnt exist in entity of name %s", T::GetType().c_str(), m_name.c_str());
		return nullptr;
	}

	auto it = std::find_if(m_components.begin(), m_components.end(),
		[&type](std::shared_ptr<Component> currentComponent)
		{ return currentComponent->GetType() == type; });

	return std::static_pointer_cast<T>(*it);

}

template<typename T>
inline bool Entity::IsComponent() const
{
	return std::is_base_of<Component, T>();
}

#endif
