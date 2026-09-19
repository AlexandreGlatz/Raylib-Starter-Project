#include <GameManager.h>
#include <Scene.h>
#include <Sprite.h>
#include <Transform2D.h>
#include <UIText.h>
#include <AssetLoader.h>
#include <UIButton.h>
#include <Logger.h>

#include <memory>

template<typename T>
using sptr = std::shared_ptr<T>;

void OnButtonHover()
{
    Logger::Log(LOG_LEVEL::LOG, "ButtonHover");
}

void OnButtonClick()
{
    Logger::Log(LOG_LEVEL::LOG, "ButtonClick");
}
int main() {
    GameManager GM;

    GM.Initialize();
    GM.CreateWindow(1280, 720, "Game");
    GM.OpenWindow();
    AssetLoader::LoadTextureFromFile("resources/Textures/texture2.png", "texture1");
    AssetLoader::LoadFontFromFile("resources/fonts/PapernotesSketch.ttf", "font1");
    AssetLoader::LoadTextureFromFile("resources/Textures/texture.png", "texture2");

    sptr<Scene> pScene = GM.CreateScene();

    sptr<Entity> pEntity1 = pScene->CreateEntity("entity1");
    sptr<Transform2D> pTransform = pScene->AddComponent<Transform2D>(pEntity1);
    pTransform->SetPosition({ 0.0f, 0.0f });

    sptr<Sprite2D> pSprite = pScene->AddComponent<Sprite2D>(pEntity1);
    sptr<Texture2D> texture1 = AssetLoader::GetTexture("texture1");
    sptr<Font> font = AssetLoader::GetFont("font1");

    pSprite->SetTexture(texture1.get());

    sptr<Entity> pEntity2 = pScene->CreateEntity();
    sptr<Transform2D> pTransform1 = pScene->AddComponent<Transform2D>(pEntity2);
    pTransform1->SetPosition({ 50.0f, 50.0f }); 
    sptr<UIText> pText = pScene->AddComponent<UIText>(pEntity2);

    sptr<Entity> pButton = pScene->CreateEntity();
    sptr<Transform2D> pButtonTransform = pScene->AddComponent<Transform2D>(pButton);
    sptr<Sprite2D> pButtonSprite = pScene->AddComponent<Sprite2D>(pButton);
    sptr<UIButton> pButtonButton = pScene->AddComponent<UIButton>(pButton);

    pButtonTransform->SetPosition({ 100.0f, 50.0f });

    sptr<Texture2D> texture2 = AssetLoader::GetTexture("texture2");
    pButtonSprite->SetTexture(texture2.get());

    pButtonButton->OnHover.Subscribe(OnButtonHover);
    pButtonButton->OnClick.Subscribe(OnButtonClick);

    TextAttributes attrib =
    {
        .pFont = font.get(),
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

    AssetLoader::UnloadAll();

    GM.CloseGameWindow();

    return 0;
}