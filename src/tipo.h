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
        void setPrimary(Tipos _prim); // Fija el tipo primario del pokemon
        void setSecondary(Tipos _sec); // Fija el tipo secundario del pokemon
        Tipos getPrimary(); // Devuelve el tipo primario del pokemon
        Tipos getSecondary(); // Devuelve el tipo secundario del pokemon
        std::string getPrimaryName(); // Devuelve el nombre del tipo primario del pokemon
        std::string getSecondaryName(); // Devuelve el nombre del tipo secundario del pokemon
        static Tipos getTypeByName(std::string _type); // Introduciendo una cadena de caracteres con el nombre del tipo devuelve el valor que le corresponde a ese tipo
        static std::string getNamebyType(Tipos _type); // Introduciendole el tipo devuelve una cadena de caracteres con el nombre del tipo
        float multiplicador(Tipos tipo); // Introduciendo un tipo, devuelve el multiplicador
        float getStab(Tipos tipo); // Calcula el stab (daño adicional por afinidad de tipos)
        std::string eficacia(float mult); // Indica si es supereficaz o poco eficaz

};

#endif // TIPO_H
