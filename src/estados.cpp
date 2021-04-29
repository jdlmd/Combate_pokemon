#include "estados.h"

using namespace std;

Estados::Estados() {
    estado = NONE;
    turnos = -1;
    mov = true;
}

Estados::~Estados() {

}

string Estados::getStateName() {
    switch (estado) {
        case(NONE):
            return "NINGUNO";
        case(PARALIZADO):
            return "PARALIZADO";
        case(QUEMADO):
            return "QUEMADO";
        case(ENVENENADO):
            return "ENVENENADO";
        case(DORMIDO):
            return "DORMIDO";
        case(CONGELADO):
            return "CONGELADO";
        default:
            return "NINGUNO";
    }
}

void Estados::resolveState(Pokemon *pokemon) {
    srand(time(NULL));
    switch (estado) {
        case(NONE):
            break;
        case(PARALIZADO): // Caso de la parálisis completo
            if (!turnos) { // Si se han acabado los turnos...
                changeState(NONE, pokemon);
            }
            if (rand() % 100 <= 25) { // El pokemon no se mueve
                mov = false;
            }else {
                mov = true;
            }
            turnos--;
            break;
        case(QUEMADO): // Hace daño cada turno y no afecta a tipo fuego
                pokemon->setHP(pokemon->estadisticas_actuales.hp-pokemon->estadisticas.hp/16);
            break;
        case(ENVENENADO): // No afecta a tipo veneno y acero, solo hace daño por turno
                pokemon->setHP(pokemon->estadisticas_actuales.hp-pokemon->estadisticas.hp/16);
            break;
        case(DORMIDO):
            mov = false;
            if (!turnos) { // Si se han acabado los turnos...
                changeState(NONE, pokemon);
            }
            turnos--;
            break;
        case(CONGELADO):
            if(rand() % 100 <= 80) { // El pokemon tiene un 20% de posibilidades de librarse del estado
                mov = false;
            }else {
                changeState(NONE, pokemon);
            }
            break;
        default:
            changeState(NONE,pokemon);
    }
}

bool Estados::getMov() {
    return mov;
}

Estado Estados::getStateByName(std::string _state) {
    if (_state == "NINGUNO") {
        return NONE;
    }else if (_state == "PARALIZADO") {
        return PARALIZADO;
    }else if (_state == "QUEMADO") {
        return QUEMADO;
    }else if (_state == "ENVENENADO") {
        return ENVENENADO;
    }else if (_state == "DORMIDO") {
        return DORMIDO;
    }else if (_state == "CONGELADO") {
        return CONGELADO;
    }else {
        return NONE;
    }
}

void Estados::changeState(Estado _state, Pokemon* pokemon) {
    srand(time(NULL));
    Tipos first = pokemon->type.getPrimary();
    Tipos second = pokemon->type.getSecondary();
    /* Se restablecen las características que eran modificadas por el estado que tenían */
    if (estado == PARALIZADO) {
        pokemon->estadisticas_actuales.speed = pokemon->estadisticas_actuales.speed*2;
    }else if (estado == QUEMADO) {
        pokemon->estadisticas_actuales.attack = pokemon->estadisticas_actuales.attack*2;
    }
    /* Se cambia de estado al pokemon aplicando los efectos del estado desde el momento en el que se
       ve afectado por el estado */
    if (_state == PARALIZADO && first != ELECTRICO && second != ELECTRICO) { // No afecta a tipo electrico
        turnos = round(1+rand()%5);
        if (rand() % 100 <= 25) { // El pokemon no se mueve
            mov = false;
        } else {
            mov = true;
        }
        pokemon->estadisticas_actuales.speed = pokemon->estadisticas_actuales.speed/2;
        estado = _state;
    }else if (_state == QUEMADO && first != FUEGO && second != FUEGO) { // No afecta a tipo fuego
        turnos = -1;
        pokemon->estadisticas_actuales.attack = pokemon->estadisticas_actuales.attack/2; // Baja las estadisticas
        estado = _state;
        mov = true;
    }else if (_state == ENVENENADO && first != ACERO && second != ACERO && first != VENENO && second != VENENO) { // No afecta a tipo acero ni a veneno
        turnos = -1;
        estado = _state;
        mov = true;
    }else if (_state == DORMIDO) {
        turnos = round(1+rand()%3);
        mov = false;
        estado = _state;
    }else if (_state == CONGELADO && first != HIELO && second != HIELO) { // No afecta a tipo hielo
        turnos = -1;
        mov = false;
        estado = _state;
    }else if (_state == NONE) {
        estado = _state;

        turnos = -1;
        mov = true;
    }else {
        estado = NONE;
        turnos = -1;
        mov = true;
    }
}

