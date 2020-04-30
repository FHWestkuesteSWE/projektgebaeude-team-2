#include "Server.h"
#include "Raum.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {

	
	// Make a new Raum
	Raum schlafraum("schlafraum");

	cout << "size fenster pointer of schlafraum: " << sizeof(schlafraum.fenster_ptr) << endl << endl;
	string raumName = schlafraum.getName();
	cout << "Raum - " << raumName << endl;
	cout << "Raum: " << raumName << " has fenster: " << endl;
	for (int i = 0; i < 2; i++){
		string fensterName = schlafraum.fenster_ptr[i].getName();
		cout << "Fenster " << i+1 << ": " << fensterName << endl;
		cout << "\t Fenster - " << fensterName << " has sensors: " << endl;
		for (int j = 0; j < 2; j++) {
			if (j == 0) {
				schlafraum.fenster_ptr[i].konstaksensor_ptr[j].setName("SENSOR_MAIN");
			}
			else {
				schlafraum.fenster_ptr[i].konstaksensor_ptr[j].setName("SENSOR_SECOND");
			}
			string sensorName = schlafraum.fenster_ptr[i].konstaksensor_ptr[j].getName();
			cout << "\t \t Sensor - " << sensorName << endl;
		}
		cout << " " << endl;
	}
	
	

	Server s;
	s.start(argv[1]);


	return 0;
}