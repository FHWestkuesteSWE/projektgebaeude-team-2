// main.cpp : Diese Datei enthält die Funktion "main". Hier beginnt und endet die Ausführung des Programms.
//

#include <iostream>
#include "Client.h"

using namespace std;
int main(int argc, char* argv[])
{
    Client c(argv[1], argv[2]);
    char req[1024];
    char ans[1024];
    char wahl;
    do { // do while Hauptmenü:
        std::cout << "Gebauedeleitsystem FHW Team 2\n";
        cout << "Hauptmenue: " << endl;
		cout << "Was wollen Sie tun? " << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Sensor abfragen \t(s)" << endl;
        cout << "Aktoren ansteuern \t(a)" << endl;
        cout << "..." << endl;
        cout << "Beenden \t\t\t\t(e)" << endl;
        cout << "----------------------------------------------------" << endl;
        cout << "Ihre Wahl: ";
        cin >> wahl;
        switch (wahl) {
		case 's': 
			do { // do while Sensor-Menü
				cout << "Waehlen Sie einen Sensor aus " << endl;
				cout << "----------------------------------------------------" << endl;
				cout << "Temperatur-Sensor \t(t)" << endl;
				cout << "Kontakt-Sensor (Fenster) \t(k)" << endl;
				cout << "Zurueck zum Hauptmenue \t\t\t\t(z)" << endl;
				cout << "----------------------------------------------------" << endl;
				cout << "Ihre Wahl: ";
				cin >> wahl;
				switch (wahl) {
				case 't': 
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

				case 'k':
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

				case 'z':
					break;

				default:
					cout << "Ungueltige Auswahl ... " << endl;
				}
			} while (wahl != 'z');
			break;

		case 'a':
			do { // do while Aktor-Menü
				cout << "Waehlen Sie einen Aktor aus " << endl;
				cout << "----------------------------------------------------" << endl;
				cout << "Lampe \t(l)" << endl;
				cout << "Zurueck zum Hauptmenue \t\t\t\t(z)" << endl;
				cout << "----------------------------------------------------" << endl;
				cout << "Ihre Wahl: ";
				cin >> wahl;
				switch (wahl) {
				case 'l':
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

				case 'z':
					break;

				default:
					cout << "Ungueltige Auswahl ... " << endl;
				}
			} while (wahl != 'z');

        case 't': // req zusammenbauen
            strncpy_s(req, "get Temp", 10);
            c.sendRequest(req, ans);
            cout << ans << endl;
            break;

		case 'e':
			break;

        default:
			cout << "Ungueltige Auswahl ... " << endl;

        }
    } while (wahl != 'e');
}

