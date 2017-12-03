#include "tag.h"

Tag::Tag(int jelszo, const string &nev):
    Felhasznalo(jelszo, nev)
{}

Tag::Tag(int id, int jelszo, const string &nev):
    Felhasznalo(id, jelszo, nev)
{}

void Tag::menu() {
    cout << endl << "1 - Edzesek megjelenitese" << endl;
    cout << "2 - Sajat orarend megjelenitese" << endl;
    cout << "3 - Orara feliratkozas" << endl;
    cout << "4 - Orarol leiratkozas" << endl;
    cout << "5 - Napi tevekenyseg megadasa" << endl;
    cout << "6 - Elorehaladas lekerdezese" << endl;
    cout << "7 - Level kuldese" << endl;
    cout << "8 - Olvasatlan levelek olvasasa" << endl;
    cout << "9 - Osszes level olvasasa" << endl;
    cout << "10 - Kijelentkezes" << endl;
    cout << "x - Bezaras" << endl;
    cout << "Valasz: ";
}

void Tag::edzesreFeliratkozas(vector<Orarend*> &edzesek, const vector<Felhasznalo *> felhasznalok) {
    cout << "Adja meg az orat tarto edzo felhasznalonevet: ";
    string edzoNev;
    int edzoId;
    cin >> edzoNev;
    bool letezikEdzo = false;
    for(auto i : felhasznalok) {
        if(i->getFelhasznaloNev()==edzoNev) {
            edzoId = i->getId();
            letezikEdzo = true;
        }
    }
    if(letezikEdzo) {
        for(auto &i : edzesek) {
            if(i->getEdzoId() == edzoId) {
                i->felirOrara(id, edzesek, felhasznalok);
            }
        }
    } else {
        cout << "Nincs ilyen nevu edzo!" << endl;
    }
}

void Tag::edzesrolLeiratkozas(vector<Orarend*> &edzesek, const vector<Felhasznalo *> felhasznalok) {
    bool letezik = false;
    for(auto i : edzesek) {
        for(auto j : i->getOra()) {
            for(auto k : j->getFeliratkozottak()) {
                if(k == id) {
                    letezik=true;
                }
            }
        }
    }
    if(letezik == false) {
        cout << "On nincs feliratkozva orara." << endl;
    } else {
        cout << "Adja meg az orat tarto edzo felhasznalonevet: ";
        string edzoNev;
        int edzoId;
        cin >> edzoNev;
        bool letezikEdzo = false;
        for(auto i : felhasznalok) {
            if(i->getFelhasznaloNev()==edzoNev) {
                edzoId = i->getId();
                letezikEdzo = true;
            }
        }
        if(letezikEdzo) {
            for(auto &i : edzesek) {
                if(i->getEdzoId() == edzoId) {
                    i->leirOrarol(id);
                }
            }
        } else {
            cout << "Nincs ilyen nevu edzo!" << endl;
        }
    }
}

void Tag::sajatEdzesekLekerdezese(const vector<Orarend *> &edzesek)
{
    bool van = false;
    for(auto i : edzesek) {
        vector<Ora*> orak = i->getOra();
        for(auto j : orak) {
            vector<int> felirtak = j->getFeliratkozottak();
            for(auto k : felirtak) {
                if(k == id) {
                    cout << endl;
                    j->oraKiir();
                    cout << endl;
                    van=true;
                }
            }
        }
    }
    if(van == false) {
        cout << "Nincs feliratkozott ora" << endl;
    }
}

void Tag::elorehaladasLekerdezese(vector<EloreHaladas*> &sportNaplo) {
    for(auto &i : sportNaplo) {
        if(i->getTagID() == id)
            i->osszegez();
    }
}

void Tag::napiTevekenysegHozzaadasa(vector<EloreHaladas*> &sportNaplo) {
    for(auto &i : sportNaplo) {
        if(i->getTagID() == id)
            i->tevekenysegekHozzaadasa();
    }
}

int Tag::getType() const {
    return 3;
}
