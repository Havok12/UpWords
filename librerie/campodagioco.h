#ifndef CAMPODAGIOCO_H
#define CAMPODAGIOCO_H
#include <iostream>
#include "tessera.h"

class CampoDaGioco {

public:
    CampoDaGioco();
    void inserireTessera(Tessera pT, int i, int j);
    void stampaCampoInConsole();

private:
    Tessera mat [10][10];
};

#endif // CAMPODAGIOCO_H
