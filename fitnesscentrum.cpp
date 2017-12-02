#include "fitnesscentrum.h"

FitnessCentrum::FitnessCentrum():
    bejelentkezettFelhasznalo(0)
{}

vector<Orarend *> &FitnessCentrum::getTeljesOrarend() {
    return teljesOrarend;
}

vector<EloreHaladas *> &FitnessCentrum::getTeljesSportnaplo() {
    return teljesSportnaplo;
}

vector<Felhasznalo *> &FitnessCentrum::getFelhasznalok() {
    return felhasznalok;
}

Levelezes *FitnessCentrum::getLevelezes()
{
    return teljesLevelezes;
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

void FitnessCentrum::setTeljesOrarend(vector<Orarend*> &p_orarend) {
    teljesOrarend = p_orarend;
}

void FitnessCentrum::setTeljesSportnaplo(vector<EloreHaladas*> &p_sportnaplo) {
    teljesSportnaplo = p_sportnaplo;
}

void FitnessCentrum::setTeljesLevelezes(Levelezes *p_levelek) {
    teljesLevelezes = p_levelek;
}

void FitnessCentrum::setFelhasznalok(vector<Felhasznalo *>  &p_felhasznalok) {
    felhasznalok = p_felhasznalok;
}

void FitnessCentrum::bejelentkezes() {
    int id, jelszo;
    cout << "Adja meg az azonositojat!" << endl;
    cin >> id;
    cout << "Adja meg a jelszavat!" << endl;
    cin >> jelszo;
    bool vegzett = false;
    for(auto it = felhasznalok.begin();it != felhasznalok.end() && !vegzett;++it) {
        if((*it)->getId()==id) {
            vegzett=true;
            if((*it)->getJelszo()==jelszo) {
                cout << "Sikeres bejelentkezes!" << endl;
                bejelentkezettFelhasznalo=(*it);
            } else {
                cout << "Helytelen jelszo!" << endl;
            }
        }
    }
}

void FitnessCentrum::regisztracio() {
    int jelszo, suly;
    cout << "Adja meg a negyjegyu pinkodjat!" << endl;
    cin >> jelszo;
    cout << "Adja meg a celsulyt amit el szeretne erni: ";
    cin >> suly;
    felhasznalok.push_back(new Tag(jelszo));
    bejelentkezettFelhasznalo = felhasznalok.back();
    teljesSportnaplo.push_back(new EloreHaladas(bejelentkezettFelhasznalo->getId(),suly));
    cout << endl << "Az on azonositoja: " << bejelentkezettFelhasznalo->getId() << endl;
    cout << "Az on jelszava: " << bejelentkezettFelhasznalo->getJelszo() << endl;
}

void FitnessCentrum::vegrehajt(int cmd) {
    if(bejelentkezettFelhasznalo) {
        switch (bejelentkezettFelhasznalo->getType()) {
        case 1:
            {Admin* felhasz = dynamic_cast<Admin*>(bejelentkezettFelhasznalo);
            switch (cmd) {
            case 1:
                felhasz->edzoRegisztralasa(felhasznalok);
                break;
            case 2:
                felhasz->statisztikakLekerdezese(teljesOrarend, felhasznalok);
                break;
            case 3:
                felhasz->levelIrasa(teljesLevelezes);
                break;
            case 4:
                felhasz->olvasatlanOlvasasa(teljesLevelezes);
                break;
            case 5:
                felhasz->teljesOlvasasa(teljesLevelezes);
                break;
            }
            break;}
        case 2:
            {Edzo* felhasz = dynamic_cast<Edzo*>(bejelentkezettFelhasznalo);
            switch(cmd) {
            case 1:
                felhasz->sajatOrarendMegtekintese(teljesOrarend);
                break;
            case 2:
                felhasz->oraHozzaadasa(teljesOrarend);
                break;
            case 3:
                felhasz->oraTorlese(teljesOrarend);
                break;
            case 4:
                felhasz->levelIrasa(teljesLevelezes);
                break;
            case 5:
                felhasz->olvasatlanOlvasasa(teljesLevelezes);
                break;
            case 6:
                felhasz->teljesOlvasasa(teljesLevelezes);
                break;
            }
            break;}
        case 3:
            {Tag* felhasz = dynamic_cast<Tag*>(bejelentkezettFelhasznalo);
            switch(cmd) {
            case 1:
                orarendekKiir();
                break;
            case 2:
                felhasz->sajatEdzesekLekerdezese(teljesOrarend);
                break;
            case 3:
                felhasz->edzesreFeliratkozas(teljesOrarend);
                break;
            case 4:
                felhasz->edzesrolLeiratkozas(teljesOrarend);
                break;
            case 5:
                felhasz->napiTevekenysegHozzaadasa(teljesSportnaplo);
                break;
            case 6:
                felhasz->elorehaladasLekerdezese(teljesSportnaplo);
                break;
            case 7:
                felhasz->levelIrasa(teljesLevelezes);
                break;
            case 8:
                felhasz->olvasatlanOlvasasa(teljesLevelezes);
                break;
            case 9:
                felhasz->teljesOlvasasa(teljesLevelezes);
                break;
            }
            break;}
        }
    } else {
        switch (cmd) {
        case 1:
            bejelentkezes();
            break;
        case 2:
            regisztracio();
            break;
        case 3:
            orarendekKiir();
            break;
        }
    }
}

void FitnessCentrum::start()
{
    string cmd;
    cout << "Udvozoljuk a Fitness Centrum programjaban!" << endl << endl;
    latogatoMenu();
    cin >> cmd;
    while(cmd != "x") {
        vegrehajt(stoi(cmd));
        if(bejelentkezettFelhasznalo) {
            bejelentkezettFelhasznalo->menu();
        } else {
            latogatoMenu();
        }
        cin >> cmd;
    }
}
