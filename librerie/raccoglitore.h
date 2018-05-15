#ifndef RACCOGLITORE_H
#define RACCOGLITORE_H
#include "tessera.h"
#include "sacchettino.h"
#include <QChar>

class Raccoglitore{

public:
    Raccoglitore();
    void inizializzaRaccoglitore(Sacchettino &pSacchettino);
    QChar getElementoRaccoglitore(int pI);
    void mescola();
    void cambiaTessera(Sacchettino &pSacchettino, int pPos);
    ~Raccoglitore();

private:
    Tessera raccoglitore[7];
    Tessera estrazioneTessera(int pPos);
    void scambio(int pPos, Tessera pT, Sacchettino &pSacchettino);
    int dimensione(); // conta le lettere giocabili

};
#endif // RACCOGLITORE_H
