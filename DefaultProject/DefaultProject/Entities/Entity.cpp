#include "Entity.h"


Entity::Entity(const float halfSize, const Vector2f& pos, int collisionGroup, bool isStatic)
{
	
	auto world = WorldManager::GetInstance().GetWorld();

	b2BodyDef bodyDef;
	if (!isStatic) bodyDef.type = b2_dynamicBody;
	else bodyDef.type = b2_staticBody;
	//bodyDef.type = (!isStatic) ? b2_dynamicBody : b2_staticBody;
	bodyDef.position.Set(pos.x, pos.y);
	bodyDef.allowSleep = false;
	bodyDef.active = true;
	bodyDef.linearDamping = 1.0f;
	bodyDef.bullet = true;
	
	int id = 1;
	m_pBody = world->CreateBody(&bodyDef);
	m_pBody->SetUserData((void*)id);
	
	b2CircleShape circle;
	circle.m_p.Set(0, 0);
	circle.m_radius = halfSize;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circle;
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 1.0f;
	fixtureDef.restitution = 1.0f;

	fixtureDef.filter.groupIndex = collisionGroup;

	m_pBody->CreateFixture(&fixtureDef);

	//create rectangleShape;
	m_Rectangle.setPosition(pos);
	m_Rectangle.setSize(Vector2f(halfSize * 2.0f, halfSize * 2.0f));
	m_Rectangle.setOrigin(m_Rectangle.getSize() / 2.0f);

}

void Entity::Update(float elapsedSec)
{
	auto pos = m_pBody->GetPosition();

	m_Rectangle.setPosition(pos.x, pos.y);
}

void Entity::Draw(RenderWindow* pWindow)
{
	pWindow->draw(m_Rectangle);
}

Vector2f Entity::GetPosition() const
{
	return m_Rectangle.getPosition();
}

Entity::~Entity()
{
}
