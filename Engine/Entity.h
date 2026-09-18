#ifndef ENTITY_H_
#define ENTITY_H_

#include "Component.h"

#include <string>
#include <vector>
#include <memory>
#include <optional>
#include <type_traits>
#include <tuple>

#include <Action.h>
#include <Logger.h>

class Entity
{
public:
	Entity();
	Entity(std::string name);
	~Entity();

	template <typename T>
	std::shared_ptr<T> AddComponent();

	template <typename T>
	std::shared_ptr<T> GetComponent() const;

	template<size_t I = 0,typename ... Args>
	bool CheckDependencies(std::string type);

	void SetName(std::string name);
	std::string GetName() const;

protected:
	static int id;
	std::string m_name;
	std::vector<std::shared_ptr<Component>> m_components;
	
private:
	bool IsComponentAdded(std::string type) const;
	template<typename T>
	bool IsComponent() const;

};

template<size_t I, typename ...Args>
inline bool Entity::CheckDependencies(std::string type)
{
	typedef std::tuple_element<I, std::tuple<Args...>>::type currentType;
	if (GetComponent<currentType>() == nullptr)
	{
		Logger::LogPrintf(LOG_LEVEL::ERROR, "Component of type %s needs a component of type %s", type, currentType::GetTypeStr(currentType::GetType()));
	}

	return false;

	if constexpr(I + 1 != sizeof ... (Args))
		CheckDependencies<I + 1>();
}

template<typename T>
inline std::shared_ptr<T> Entity::AddComponent()
{

	if (IsComponent<T>() == false)
	{
		Logger::Log(LOG_LEVEL::ERROR, "Can't add a non-component to an entity");
		return nullptr;
	}

	std::shared_ptr<T> pNewComponent = std::make_shared<T>(this);

	std::string newComponentType = pNewComponent->GetTypeStr(pNewComponent->GetType());
	//if (IsComponentAdded(newComponentType))
	//{
	//	Logger::LogPrintf(LOG_LEVEL::ERROR, "Component of Type %s already exists in Entity of name %s", newComponentType.c_str(), m_name.c_str());
	//	return nullptr;
	//}

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

	/*std::string type = T::GetTypeStr(T::GetType());
	if (IsComponentAdded(type) == false)
	{
		Logger::LogPrintf(LOG_LEVEL::ERROR, "Component of type %s does'nt exist in entity of name %s", T::GetTypeStr(T::GetType()).c_str(), m_name.c_str());
		return nullptr;
	}*/

	for (int i = 0; i < m_components.size(); ++i)
	{
		std::shared_ptr<T> pComponent = dynamic_pointer_cast<T>(m_components[i]);
		if (pComponent != nullptr)
			return pComponent;
	}

	Logger::LogPrintf(LOG_LEVEL::ERROR, "Component of type %s does'nt exist in entity of name %s", T::GetTypeStr(T::GetType()).c_str(), m_name.c_str());
	return nullptr;

}

template<typename T>
inline bool Entity::IsComponent() const
{
	return std::is_base_of<Component, T>();
}

#endif
