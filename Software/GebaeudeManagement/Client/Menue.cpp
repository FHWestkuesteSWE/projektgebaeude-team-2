#include "Menue.h"


Menue::Menue(string text, vector<string> items, int (*cb)(int)) {
	wahl = 0;
	position = 1;
	exitHauptmenue = 0;

	//client = clt;
	menueText = text;
	menueItems = items;
	maxLines = menueItems.size() + 1;

	callback = cb;
}

int Menue::Up() {
	do {
		system("cls");
		std::cout << "Gebauedeleitsystem FHW Team 2\n";
		cout << "Menue: " << endl;
		cout << menueText << endl;
		cout << "----------------------------------------------------" << endl;

		vector<string>::iterator i;
		int lineCount = 1;
		for (i = menueItems.begin(); i != menueItems.end(); i++)
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
			callback(position);
			break;
		}
	} while (exitHauptmenue != 1);

	return 0;
}

void Menue::selectionMarker(int position, int markerPosition)
{
	if (position == markerPosition)
		printf("--> ");
	else
		printf("    ");
}