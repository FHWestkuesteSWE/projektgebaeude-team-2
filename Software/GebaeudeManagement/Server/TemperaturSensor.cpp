#include "TemperaturSensor.h"

#include <iostream>

using namespace std;

TemperaturSensor::TemperaturSensor() {
	// Set Sensor id = 2
	Sensor::setId(2);

}

TemperaturSensor::~TemperaturSensor() {

}

void TemperaturSensor::setName(const string p_name) {
	this->name = p_name;
}

void TemperaturSensor::setStatus(bool p_status) {
	Sensor::setStatus(p_status);
}

void TemperaturSensor::setValue(double p_value) {
	Sensor::setValue(p_value);
}


double TemperaturSensor::getValue() {
	double value = Sensor::getValue();
	return value;
}
bool TemperaturSensor::getStatus() {
	bool status = Sensor::getStatus();
	return status;
}


string TemperaturSensor::getName() {
	return this->name;
}

