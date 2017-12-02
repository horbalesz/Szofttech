#include "felhasznalo.h"

Felhasznalo::Felhasznalo(int jelszo):
    id(IdBox::getInstance().giveId()), jelszo(jelszo)
{}

Felhasznalo::Felhasznalo(int id, int jelszo):
    id(id), jelszo(jelszo)
{}

Felhasznalo::~Felhasznalo()
{}

int Felhasznalo::getId() const {
    return id;
}

int Felhasznalo::getJelszo() const {
    return jelszo;
}

void Felhasznalo::levelIrasa(Levelezes *levelek,  vector<Felhasznalo *> &felhasznalok) {
    cout << "Level irasa" << endl << "Cimzett kodja: ";
    int cimzett;
    cin >> cimzett;
    bool letezik = 0;
    for(auto i : felhasznalok) {
        if(i->getId()==cimzett) {
            letezik = true;
        }
    }
    if(letezik) {
        cout << "uzenet: (enterrel kuldes)" << endl;
        string uzi = "";
        while(uzi == "")
            getline(cin, uzi);
        levelek->levelHozzaadasa(new Level(id, cimzett, uzi));
        cout << "Level kuldese sikeres." << endl;
    } else {
        cout << "Nincs ilyen felhasznalo!" << endl;
    }
}

void Felhasznalo::olvasatlanOlvasasa(Levelezes *levelek) {
    cout << endl;
    levelek->olvasatlanKiirasa(id);
    cout << endl;
}

void Felhasznalo::teljesOlvasasa(Levelezes *levelek) {
    cout << endl;
    levelek->levelezesKiirasa(id);
    cout << endl;
}
