#include "pokemon.h"
#include "estados.h"
#include "movimientos.h"
#include "movimientoestado.h"

Pokemon::Pokemon() {
    name = "MISSIGNO";
}

Pokemon::Pokemon(std::string _name,std::string _t1, std::string _t2, uint _level, struct stats _ivs, struct stats _evs, struct stats _base) {
    name = _name;
    type.setPrimary(Tipo::getTypeByName(_t1));
    type.setSecondary(Tipo::getTypeByName(_t2));
    level = _level;
    IVs = _ivs;
    EVs = _evs;
    // Calcular las estadísticas con la base
    estadisticas_actuales = _base;
    estadisticas = _base;
    state = new Estados();
}

void Pokemon::addMove(Movimientos* move) {
    if (attck.size() < 4) {
        attck.push_back(move);
    } else {
        std::cout << "El pokemon ya tiene todos sus movimientos.\n";
    }
}

void Pokemon::setHP(uint newHP) {
    estadisticas_actuales.hp = newHP;
}

void Pokemon::removeMove(int i) {
    Movimientos* move = attck[i];
    attck.erase(attck.begin() + i);
    delete move;
}

uint Pokemon::getNumberMoves() {
    return attck.size();
}

void Pokemon::setSecondaryType(Tipos _second) {
    type.setSecondary(_second);
}

Movimientos* Pokemon::getMove(int i) {
    return attck[i];
}

std::string Pokemon::getName() {
    return name;
}

uint Pokemon::getHP() {
    return estadisticas_actuales.hp;
}

uint Pokemon::getHPtotal() {
    return estadisticas.hp;
}
