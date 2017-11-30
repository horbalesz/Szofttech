#ifndef FITNESSCENTRUM_H
#define FITNESSCENTRUM_H

#include <iostream>
#include <string>
#include <vector>

#include "orarend.h"
#include "levelezes.h"
#include "elorehaladas.h"

using namespace std;

class FitnessCentrum
{
    vector<Orarend*> teljesOrarend;
    vector<EloreHaladas*> teljesSportnaplo;
    Levelezes* teljesLevelezes;
public:
    FitnessCentrum();
    vector<Orarend*>& getTeljesOrarend();
    vector<EloreHaladas*>& getTeljesSportnaplo();
    void orarendekKiir();
    void latogatoMenu();
    void setTeljesOrarend(vector<Orarend*> p_orarend);
    void setTeljesSportnaplo(vector<EloreHaladas*> p_sportnaplo);
    void setTeljesLevelezes(Levelezes* p_levelek);
};

#endif // FITNESSCENTRUM_H
