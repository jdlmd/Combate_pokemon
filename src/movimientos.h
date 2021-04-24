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
        uint atckORsp;  // Movimiento fisico (0), especial(1) o de estado(2)
        bool defORspdef; // Defensa fisica (false) o especial (true)
        virtual void getDamage(Pokemon *atacante,Pokemon *defensor); // Calcular el daño

};

class Movimiento_estado : public Movimientos , public Estados {
    public:
        Movimiento_estado();
    // Enum estados
    private:

        void getDamage(Pokemon *atacante,Pokemon *defensor);
        void resolveState();
};

class Movimiento_caracteristicas : public Movimientos {
    public:
        Movimiento_caracteristicas();
    private:
        void getDamage(Pokemon *atacante,Pokemon *defensor);
        void resolveStat();
};

#endif // MOVIMIENTOS_H
