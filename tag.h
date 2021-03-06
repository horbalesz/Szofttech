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
    Tag(int jelszo, const string &nev);
    Tag(int id, int jelszo, const string &nev);
    void menu();
    void edzesreFeliratkozas(vector<Orarend *> &edzesek, const vector<Felhasznalo*> felhasznalok);
    void edzesrolLeiratkozas(vector<Orarend*> &edzesek, const vector<Felhasznalo *> felhasznalok);
    void sajatEdzesekLekerdezese(const vector<Orarend*> &edzesek);
    void elorehaladasLekerdezese(vector<EloreHaladas*> &sportNaplo);
    void napiTevekenysegHozzaadasa(vector<EloreHaladas*> &sportNaplo);
    int getType() const;
};

#endif // TAG_H
