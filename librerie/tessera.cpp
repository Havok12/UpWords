#include "tessera.h"

Tessera::Tessera () {
    lettera = '\0';
}
Tessera::Tessera (char pLettera) {
    lettera = pLettera;
}
Tessera::~Tessera() {}
void Tessera::stampa_Lettera(){
    std::cout << lettera;
}
char Tessera::getLettera(){
    return lettera;
}
