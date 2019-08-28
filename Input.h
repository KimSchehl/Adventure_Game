#pragma once

#include <Windows.h>

class Input
{
public:
	static bool IsKeyPressed(char key)
	{
		return GetKeyState(key) < 0;
	}

	static int GetKeyBlocking()
	{
		return _getch();
	}
};