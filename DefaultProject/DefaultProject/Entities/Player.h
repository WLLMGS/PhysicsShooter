#pragma once
#include "Entity.h"
#include "../Core/Animator.h"

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
	void HandleAttacks();
	const float m_Speed = 300.0f;
private:
	Vector2f m_MouseWorldPos;
	float m_Angle = 0.0f;
	const float m_ShotCooldown = 0.25f;
	float m_ShotTimer = 0.0f;
	Animator* m_Animator = nullptr;
};

