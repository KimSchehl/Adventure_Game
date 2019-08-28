#pragma once
#include<iostream>
#include "ScreenTools.h"
#include "Player.h"
#include "Input.h"
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
		CConsoleLogger another_console;
		another_console.Create("This is the first console");
		another_console.printf("WOW !!! COOLL !!! another console ???");
		ScreenTools::ClearScreen();
		cout << "Besiege deinen Gegner in [1]Schere, [2]Stein, [3]Papier" << endl;

		bool kampfBeendet = false;
		while (!kampfBeendet)
		{
			Hand hand = PlayerHand();
			if (hand == Nix)
				continue; // Auf Spieler Input warten

			cout << "\n";

			Hand cpuHand = CpuHand();
			cout << GetHandName(hand) << " vs " << GetHandName(cpuHand) << endl;

			Sleep(500);

			if (GewinntGegen(hand, cpuHand)) {
				cout << "  Du hast gewonnen" << endl;
				Sleep(500);
				break;
			}
			else if (GewinntGegen(cpuHand, hand)) {
				cout << "  Du hast verloren" << endl;
				player.Live -= 10;
				Sleep(1500);
				break;
			}
			else{
				cout << "  Unentschieden" << endl;
				Sleep(500);
			}

			Sleep(200);
		}
	}

	static Hand PlayerHand() {
		if (Input::IsKeyPressed('1'))
			return Schere;
		
		if (Input::IsKeyPressed('2'))
			return Stein;
		
		if (Input::IsKeyPressed('3'))
			return Papier;
		
		return Nix;
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

	static std::string GetHandName(Hand hand) {
		switch (hand) {
		case Brunnen: return "Brunnen";
		case Stein: return "Stein";
		case Schere: return "Schere";
		case Papier: return "Papier";
		case Nix: return "Nix";
		}
	}
};