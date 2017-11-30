#include "fitnesscentrum.h"

FitnessCentrum::FitnessCentrum()
{}

vector<Orarend *> &FitnessCentrum::getTeljesOrarend() {
    return teljesOrarend;
}

vector<EloreHaladas *> &FitnessCentrum::getTeljesSportnaplo() {
    return teljesSportnaplo;
}

void FitnessCentrum::orarendekKiir() {
    cout << "A teljes orarend:" << endl;
    for(auto it = teljesOrarend.begin();it!=teljesOrarend.end();++it) {
        (*it)->orarendKiir();
        cout << endl;
    }
}

void FitnessCentrum::latogatoMenu() {
    cout << "1 - Belepes" << endl;
    cout << "2 - Regisztracio" << endl;
    cout << "3 - Orarend lekerdezese" << endl;
    cout << "x - Kilepes" << endl;
}

void FitnessCentrum::setTeljesOrarend(vector<Orarend*> p_orarend) {
    teljesOrarend = p_orarend;
}

void FitnessCentrum::setTeljesSportnaplo(vector<EloreHaladas*> p_sportnaplo) {
    teljesSportnaplo = p_sportnaplo;
}

void FitnessCentrum::setTeljesLevelezes(Levelezes *p_levelek) {
    teljesLevelezes = p_levelek;
}
