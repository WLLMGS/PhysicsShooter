#pragma once
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"

#include <iostream>
using namespace std;

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
private:
	WorldManager()
	{
		cout << "instance made\n";
		m_pWorld = new b2World(b2Vec2(0.0f, 0.0f));
	}
	b2World* m_pWorld = nullptr;
};

