#include "ora.h"

void Ora::setFeliratkozottak(const vector<int> &value)
{
    feliratkozottak = value;
}

string Ora::oraMent()
{
    return to_string(kezdEv) + " " + to_string(kezdHonap) + " " + to_string(kezdNap) + " " + to_string(kezdOra) + " " + to_string(kezdPerc) + " " + to_string(hossz) + " " + to_string(maxLetszam) + " " + sport + " " + to_string(id);
}

string Ora::feliratkozottakMent()
{
    string str = to_string(id) + "\n";
    for(auto i : feliratkozottak) {
        str += to_string(i) + "\n";
    }
    return str;
}

vector<int> Ora::getFeliratkozottak() const
{
    return feliratkozottak;
}

Ora::Ora(int kezdEv, int kezdHonap, int kezdNap, int kezdOra, int kezdPerc,
         int hossz, int maxLetszam, const string &sport):
    kezdEv(kezdEv),
    kezdHonap(kezdHonap),
    kezdNap(kezdNap),
    kezdOra(kezdOra),
    kezdPerc(kezdPerc),
    hossz(hossz),
    maxLetszam(maxLetszam),
    id(IdBox::getInstance().giveId()),
    sport(sport)
{}

Ora::Ora(int kezdEv, int kezdHonap, int kezdNap, int kezdOra, int kezdPerc, int hossz, int maxLetszam, int id, const string &sport):
    kezdEv(kezdEv),
    kezdHonap(kezdHonap),
    kezdNap(kezdNap),
    kezdOra(kezdOra),
    kezdPerc(kezdPerc),
    hossz(hossz),
    maxLetszam(maxLetszam),
    id(id),
    sport(sport)
{}

bool Ora::tele() {
    if((int)feliratkozottak.size() == maxLetszam)
        return true;
    else
        return false;
}

int Ora::getId() const {
    return id;
}

void Ora::oraKiir() {
    cout << "Ora adatai: " << endl;
    cout << "OraID: " << id << endl;
    cout << "Idopont: " << kezdEv << ". " << kezdHonap << ". " << kezdNap << "." << endl;
    cout << "Kezdes: " << kezdOra << ":" << kezdPerc << endl;
    cout << "Hossza: " << hossz << " perc" << endl;
    cout << "Szabad helyek szama: " << maxLetszam-feliratkozottak.size() << endl;
}

void Ora::feliratkoztat(int id) {
    bool vane=false;
    for(auto i: feliratkozottak) {
        if(i == id)
            vane=true;
    }

    if(vane)
        cout << "Mar fel vagy iratkozva erre az orara!" << endl;
    else {
        feliratkozottak.push_back(id);
        cout << "Feliratkozas sikeres." << endl;
    }
}

void Ora::leiratkoztat(int id) {
    int holvan=-1;
    int i=0;
    for(auto j: feliratkozottak) {
        if(j == id)
            holvan=i;
        i++;
    }

    if(holvan!=-1)
        feliratkozottak.erase(feliratkozottak.begin()+holvan); //potenciális hiba
    else
        cout << "Nem is vagy feliratkozva erre az orara!" << endl;
}
