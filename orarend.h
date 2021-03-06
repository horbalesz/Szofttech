#ifndef ORAREND_H
#define ORAREND_H

#include <sstream>

#include "felhasznalo.h"
#include "levelezes.h"
#include "ora.h"

using namespace std;

class Orarend
{
    int edzoId;
    vector<Ora*> ora;
public:
    Orarend(int edzoId);
    ~Orarend();
    void orarendKiir(const vector<Felhasznalo*> felhasznalok);
    void oraHozzaadasa();
    void oraTorlese(Levelezes *levelezesek);
    void felirOrara(int id, const vector<Orarend *> &edzesek, vector<Felhasznalo *> felhasznalok);
    void leirOrarol(int id);
    int getEdzoId() const;
    int orakSzama();
    void setEdzoId(int value);
    void oraBetoltes(Ora* o);
    vector<Ora *> &getOra();
};

#endif // ORAREND_H
