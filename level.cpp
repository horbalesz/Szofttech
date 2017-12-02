#include "level.h"

using namespace std;

string Level::getUzenet() const
{
    return uzenet;
}

Level::Level(int kuldo, int cimzett, const string &p_uzenet):
    kuldoID(kuldo),
    cimzettID(cimzett),
    levelID(IdBox::getInstance().giveId()),
    uzenet(p_uzenet),
    olvasott(false)
{}

Level::Level(int kuldo, int cimzett, const string &p_uzenet, bool p_olvasott):
    kuldoID(kuldo),
    cimzettID(cimzett),
    uzenet(p_uzenet),
    olvasott(p_olvasott)
{}

int Level::getKuldoID() const {
    return kuldoID;
}

int Level::getCimzettID() const {
    return cimzettID;
}

void Level::setOlvasott() {
    olvasott = true;
}

bool Level::getOlvasott() {
    return olvasott;
}
