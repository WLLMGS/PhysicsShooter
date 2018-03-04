
#include "Game.h"
#include "Core/WorldManager.h"
#include "LevelGenerator.h"

//#include <vld.h>

using namespace std;
using namespace sf;

Game::Game() 
{
	m_pWindow = new RenderWindow(VideoMode(1920, 1080), "Agent Of Destruction");

	//m_pWindow->setVerticalSyncEnabled(true);

	//testing entity

	m_pEntity = new Entity(32.0f, { 100.0f,100.0f }, 1, true);
	m_pPlayer = new Player(16.0f, { 250.0f, 250.0f });

	//init view
	m_View.setCenter(m_pPlayer->GetPosition());
	m_View.setSize(1080.0f, 720.0f);

	//set playerpos
	
	m_pLevelGenerator = new LevelGenerator();

	m_pPlayer->SetPosition(m_pLevelGenerator->GetPlayerSpawnPos());
}

Game::~Game()
{
	delete m_pWindow;
	m_pWindow = nullptr;
	delete m_pEntity;
	m_pEntity = nullptr;
	delete m_pPlayer;
	m_pPlayer = nullptr;
	delete m_pLevelGenerator;
	m_pLevelGenerator = nullptr;
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
	m_View.setCenter(m_pPlayer->GetPosition());
	m_pPlayer->Update(deltaTime);
	m_pEntity->Update(deltaTime);
	WorldManager::GetInstance().GetWorld()->Step(deltaTime, 6, 2);

	
	WorldManager::GetInstance().Update(deltaTime);
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
	m_pWindow->setView(m_View);
	
	m_pLevelGenerator->Draw(m_pWindow);
	WorldManager::GetInstance().Draw(m_pWindow);

	m_pEntity->Draw(m_pWindow);
	m_pPlayer->Draw(m_pWindow);
	m_pWindow->display();
}