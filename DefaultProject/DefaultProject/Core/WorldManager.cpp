#include "WorldManager.h"
#include "../Entities/BulletManager.h"
#include "../LevelGenerator.h"

WorldManager::~WorldManager()
{
	cout << "world ends\n";
	delete m_pWorld;

	delete m_pBulletManager;
	m_pBulletManager = nullptr;

	delete m_pLevelGenerator;
	m_pLevelGenerator = nullptr;
}

void WorldManager::Draw(RenderWindow* pWindow)
{
	pWindow->draw(m_Background);
	m_pLevelGenerator->Draw(pWindow);
	m_pBulletManager->Draw(pWindow);

}

void WorldManager::Update(float elapsedSec)
{
	m_pBulletManager->Update(elapsedSec);
}

Vector2f WorldManager::GetPlayerSpawnPos() const
{
	return m_pLevelGenerator->GetPlayerSpawnPos();
}

WorldManager::WorldManager()
{
	cout << "instance made\n";
	m_pWorld = new b2World(b2Vec2(0.0f, 0.0f));

	//initializing background
	//move to level class later
	m_Background.setPosition(0.0f, 0.0f);
	m_Background.setSize(Vector2f(100000.0f, 100000.0f));
	m_Background.setOrigin(m_Background.getSize() / 2.0f);

	Texture* t = TextureManager::GetInstance().GetTexture(FLOORTILE_1);
	IntRect textureRect(0, 0, 25000.0f, 25000.0f);

	m_Background.setTexture(t);
	m_Background.setTextureRect(textureRect);

	m_pBulletManager = new BulletManager();

	m_pLevelGenerator = new LevelGenerator();
}
