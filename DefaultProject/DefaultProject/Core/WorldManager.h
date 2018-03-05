#pragma once
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

class BulletManager;


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
	
	void Draw(RenderWindow* pWindow);
	void Update(float elapsedSec);
	
private:
	WorldManager();
	b2World* m_pWorld = nullptr;
	
};

