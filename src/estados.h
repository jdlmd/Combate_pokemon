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
        std::string getStateName();
        bool getMov();
    protected:
        Estado estado;
        uint turnos; // -1 = Infinito
        bool mov;
        void changeState(Estado _state, Pokemon* receiver); // Cambiar el estado
        void resolveState(Pokemon* receiver); // Resuelve el estado del pokemon
        static Estado getStateByName(std::string _state);
 };

#endif // ESTADOS_H
