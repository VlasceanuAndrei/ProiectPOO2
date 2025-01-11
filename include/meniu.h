#ifndef PROIECT_MENIU_H
#define PROIECT_MENIU_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "profesor.h"
#include "elev.h"
#include "nota.h"

class Meniu {
    Meniu();
    ~Meniu();
public:
    static Meniu& inst();
    void run();
};

#endif
