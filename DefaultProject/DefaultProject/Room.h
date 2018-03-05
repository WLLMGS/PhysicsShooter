#pragma once
#include "../Core/WorldManager.h"
#include "SFML/Graphics.hpp"
#include <vector>

using namespace sf;
using namespace std;

class Room
{
public:
	Room(const Vector2f& size, const Vector2f& pos);
	~Room();
	void Init();
	void Update(float elapsedSec);
	void Draw(RenderWindow* pWindow);

	bool m_Right = false;
	bool m_Left = false;
	bool m_Up = false;
	bool m_Down = false;

	int indexX, indexY;
private:
	vector<RectangleShape*> m_pTiles;
	RectangleShape* m_pFloor;

	const float m_TileSize = 64.f;
private:
	void GenerateWalls();
	
};

