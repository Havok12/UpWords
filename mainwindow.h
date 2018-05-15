#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include "time.h"
#include "stdlib.h"
#include <iostream>

#include <QMainWindow>
#include <QTime>
#include "librerie/dizionario.h"
#include "librerie/tessera.h"
#include "librerie/raccoglitore.h"
#include "librerie/giocatore.h"
#include "librerie/sacchettino.h"
#include "librerie/listagiocatori.h"
#include "librerie/campodagioco.h"
#include <QGraphicsDropShadowEffect>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent, ListaGiocatori *pLista, Sacchettino &pSacchettino);
    ~MainWindow();

private slots:
    void onClickedRaccoglitore();

    void onClickedGriglia();

    void on_actionNuova_Partita_triggered();

    void on_actionSchermo_Intero_triggered();

    void on_actionEsci_Dal_Gioco_triggered();

private:
    Ui::MainWindow *ui;
    QWidget* lobby;
    bool schermoIntero;
    QString text; //DA CONTROLLARE
    ListaGiocatori* lista;
    Sacchettino sacchettino;
    bool modalitaLettera;
    CampoDaGioco campo;

    void caricaInfoGiocatore();
    void caricaRaccoglitoreGrafico();
    void caricaRaccoglitoreGrafico(int pI);
    void resetRaccoglitoreGrafico();
    void caricaCampoGioco();
    void salvaCampoGioco();
};

#endif // MAINWINDOW_H
