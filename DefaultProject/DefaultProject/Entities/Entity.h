#pragma once
#include "SFML/Graphics.hpp"
#include "../Box2D/Box2D.h"
#include "../WorldManager.h"

using namespace sf;

class Entity
{
public:
	Entity(const float halfSize, const Vector2f& pos, int collisionGroup = 1, bool isStatic = false);
	virtual void Update(float elapsedSec);
	void Draw(RenderWindow* pWindow);
	~Entity();
protected:
	RectangleShape m_Rectangle;
	b2Body* m_pBody;

};

