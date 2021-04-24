#include "mainwindow.h"
#include "personaje.h"
#include "battle.h"

#include <QApplication>

int main(int argc, char *argv[]) {

    QApplication a(argc, argv);
    Battle* w = new Battle();
    w->show();
    return a.exec();
}
