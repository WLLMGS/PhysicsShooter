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
}
