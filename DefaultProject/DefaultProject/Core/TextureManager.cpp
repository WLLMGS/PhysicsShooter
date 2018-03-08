
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
	AddTexture(CHARACTER_DIA_DOWN, "Resources/2_diagdown.png");
	AddTexture(CHARACTER_DIA_UP, "Resources/2_diagup.png");
	AddTexture(CHARACTER_NORTH, "Resources/2_north.png");
	AddTexture(CHARACTER_SIDE, "Resources/2_side.png");
	AddTexture(CHARACTER_SOUTH, "Resources/2_south.png");
	AddTexture(FLOORTILE_2, "Resources/FloorTile02.png");
	AddTexture(SPACESHIP_1, "Resources/Space game/spritesheets/ship.png");
	AddTexture(WALL_BOTTOM, "Resources/wall_bottom.png");
	AddTexture(WALL_TOP, "Resources/wall_top.png");
	AddTexture(WALL_RIGHT, "Resources/wall_right.png");
	AddTexture(WALL_LEFT, "Resources/wall_left.png");
	AddTexture(WALL_TOP2, "Resources/wall_top2.png");
	AddTexture(WALL_TOP_LEFT, "Resources/corner_left_up.png");
	AddTexture(WALL_TOP_RIGHT, "Resources/corner_right_up.png");
	AddTexture(WALL_DOWN_LEFT, "Resources/corner_left_down.png");
	AddTexture(WALL_DOWN_RIGHT, "Resources/corner_right_down.png");


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
