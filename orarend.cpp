#include "orarend.h"

vector<Ora *> &Orarend::getOra()
{
    return ora;
}

Orarend::Orarend(int edzoId):
    edzoId(edzoId)
{}

void Orarend::orarendKiir() {
    cout << endl << edzoId << " azonositoju edzo orai:" << endl;
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

void Orarend::oraTorlese() {
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
        ora.erase(ora.begin()+holvan);
        cout << "Ora torolve." << endl;
    }
}

void Orarend::felirOrara(int id) {
    int oraID;
    cout << "(Feliratkozas) Add meg az ora azonositojat: ";
    cin >> oraID;
    for(auto &i : ora) {
        if(i->getId() == oraID)
            i->feliratkoztat(id);
    }
}

void Orarend::leirOrarol(int id) {
    int oraID;
    cout << "(Leiratkozas) Add meg az ora azonositojat: ";
    cin >> oraID;
    for(auto &i : ora) {
        if(i->getId() == oraID)
            i->leiratkoztat(id);
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
