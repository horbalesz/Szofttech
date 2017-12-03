#ifndef FITNESSCENTRUM_H
#define FITNESSCENTRUM_H

#include <iostream>
#include <string>
#include <vector>

#include "orarend.h"
#include "levelezes.h"
#include "elorehaladas.h"
#include "tag.h"
#include "admin.h"
#include "edzo.h"

using namespace std;

class FitnessCentrum
{
    vector<Orarend*> teljesOrarend;
    vector<EloreHaladas*> teljesSportnaplo;
    vector<Felhasznalo*> felhasznalok;
    Felhasznalo* bejelentkezettFelhasznalo;
    Levelezes* teljesLevelezes;
public:
    FitnessCentrum();
    ~FitnessCentrum();
    vector<Orarend*>& getTeljesOrarend();
    vector<EloreHaladas*>& getTeljesSportnaplo();
    vector<Felhasznalo*>& getFelhasznalok();
    Levelezes* getTeljesLevelezes();
    void orarendekKiir();
    void latogatoMenu();
    void setTeljesOrarend(vector<Orarend *> &p_orarend);
    void setTeljesSportnaplo(vector<EloreHaladas*> &p_sportnaplo);
    void setTeljesLevelezes(Levelezes* p_levelek);
    void setFelhasznalok(vector<Felhasznalo *> &p_felhasznalok);
    void bejelentkezes();
    void regisztracio();
    void vegrehajt(int cmd);
    void start();
    void kijelentkezes();

};

#endif // FITNESSCENTRUM_H
