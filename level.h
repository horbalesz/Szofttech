#ifndef LEVEL_H
#define LEVEL_H

#include <string>
#include <iostream>

#include "idbox.h"

using namespace std;

class Level
{
    int kuldoID;
    int cimzettID;
    int levelID;
    string uzenet;
    bool olvasott;
public:
    Level(int kuldo, int cimzett, const string &p_uzenet);
    Level(int kuldo, int cimzett, const string &p_uzenet, bool p_olvasott);
    int getKuldoID();
    int getCimzettID();
    void setOlvasott();
    void levelKiir();
    bool getOlvasott();
    string getUzenet() const;
};

#endif // LEVEL_H
