#ifndef MOVIMIENTOS_H
#define MOVIMIENTOS_H

#include "tipo.h"
#include "string"
#include "pokemon.h"

/* Clase movimientos:
La clase movimientos se encargará de guardar los datos a utilizar en la resolución
del uso de un movimiento por parte de un Pokemon. Por tanto, sus métodos deberán
ser capaz de leer la zona de memoria donde se guarde el pokemon.
*/
class Movimientos {
    public:
        Movimientos();
        Movimientos(std::string _name, std::string _type, uint _atckORsp, uint _precision, uint _potencia, uint _pp, uint _defORspdef); // Constructor
        virtual ~Movimientos();
        std::string getName();
        uint getPPtotal();
        uint getPPremaining();
        std::string getType();
        virtual uint getDamage(Pokemon* atacante,Pokemon* defensor); // Calcular el daño
    protected:
        std::string nombre; // Nombre del movimiento
        Tipos type; // Tipo del movimiento
        uint precision; // Precisión del movimiento
        uint potencia; // Potencia del movimiento
        uint ppTotal; // PP's totales
        uint ppRemaining; // PP's actuales
        uint atckORsp;  // Movimiento fisico (0), especial(1) o de estado(2)
        uint defORspdef; // Defensa fisica (false) o especial (true)


};

#endif // MOVIMIENTOS_H
