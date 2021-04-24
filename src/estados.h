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
        void setState(); // Fija el estado del pokemon
        void setTurns(); // Fija los turnos
        void changeState(Estado state); // Cambia el estado
        virtual void resolveState(Pokemon* receiver); // Resuelve el estado del pokemon
    friend class Pokemon;
 };

#endif // ESTADOS_H
