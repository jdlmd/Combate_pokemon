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
typedef unsigned short int uint

enum Tipos : uint {
    NINGUNO = 0,
    NORMAL = 1,
    FUEGO = 2,
    LUCHA = 3,
    AGUA = 4,
};

class Tipo{
    private:
        Tipos primario;
        Tipos secundario;

    public:
        Tipos getprimario();
        Tipos getsecundario();
}

*/
