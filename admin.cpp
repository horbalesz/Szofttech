#include "admin.h"

Admin::Admin(int jelszo):
    Felhasznalo(jelszo)
{

}

Admin::Admin(int id, int jelszo):
    Felhasznalo(id, jelszo)
{

}

void Admin::menu()
{
        cout << "1 - Edzok regisztralasa" << endl;
        cout << "2 - Statisztikak lekerdezese" << endl;
        cout << "x - Kilepes" << endl;
        cout << "Valassz: ";
}

void Admin::edzoRegisztralasa(vector<Felhasznalo*> &felhasznalok)
{
    cout << "Az uj edzo jelszava: ";
    int jelszo;
    cin >> jelszo;

    felhasznalok.push_back(new Edzo(jelszo));
}

void Admin::statisztikakLekerdezese(const vector<Orarend*> &edzesek, const vector<Felhasznalo *> &felhasznalok)
{
    int tagCounter=0, edzoCounter=0;

    for(auto i : felhasznalok) {
        if(i->getType() == "tag")
            tagCounter++;
        else if(i->getType() == "edzo")
            edzoCounter++;
    }

    cout << "Regisztrált tagok száma: " << tagCounter << endl;
    cout << "Regisztrált edzők száma: " << edzoCounter << endl;

    int oraCounter=0;
    for(auto i : edzesek) {
        oraCounter+=i->orakSzama();
    }

    cout << "Osszes orak szama: " << oraCounter << endl;
}

string Admin::getType() const
{
    return "admin";
}
