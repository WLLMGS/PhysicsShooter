#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(const float halfSize, const Vector2f& pos);
	virtual void Update(float elapsedSec) override;
	virtual void Draw(RenderWindow* pWindow);
	
	~Player();
private:
	void HandleControls();
	void HandleRotation();
	const float m_Speed = 300.0f;

	Vector2f m_MouseWorldPos;
};

