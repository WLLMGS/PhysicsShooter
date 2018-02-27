#pragma once
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

#include <iostream>
#include "TextureManager.h"
using namespace std;
using namespace sf;

class WorldManager
{
public:
	static WorldManager& GetInstance()
	{
		static WorldManager instance;

		return instance;
	}
	b2World* GetWorld() { return m_pWorld; }
	~WorldManager()
	{
		cout << "world ends\n";
	   delete m_pWorld;
	}

	void Draw(RenderWindow* pWindow);
	
private:
	WorldManager()
	{
		cout << "instance made\n";
		m_pWorld = new b2World(b2Vec2(0.0f, 0.0f));

		//initializing background
		//move to level class later
		m_Background.setPosition(0.0f, 0.0f);
		m_Background.setSize(Vector2f(2000.0f, 2000.0f));
		m_Background.setOrigin(m_Background.getSize() / 2.0f);

		Texture* t = TextureManager::GetInstance().GetTexture(FLOORTILE_1);
		IntRect textureRect(0, 0, 500, 500);

		m_Background.setTexture(t);
		m_Background.setTextureRect(textureRect);

	}
	b2World* m_pWorld = nullptr;

private:
	RectangleShape m_Background;
};

