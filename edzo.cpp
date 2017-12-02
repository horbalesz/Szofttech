#include "edzo.h"

Edzo::Edzo(int jelszo, string nev):
    Felhasznalo(jelszo, nev)
{}

Edzo::Edzo(int id, int jelszo, string nev):
    Felhasznalo(id, jelszo, nev)
{}

void Edzo::menu() {
    cout << endl << "1 - Sajat orarend megtekintese" << endl;
    cout << "2 - Ora hozzaadasa" << endl;
    cout << "3 - Ora torlese" << endl;
    cout << "4 - Level kuldese" << endl;
    cout << "5 - Olvasatlan levelek olvasasa" << endl;
    cout << "6 - Osszes level olvasasa" << endl;
    cout << "7 - Kijelentkezes" << endl;
    cout << "x - Bezaras" << endl;
    cout << "Valasz: ";
}

void Edzo::oraHozzaadasa(vector<Orarend*> &orarendek) {
    for(auto &i : orarendek) {
        if(i->getEdzoId() == id)
            i->oraHozzaadasa();
    }
}

void Edzo::oraTorlese(vector<Orarend*> &orarendek, Levelezes *levelezesek) {
    for(auto &i : orarendek) {
        if(i->getEdzoId() == id)
            i->oraTorlese(levelezesek);
    }
}

void Edzo::sajatOrarendMegtekintese(vector<Orarend*> &orarendek) {
    for(auto &i : orarendek) {
        if(i->getEdzoId() == id)
            i->orarendKiir();
    }
}

int Edzo::getType() const {
    return 2;
}
