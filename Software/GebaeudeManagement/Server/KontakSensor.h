#pragma once

#include "Sensor.h"

class KontakSensor : Sensor {
private:
	string name;

public:
	KontakSensor();
	~KontakSensor();

	void setStatus(bool p_status);
	void setValue(double p_value);

	void setName(string p_name);
	string getName();

	double getValue();
	bool getStatus();
};

