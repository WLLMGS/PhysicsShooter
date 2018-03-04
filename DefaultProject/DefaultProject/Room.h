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
	void Update(float elapsedSec);
	void Draw(RenderWindow* pWindow);

private:
	vector<RectangleShape*> m_pTiles;
	RectangleShape* m_pFloor;

	bool m_Right = false;
	bool m_Left = false;
	bool m_Up = false;
	bool m_Down = false;
private:
	void GenerateWalls();
};

