#include <GameManager.h>
#include <Scene.h>
#include <Sprite.h>
#include <Transform2D.h>

#include <memory>

template<typename T>
using sptr = std::shared_ptr<T>;

int main() {
    GameManager GM;

    GM.Initialize();
    GM.CreateWindow(1280, 720, "Game");
    GM.OpenWindow();
   

    sptr<Scene> pScene = GM.CreateScene();

    sptr<Entity> pEntity1 = pScene->CreateEntity("entity1");
    sptr<Transform2D> pTransform = pScene->AddComponent<Transform2D>(pEntity1);
    pTransform->SetPosition({0.0f, 0.0f});

    sptr<Sprite2D> pSprite = pScene->AddComponent<Sprite2D>(pEntity1);
    pSprite->LoadTextureFromFile("resources/Textures/texture2.png");

    
    GM.SetActiveScene(pScene);

    while (GM.IsWindowOpen())
    {
        GM.Update();
    }


    //
    //cout << "Hello World" << endl;

    //InitWindow(300, 300, "My first Raylib window!");
    //SetTargetFPS(60);

    //while (!WindowShouldClose()) {
    //    BeginDrawing();
    //    ClearBackground(DARKGREEN);
    //    EndDrawing();
    //}

    //CloseWindow();
    //return 0;
}