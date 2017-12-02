#ifndef EDZO_H
#define EDZO_H

#include "orarend.h"
#include "felhasznalo.h"

class Edzo: public Felhasznalo
{
public:
    Edzo(int jelszo, string nev);
    Edzo(int id, int jelszo, string nev);
    void menu();
    void oraHozzaadasa(vector<Orarend *> &orarendek);
    void oraTorlese(vector<Orarend *> &orarendek);
    void sajatOrarendMegtekintese(vector<Orarend*> &orarendek);
    int getType() const;
};

#endif // EDZO_H
