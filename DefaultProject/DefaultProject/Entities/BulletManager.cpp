#include "BulletManager.h"



BulletManager::BulletManager()
{
}


BulletManager::~BulletManager()
{
	for(Bullet* b : m_pBullets)
	{
		delete b;
		b = nullptr;
	}
}

void BulletManager::Update(float elapsedSec)
{
	for(size_t i{}; i < m_pBullets.size(); ++i)
	{
		m_pBullets[i]->Update(elapsedSec);
	}
}

void BulletManager::Draw(RenderWindow* pWindow)
{
	for (size_t i{}; i < m_pBullets.size(); ++i)
	{
		m_pBullets[i]->Draw(pWindow);
	}
}

void BulletManager::PushBack(Bullet* b)
{
	m_pBullets.push_back(b);
}
