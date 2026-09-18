#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_

#include <memory>
#include <string>
#include <raylib.h>
#include <filesystem>

class Window;
class Scene;
class Component;
class GameManager
{
public:
	GameManager();
	~GameManager();

	void Initialize();

	void Update();

	std::shared_ptr<Scene> CreateScene();
	void SetActiveScene(std::shared_ptr<Scene> pScene);

	void SetClearColor(Color clearColor);
	
	std::shared_ptr<Window> CreateWindow(int width, int height, std::string name);

	void OpenWindow();
	bool IsWindowOpen();
	void SetTargetFPS(int target);
	void CloseGameWindow();

	Texture LoadTextureFromFile(std::filesystem::path path);
	Font LoadFontFromFile(std::filesystem::path path);

private:
	std::shared_ptr<Scene> m_pActiveScene;
	std::shared_ptr<Window> m_pWindow;
	Color m_clearColor;

};


#endif
