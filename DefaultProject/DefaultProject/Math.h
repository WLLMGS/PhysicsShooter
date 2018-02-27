
#include <iostream>
#include "Box2D/Box2D.h"

using namespace std;

namespace Maths
{
	float CalculateAngle(const Vector2f& pos1, const Vector2f& pos2)
	{
		auto dPos = pos2 - pos1;

		return atan2(dPos.y, dPos.x);
	}
	float ToEuler(float angle)
	{
		float result = angle * 180.0f / b2_pi;

		return result;
	}
}
