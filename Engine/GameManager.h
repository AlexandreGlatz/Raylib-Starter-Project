#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_

#include <memory>
#include <string>

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

	std::shared_ptr<Window> CreateWindow(int width, int height, std::string name);
	void OpenWindow();
	bool IsWindowOpen();

private:
	std::shared_ptr<Scene> m_pActiveScene;
	std::shared_ptr<Window> m_pWindow;

};


#endif
