#ifndef LOBBY_H
#define LOBBY_H

#include <QDialog>
#include <QMessageBox>
#include <QDebug>
#include "librerie/sacchettino.h"
#include "librerie/listagiocatori.h"

namespace Ui {
class Lobby;
}

class Lobby : public QDialog
{
    Q_OBJECT

public:
    explicit Lobby(QWidget *parent = 0);
    ~Lobby();

private slots:

    void on_btGiocatoreSingolo_clicked();
    void on_btDueGiocatori_clicked();
    void on_btTreGiocatori_clicked();
    void on_btQuattroGiocatori_clicked();
    void on_btStart_clicked();
    void on_btIndietro_clicked();

private:
    Ui::Lobby *ui;
    std::vector <QString> nomiGiocatori;
    Sacchettino sacchettino;
    ListaGiocatori* lista;
    void setSecondPage1();
    void setSecondPage2();
    void setSecondPage3();
    void resetLobby();
    void resetLineEdits();
    void creaListaGiocatori();
    void resetNomi();
};

#endif // LOBBY_H
