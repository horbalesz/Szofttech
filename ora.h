#ifndef ORA_H
#define ORA_H

#include <vector>
#include <iostream>

#include "idbox.h"

using namespace std;

class Ora
{
    int kezdEv, kezdHonap, kezdNap, kezdOra, kezdPerc, hossz, maxLetszam, id;
    vector<int> feliratkozottak;
    string sport;
public:
    Ora(int kezdEv, int kezdHonap, int kezdNap, int kezdOra, int kezdPerc, int hossz, int maxLetszam, const string &sport);
    Ora(int kezdEv, int kezdHonap, int kezdNap, int kezdOra, int kezdPerc, int hossz, int maxLetszam, int id, const string &sport);
    bool tele();
    int getId() const;
    void oraKiir();
    void feliratkoztat(int id);
    void leiratkoztat(int id);
    void setFeliratkozottak(const vector<int> &value);
    string oraMent();
    string feliratkozottakMent();
    vector<int> getFeliratkozottak() const;
    int getLetszam();
    string getSport() const;
    int getDatum() const;
};

#endif // ORA_H
