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
    VOLADOR = 5,
    PLANTA = 6,
    ELECTRICO = 7,
    VENENO = 8,
    TIERRA = 9,
    PSIQUICO = 10,
    ROCA = 11,
    HIELO = 12,
    BICHO = 13,
    DRAGON = 14,
    FANTASMA = 15,
    SINIESTO = 16,
    ACERO = 17,
    HADA = 18,
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
