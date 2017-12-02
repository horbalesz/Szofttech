#include "orarend.h"

vector<Ora *> &Orarend::getOra()
{
    return ora;
}

Orarend::Orarend(int edzoId):
    edzoId(edzoId)
{}

void Orarend::orarendKiir(const vector<Felhasznalo*> felhasznalok) {
    string edzoNev;
    for(auto i : felhasznalok) {
        if(i->getId()==edzoId) {
            edzoNev = i->getFelhasznaloNev();
        }
    }
    cout << endl << edzoNev + " edzo orai:" << endl;
    for(auto i : ora)
    {
        i->oraKiir();
        cout << endl;
    }
}

void Orarend::oraHozzaadasa() {

    int kezdEv, kezdHo, kezdNap, kezdOra, kezdPerc, hossz, maxLetszam;
    string sport;
    cout << "Adja meg az evet: ";
    cin >> kezdEv;
    cout << "Adja meg a honapot: ";
    cin >> kezdHo;
    cout << "Adja meg a napot: ";
    cin >> kezdNap;
    cout << "Adja meg az orat: ";
    cin >> kezdOra;
    cout << "Adja meg a percet: ";
    cin >> kezdPerc;
    cout << "Adja meg az ora hosszat percben: ";
    cin >> hossz;
    cout << "Adja meg a max letszamot: ";
    cin >> maxLetszam;
    cout << "Adja meg a sportagat: ";
    cin >> sport;
    ora.push_back(new Ora(kezdEv, kezdHo, kezdNap, kezdOra, kezdPerc, hossz, maxLetszam, sport));
    cout << "Ora hozzaadva." << endl;
}

void Orarend::oraTorlese(Levelezes* levelezesek) {
    int id;
    cout << "Add meg a torolni kivant ora id-jet" << endl;
    cin >> id;
    bool kapcsolo = true;
    int holvan;
    for(unsigned int i =0; i<ora.size(); ++i) {
        if(ora[i]->getId() == id) {
            kapcsolo = false;
            holvan = i;
        }
    }
    if(kapcsolo)
        cout << "Ilyen ora nincs." << endl;
    else {
        vector<int> fel_tmp = ora[holvan]->getFeliratkozottak();
        for(auto i :fel_tmp) {
            levelezesek->levelHozzaadasa(new Level(edzoId, i,"Elnezest, a(z) " + to_string(ora[holvan]->getId()) + " azonositoju ora torlesre kerult."));
        }
        ora.erase(ora.begin()+holvan);
        cout << "Ora torolve." << endl;
    }
}

void Orarend::felirOrara(int id) {
    int oraID;
    cout << "Add meg az ora azonositojat: ";
    cin >> oraID;
    bool letezikOra = false;
    for(auto &i : ora) {
        if(i->getId() == oraID) {
            i->feliratkoztat(id);
            letezikOra = true;
        }
    }
    if(!letezikOra) {
        cout << "Nincs ilyen ora!" << endl;
    }
}

void Orarend::leirOrarol(int id) {
    int oraID;
    cout << "Add meg az ora azonositojat: ";
    cin >> oraID;
    bool letezikOra = false;
    for(auto &i : ora) {
        if(i->getId() == oraID) {
            i->leiratkoztat(id);
            letezikOra=true;
        }
    }
    if(!letezikOra) {
        cout << "Nincs ilyen ora!" << endl;
    }
}

int Orarend::getEdzoId() const {
    return edzoId;
}

int Orarend::orakSzama() {
    return (int)ora.size();
}

void Orarend::oraBetoltes(Ora *o) {
    ora.push_back(o);
}

void Orarend::setEdzoId(int value) {
    edzoId = value;
}
