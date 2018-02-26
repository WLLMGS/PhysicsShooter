#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(const float halfSize, const Vector2f& pos);
	virtual void Update(float elapsedSec) override;
	~Player();
private:
	void HandleControls();

	const float m_Speed = 200.0f;
};

