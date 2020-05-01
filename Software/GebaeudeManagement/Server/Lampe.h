#pragma once

#include "Actor.h"

class Lampe : Actor {
private:
	string name;

public:
	Lampe();
	~Lampe();

	void setState(bool p_action);
	bool getState();

	void setName(string p_name);
	string getName();

};
