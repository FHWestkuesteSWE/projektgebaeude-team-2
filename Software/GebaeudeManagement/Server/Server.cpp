#define _CRT_SECURE_NO_WARNINGS
#include "Server.h"
#include <algorithm>
#include <iostream>
#include "Raum.h"


vector<Raum*> Raum::objList;

Server::Server() {
	;
}

void Server::start(char port[]) {
	
	// Start server using function from BasicServer
	BasicServer::start(port);

}

void Server::processRequest(char req[], char ans[]) {
	//strncpy(ans, req, std::min<int>(1024, strlen(ans) + 1));

	// Schnitstellen zu der andren Klasse

	cout << "-------------------------" << endl;
	cout << "From server - processRequest" << endl;
	cout << "req: " << req << endl;
	cout << "-------------------------" << endl;

	string convReq = (string)req;

	if(convReq.compare("GET_ROOMS") == 0) {
		//char temp[] = "Wohnzimmer,Schlafzimmer,Kueche,Badezimmer";
		char temp[1024];
		this->getAllRooms(temp);
		strncpy(ans, temp, std::min<int>(max_length, strlen(temp) + 1));

	}

	if (convReq.compare("GET_SENSORS_Schlafzimmer") == 0 || convReq.compare("GET_SENSORS_Keller") == 0) {
		string roomName = this->getRoomNameFromMsg(req);
		char temp[1024];
		this->getSensorFromRoom(roomName, temp);
		strncpy(ans, temp, std::min<int>(max_length, strlen(temp) + 1));
	}

	if (convReq.compare("GET_ACTORS_Schlafzimmer") == 0  || convReq.compare("GET_ACTORS_Keller") == 0) {

		string roomName = this->getRoomNameFromMsg(req);

		char temp[1024];
		this->getActorFromRoom(roomName, temp);
		strncpy(ans, temp, std::min<int>(max_length, strlen(temp) + 1));
	}






}

Server::~Server(){
}


/*
	param:
		msg: "GET_SENSORS_<room name>"

	return: <room name> -> string
*/
string Server::getRoomNameFromMsg(char msg[]) {
	
	string convMsg = string(msg);
	string delimiter = "_";
	size_t pos = 0;
	string token;

	while ((pos = convMsg.find(delimiter)) != string::npos) {
		token = convMsg.substr(0, pos);
		cout << token << endl;
		convMsg.erase(0, pos + delimiter.length());
	}
	cout << convMsg << endl;
	return convMsg;
}


void Server::getSensorFromRoom(string roomname, char* sensors) {
	

	cout << "-----------------" << endl;
	cout << "FROM - SERVER getSensorFromRoom" << endl;
	cout << "roomname: " << roomname << endl;
	string tempKontaktSensorList[100] = {}; // Now: represent KontaktSensor's name
	string tempTemperatureSensList;
	char sensorInRoom[1024];
	int lengthOfKontakSensName = 0;
	int numOfFens = 0;

	int location_next_char = 0;
	int location_last_char = 0;
	
	cout << "+++++++++++++" << endl;

	// Get list of Raum's object
	for (int i = 0; i < Raum::getAllObjects().size(); i++) {
		string roomName_i = Raum::getAllObjects()[i]->getName();
		cout << "roomName_i: " << roomName_i << endl;
		if (roomName_i.compare(roomname) == 0) {
			cout << "Room " << roomName_i << "was found on the Raum objList" << endl;
			numOfFens = Raum::getAllObjects()[i]->getNumOfFenster();
			if (numOfFens == 0) {
				// Raum does not have Fenster/KontaktSensor, Get only TempSens's name instead
				tempTemperatureSensList = Raum::getAllObjects()[i]->temp_sens.getName();
				break;
			}
			else {
				// Raum has Fenster/KontaktSensor
				cout << "numOfFens: " << numOfFens << endl;
				cout << Raum::getAllObjects()[i]->fenster[1].getName() << endl;

				// Right now, use Fentername as Kontaktsensor's name
				for (int j = 0; j < numOfFens; j++) {
					tempKontaktSensorList[j] = Raum::getAllObjects()[i]->fenster[j].getName();
					cout << "tempFensList[i]: " << tempKontaktSensorList[i] << endl;
				}

				// Get TempSens's name
				tempTemperatureSensList = Raum::getAllObjects()[i]->temp_sens.getName();
				break;
			}

		}
		cout << endl;
	}
	cout << "+++++++++++++" << endl;


	// Prepare to save the string array in char array
	if (numOfFens == 0) {
		;
	}
	else {
		// Save all sensors in char array
		// Kontaktsensor
		for (int k = 0; k < numOfFens; k++) {
			cout << tempKontaktSensorList[k] << endl;
			cout << tempKontaktSensorList[k].length() << endl << endl;

			for (int m = 0; m < (tempKontaktSensorList[k].length()); m++) {
				char now = (tempKontaktSensorList[k])[m];
				sensorInRoom[m + location_next_char] = now;

			}
			location_next_char += tempKontaktSensorList[k].length();
			sensorInRoom[location_next_char] = ',';
			location_next_char += 1; // after comma
		}

	}


	// Temperature Sensor
	for (int n = 0; n < tempTemperatureSensList.length(); n++) {
		sensorInRoom[n + location_next_char] = tempTemperatureSensList[n];
	}
	location_last_char = location_next_char + tempTemperatureSensList.length();
	sensorInRoom[location_last_char] = '\0';


	cout << "sensorInRoom: " << sensorInRoom << endl;

	strcpy(sensors, sensorInRoom);


	cout << "-----------------" << endl;

}



void Server::getActorFromRoom(string roomname, char* actor) {


	cout << "-----------------" << endl;
	cout << "FROM - SERVER getActorFromRoom" << endl;
	cout << "roomname: " << roomname << endl;
	string tempActorList[100] = {};
	string tempTemperatureSensList;
	char actorInRoom[1024];
	int lengthOfKontakSensName = 0;
	int numOfLamp = 0;

	int location_next_char = 0;
	int location_last_char = 0;

	cout << "+++++++++++++" << endl;
	for (int i = 0; i < Raum::getAllObjects().size(); i++) {
		string roomName_i = Raum::getAllObjects()[i]->getName();
		cout << "roomName_i: " << roomName_i << endl;
		if (roomName_i.compare(roomname) == 0) {

			cout << "Room " << roomName_i << "was found on the Raum objList" << endl;
			numOfLamp = Raum::getAllObjects()[i]->getNumOfLampe();
			cout << "numOfLamp: " << numOfLamp << endl;

			for (int j = 0; j < numOfLamp; j++) {
				tempActorList[j] = Raum::getAllObjects()[i]->lampe[j].getName();
				cout << "tempActorList[i]: " << tempActorList[i] << endl;
			}
			break;
		}
		cout << endl;
	}
	cout << "+++++++++++++" << endl;

	// Save all actor in charr array
	// Kontaktsensor
	for (int k = 0; k < numOfLamp; k++) {
		cout << tempActorList[k] << endl;
		cout << tempActorList[k].length() << endl << endl;

		for (int m = 0; m < (tempActorList[k].length()); m++) {
			char now = (tempActorList[k])[m];
			actorInRoom[m + location_next_char] = now;

		}
		location_next_char += tempActorList[k].length();

		if (k == numOfLamp - 1) {
			actorInRoom[location_next_char] = '\0';
		}
		else {
			actorInRoom[location_next_char] = ',';
			location_next_char += 1; // after comma
		}

	}

	cout << "actorInRoom: " << actorInRoom << endl;


	strcpy(actor, actorInRoom);


	cout << "-----------------" << endl;

}


void Server::getAllRooms(char* rooms) {

	int location_next_char = 0;

	for (int i = 0; i < Raum::getAllObjects().size(); i++) {
		string roomName_i = Raum::getAllObjects()[i]->getName();

		for (int m = 0; m < roomName_i.length(); m++) {
			char now = roomName_i[m];
			rooms[m + location_next_char] = now;
		}

		location_next_char += roomName_i.length();

		if (i == Raum::getAllObjects().size() - 1) {
			rooms[location_next_char] = '\0';
		}
		else {
			rooms[location_next_char] = ',';
			location_next_char += 1; // after comma
		}

	}
}