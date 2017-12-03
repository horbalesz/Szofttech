#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "fitnesscentrum.h"

using namespace std;

void betolt(FitnessCentrum* fc)  {
    { //felhasználók beolvasása
        vector<Felhasznalo*> felhasznalo_tmp;
        ifstream input("felhasznalok.txt");
        if(input.is_open()) {
            int id, jelszo, type;
            string nev;
            while(input.good()) {
                input >> type >> id >> jelszo >> nev;
                switch(type) {
                    case 1:
                        felhasznalo_tmp.push_back(new Admin(id, jelszo, nev));
                        break;
                    case 2:
                        felhasznalo_tmp.push_back(new Edzo(id, jelszo, nev));
                        break;
                    case 3:
                        felhasznalo_tmp.push_back(new Tag(id, jelszo, nev));
                        break;
                }
            }
        }
        input.close();
        fc->setFelhasznalok(felhasznalo_tmp);
    }
    { //levelek beolvasása
        Levelezes* levelek_tmp = new Levelezes();
        ifstream input("levelek.txt");
        if(input.is_open()) {
            int kuldoId, cimzettId;
            string line;
            bool olvasott;
            stringstream ss;
            while(input.good()) {
                getline(input, line);
                ss << line;
                ss >> kuldoId >> cimzettId >> olvasott;
                getline(input,line);
                levelek_tmp->levelHozzaadasa(new Level(kuldoId, cimzettId, line, olvasott));
                ss.clear();
            }
            input.close();
            fc->setTeljesLevelezes(levelek_tmp);
        }
    }
    { //órarendek beolvasása
        vector<Orarend*> orarendek_tmp;
        ifstream input("orarendek.txt");
        if(input.is_open()) {
            int edzoId, ev, ho, nap, ora, perc, hossz, letszam, id;
            string sportag;
            Orarend* tmp = new Orarend(0);
            while(input.good()) {
                input >> ev;
                if(ev < 2000) {
                    edzoId = ev;
                    if(tmp->getEdzoId() != 0)
                        orarendek_tmp.push_back(tmp);
                    tmp = new Orarend(edzoId);
                } else {
                    input >> ho >> nap >> ora >> perc >> hossz >> letszam >> sportag >> id;
                    tmp->oraBetoltes(new Ora(ev, ho, nap, ora, perc, hossz, letszam, id, sportag));
                }
            }
            delete tmp;
            input.close();
            fc->setTeljesOrarend(orarendek_tmp);
        }

        input.open("orak.txt");
        vector<int> fel_tmp;
        if(input.is_open()) {
            string line, prevLine;
            prevLine="";
            int oraId;
            while(input.good()) {
                getline(input, line);
                if(line!="") {
                    if(prevLine == "") {
                        if(!fel_tmp.empty()) {
                            vector<Orarend*> orarendek= fc->getTeljesOrarend();
                            for(auto &i: orarendek) {
                                vector<Ora*> orak = i->getOra();
                                for(auto &j : orak) {
                                    if(j->getId() == oraId)
                                        j->setFeliratkozottak(fel_tmp);
                                }
                            }
                            fel_tmp.clear();
                        }
                        oraId = stoi(line);
                    } else
                        fel_tmp.push_back(stoi(line));
                }
                prevLine = line;
            }
            input.close();
        }
    }
    { //elorehaladások beolvasása
        vector<EloreHaladas*> elore_tmp;
        ifstream input("elorehaladas.txt");
        if(input.is_open()) {
            int ev, ho, nap, suly, ido, tagId;
            string sport;
            EloreHaladas* tmp = new EloreHaladas(0,0);
            while(input.good()) {
                input >> ev;
                if(ev < 2000) {
                    tagId = ev;
                    input >> suly;
                    if(tmp->getTagID() != 0)
                        elore_tmp.push_back(tmp);
                    tmp = new EloreHaladas(tagId, suly);
                } else {
                    input >> ho >> nap >> ido >> suly >> sport;
                    tmp->tevekenysegBetoltese(new NapiTevekenyseg(sport, ido, ev, ho, nap, suly));
                }
            }
            fc->setTeljesSportnaplo(elore_tmp);
            delete tmp;

            input.close();
        }
    }

    { //counter beolvasása
        ifstream input("counter.txt");
        if(input.is_open()) {
            int ct;
            input >> ct;
            IdBox::getInstance().setCounter(ct);
            input.close();
        }
    }
}

void ment(FitnessCentrum *fc)
{
    { //felhasználók elmentése
        ofstream out("felhasznalok.txt");
        if(out.is_open()) {
            vector<Felhasznalo*> felhaszn_tmp = fc->getFelhasznalok();
            for(auto i: felhaszn_tmp) {
                out << i->getType() << " " << i->getId() << " " << i->getJelszo() << " " << i->getFelhasznaloNev();
                if(i != felhaszn_tmp[felhaszn_tmp.size()-1])
                    out << "\n";
            }
            out.close();
        }
    }

    { //levelek elmentése
        ofstream out("levelek.txt");
        if(out.is_open()) {
            vector<Level*> level_tmp = fc->getTeljesLevelezes()->getLevelek();
            for(auto i: level_tmp) {
                out << i->getKuldoID() << " " << i->getCimzettID() << " " << i->getOlvasott() << "\n" << i->getUzenet();
                if(i != level_tmp[level_tmp.size()-1])
                    out << "\n";
            }
            out.close();
        }
    }

    { //órarendek elmentése
        ofstream out("orarendek.txt");
        if(out.is_open()) {
            vector<Orarend*> orarend_tmp = fc->getTeljesOrarend();
            for(auto i: orarend_tmp) {
                out << i->getEdzoId() << endl;
                vector<Ora*> orak = i->getOra();
                for(auto j : orak)
                    out << j->oraMent() << endl;
            }
            out << "0";
            out.close();
        }

        out.open("orak.txt");
        if(out.is_open()) {
            vector<Orarend*> orarend_tmp = fc->getTeljesOrarend();
            for(auto i: orarend_tmp) {
                vector<Ora*> orak = i->getOra();
                for(auto j : orak)
                    out << j->feliratkozottakMent() << endl;
            }
        }
    }

    { //elrehaladások elmentése
        ofstream out("elorehaladas.txt");
        if(out.is_open()) {
            vector<EloreHaladas*> elore_tmp = fc->getTeljesSportnaplo();
            for(auto i: elore_tmp) {
                out << i->getTagID() << " " << i->getCel() << endl;
                vector<NapiTevekenyseg*> orak = i->getTevekenysegek();
                for(auto j : orak)
                    out << j->tevekenysegMent();
            }
            out << "0";
            out.close();
        }
    }

    { //counter elmentése
        ofstream out("counter.txt");
        if(out.is_open()) {
            out << IdBox::getInstance().getCounter();
            out.close();
        }
    }
}

int main() {
    FitnessCentrum myFitnessCentrum;
    betolt(&myFitnessCentrum);
    myFitnessCentrum.start();
    ment(&myFitnessCentrum);
    return 0;
}
