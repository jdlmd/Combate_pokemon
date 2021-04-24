#ifndef POKEMON_H
#define POKEMON_H

#include "definiciones.h"
#include "movimientos.h"
#include "tipos.h"
#include "estados.h"
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

/* Clase pokemon:
La clase pokemon guardará un vector con los movimientos a usar. Los pokemons
estarán formados por 4 estructuras de estadísticas, que se utilizarán posteriormente
por los movimientos para resolver los daños. Cada pokemon tiene un objeto Tipo,
que determinará sus fortalezas y debilidades, así como un estado, que se utilizará
para saber si puede atacar, si recibe daño por turno, etc
*/
class Pokemon {
    public:
        struct stats estadisticas_actuales;

        Pokemon();
        Pokemon(std::string _name); // Terminar constructor
        void setHP(uint newHP);
        uint getHP();
        uint getTotalHP();
        uint getLevel();
        uint getAtack();
        uint getSpAtack();
        uint getDefense();
        uint getSpDefense();
    private:
        std::string name;
        struct stats IVs;
        struct stats EVs;
        struct stats estadisticas;
        vector<Movimientos> attck;
        Estados state;
        Tipo type;
};

#endif // POKEMON_H
