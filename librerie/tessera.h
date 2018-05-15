#ifndef TESSERA_H
#define TESSERA_H
#include <iostream>

class Tessera {

public:
    Tessera ();
    //costruttore con parametri lettera
    Tessera (char pLettera);
    //distruttore
    ~Tessera();
    void stampa_Lettera();
    char getLettera();

private:
    //lista attributi
    char lettera;
    //int altezza;
};

#endif //TESSERA_H
