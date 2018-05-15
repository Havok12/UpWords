#ifndef GIOCATORE_H
#define GIOCATORE_H
#include <QString>
#include <QDebug>
#include "raccoglitore.h"
#include "sacchettino.h"

class Giocatore {

public:
    Giocatore();
    Giocatore(QString pNome, Sacchettino &pSacchettino);
    void setNome(QString pNome);
    void stampaNome();
    QString getNome();
    QString getPunteggio();


private:
    QString nome;
    int punteggio;
    Raccoglitore raccoglitore;
};

#endif // GIOCATORE_H
