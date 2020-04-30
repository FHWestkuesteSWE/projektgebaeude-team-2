#include "Fenster.h"
#include <iostream>

using namespace std;

Fenster::Fenster() {
	//this->konstaksensor_ptr = kontaksensor;
	this->konstaksensor_ptr = kontaksensor;
}


void Fenster::setName(string p_name) {
	this->name = p_name;
}

string Fenster::getName() {
	return this->name;
}
