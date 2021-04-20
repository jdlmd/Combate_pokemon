#ifndef TIPOS_H
#define TIPOS_H

#include <string>
#include "definiciones.h"

using namespace std;


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
