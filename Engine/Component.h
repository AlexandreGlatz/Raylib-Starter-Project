#ifndef COMPONENT_H_
#define COMPONENT_H_

#include<memory>
#include<optional>
#include<Action.h>
#include<string>

class Entity;
class Component
{
public:
	Component() = default;
	Component(Entity const& entity);
	~Component();

	std::shared_ptr<Entity const> GetEntity() const;
	
	virtual void Update();
	static std::string GetType();

protected:

	void DisplayDependencyError(std::string type);

protected:
	std::shared_ptr<Entity> m_pEntity;
	static std::string m_type;
};

#endif
