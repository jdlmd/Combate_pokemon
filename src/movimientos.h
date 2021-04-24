#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include "tipos.h"
#include "string"
#include "pokemon.h"
#include "estados.h"

using namespace std;

class Movimientos {
    public:
        Movimientos(); // Constructor

    protected:
        string nombre; // Nombre del movimiento
        Tipo type; // Tipo del movimiento
        uint precision; // Precisión del movimiento
        uint potencia; // Potencia del movimiento
        uint ppTotal; // PP's totales
        uint ppRemaining; // PP's actuales

        virtual void getDamage(); // Calcular el daño
        void resolveStat(); // Resolver características
};

class Movimiento_estado : public Movimientos , public Estados {
    public:
        Movimiento_estado();
    // Enum estados
    private:
        void getDamage();
};

#endif // MOVIMIENTOS_H
