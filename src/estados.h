#ifndef ESTADOS_H
#define ESTADOS_H

#include <time.h>
#include <random>
#include "pokemon.h"
#include "definiciones.h"

/* Clase estados:
La clase estados guardará un enum de tipo estado, que servirá posteriormente para
resolver los turnos de cada pokemon. Cada estado tendrá una duración, expresado por
la variable turnos. Haciendo uso de las banderas mov y solve, se determinará si el pokemon
puede moverse .o si se ha solucionado los stats del pokemon en la entrada del Stat.
*/
class Estados {
    public:
        Estados();
        ~Estados();
        std::string getStateName(); // Devuelve un cadena de caracteres con el nombre del estado que tiene el pokemon
        bool getMov(); // Indica si el pokemon se puede mover o no
        Estado getState(); // Devuelve el estado del pokemon
        void changeState(Estado _state, Pokemon* receiver); // Cambia el estado
        static Estado getStateByName(std::string _state); // Introduciendole una cadena de caracteres con el nombre del estado devuelve  el valor que le corresponde a ese estado
        static std::string getNameByState(Estado _state); // Introduciendole un estado devuelve un cadena de caracteres con el nombre del estado
        void resolveState(Pokemon* receiver); // Resuelve el estado del pokemon

    protected:
        Estado estado;
        uint turnos; // Turnos que dura el estado, siendo -1 = Infinito
        bool mov; // Indica si puede moverse o no el pokemon

 };

#endif // ESTADOS_H
