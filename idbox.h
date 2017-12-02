#ifndef _IDBOX_H
#define _IDBOX_H

#include <iostream>

using namespace std;

class IdBox {
    int counter;
    IdBox();
public:
    static IdBox &getInstance();
    int giveId();
    void setCounter(int value);
    int getCounter() const;
};


#endif
