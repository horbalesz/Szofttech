#include "napitevekenyseg.h"

NapiTevekenyseg::NapiTevekenyseg(string &p_sport, int p_idotartam, int p_ev, int p_honap, int p_nap, int p_suly):
    sport(p_sport),
    idotartam(p_idotartam),
    ev(p_ev),
    honap(p_honap),
    nap(p_nap),
    suly(p_suly)
{}

string NapiTevekenyseg::getSport() {
    return sport;
}

int NapiTevekenyseg::getIdotartam() {
    return idotartam;
}

int NapiTevekenyseg::getSuly() {
    return suly;
}

bool NapiTevekenyseg::datumEllenoriz(int p_ev, int p_honap, int p_nap) {
    if((p_ev==ev) && (p_honap==honap) && (p_nap==nap)) {
        return true;
    } else {
        return false;
    }
}

string NapiTevekenyseg::getDatum() {
    string datum;
    datum = to_string(ev) + "." + to_string(honap) + "." + to_string(nap);
    return datum;
}

void NapiTevekenyseg::tevekenysegKiir() {
    cout << "Datum: " << getDatum() << endl;
    cout << "Sport: " << getSport() << endl;
    cout << "Idotartam" << getIdotartam() << endl;
}
