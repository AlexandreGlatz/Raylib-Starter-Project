#include <GameManager.h>
#include <Scene.h>
#include <Sprite.h>

#include <memory>

template<typename T>
using sptr = std::shared_ptr<T>;

int main() {
    GameManager GM;

    GM.CreateWindow(100, 100, "Game");
    GM.OpenWindow();

    sptr<Scene> pScene = GM.CreateScene();

    sptr<Entity> entity1 = pScene->CreateEntity("entity1");
    pScene->AddComponent<Sprite2D>(entity1);

    


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