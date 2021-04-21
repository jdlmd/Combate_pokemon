#ifndef POKEMON_H
#define POKEMON_H

#include "definiciones.h"
#include "movimientos.h"
#include "tipos.h"
#include <vector>

struct stats {
    uint hp;
    uint atack;
    uint defense;
    uint sp_atack;
    uint sp_defense;
    uint speed;
    uint evasion;
};

class Pokemon {
    public:
        Pokemon();
        struct stats estadisticas_actuales;

    private:
        struct stats IVs;
        struct stats EVs;
        struct stats estadisticas;
//        Movimientos attck[4];
        vector<Movimientos> attck;
};

#endif // POKEMON_H
