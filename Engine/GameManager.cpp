#include "pch.h"
#include "GameManager.h"
#include "BoxCollider.h"
#include "Transform2D.h"
#include "Sprite.h"
#include "Scene.h"
#include "Window.h"

GameManager::GameManager()
{
	m_clearColor = RED;
}

GameManager::~GameManager()
{
}

void GameManager::Initialize()
{
}

void GameManager::Update()
{
	BeginDrawing();
	ClearBackground(m_clearColor);
	m_pActiveScene->Update();
	EndDrawing();
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

void GameManager::SetClearColor(Color clearColor)
{
	m_clearColor = clearColor;
}

std::shared_ptr<Window> GameManager::CreateWindow(int width, int height, std::string name)
{
	m_pWindow = std::make_shared<Window>(width, height, name);
	return m_pWindow;
}

void GameManager::OpenWindow()
{
	m_pWindow->Open();
}

bool GameManager::IsWindowOpen()
{
	return m_pWindow->IsOpen();
}

void GameManager::SetTargetFPS(int target)
{
	m_pWindow->SetTargetFPS(target);
}

void GameManager::CloseGameWindow()
{
	m_pWindow->Close();
}


