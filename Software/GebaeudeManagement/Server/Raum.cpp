#include "Raum.h"

Raum::Raum(string p_name) {

	this->name = p_name;

	// create Fenster for each Raum
	fenster[0].setName("Links");
	fenster[1].setName("Rechts");

	// assign fenster pointer
	fenster_ptr = fenster;


	fenster_ptr[0].konstaksensor_ptr[0].setName("FENSTER_0_SENSOR_MAIN");
	fenster_ptr[0].konstaksensor_ptr[1].setName("FENSTER_0_SENSOR_SECOND");

	fenster_ptr[1].konstaksensor_ptr[0].setName("FENSTER_1_SENSOR_MAIN");
	fenster_ptr[1].konstaksensor_ptr[1].setName("FENSTER_1_SENSOR_SECOND");

}

Raum::~Raum() {
	//delete fenster_ptr;
}

string Raum::getName() {
	return this->name;
}