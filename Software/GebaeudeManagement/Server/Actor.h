#pragma once

#include <string>

using namespace std;

class Actor {
private:
	int id;
	bool state;

public:

	void setId(int p_id);
	void setState(bool p_action);
	bool getState();

	Actor();
	~Actor();

};

