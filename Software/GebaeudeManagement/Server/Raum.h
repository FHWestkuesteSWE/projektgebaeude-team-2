#pragma once

#include <string>
#include "Fenster.h"

//#include "Lampe.h"
//#include "TemperaturSensor.h"

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
	
	// Pointer to the windows(array)
	Fenster* fenster_ptr;
	
};

