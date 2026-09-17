#include "pch.h"
#include "Sprite.h"

Sprite::Sprite(Entity const& entity) : Component(entity)
{
}

Sprite::~Sprite()
{
}

void Sprite::LoadTextureFromFile(std::filesystem::path path)
{
	m_texture = LoadTexture(path.string().c_str());
}

void Sprite::Display()
{
	//DrawTexturePro(m_texture, )
}


