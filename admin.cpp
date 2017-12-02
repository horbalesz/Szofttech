#include "admin.h"

Admin::Admin(int jelszo):
    Felhasznalo(jelszo)
{}

Admin::Admin(int id, int jelszo):
    Felhasznalo(id, jelszo)
{}

void Admin::menu() {
        cout << endl << "1 - Edzok regisztralasa" << endl;
        cout << "2 - Statisztikak lekerdezese" << endl;
        cout << "3 - Level kuldese" << endl;
        cout << "4 - Olvasatlan levelek olvasasa" << endl;
        cout << "5 - Osszes level olvasasa" << endl;
        cout << "x - Kilepes" << endl;
        cout << "Valasz: ";
}

void Admin::edzoRegisztralasa(vector<Felhasznalo*> &felhasznalok) {
    cout << "Az uj edzo jelszava: ";
    int jelszo;
    cin >> jelszo;
    felhasznalok.push_back(new Edzo(jelszo));
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
