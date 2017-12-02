#include "admin.h"

Admin::Admin(int jelszo, string nev):
    Felhasznalo(jelszo, nev)
{}

Admin::Admin(int id, int jelszo, string nev):
    Felhasznalo(id, jelszo, nev)
{}

void Admin::menu() {
        cout << endl << "1 - Edzok regisztralasa" << endl;
        cout << "2 - Statisztikak lekerdezese" << endl;
        cout << "3 - Level kuldese" << endl;
        cout << "4 - Olvasatlan levelek olvasasa" << endl;
        cout << "5 - Osszes level olvasasa" << endl;
        cout << "6 - Kijelenetkezes" << endl;
        cout << "x - Bezaras" << endl;
        cout << "Valasz: ";
}

void Admin::edzoRegisztralasa(vector<Felhasznalo*> &felhasznalok) {
    int jelszo;
    string felhaszNev;
    cout << "Az uj edzo jelszava: ";
    cin >> jelszo;
    cout << "Az uj edzo felhasznalo neve: ";
    cin >> felhaszNev;
    Edzo* uj = new Edzo(jelszo, felhaszNev);
    felhasznalok.push_back(uj);
    cout << "Uj edzo sikeresen regisztralva: " << endl;
    cout << "Azonosito: " << uj->getId() << endl;
    cout << "Jelszo: " << uj->getJelszo() << endl;
}

void Admin::statisztikakLekerdezese(const vector<Orarend*> &edzesek, const vector<Felhasznalo *> &felhasznalok) {
    int tagCounter=0, edzoCounter=0;

    for(auto i : felhasznalok) {
        if(i->getType() == 3)
            tagCounter++;
        else if(i->getType() == 2)
            edzoCounter++;
    }

    cout << "Regisztralt tagok szama: " << tagCounter << endl;
    cout << "Regisztralt edzok szama: " << edzoCounter << endl;

    int oraCounter=0;
    for(auto i : edzesek) {
        oraCounter+=i->orakSzama();
    }

    cout << "Osszes orak szama: " << oraCounter << endl;
}

int Admin::getType() const {
    return 1;
}
