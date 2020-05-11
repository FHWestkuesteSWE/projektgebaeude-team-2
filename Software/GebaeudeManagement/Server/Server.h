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

	string getRoomNameFromMsg(char msg[]);
	void getSensorFromRoom(string roomname, char* sensors);
	void getActorFromRoom(string roomname, char* actor);
	void getAllRooms(char* rooms);


protected:
	virtual void processRequest(char request[], char answer[]);
};

