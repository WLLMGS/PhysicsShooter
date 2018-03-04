#include "Room.h"
#include "Core/TextureManager.h"

Room::Room(const Vector2f& size, const Vector2f& pos)
{
	//init floor
	//tile = 16
	//real size = 64.f
	//ratio = 64 / 16
	
	m_pFloor = new RectangleShape();
	m_pFloor->setSize(size);
	m_pFloor->setPosition(pos);
	m_pFloor->setOrigin(size / 2.0f);
	m_pFloor->setTexture(TextureManager::GetInstance().GetTexture(FLOORTILE_2));
	m_pFloor->setTextureRect({ 0,0,(int)size.x / 4, (int)size.y / 4 });
	

	GenerateWalls();
	
	
}

Room::~Room()
{
	for(RectangleShape* rs : m_pTiles)
	{
		delete rs;
		rs = nullptr;
	}

	delete m_pFloor;
	m_pFloor = nullptr;
}

void Room::Update(float elapsedSec)
{
}

void Room::Draw(RenderWindow* pWindow)
{
	pWindow->draw(*m_pFloor);

	for(RectangleShape* rs : m_pTiles)
	{
		pWindow->draw(*rs);
	}
}

void Room::GenerateWalls()
{
	
	if(!m_Up)
	{
		// fully closed wall
		auto pos = m_pFloor->getPosition();

		pos.x = pos.x - m_pFloor->getSize().x / 2.0f;
		pos.y = pos.y + m_pFloor->getSize().y / 2.0f;


		auto size = m_pFloor->getSize();
		size.y = 64.0f;

		RectangleShape* wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		//wall->setOrigin(size / 2.0f);

		m_pTiles.push_back(wall);

		//add physics
		b2BodyDef def;
		def.type = b2_staticBody;
		def.position.Set(pos.x + size.x / 2.0f, pos.y + size.y / 2.0f);

		
		b2Body* body;
		body = WorldManager::GetInstance().GetWorld()->CreateBody(&def);


		b2PolygonShape shape;
		shape.SetAsBox(size.x / 2.0f, size.y / 2.0f);
		
		b2FixtureDef fDef;
		fDef.shape = &shape;

		body->CreateFixture(&fDef);


	}
	else
	{
		//gap in the middle for doorway
	}

	if(!m_Down)
	{
		// fully closed wall
		auto pos = m_pFloor->getPosition();

		pos.x = pos.x - m_pFloor->getSize().x / 2.0f;
		pos.y = pos.y - m_pFloor->getSize().y / 2.0f;


		auto size = m_pFloor->getSize();
		size.y = 64.0f;

		RectangleShape* wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		//wall->setOrigin(size / 2.0f);

		m_pTiles.push_back(wall);


		//add physics
		b2BodyDef def;
		def.type = b2_staticBody;
		def.position.Set(pos.x + size.x / 2.0f, pos.y + size.y / 2.0f);


		b2Body* body;
		body = WorldManager::GetInstance().GetWorld()->CreateBody(&def);


		b2PolygonShape shape;
		shape.SetAsBox(size.x / 2.0f, size.y / 2.0f);

		b2FixtureDef fDef;
		fDef.shape = &shape;

		body->CreateFixture(&fDef);
	}
	else
	{
		
	}

	if(!m_Left)
	{
		auto pos = m_pFloor->getPosition();
		pos.x = pos.x - m_pFloor->getSize().x / 2.0f;
		pos.y = pos.y - m_pFloor->getSize().y / 2.0f;

		auto size = m_pFloor->getSize();
		size.x = 64.0f;
		size.y += 0;
		
		RectangleShape* wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);

		m_pTiles.push_back(wall);

		//add physics
		b2BodyDef def;
		def.type = b2_staticBody;
		def.position.Set(pos.x + size.x / 2.0f, pos.y + size.y / 2.0f);


		b2Body* body;
		body = WorldManager::GetInstance().GetWorld()->CreateBody(&def);


		b2PolygonShape shape;
		shape.SetAsBox(size.x / 2.0f, size.y / 2.0f);

		b2FixtureDef fDef;
		fDef.shape = &shape;

		body->CreateFixture(&fDef);
	}
	else
	{
		
	}

	if(!m_Right)
	{
		auto pos = m_pFloor->getPosition();
		pos.x = pos.x + m_pFloor->getSize().x / 2.0f;
		pos.y = pos.y - m_pFloor->getSize().y / 2.0f;

		auto size = m_pFloor->getSize();
		size.x = 64.0f;
		size.y += 64.0f;

		RectangleShape* wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);

		m_pTiles.push_back(wall);

		//add physics
		b2BodyDef def;
		def.type = b2_staticBody;
		def.position.Set(pos.x + size.x / 2.0f, pos.y + size.y / 2.0f);


		b2Body* body;
		body = WorldManager::GetInstance().GetWorld()->CreateBody(&def);


		b2PolygonShape shape;
		shape.SetAsBox(size.x / 2.0f, size.y / 2.0f);

		b2FixtureDef fDef;
		fDef.shape = &shape;

		body->CreateFixture(&fDef);
	}
	else
	{
		
	}
}
