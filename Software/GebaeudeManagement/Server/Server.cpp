#define _CRT_SECURE_NO_WARNINGS
#include "Server.h"
#include <string.h>
#include <algorithm>

Server::Server()
{

}

void Server::start(char port[]) {
	
	// Start server using function from BasicServer
	BasicServer::start(port);

}

void Server::processRequest(char req[], char ans[]) {
	//strncpy(ans, req, std::min<int>(1024, strlen(ans) + 1));
	char temp[] = "Wohnzimmer,Schlafzimmer,Küche,Badezimmer";

	strncpy(ans, temp, std::min<int>(max_length, strlen(temp) + 1));
	// Schnitstellen zu der andren Klasse

}

Server::~Server(){
}
