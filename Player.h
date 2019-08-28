#pragma once
#include <iostream>
#include "Vector2.h"
using namespace std;


class Player
{
public:
	Vector2 Pos;
	string Name;
	int Live;

	Player(string Name, int Live, Vector2 Pos)
		: Name(Name)
		, Live(Live)
		, Pos(Pos)
	{
	}



};