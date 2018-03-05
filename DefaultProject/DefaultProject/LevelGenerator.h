#pragma once
#include <vector>

using namespace std;
#include "SFML/Graphics.hpp"

using namespace sf;

class Room;

enum Direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class LevelGenerator
{
public:
	LevelGenerator();
	~LevelGenerator();
	void Draw(RenderWindow* pWindow);
	Vector2f GetPlayerSpawnPos() const;
private:
	static const int m_Size = 11;
	int m_Map[m_Size][m_Size];

	std::vector<std::pair<int, int>> m_Rooms;

	int m_ConnectionX;
	int m_ConnectionY;


	vector <Room*> m_pRooms;

	const int m_MinSize = 15;
	const int m_MaxSize = 20;
	const float m_GridSize = 24.0f;
	const float m_TileSize = 64.0f;

	Vector2f m_PlayerSpawnPos;


	RectangleShape m_Background;
private:
	void InitMap();
	void GenerateSpecialRooms();
	void ConnectRooms();
	void MakeRooms();
	void DetermineHallways();
	vector<bool> CheckNeighbors(int x, int y);
};

