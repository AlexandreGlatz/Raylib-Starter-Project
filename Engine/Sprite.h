#pragma once

#include "Component.h"

#include <filesystem>
#include <raylib.h>

class Sprite : public Component
{
public:
	Sprite(Entity const& entity);
	~Sprite();
	
	void Update();

	void LoadTextureFromFile(std::filesystem::path path);
	void Display();

private:
	Texture2D m_texture;
};

