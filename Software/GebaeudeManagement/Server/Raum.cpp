#include "Raum.h"

Raum::Raum(string p_name) {

	this->name = p_name;

	// create Fenster for each Raum
	fenster[0].setName("Links");
	fenster[1].setName("Rechts");


	fenster[0].setName("FENSTER_0_SENSOR_MAIN");
	fenster[0].konstaksensor_ptr[1].setName("FENSTER_0_SENSOR_SECOND");
	fenster[1].konstaksensor_ptr[0].setName("FENSTER_1_SENSOR_MAIN");
	fenster[1].konstaksensor_ptr[1].setName("FENSTER_1_SENSOR_SECOND");

	// Temp Sensor
	temp_sens.setName("TEMP_SENSOR_MAIN");

	// Lamp
	lamp[0].setName("LAMP_1");
	lamp[1].setName("LAMP_2");
	lamp[0].setState(true); // on
	lamp[1].setState(false); // off

	
}

Raum::~Raum() {
	//delete fenster_ptr;
}

string Raum::getName() {
	return this->name;
}