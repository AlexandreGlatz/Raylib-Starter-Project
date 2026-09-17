#ifndef COMPONENT_H_
#define COMPONENT_H_

#include<memory>
#include<optional>
#include<Action.h>
#include<string>
#include<tuple>

class Entity;
class Component
{
public:
	Component(Entity const& entity);
	~Component();

	std::shared_ptr<Entity const> GetEntity() const;
	
	virtual void Update();
	static std::string GetType();

protected:
	template<typename ... Args>
	bool CheckDependencies();
	void DisplayDependencyError(std::string type);

protected:
	std::shared_ptr<Entity> m_pEntity;
	static std::string m_type;
};

template<typename ...Args>
inline bool Component::CheckDependencies()
{
	std::tuple<Args...> types;
	std::apply([](auto&& ... args)
		{
			((
				if (m_pEntity.GetComponent<args>() == nullptr)
				{
					DisplayDependencyError(args::GetType());
				}
					), ...); }, types)
}

#endif
