#pragma once

#include "KontakSensor.h"
#include <string>

class Fenster {
	string name;

public:
	void setName(string p_name);
	
	string getName();

	Fenster();

	// Every Fenster has 2 KontakSensor
	KontakSensor kontaksensor[2];
};

