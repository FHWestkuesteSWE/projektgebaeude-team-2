#pragma once

#include "Sensor.h"

class TemperaturSensor : Sensor {
private:
	string name;

public:
	TemperaturSensor();
	~TemperaturSensor();

	void setStatus(bool p_status);
	void setValue(double p_value);

	void setName(const string p_name);
	string getName();

	double getValue();
	bool getStatus();
};
