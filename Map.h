#pragma once

#include "Zone.h"

class Map
{
public:
	int width = 30;
	int height = 30;
	std::vector<Zone*> Zones;

	Map()
	{
		Zones = {
			new ShopZone(25, 25, 5, 5),
			new WarZone(0, 0, 10, 10),
			//platz für neue Zonen
			new NoZone(0, 0, width, height)
		};
	}
};