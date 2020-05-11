#include "Server.h"
#include "Raum.h"
#include "UnitTest.h"

#include <iostream>
#include <string.h>

using namespace std;


int main(int argc, char* argv[]) {

	Server s;

	// RAUM
	string fensterName[] = { "links", "mitte", "rechts" };
	unsigned int numOfFenster = sizeof(fensterName) / sizeof(fensterName[0]);
	string lampeName[] = { "LampTable", "LampLeft", "LampRight" , "LampDoor" };
	unsigned int numOfLamp = sizeof(lampeName) / sizeof(lampeName[0]);
	Raum schlafzimmer("Schlafzimmer", fensterName, numOfFenster, lampeName, numOfLamp);

	string lampeNameKeller[] = { "Mitte" };
	unsigned int numOfLampKeller = sizeof(lampeNameKeller) / sizeof(lampeNameKeller[0]);
	Raum keller("Keller", NULL, 0, lampeNameKeller, numOfLampKeller);



	// SIMULATE MESSAGE FROM CLIENT
	cout << "-------------------------" << endl;
	cout << "From server - main" << endl;
	//char req[] = "GET_SENSORS_Schlafzimmer";
	char req[] = "GET_ACTORS_Schlafzimmer";
	char ans[1024];
	cout << "req: " << req << endl;

	string convReq = (string)req;
	
	if (convReq.compare("GET_ROOMS") == 0) {

		cout << "1. if" << endl;
		char temp[] = "Wohnzimmer,Schlafzimmer,Kueche,Badezimmer";
		strncpy_s(ans, temp, sizeof(temp));

	}

	if (convReq.compare("GET_SENSORS_Schlafzimmer") == 0) {

		cout << "2. if" << endl;

		string roomName = s.getRoomNameFromMsg(req);

		char temp[1024];
		s.getSensorFromRoom(roomName, temp);

		strncpy_s(ans, temp, sizeof(temp));
	}

	if (convReq.compare("GET_ACTORS_Schlafzimmer") == 0) {

		cout << "3. if" << endl;

		string roomName = s.getRoomNameFromMsg(req);

		char temp[1024];
		s.getActorFromRoom(roomName, temp);

		strncpy_s(ans, temp, sizeof(temp));
	}

	cout << "ans: " << ans << endl;

	cout << "-------------------------" << endl;












	//UnitTest obj;
	//obj.runUnitTest();
	

	/* ---------------- SCHLAFZIMMER ---------------- */
	// Define Raum und Fenster
	/*
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
	*/


	/* ---------------- KELLER ---------------- */
	/*
	string lampeNameKeller[] = { "Mitte" };
	unsigned int numOfLampKeller = sizeof(lampeNameKeller) / sizeof(lampeNameKeller[0]);
	Raum keller("Keller", NULL, 0, lampeNameKeller, numOfLampKeller);
	cout << "RAUM: " << keller.getName() << endl;
	cout << "number_of_fenster: " << keller.getNumOfFenster() << endl;
	cout << "number_of_lampe: " << keller.getNumOfLampe() << endl;
	*/


	s.start(argv[1]);


	return 0;
}