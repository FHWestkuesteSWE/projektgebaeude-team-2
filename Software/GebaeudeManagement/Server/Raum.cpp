#include "Raum.h"
#include <iostream>


vector<Raum*> Raum::getAllObjects() {
	return objList;
}

Raum::Raum() {
	this->numOfFenster = 0;
	this->numOfLampe = 0;
	this->fenster = NULL;
	this->lampe = NULL;
}



void Raum::addFenster(int numOfFens, string fensterName[], Raum* ptr) {
	try {
		// Check if Raum has Fenster or not
		if (fensterName == NULL) {
			;
		}
		else {
			if (numOfFens == 0) {
				throw "Error - Length of fensterName Array is 0, while fensterName Array is not empty";
			}
			else {
				// Allocate Fenster
				ptr->fenster = new Fenster[numOfFens];
				ptr->numOfFenster = numOfFens;
				//this->fenster = new Fenster[numOfFens];
				//this->numOfFenster = numOfFens;

				for (int i = 0; i < numOfFens; i++) {
					// Set Fenster name
					//this->fenster[i].setName(fensterName[i]);
					ptr->fenster[i].setName(fensterName[i]);
				}

			}
		}
	}
	catch (const char* msg) {
		cout << msg << endl;
	}
	catch (std::exception& e) {
		cerr << e.what() << endl;
	}
}

void Raum::addLampe(int numOflamp, string lampeName[], Raum* ptr) {
	try {
		// Check if Raum has Lampe or not
		if (lampeName == NULL) {
			// Raum does not have Lampe
			;
		}
		else {
			if (numOflamp == 0) {
				throw "Error - Length of lenghtLampArr is 0, while lampeName Array is not empty";
			}
			else {
				// Raum has Lampe
				ptr->lampe = new Lampe[numOflamp];
				ptr->numOfLampe = numOflamp;

				for (int i = 0; i < numOflamp; i++) {

					// Set Lampe name
					ptr->lampe[i].setName(lampeName[i]);

					// Set Lampe state to off (false)
					ptr->lampe[i].setState(false);
				}

			}

		}

	}
	catch (const char* msg) {
		cout << msg << endl;
	}
	catch (std::exception& e) {
		cerr << e.what() << endl;
	}
}

Raum::Raum(string p_name, string fensterName[], int lengthFensterArr, string lampeName[], int lenghtLampArr) {

	// Set Raum name
	this->name = p_name;
	// push Raum object into vector
	objList.push_back(this);

	// Add Fenster and Lampe, and temp sensor
	Raum* roomObj_ptr = Raum::getRoomObj(p_name);
	if ((roomObj_ptr->getName()).compare(p_name) == 0) {
		// First add Fenster
		addFenster(lengthFensterArr, fensterName, roomObj_ptr);

		// Then, add Lampe
		addLampe(lenghtLampArr, lampeName, roomObj_ptr);

		// Lastly, add Temp Sensor
		temp_sens.setName("TempSensMain");
	}

}

Raum::~Raum() {
	
	delete this->fenster;
	delete this->lampe;
	// clear vector objList
	for (std::vector<Raum*>::iterator i = this->objList.begin(), endI = this->objList.end(); i != endI; ++i){
		delete *i;
	}
	this->objList.clear();
	

}


Raum* Raum::getRoomObj(string roomName) {

	Raum* res = new Raum();
	for (int i = 0; i < getAllObjects().size(); i++) {
		string roomName_i = getAllObjects()[i]->getName();
		if (roomName_i.compare(roomName) == 0) {
			res = getAllObjects()[i];
			break;
		}
		else {
			;
		}

	}
	return res;
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