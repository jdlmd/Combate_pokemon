#include "pokemon.h"
#include "estados.h"

Pokemon::Pokemon() {

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
