#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include "Zone.h"
#include "Kampfsystem.h"
using namespace std;

void ClearScreen();
//Globale Variabeln
Kampfsystem StartKampfSystem;



int main() {

HWND console = GetConsoleWindow();
RECT r;
GetWindowRect(console, &r); //stores the console's current dimensions
MoveWindow(console, r.left, r.top, 350, 600, TRUE); // 800 width, 100 height



	int tmp;
	string Spieler1;
	int Leben;
	Leben = 100;
	int Spieler1X = 15;
	int Spieler1Y = 15;



	string Auswahl;

	string Spielstand_1;
	string Spielstand_2;
	string Spielstand_3;
	Spielstand_1 = "Leer";
	Spielstand_2 = "Leer";
	Spielstand_3 = "Leer";

	int mapWidth, mapHeight;
	mapWidth = 30;
	mapHeight = 30;
	
	



	for (;;) {
		cout << "\n\n\n";

		cout << "(N)ew Game" << endl << "(L)oad Game" << endl << "(E)xit" << endl << endl;
		cin >> Auswahl;
		cout << endl;

		if ((Auswahl == "N") || (Auswahl == "n")) {
			cout << "Ein neues Spiel wird gestartet: ";
	/*		Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);				
	*/		cout << "." << endl;
			

			Sleep(500);
			
			cout << "Spielername:";
			cin >> Spieler1;

			cout << "Hallo " << Spieler1 << " Du hast " << Leben << " Leben." << endl;
			


			//Zone festlegen
			auto warZone = new WarZone(0, 0, 10, 10);
			std::vector<Zone*> zones{
					warZone,
					new ShopZone(25, 25, 5, 5),
					//platz für neue Zonen
					//platz für neue Zonen
					//platz für neue Zonen
					new NoZone(0, 0, mapWidth, mapHeight),
			};



			char Richtung;

			for (;;) {
				// Input
				Richtung = _getch();
				//Spieler bewegen
				if ((Richtung == 'W') || (Richtung == 'w') && Spieler1Y < mapHeight) {

					Spieler1Y += 1;
				}
				else if ((Richtung == 'S') || (Richtung == 's') && Spieler1Y > 0) {

					Spieler1Y -= 1;
				}
				else if ((Richtung == 'A') || (Richtung == 'a') && Spieler1X > 0) {

					Spieler1X -= 1;
				}
				else if ((Richtung == 'D') || (Richtung == 'd') && Spieler1X < mapWidth) {

					Spieler1X += 1;
				}
				else if (Richtung == 'p') {  //Spiel Pausieren

					break;
				}

				// Logik

				//Kampfsystem
				if (warZone->Inside(Spieler1X, Spieler1Y)) {
					cout << "TEST";
					if ((rand() % 100 + 1) < 5) {
						StartKampfSystem.fight();
						// Wenn ja: Zu Kampfsystem wechseln
					}
				}
				
				




				// Render
				ClearScreen();
				cout << Spieler1X << "/" << Spieler1Y << "\n";

				for (int y = mapHeight; y >= 0; --y) {
					for (int x = 0; x <= mapWidth; ++x) {
						//Spieler anzeigen
						if (x == Spieler1X && y == Spieler1Y) {
							cout << "P";
							continue;
						}

						//Zonen anzeigen
						for (auto zone : zones) {
							if (zone->Inside(x, y)) {
								zone->Paint();
								break;
								
							}
						}
					}
					cout << "\n";
				}
			}
		}
		else if ((Auswahl == "L") || (Auswahl == "l")) {
			if (Spielstand_1 == "Leer" && Spielstand_2 == "Leer" && Spielstand_3 == "Leer") {
				cout << "Kein Spielstand vorhanden" << endl;
				Sleep(2000);
				continue;

			}
			else {
				cout << "Spielstand_1: " << Spielstand_1 << endl;
				cout << "Spielstand_2: " << Spielstand_2 << endl;
				cout << "Spielstand_3: " << Spielstand_3 << endl;
			}







		}
		else if ((Auswahl == "E") || (Auswahl == "e")) {
			cout << "Das Spiel wird beendet.\n !Bitte Warten!" << endl;
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << "." << endl;
			return 0;




		}
		else {
			cout << "Eingabe Ungueltig." << endl;
		}


	}

	cin >> tmp;
	return 0;

}


























































void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}