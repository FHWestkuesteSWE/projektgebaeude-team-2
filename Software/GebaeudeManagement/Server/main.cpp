#include "Server.h"
#include "Raum.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

	
	// Make a new Raum
	Raum schlafraum("schlafraum");

	string raumName = schlafraum.getName();
	cout << "Raum - " << raumName << endl;
	cout << "Raum: " << raumName << " has fenster: " << endl;
	for (int i = 0; i < 2; i++){
		string fensterName = schlafraum.fenster[i].getName();
		cout << "Fenster " << i+1 << ": " << fensterName << endl;
		cout << "\t Fenster - " << fensterName << " has sensors: " << endl;
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				schlafraum.fenster[i].konstaksensor_ptr[j].setName("SENSOR_MAIN");
			}
			else {
				schlafraum.fenster[i].konstaksensor_ptr[j].setName("SENSOR_SECOND");
			}
			string sensorName = schlafraum.fenster[i].konstaksensor_ptr[j].getName();
			cout << "\t \t Sensor - " << sensorName << endl;
		}
		cout << " " << endl;
	}

	schlafraum.temp_sens.setValue(22.3);

	cout << "Schlafraum temp_sens: " << schlafraum.temp_sens.getValue() << endl;
	cout << "Sclafraum lamp 1: " << schlafraum.lamp[0].getState() << endl;
	cout << "Sclafraum lamp 2: " << schlafraum.lamp[1].getState() << endl << endl;
	
	

	Server s;
	s.start(argv[1]);


	return 0;
}