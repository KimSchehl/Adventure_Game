#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include "Player.h"
#include "ScreenTools.h"
#include "Zone.h"
#include "Map.h"
using namespace std;


class Renderer
{
public:
	void Render(Map& map, Player& player)
	{
		ScreenTools::ClearScreen();

		cout << player.Pos.X << "/" << player.Pos.Y << " " << player.Live << "hp\n";
		for (int y = map.height; y >= 0; --y) {
			for (int x = 0; x <= map.width; ++x) {
				//Spieler anzeigen
				if (x == player.Pos.X && y == player.Pos.Y) {
					cout << "P";
					continue;
				}

				//Zonen anzeigen
				for (auto zone : map.Zones) {
					if (zone->Inside(x, y)) {
						zone->Paint();
						break;
					}
				}
			}
			cout << "\n";
		}
	}



};

