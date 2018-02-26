#pragma once
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"
#include "Entities/Entity.h"
#include "Entities/Player.h"

using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void Run();
private:
	//functions
	void ProcessEvents();
	void Update(float deltaTime);
	void Draw();

	
	//members
	RenderWindow* m_pWindow = nullptr;

	//physics world
	b2World* m_pWorld;

	Entity* m_pEntity = nullptr;
	Player* m_pPlayer = nullptr;


};

