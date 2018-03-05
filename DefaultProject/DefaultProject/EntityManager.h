#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class BulletManager;

class EntityManager
{
public:
	static EntityManager& GetInstance()
	{
		static EntityManager instance;

		return instance;
	}
	~EntityManager();

	void Update(float elapsedSec);
	void Draw(RenderWindow* pWindow);

	public:

	//entity manager
	BulletManager* m_pBulletManager;
private:
	EntityManager();

};

