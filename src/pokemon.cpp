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
    state = new Estados();
    // Calculo de las estadisticas.
    calculateStatsFromBase( _ivs, _evs,_base);
    estadisticas_actuales=estadisticas;
}
void Pokemon::calculateStatsFromBase(struct stats _ivs, struct stats _evs, struct stats _base){
    estadisticas.hp=(uint)(0.01*(2*_base.hp+_ivs.hp+(int)(0.25*_evs.hp))*level)+level+10;
    estadisticas.attack=(uint)(0.01*(2*_base.attack+_ivs.attack+(uint)(0.25*_evs.attack))*level)+5;
    estadisticas.defense=(uint)(0.01*(2*_base.defense+_ivs.defense+(uint)(0.25*_evs.defense))*level)+5;
    estadisticas.sp_attack=(uint)(0.01*(2*_base.sp_attack+_ivs.sp_attack+(uint)(0.25*_evs.sp_attack))*level)+5;
    estadisticas.sp_defense=(uint)(0.01*(2*_base.sp_defense+_ivs.sp_defense+(uint)(0.25*_evs.sp_defense))*level)+5;
    estadisticas.speed=(uint)(0.01*(2*_base.speed+_ivs.speed+(uint)(0.25*_evs.speed))*level)+5;
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

Estados* Pokemon::getStatePtr(){
    return state;
}

uint Pokemon::getSpeed(){
    return estadisticas_actuales.speed;
}

void Pokemon::returnStats(){
    estadisticas_actuales=estadisticas;
}

Tipos Pokemon::getPrimary(){
    return type.getPrimary();
}

Tipos Pokemon::getSecondary(){
    return type.getSecondary();
}

Estado Pokemon::getState() {
    return state->getState();
}
