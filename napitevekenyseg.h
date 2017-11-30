#ifndef NAPITEVEKENYSEG_H
#define NAPITEVEKENYSEG_H

#include <iostream>
#include <string>

using namespace std;

class NapiTevekenyseg
{
    string sport;
    int idotartam, ev, honap, nap, suly;
public:
    NapiTevekenyseg(string& p_sport, int p_idotartam, int p_ev, int p_honap, int p_nap, int p_suly);
    string getSport();
    int getIdotartam();
    int getSuly();
    bool datumEllenoriz(int p_ev, int p_honap, int p_nap);
    string getDatum();
    void tevekenysegKiir();
};

#endif // NAPITEVEKENYSEG_H
