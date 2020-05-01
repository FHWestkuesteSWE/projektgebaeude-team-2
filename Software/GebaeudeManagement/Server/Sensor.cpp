#include "Sensor.h"

Sensor::Sensor() {
	this->id = 0;
	this->status = false;
	this->value = 0.0;
}

Sensor::~Sensor() {

}

double Sensor::getValue() {
	return value;
}
bool Sensor::getStatus() {
	return status;
}

void Sensor::setId(int p_id) {
	this->id = p_id;
}

void Sensor::setStatus(bool p_status) {
	status = p_status;
}
void Sensor::setValue(double p_value) {
	value = p_value;
}

