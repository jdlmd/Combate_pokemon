#ifndef MOVIMIENTOESTADO_H
#define MOVIMIENTOESTADO_H

#include "pokemon.h"
#include "movimientos.h"
#include "estados.h"

class MovimientoEstado : public Movimientos , public Estados {
    public:
        MovimientoEstado();
        MovimientoEstado(std::string _name, std::string _type, uint _atckORsp, uint _precision, uint _potencia, uint _pp, std::string _estado, uint _porcentaje, uint _defOR); // Constructor
        ~MovimientoEstado();
        uint getDamage(Pokemon *atacante,Pokemon *defensor); // Calcula el daño del movimiento
    private:

        uint porcentaje;
};

#endif // MOVIMIENTOESTADO_H
