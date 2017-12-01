#ifndef ORAREND_H
#define ORAREND_H
//#include "tag.h"

#include <sstream>

#include "ora.h"

using namespace std;

class Orarend
{
    int edzoId;
    vector<Ora*> ora;
public:
    Orarend(int edzoId);
    void orarendKiir();
    void oraHozzaadasa();
    void oraTorlese();
    void felirOrara(int id);
    void leirOrarol(int id);
    int getEdzoId() const;
    int orakSzama();
    void setEdzoId(int value);
    void oraBetoltes(Ora* o);
    vector<Ora *> &getOra();
};

#endif // ORAREND_H
