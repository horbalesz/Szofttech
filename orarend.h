#ifndef ORAREND_H
#define ORAREND_H
#include "tag.h"
#include "ora.h"
#include "idbox.h"
#include <sstream>
using namespace std;

class Ora;
class Tag;

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
    void setEdzoId(int value);
    int orakSzama();
    void oraBetoltes(Ora* o);
};

#endif // ORAREND_H
