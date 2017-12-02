#ifndef FELHASZNALO_H
#define FELHASZNALO_H

#include "levelezes.h"
#include "idbox.h"

class Felhasznalo {
protected:
    int id, jelszo;
public:
    Felhasznalo(int jelszo);
    Felhasznalo(int id, int jelszo);
    virtual ~Felhasznalo();
    virtual void menu() =0;
    virtual int getType() const = 0;
    int getId() const;
    int getJelszo() const;
    void levelIrasa(Levelezes* levelek);
    void olvasatlanOlvasasa(Levelezes* levelek);
    void teljesOlvasasa(Levelezes* levelek);
};

#endif // FELHASZNALO_H
