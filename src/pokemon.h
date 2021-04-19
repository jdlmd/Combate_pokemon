#ifndef POKEMON_H
#define POKEMON_H
#include "definiciones.h"

struct stats{
    uint hp;
    uint atack;
    uint defense;
    uint sp_atack;
    uint sp_defense;
    uint speed;
};

class Pokemon
{
public:
    Pokemon();
    struct stats estadisticas;
    struct stats IVs;
    struct stats EVs;
    struct stats estadisticas_actuales;

private:

};

#endif // POKEMON_H
