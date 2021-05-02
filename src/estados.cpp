#include "estados.h"

using namespace std;

/* Constructor por defecto: pone el estado a NONE, el pokemon se puede mover y dura infinitos turnos */
Estados::Estados() {
    estado = NONE;
    turnos = -1;
    mov = true;
}

/* Destructor, vacío a propósito */
Estados::~Estados() {

}

/* Devuelve una cadena de caracteres con el estado que tiene el pokemon */
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

/* Resuelve el estado del pokemon, esto es aplicarle el efecto del estado cada turno y reducir
   la duración en turnos del estado si éste no es infinito. Los efectos del estados pueden ser
   reducción de la vida cada turno o que no se pueda mover */
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

/* Devuelve si el pokemon puede moverse o no, siendo false que no puede moverse */
bool Estados::getMov() {
    return mov;
}

/* Introduciendo una cadena de caracteres con el nombre del estado devuelve el valor que hace
   referencia a ese estado */
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

/* Introduciendo una variable tipo 'estado' devuelve una cadena de caracteres con el nombre
   del estado */
std::string Estados::getNameByState(Estado _state) {
    switch (_state) {
        case(NONE):
            return "NONE";
        case(QUEMADO):
            return "QUEMADO";
        case(PARALIZADO):
            return "PARALIZADO";
        case(ENVENENADO):
            return "ENVENENADO";
        case(DORMIDO):
            return "DORMIDO";
        case(CONGELADO):
            return "CONGELADO";
        default:
            return "NONE";
    }
}

/* Cambia el estado de un pokemon, los valores que se introducen son el nuevo estado y el pokemon al
   que afectará este nuevo estado. Si ya tenía un estado anteriormente devuelve las estadísticas del
   pokemon (alteradas por el estado) a la normalidad, esto ocurre en el caso de paralizado y quemado
   que reducían la velocidad y el ataque respectivamente. Al aplicar un estado nuevo se cambian las
   estadísticas que correspondan y el pokemon sufre los efectos del estado en el mismo turno en el
   que le meten el estado */
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
        mov = true;
        turnos = -1;
        mov = true;
    }else {
        estado = NONE;
        turnos = -1;
        mov = true;
    }
}

/* Devuelve el estado actual del pokemon */
Estado Estados::getState(){
    return estado;
}

