#ifndef EDZO_H
#define EDZO_H

#include "orarend.h"
#include "felhasznalo.h"

class Edzo: public Felhasznalo
{
public:
    Edzo(int jelszo, const string &nev);
    Edzo(int id, int jelszo, const string &nev);
    void menu();
    void oraHozzaadasa(vector<Orarend *> &orarendek);
    void oraTorlese(vector<Orarend *> &orarendek, Levelezes* levelezesek);
    void sajatOrarendMegtekintese(const vector<Orarend*> &orarendek, const vector<Felhasznalo*> &felhasznalok);
    int getType() const;
};

#endif // EDZO_H
