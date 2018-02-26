
#include "Game.h"
#include "WorldManager.h"
//#include <vld.h>

using namespace std;
using namespace sf;

Game::Game() 
{
	m_pWindow = new RenderWindow(VideoMode(1920, 1080), "Default Project");

	//m_pWindow->setVerticalSyncEnabled(true);

	//testing entity

	m_pEntity = new Entity(32.0, { 100.0f,100.0f }, 1, true);
	m_pPlayer = new Player(16.0f, { 250.0f, 250.0f });
}

Game::~Game()
{
	delete m_pWindow;
	m_pWindow = nullptr;
	delete m_pEntity;
	m_pEntity = nullptr;
	delete m_pPlayer;
	m_pPlayer = nullptr;
	
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
	
	WorldManager::GetInstance().GetWorld()->Step(deltaTime, 1, 1);
	
	m_pPlayer->Update(deltaTime);
	m_pEntity->Update(deltaTime);
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

	//WorldManager::GetInstance().GetWorld()->Step(deltaTime, 1, 1);
}

void Game::Draw()
{
	m_pWindow->clear();
	m_pEntity->Draw(m_pWindow);
	m_pPlayer->Draw(m_pWindow);
	m_pWindow->display();
}