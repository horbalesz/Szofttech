#ifndef FCMAIN_H
#define FCMAIN_H
#include "fitnesscentrum.h"
#include "levelezes.h"
#include "level.h"
#include "felhasznalo.h"
#include "tag.h"
#include "edzo.h"
#include "admin.h"
#include "elorehaladas.h"
#include "napitevekenyseg.h"
#include "orarend.h"
#include "ora.h"

#include <iostream>
#include <fstream>

using namespace std;

class FCMain
{
    FitnessCentrum fc;
public:
    FCMain();
    void betolt();
    void elindit();
    void ment();
};

#endif // FCMAIN_H
