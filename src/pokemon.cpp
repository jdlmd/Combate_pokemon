#include "pokemon.h"
#include "estados.h"
#include "movimientos.h"
#include "movimientoestado.h"

/* Constructor por defecto del pokemon si no recibe argumentos de entrada */
Pokemon::Pokemon() {
    name = "MISSIGNO";
}

/* Destructor del pokemon */
Pokemon::~Pokemon(){
    for (uint i = 0 ; i < attck.size() ; i++) {
        delete attck[i];
    }
}

/* Constructor del pokemon */
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

/* Calcula las distintas estadisticas base del pokemon desde los datos de ivs, evs y puntos base */
void Pokemon::calculateStatsFromBase(struct stats _ivs, struct stats _evs, struct stats _base){
    estadisticas.hp=(uint)(0.01*(2*_base.hp+_ivs.hp+(int)(0.25*_evs.hp))*level)+level+10;
    estadisticas.attack=(uint)(0.01*(2*_base.attack+_ivs.attack+(uint)(0.25*_evs.attack))*level)+5;
    estadisticas.defense=(uint)(0.01*(2*_base.defense+_ivs.defense+(uint)(0.25*_evs.defense))*level)+5;
    estadisticas.sp_attack=(uint)(0.01*(2*_base.sp_attack+_ivs.sp_attack+(uint)(0.25*_evs.sp_attack))*level)+5;
    estadisticas.sp_defense=(uint)(0.01*(2*_base.sp_defense+_ivs.sp_defense+(uint)(0.25*_evs.sp_defense))*level)+5;
    estadisticas.speed=(uint)(0.01*(2*_base.speed+_ivs.speed+(uint)(0.25*_evs.speed))*level)+5;
}

/* Añade un movimiento al pokemon, como máximo puede tener 4 movimientos */
void Pokemon::addMove(Movimientos* move) {
    if (attck.size() < 4) {
        attck.push_back(move);
    } else {
        std::cout << "El pokemon ya tiene todos sus movimientos.\n";
    }
}

/* Fija la vida actual del pokemon */
void Pokemon::setHP(uint newHP) {
    estadisticas_actuales.hp = newHP;
}

/* Elimina un movimiento del pokemon */
void Pokemon::removeMove(int i) {
    Movimientos* move = attck[i];
    attck.erase(attck.begin() + i);
    delete move;
}

/* Devuelve el numero de movimientos que tiene un pokemon */
uint Pokemon::getNumberMoves() {
    return attck.size();
}

/* Fija el tipo secundario del pokemon, ya que al evolucionar el pokemon sólo
   cambiaría su tipo secundario, finalmente este caso no se ha contemplado en el ejercicio */
void Pokemon::setSecondaryType(Tipos _second) {
    type.setSecondary(_second);
}

/* Devuelve el puntero de un movimiento del pokemon */
Movimientos* Pokemon::getMove(int i) {
    return attck[i];
}

/* Devuelve el nombre del pokemon */
std::string Pokemon::getName() {
    return name;
}

/* Devuelve la vida actual del pokemon */
int Pokemon::getHP() {
    return estadisticas_actuales.hp;
}

/* Devuelve la vida total del pokemon */
int Pokemon::getHPtotal() {
    return estadisticas.hp;
}

/* Devuelve un puntero de estados del pokemon, para que pueda ser modificado */
Estados* Pokemon::getStatePtr(){
    return state;
}

/* Devuelve la velocidad del pokemon */
uint Pokemon::getSpeed(){
    return estadisticas_actuales.speed;
}

/* Devuelve las estadísticas del pokemon a la normalidad por si se hubiera usado un movimiento
   que aumentase sus estadísticas durante el combate */
void Pokemon::returnStats(){
    estadisticas_actuales=estadisticas;
}

/* Devuelve el tipo primario del pokemon */
Tipos Pokemon::getPrimary(){
    return type.getPrimary();
}

/* Devuelve el tipo secundario del pokemon */
Tipos Pokemon::getSecondary(){
    return type.getSecondary();
}

/* Devuelve el estado del pokemon */
Estado Pokemon::getState() {
    return state->getState();
}

/* Devuelve el nivel del pokemon */
uint Pokemon::getLevel(){
    return level;
}

/* Devuelve el tipo del pokemon */
Tipo Pokemon::getType(){
    return type;
}
