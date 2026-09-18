#include "pch.h"
#include "GameManager.h"
#include "BoxCollider.h"
#include "Transform2D.h"
#include "Sprite.h"
#include "Scene.h"

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::Initialize()
{
	Sprite2D::SetType	(COMPONENT_TYPE::SPRITE_2D);
	Component::SetType	(COMPONENT_TYPE::NONE);
	Transform2D::SetType(COMPONENT_TYPE::TRANSFORM_2D);
	BoxCollider::SetType(COMPONENT_TYPE::BOX_COLLIDER);
}

void GameManager::Update()
{
	m_pActiveScene->Update();
}

std::shared_ptr<Scene> GameManager::CreateScene()
{
	return std::make_shared<Scene>();
}

void GameManager::SetActiveScene(std::shared_ptr<Scene> pScene)
{
	if (m_pActiveScene != nullptr)
		m_pActiveScene->Unload();
	m_pActiveScene = pScene;
	m_pActiveScene->Load();
}
