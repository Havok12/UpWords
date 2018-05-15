#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, ListaGiocatori* pLista, Sacchettino &pSacchettino) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    schermoIntero = false;
    lobby = parent;
    ui->setupUi(this);
    sacchettino = pSacchettino;
    modalitaLettera = false;
    /*qsrand(time(NULL));
    int random = qrand() % ((4 + 1) - 1) + 1;*/  //TROVO CHI PESCA LA LETTERA A PER PRIMO

    //CREO LISTA GIOCATORI E GIOCATORI
    //caricaInfoGiocatore();
    //caricaCampoGioco();

    //PRENDO A CASO LE TESSERE DAL VETTORE PER DISTRIBUIRLE AI GIOCATORI
    int casella = 0;
    QString str = "";
    int contatore = 100;

    /*for(int i=0; i < 7; i++){
        QLayoutItem* item = ui->raccoglitore->itemAt(i);
        QPushButton* btn = qobject_cast<QPushButton *>(item->widget());
        if (btn->text() == "") {
            casella = qrand() % ((sacchettino.dimensione() + 1) - 1) + 1;
            str = QChar(sacchettino.getSacchettino().at(casella).getLettera());
            btn->setText(str);
            contatore -= 1;
        }
    }*/

    //ASSEGNO LE AZIONI AI PUSHBUTTONS DEL RACCOGLITORE
    for(int i=0; i < 7; i++){
        QLayoutItem* item = ui->raccoglitore->itemAt(i);
        QPushButton* btn = qobject_cast<QPushButton *>(item->widget());
        connect(btn, &QPushButton::clicked, this, &MainWindow::onClickedRaccoglitore);
    }
    //ASSEGNO LE AZIONI AI PUSHBUTTONS DELLA GRIGLIA
    for(int i=0; i < ui->gridLayout->rowCount(); i++) {
        for(int j=0; j < ui->gridLayout->columnCount(); j++){
            QLayoutItem* item = ui->gridLayout->itemAtPosition(i, j);
            QPushButton* btn = qobject_cast<QPushButton *>(item->widget());
            connect(btn, &QPushButton::clicked, this, &MainWindow::onClickedGriglia);
        }
    }

    //ui->labelProva->setText("<sup>•</sup> x <sup>2</sup>");

    QGraphicsDropShadowEffect *e = new QGraphicsDropShadowEffect;
    e->setBlurRadius(10);
    e->setXOffset(0);
    e->setYOffset(8);
    ui->btGioca->setGraphicsEffect(e);
    QGraphicsDropShadowEffect *e1 = new QGraphicsDropShadowEffect;
    e1->setBlurRadius(10);
    e1->setXOffset(5);
    e1->setYOffset(5);
    ui->labelProva->setGraphicsEffect(e1);
    ui->frame->setStyleSheet("#frame { border: 2px solid black; }");


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClickedRaccoglitore()
{
        QPushButton *btn = qobject_cast<QPushButton *>(sender());
        text = btn->text();
        btn->setText("");
}

void MainWindow::onClickedGriglia()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    if (text!="") {
        btn->setText(text);
        text = "";
    }
}

void MainWindow::on_actionNuova_Partita_triggered()
{
    lobby->show();
    this->close();
}

void MainWindow::on_actionSchermo_Intero_triggered()
{
    if (schermoIntero == false) {
        showFullScreen();
        ui->actionSchermo_Intero->setText("Torna in finestra");
        schermoIntero = true;
    } else {
        showMaximized();
        ui->actionSchermo_Intero->setText("Schermo Intero");
        schermoIntero = false;
    }
}

void MainWindow::on_actionEsci_Dal_Gioco_triggered()
{
    QApplication::quit();
}
