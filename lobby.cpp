#include "lobby.h"
#include "ui_lobby.h"
#include "mainwindow.h"

Lobby::Lobby(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lobby)
{
    ui->setupUi(this);
    ui->swPage->setCurrentIndex(0);
}

void Lobby:: setSecondPage1() {
    ui->label_Giocatore2->setEnabled(false);
    ui->lineEdit_Giocatore2->setEnabled(false);
    ui->label_Giocatore3->setEnabled(false);
    ui->lineEdit_Giocatore3->setEnabled(false);
    ui->label_Giocatore4->setEnabled(false);
    ui->lineEdit_Giocatore4->setEnabled(false);
}

void Lobby:: setSecondPage2() {
    ui->label_Giocatore3->setEnabled(false);
    ui->lineEdit_Giocatore3->setEnabled(false);
    ui->label_Giocatore4->setEnabled(false);
    ui->lineEdit_Giocatore4->setEnabled(false);
}

void Lobby:: setSecondPage3() {
    ui->label_Giocatore4->setEnabled(false);
    ui->lineEdit_Giocatore4->setEnabled(false);
}

void Lobby::resetLobby() {
    ui->label_Giocatore2->setEnabled(true);
    ui->lineEdit_Giocatore2->setEnabled(true);
    ui->label_Giocatore3->setEnabled(true);
    ui->lineEdit_Giocatore3->setEnabled(true);
    ui->label_Giocatore4->setEnabled(true);
    ui->lineEdit_Giocatore4->setEnabled(true);
    ui->swPage->setCurrentIndex(0);
}

void Lobby::resetLineEdits() {
    ui->lineEdit_Giocatore1->clear();
    ui->lineEdit_Giocatore2->clear();
    ui->lineEdit_Giocatore3->clear();
    ui->lineEdit_Giocatore4->clear();
}

void Lobby::creaListaGiocatori(){
    //CREO I GIOCATORI E CARICO LA LISTA GIOCATORI
    srand(time(0));
    std::vector<QString> copiaNomiGiocatori = nomiGiocatori;
    for (int i = nomiGiocatori.size(); i > 0; --i ){
        int n = rand() % i;
        Giocatore g(copiaNomiGiocatori[n], sacchettino);
        inserimentoCoda(lista, g);
        copiaNomiGiocatori.erase(copiaNomiGiocatori.begin()+n);
    }
}

void Lobby::resetNomi(){
    while (!nomiGiocatori.empty()) {
        nomiGiocatori.pop_back();
    }
}

Lobby::~Lobby()
{
    delete ui;
}

void Lobby::on_btGiocatoreSingolo_clicked()
{
    setSecondPage1();
    ui->swPage->setCurrentIndex(1);
}

void Lobby::on_btDueGiocatori_clicked()
{
    setSecondPage2();
    ui->swPage->setCurrentIndex(1);
}

void Lobby::on_btTreGiocatori_clicked()
{
    setSecondPage3();
    ui->swPage->setCurrentIndex(1);
}

void Lobby::on_btQuattroGiocatori_clicked()
{
    ui->swPage->setCurrentIndex(1);
}

void Lobby::on_btStart_clicked()
{
    resetNomi();
    if (((ui->lineEdit_Giocatore1->isEnabled()) && ((ui->lineEdit_Giocatore1->text().isEmpty()) || (ui->lineEdit_Giocatore1->text().at(0) == " "))) || ((ui->lineEdit_Giocatore2->isEnabled()) && ((ui->lineEdit_Giocatore2->text().isEmpty()) || (ui->lineEdit_Giocatore2->text().at(0) == " "))) || ((ui->lineEdit_Giocatore3->isEnabled()) && ((ui->lineEdit_Giocatore3->text().isEmpty()) || (ui->lineEdit_Giocatore3->text().at(0) == " "))) ||((ui->lineEdit_Giocatore4->isEnabled()) && ((ui->lineEdit_Giocatore4->text().isEmpty())  || (ui->lineEdit_Giocatore4->text().at(0) == " ")))) {
        QMessageBox::critical (0, "Error Message", "Assegnare un nome a ciascun giocatore.");
    } else {
        if(ui->lineEdit_Giocatore1->isEnabled()){
            nomiGiocatori.push_back(ui->lineEdit_Giocatore1->text());
        }
        if (ui->lineEdit_Giocatore2->isEnabled()) {
            nomiGiocatori.push_back(ui->lineEdit_Giocatore2->text());
        }
        if (ui->lineEdit_Giocatore3->isEnabled()) {
            nomiGiocatori.push_back(ui->lineEdit_Giocatore3->text());
        }
        if (ui->lineEdit_Giocatore4->isEnabled()) {
            nomiGiocatori.push_back(ui->lineEdit_Giocatore4->text());
        }

        /*qDebug() << nomi[0];
        qDebug() << nomi[1];
        qDebug() << nomi[2];
        qDebug() << nomi[3];*/

        creaListaGiocatori();
        MainWindow *m = new MainWindow (this, lista, sacchettino);
        m->showMaximized();
        resetLineEdits();
        resetLobby();
        this->hide();
    }
}

void Lobby::on_btIndietro_clicked()
{
    resetLobby();
}
