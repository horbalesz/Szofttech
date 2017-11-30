#include "fcmain.h"

FCMain::FCMain()
{

}

void FCMain::betolt()
{
    { //felhasználók beolvasása
        vector<Felhasznalo*> felhasznalo_tmp;

        ifstream input("felhasznalok.txt");

        if(input.is_open())
        {
            int id, jelszo, type;

            while(input.good())
            {
                input >> type >> id >> jelszo;

                switch(type)
                {
                    case 1:
                        felhasznalo_tmp.push_back(new Admin(id, jelszo));
                        break;
                    case 2:
                        felhasznalo_tmp.push_back(new Edzo(id, jelszo));
                        break;
                    case 3:
                        felhasznalo_tmp.push_back(new Tag(id, jelszo));
                        break;
                }
            }
        }

        //fc.setTeljesFelhasznalok();

    }

    { //levelek beolvasása
        Levelezes* levelek_tmp = new Levelezes();

        ifstream input("levelek.txt");

        if(input.is_open())
        {
            int kuldoId, cimzettId;
            string uzenet;

            while(input.good())
            {
                input >> kuldoId >> cimzettId;
                getline(input,uzenet);

                levelek_tmp->levelHozzaadasa(new Level(kuldoId, cimzettId, uzenet));
            }

            fc.setTeljesLevelezes(levelek_tmp);
        }
    }

    { //órarendek beolvasása

        vector<Orarend*> orarendek_tmp;

        ifstream input("orarendek.txt");

        if(input.is_open())
        {
            int edzoId, ev, ho, nap, ora, perc, hossz, letszam, id;
            string sportag;
            Orarend* tmp = new Orarend(0);

            while(input.good())
            {
                input >> ev;

                if(ev < 2000)
                {
                    edzoId = ev;
                    if(tmp->getEdzoId() != 0)
                        orarendek_tmp.push_back(tmp);
                    delete tmp;
                    tmp = new Orarend(edzoId);
                }
                else
                {
                    input >> ho >> nap >> ora >> perc >> hossz >> letszam >> sportag >> id;
                    tmp->oraBetoltes(new Ora(ev, ho, nap, ora, perc, hossz, letszam, id, sportag));
                }
            }

            delete tmp;



            fc.setTeljesOrarend(orarendek_tmp);
        }

    }

    { //elorehaladások beolvasása

        vector<EloreHaladas*> elore_tmp;

        ifstream input("elorehaladas.txt");

        if(input.is_open())
        {
            int ev, ho, nap, suly, ido, tagId;
            string sport;
            EloreHaladas* tmp = new EloreHaladas(0,0);

            while(input.good())
            {
                input >> ev;

                if(ev < 2000)
                {
                    tagId = ev;
                    input >> suly;
                    if(tmp->getTagID() != 0)
                        elore_tmp.push_back(tmp);
                    delete tmp;
                    tmp = new EloreHaladas(tagId, suly);
                }
                else
                {
                    input >> ho >> nap >> ido >> suly >> sport;
                    tmp->tevekenysegBetoltese(new NapiTevekenyseg(sport, ido, ev, ho, nap, suly));
                }
            }

            fc.setTeljesSportnaplo(elore_tmp);
            delete tmp;
        }

    }
}

void FCMain::elindit()
{

}

void FCMain::ment()
{

}
