#include <iostream>
#include <vector>
#include <fstream>
#include "dizionario.h"

// costruttore senza parametri
Dizionario::Dizionario(){
    rootDizionario = nullptr;
    std::fstream in ("C:/Users/Luciano/OneDrive - Politecnico di Milano/Corsi/I semestre/Fondamenti di Informatica/Elaborato 2017-2018/INSIEME/Upwords/Progetto/Parti/Test/prTest/Dizionario/dizionarioIT.txt", std::fstream::in);
    // fstream in ("./dizionarioIT.txt", std::fstream::in);
    while(!in.eof()){
        std::string s = "\0";
        in >> s;
        if(s.length() >= 3 && s.length() <= 10) // MIN, MAX LUNGHEZZA PAROLA GIOCABILI
            inserisciParolaDizionario(s);
    }
    in.close();
}
// distruttore
Dizionario::~Dizionario(){
    distruggiDizionario(rootDizionario);
}

void Dizionario::stampaDizionario(nodeTrie* pChild, std::string &pS){
    if(pChild == nullptr) return;
    if(pChild->data != '\0')
        pS = pS + pChild->data;
    // sono arrivato alla fine della parola salvata e la stampo
    if(pChild->isEnd)
        std::cout << pS << std::endl;
    if(pChild->children.size() != 0){
        for(nodeTrie* c: pChild->children)
            stampaDizionario(c, pS);
        //rimuove ultima lettera gia' stampata
        pS.pop_back();
    }else
        //rimuove ultima lettera gia' stampata
        pS.pop_back();
}

void Dizionario::stampaDizionario(){
    std::string s = "\0";
    stampaDizionario(rootDizionario, s);
}
bool Dizionario::ricercaFiglioTrie(nodeTrie* pRootChild, char pC, nodeTrie* &pChildFind){
    for(nodeTrie* child: pRootChild->children)
        if(child->data == pC){
            pChildFind = child;
            return true;
        }
    return false;
}
bool Dizionario::cercaParolaDizionario(nodeTrie* pChild, std::string pS){
    if(pChild == nullptr) return false;
    if(pS.length() == 0 && pChild->isEnd) return true;
    for(nodeTrie* c: pChild->children){
        if(c->data == pS[0])
            return cercaParolaDizionario(c, pS.substr(1, pS.length()));
    }
    return false;
}
bool Dizionario::cercaParolaDizionario(std::string pS){
    return cercaParolaDizionario(rootDizionario, pS);
}
void Dizionario::inserisciParolaDizionario(nodeTrie* &pChild, std::string pS){
    if(pS.length() == 0) return;
    if(pChild == nullptr){
        // se non esiste il Trie lo creo
        pChild = new nodeTrie;
        pChild->data = '\0';
        rootDizionario->isEnd = false;
    }
    // creo il nodo figlio
    nodeTrie* newChild = nullptr;
    // cerco se parte della parola è gia' stata salvata
    if(!ricercaFiglioTrie(pChild, toupper(pS[0]), newChild)){
        // se non lo è inzio a salvarla
        newChild = new nodeTrie;
        newChild->data = toupper(pS[0]);
        newChild->isEnd = false;
        if(pS.length()-1 == 0)
            newChild->isEnd = true;
        pChild->children.push_back(newChild);
    }
    //continua per le altre lettere
    inserisciParolaDizionario(newChild, pS.substr(1, pS.size()));
}
void Dizionario::inserisciParolaDizionario(std::string pS){
    inserisciParolaDizionario(rootDizionario, pS);
}
void Dizionario::distruggiDizionario(nodeTrie* &pChild){
    if(pChild == nullptr) return;
    for(nodeTrie* c: pChild->children)
        distruggiDizionario(c);
    delete pChild;
    rootDizionario = nullptr;
}
