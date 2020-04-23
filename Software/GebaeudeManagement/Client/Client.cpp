#include "Client.h"


Client::Client(char _server[], char _port[]) : BasicClient(_server, _port){

}

void Client::sendRequest(const char request[], char answer[]) {

	BasicClient::sendRequest(request, answer);

}

Client::~Client() {

}
