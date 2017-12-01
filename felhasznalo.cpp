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

void Felhasznalo::levelIrasa(Levelezes *levelek) {
    cout << "Level irasa" << endl << "Cimzett kodja: ";
    int cimzett;
    cin >> cimzett;
    cout << "uzenet: (enterrel kuldes)" << endl;
    string uzi = "";
    while(uzi == "")
        getline(cin, uzi);
    levelek->levelHozzaadasa(new Level(id, cimzett, uzi));
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
