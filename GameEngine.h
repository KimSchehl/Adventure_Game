#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <vector>

#include "MainScreen.h"
#include "Renderer.h"
#include "Movement.h"
#include "Zone.h"
#include "Player.h"
#include "Combat.h"

using namespace std;

class GameEngine
{

	MainScreen::EGameSelection _gameMode;
	string _name;
public:


	GameEngine(MainScreen::EGameSelection gameMode, string name)
		:_gameMode(gameMode),
		_name(name) {}

		//andere, kürzere schreibweise
		//_gameMode = gameMode;
		//_name = name;

	void gameLoop() {
		Map gameMap;
		Player player1("p1", 100, Vector2(25, 25));
		Renderer renderer;

		for (;;)
		{
			// Movement
			Movement::move(gameMap, player1);

			// Zones
			//   gameMap.Zones
			//   player1.Pos

			for (auto zone : gameMap.Zones)
			{
				WarZone* warZone = dynamic_cast<WarZone*>(zone);
				if (warZone != nullptr)
				{
					if (warZone->Inside(player1.Pos)) {
							if (rand() % 100 < 3) {
							Combat::Fight(player1);
							ScreenTools::SetWindowSize(350, 600);
						}
					}
				}
			}

			// Render
			renderer.Render(gameMap, player1);

			Sleep(50);
		}
	}

};

