#include "giocatore.h"

Giocatore::Giocatore(){
    nome = "\0";
    punteggio = 0;
}

Giocatore::Giocatore(QString pNome, Sacchettino &pSacchettino)
{
    nome = pNome;
    punteggio = 0;
    raccoglitore.inizializzaRaccoglitore(pSacchettino);
}

void Giocatore::stampaNome(){
    qDebug() << nome << "\n";
}
