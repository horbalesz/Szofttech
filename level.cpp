#include "level.h"

using namespace std;

Level::Level(int kuldo, int cimzett, string p_uzenet):
    kuldoID(kuldo),
    cimzettID(cimzett),
    uzenet(p_uzenet),
    olvasott(false)
{}

int Level::getKuldoID() {
    return kuldoID;
}

int Level::getCimzettID() {
    return cimzettID;
}

void Level::setOlvasott() {
    olvasott = true;
}

void Level::levelKiir() {
    cout << "KuldoID: " << kuldoID << endl;
    cout << "CimzettID: " << cimzettID << endl;
    cout << "Uzenet:" << endl << uzenet << endl;
}

bool Level::getOlvasott() {
    return olvasott;
}
