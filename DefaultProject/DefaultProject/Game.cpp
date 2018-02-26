
#include "Game.h"
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Box2D/Box2D.h"


using namespace std;
using namespace sf;

Game::Game() 
{
	m_pWindow = new RenderWindow(VideoMode(1920, 1080), "Default Project");

	//m_pWindow->setVerticalSyncEnabled(true);

	//create world
	
	//create groundbox
	
	
	//create rectangleshape for groundbox;
	
}

Game::~Game()
{

}

void Game::Run()
{
	Clock clock;
	float deltaTime{};
	
	while (m_pWindow->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		ProcessEvents();
		Update(deltaTime);
		Draw();
	}
}

void Game::ProcessEvents()
{
	Event event{};
	while (m_pWindow->pollEvent(event))
	{
		if (event.type == Event::Closed) m_pWindow->close();
	}
}
void Game::Update(float deltaTime)
{
	//testing contacts
	//for (b2Contact* c = m_pWorld->GetContactList(); c; c->GetNext())
	//{
	//	int uid = int(c->GetFixtureB()->GetBody()->GetUserData());

	//	if(uid == 12)
	//	{
	//		
	//		break;
	//	}
	//	else if (uid == 13)
	//	{
	//		c->GetFixtureB()->GetBody()->SetActive(false);
	//		//apply force to other obj later
	//		break;
	//	}
	//	break;
	//}



	
}

void Game::Draw()
{
	m_pWindow->clear();

	m_pWindow->display();
}