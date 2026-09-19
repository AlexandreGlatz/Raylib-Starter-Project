#ifndef  ASSET_LOADER_H_
#define  ASSET_LOADER_H_

#include <filesystem>
#include <string>
#include <unordered_map>
#include <memory>
#include <raylib.h>

class AssetLoader
{
public:
	static void LoadTextureFromFile(std::filesystem::path path, std::string name = "");
	static void LoadFontFromFile(std::filesystem::path path, std::string name = "");

	static std::shared_ptr<Texture2D> GetTexture(std::string name);
	static std::shared_ptr<Font> GetFont(std::string name);
	static void UnloadAll();

private:
	static std::unordered_map < std::string, std::shared_ptr<Font>> m_fonts;
	static std::unordered_map < std::string, std::shared_ptr<Texture2D>> m_textures;
	static int m_fontId;
	static int m_textureId;
};

#endif 

