#include "BasicClient.h"

#include <iostream>
using namespace std;


BasicClient::BasicClient(char _server[], char _port[]) {
	server = _server;
	port = _port;
}
void BasicClient::sendRequest(const char request[], char answer[]) {
	cout << "BasicClient::sendRequest" << endl;
	boost::asio::io_service io_service;

	tcp::resolver resolver(io_service);
	tcp::resolver::query query(tcp::v4(), server, port);
	tcp::resolver::iterator iterator = resolver.resolve(query);

	tcp::socket s(io_service);
	cout << "connecting..." << endl;
	boost::asio::connect(s, iterator);
	cout << "connection done" << endl;

	size_t request_length = strlen(request)+1;
	boost::asio::write(s, boost::asio::buffer(request, request_length));

	size_t reply_length = boost::asio::read(s,
		boost::asio::buffer(answer, max_length));
}
BasicClient::~BasicClient() {

}
