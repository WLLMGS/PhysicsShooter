#pragma once
#include "SFML/Graphics.hpp"


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

};

