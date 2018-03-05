#include "EntityManager.h"
#include "../Entities/BulletManager.h"


EntityManager::EntityManager()
{
	m_pBulletManager = new BulletManager();
}


EntityManager::~EntityManager()
{
	delete m_pBulletManager;
	m_pBulletManager = nullptr;
}

void EntityManager::Update(float elapsedSec)
{
	//update bullet manager
	m_pBulletManager->Update(elapsedSec);
}

void EntityManager::Draw(RenderWindow* pWindow)
{
	m_pBulletManager->Draw(pWindow);
}
