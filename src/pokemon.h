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
        Pokemon();
        Pokemon(std::string _name,std::string _t1, std::string _t2, uint _level, struct stats _ivs, struct stats _evs, struct stats _base); // Terminar constructor
        void setHP(uint newHP);
        void addMove(Movimientos* move);
        void removeMove(int i);
        void setSecondaryType(Tipos _second);
        uint getNumberMoves();
        Movimientos* getMove(int i);
        std::string getName();
        uint getHP();
        uint getHPtotal();
        Tipos getPrimary();
        Tipos getSecondary();
        Estado getState();

    private:
        std::string name;
        struct stats IVs;
        struct stats EVs;
        struct stats estadisticas;
        struct stats estadisticas_actuales;
        std::vector<Movimientos*> attck;
        uint level;
        Estados* state;
        Tipo type;
        void calculateStatsFromBase(); // Implementar

    friend class Estados;
    friend class Movimientos;
};

#endif // POKEMON_H
