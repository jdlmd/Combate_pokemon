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
    return 0;
}
