#include "levelezes.h"

Levelezes::Levelezes()
{}

void Levelezes::levelHozzaadasa(Level *hozzaadando) {
    levelek.push_back(hozzaadando);
}

void Levelezes::levelezesKiirasa(int szemelyid) const {
    for(auto it = levelek.begin();it != levelek.end();++it) {
        if((*it)->getCimzettID() == szemelyid || (*it)->getKuldoID() == szemelyid) {
            (*it)->levelKiir();
            cout << endl;
        }
    }
}

void Levelezes::olvasatlanKiirasa(int szemelyid) const
{
    for(auto it = levelek.begin();it != levelek.end();++it) {
        if(((*it)->getCimzettID() == szemelyid || (*it)->getKuldoID() == szemelyid) && !((*it)->getOlvasott())) {
            (*it)->levelKiir();
            cout << endl;
            (*it)->setOlvasott();
        }
    }
}

vector<Level *> Levelezes::getLevelek()
{
    return levelek;
}
