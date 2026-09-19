#include "pch.h"
#include "AssetLoader.h"

std::unordered_map < std::string, std::shared_ptr<Font>> AssetLoader::m_fonts;
std::unordered_map < std::string, std::shared_ptr<Texture2D>> AssetLoader::m_textures;

void AssetLoader::LoadTextureFromFile(std::filesystem::path path, std::string name)
{
	std::string filePath = path.string();
	Texture2D texture = LoadTexture(filePath.c_str());

	m_textures[name] = std::make_shared<Texture2D>(texture);
}

void AssetLoader::LoadFontFromFile(std::filesystem::path path, std::string name)
{
	std::string filePath = path.string();
	Font font = LoadFont(filePath.c_str());

	m_fonts[name] = std::make_shared<Font>(font);
}

std::shared_ptr<Texture2D> AssetLoader::GetTexture(std::string name)
{
	return m_textures[name];
}

std::shared_ptr<Font> AssetLoader::GetFont(std::string name)
{
	return m_fonts[name];
}

void AssetLoader::UnloadAll()
{
	for (auto const& [key, val] : m_textures)
	{
		UnloadTexture(*val);
	}

	for (auto const& [key, val] : m_fonts)
	{
		UnloadFont(*val);
	}
}
