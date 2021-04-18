#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


/*

enum Tipos : unsigned short int {
    NINGUNO = 0,
    NORMAL = 1,
    FUEGO = 2,
    LUCHA = 3,
    AGUA = 4,
};

*/
