#include "Sensor.h"

Sensor::Sensor(int p_id) {
	id = p_id;
}

Sensor::~Sensor() {

}

double Sensor::getValue() {
	return value;
}
bool Sensor::getStatus() {
	return status;
}

