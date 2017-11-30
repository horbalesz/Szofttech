#include "edzo.h"

Edzo::Edzo(int jelszo):
    Felhasznalo(jelszo)
{

}

Edzo::Edzo(int id, int jelszo):
    Felhasznalo(id, jelszo)
{

}

void Edzo::menu()
{
    cout << "1 - Sajat orarend megtekintese" << endl;
    cout << "2 - Ora hozzaadasa" << endl;
    cout << "3 - Ora torlese" << endl;
    cout << "x - Kilepes" << endl;
    cout << "Valassz: ";
}

void Edzo::oraHozzaadasa(vector<Orarend*> &orarendek)
{
    for(auto &i : orarendek)
    {
        if(i->getEdzoId() == id)
            i->oraHozzaadasa();
    }
}

void Edzo::oraTorlese(vector<Orarend*> &orarendek)
{
    for(auto &i : orarendek)
    {
        if(i->getEdzoId() == id)
            i->oraTorlese();
    }
}

void Edzo::sajatOrarendMegtekintese(vector<Orarend*> &orarendek)
{
    for(auto &i : orarendek)
    {
        if(i->getEdzoId() == id)
            i->orarendKiir();
    }
}

string Edzo::getType() const
{
    return "edzo";
}
