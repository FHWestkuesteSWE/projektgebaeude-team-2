#include <iostream>
#include <cstdlib>
#include "UnitTest.h"

using namespace std;

void UnitTest::runUnitTest() {
    
    cout << "Start test with correct room" << endl;
    try {
        this->initCorrectRoom();
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }
    cout << "End test with correct room" << endl << endl;;



    cout << "Start test with wrong room" << endl;
    try {
        this->initWrongRoom();
    }
    catch (const char* msg) {
        cerr << msg << endl;
    }
    cout << "End test with wrong room" << endl;

}

UnitTest::UnitTest() {

    this->numOfFenster = 0;
    this->numOfLampe = 0;
    this->raum = new Raum();
    
}


UnitTest::~UnitTest() {
    delete raum;
}

void UnitTest::initCorrectRoom(){
   
    string lampeName[] = { "Mitte" };
    this->numOfLampe = sizeof(lampeName) / sizeof(lampeName[0]);
    string fensterName[] = { "links", "mitte", "rechts" };
    this->numOfFenster = sizeof(fensterName) / sizeof(fensterName[0]);

    this->raum = new Raum("RoomTestCorrect", fensterName, this->numOfFenster, lampeName, this->numOfLampe);
}

void UnitTest::initWrongRoom() {
    string lampeName[] = { "Mitte" };
    this->numOfLampe = 0; // sizeof(lampeName) / sizeof(lampeName[0]);

    string fensterName[] = { "links", "mitte", "rechts" };
    this->numOfFenster = sizeof(fensterName) / sizeof(fensterName[0]);

    this->raum = new Raum("RoomTestWrong", fensterName, this->numOfFenster, lampeName, this->numOfLampe);
}

