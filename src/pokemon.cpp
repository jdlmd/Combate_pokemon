#include "pokemon.h"

Pokemon::Pokemon() {

}

Pokemon::Pokemon(std::string _name,std::string _t1, std::string _t2, uint _level, struct stats _ivs, struct stats _evs, struct stats _base) {
    return;
}

uint Pokemon::getAtack() {
    return 0;
}

uint Pokemon::getSpAtack() {
    return 0;
}

uint Pokemon::getDefense() {
    return 0;
}

uint Pokemon::getSpDefense() {
    return 0;
}

void Pokemon::addMove(Movimientos* move) {
    if (attck.size() < 4) {
        attck.push_back(move);
    } else {
        std::cout << "El pokemon ya tiene todos sus movimientos.\n";
    }
}
