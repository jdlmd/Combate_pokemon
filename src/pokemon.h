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
    uint precision;
};

class Pokemon {
    public:
        Pokemon();
        struct stats estadisticas_actuales;
        Tipo tipo_Pkm;

        float getStab(Tipo);
        uint getLevel();
        uint getAtack();
        uint getSpAtack();
        uint getDefense();
        uint getSpDefense();
    private:
        uint nivel;
        struct stats IVs;
        struct stats EVs;
        struct stats estadisticas;
//        Movimientos attck[4];
        vector<Movimientos> attck;
};

#endif // POKEMON_H
