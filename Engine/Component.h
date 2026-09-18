#ifndef COMPONENT_H_
#define COMPONENT_H_

#include<memory>
#include<optional>
#include<Action.h>
#include<string>


enum class COMPONENT_TYPE : char
{
	NONE,
	SPRITE_2D,
	BOX_COLLIDER,
	TRANSFORM_2D,

	COMPONENT_COUNT
};

class Entity;
class Component
{
public:
	Component(Entity const& entity);
	~Component();

	std::shared_ptr<Entity const> GetEntity() const;
	
	virtual void Update();
	static std::string GetTypeStr();
	static COMPONENT_TYPE GetType();
	static void SetType(COMPONENT_TYPE type);

protected:

	void DisplayDependencyError(std::string type);

protected:
	std::shared_ptr<Entity> m_pEntity;
	static COMPONENT_TYPE m_type;
};

#endif
