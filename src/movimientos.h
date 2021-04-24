#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include "tipos.h"
#include "string"
#include "pokemon.h"
#include "estados.h"

using namespace std;


/* Clase movimientos:
La clase movimientos se encargará de guardar los datos a utilizar en la resolución
del uso de un movimiento por parte de un Pokemon. Por tanto, sus métodos deberán
ser capaz de leer la zona de memoria donde se guarde el pokemon.
*/
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
    private:
        void getDamage(Pokemon *atacante,Pokemon *defensor); // Se utiliza en lugar de la habitual
};

#endif // MOVIMIENTOS_H
