#pragma once
#include "BasicClient.h"
#include <iostream>
#include "Client.h"
#include "conio.h"
#include <boost/algorithm/string.hpp> // split
#include "SSLClient.h"
using namespace std;
//class Client : BasicClient
class Client : SSLClient
{
public:
	Client(char server[], char port[]);
	void sendRequest(const char request[], char answer[]);
	void removeErrorCode(char* s);
	vector<string> getRooms();
	vector<string> getSensorList(string room);
	~Client();
protected:

}; 
