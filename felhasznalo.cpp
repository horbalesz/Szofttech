#include "felhasznalo.h"

Felhasznalo::Felhasznalo(int jelszo, const string &nev):
    id(IdBox::getInstance().giveId()),
    jelszo(jelszo),
    felhasznaloNev(nev)
{}

Felhasznalo::Felhasznalo(int id, int jelszo,const string &nev):
    id(id),
    jelszo(jelszo),
    felhasznaloNev(nev)
{}

Felhasznalo::~Felhasznalo()
{}

int Felhasznalo::getId() const {
    return id;
}

int Felhasznalo::getJelszo() const {
    return jelszo;
}

string Felhasznalo::getFelhasznaloNev() const {
    return felhasznaloNev;
}

void Felhasznalo::levelIrasa(Levelezes *levelek,  vector<Felhasznalo *> &felhasznalok) {
    cout << "Level irasa" << endl << "Cimzett felhasznalo neve: ";
    string cimzett;
    cin >> cimzett;
    int cimzettID;
    bool letezik = 0;
    for(auto i : felhasznalok) {
        if(i->getFelhasznaloNev()==cimzett) {
            cimzettID = i->getId();
            letezik = true;
        }
    }
    if(letezik) {
        cout << "uzenet: (enterrel kuldes)" << endl;
        string uzi = "";
        while(uzi == "")
            getline(cin, uzi);
        levelek->levelHozzaadasa(new Level(id, cimzettID, uzi));
        cout << "Level kuldese sikeres." << endl;
    } else {
        cout << "Nincs ilyen felhasznalo!" << endl;
    }
}

void Felhasznalo::olvasatlanOlvasasa(Levelezes *levelek, vector<Felhasznalo *> &felhasznalok) {
    cout << endl;
    bool letezik = false;
    for(auto i : levelek->getLevelek()) {
        if(i->getCimzettID()==id && !(i->getOlvasott())) {
            letezik = true;
            i->setOlvasott();
            int feladoID = i->getKuldoID();
            string feladoNev;
            for(auto j : felhasznalok) {
                if(j->getId()==feladoID) {
                    feladoNev =j->getFelhasznaloNev();
                }
            }
            cout << "Felado: " + feladoNev << endl;
            cout << "Cimzett: " + felhasznaloNev << endl;
            cout << "Uzenet: " << endl << i->getUzenet() << endl << endl;
        }
    }
    if(!letezik) {
        cout << "Nincs olvasatlan levele." << endl;
    }
    cout << endl;
}

void Felhasznalo::teljesOlvasasa(Levelezes *levelek, vector<Felhasznalo *> &felhasznalok) {
    cout << endl;
    bool letezik = false;
    for(auto i : levelek->getLevelek()) {
        if(i->getCimzettID()==id || i->getKuldoID()==id) {
            i->setOlvasott();
            int kuldoID = i->getKuldoID(), cimzettID = i-> getCimzettID();
            string cimzett, kuldo;
            for(auto j :felhasznalok) {
                if(j->getId()==kuldoID) {
                    kuldo = j->getFelhasznaloNev();
                } else if(j->getId()==cimzettID) {
                    cimzett = j->getFelhasznaloNev();
                }
            }
            letezik = true;
            cout << "Felado: " + kuldo << endl;
            cout << "Cimzett: " + cimzett << endl;
            cout << "Uzenet: " << endl << i->getUzenet() << endl << endl;
        }
    }
    if(!letezik) {
        cout << "Onnek nincs levele." << endl;
    }
    cout << endl;
}
