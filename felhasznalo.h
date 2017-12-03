#ifndef FELHASZNALO_H
#define FELHASZNALO_H

#include "levelezes.h"
#include "idbox.h"

class Felhasznalo {
protected:
    int id, jelszo;
    string felhasznaloNev;
public:
    Felhasznalo(int jelszo, const string &nev);
    Felhasznalo(int id, int jelszo, const string &nev);
    virtual ~Felhasznalo();
    virtual void menu() =0;
    virtual int getType() const = 0;
    int getId() const;
    int getJelszo() const;
    string getFelhasznaloNev() const;
    void levelIrasa(Levelezes* levelek,  vector<Felhasznalo*> &felhasznalok);
    void olvasatlanOlvasasa(Levelezes* levelek, vector<Felhasznalo*> &felhasznalok);
    void teljesOlvasasa(Levelezes* levelek, vector<Felhasznalo*> &felhasznalok);
};

#endif // FELHASZNALO_H
