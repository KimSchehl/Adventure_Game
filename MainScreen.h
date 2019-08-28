#pragma once

#include <iostream>
#include <string>
#include <Windows.h>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <vector>
#include "Input.h"
using namespace std;

class MainScreen
{
public:
	MainScreen() {};
	
	enum EGameSelection {
		eUnknown,
		eNewGame,
		eLoadGame,
		eExit
	};

	EGameSelection getSelection()
	{
		return _selection;
	}

	string getName()
	{
		return _name;
	}

	bool setSelection(int key)
	{
		if(key == 'N' || key == 'n' )
		{
			_selection = eNewGame;
			return true;
		}

		if (key == 'L' || key == 'l')
		{
			_selection = eLoadGame;
			return true;
		}

		if (key == 'E' || key == 'e')
		{
			_selection = eExit;
			return true;
		}
		return false;
	}

	void getInput()
	{
		string Spieler1;
		cout << "(N)ew Game" << endl << "(L)oad Game" << endl << "(E)xit" << endl << endl;
		int Auswahl = Input::GetKeyBlocking();

		if (setSelection(Auswahl) == false)
		{
			cout << "Eingabe Ungueltig." << endl;
		}
	}

	void show()
	{
	
		getInput();

		if (_selection == eNewGame) {
			cout << "Ein neues Spiel wird gestartet: ";
			/*		Sleep(1000);
					cout << ".";
					Sleep(1000);
					cout << ".";
					Sleep(1000);
			*/		cout << "." << endl;


			Sleep(500);

			string Spieler;

			cout << "Spielername:";
			cin >> Spieler;

			cout << "Hallo " << Spieler <<  endl;

			_name = Spieler;
			







		}
		else if (_selection == eExit) {
			cout << "Das Spiel wird beendet.\n !Bitte Warten!" << endl;
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << "." << endl;
			return;



		}
		





	}


	private:

		string _name;
		EGameSelection _selection = eUnknown;
};

