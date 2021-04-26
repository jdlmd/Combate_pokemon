#include "estados.h"

using namespace std;

Estados::Estados() {
    estado = NONE;
    turnos = -1;
    mov = true;
    solve = false;
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
    Tipos first = pokemon->type.getPrimary();
    Tipos second = pokemon->type.getSecondary();
    switch (estado) {
        case(NONE):
            break;
        case(PARALIZADO): // Caso de la parálisis completo
            if (first!=ELECTRICO && second!=ELECTRICO){ // La paralisis no afecta a tipo electrico
                turnos--;
                srand(time(NULL));
                if (rand() % 100 <= 25) { // El pokemon no se mueve
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
            }

            break;
        case(QUEMADO): // Quemado no afecta a tipo fuego
            turnos = -1;

            if (first!=FUEGO && second!=FUEGO) { // Hace daño cada turno
                pokemon->setHP(pokemon->getHP()-pokemon->getTotalHP()/16);
            }else if (!solve) { // Las estadisticas solo se las baja una vez
                pokemon->estadisticas_actuales.atack = pokemon->estadisticas_actuales.atack/2;
                    solve = true;
                }

            break;
        case(ENVENENADO): // No afecta a tipo veneno y acero, solo hace daño por turno
            turnos = -1;

            if (first!=VENENO && second!=VENENO && first!=ACERO && second!=ACERO) {
                pokemon->setHP(pokemon->getHP()-pokemon->getTotalHP()/16);
            }

            break;
        case(DORMIDO):
            turnos--;
            mov = false;

            if (!turnos) { // Si se han acabado los turnos...
                turnos = -1;
                estado = NONE;
                mov = true;
            }

            break;
        case(CONGELADO):
            if (first!=HIELO && second!=HIELO) {
                turnos = -1;
                srand(time(NULL));

                if(rand() % 100 <= 80) { // El pokemon tiene un 20% de posibilidades de librarse del estado
                    mov = false;
                }else {
                    mov = true;
                    estado = NONE;
                }
            }

            break;
    }
}

bool Estados::getMov() {
    return mov;
}

void Estados::setState(Estado estado, Pokemon* pokemon) {
    pokemon->state->estado=estado;
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

void Estados::changeState(Estado state, uint turno) {

}
