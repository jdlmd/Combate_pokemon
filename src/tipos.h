#ifndef TIPOS_H
#define TIPOS_H

<<<<<<< HEAD
#include <string>
=======
#include<strings.h>
>>>>>>> 44b051c74bb860f6355cf4c5738cda8346086ea2

typedef unsigned short int uint;

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

class Tipo{;
    private:
        Tipos primario;
        Tipos secundario;

    public:
        Tipo();
        Tipo(Tipos primario, Tipos secundario);
        Tipos getPrimary();
        Tipos getSecondary();
<<<<<<< HEAD
        std::string getPrimaryName();
        std::string getSecondaryName();
        uint multiplicador(Tipos tipo);
};
=======
        string getPrimaryName();
        string getSecondaryName();
        float multiplicador(Tipos tipo);
}
>>>>>>> 44b051c74bb860f6355cf4c5738cda8346086ea2

#endif // TIPOS_H

