#include "tipo.h"

using namespace std;

Tipo::Tipo() {
    primario = NINGUNO;
    secundario = NINGUNO;
}

Tipos Tipo::getPrimary() {
    return primario;
}

Tipos Tipo::getSecondary() {
    return secundario;
}

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
        case(SINIESTO):
            return "SINIESTRO";
        case(ACERO):
            return "ACERO";
        case(HADA):
            return "HADA";
        default:
            return "NINGUNO";
    }
}

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
        case(SINIESTO):
            return "SINIESTRO";
        case(ACERO):
            return "ACERO";
        case(HADA):
            return "HADA";
        default:
            return "NINGUNO";
    }
}

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
            if (primario == SINIESTO || secundario == SINIESTO)
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
            if (primario == FANTASMA || secundario == FANTASMA)
                value = 0;
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
            if (primario == SINIESTO || secundario == SINIESTO)
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
            if (primario == SINIESTO || secundario == SINIESTO)
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
            if (primario == SINIESTO || secundario == SINIESTO)
                value /= 2;
            if (primario == NORMAL || secundario == NORMAL)
                value = 0;
            break;
        case(SINIESTO):
            if (primario == FANTASMA || secundario == FANTASMA)
                value *= 2;
            if (primario == PSIQUICO || secundario == PSIQUICO)
                value *= 2;
            if (primario == HADA || secundario == HADA)
                value /= 2;
            if (primario == SINIESTO || secundario == SINIESTO)
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
            if (primario == SINIESTO || secundario == SINIESTO)
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

float Tipo::getStab(Tipos tipo) {
    float stab = 1;

    if (tipo == primario || tipo == secundario) {
        stab = 1.5;
    }
    return stab;
}

string Tipo::eficacia(float mult) {
    string effective;
    if (mult == 0) {
        effective = "No ha tenido efecto...";
    }else if (mult == 1) {
        effective = "No es muy eficaz...";
    }else if (mult == 1) {
        effective = " ";
    }else if (mult == 2) {
        effective = "Es muy eficaz";
    }else if (mult == 4) {
        effective = "¡Es supereficaz!";
    }
    return effective;
}

