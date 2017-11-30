#ifndef TAG_H
#define TAG_H
#include "orarend.h"
#include "elorehaladas.h"
#include "felhasznalo.h"
using namespace std;

class Orarend;

class Tag: public Felhasznalo
{
    int cel;
public:
    Tag(int jelszo);
    Tag(int id, int jelszo);
    void menu();
    void edzesreFeliratkozas(vector<Orarend *> &edzesek);
    void edzesrolLeiratkozas(vector<Orarend*> &edzesek);
    void edzesekLekerdezese(const vector<Orarend*> &edzesek);
    void elorehaladasLekerdezese(vector<EloreHaladas*> &sportNaplo);
    void napiTevekenysegHozzaadasa(vector<EloreHaladas*> &sportNaplo);
    string getType() const;
};

#endif // TAG_H
