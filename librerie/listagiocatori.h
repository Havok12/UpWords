#ifndef LISTAGIOCATORI_H
#define LISTAGIOCATORI_H
#include "giocatore.h"

struct ListaGiocatori{
    ListaGiocatori* nextptr;
    Giocatore g;
};
void stampa(ListaGiocatori* pTesta);
void inserimentoCoda(ListaGiocatori* &pTesta, Giocatore pG);
void distruzione(ListaGiocatori* &pTesta);

#endif //LISTAGIOCATORI_H

