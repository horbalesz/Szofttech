#include "levelezes.h"

Levelezes::Levelezes()
{}

Levelezes::~Levelezes()
{
    for(auto &i: levelek)
        delete i;
}

void Levelezes::levelHozzaadasa(Level *hozzaadando) {
    levelek.push_back(hozzaadando);
}

vector<Level *> Levelezes::getLevelek()
{
    return levelek;
}
