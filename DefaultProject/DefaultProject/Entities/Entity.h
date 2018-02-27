#pragma once
#include "SFML/Graphics.hpp"
#include "../Box2D/Box2D.h"
#include "../Core/WorldManager.h"

using namespace sf;

class Entity
{
public:
	Entity(const float halfSize, const Vector2f& pos, int collisionGroup = 1, bool isStatic = false);
	virtual void Update(float elapsedSec);
	virtual void Draw(RenderWindow* pWindow);
	Vector2f GetPosition() const;
	~Entity();
protected:
	RectangleShape m_Rectangle;
	b2Body* m_pBody;

};

