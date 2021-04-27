#include "movimientoestado.h"

MovimientoEstado::MovimientoEstado() {

}

MovimientoEstado::MovimientoEstado(std::string _name, std::string _type, uint _atckORsp, uint _precision, uint _potencia, uint _pp, std::string _estado, uint _turnos, uint _porcentaje, uint _defOR) {
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
    defORspdef = _defOR;
}

MovimientoEstado::~MovimientoEstado() {

}

void MovimientoEstado::getDamage(Pokemon *atacante,Pokemon *defensor) {
    if(potencia>0){
        uint atk_stat= atacante->estadisticas_actuales.attack;
        uint def_stat=defensor->estadisticas_actuales.defense;

        if(atckORsp==1)
            atk_stat=atacante->estadisticas_actuales.sp_attack;
        if(defORspdef==1)
            def_stat=defensor->estadisticas_actuales.sp_defense;

        // El golpe critico evade las
        if((rand()%10000+1)/100<6.25){
            if(atckORsp==0){
                if(atacante->estadisticas_actuales.attack<atacante->estadisticas.attack)
                    atk_stat=atacante->estadisticas.attack;
            }else{
                if(atacante->estadisticas_actuales.sp_attack<atacante->estadisticas.sp_attack)
                    atk_stat=atacante->estadisticas.sp_attack;
            }
            if(defORspdef==0){
                if(defensor->estadisticas_actuales.defense>defensor->estadisticas.defense)
                    def_stat=defensor->estadisticas.defense;
            }else{
                if(defensor->estadisticas_actuales.sp_defense>defensor->estadisticas.sp_defense)
                    def_stat=defensor->estadisticas.sp_defense;
            }

        }

//          Este precision_mod se usará cuando se añada la evasion y la precision como estadisticas de los pokemon.
//        int precision_mod=precision*atacante->estadisticas_actuales.precision/defensor->estadisticas_actuales.evasion;
        if ((rand() % 100+1)>precision){
            float stab=atacante->type.getStab(type);
            float effectiveness=defensor->type.multiplicador(type);
            uint variacion=rand()%16+85;
            uint N=atacante->level;

            int damage= (int)(0.01*stab*effectiveness*variacion*(((0.2*N+1)*atk_stat*potencia)/(25*def_stat)+2));
//            defensor->estadisticas_actuales.hp=defensor->estadisticas_actuales.hp-damage;
            if(damage<1)    //El golpe minimo es de 1 ps.
                damage=1;
                        // Bajar la barra de vida
            defensor->setHP(defensor->estadisticas_actuales.hp-damage);
        }
    }
    if ((rand() % 100+1)<porcentaje){
        // Cuando se unan esta rama y la de nerea se descomenta esta parte
//        changeState(estado,defensor);
        // Añadir comentario del tipo el pokemon ha sido envenado
    }
}
