#ifndef GAME_MANAGER_H_
#define GAME_MANAGER_H_

#include <memory>

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

private:
	std::shared_ptr<Scene> m_pActiveScene;

};


#endif
