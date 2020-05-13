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
	keller.temp_sens.setValue(22.5);

	
	/*
	// SIMULATE MESSAGE FROM CLIENT
	cout << "-------------------------" << endl;
	cout << "From server - main" << endl;
	//char req[] = "GET_ROOMS";
	//char req[] = "GET_SENSORSLIST_Schlafzimmer";
	char req[] = "GET_SENSORSTATE_xxx_Keller";
	//char req[] = "SET_ACTOR_Mitte_Keller_On";
	
	char ans[1024];
	cout << "req: " << req << endl;

	string convReq = (string)req;

	// first "decode" the message, and look for the first word, is it GET or SET

	stringstream string_stream_convReq(convReq);
	string segment;
	string msgArr[10];
	int i = 0;

	while (getline(string_stream_convReq, segment, '_')){

		msgArr[i] = segment;	
		cout << "msgArr[i]: " << msgArr[i] << endl;
		i++;
	}
	*/





	//Befehl:
	//Sensor: GET
	//Aktor: SET
	//------------
	//Sensor: <Art des Sensors>_<raum>
	//Aktor : <Art des Aktors>_<raum>_<Action>

	/*
	Options for incomming message from client:
		GET_ROOMS
		GET_SENSORLIST_<RaumName>
		GET_ACTORLIST_<RaumName>

		GET_SENSORSTATE_<sensorName>_<RaumName>
		SET_<actorName>_<RaumName>_<Action>
	*/



	/*
	if (msgArr[0].compare("GET") == 0) {
		cout << "GET Request" << endl;

		// get sensor or actor or room?
		if (msgArr[1].compare("ROOMS") == 0) {
			cout << "get rooms" << endl;
		}
		if (msgArr[1].compare("SENSORSLIST") == 0) {
			cout << "get sensor list" << endl;
			string roomName = msgArr[2];
			char temp[1024];
			s.getSensorFromRoom(roomName, temp);
			cout << "answer: " << temp << endl;

		}
		if (msgArr[1].compare("ACTORLIST") == 0) {
			cout << "get actor list" << endl;
		}
		if (msgArr[1].compare("SENSORSTATE") == 0) {
			cout << "get sensor state" << endl;
			string sensorName = msgArr[2];
			string roomName = msgArr[3];
			char temp[1024];
			s.getSensorState(roomName, sensorName, temp);
			cout << "answer: " << temp << endl;
		}
		
	}
	else {
		// SET_ACTOR_<actorName>_<RaumName>_<Action>
		cout << "SET Request" << endl;
		string actorName = msgArr[2];
		string roomName = msgArr[3];
		string action = msgArr[4];
		char temp[1024];
		s.setActorState(roomName, actorName, action, temp);
		cout << "answer: " << temp << endl;
	}
	*/



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