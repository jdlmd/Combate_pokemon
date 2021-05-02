#include "tipo.h"

using namespace std;

/* Constructor por defecto: Pone los tipos primario y secundario a ninguno*/
Tipo::Tipo() {
    primario = NINGUNO;
    secundario = NINGUNO;
}

/* Fija el tipo principal del pokemon al tipo que se le introduce */
void Tipo::setPrimary(Tipos _prim) {
    primario = _prim;
}

/* Fija el tipo secundario del pokemon al tipo que se le introduce */
void Tipo::setSecondary(Tipos _sec) {
    secundario = _sec;
}

/* Devuelve el tipo principal del pokemon */
Tipos Tipo::getPrimary() {
    return primario;
}

/* Devuelve el tipo secundario del pokemon */
Tipos Tipo::getSecondary() {
    return secundario;
}

/* Devuelve como cadena de caracteres el tipo principal del pokemon */
string Tipo::getPrimaryName() {
    switch (primario) {
        case(NINGUNO):
            return "NINGUNO";
        case(NORMAL):
            return "NORMAL";
        case(FUEGO):
            return "FUEGO";
        case(LUCHA):
            return "LUCHA";
        case(AGUA):
            return "AGUA";
        case(VOLADOR):
            return "VOLADOR";
        case(PLANTA):
            return "PLANTA";
        case(ELECTRICO):
            return "ELECTRICO";
        case(VENENO):
            return "VENENO";
        case(TIERRA):
            return "TIERRA";
        case(PSIQUICO):
            return "PSIQUICO";
        case(ROCA):
            return "ROCA";
        case(HIELO):
            return "HIELO";
        case(BICHO):
            return "BICHO";
        case(DRAGON):
            return "DRAGON";
        case(FANTASMA):
            return "FANTASMA";
        case(SINIESTRO):
            return "SINIESTRO";
        case(ACERO):
            return "ACERO";
        case(HADA):
            return "HADA";
        default:
            return "NINGUNO";
    }
}

/* Devuelve como cadena de caracteres el tipo secundario del pokemon */
string Tipo::getSecondaryName() {
    switch (secundario) {
        case(NINGUNO):
            return "NINGUNO";
        case(NORMAL):
            return "NORMAL";
        case(FUEGO):
            return "FUEGO";
        case(LUCHA):
            return "LUCHA";
        case(AGUA):
            return "AGUA";
        case(VOLADOR):
            return "VOLADOR";
        case(PLANTA):
            return "PLANTA";
        case(ELECTRICO):
            return "ELECTRICO";
        case(VENENO):
            return "VENENO";
        case(TIERRA):
            return "TIERRA";
        case(PSIQUICO):
            return "PSIQUICO";
        case(ROCA):
            return "ROCA";
        case(HIELO):
            return "HIELO";
        case(BICHO):
            return "BICHO";
        case(DRAGON):
            return "DRAGON";
        case(FANTASMA):
            return "FANTASMA";
        case(SINIESTRO):
            return "SINIESTRO";
        case(ACERO):
            return "ACERO";
        case(HADA):
            return "HADA";
        default:
            return "NINGUNO";
    }
}

/* Implementación de la tabla de tipos: Introduciendo el tipo del ataque devuelve el
   valor por el que debe multiplicarse el daño según los tipos primario y secundario
   del pokemon, pudiendo ser 0, 0.25, 0.5, 1, 2 y 4 */
float Tipo::multiplicador(Tipos tipo) {
    float value = 1;

    switch(tipo) {
        case(NORMAL):
            if (primario == ACERO || secundario == ACERO)
                value /= 2;
            if (primario == ROCA || secundario == ROCA)
                value /= 2;
            if (primario == FANTASMA || secundario == FANTASMA)
                value = 0;
            break;
        case(FUEGO):
            if (primario == ACERO || secundario == ACERO)
                value *= 2;
            if (primario == HIELO || secundario == HIELO)
                value *= 2;
            if (primario == PLANTA || secundario == PLANTA)
                value *= 2;
            if (primario == BICHO || secundario == BICHO)
                value *= 2;
            if (primario == ROCA || secundario == ROCA)
                value /= 2;
            if (primario == FUEGO || secundario == FUEGO)
                value /= 2;
            if (primario == AGUA || secundario == AGUA)
                value /= 2;
            if (primario == DRAGON || secundario == DRAGON)
                value /= 2;
            break;
        case(LUCHA):
            if (primario == ACERO || secundario == ACERO)
                value *= 2;
            if (primario == HIELO || secundario == HIELO)
                value *= 2;
            if (primario == NORMAL || secundario == NORMAL)
                value *= 2;
            if (primario == ROCA || secundario == ROCA)
                value *= 2;
            if (primario == SINIESTRO || secundario == SINIESTRO)
                value *= 2;
            if (primario == BICHO || secundario == BICHO)
                value /= 2;
            if (primario == HADA || secundario == HADA)
                value /= 2;
            if (primario == PSIQUICO || secundario == PSIQUICO)
                value /= 2;
            if (primario == VENENO || secundario == VENENO)
                value /= 2;
            if (primario == VOLADOR || secundario == VOLADOR)
                value /= 2;
            if (primario == FANTASMA || secundario == FANTASMA)
                value = 0;
            break;
        case(AGUA):
            if (primario == FUEGO || secundario == FUEGO)
                value *= 2;
            if (primario == ROCA || secundario == ROCA)
                value *= 2;
            if (primario == TIERRA || secundario == TIERRA)
                value *= 2;
            if (primario == PLANTA || secundario == PLANTA)
                value /= 2;
            if (primario == ELECTRICO || secundario == ELECTRICO)
                value /= 2;
            if (primario == DRAGON || secundario == DRAGON)
                value /= 2;
            break;
        case(VOLADOR):
            if (primario == BICHO || secundario == BICHO)
                value *= 2;
            if (primario == LUCHA || secundario == LUCHA)
                value *= 2;
            if (primario == PLANTA || secundario == PLANTA)
                value *= 2;
            if (primario == ACERO || secundario == ACERO)
                value /= 2;
            if (primario == ELECTRICO || secundario == ELECTRICO)
                value /= 2;
            if (primario == ROCA || secundario == ROCA)
                value /= 2;
            break;
        case(PLANTA):
            if (primario == AGUA || secundario == AGUA)
                value *= 2;
            if (primario == ROCA || secundario == ROCA)
                value *= 2;
            if (primario == TIERRA || secundario == TIERRA)
                value *= 2;
            if (primario == ACERO || secundario == ACERO)
                value /= 2;
            if (primario == BICHO || secundario == BICHO)
                value /= 2;
            if (primario == DRAGON || secundario == DRAGON)
                value /= 2;
            if (primario == FUEGO || secundario == FUEGO)
                value /= 2;
            if (primario == PLANTA || secundario == PLANTA)
                value /= 2;
            if (primario == VENENO || secundario == VENENO)
                value /= 2;
            if (primario == VOLADOR || secundario == VOLADOR)
                value /= 2;
            break;
        case(ELECTRICO):
            if (primario == AGUA || secundario == AGUA)
                value *= 2;
            if (primario == VOLADOR || secundario == VOLADOR)
                value *= 2;
            if (primario == DRAGON || secundario == DRAGON)
                value /= 2;
            if (primario == ELECTRICO || secundario == ELECTRICO)
                value /= 2;
            if (primario == PLANTA || secundario == PLANTA)
                value /= 2;
            if (primario == TIERRA || secundario == TIERRA)
                value = 0;
            break;
        case(VENENO):
            if (primario == HADA || secundario == HADA)
                value *= 2;
            if (primario == PLANTA || secundario == PLANTA)
                value *= 2;
            if (primario == FANTASMA || secundario == FANTASMA)
                value /= 2;
            if (primario == ROCA || secundario == ROCA)
                value /= 2;
            if (primario == TIERRA || secundario == TIERRA)
                value /= 2;
            if (primario == VENENO || secundario == VENENO)
                value /= 2;
            if (primario == ACERO || secundario == ACERO)
                value = 0;
            break;
        case(TIERRA):
            if (primario == ACERO || secundario == ACERO)
                value *= 2;
            if (primario == ELECTRICO || secundario == ELECTRICO)
                value *= 2;
            if (primario == ROCA || secundario == ROCA)
                value *= 2;
            if (primario == VENENO || secundario == VENENO)
                value *= 2;
            if (primario == FUEGO || secundario == FUEGO)
                value *= 2;
            if (primario == BICHO || secundario == BICHO)
                value /= 2;
            if (primario == PLANTA || secundario == PLANTA)
                value /= 2;
            if (primario == VOLADOR || secundario == VOLADOR)
                value = 0;
            break;
        case(PSIQUICO):
            if (primario == LUCHA || secundario == LUCHA)
                value *= 2;
            if (primario == VENENO || secundario == VENENO)
                value *= 2;
            if (primario == ACERO || secundario == ACERO)
                value *= 2;
            if (primario == PSIQUICO || secundario == PSIQUICO)
                value /= 2;
            if (primario == SINIESTRO || secundario == SINIESTRO)
                value = 0;
            break;
        case(ROCA):
            if (primario == BICHO || secundario == BICHO)
                value *= 2;
            if (primario == FUEGO || secundario == FUEGO)
                value *= 2;
            if (primario == HIELO || secundario == HIELO)
                value *= 2;
            if (primario == VOLADOR || secundario == VOLADOR)
                value *= 2;
            if (primario == ACERO || secundario == ACERO)
                value /= 2;
            if (primario == LUCHA || secundario == LUCHA)
                value /= 2;
            if (primario == TIERRA || secundario == TIERRA)
                value /= 2;
            break;
        case(HIELO):
            if (primario == DRAGON || secundario == DRAGON)
                value *= 2;
            if (primario == PLANTA || secundario == PLANTA)
                value *= 2;
            if (primario == TIERRA || secundario == TIERRA)
                value *= 2;
            if (primario == VOLADOR || secundario == VOLADOR)
                value *= 2;
            if (primario == ACERO || secundario == ACERO)
                value /= 2;
            if (primario == AGUA || secundario == AGUA)
                value /= 2;
            if (primario == FUEGO || secundario == FUEGO)
                value /= 2;
            if (primario == HIELO || secundario == HIELO)
                value /= 2;
            break;
        case(BICHO):
            if (primario == PSIQUICO || secundario == PSIQUICO)
                value *= 2;
            if (primario == PLANTA || secundario == PLANTA)
                value *= 2;
            if (primario == SINIESTRO || secundario == SINIESTRO)
                value *= 2;
            if (primario == ACERO || secundario == ACERO)
                value /= 2;
            if (primario == FANTASMA || secundario == FANTASMA)
                value /= 2;
            if (primario == FUEGO || secundario == FUEGO)
                value /= 2;
            if (primario == HADA || secundario == HADA)
                value /= 2;
            if (primario == LUCHA || secundario == LUCHA)
                value /= 2;
            if (primario == VENENO || secundario == VENENO)
                value /= 2;
            if (primario == VOLADOR || secundario == VOLADOR)
                value /= 2;
            break;
        case(DRAGON):
            if (primario == DRAGON || secundario == DRAGON)
                value *= 2;
            if (primario == ACERO || secundario == ACERO)
                value /= 2;
            if (primario == HADA || secundario == HADA)
                value = 0;
            break;
        case(FANTASMA):
            if (primario == FANTASMA || secundario == FANTASMA)
                value *= 2;
            if (primario == PSIQUICO || secundario == PSIQUICO)
                value *= 2;
            if (primario == SINIESTRO || secundario == SINIESTRO)
                value /= 2;
            if (primario == NORMAL || secundario == NORMAL)
                value = 0;
            break;
        case(SINIESTRO):
            if (primario == FANTASMA || secundario == FANTASMA)
                value *= 2;
            if (primario == PSIQUICO || secundario == PSIQUICO)
                value *= 2;
            if (primario == HADA || secundario == HADA)
                value /= 2;
            if (primario == SINIESTRO || secundario == SINIESTRO)
                value /= 2;
            if (primario == LUCHA || secundario == LUCHA)
                value /= 2;
            break;
        case(ACERO):
            if (primario == HADA || secundario == HADA)
                value *= 2;
            if (primario == HIELO || secundario == HIELO)
                value *= 2;
            if (primario == ROCA || secundario == HADA)
                value *= 2;
            if (primario == ACERO || secundario == ACERO)
                value /= 2;
            if (primario == AGUA || secundario == AGUA)
                value /= 2;
            if (primario == ELECTRICO || secundario == ELECTRICO)
                value /= 2;
            if (primario == FUEGO || secundario == FUEGO)
                value /= 2;
            break;
        case(HADA):
            if (primario == DRAGON || secundario == DRAGON)
                value *= 2;
            if (primario == LUCHA || secundario == LUCHA)
                value *= 2;
            if (primario == SINIESTRO || secundario == SINIESTRO)
                value *= 2;
            if (primario == ACERO || secundario == ACERO)
                value /= 2;
            if (primario == FUEGO || secundario == FUEGO)
                value /= 2;
            if (primario == VENENO || secundario == VENENO)
                value /= 2;
            break;
        default:
            value = 1;
            break;
    }
    return value;
}

/* Devuelve el valor del stab, siendo éste un multiplicador al daño que causará al rival
   si uno de los tipos del pokemon es igual al tipo del ataque que vaya a realizar */
float Tipo::getStab(Tipos tipo) {
    float stab = 1;

    if (tipo == primario || tipo == secundario) {
        stab = 1.5;
    }
    return stab;
}

/* Según el valor obtenido en el método 'multiplicador' devuelve una cadena de caracteres
   que indica la eficacia del ataque */
string Tipo::eficacia(float mult) {
    string effective;
    if (mult == 0) {
        effective = "No ha tenido efecto...";
    }else if (mult == 0.25) {
        effective = "Apenas tiene eficacia...";
    }else if (mult == 0.5) {
        effective = "No es muy eficaz...";
    }else if (mult == 1) {
        effective = " ";
    }else if (mult == 2) {
        effective = "Es muy eficaz";
    }else if (mult == 4) {
        effective = "¡Es supereficaz!";
    } else {
        effective = "";
    }
    return effective;
}

/* Introduciendo una cadena de caracteres con el tipo devuelve el valor que hace
   referencia a ese tipo */
Tipos Tipo::getTypeByName(std::string _type) {
    if (_type == "NINGUNO") {
        return NINGUNO;
    }else if (_type == "NORMAL") {
        return NORMAL;
    }else if (_type == "FUEGO") {
        return FUEGO;
    }else if (_type == "LUCHA") {
        return LUCHA;
    }else if (_type == "AGUA") {
        return AGUA;
    }else if (_type == "VOLADOR") {
        return VOLADOR;
    }else if (_type == "PLANTA") {
        return PLANTA;
    }else if (_type == "ELECTRICO") {
        return ELECTRICO;
    }else if (_type == "VENENO") {
        return VENENO;
    }else if (_type == "TIERRA") {
        return TIERRA;
    }else if (_type == "PSIQUICO") {
        return PSIQUICO;
    }else if (_type == "ROCA") {
        return ROCA;
    }else if (_type == "HIELO") {
        return HIELO;
    }else if (_type == "BICHO") {
        return BICHO;
    }else if (_type == "DRAGON") {
        return DRAGON;
    }else if (_type == "FANTASMA") {
        return FANTASMA;
    }else if (_type == "SINIESTRO") {
        return SINIESTRO;
    }else if (_type == "ACERO") {
        return ACERO;
    }else if (_type == "HADA") {
        return HADA;
    }else {
        return NINGUNO;
    }
}

/* Introduciendo una variable 'tipo' devuelve una cadena de caracteres con nombre del tipo */
string Tipo::getNamebyType(Tipos _type) {
    switch (_type) {
        case(NINGUNO):
            return "NINGUNO";
        case(NORMAL):
            return "NORMAL";
        case(FUEGO):
            return "FUEGO";
        case(LUCHA):
            return "LUCHA";
        case(AGUA):
            return "AGUA";
        case(VOLADOR):
            return "VOLADOR";
        case(PLANTA):
            return "PLANTA";
        case(ELECTRICO):
            return "ELECTRICO";
        case(VENENO):
            return "VENENO";
        case(TIERRA):
            return "TIERRA";
        case(PSIQUICO):
            return "PSIQUICO";
        case(ROCA):
            return "ROCA";
        case(HIELO):
            return "HIELO";
        case(BICHO):
            return "BICHO";
        case(DRAGON):
            return "DRAGON";
        case(FANTASMA):
            return "FANTASMA";
        case(SINIESTRO):
            return "SINIESTRO";
        case(ACERO):
            return "ACERO";
        case(HADA):
            return "HADA";
        default:
            return "NINGUNO";
    }
}
