#ifndef POKEMON_H
#define POKEMON_H

#include "tipo.h"
#include <vector>
#include "definiciones.h"
#include <iostream>

/* Clase pokemon:
La clase pokemon guardará un vector con los movimientos a usar. Los pokemons
estarán formados por 4 estructuras de estadísticas, que se utilizarán posteriormente
por los movimientos para resolver los daños. Cada pokemon tiene un objeto Tipo,
que determinará sus fortalezas y debilidades, así como un estado, que se utilizará
para saber si puede atacar, si recibe daño por turno, etc
*/
class Movimientos;
class Estados;
class Pokemon {
    public:
        struct stats estadisticas_actuales;

        Pokemon();
        Pokemon(std::string _name,std::string _t1, std::string _t2, uint _level, struct stats _ivs, struct stats _evs, struct stats _base); // Terminar constructor
        void setHP(uint newHP);
        uint getHP();
        uint getTotalHP();
        uint getLevel();
        uint getAtack();
        uint getSpAtack();
        uint getDefense();
        uint getSpDefense();
        void addMove(Movimientos* move);
    private:
        std::string name;
        struct stats IVs;
        struct stats EVs;
        struct stats estadisticas;
        std::vector<Movimientos*> attck;
        uint level;
        Estados* state;
        Tipo type;
};

#endif // POKEMON_H
