// main.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Client.h"
#include "conio.h"
#include <boost/algorithm/string.hpp> // split

using namespace std;

/*
 * Parse Server-String
 */
list<string> parseServerString(string serverString)
{
	list<string> str;

	boost::split(str, serverString, boost::is_any_of(","));

	list<string>::iterator i;
	for (i = str.begin(); i != str.end(); i++)
	{
		std::cout << *i << endl;

	}

	return str;
}

void hauptmenueRoomSelection(Client c)
{
	void selectionMarker(int, int);
	void sensorMenue();
	void aktorMenue();

	char req[] = "GET_ROOMS";
	char ans[1024];
	c.sendRequest(req, ans);

	list<string> splittedAnswer;
	boost::split(splittedAnswer, ans, boost::is_any_of(","));

	char wahl = 0;
	int position = 1;
	int maxLines = splittedAnswer.size() + 1;
	int exitHauptmenue = 0;

	do {
		system("cls");
		std::cout << "Gebauedeleitsystem FHW Team 2\n";
		cout << "Hauptmenue: " << endl;
		cout << "Waehlen Sie einen Raum aus" << endl;
		cout << "----------------------------------------------------" << endl;

		list<string>::iterator i;
		int lineCount = 1;
		for (i = splittedAnswer.begin(); i != splittedAnswer.end(); i++)
		{
			selectionMarker(lineCount++, position); cout << *i << endl;

		}

		selectionMarker(lineCount, position); printf("Programm beenden\n");


		wahl = _getch();
		switch (wahl) {
		case 80: // Arrow down
			if (position != maxLines)
				position++;
			break;

		case 72: // Arrow up
			if (position != 1)
				position--;
			break;

		case 13: // Enter
			switch (position) {
			case 1: // Sensoren-Menü
				sensorMenue();
				break;
			case 2: // Aktoren-Menü
				aktorMenue();
				break;
			case 3: // Hauptmenü/Programm beenden
				printf("Programm wird beendet ...\n");
				exitHauptmenue = 1;
				//Sleep(1000);
				break;
			}
			break;
		}
	} while (exitHauptmenue != 1);
}

int main(int argc, char* argv[])
{
	//void parseServerString(string);
	void selectionMarker(int, int);
	void hauptmenue();

    Client c(argv[1], argv[2]);
    char req[1024];
    char ans[1024];
	char test[] = "Wohnzimmer,Schlafzimmer,Kueche,Badezimmer (Gast)";
	hauptmenueRoomSelection(c);

	//TODO
	//-> sending requests from sub(sub)menues to server
	
	list<string> ret = parseServerString(test);
	printf("num_Max = %d\n", ret.size());

	return 0;
}

void selectionMarker(int position, int markerPosition)
{
	if (position == markerPosition)
		printf("--> ");
	else
		printf("    ");
}

/*
 * Try of server based client menue
 */



void hauptmenue() {

	void sensorMenue();
	void aktorMenue();

	char wahl = 0;
	int position = 1;
	int maxLines = 3;
	int exitHauptmenue = 0;


	do {
		system("cls");
		std::cout << "Gebauedeleitsystem FHW Team 2\n";
		cout << "Hauptmenue: " << endl;
		cout << "Was wollen Sie tun? " << endl;
		cout << "----------------------------------------------------" << endl;
		selectionMarker(1, position); printf("Sensoren abfragen\n");
		selectionMarker(2, position); printf("Aktoren ansteuern\n");
		selectionMarker(3, position); printf("Programm beenden\n");

		wahl = _getch();
		switch (wahl) {
		case 80: // Arrow down
			if (position != maxLines)
				position++;
			break;

		case 72: // Arrow up
			if (position != 1)
				position--;
			break;

		case 13: // Enter
			switch (position) {
			case 1: // Sensoren-Menü
				sensorMenue();
				break;
			case 2: // Aktoren-Menü
				aktorMenue();
				break;
			case 3: // Hauptmenü/Programm beenden
				printf("Programm wird beendet ...\n");
				exitHauptmenue = 1;
				//Sleep(1000);
				break;
			}
			break;
		}
	}
	while (exitHauptmenue != 1);
}

void sensorMenue()
{
	char wahl = 0;
	int position = 1;
	int maxLines = 4;
	int exitSensorMenue = 0;

	do {
		system("cls");
		std::cout << "Gebauedeleitsystem FHW Team 2\n";
		cout << "Untermenue: Sensorauswahl" << endl;
		cout << "Waehlen Sie einen Sensor aus" << endl;
		cout << "----------------------------------------------------" << endl;
		selectionMarker(1, position); printf("Temperatursensor\n");
		selectionMarker(2, position); printf("Kontaktsensor\n");
		selectionMarker(3, position); printf("Zurueck zum Hauptmenue\n");

		wahl = _getch();
		switch (wahl) {
		case 80: // Arrow down
			if (position != maxLines)
				position++;
			break;

		case 72: // Arrow up
			if (position != 1)
				position--;
			break;

		case 13: // Enter
			switch (position) {
			case 1: // Temperatursensor-Menü
				do { // do while Temperatursensor-Menü
					cout << "Waehlen Sie einen Raum fuer die Temperaturapfrage aus " << endl;
					cout << "----------------------------------------------------" << endl;
					cout << "Raum 1 \t(1)" << endl;
					cout << "Raum 2\t(2)" << endl;
					cout << "Raum 3\t(3)" << endl;
					cout << "Zurueck zur Sensorauswahl \t\t\t\t(z)" << endl;
					cout << "----------------------------------------------------" << endl;
					cout << "Ihre Wahl: ";
					cin >> wahl;
					switch (wahl) {
					case '1':
						cout << "Send Temp RQ Raum 1 " << endl;
						break;

					case '2':
						cout << "Send Remp RW Raum 2 " << endl;
						break;

					case '3':
						cout << "Send Temp RQ Raum 3 " << endl;
						break;

					case 'z':
						break;

					default:
						cout << "Ungueltige Auswahl ... " << endl;
					}
				} while (wahl != 'z');
				break;

			case 2: // Kontaktsensor-Menü
				do { // do while Kontaktsensor-Menü
					cout << "Waehlen Sie einen Raum fuer die Kontaktstatus-Abfrage aus " << endl;
					cout << "----------------------------------------------------" << endl;
					cout << "Raum 1 \t(1)" << endl;
					cout << "Raum 2\t(2)" << endl;
					cout << "Raum 3\t(3)" << endl;
					cout << "Zurueck zur Sensorauswahl \t\t\t\t(z)" << endl;
					cout << "----------------------------------------------------" << endl;
					cout << "Ihre Wahl: ";
					cin >> wahl;
					switch (wahl) {
					case '1':
						do { // do while Fensterauswahl Raum 1
							cout << "Waehlen Sie einen Fenster fuer die Statusabfrage aus (Raum 1) " << endl;
							cout << "----------------------------------------------------" << endl;
							cout << "Fenster 1 \t(1)" << endl;
							cout << "Fenster 2\t(2)" << endl;
							cout << "Zurueck zur Raumauswahl \t\t\t\t(z)" << endl;
							cout << "----------------------------------------------------" << endl;
							cout << "Ihre Wahl: ";
							cin >> wahl;
							switch (wahl) {
							case '1':
								cout << "Send R1 Fenster 1 Status RQ " << endl;
								break;

							case '2':
								cout << "Send R1 Fenster 2 Status RQ " << endl;
								break;

							case 'z':
								break;

							default:
								cout << "Ungueltige Auswahl ... " << endl;
							}
						} while (wahl != 'z');
						break;

					case '2':
						do { // do while Fensterauswahl Raum 2
							cout << "Waehlen Sie einen Fenster fuer die Statusabfrage aus (Raum 2)" << endl;
							cout << "----------------------------------------------------" << endl;
							cout << "Fenster 1 \t(1)" << endl;
							cout << "Fenster 2\t(2)" << endl;
							cout << "Zurueck zur Raumauswahl \t\t\t\t(z)" << endl;
							cout << "----------------------------------------------------" << endl;
							cout << "Ihre Wahl: ";
							cin >> wahl;
							switch (wahl) {
							case '1':
								cout << "Send R2 Fenster 1 Status RQ " << endl;
								break;

							case '2':
								cout << "Send R2 Fenster 2 Status RQ " << endl;
								break;

							case 'z':
								break;

							default:
								cout << "Ungueltige Auswahl ... " << endl;
							}
						} while (wahl != 'z');
						break;

					case '3':
						do { // do while Fensterauswahl Raum 3
							cout << "Waehlen Sie einen Fenster fuer die Statusabfrage aus (Raum 3)" << endl;
							cout << "----------------------------------------------------" << endl;
							cout << "Fenster 1 \t(1)" << endl;
							cout << "Fenster 2\t(2)" << endl;
							cout << "Zurueck zur Raumauswahl \t\t\t\t(z)" << endl;
							cout << "----------------------------------------------------" << endl;
							cout << "Ihre Wahl: ";
							cin >> wahl;
							switch (wahl) {
							case '1':
								cout << "Send R3 Fenster 1 Status RQ " << endl;
								break;

							case '2':
								cout << "Send R3 Fenster 2 Status RQ " << endl;
								break;

							case 'z':
								break;

							default:
								cout << "Ungueltige Auswahl ... " << endl;
							}
						} while (wahl != 'z');
						break;

					case 'z':
						break;




					default:
						cout << "Ungueltige Auswahl ... " << endl;
					}
				} while (wahl != 'z');
				break;

			case 3: // Zurueck zum Hauptmenue
				exitSensorMenue = 1;
				break;

			}
		}
	} while (exitSensorMenue != 1);

}

void aktorMenue()
{
	char wahl = 0;
	int position = 1;
	int maxLines = 3;
	int exitAktorMenue = 0;

	do {
		system("cls");
		std::cout << "Gebauedeleitsystem FHW Team 2\n";
		cout << "Untermenue: Aktorenauswahl" << endl;
		cout << "Wählen Sie eine Aktion aus " << endl;
		cout << "----------------------------------------------------" << endl;
		selectionMarker(1, position); printf("Lampenansteuerung\n");
		selectionMarker(2, position); printf("Zurueck zum Hauptmenue\n");

		wahl = _getch();

		switch (wahl) {
		case 80: // Arrow down
			if (position != maxLines)
				position++;
			break;

		case 72: // Arrow up
			if (position != 1)
				position--;
			break;

		case 13: // Enter
			switch (position) {
			case 1: // Raumauswahl für Lampenansteuerung
				do { // do while Lampenansterungs-Menü
					cout << "Waehlen Sie einen Raum fuer die Lampenansteuerung aus" << endl;
					cout << "----------------------------------------------------" << endl;
					cout << "Raum 1 \t(1)" << endl;
					cout << "Raum 2\t(2)" << endl;
					cout << "Raum 3\t(3)" << endl;
					cout << "Zurueck zur Sensorauswahl \t\t\t\t(z)" << endl;
					cout << "----------------------------------------------------" << endl;
					cout << "Ihre Wahl: ";
					cin >> wahl;
					switch (wahl) {
					case '1':
						do { // do while Lampenauswahl Raum 1
							cout << "Waehlen Sie eine Lampe fuer die Ansteuerung aus (Raum 1) " << endl;
							cout << "----------------------------------------------------" << endl;
							cout << "Lampe 1 \t(1)" << endl;
							cout << "Lampe 2\t(2)" << endl;
							cout << "Zurueck zur Raumauswahl \t\t\t\t(z)" << endl;
							cout << "----------------------------------------------------" << endl;
							cout << "Ihre Wahl: ";
							cin >> wahl;
							switch (wahl) {
							case '1':
								cout << "Wollen Sie in Raum 1 die Lampe 1 einschalten (1) oder ausschalten (2) ?" << endl;
								cout << "Ihre Wahl: ";
								cin >> wahl;
								if (wahl == '1')
									cout << "SET R1L1 ein";
								else if (wahl == '0')
									cout << "SET R1L1 aus";
								break;

							case '2':
								cout << "Wollen Sie in Raum 1 die Lampe 2 einschalten (1) oder ausschalten (2) ?" << endl;
								cout << "Ihre Wahl: ";
								cin >> wahl;
								if (wahl == '1')
									cout << "SET R1L2 ein";
								else if (wahl == '0')
									cout << "SET R1L2 aus";
								break;

							case 'z':
								break;

							default:
								cout << "Ungueltige Auswahl ... " << endl;
							}
						} while (wahl != 'z');
						break;

					case '2':
						do { // do while Lampenauswahl Raum 2
							cout << "Waehlen Sie eine Lampe fuer die Ansteuerung aus (Raum 2) " << endl;
							cout << "----------------------------------------------------" << endl;
							cout << "Lampe 1 \t(1)" << endl;
							cout << "Lampe 2\t(2)" << endl;
							cout << "Zurueck zur Raumauswahl \t\t\t\t(z)" << endl;
							cout << "----------------------------------------------------" << endl;
							cout << "Ihre Wahl: ";
							cin >> wahl;
							switch (wahl) {
							case '1':
								cout << "Wollen Sie in Raum 2 die Lampe 1 einschalten (1) oder ausschalten (2) ?" << endl;
								cout << "Ihre Wahl: ";
								cin >> wahl;
								if (wahl == '1')
									cout << "SET R2L1 ein";
								else if (wahl == '0')
									cout << "SET R2L1 aus";
								break;

							case '2':
								cout << "Wollen Sie in Raum 2 die Lampe 2 einschalten (1) oder ausschalten (2) ?" << endl;
								cout << "Ihre Wahl: ";
								cin >> wahl;
								if (wahl == '1')
									cout << "SET R2L2 ein";
								else if (wahl == '0')
									cout << "SET R2L2 aus";
								break;

							case 'z':
								break;

							default:
								cout << "Ungueltige Auswahl ... " << endl;
							}
						} while (wahl != 'z');
						break;

					case '3':
						do { // do while Lampenauswahl Raum 3
							cout << "Waehlen Sie eine Lampe fuer die Ansteuerung aus (Raum 3) " << endl;
							cout << "----------------------------------------------------" << endl;
							cout << "Lampe 1 \t(1)" << endl;
							cout << "Lampe 2\t(2)" << endl;
							cout << "Zurueck zur Raumauswahl \t\t\t\t(z)" << endl;
							cout << "----------------------------------------------------" << endl;
							cout << "Ihre Wahl: ";
							cin >> wahl;
							switch (wahl) {
							case '1':
								cout << "Wollen Sie in Raum 3 die Lampe 1 einschalten (1) oder ausschalten (2) ?" << endl;
								cout << "Ihre Wahl: ";
								cin >> wahl;
								if (wahl == '1')
									cout << "SET R3L1 ein";
								else if (wahl == '0')
									cout << "SET R3L1 aus";
								break;

							case '2':
								cout << "Wollen Sie in Raum 3 die Lampe 2 einschalten (1) oder ausschalten (2) ?" << endl;
								cout << "Ihre Wahl: ";
								cin >> wahl;
								if (wahl == '1')
									cout << "SET R3L2 ein";
								else if (wahl == '0')
									cout << "SET R3L2 aus";
								break;

							case 'z':
								break;

							default:
								cout << "Ungueltige Auswahl ... " << endl;
							}
						} while (wahl != 'z');
						break;

					case 'z':
						break;

					default:
						cout << "Ungueltige Auswahl ... " << endl;
					}
				} while (wahl != 'z');
				break;

			case 2: // Zurueck zum Hauptmenue
				exitAktorMenue = 1;
				break;
			}
		}

	} while (exitAktorMenue != 1);
}


 

