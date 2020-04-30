#include "KontakSensor.h"

#include <iostream>

using namespace std;

KontakSensor::KontakSensor() {
	// Set Sensor id = 1
	Sensor::setId(1);

}

KontakSensor::~KontakSensor() {

}

void KontakSensor::setName(string p_name) {
	this->name = p_name;
}

void KontakSensor::setStatus(bool p_status) {
	Sensor::setStatus(p_status);
}

void KontakSensor::setValue(double p_value) {
	Sensor::setValue(p_value);
}


double KontakSensor::getValue() {
	double value = Sensor::getValue();
	return value;
}
bool KontakSensor::getStatus() {
	bool status = Sensor::getStatus();
	return status;
}


string KontakSensor::getName() {
	return this->name;
}

