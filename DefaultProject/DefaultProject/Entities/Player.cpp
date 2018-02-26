#include "Player.h"


Player::Player(const float halfSize, const Vector2f& pos) :
	Entity(halfSize, pos, 1, false)
{
}

void Player::Update(float elapsedSec)
{
	HandleControls();

	auto pos = m_pBody->GetPosition();
	m_Rectangle.setPosition(pos.x, pos.y);
	
}

Player::~Player()
{
}

void Player::HandleControls()
{
	b2Vec2 velocity;

	if(Keyboard::isKeyPressed(Keyboard::Z))
	{
		//cout << "updating\n";
		velocity.y = -m_Speed;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		velocity.y = m_Speed;
	}
	else
	{
		velocity.y = 0.0f;
	}

	if (Keyboard::isKeyPressed(Keyboard::Q))
	{
		velocity.x = -m_Speed;
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		velocity.x = m_Speed;
	}
	else
	{
		velocity.x = 0.0f;
	}

	m_pBody->SetLinearVelocity(velocity);


}
