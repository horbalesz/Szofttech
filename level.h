#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include <iostream>

using namespace std;

class Level
{
    int kuldoID;
    int cimzettID;
    int levelID;
    string uzenet;
    bool olvasott;
public:
    Level(int kuldo, int cimzett, string p_uzenet);
    int getKuldoID();
    int getCimzettID();
    void setOlvasott();
    void levelKiir();
    bool getOlvasott();
};

#endif // LEVEL_H
