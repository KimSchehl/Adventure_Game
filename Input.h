#pragma once

#include <Windows.h>

class Input
{
public:
	static bool IsKeyPressed(int key)
	{
		return GetKeyState(key) < 0;
	}			//Schaut ob die Taste gedr�ckt ist.

	static int GetKeyBlocking()
	{
		return _getch();
	}
};