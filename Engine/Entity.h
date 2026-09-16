#ifndef ENTITY_H_
#define ENTITY_H_

#include <string>
#include <vector>

class Component;
class Entity
{
public:
	Entity();
	~Entity();

	void Update();

	template <typename T>
	T* AddComponent(T* component);

	template <typename T>
	T* GetComponent(T* component);

private:
	std::string m_name;
	std::vector<Component*> m_components;
};

#endif

