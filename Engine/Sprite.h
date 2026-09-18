#pragma once

#include "Component.h"

#include <filesystem>
#include <raylib.h>

#include <Vec2.h>

class Transform2D;
class Sprite2D : public Component
{
public:
	Sprite2D(Entity const& entity);
	~Sprite2D();
	
	void Update() override;

	void LoadTextureFromFile(std::filesystem::path path);
	void Display();

	void SetOrigin(Vec2f const& origin);

private:
	Texture2D m_texture;
	std::shared_ptr<Transform2D> m_pTransform;
	Vec2f m_origin;
};

