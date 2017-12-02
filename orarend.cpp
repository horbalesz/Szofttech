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
    cout << "Szokozokkel elvalasztva adja meg az ora adatait(ev/ho/nap/ora/perc/hossz/maxmimalis letszam/sport)" << endl;
    stringstream ss;
    string line;
    getline(cin, line);

    ss << line;
    ss >> kezdEv >> kezdHo >> kezdNap >> kezdOra >> kezdPerc >> hossz >> maxLetszam >> sport;

    ora.push_back(new Ora(kezdEv, kezdHo, kezdNap, kezdOra, kezdPerc, hossz, maxLetszam, sport));

    cout << "Ora hozzaadva." << endl;
}

void Orarend::oraTorlese() {
    int id;

    cout << "Add meg a torolni kivant ora id-jet" << endl;
    cin >> id;
    bool kapcsolo = true;

    for(auto i = ora.begin(); i != ora.end(); ++i) {
        if((*i)->getId() == id) {
            delete *i;
            ora.erase(i);
            kapcsolo = false;
        }
    }

    if(kapcsolo)
        cout << "Ilyen ora nincs." << endl;
    else
        cout << "Ora torolve." << endl;

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
