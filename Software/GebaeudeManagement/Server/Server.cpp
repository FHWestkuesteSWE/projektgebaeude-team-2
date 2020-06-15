#define _CRT_SECURE_NO_WARNINGS
#include "Server.h"
#include <algorithm>
#include <iostream>
#include "ErrorCode.h"


vector<Raum*> Raum::objList;

Server::Server() {
	;
}

Server::~Server() {
	;
}


void Server::start(char port[]) {
	// Start server using function from BasicServer
	BasicServer::start(port);
	//SSLServer::start(port);
}


void Server::processRequest(char req[], char ans[]) {

	cout << "-------------------------" << endl;
	cout << "From server - processRequest" << endl;
	cout << "req: " << req << endl;
	cout << "-------------------------" << endl;

	string convReq = (string)req;
	stringstream string_stream_convReq(convReq);
	string segment;
	string msgArr[10];
	int i = 0;

	// Parse incomming message into string array
	while (getline(string_stream_convReq, segment, '_')) {
		msgArr[i] = segment;
		cout << "msgArr[i]: " << msgArr[i] << endl;
		i++;
	}


	/*
	Options for incomming message from client:
		GET_ROOMS
		GET_SENSORLIST_<RaumName>
		GET_ACTORLIST_<RaumName>

		GET_SENSORSTATE_<sensorName>_<RaumName>
		SET_<actorName>_<RaumName>_<Action>
		CREATE_ROOM_<Raumbezeichner>_<Fensterbezeichner>_<Anzahl der Fenster>_<Lampenbezeichner>_< Anzahl der Lampe >
	*/

	if (msgArr[0].compare("GET") == 0) {

		// get rooms
		if (msgArr[1].compare("ROOMS") == 0) {
			char temp[1024];
			this->getAllRooms(temp);
			strncpy(ans, temp, std::min<int>(max_length, strlen(temp) + 1));
		}

		// get list of sensor
		else if (msgArr[1].compare("SENSORLIST") == 0) {
			string roomName = msgArr[2];
			char temp[1024];
			this->getSensorFromRoom(roomName, temp);
			strncpy(ans, temp, std::min<int>(max_length, strlen(temp) + 1));
		}

		// get list of actor
		else if (msgArr[1].compare("ACTORLIST") == 0) {
			string roomName = msgArr[2];
			char temp[1024];
			this->getActorFromRoom(roomName, temp);
			strncpy(ans, temp, std::min<int>(max_length, strlen(temp) + 1));
		}

		// get sensor state
		else if (msgArr[1].compare("SENSORSTATE") == 0) {
			cout << "get sensor state" << endl;
			string sensorName = msgArr[2];
			string roomName = msgArr[3];
			char temp[1024];
			this->getSensorState(roomName, sensorName, temp);
			strncpy(ans, temp, std::min<int>(max_length, strlen(temp) + 1));
		}

		else {
			cout << "Unknown GET Request" << endl;
			char temp[1024] = "1_SERVER_Unknown Request";
			strncpy(ans, temp, std::min<int>(max_length, strlen(temp) + 1));
		}

	}

	else if (msgArr[0].compare("SET") == 0) {
		//SET_<actorName>_<RaumName>_<Action>
		cout << "SET Request" << endl;
		string actorName = msgArr[1];
		string roomName = msgArr[2];
		string action = msgArr[3];
		char temp[1024];
		this->setActorState(roomName, actorName, action, temp);
		strncpy(ans, temp, std::min<int>(max_length, strlen(temp) + 1));
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
		this->getPropertiesFromMessage(msgArr[3], 4, fensterName);
		string* lampeName = new string[lampeNum];
		this->getPropertiesFromMessage(msgArr[5], 4, lampeName);

		char temp[1024];

		this->createRoom(roomName, fensterName, fensterNum, lampeName, lampeNum, temp);
		strncpy(ans, temp, std::min<int>(max_length, strlen(temp) + 1));
	}

	else {
		// unknown request
		cout << "Unknown Request" << endl;
		char temp[1024] = "100_SERVER_UnknownRequest";
		strncpy(ans, temp, std::min<int>(max_length, strlen(temp) + 1));

	}

}



void Server::getSensorFromRoom(string roomname, char* sensors) {

	string tempKontaktSensorList[100] = {}; // Now: represent KontaktSensor's name
	string tempTemperatureSensList;
	char sensorInRoom[1024];
	int lengthOfKontakSensName = 0;
	int numOfFens = 0;

	int location_next_char = 0;
	int location_last_char = 0;

	string str_ans[3];

	bool roomFound = false;

	try {

		// Get list of Raum's object
		for (int i = 0; i < Raum::getAllObjects().size(); i++) {
			string roomName_i = Raum::getAllObjects()[i]->getName();
			cout << "roomName_i: " << roomName_i << endl;
			if (roomName_i.compare(roomname) == 0) {
				cout << "Room " << roomName_i << "was found on the Raum objList" << endl;
				roomFound = true;
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

		if (roomFound == false) {
			throw ROOM_NOT_FOUND;
		}
		else {
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

			str_ans[0] = "0";
			str_ans[1] = sensorInRoom;
			str_ans[2] = roomname;

			this->prepareAnswer(str_ans, 3, sensorInRoom);

			strcpy(sensors, sensorInRoom);
			cout << "-----------------" << endl;
		}


	}
	catch (const char* errorCode) {
		cout << errorCode << endl;
		str_ans[0] = errorCode;
		str_ans[1] = "GET_SENSORLIST";
		str_ans[2] = roomname;

		this->prepareAnswer(str_ans, 3, sensorInRoom);
		strcpy(sensors, sensorInRoom);
	}
	catch (std::exception& e) {
		cerr << e.what() << endl;
		str_ans[0] = SERVER_ERROR; // Server error, exception occure
		str_ans[1] = e.what();
		str_ans[2] = roomname;

		this->prepareAnswer(str_ans, 3, sensorInRoom);
		strcpy(sensors, sensorInRoom);
	}


}



void Server::getActorFromRoom(string roomname, char* actor) {


	string tempActorList[100] = {};
	string tempTemperatureSensList;
	char actorInRoom[1024];
	int lengthOfKontakSensName = 0;
	int numOfLamp = 0;
	string str_ans[3];

	int location_next_char = 0;
	int location_last_char = 0;
	bool roomFound = false;

	cout << "+++++++++++++" << endl;
	try {

		for (int i = 0; i < Raum::getAllObjects().size(); i++) {
			string roomName_i = Raum::getAllObjects()[i]->getName();
			cout << "roomName_i: " << roomName_i << endl;
			if (roomName_i.compare(roomname) == 0) {
				cout << "Room " << roomName_i << "was found on the Raum objList" << endl;
				roomFound = true;
				numOfLamp = Raum::getAllObjects()[i]->getNumOfLampe();
				cout << "numOfLamp: " << numOfLamp << endl;
				for (int j = 0; j < numOfLamp; j++) {
					tempActorList[j] = Raum::getAllObjects()[i]->lampe[j].getName();
					cout << "tempActorList[i]: " << tempActorList[i] << endl;
				}
				break;
			}
			else {
				roomFound = false;
			}
			cout << endl;
		}

		cout << "+++++++++++++" << endl;

		if (roomFound == false) {
			throw ROOM_NOT_FOUND;
		}
		else {
			// Save all actor in charr array
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

			str_ans[0] = "0";
			str_ans[1] = actorInRoom;
			str_ans[2] = roomname;

			this->prepareAnswer(str_ans, 3, actorInRoom);

			strcpy(actor, actorInRoom);


			cout << "-----------------" << endl;
		}


	}
	catch (const char* errorCode) {
		str_ans[0] = errorCode;
		str_ans[1] = "GET_ACTORLIST";
		str_ans[2] = roomname;

		this->prepareAnswer(str_ans, 3, actorInRoom);
		strcpy(actor, actorInRoom);
	}
	catch (std::exception& e) {
		cerr << e.what() << endl;
		str_ans[0] = SERVER_ERROR; // Server error, exception occure
		str_ans[1] = e.what();
		str_ans[2] = roomname;

		this->prepareAnswer(str_ans, 3, actorInRoom);
		strcpy(actor, actorInRoom);
	}

}


void Server::getAllRooms(char* rooms) {

	int location_next_char = 0;
	char temp[1024];
	string str_ans[2];

	for (int i = 0; i < Raum::getAllObjects().size(); i++) {
		string roomName_i = Raum::getAllObjects()[i]->getName();

		for (int m = 0; m < roomName_i.length(); m++) {
			char now = roomName_i[m];
			temp[m + location_next_char] = now;
		}

		location_next_char += roomName_i.length();

		if (i == Raum::getAllObjects().size() - 1) {
			temp[location_next_char] = '\0';
		}
		else {
			temp[location_next_char] = ',';
			location_next_char += 1; // after comma
		}

	}

	str_ans[0] = "0";
	str_ans[1] = temp;
	this->prepareAnswer(str_ans, 2, rooms);

}



void Server::getSensorState(string roomname, string sensorname, char* ans) {

	const char* tempAns;

	int numOfFens = 0;

	bool sensorFound = false;
	bool sensState = false;
	bool roomFound = false;
	double tempVal = 0.0;

	string str_ans[4];

	try {
		// Get list of Raum's object
		for (int i = 0; i < Raum::getAllObjects().size(); i++) {
			string roomName_i = Raum::getAllObjects()[i]->getName();
			cout << "roomName_i: " << roomName_i << endl;
			if (roomName_i.compare(roomname) == 0) {
				cout << "Room " << roomName_i << "was found on the Raum objList" << endl;
				roomFound = true;
				numOfFens = Raum::getAllObjects()[i]->getNumOfFenster();

				string kontakSensName = "";

				// go through all Fenster
				for (int k = 0; k < numOfFens; k++) {
					kontakSensName = Raum::getAllObjects()[i]->fenster->kontaksensor->getName();
					// check if given sensorname is "kontaktsensor"
					if (kontakSensName.compare(sensorname) == 0) {
						// kontaksensor was found
						sensState = Raum::getAllObjects()[i]->fenster->kontaksensor->getStatus();

						sensorFound = true;
						str_ans[0] = "0"; // actor/sensor was found
						str_ans[1] = sensorname;
						str_ans[2] = roomname;
						if (sensState == true) {
							str_ans[3] = "On";
						}
						else {
							str_ans[3] = "Off";
						}
						this->prepareAnswer(str_ans, 4, ans);
						break;
					}
					else {
						sensorFound = false;
						// cant find the given sensorname in kontaksensor, maybe tempSens?
					}
				}

				if (sensorFound == false) {
					string tempSensName = Raum::getAllObjects()[i]->temp_sens.getName();
					if (tempSensName.compare(sensorname) == 0) {
						// given sensorname must be TempSens
						tempVal = Raum::getAllObjects()[i]->temp_sens.getValue();
						sensorFound = true;

						// copy the result in ans
						string str_tempVal = to_string(tempVal);
						tempAns = str_tempVal.c_str();
						str_ans[0] = "0"; // actor/sensor was found
						str_ans[1] = sensorname;
						str_ans[2] = roomname;
						str_ans[3] = tempAns;
						this->prepareAnswer(str_ans, 4, ans);
					}
					else {
						sensorFound = false;
						// Here the sensorname was found nowhere in the room
						throw SENSOR_ACTOR_NOT_FOUND;
					}

				}



			}
			else {
				roomFound = false;
			}

			cout << endl;
		}
		
		if (roomFound == false) {
			throw ROOM_NOT_FOUND;
		}

	}
	catch (const char* errorCode) {
		// cant find the given actor in room
		/*
		str_ans[0] = errorCode;
		str_ans[1] = "GET_SENSORSTATE";
		str_ans[2] = sensorname;
		str_ans[3] = roomname;
		*/
		str_ans[0] = errorCode;
		str_ans[1] = sensorname;
		str_ans[2] = roomname;
		str_ans[3] = "null";

		this->prepareAnswer(str_ans, 4, ans);
	}
	catch (std::exception& e) {
		cerr << e.what() << endl;
		str_ans[0] = SERVER_ERROR; // Server error, exception occure
		str_ans[1] = e.what();
		str_ans[2] = roomname;

		this->prepareAnswer(str_ans, 4, ans);
	}
}


void Server::setActorState(string roomname, string actorname, string action, char* ans) {
	cout << "-----------------" << endl;
	cout << "FROM - SERVER setActorState" << endl;
	cout << "roomname: " << roomname << endl;

	int numOfLamp = 0;
	bool actorFound = false;
	string str_ans[4];
	int location_next_char = 0;
	int location_last_char = 0;
	bool roomFound = false;


	try {

		cout << "+++++++++++++" << endl;
		for (int i = 0; i < Raum::getAllObjects().size(); i++) {
			string roomName_i = Raum::getAllObjects()[i]->getName();
			cout << "roomName_i: " << roomName_i << endl;
			if (roomName_i.compare(roomname) == 0) {
				cout << "Room " << roomName_i << "was found on the Raum objList" << endl;
				roomFound = true;
				numOfLamp = Raum::getAllObjects()[i]->getNumOfLampe();

				string actorName = "";

				// go through actor lamp first
				for (int k = 0; k < numOfLamp; k++) {
					actorName = Raum::getAllObjects()[i]->lampe->getName();
					// check if given actor is "lamp"
					if (actorName.compare(actorname) == 0) {
						// actor was found as lamp
						actorFound = true;

						// set actor status 
						bool action_bool = false;
						if (action.compare("On") == 0) {
							action_bool = true;
						}
						else {
							action_bool = false;
						}
						Raum::getAllObjects()[i]->lampe->setState(action_bool);

						// copy the result in ans
						// ans = <Fehlernummer>_<AktorName>_<RaumName>_<actor state>
						str_ans[0] = "0"; // actor/sensor not found
						str_ans[1] = actorname;
						str_ans[2] = roomname;
						str_ans[3] = action;
						break;
					}
					else {
						actorFound = false;
						throw SENSOR_ACTOR_NOT_FOUND;
						break;
					}
				}
			}
			cout << endl;
		}

		this->prepareAnswer(str_ans, 4, ans);

		cout << "+++++++++++++" << endl;



		if (roomFound == false) {
			throw ROOM_NOT_FOUND;
		}
	}

	catch (const char* errorCode) {
		// cant find the given actor in room
		// ans = <Fehlernummer>_<AktorName>_<RaumName>_<actor state>
		str_ans[0] = errorCode;
		str_ans[1] = actorname;
		str_ans[2] = roomname;
		str_ans[3] = action;

		this->prepareAnswer(str_ans, 4, ans);
	}
	catch (std::exception& e) {
		cerr << e.what() << endl;
		str_ans[0] = SERVER_ERROR; // Server error, exception occure
		str_ans[1] = e.what();
		str_ans[2] = roomname;

		this->prepareAnswer(str_ans, 3, ans);
	}
}


void Server::createRoom(string p_name, string fensterName[], int lengthFensterArr, string lampeName[], int lenghtLampArr, char* ans) {

	string str_ans[4];
	bool roomExisted = false;

	try {

		// Get list of Raum's object
		for (int i = 0; i < Raum::getAllObjects().size(); i++) {
			string roomName_i = Raum::getAllObjects()[i]->getName();
			cout << "roomName_i: " << roomName_i << endl;
			if (roomName_i.compare(p_name) == 0) {
				cout << "Room " << roomName_i << "is existed" << endl;
				roomExisted = true;
				break;
			}
			else {
				roomExisted = false;
			}
		}

		if (roomExisted == false) {
			// Create Room
			this->raumObj = new Raum(p_name, fensterName, lengthFensterArr, lampeName, lenghtLampArr);
			str_ans[0] = SERVER_NO_ERROR;
			str_ans[1] = p_name;
			this->prepareAnswer(str_ans, 2, ans);
		}
		else {
			// throw error, room is existed
			throw ROOM_IS_EXISTED;
		}
	}
	catch (const char* errorCode) {
		str_ans[0] = errorCode;
		str_ans[1] = p_name;
		this->prepareAnswer(str_ans, 2, ans);
	}
	catch (std::exception& e) {
		cerr << e.what() << endl;
		str_ans[0] = SERVER_ERROR; // Server error, exception occure
		str_ans[1] = e.what();
		str_ans[2] = p_name;
		this->prepareAnswer(str_ans, 3, ans);
	}
}


/*
	Function prepareAnswer(string* content, int content_len, char* ans): "convert" array of string to a char array

	@param:
	- content: string array, the member of this array based on the type of message
		- For sensors:
		e.g GET_SENSORS_<roomName>: { failure code, sensorsInRoom: char array}


	- content_len = length of the array content
	- ans = the answer will be copied into this buffer as char array

*/
void Server::prepareAnswer(string* content, int content_len, char* ans) {
	int location_next_char = 0;
	int location_last_char = 0;

	for (int k = 0; k < content_len; k++) {

		// Failure code
		if (k == 0) {
			ans[0] = content[0][0];
			ans[1] = '_'; // add '_' after failure code
			location_next_char += 2; // next index is number 2
		}

		// After failure code
		else {

			for (int m = 0; m < (content[k].length()); m++) {
				char now = (content[k])[m];
				ans[m + location_next_char] = now;

			}

			location_next_char += content[k].length();

			// Last element or Word
			if (k == content_len - 1) {
				// Last element or word from array, append \0 at the end
				ans[location_next_char] = '\0';
			}
			else {
				ans[location_next_char] = '_';
				location_next_char += 1; // after _
			}

		}

	}


}



void Server::getPropertiesFromMessage(string raw, int propertes_len, string* res) {
	// raw: "first,second,third,"...
	string segment;
	int i = 0;
	stringstream string_stream_convReq(raw);

	// first parse the raw string array, remove the comma, save into Array of string array
	while (getline(string_stream_convReq, segment, ',')) {
		res[i] = segment;
		cout << "msgArr[i]: " << res[i] << endl;
		i++;
	}

}
