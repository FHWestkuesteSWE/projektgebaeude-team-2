#include "Fenster.h"
#include <iostream>

using namespace std;

Fenster::Fenster() {
	
	// Set KontaktSensor name to _MAIN and _SECOND
	this->kontaksensor[0].setName("KONTAKT_SENSOR_MAIN");
	this->kontaksensor[1].setName("KONTAKT_SENSOR_SECOND");
}


void Fenster::setName(string p_name) {
	this->name = p_name;
}

string Fenster::getName() {
	return this->name;
}
