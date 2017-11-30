#include "tag.h"

Tag::Tag(int jelszo):
    Felhasznalo(jelszo)
{

}

Tag::Tag(int id, int jelszo):
    Felhasznalo(id, jelszo)
{

}

void Tag::menu()
{
        cout << "1 - Orara feliratkozas" << endl;
        cout << "2 - Orarol leiratkozas" << endl;
        cout << "x - Kilepes" << endl;
        cout << "Valassz: ";
}

void Tag::edzesreFeliratkozas(vector<Orarend*> &edzesek)
{
    cout << "(Feliratkozas) Add meg az orat tarto edzo id-jet: ";
    int edzoId;
    cin >> edzoId;

    for(auto &i : edzesek) {
        if(i->getEdzoId() == edzoId)
            i->felirOrara(id);
    }

}

void Tag::edzesrolLeiratkozas(vector<Orarend*> &edzesek)
{
    cout << "(Leiratkozas) Add meg az orat tarto edzo id-jet: ";
    int edzoId;
    cin >> edzoId;

    for(auto &i : edzesek) {
        if(i->getEdzoId() == edzoId)
            i->leirOrarol(id);
    }
}

void Tag::elorehaladasLekerdezese(vector<EloreHaladas*> &sportNaplo)
{
    for(auto &i : sportNaplo) {
        if(i->getTagID() == id)
            i->osszegez();
    }
}

void Tag::napiTevekenysegHozzaadasa(vector<EloreHaladas*> &sportNaplo)
{
    for(auto &i : sportNaplo) {
        if(i->getTagID() == id)
            i->tevekenysegekHozzaadasa();
    }
}

string Tag::getType() const
{
    return "tag";
}
