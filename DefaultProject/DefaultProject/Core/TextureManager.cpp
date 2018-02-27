
#include "TextureManager.h"

TextureManager* TextureManager::m_pInstance = nullptr;


TextureManager& TextureManager::GetInstance()
{
	static TextureManager instance;
	
	return instance;
}

Texture* TextureManager::GetTexture(const TextureType& type)
{
	return m_pTextures[type];
}

TextureManager::TextureManager()
{
	AddTexture(HERO_0, "Resources/Hero_MachineGun.png");
	AddTexture(BULLET_0, "Resources/Bullet0.png");
	AddTexture(TILES, "Resources/Level.png");
	AddTexture(FLOORTILE_1, "Resources/FloorTile01.png");
}


TextureManager::~TextureManager()
{
	//delete all textures
	delete m_pInstance;
	m_pInstance = nullptr;
	for(pair<TextureType, Texture*> p : m_pTextures)
	{
		delete p.second;
		p.second = nullptr;
	}
}

void TextureManager::CreateInstance()
{
	m_pInstance = new TextureManager();
}

void TextureManager::AddTexture(const TextureType& type, string path)
{
	Texture* texture = new Texture();
	if (!texture->loadFromFile(path)) cout << "could not instantiate texture: " << path << endl;

	texture->setRepeated(true);

	m_pTextures[type] = texture;
}
