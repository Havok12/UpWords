#ifndef SACCHETTINO_H
#define SACCHETTINO_H
#include <cstdlib>
#include <ctime>
#include <vector>
#include "tessera.h"

class Sacchettino {

public:
    Sacchettino ();
    ~Sacchettino();
    std::vector <Tessera> getSacchettino();
    int dimensione();
    void aggiungiTessera(char pC);
    Tessera estraiTessera();

private:
    std::vector <Tessera> sacchettino;
};

#endif // SACCHETTINO_H
