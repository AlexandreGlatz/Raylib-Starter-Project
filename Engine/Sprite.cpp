#include "pch.h"
#include "Sprite.h"
#include "Entity.h"
#include "Transform2D.h"

Sprite2D::Sprite2D(Entity const& entity) : Component(entity), m_texture()
{
	m_pEntity->CheckDependencies<0, Transform2D>(GetTypeStr());

	m_pTransform = m_pEntity->GetComponent<Transform2D>();

	m_origin = { 0.0f, 0.0f };
}

Sprite2D::~Sprite2D()
{
}

void Sprite2D::Update()
{
	Display();
}

void Sprite2D::LoadTextureFromFile(std::filesystem::path path)
{
	m_texture = LoadTexture(path.string().c_str());
}

void Sprite2D::Display()
{
	Vec2f position = m_pTransform->GetPosition();
	float rotation = m_pTransform->GetRotation();
	Vec2f size = m_pTransform->GetSize();
	Vec2f scale = m_pTransform->GetScale();

	Rectangle sourceRectangle = { 0.0f, 0.0f, float(m_texture.width), float(m_texture.height) };
	Rectangle destRectangle = { position.x, position.y, size.x * scale.x, size.y * scale.y };
	DrawTexturePro(m_texture, sourceRectangle, destRectangle, Vector2(m_origin.x, m_origin.y), rotation, WHITE);
}

void Sprite2D::SetOrigin(Vec2f const& origin)
{
	m_origin = origin;
}


