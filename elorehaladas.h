#ifndef ELOREHALADAS_H
#define ELOREHALADAS_H

#include <iostream>
#include<string>
#include<vector>

#include "napitevekenyseg.h"

using namespace std;

class EloreHaladas
{
    int tagID;
    int cel;
    vector<NapiTevekenyseg*> tevekenysegek;
public:
    EloreHaladas(int p_tagID, int p_cel);
    int getTagID();
    void tevekenysegekHozzaadasa();
    void osszegez();
    void tevekenysegBetoltese(NapiTevekenyseg *nt);
};

#endif // ELOREHALADAS_H
