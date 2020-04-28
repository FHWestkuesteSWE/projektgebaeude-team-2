#pragma once

#include "Raum.h"
#include "KontakSensor.h"

class Fenster {
public:
	string name;
	Fenster(std::string p_name);
	~Fenster();

	// For redundancy, use 2 sensors
	KontakSensor kontaktsens[2];
};

