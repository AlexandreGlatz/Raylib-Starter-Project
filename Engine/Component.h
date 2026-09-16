#ifndef COMPONENT_H_
#define COMPONENT_H_

class Entity;
class Component
{
public:
	Component(Entity const* pEntity);
	~Component();

	Entity const* GetEntity();
	
	virtual void Update() = 0;

private:
	Entity* m_pEntity;
};

#endif
