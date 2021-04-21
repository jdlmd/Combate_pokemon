#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include "tipos.h"
#include "string"

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
};

class Movimiento_estado : public Movimientos {
    public:
        Movimiento_estado();
    // Enum estados
    private:
        void getDamage();
        void resolveState();
};

class Movimiento_caracteristicas : public Movimientos {
    public:
        Movimiento_caracteristicas();
    private:
        void getDamage();
        void resolveStat();
};

#endif // MOVIMIENTOS_H
