#include <GameManager.h>
#include <Scene.h>
#include <Sprite.h>
#include <Transform2D.h>
#include <UIText.h>

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
    pTransform->SetPosition({ 0.0f, 0.0f });

    sptr<Sprite2D> pSprite = pScene->AddComponent<Sprite2D>(pEntity1);
    Texture texture1 = GM.LoadTextureFromFile("resources/Textures/texture2.png");
    Font font = GM.LoadFontFromFile("resources/fonts/PapernotesSketch.ttf");

    pSprite->SetTexture(texture1);

    sptr<Entity> pEntity2 = pScene->CreateEntity();
    sptr<Transform2D> pTransform1 = pScene->AddComponent<Transform2D>(pEntity2);
    pTransform1->SetPosition({ 50.0f, 50.0f }); 
    sptr<UIText> pText = pScene->AddComponent<UIText>(pEntity2);

    TextAttributes attrib =
    {
        .font = font,
        .color = WHITE,
        .fontSize = 50,
        .spacing = 5
    };

    pText->SetTextAttibutes(attrib);
    pText->SetOrigin({ 0.0f, 0.0f });
    pText->SetText("Test text help plsas");

    GM.SetActiveScene(pScene);

    while (GM.IsWindowOpen())
    {
        GM.Update();
    }

    GM.CloseGameWindow();

    return 0;
}