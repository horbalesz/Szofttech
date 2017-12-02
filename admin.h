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
    Admin(int jelszo);
    Admin(int id, int jelszo);
    void menu();
    void edzoRegisztralasa(vector<Felhasznalo*> &felhasznalok);
    void statisztikakLekerdezese(const vector<Orarend*> &edzesek, const vector<Felhasznalo*> &felhasznalok);
    int getType() const;
};

#endif // ADMIN_H
