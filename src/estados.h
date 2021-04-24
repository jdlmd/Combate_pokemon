#ifndef ESTADOS_H
#define ESTADOS_H

#include "definiciones.h"
#include "pokemon.h"
#include "movimientos.h"
#include <time.h>
#include <random>

class Estados {
    public:
        Estados();
        ~Estados();
        std::string getStateName();
        bool getMov();
    protected:
        Estado estado;
        short int turnos; // -1 = Infinito
        bool mov;
        bool solve;
        void setState(Estado state); // Fija el estado del pokemon
        void setTurns(); // Fija los turnos
        virtual void resolveState(Pokemon* receiver); // Resuelve el estado del pokemon
 };

#endif // ESTADOS_H
