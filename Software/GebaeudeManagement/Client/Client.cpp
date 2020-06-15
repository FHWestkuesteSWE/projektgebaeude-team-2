#include "Client.h"
#include <boost/algorithm/string.hpp> // split
#include <iostream>
#include "conio.h"


Client::Client(char _server[], char _port[]) : BasicClient(_server, _port){

}

void Client::sendRequest(const char request[], char answer[]) {

	BasicClient::sendRequest(request, answer);

}

void Client::removeErrorCode(char* s)
{
	for (int n = 0; n < strlen(s); ++n)
		s[n] = s[n + 2];

	
}


vector<string> Client::getRooms() {
	char req[] = "GET_ROOMS";
	char ans[1024];
	BasicClient::sendRequest(req, ans);


	vector<string> splittedVector;
	boost::split(splittedVector, ans, boost::is_any_of(","));
	removeErrorCode(&splittedVector[0][0]);
	cout << splittedVector.at(0) << endl;
	return splittedVector;
	
}

vector<string> Client::getSensorList(string room) {
	//string temp =  "GET_SENSORSLIST_"  + room;
	string temp = "GET_ACTORLIST_Schlafzimmer";

	char req[1024];
	int test = strlen(temp.c_str());
	//strcpy_s(req, strlen(temp.c_str()), temp.c_str());
	char ans[1024];
	BasicClient::sendRequest(temp.c_str(), ans);


	vector<string> splittedVector;
	boost::split(splittedVector, ans, boost::is_any_of(","));
	removeErrorCode(&splittedVector[0][0]);
	cout << splittedVector.at(0) << endl;
	return splittedVector;

}


Client::~Client() {

}
