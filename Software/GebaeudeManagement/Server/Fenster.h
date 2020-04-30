#pragma once

#include "KontakSensor.h"
#include <string>

class Fenster {
	string name;

public:
	void setName(string p_name);
	
	string getName();

	Fenster();

	KontakSensor kontaksensor[2];

	KontakSensor* konstaksensor_ptr;
};

