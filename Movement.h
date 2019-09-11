#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <vector>

#include "Player.h"
#include "Map.h"
#include "Input.h"

using namespace std;


class Movement
{
public:
	static void move(Map& map, Player& player){


		if (Input::IsKeyPressed('W') && player.Pos.Y < map.height) {
	
			player.Pos.Y += 1;
		}
		else if (Input::IsKeyPressed('S') && player.Pos.Y > 0) {
	
			player.Pos.Y -= 1;
		}
		
		if (Input::IsKeyPressed('A') && player.Pos.X > 0) {
	
			player.Pos.X -= 1;
		}
		else if (Input::IsKeyPressed('D') && player.Pos.X < map.width) {
	
			player.Pos.X += 1;
		}


	}


};

