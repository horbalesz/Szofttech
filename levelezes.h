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
    ~Levelezes();
    void levelHozzaadasa(Level* hozzaadando);
    vector<Level*> getLevelek();
};

#endif // LEVELEZES_H
