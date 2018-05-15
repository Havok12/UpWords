#include "raccoglitore.h"

// costruttore senza parametri
Raccoglitore::Raccoglitore(){}

void Raccoglitore::inizializzaRaccoglitore(Sacchettino &pSacchettino){
    for(int i=0; i<7 ; ++i){
        raccoglitore[i] = pSacchettino.estraiTessera();
    }
}

Raccoglitore::~Raccoglitore(){}

QChar Raccoglitore::getElementoRaccoglitore(int pI){
    return raccoglitore[pI].getLettera();
}

//La tessera che non mi serve piu viene messa nel sacchettino
void Raccoglitore::cambiaTessera(Sacchettino &pSacchettino, int pPos){
    pSacchettino.aggiungiTessera(estrazioneTessera(pPos).getLettera());
    raccoglitore[pPos] = pSacchettino.estraiTessera();
}

Tessera Raccoglitore::estrazioneTessera(int pPos){
    Tessera tVuota;
    Tessera t = raccoglitore[pPos];
    raccoglitore[pPos] = tVuota;
    return t;
}

void Raccoglitore::scambio(int pPos, Tessera pT, Sacchettino &pSacchettino){
    // scambio di una lettera giocabile con una vuota
    if(raccoglitore[pPos].getLettera() == '\0'){
        raccoglitore[pPos] = pT;
        return;
    }
    Tessera t = raccoglitore[pPos];
    raccoglitore[pPos] = pT;
    // lo scambio è solo tra sacchettino e raccoglitore
    pSacchettino.aggiungiTessera(t.getLettera());
}

// conta le lettere giocabili
int Raccoglitore::dimensione(){
    int c = 0;
    for(int i=0; i<7 ; ++i)
        if(raccoglitore[i].getLettera() != '\0')
            ++c;
    return c;
}

void Raccoglitore::mescola(){
    std::random_shuffle(&raccoglitore[0], &raccoglitore[7]);
}
