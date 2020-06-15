// main.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Client.h"
#include "Menue.h"
#include "conio.h"
#include <boost/algorithm/string.hpp> // split

using namespace std;

int main(int argc, char* argv[])
{
	int raumAuswahl_cb(int);
	Client c(argv[1], argv[2]);
    //char req[1024];
    //char ans[1024];
	//char test[] = "Wohnzimmer,Schlafzimmer,Kueche,Badezimmer (Gast)";
	//hauptmenueRoomSelection(c);

	vector<string> rooms = c.getRooms();

	Menue raumAuswahl = Menue::Menue("Waehlen Sie einen Raum aus:", rooms, &raumAuswahl_cb);

	// Menü/ClientProgramm endet hier
	return 0;
}









int raumAuswahl_cb(int i)
{
	//Benutzereingabe auswerten: Hier: Welcher Raum wurde gewählt bzw. soll das Programm beendet werden?

	// Dafür wird benötigt: Position der Auswahl und und Menü-Items

	int sensorAktorAuswahl_cb(int);
	vector<string> aktor_sensor = {"Aktoren ansteuern", "Sensoren abfragen"};

	//Menue sensorAktorAuswahl = Menue::Menue(c,"Waehlen Sie eine Aktion aus:", aktor_sensor, &sensorAktorAuswahl_cb);


	printf("%d\n",i);
	return 0;

}

int sensorAktorAuswahl_cb(int i)
{
	printf("%d\n", i);
	return 0;

}

 

