#pragma once
#include <string>
#include <vector>
#include "BasicServer.h"

using namespace std;

class Server : BasicServer {
public:
	void start(char port[]);
	Server();
	~Server();


	void getSensorFromRoom(string roomname, char* sensors);
	void getActorFromRoom(string roomname, char* actor);
	void getAllRooms(char* rooms);

	// todo
	void getSensorState(string roomname, string sensorname, char* ans);
	void setActorState(string roomname, string actorname, string action, char* ans);

	void prepareAnswer(string* content, int content_len, char* ans);


protected:
	virtual void processRequest(char request[], char answer[]);
};

