#pragma once

struct Vector2
{
	int X = 15;
	int Y = 15;

	Vector2()
	{}

	Vector2(int X, int Y)
		: X(X)
		, Y(Y)
	{
		//this->x = x;
		//this->y = y;
	}
};