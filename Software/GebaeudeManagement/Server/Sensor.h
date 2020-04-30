#pragma once

#include <string>

using namespace std;

class Sensor {
private:
	int id;
	bool status;
	double value;

public:

	Sensor();
	~Sensor();

protected:
	double getValue();
	bool getStatus();

	void setId(int p_id);
	void setStatus(bool p_status);
	void setValue(double p_value);
};

