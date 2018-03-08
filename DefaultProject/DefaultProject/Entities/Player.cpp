#include "Player.h"
#include "../Core/TextureManager.h"
#include "../Math.h"
#include "../Core/WorldManager.h"
#include "../Entities/BulletManager.h"
#include "../EntityManager.h"

Player::Player(const float halfSize, const Vector2f& pos) :
	Entity(halfSize, pos, -1, false)
{
	m_Rectangle.setTexture(TextureManager::GetInstance().GetTexture(CHARACTER_DIA_DOWN));
	m_Rectangle.setTextureRect({ 0,0,16,24 });
	int id = 2;

	//set unique id for player
	m_pBody->SetUserData((void*)id);

	//init animator
	m_Animator = new Animator(6, 3);

}

void Player::Update(float elapsedSec)
{
	HandleControls();
	HandleRotation();
	HandleAttacks();

	//count down shot timer
	m_ShotTimer -= elapsedSec;

	auto pos = m_pBody->GetPosition();
	m_Rectangle.setPosition(pos.x, pos.y);

	//update animations
	m_Animator->Update(elapsedSec);
	
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

	//dash
	if(Mouse::isButtonPressed(Mouse::Right))
	{
		//do dash
		auto direction = m_MouseWorldPos - m_Rectangle.getPosition();
		b2Vec2 normDir;
		normDir.x = direction.x;
		normDir.y = direction.y;
		normDir.Normalize();

		normDir *= m_Speed * 20.f;

		m_pBody->SetLinearVelocity(normDir);
		
	}

}

void Player::HandleRotation()
{
	m_Angle = Maths::CalculateAngle(m_Rectangle.getPosition(), m_MouseWorldPos);
	m_Angle = Maths::ToEuler(m_Angle);


	/*m_Rectangle.setRotation(m_Angle + 90.0f);

	switch (m_Animator->CurrentFrame())
	{
	case 0:
		m_Rectangle.setTextureRect({ 0,0,16,24 });
		break;
	case 1:
		m_Rectangle.setTextureRect({ 0,24,16,24 });
		break;
	}*/

	if (m_Angle > -22.5f && m_Angle < 22.5f)
	{
		m_Rectangle.setScale(1, 1);
		m_Rectangle.setTexture(TextureManager::GetInstance().GetTexture(CHARACTER_SIDE));
		m_Rectangle.setTextureRect({ 19 * m_Animator->CurrentFrame(), 0, 19, 24 });
	}
	else if (m_Angle < -22.5f && m_Angle > -67.5f)
	{
		m_Rectangle.setScale(1, 1);
		m_Rectangle.setTexture(TextureManager::GetInstance().GetTexture(CHARACTER_DIA_UP));
		m_Rectangle.setTextureRect({ 19 * m_Animator->CurrentFrame(), 0, 19, 24 });
	}
	else if (m_Angle < -67.5f && m_Angle > -112.5f)
	{
		m_Rectangle.setScale(1, 1);
		m_Rectangle.setTexture(TextureManager::GetInstance().GetTexture(CHARACTER_NORTH));
		m_Rectangle.setTextureRect({ 19 * m_Animator->CurrentFrame(), 0, 19, 24 });
	}
	else if(m_Angle < -112.5f && m_Angle > -157.5f)
	{
		m_Rectangle.setScale(-1, 1);
		m_Rectangle.setTexture(TextureManager::GetInstance().GetTexture(CHARACTER_DIA_UP));
		m_Rectangle.setTextureRect({ 19 * m_Animator->CurrentFrame(), 0, 19, 24 });
	}
	else if(m_Angle < -157.5f || m_Angle > 157.5f)
	{
		m_Rectangle.setScale(-1, 1);
		m_Rectangle.setTexture(TextureManager::GetInstance().GetTexture(CHARACTER_SIDE));
		m_Rectangle.setTextureRect({ 19 * m_Animator->CurrentFrame(), 0, 19, 24 });
	}
	else if (m_Angle > 112.5f && m_Angle < 157.5f)
	{
		m_Rectangle.setScale(-1, 1);
		m_Rectangle.setTexture(TextureManager::GetInstance().GetTexture(CHARACTER_DIA_DOWN));
		m_Rectangle.setTextureRect({ 19 * m_Animator->CurrentFrame(), 0, 19, 24 });
	}
	else if(m_Angle > 67.5f && m_Angle < 112.5f)
	{
		m_Rectangle.setScale(1, 1);
		m_Rectangle.setTexture(TextureManager::GetInstance().GetTexture(CHARACTER_SOUTH));
		m_Rectangle.setTextureRect({ 19 * m_Animator->CurrentFrame(), 0, 19, 24 });
	}
	else if(m_Angle > 22.5f && m_Angle < 67.5f)
	{
		m_Rectangle.setScale(1, 1);
		m_Rectangle.setTexture(TextureManager::GetInstance().GetTexture(CHARACTER_DIA_DOWN));
		m_Rectangle.setTextureRect({ 19 * m_Animator->CurrentFrame(), 0, 19, 24 });
	}
}

void Player::HandleAttacks()
{
	if(m_ShotTimer < 0.0f)
	{
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			m_ShotTimer = m_ShotCooldown;
			Bullet* b = new Bullet(24.0f, m_Rectangle.getPosition(), Maths::ToRadians(m_Angle));

			//WorldManager::GetInstance().pBulletManager()->PushBack(b);
			EntityManager::GetInstance().m_pBulletManager->PushBack(b);
		}
	}

}
