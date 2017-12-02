#include "levelezes.h"

Levelezes::Levelezes()
{}

void Levelezes::levelHozzaadasa(Level *hozzaadando) {
    levelek.push_back(hozzaadando);
}

vector<Level *> Levelezes::getLevelek()
{
    return levelek;
}
