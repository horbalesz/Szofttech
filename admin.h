#ifndef ADMIN_H
#define ADMIN_H

#include <vector>

#include "orarend.h"
#include "felhasznalo.h"
#include "edzo.h"

using namespace std;

class Admin: public Felhasznalo
{
public:
    Admin(int jelszo, string nev);
    Admin(int id, int jelszo, string nev);
    void menu();
    void edzoRegisztralasa(vector<Felhasznalo*> &felhasznalok, vector<Orarend *> &orarendek);
    void statisztikakLekerdezese(const vector<Orarend*> &edzesek, const vector<Felhasznalo*> &felhasznalok);
    int getType() const;
};

#endif // ADMIN_H
