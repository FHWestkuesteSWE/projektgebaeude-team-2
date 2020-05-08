#include "Raum.h"
#include <iostream>


using namespace std;


Raum::Raum() {
	;
}

Raum::Raum(string p_name, string fensterName[], int lengthFensterArr, string lampeName[], int lenghtLampArr) {
	// Now array fensterName is decayed as pointer
	// Because the array in parameter decayed as pointer, there is no change to get the length of it.
	// It is automaticly became an address of the array

	/* ------------ FENSTER ------------ */
	// Check if Raum has Fenster or not
	if (fensterName == NULL) {
		// Raum does not have Fenster
		cout << "Raum " << this->name << "does not have Fenster" << endl;
	}
	else {
		if (lengthFensterArr == 0) {
			throw "Error - Length of fensterName Array is 0, while fensterName Array is not empty";
		}
		else {
			// Set Raum name
			this->name = p_name;

			// Allocate Fenster, Lampe object based on the given length parameter
			this->fenster = new Fenster[lengthFensterArr];
			this->lampe = new Lampe[lenghtLampArr];

			// Save total of Fenster and Lampe in variable
			this->numOfFenster = lengthFensterArr;
			this->numOfLampe = lenghtLampArr;

			// Raum has Fenster
			for (int i = 0; i < lengthFensterArr; i++) {

				// Set Fenster name
				this->fenster[i].setName(fensterName[i]);
			}

		}
	}

	/* ------------ Lampe ------------ */
	// Check if Raum has Lampe or not
	if (lampeName == NULL) {
		// Raum does not have Lampe
		cout << "Raum " << this->name << "does not have Lampe" << endl;
	}
	else {
		if (lenghtLampArr == 0) {
			throw "Error - Length of lenghtLampArr is 0, while lampeName Array is not empty";
		}
		else {
			// Raum has Lampe
			for (int i = 0; i < lenghtLampArr; i++) {

				// Set Lampe name
				this->lampe[i].setName(lampeName[i]);

				// Set Lampe state to off (false)
				this->lampe[i].setState(false);
			}

		}


	}

	/* ------------ TEMPERATURE SENSOR ------------ */
	// Temp Sensor
	temp_sens.setName("TEMP_SENSOR_MAIN");


}

Raum::~Raum() {
	delete this->fenster;
}

string Raum::getName() {
	return this->name;
}

int Raum::getNumOfFenster() {
	return this->numOfFenster;
}

int Raum::getNumOfLampe() {
	return this->numOfLampe;
}