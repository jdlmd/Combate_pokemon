#include "estados.h"

Estados::Estados() {
    estado = NONE;
    turnos = -1;
    mov = true;
    solve = false;
}

Estados::~Estados() {

}

void Estados::resolveState(Pokemon *pokemon) {
    switch (estado) {
        case(NONE):
            break;
        case(PARALIZADO): // Caso de la parálisis completo
            turnos--;
            srand(time(NULL));

            if(rand() % 100 <= 25) { // El pokemon no se mueve
                mov = false;
            }

            if (!solve) {
                pokemon->estadisticas_actuales.speed = pokemon->estadisticas_actuales.speed/2;
                solve = true;
            }

            if (!turnos) { // Si se han acabado los turnos...
                turnos = -1;
                estado = NONE;
                pokemon->estadisticas_actuales.speed = pokemon->estadisticas_actuales.speed*2;
                solve = false;
            }

            break;
        case(QUEMADO):
            break;
        default:
            break;
    }
}

Estado Estados::getStateByName(std::string _state){
    return NONE;
}
