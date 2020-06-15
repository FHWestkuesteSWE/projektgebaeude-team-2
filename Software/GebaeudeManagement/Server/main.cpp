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
	char dummy1[1024];
	s.createRoom("Schlafzimmer", fensterName, 0, lampeName, numOfLamp, dummy1);


	string lampeNameKeller[] = { "Mitte" };
	unsigned int numOfLampKeller = sizeof(lampeNameKeller) / sizeof(lampeNameKeller[0]);
	//Raum keller("Keller", NULL, 0, lampeNameKeller, numOfLampKeller);
	//keller.temp_sens.setValue(22.5);
	char dummy2[1024];
	s.createRoom("Keller", NULL, 0, lampeNameKeller, numOfLampKeller, dummy2);

	string fensterNameNew[] = { "FensLinks", "FensMitte" };
	unsigned int numOfFensterNew = sizeof(fensterNameNew) / sizeof(fensterNameNew[0]);
	string lampeNameNew[] = { "LampTable", "LampLeft", "LampRight" , "LampDoor" };
	unsigned int numOfLampNew = sizeof(lampeNameNew) / sizeof(lampeNameNew[0]);
	char dummy3[1024];
	s.createRoom("newRoom", fensterNameNew, numOfFensterNew, lampeNameNew, numOfLampNew, dummy3);
	cout << "DONE create new room" << endl;



	// SIMULATE MESSAGE FROM CLIENT
	/*
	cout << "-------------------------" << endl;
	cout << "From server - main" << endl;
	//char req[] = "GET_ROOMS";
	//char req[] = "GET_SENSORSLIST_Schlafzimmer";
	//char req[] = "GET_SENSORSLIST_notExistedRoom"; // WRONG room name
	//char req[] = "GET_ACTORLIST_Schlafzimmer";
	//char req[] = "GET_ACTORLIST_notExistedRoom"; // WRONG room name
	//char req[] = "GET_SENSORSTATE_TempSensMain_Schlafzimmer";
	//char req[] = "GET_SENSORSTATE_TempSensMain_notExistedRoom"; // Wrong room name
	//char req[] = "GET_SENSORSTATE_WrongSensorName_Schlafzimmer"; // Wrong sensorname name
	//char req[] = "SET_ACTOR_Mitte_Keller_On";
	//char req[] = "CREATE_ROOMS_Keller_fensterNr1,fensterNr2_2_LampMitte,LampHinten_2";
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
		CREATE_ROOM_<Raumbezeichner>_<Fensterbezeichner>_<Anzahl der Fenster>_<Lampenbezeichner>_< Anzahl der Lampe >
	*/


	/*
	
	if (msgArr[0].compare("GET") == 0) {
		cout << "GET Request" << endl;

		// get sensor or actor or room?
		if (msgArr[1].compare("ROOMS") == 0) {
			cout << "get rooms" << endl;
			char temp[1024];
			s.getAllRooms(temp);
			cout << "answer: " << temp << endl;
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
			string roomName = msgArr[2];
			char temp[1024];
			s.getActorFromRoom(roomName, temp);
			cout << "answer: " << temp << endl;
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

	else if (msgArr[0].compare("SET") == 0) {
		// SET_ACTOR_<actorName>_<RaumName>_<Action>
		cout << "SET Request" << endl;
		string actorName = msgArr[2];
		string roomName = msgArr[3];
		string action = msgArr[4];
		char temp[1024];
		s.setActorState(roomName, actorName, action, temp);
		cout << "answer: " << temp << endl;
	}

	else if (msgArr[0].compare("CREATE") == 0) {
		//CREATE_ROOM_<Raumbezeichner>_<Fensterbezeichner>_<Anzahl der Fenster>_<Lampenbezeichner>_< Anzahl der Lampe >
		cout << "CREATE Request" << endl;
		string roomName = msgArr[2];

		// Fensterbezeichner,Lampenbezeichner: "fens1,fens2,fens3"
		int fensterNum = stoi(msgArr[4]);
		int lampeNum = stoi(msgArr[6]);

		// Parse properties
		string* fensterName = new string[fensterNum];
		s.getPropertiesFromMessage(msgArr[3], 4, fensterName);
		string* lampeName = new string[lampeNum];
		s.getPropertiesFromMessage(msgArr[5], 4, lampeName);

		char temp[1024];
		s.createRoom(roomName, fensterName, fensterNum, lampeName, lampeNum, temp);
		cout << "answer: " << temp << endl;
	}

	else {
		// unknown request
		char temp[1024] = "100_SERVER_UnknownRequest";
		cout << "answer: " << temp << endl;

	}
	
	*/


	//UnitTest obj;
	//obj.runUnitTest();
	


	//char port[] = "8000";
	s.start(argv[1]);


	return 0;
}