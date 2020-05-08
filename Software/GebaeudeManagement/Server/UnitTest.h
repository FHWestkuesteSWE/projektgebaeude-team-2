#pragma once

#include <string>
#include "Raum.h"

class UnitTest : public Raum {
private:
    Raum* raum;
    string name;
    unsigned int numOfFenster;
    unsigned int numOfLampe;
public:

    void initCorrectRoom();
    void initWrongRoom();

    void runUnitTest();
    UnitTest();
    ~UnitTest();


};

