#pragma once
#include "Bullet.h"

class BulletManager
{
public:
	BulletManager();
	~BulletManager();
	void Update(float elapsedSec);
	void Draw(RenderWindow* pWindow);
	void PushBack(Bullet* b);
private:
	vector<Bullet*> m_pBullets;
};

