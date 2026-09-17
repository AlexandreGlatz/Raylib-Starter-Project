#ifndef COMPONENT_H_
#define COMPONENT_H_

#include<memory>
#include<optional>
#include<Action.h>

class Entity;
class Component
{
public:
	Component(Entity const& entity);
	~Component();

	std::shared_ptr<Entity const> GetEntity() const;
	
	void Update();

	Action<void()> OnUpdate;

protected:
	std::shared_ptr<Entity> m_pEntity;
};

#endif
