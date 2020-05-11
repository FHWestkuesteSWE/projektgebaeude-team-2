#include "Server.h"
#include "Raum.h"
#include "UnitTest.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

	UnitTest obj;
	obj.runUnitTest();
	

	/* ---------------- SCHLAFZIMMER ---------------- */
	// Define Raum und Fenster
	
	string fensterName[] = { "links", "mitte", "rechts" };
	unsigned int numOfFenster = sizeof(fensterName) / sizeof(fensterName[0]);
	string lampeName[] = { "LampTable", "LampLeft", "LampRight" , "LampDoor" };
	unsigned int numOfLamp = sizeof(lampeName) / sizeof(lampeName[0]);

	Raum schlafzimmer("Schlafzimmer", fensterName, numOfFenster, lampeName, numOfLamp);
	cout << "RAUM: " << schlafzimmer.getName() << endl;

	for (int i = 0; i < numOfFenster; i++) {
		// Get Fenster name
		cout << "Fenster" << "[" << i << "]: " << (schlafzimmer.fenster[i].getName()) << endl;
	}

	cout << endl;

	for (int i = 0; i < numOfLamp; i++) {
		// Get Lampe name
		cout << "Lampe" << "[" << i << "]: " << (schlafzimmer.lampe[i].getName()) << endl;
	}

	cout << endl;

	cout << "number_of_fenster: " << schlafzimmer.getNumOfFenster() << endl;
	cout << "number_of_lampe: " << schlafzimmer.getNumOfLampe() << endl;

	cout << endl << endl;
	


	/* ---------------- KELLER ---------------- */
	
	string lampeNameKeller[] = { "Mitte" };
	unsigned int numOfLampKeller = sizeof(lampeNameKeller) / sizeof(lampeNameKeller[0]);
	Raum keller("Keller", NULL, 0, lampeNameKeller, numOfLampKeller);
	cout << "RAUM: " << keller.getName() << endl;
	cout << "number_of_fenster: " << keller.getNumOfFenster() << endl;
	cout << "number_of_lampe: " << keller.getNumOfLampe() << endl;
	

	Server s;
	s.start(argv[1]);


	return 0;
}