#pragma once
#include "Entity.h"

class Bullet : public Entity
{
public:
	Bullet(const float size, const Vector2f& pos, const float angle);
	~Bullet();
	virtual void Update(float elapsedSec) override;
	virtual void Draw(RenderWindow* pWindow) override;

private:
	const float m_Speed = 500.0f;
	const float m_Angle;
private:
	void HandleMovement();
};

