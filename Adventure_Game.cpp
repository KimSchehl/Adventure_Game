#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include "Zone.h"
#include "Combat.h"
#include "MainScreen.h"
#include "ScreenTools.h"
#include "GameEngine.h"
using namespace std;



//Globale Variabeln
Combat StartKampfSystem;



int main() {

	ScreenTools::SetWindowSize(350, 600);
	ScreenTools::HideCursor();
	ScreenTools::ClearScreen();

	

	for (;;) {
		cout << "\n\n\n";

		MainScreen m;
		m.show();
		
		

		if (m.getSelection() == MainScreen::eNewGame)
		{
			GameEngine e(m.getSelection(), m.getName());
			e.gameLoop();
			continue;
			
		}

		if (m.getSelection() == MainScreen::eExit)
		{
			break;

		}

	
	}
}