#pragma once

#include "Component.h"

#include <filesystem>
#include <raylib.h>

#include <Vec2.h>

class Transform2D;
class Sprite2D : public Component
{
public:
	Sprite2D(Entity* pEntity);
	~Sprite2D();
	
	void Update() override;

	void SetTexture(Texture const& texture);
	void Display();

	void SetOrigin(Vec2f const& origin);

	static COMPONENT_TYPE GetType();

private:
	Texture2D m_texture;
	std::shared_ptr<Transform2D> m_pTransform;
	Vec2f m_origin;
};

