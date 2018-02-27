#include "Player.h"
#include "../Core/TextureManager.h"
#include "../Math.h"


Player::Player(const float halfSize, const Vector2f& pos) :
	Entity(halfSize, pos, 1, false)
{
	m_Rectangle.setTexture(TextureManager::GetInstance().GetTexture(HERO_0));

	int id = 2;

	//set unique id for player
	m_pBody->SetUserData((void*)id);
}

void Player::Update(float elapsedSec)
{
	HandleControls();
	HandleRotation();

	auto pos = m_pBody->GetPosition();
	m_Rectangle.setPosition(pos.x, pos.y);
	
}

void Player::Draw(RenderWindow* pWindow)
{
	pWindow->draw(m_Rectangle);
	m_MouseWorldPos = pWindow->mapPixelToCoords(Mouse::getPosition());
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

void Player::HandleRotation()
{
	auto angle = Maths::CalculateAngle(m_Rectangle.getPosition(), m_MouseWorldPos);
	angle = Maths::ToEuler(angle);

	m_Rectangle.setRotation(angle - 90.0f);
}
