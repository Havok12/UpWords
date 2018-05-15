#include "campodagioco.h"

CampoDaGioco::CampoDaGioco()
{
    int i, j;
    Tessera t;
    for ( i=0; i<10; i++ ) {
        for ( j=0; j<10; j++ ) {
            mat [i][j] = t;
        }
    }
}
void CampoDaGioco::inserireTessera(Tessera pT, int i, int j) {
    mat [i][j] = pT;
}

void CampoDaGioco::stampaCampoInConsole() {
    for (int i=0; i<10; i++ ) {
        for (int j=0; j<10; j++ ) {
            mat [i][j].stampa_Lettera();
            if (j==9) {
                std::cout << std::endl;
            }
        }
    }
}
