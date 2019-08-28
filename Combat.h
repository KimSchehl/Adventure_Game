#pragma once
#include<iostream>
#include "ScreenTools.h"
#include "Player.h"
using namespace std;


class Combat
{

public:
	enum Hand{
		Brunnen,
		Stein,
		Schere,
		Papier,
		Nix
	};

	static void Fight(Player& player)
	{
		bool kampfBeendet = false;
		while (!kampfBeendet)
		{
			ScreenTools::ClearScreen();
			int Auswahl;

			cout << "Besiege deinen Gegner in [1]Schere, [2]Stein, [3]Papier" << endl;
			cin >> Auswahl;
			Hand hand = GetHand(Auswahl);
			if (hand == Nix)
				continue;

			Hand cpuHand = CpuHand();

			if (GewinntGegen(hand, cpuHand)) {
				cout << "Du hast gewonnen" << endl;
				Sleep(500);
			}
			else if (GewinntGegen(cpuHand, hand)) {
				cout << "Du hast verloren" << endl;
				player.Live -= 10;
				Sleep(500);
			}
			else{
				cout << "Unentschieden" << endl;
				Sleep(500);
			}

			Sleep(200);
		}
	}

	static Hand GetHand(int auswahl){
		switch (auswahl){
		case 0: return Brunnen;
		case 1: return Schere;
		case 2: return Stein;
		case 3: return Papier;
		}
		return Nix;
	}

	static Hand CpuHand(){
		switch (rand() % 3){
		case 0: return Schere;
		case 1: return Stein;
		case 2: return Papier;
		}
	}

	static bool GewinntGegen(Hand h1, Hand h2){
		if (h1 == Schere && h2 == Papier) return true;
		if (h1 == Stein && h2 == Schere) return true;
		if (h1 == Papier && h2 == Stein) return true;
		if (h1 == Brunnen && h2 == Stein) return true;
		if (h1 == Brunnen && h2 == Schere) return true;
		if (h1 == Papier && h2 == Brunnen) return true;
		return false;
	}


};