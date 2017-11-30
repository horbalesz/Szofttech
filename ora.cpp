#include "ora.h"

Ora::Ora(int kezdEv, int kezdHonap, int kezdNap, int kezdOra, int kezdPerc, int hossz, int maxLetszam, int id, const string &sport):
    kezdEv(kezdEv), kezdHonap(kezdHonap), kezdNap(kezdNap), kezdOra(kezdOra), kezdPerc(kezdPerc), hossz(hossz), maxLetszam(maxLetszam), id(id), sport(sport)
{

}

bool Ora::tele()
{
    if((int)feliratkozottak.size() == maxLetszam)
        return true;
    else
        return false;
}

int Ora::getId() const
{
    return id;
}

void Ora::oraKiir()
{
    cout << "Ora adatai: " << endl;
    cout << "Idopont: " << kezdEv << ". " << kezdHonap << ". " << kezdNap << "." << endl;
    cout << "Kezdes: " << kezdOra << ":" << kezdPerc << endl;
    cout << "Hossza: " << hossz << " perc" << endl;
    cout << "Szabad helyek szama: " << maxLetszam-feliratkozottak.size() << endl;
}

void Ora::feliratkoztat(int id)
{
    bool vane=false;
    for(auto i: feliratkozottak)
    {
        if(i == id)
            vane=true;
    }

    if(vane)
        cout << "Mar fel vagy iratkozva erre az orara!" << endl;
    else
        feliratkozottak.push_back(id);
}

void Ora::leiratkoztat(int id)
{
    int holvan=-1;
    int i=0;
    for(auto j: feliratkozottak)
    {
        if(j == id)
            holvan=i;
        i++;
    }

    if(holvan!=-1)
        feliratkozottak.erase(feliratkozottak.begin()+holvan); //potenciális hiba
    else
        cout << "Nem is vagy feliratkozva erre az orara!" << endl;
}
