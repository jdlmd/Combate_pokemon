#include "estados.h"

Estados::Estados() {
    estado = NONE;
    turnos = -1;
    mov = true;
    solve = false;
}

Estados::~Estados() {

}

void Estados::resolveState(Pokemon* receiver) {
    return;
}
