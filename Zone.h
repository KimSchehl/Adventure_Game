#pragma once
#include <iostream>
using namespace std;

class Zone
{
	int _ZoneX, _ZoneY;
	int _ZoneWidth, _ZoneHeight;

public:

	Zone(int ZoneX, int ZoneY, int ZoneWidth, int ZoneHeight)
		:_ZoneX(ZoneX)
		,_ZoneY(ZoneY)
		,_ZoneWidth(ZoneWidth)
		,_ZoneHeight(ZoneHeight)
	{}

	virtual void Paint() = 0;

	bool Inside(int x, int y){	
		if (
			(x >= _ZoneX) && (x <= _ZoneX + _ZoneWidth) &&
			(y >= _ZoneY) && (y <= _ZoneY + _ZoneHeight)
			) {
			return true;
		}
		else {
		
			return false;
			
		}
	}

};












class NoZone : public Zone
{
public:
	NoZone(int x, int y, int width, int height)
		:Zone(x, y, width, height)
	{}

	void Paint() {
		cout << ' ';
	}
};


class WarZone : public Zone
{
public: 
	WarZone(int x, int y, int width, int height)
		:Zone(x,y,width,height)
	{}

	void Paint(){
		cout << 'w';
	}
};




class ShopZone : public Zone
{
public:
	ShopZone(int x, int y, int width, int height)
		:Zone(x, y, width, height){}

	void Paint(){
		cout << 's';
	}
};
