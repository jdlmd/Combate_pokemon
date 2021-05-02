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
class MovimientoEstado;
class Pokemon {
    public:
        Pokemon();
        ~Pokemon();
        Pokemon(std::string _name,std::string _t1, std::string _t2, uint _level, struct stats _ivs, struct stats _evs, struct stats _base);
        void setHP(uint newHP); // Fija la vida del pokemon
        void addMove(Movimientos* move); // Añade un movimiento al pokemon
        void removeMove(int i); // Elimina un movimiento del pokemon
        void setSecondaryType(Tipos _second); // Fija el tipo secundario del pokemon
        uint getNumberMoves(); // Devuelve el numero de movimientos que tiene el pokemon
        Movimientos* getMove(int i); // Devuelve el puntero de un movimiento del pokemon
        std::string getName(); // Devuelve el nombre del pokemon
        int getHP(); // Devuelve la vida actual del pokemon
        int getHPtotal(); // Devuelve la vida total del pokemon
        Tipos getPrimary(); // Devuelve el tipo primario del pokemon
        Tipos getSecondary(); // Devuelve el tipo secundario del pokemon
        Estados* getStatePtr(); // Devuelve el puntero del estado del pokemon
        Estado getState(); // Devuelve el estado del pokemon
        uint getSpeed(); // Devuelve la velocidad del pokemon
        uint getLevel(); // Devuelve el nivel del pokemon
        Tipo getType(); // Devuelve el tipo del pokemon

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
        void calculateStatsFromBase(struct stats,struct stats,struct stats); // Calcula las estadisticas en base a los ivs, evs y los puntos base
        void returnStats(); // Devuelve las estadisticas del pokemon a la normalidad, por si hubiera movimientos que potenciasen las estadisticas

    friend class Estados;
    friend class Movimientos;
    friend class MovimientoEstado;
};

#endif // POKEMON_H
