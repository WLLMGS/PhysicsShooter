#include "WorldManager.h"
#include <iostream>
using namespace std;

WorldManager::~WorldManager()
{
	cout << "world ends\n";
	delete m_pWorld;
}

void WorldManager::Draw(RenderWindow* pWindow)
{
}

void WorldManager::Update(float elapsedSec)
{
}

WorldManager::WorldManager()
{
	cout << "instance made\n";
	m_pWorld = new b2World(b2Vec2(0.0f, 0.0f));
}


