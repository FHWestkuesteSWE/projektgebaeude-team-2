#pragma once
#include "BasicClient.h"
class Client : BasicClient
{
public:
	Client(char server[], char port[]);
	void sendRequest(const char request[], char answer[]);
	~Client();
protected:

}; 
