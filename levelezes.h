#ifndef LEVELEZES_H
#define LEVELEZES_H

#include <iostream>
#include <vector>

#include "level.h"

using namespace std;

class Levelezes
{
    vector<Level*> levelek;
public:
    Levelezes();
    void levelHozzaadasa(Level* hozzaadando);
    void levelezesKiirasa(int szemelyid) const;
    void olvasatlanKiirasa(int szemelyid) const;
    vector<Level*> getLevelek();
};

#endif // LEVELEZES_H
