#include "Bullet.h"
#include "../Core/TextureManager.h"

Bullet::Bullet(const float size, const Vector2f& pos, const float angle) :
Entity(size, pos, -1),
m_Angle(angle)
{
	//texture
	m_Rectangle.setTexture(TextureManager::GetInstance().GetTexture(BULLET_0));


	//set rotation
	m_Rectangle.setRotation(angle * 180.f / b2_pi + 90.0f);
	int id = 3;

	m_pBody->SetUserData((void*)id);


}


Bullet::~Bullet()
{
}

void Bullet::Update(float elapsedSec)
{
	HandleMovement();

	//set rect pos to body pos
	auto pos = m_pBody->GetPosition();
	m_Rectangle.setPosition(pos.x, pos.y);
}

void Bullet::Draw(RenderWindow* pWindow)
{
	pWindow->draw(m_Rectangle);
}

void Bullet::HandleMovement()
{
	b2Vec2 velocity;

	velocity.x = cos(m_Angle) * m_Speed;
	velocity.y = sin(m_Angle) * m_Speed;

	m_pBody->SetLinearVelocity(velocity);
}
