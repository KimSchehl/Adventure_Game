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
	enum Hand {
		Win,
		Lose,
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
/*Das ist Bullshit
#define ASCII_1			49	// ASCII wert für Taste 1
#define ASCII_2			50	// ASCII wert für Taste 2
#define ASCII_3			51	// ASCII wert für Taste 3
#define ASCII_4			52	// ASCII wert für Taste 4
#define ASCII_5			53	// ASCII wert für Taste 5
#define ASCII_w			119	// ASCII wert für Taste w
#define ASCII_l			108 // ASCII wert für Taste l
*/
	static Hand PlayerHand() {
	
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
//Testkeys
		if (Input::IsKeyPressed('W'))
			return Win;

		if (Input::IsKeyPressed('L'))
			return Lose;


		return Nix;
	}

	static Hand GetHand(int auswahl){
		switch (auswahl){
		case 0: return Win;
		case 1: return Schere;
		case 2: return Stein;
		case 3: return Papier;
		case 4: return Echse;
		case 5: return Spock;
		case 6: return Lose;
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
		if (h1 == Schere && h2 == Echse) return true;
		if (h1 == Stein && h2 == Schere) return true;
		if (h1 == Papier && h2 == Stein) return true;
			
		if (h1 == Echse && h2 == Spock) return true;
		if (h1 == Echse && h2 == Papier) return true;
		if (h1 == Stein && h2 == Echse) return true;
		if (h1 == Spock && h2 == Schere) return true;
		if (h1 == Spock && h2 == Stein) return true;
		if (h1 == Papier && h2 == Spock) return true;
		
		
		//Test commands
		
		if (h1 == Win && h2 == Schere) return true;
		if (h1 == Win && h2 == Stein) return true;
		if (h1 == Win && h2 == Papier) return true;
		if (h1 == Win && h2 == Echse) return true;
		if (h1 == Win && h2 == Spock) return true;

		if (h1 == Schere && h2 == Lose) return true;
		if (h1 == Stein && h2 == Lose) return true;
		if (h1 == Papier && h2 == Lose) return true;
		if (h1 == Echse && h2 == Lose) return true;
		if (h1 == Spock && h2 == Lose) return true;

		return false;
	}

	static std::string GetHandName(Hand hand) {
		switch (hand) {
			case Win: return "Winner winner chicken dinner";
			case Schere: return "Schere";
			case Stein: return "Stein";
			case Papier: return "Papier";
			case Echse: return "Echse";
			case Spock: return "Spock";
			case Lose: return "R.I.P";
			default:
			case Nix: return "Nix";
		}
	}
};