#ifndef COMPONENT_H_
#define COMPONENT_H_

class Entity;
class Component
{
public:
	Component(Entity const* pEntity);
	~Component();

	Entity const* GetEntity();

private:
	Entity* m_pEntity;
};

#endif
