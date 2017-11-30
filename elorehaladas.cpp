#include "elorehaladas.h"

EloreHaladas::EloreHaladas(int p_tagID, int p_cel):
    tagID(p_tagID), cel(p_cel)
{}

int EloreHaladas::getTagID() {
    return tagID;
}

void EloreHaladas::tevekenysegekHozzaadasa() {
    string sport;
    int ev, honap, nap, idotartam, suly, sportNum;
    cout << "Adja meg az evet!" << endl;
    cin >> ev;
    cout << "Adja meg a honapot!" << endl;
    cin >> honap;
    cout << "Adja meg a napot!" << endl;
    cin >> nap;
    do {
        cout << "Adja meg a sportot!" << endl;
        cin >> sportNum;
        switch (sportNum) {
        case 0:
            sport = "aerobic";
            break;
        case 1:
            sport = "pilates";
            break;
        case 2:
            sport = "kengu";
            break;
        }
    } while(sportNum > 2);
    cout << "Adja meg az idotartamot!" << endl;
    cin >> idotartam;
    cout << "Adja meg az sulyat!" << endl;
    cin >> suly;
    tevekenysegek.push_back(new NapiTevekenyseg(sport, idotartam, ev, honap, nap, suly));
}

void EloreHaladas::osszegez() {
    cout << "Tevekenysegek: " << endl << endl;
    int osszIdotartam = 0, kezdoSuly, jelenlegiSuly;
    for(auto it = tevekenysegek.begin(); it != tevekenysegek.end(); ++it) {
        (*it)->tevekenysegKiir();
        cout << endl;
        osszIdotartam+=(*it)->getIdotartam();
    }
    kezdoSuly = (*(tevekenysegek.begin()))->getSuly();
    jelenlegiSuly = (tevekenysegek.back())->getSuly();
    cout << "Ossz sportolt ido: " << osszIdotartam << endl;
    cout << "Kezdeti suly: " << kezdoSuly << endl;
    cout << "Jelenlegi suly: " << jelenlegiSuly << endl;
    cout << "Cel suly: " << cel << endl;
}

void EloreHaladas::tevekenysegBetoltese(NapiTevekenyseg* nt)
{
    tevekenysegek.push_back(nt);
}
