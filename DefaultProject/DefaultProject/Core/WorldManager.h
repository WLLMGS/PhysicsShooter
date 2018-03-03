#pragma once
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

#include <iostream>
#include "TextureManager.h"

class BulletManager;
class LevelGenerator;

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

	~WorldManager();

	b2World* GetWorld() { return m_pWorld; }
	BulletManager* pBulletManager() { return m_pBulletManager; }

	void Draw(RenderWindow* pWindow);
	void Update(float elapsedSec);
	Vector2f GetPlayerSpawnPos() const;

private:
	WorldManager();
	;
	b2World* m_pWorld = nullptr;
	BulletManager* m_pBulletManager = nullptr;
	LevelGenerator* m_pLevelGenerator = nullptr;

private:
	RectangleShape m_Background;
};

