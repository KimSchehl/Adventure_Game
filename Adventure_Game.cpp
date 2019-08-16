#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;


int main() {
	string Spielername;
	int Leben;
	Leben = 100;
	int tmp;
	string Auswahl;
	string Spielstand_1;
	string Spielstand_2;
	string Spielstand_3;
	Spielstand_1 = "Leer";
	Spielstand_2 = "Leer";
	Spielstand_3 = "Leer";

	for (;;) {
		cout << "\n\n\n";

		cout << "(N)ew Game" << endl << "(L)oad Game" << endl << "(E)xit" << endl << endl;
		cin >> Auswahl;
		cout << endl;

		if ((Auswahl == "N") || (Auswahl == "n")) {
			cout << "Ein neues Spiel wird gestartet: ";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << ".";
			Sleep(1000);
			cout << "." << endl;


			Sleep(1000);

			cout << "Spielername:";
			cin >> Spielername;

			cout << "Hallo " << Spielername << " Du hast " << Leben << " Leben." << endl;







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

