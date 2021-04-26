#include "movimientoestado.h"

MovimientoEstado::MovimientoEstado() {

}

MovimientoEstado::MovimientoEstado(std::string _name, std::string _type, uint _atckORsp, uint _precision, uint _potencia, uint _pp, std::string _estado, uint _turnos, uint _porcentaje) {
    nombre = _name;
    type = Tipo::getTypeByName(_type);
    atckORsp = _atckORsp;
    precision = _precision;
    potencia = _potencia;
    ppTotal = _pp;
    ppRemaining = _pp;
    estado = Estados::getStateByName(_estado);
    turnos = _turnos;
    porcentaje = _porcentaje;
}

MovimientoEstado::~MovimientoEstado() {

}

void MovimientoEstado::getDamage(Pokemon *atacante,Pokemon *defensor) {
    return;
}
