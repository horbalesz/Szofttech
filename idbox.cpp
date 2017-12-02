#include "IdBox.h"

void IdBox::setCounter(int value) {
    counter = value;
}

int IdBox::getCounter() const
{
    return counter;
}

IdBox::IdBox():
    counter(1)
{}

IdBox &IdBox::getInstance() {

    static IdBox instance;

    return instance;

}

int IdBox::giveId() {
    return counter++;
}
