#pragma once
#include<iostream>
#include "ntverp.h"
#include "ScreenTools.h"
#include "Player.h"
#include "Input.h"
using namespace std;


class Combat
{

public:
	enum Hand{
		Brunnen,
		Schere,
		Stein,
		Papier,
		Echse,
		Spock,
		Nix
	};

	static void Fight(Player& player)
	{	
		ScreenTools::SetWindowSize(800, 300);
		ScreenTools::ClearScreen();

		cout << "Besiege deinen Gegner in [1]Schere, [2]Stein, [3]Papier, [4]Echse, [5]Spock." << endl;

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
				Sleep(2500);
				break;
			}
			else if (GewinntGegen(cpuHand, hand)) {
				cout << "  Du hast verloren" << endl;
				player.Live -= 10;
				Sleep(2500);
				break;
			}
			else{
				cout << "  Unentschieden" << endl;
				cout << "\n\n" "Kaempft erneut!" << endl;
			}

			Sleep(200);
		}
	}

	static Hand PlayerHand() {
		if (Input::IsKeyPressed('0'))
			return Brunnen;

		if (Input::IsKeyPressed('1'))
			return Schere;
		
		if (Input::IsKeyPressed('2'))
			return Stein;
		
		if (Input::IsKeyPressed('3'))
			return Papier;

		if (Input::IsKeyPressed('4'))
			return Echse;

		if (Input::IsKeyPressed('5'))
			return Spock;

		return Nix;
	}

	static Hand GetHand(int auswahl){
		switch (auswahl){
		case 0: return Brunnen;
		case 1: return Schere;
		case 2: return Stein;
		case 3: return Papier;
		case 4: return Echse;
		case 5: return Spock;
		}
		return Nix;
	}

	static Hand CpuHand(){
		switch (rand() % 5){
		case 0: return Schere;
		case 1: return Stein;
		case 2: return Papier;
		case 3: return Echse;
		case 4: return Spock;
		}
	}

	static bool GewinntGegen(Hand h1, Hand h2){
		if (h1 == Schere && h2 == Papier) return true;
		if (h1 == Stein && h2 == Schere) return true;
		if (h1 == Papier && h2 == Stein) return true;
			if (h1 == Brunnen && h2 == Stein) return true;
			if (h1 == Brunnen && h2 == Schere) return true;
			if (h1 == Papier && h2 == Brunnen) return true;
		if (h1 == Echse && h2 == Spock) return true;
		if (h1 == Echse && h2 == Papier) return true;
		if (h1 == Stein && h2 == Echse) return true;
		if (h1 == Spock && h2 == Schere) return true;
		if (h1 == Spock && h2 == Stein) return true;
		if (h1 == Papier && h2 == Spock) return true;

		return false;
	}

	static std::string GetHandName(Hand hand) {
		switch (hand) {
			case Brunnen: return "Brunnen";
			case Schere: return "Schere";
			case Stein: return "Stein";
			case Papier: return "Papier";
			case Echse: return "Echse";
			case Spock: return "Spock";
			default:
			case Nix: return "Nix";
		}
	}
};