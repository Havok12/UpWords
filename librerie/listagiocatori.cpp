#include "listagiocatori.h"

void stampa(ListaGiocatori* pTesta){
    if(pTesta == nullptr)
        return;
    ListaGiocatori* supporto = pTesta;
   supporto->g.stampaNome();
    supporto = supporto->nextptr;
    while(supporto != pTesta){
        supporto->g.stampaNome();
        supporto = supporto->nextptr;
    }
}

void inserimentoCoda(ListaGiocatori* &pTesta, Giocatore pG){
    ListaGiocatori* nuovoNodo = new ListaGiocatori;
    if(pTesta == nullptr){
        nuovoNodo->g = pG;
        nuovoNodo->nextptr = nuovoNodo;
        pTesta = nuovoNodo;
    }
    ListaGiocatori* supporto = pTesta;
    nuovoNodo->g = pG;
    nuovoNodo->nextptr = pTesta;
    while(pTesta != supporto->nextptr)
        supporto = supporto->nextptr;
    supporto->nextptr = nuovoNodo;
}

void distruzione(ListaGiocatori* &pTesta){
    ListaGiocatori* supporto = pTesta;
    pTesta = pTesta->nextptr;
    supporto->nextptr = nullptr;
    while(pTesta->nextptr != nullptr){
        supporto = pTesta;
        pTesta = pTesta->nextptr;
        delete supporto;
        supporto = nullptr;
    }
    pTesta = nullptr;
}
