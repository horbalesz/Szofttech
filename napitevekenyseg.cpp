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

int NapiTevekenyseg::getSportType()
{
    if(sport == "pilates")
        return 0;
    else if(sport == "aerobic")
        return 1;
    else
        return 2; // kangoo
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
    return to_string(ev) + "." + to_string(honap) + "." + to_string(nap);
}

void NapiTevekenyseg::tevekenysegKiir() {
    cout << "Datum: " << getDatum() << endl;
    cout << "Sport: " << sport << endl;
    cout << "Idotartam: " << idotartam << endl;
    int kaloria;
    switch(getSportType()) {
    case 0: kaloria=225*((double)idotartam/60); break;
    case 1: kaloria=430*((double)idotartam/60); break;
    case 2: kaloria=530*((double)idotartam/60); break;
    }
    cout << "Elegetett kaloria: " << kaloria << endl;
}

string NapiTevekenyseg::tevekenysegMent()
{
    return to_string(ev) + " " + to_string(honap) + " " + to_string(nap) + " " + to_string(idotartam) + " " + to_string(suly) + " " + sport + "\n";
}
