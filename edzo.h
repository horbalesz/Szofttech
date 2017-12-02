#ifndef EDZO_H
#define EDZO_H

#include "orarend.h"
#include "felhasznalo.h"

class Edzo: public Felhasznalo
{
public:
    Edzo(int jelszo);
    Edzo(int id, int jelszo);
    void menu();
    void oraHozzaadasa(vector<Orarend *> &orarendek);
    void oraTorlese(vector<Orarend *> &orarendek, Levelezes* levelezesek);
    void sajatOrarendMegtekintese(vector<Orarend*> &orarendek);
    int getType() const;
};

#endif // EDZO_H
