#pragma once
#include <string>
#include <vector>
#include "BasicServer.h"
#include "Raum.h"

using namespace std;

class Server : BasicServer {
private:
	Raum* raumObj;

public:
	void start(char port[]);
	Server();
	~Server();


	void getSensorFromRoom(string roomname, char* sensors);
	void getActorFromRoom(string roomname, char* actor);
	void getAllRooms(char* rooms);

	void getSensorState(string roomname, string sensorname, char* ans);
	void setActorState(string roomname, string actorname, string action, char* ans);
	void createRoom(string p_name, string fensterName[], int lengthFensterArr, string lampeName[], int lenghtLampArr, char* ans);

	void prepareAnswer(string* content, int content_len, char* ans);
	void getPropertiesFromMessage(string raw, int propertes_len, string* res);


protected:
	virtual void processRequest(char request[], char answer[]);
};

