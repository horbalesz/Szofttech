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
    bool van = false;
    for(auto it = levelek.begin();it != levelek.end();++it) {
        if((*it)->getCimzettID() == szemelyid && !((*it)->getOlvasott())) {
            (*it)->levelKiir();
            cout << endl;
            (*it)->setOlvasott();
            van = true;
        }
    }
    if(!van) {
        cout << endl << "----------------------------------------" << endl;
        cout << "Nincs olvasatlan levele." << endl;
        cout << "----------------------------------------" << endl;
    }
}

vector<Level *> Levelezes::getLevelek()
{
    return levelek;
}
