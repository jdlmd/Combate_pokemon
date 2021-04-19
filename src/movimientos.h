#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include "tipos.h"

class Movimientos {
    public:
        Movimientos();
        string nombre;
        int precision;
        int  potencia;

    protected:
        virtual void getDamage();
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
