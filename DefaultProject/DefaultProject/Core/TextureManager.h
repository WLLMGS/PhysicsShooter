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
	FLOORTILE_1 = 3

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

