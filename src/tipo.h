#ifndef TIPO_H
#define TIPO_H

#include <string>
#include "definiciones.h"

/* Clase tipo:
Un objeto Tipo guardará los dos tipos a los que puede pertenecer un pokemon,
haciendo uso del enum Tipos. Además, este mismo objeto será el encargado de
resolver la eficacio de los ataques de un determinado tipo, en función de los tipos
del pokemon que lo reciviera (Por ejemplo, fuego es fuerte contra planta, y agua
es fuerte contra fuego)
*/
class Tipo{
    private:
        Tipos primario;
        Tipos secundario;

    public:
        Tipo();
        Tipo(Tipos primario, Tipos secundario);
        Tipos getPrimary();
        Tipos getSecondary();
        std::string getPrimaryName();
        std::string getSecondaryName();
        float multiplicador(Tipos tipo); // Introduciendo un tipo, devuelve el multiplicador
        float getStab(Tipos tipo); // Calcula el stab
};

#endif // TIPO_H
