#pragma once

#include <string>
#include "Lampe.h"
#include "Fenster.h"
#include "TemperaturSensor.h"

using namespace std;

class Raum {
public:

	string name;
	Raum(string p_name);
	~Raum();

	// For redundancy, use 2 temperature sensors
	TemperaturSensor tempSens[2];

	// For now each room has:
	// Fenster: 2
	// Lampe: 1
	// Alterative: fens[number_of_fenster]

	Fenster fens[2];
	Lampe lamp("Links");

};

