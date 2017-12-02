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

Levelezes *FitnessCentrum::getLevelezes() {
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
    cout << endl << "1 - Belepes" << endl;
    cout << "2 - Regisztracio" << endl;
    cout << "3 - Orarend lekerdezese" << endl;
    cout << "x - Bezaras" << endl;
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
    Felhasznalo* talaltFelhasznalo= 0;
    for(auto i : felhasznalok) {
        if(i->getId()==id) {
            talaltFelhasznalo = i;
        }
    }
    if(talaltFelhasznalo) {
        string tipus;
        switch (talaltFelhasznalo->getType()) {
        case 1:
            tipus = "admin";
            break;
        case 2:
            tipus = "edzo";
            break;
        case 3:
            tipus = "tag";
            break;
        }
        cout << "Bejelentkezes " << talaltFelhasznalo->getId() << " azonositoju " + tipus + "kent." << endl;
        cout << "Adja meg a jelszavat!" << endl;
        cin >> jelszo;
        if(talaltFelhasznalo->getJelszo()==jelszo) {
            bejelentkezettFelhasznalo=talaltFelhasznalo;
            cout << "Sikeres bejelentkezes!" << endl;
        } else {
            cout << "Helytelen jelszo!" << endl;
        }
    } else {
        cout << "Nincs ilyen azonositoju felhasznalo!" << endl;
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
                felhasz->levelIrasa(teljesLevelezes, felhasznalok);
                break;
            case 4:
                felhasz->olvasatlanOlvasasa(teljesLevelezes);
                break;
            case 5:
                felhasz->teljesOlvasasa(teljesLevelezes);
                break;
            case 6:
                kijelentkezes();
                break;
            default:
                cout << "Nincs ilyen parancs." << endl;
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
                felhasz->levelIrasa(teljesLevelezes, felhasznalok);
                break;
            case 5:
                felhasz->olvasatlanOlvasasa(teljesLevelezes);
                break;
            case 6:
                felhasz->teljesOlvasasa(teljesLevelezes);
                break;
            case 7:
                kijelentkezes();
                break;
            default:
                cout << "Nincs ilyen parancs." << endl;
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
                felhasz->levelIrasa(teljesLevelezes, felhasznalok);
                break;
            case 8:
                felhasz->olvasatlanOlvasasa(teljesLevelezes);
                break;
            case 9:
                felhasz->teljesOlvasasa(teljesLevelezes);
                break;
            case 10:
                kijelentkezes();
                break;
            default:
                cout << "Nincs ilyen parancs." << endl;
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
        default:
            cout << "Nincs ilyen parancs." << endl;
        }
    }
}

void FitnessCentrum::start() {
    string cmd;
    cout << "Udvozoljuk a Fitness Centrum programjaban!" << endl << endl;
    latogatoMenu();
    cin >> cmd;
    while(cmd != "x") {
        cout << endl;
        vegrehajt(stoi(cmd));
        if(bejelentkezettFelhasznalo) {
            bejelentkezettFelhasznalo->menu();
        } else {
            latogatoMenu();
        }
        cin >> cmd;
    }
}

void FitnessCentrum::kijelentkezes() {
    bejelentkezettFelhasznalo = 0;
    cout << "Sikeres kijelentkezes!" << endl;
}
