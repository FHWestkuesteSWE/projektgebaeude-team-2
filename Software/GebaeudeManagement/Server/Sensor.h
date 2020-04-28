#pragma once

#include <string>

using namespace std;

class Sensor {
private:
	int id;
	bool status;
	double value;

public:

	double getValue();
	bool getStatus();

	Sensor(int p_id);
	~Sensor();

};

