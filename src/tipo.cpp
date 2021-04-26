#include "tipo.h"

Tipo::Tipo() {

}

Tipos Tipo::getTypeByName(std::string) {
    return NINGUNO;
}

void Tipo::setPrimary(Tipos _primario) {
    primario = _primario;
}

void Tipo::setSecondary(Tipos _secundario) {
    secundario = _secundario;
}
