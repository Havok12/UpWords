#ifndef DIZIONARIO_H
#define DIZIONARIO_H
#include <vector>

struct nodeTrie{
    char data;
    bool isEnd; // serve nel caso in cui una parola ne contenga un'altra (abbaglia, abbagliai)
    std::vector<nodeTrie*> children;
};

class Dizionario{
public:
    // firma metodi pubblici compresi distruttori e costruttori
    Dizionario(); //caricaDizionario
    ~Dizionario(); // 	distruggiDizionario();
    void stampaDizionario();
    bool cercaParolaDizionario(std::string pS);
protected:

private:
    // lista variabili (firma)
    nodeTrie* rootDizionario;
    // lista metodi privati
    void stampaDizionario(nodeTrie* pChild, std::string &pS);
    // inserimento in posizione x (pRootDizionario)
    //DA RINOMINARE
    bool ricercaFiglioTrie(nodeTrie* pRootChild, char c, nodeTrie* &pChildFind);
    bool cercaParolaDizionario(nodeTrie* pChild, std::string pS);
    void inserisciParolaDizionario(nodeTrie* &pChild, std::string pS);
    void inserisciParolaDizionario(std::string pS);
    void distruggiDizionario(nodeTrie* &pChild);
};

#endif
