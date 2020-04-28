#pragma once

#include <string>

using namespace std;

class Actor {
private:

	int id;
	bool state;

public:

	void setState(bool _action);
	bool getState();

	Actor();
	Actor(int _id);
	~Actor();

};

