#ifndef TIPOS_H
#define TIPOS_H

#include <string>

typedef unsigned short int uint;
using namespace std;

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
        Tipo();
        Tipo(Tipos primario, Tipos secundario);
        Tipos getPrimary();
        Tipos getSecondary();
        string getPrimaryName();
        string getSecondaryName();
        float multiplicador(Tipos tipo);
};

#endif // TIPOS_H

/*
    string Tipo::getPrimaryName(){
        switch (primario){
            case NINGUNO:
                return "None";
                break;
            case NORMAL:
                return "Normal";
                break;
            case FUEGO:
                return "Fuego";
                break;
            case LUCHA:
                return "Lucha";
                break;
            case AGUA:
                return "Agua";
                break;
            default:
                return "None";
                break;
        }
    }

*/
