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
	m_pFloor->setTextureRect({ 0,0,(int)size.x, (int)size.y});
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

void Room::Init()
{
	GenerateWalls();
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
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_BOTTOM));
		wall->setTextureRect({ 0,0, (int)size.x, 48});

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
		//left
		auto pos = m_pFloor->getPosition();

		pos.x = pos.x - m_pFloor->getSize().x / 2.0f;
		pos.y = pos.y + m_pFloor->getSize().y / 2.0f;


		auto size = m_pFloor->getSize();
		size.y = 64.0f;
		size.x = size.x / 2.0f - m_TileSize;


		RectangleShape* wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_BOTTOM));
		wall->setTextureRect({ 0,0, (int)size.x, 48 });

		//wall->setOrigin(size / 2.0f);

		m_pTiles.push_back(wall);

		//physx left
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

		//right
		pos = m_pFloor->getPosition();
		pos.y =  pos.y + m_pFloor->getSize().y / 2.0f;
		pos.x = pos.x + m_TileSize * 2.0f;

		wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_BOTTOM));
		wall->setTextureRect({ 0,0, (int)size.x, 48 });

		m_pTiles.push_back(wall);

		//physx right
		b2BodyDef def2;
		def2.type = b2_staticBody;
		def2.position.Set(pos.x + size.x / 2.0f, pos.y + size.y / 2.0f);


		b2Body* body2;
		body2 = WorldManager::GetInstance().GetWorld()->CreateBody(&def2);


		b2PolygonShape shape2;
		shape2.SetAsBox(size.x / 2.0f, size.y / 2.0f);

		b2FixtureDef fDef2;
		fDef2.shape = &shape2;

		body2->CreateFixture(&fDef2);

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
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_TOP2));
		wall->setTextureRect({ 0,0, (int)(size.x), 48});

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

		pos = m_pFloor->getPosition();

		pos.x = pos.x - m_pFloor->getSize().x / 2.0f;
		pos.y = pos.y - m_pFloor->getSize().y / 2.0f + m_TileSize;

		wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		//wall->setOrigin(size / 2.0f);
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_TOP));
		wall->setTextureRect({ 0,0, (int)(size.x ), 48 });

		m_pTiles.push_back(wall);
	}
	else
	{
		auto pos = m_pFloor->getPosition();

		pos.x = pos.x - m_pFloor->getSize().x / 2.0f;
		pos.y = pos.y - m_pFloor->getSize().y / 2.0f;


		auto size = m_pFloor->getSize();
		size.y = 64.0f;
		size.x = size.x / 2.0f - m_TileSize;


		RectangleShape* wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_TOP2));
		wall->setTextureRect({ 0,0, (int)(size.x), 48 });
		m_pTiles.push_back(wall);

		
		//physx left
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


		pos.y += m_TileSize;


		wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_TOP));
		wall->setTextureRect({ 0,0, (int)(size.x), 48 });
		m_pTiles.push_back(wall);

		//wall->setOrigin(size / 2.0f);

		

		

		//right
		pos = m_pFloor->getPosition();
		pos.y = pos.y - m_pFloor->getSize().y / 2.0f;
		pos.x = pos.x + m_TileSize * 2.0f;

		wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_TOP2));
		wall->setTextureRect({ 0,0, (int)(size.x), 48 });

		m_pTiles.push_back(wall);

		//physx right
		b2BodyDef def2;
		def2.type = b2_staticBody;
		def2.position.Set(pos.x + size.x / 2.0f, pos.y + size.y / 2.0f);


		b2Body* body2;
		body2 = WorldManager::GetInstance().GetWorld()->CreateBody(&def2);


		b2PolygonShape shape2;
		shape2.SetAsBox(size.x / 2.0f, size.y / 2.0f);

		b2FixtureDef fDef2;
		fDef2.shape = &shape2;

		body2->CreateFixture(&fDef2);

		pos.y += m_TileSize;

		wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_TOP));
		wall->setTextureRect({ 0,0, (int)(size.x), 48 });

		m_pTiles.push_back(wall);

		
	}

	if(!m_Left)
	{
		auto pos = m_pFloor->getPosition();
		pos.x = pos.x - m_pFloor->getSize().x / 2.0f;
		pos.y = pos.y - m_pFloor->getSize().y / 2.0f + m_TileSize;

		auto size = m_pFloor->getSize();
		size.x = 64.0f;
		size.y -= m_TileSize;
		
		RectangleShape* wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_LEFT));
		wall->setTextureRect({ 0, 0, 48, int(size.y) });
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
		//up
		auto pos = m_pFloor->getPosition();
		pos.x = pos.x - m_pFloor->getSize().x / 2.0f;
		pos.y = pos.y - m_pFloor->getSize().y / 2.0f + m_TileSize;

		auto size = m_pFloor->getSize();
		size.x = m_TileSize;
		size.y = size.y / 2.0f - m_TileSize * 2.f;

		RectangleShape* wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_LEFT));
		wall->setTextureRect({ 0, 0, 48, int(size.y) });

		m_pTiles.push_back(wall);

		//add physics up
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
		
		//down
		pos = m_pFloor->getPosition();
		pos.x = pos.x - m_pFloor->getSize().x / 2.0f;
		pos.y = pos.y + m_TileSize * 2.0f;

		size = m_pFloor->getSize();
		size.x = m_TileSize;
		size.y = size.y / 2.0f - m_TileSize * 2.0f;

		wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_LEFT));
		wall->setTextureRect({ 0, 0, 48, int(size.y) });

		m_pTiles.push_back(wall);

		//add physx down
		b2BodyDef def2;
		def2.type = b2_staticBody;
		def2.position.Set(pos.x + size.x / 2.0f, pos.y + size.y / 2.0f);


		b2Body* body2;
		body2 = WorldManager::GetInstance().GetWorld()->CreateBody(&def2);


		b2PolygonShape shape2;
		shape2.SetAsBox(size.x / 2.0f, size.y / 2.0f);

		b2FixtureDef fDef2;
		fDef2.shape = &shape2;

		body2->CreateFixture(&fDef2);


	}

	if(!m_Right)
	{
		auto pos = m_pFloor->getPosition();
		pos.x = pos.x + m_pFloor->getSize().x / 2.0f;
		pos.y = pos.y - m_pFloor->getSize().y / 2.0f + m_TileSize;

		auto size = m_pFloor->getSize();
		size.x = 64.0f;
		size.y -= 64.0f;

		RectangleShape* wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_RIGHT));
		wall->setTextureRect({ 0,0, 48, (int)size.y });

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
		//up
		auto pos = m_pFloor->getPosition();
		pos.x = pos.x + m_pFloor->getSize().x / 2.0f;
		pos.y = pos.y - m_pFloor->getSize().y / 2.0f + m_TileSize;

		auto size = m_pFloor->getSize();
		size.x = m_TileSize;
		size.y = size.y / 2.0f - m_TileSize * 2.f;

		RectangleShape* wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_RIGHT));
		wall->setTextureRect({ 0,0, 48, (int)size.y });


		m_pTiles.push_back(wall);

		//add physics up
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

		//down
		pos = m_pFloor->getPosition();
		pos.x = pos.x + m_pFloor->getSize().x / 2.0f;
		pos.y = pos.y + m_TileSize * 2.0f;

		size = m_pFloor->getSize();
		size.x = m_TileSize;
		size.y = size.y / 2.0f - m_TileSize;

		wall = new RectangleShape();
		wall->setPosition(pos);
		wall->setSize(size);
		wall->setTexture(TextureManager::GetInstance().GetTexture(WALL_RIGHT));
		wall->setTextureRect({ 0,0, 48, (int)size.y });

		m_pTiles.push_back(wall);

		//add physx down
		b2BodyDef def2;
		def2.type = b2_staticBody;
		def2.position.Set(pos.x + size.x / 2.0f, pos.y + size.y / 2.0f);


		b2Body* body2;
		body2 = WorldManager::GetInstance().GetWorld()->CreateBody(&def2);


		b2PolygonShape shape2;
		shape2.SetAsBox(size.x / 2.0f, size.y / 2.0f);

		b2FixtureDef fDef2;
		fDef2.shape = &shape2;

		body2->CreateFixture(&fDef2);


	}
}
