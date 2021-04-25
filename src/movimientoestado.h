#ifndef MOVIMIENTOESTADO_H
#define MOVIMIENTOESTADO_H

#include "pokemon.h"
#include "movimientos.h"
#include "estados.h"

class MovimientoEstado : public Movimientos , public Estados {
    public:
        MovimientoEstado();
        ~MovimientoEstado();
    private:
        void getDamage(Pokemon *atacante,Pokemon *defensor); // Se utiliza en lugar de la habitual
};

#endif // MOVIMIENTOESTADO_H
