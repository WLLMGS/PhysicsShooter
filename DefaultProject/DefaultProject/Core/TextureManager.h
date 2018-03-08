#pragma once
#include <map>
#include "SFML/Graphics.hpp"
#include <string>
#include <iostream>
using namespace sf;
using namespace std;
enum TextureType
{
	HERO_0 = 0,
	BULLET_0 = 1,
	TILES = 2,
	FLOORTILE_1 = 3,
	CHARACTER_DIA_DOWN = 4,
	CHARACTER_DIA_UP = 5,
	CHARACTER_NORTH = 6,
	CHARACTER_SIDE = 7,
	CHARACTER_SOUTH = 8,
	FLOORTILE_2 = 9,
	SPACESHIP_1 = 10,
	WALL_BOTTOM = 11,
	WALL_TOP = 12,
	WALL_RIGHT = 13,
	WALL_LEFT = 14,
	WALL_TOP2 = 15,
	WALL_TOP_LEFT = 16,
	WALL_TOP_RIGHT = 17,
	WALL_DOWN_LEFT = 18,
	WALL_DOWN_RIGHT = 19
};

class TextureManager
{
public:
	static TextureManager& GetInstance();
	Texture* GetTexture(const TextureType& type);
	~TextureManager();

private:
	TextureManager();
	
	static void CreateInstance();

	static TextureManager* m_pInstance;

	void AddTexture(const TextureType& type, string path);

	map<TextureType, Texture*> m_pTextures;

};

