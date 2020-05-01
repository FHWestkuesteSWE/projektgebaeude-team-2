#pragma once

#include <string>
#include "Fenster.h"
#include "TemperaturSensor.h"
#include "Lampe.h"


using namespace std;

class Raum {
private:
	string name;

public:
	
	Raum(string p_name);
	~Raum();

	string getName();


	// Every room has 2 windows
	Fenster fenster[2];

	// Every room has 1 temperature sensor
	TemperaturSensor temp_sens;

	// Every room has 2 lamps
	Lampe lamp[2];
	
};

