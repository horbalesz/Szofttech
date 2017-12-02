#include "edzo.h"

Edzo::Edzo(int jelszo):
    Felhasznalo(jelszo)
{}

Edzo::Edzo(int id, int jelszo):
    Felhasznalo(id, jelszo)
{}

void Edzo::menu() {
    cout << endl << "1 - Sajat orarend megtekintese" << endl;
    cout << "2 - Ora hozzaadasa" << endl;
    cout << "3 - Ora torlese" << endl;
    cout << "4 - Level kuldese" << endl;
    cout << "5 - Olvasatlan levelek olvasasa" << endl;
    cout << "6 - Osszes level olvasasa" << endl;
    cout << "x - Kilepes" << endl;
    cout << "Valasz: ";
}

void Edzo::oraHozzaadasa(vector<Orarend*> &orarendek) {
    for(auto &i : orarendek) {
        if(i->getEdzoId() == id)
            i->oraHozzaadasa();
    }
}

void Edzo::oraTorlese(vector<Orarend*> &orarendek) {
    for(auto &i : orarendek) {
        if(i->getEdzoId() == id)
            i->oraTorlese();
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
