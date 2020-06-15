#pragma once
#include <iostream>
#include "Client.h"
#include "conio.h"
#include <boost/algorithm/string.hpp> // split

using namespace std;
class Menue
{
private:
	void selectionMarker(int, int);
	char wahl;
	int position;
	int maxLines;
	int exitHauptmenue;
	string menueText;
	vector<string> menueItems;
	int (*callback)(int);
	static Client client;

public:
	Menue(string, vector<string>, int (*callback)(int));
	int Up();
};

