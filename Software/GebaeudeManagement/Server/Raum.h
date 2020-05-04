#pragma once

#include <string>
#include "Fenster.h"
#include "TemperaturSensor.h"
#include "Lampe.h"

using namespace std;

class Raum {
private:
	string name;
	int numOfFenster;
	int numOfLampe;

public:
	
	Raum(string p_name, string fensterName[], int lengthFensterArr, string lampeName[], int lenghtLampArr);
	~Raum();

	int getNumOfFenster();
	int getNumOfLampe();

	string getName();



	Fenster* fenster;
	Lampe* lampe;

	// Every room has 1 temperature sensor
	TemperaturSensor temp_sens;



	
};

