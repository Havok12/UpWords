#include <QApplication>
#include "lobby.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Lobby lobby;
    lobby.show();

    return a.exec();
}
