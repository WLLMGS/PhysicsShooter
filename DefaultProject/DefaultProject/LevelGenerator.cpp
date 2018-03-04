#include "LevelGenerator.h"
#include <cstdlib>
#include <iostream>

#include "Room.h"

LevelGenerator::LevelGenerator()
{
	InitMap();
	GenerateSpecialRooms();
	ConnectRooms();
	MakeRooms();
	
	for(int y{}; y < m_Size; ++y)
	{
		for (int x{}; x < m_Size; ++x)
		{
		std::cout << m_Map[x][y] << " ";
		}
		std::cout << "\n";
	}

}


LevelGenerator::~LevelGenerator()
{
	for(Room* room : m_pRooms)
	{
		delete room;
		room = nullptr;
	}
}

void LevelGenerator::Draw(RenderWindow* pWindow)
{
	for(Room* room : m_pRooms)
	{
		room->Draw(pWindow);
	}
}

Vector2f LevelGenerator::GetPlayerSpawnPos() const
{
	return m_PlayerSpawnPos;
}

void LevelGenerator::InitMap()
{
	for(int x{}; x < m_Size; ++x)
	{
		for(int y{}; y < m_Size; ++y)
		{
			m_Map[x][y] = 0;
		}
	}
}

void LevelGenerator::GenerateSpecialRooms()
{
	//room q1
	int q1X = rand() % (m_Size / 2);
	int q1y = rand() % (m_Size / 2);

	m_Map[q1X][q1y] = 1;

	std::cout << q1X << " " << q1y << endl;

	m_Rooms.push_back(make_pair(q1X, q1y));

	//room q2
	int q2X = rand() % (m_Size / 2) + (m_Size / 2);
	int q2y = rand() % (m_Size / 2);

	m_Map[q2X][q2y] = 2;

	m_Rooms.push_back(make_pair(q2X, q2y));

	//room q3
	int q3x = rand() % (m_Size / 2);
	int q3y = rand() % (m_Size / 2) + (m_Size / 2);

	m_Map[q3x][q3y] = 3;

	m_Rooms.push_back(make_pair(q3x, q3y));


	//room q4
	int q4X = rand() % (m_Size / 2) + (m_Size / 2);
	int q4y = rand() % (m_Size / 2) + (m_Size / 2);

	m_Map[q4X][q4y] = 4;

	m_Rooms.push_back(make_pair(q4X, q4y));


	//generate connection point

	m_ConnectionX = rand() % m_Size;
	m_ConnectionY = rand() % m_Size;

	m_Map[m_ConnectionX][m_ConnectionY] = 7;

	m_PlayerSpawnPos.x = m_ConnectionX * m_GridSize * m_TileSize + (m_GridSize * m_TileSize / 2.0f);
	m_PlayerSpawnPos.y = m_ConnectionY * m_GridSize * m_TileSize + (m_GridSize * m_TileSize / 2.0f);

}

void LevelGenerator::ConnectRooms()
{
	for(pair<int, int>& p : m_Rooms)
	{
		int x = p.first;
		int y = p.second;

		if(x > m_ConnectionX)
		{
			int dx = x - m_ConnectionX;
			
			for(int i{}; i < dx; ++i)
			{
				m_Map[x - i][y] = 9;
			}
		}
		else
		{
			int dx = m_ConnectionX - x;
		
			for (int i{}; i < dx; ++i)
			{
				m_Map[x + i][y] = 9;
			}
		}

		if(y > m_ConnectionY)
		{
			int dy = y - m_ConnectionY;

			for(int i{}; i < dy; ++i)
			{
				m_Map[m_ConnectionX][y - i] = 9;
			}
		}
		else
		{
			int dy = m_ConnectionY - y;

			for(int i{}; i < dy; ++i)
			{
				m_Map[m_ConnectionX][y + i] = 9;
			}
		}
	}
}

void LevelGenerator::MakeRooms()
{
	Vector2f gridPos;
	Vector2f size;
	Vector2f pos;

	for(int x{}; x < m_Size; ++x)
	{
		for(int y{}; y < m_Size; ++y)
		{
			if(m_Map[x][y] != 0)
			{
				//make room
				//determine where on grid
				gridPos.x = x * m_GridSize * m_TileSize;
				gridPos.y = y * m_GridSize * m_TileSize;

				pos.x = gridPos.x + (m_GridSize * m_TileSize / 2.0f);
				pos.y = gridPos.y + (m_GridSize * m_TileSize / 2.0f);

				//determine size
				size.x =float( rand() % (m_MaxSize - m_MinSize) + m_MinSize) * m_TileSize;
				size.y = float(rand() % (m_MaxSize - m_MinSize) + m_MinSize) * m_TileSize;

				//new room
				Room* room = new Room(size, pos);

				m_pRooms.push_back(room);
			}
		}
	}
}
