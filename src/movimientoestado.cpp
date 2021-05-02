#include "movimientoestado.h"
#include "qdebug.h"

/* Constructor por defecto, vacío a propósito */
MovimientoEstado::MovimientoEstado() {

}

/* Constructor de un movimiento que mete estado */
MovimientoEstado::MovimientoEstado(std::string _name, std::string _type, uint _atckORsp, uint _precision, uint _potencia, uint _pp, std::string _estado, uint _porcentaje, uint _defOR) {
    nombre = _name;
    type = Tipo::getTypeByName(_type);
    atckORsp = _atckORsp;
    precision = _precision;
    potencia = _potencia;
    ppTotal = _pp;
    ppRemaining = _pp;
    estado = Estados::getStateByName(_estado);
    turnos = -1;
    porcentaje = _porcentaje;
    defORspdef = _defOR;
}

/* Destructor, vacío a propósito */
MovimientoEstado::~MovimientoEstado() {

}

/* Calcula el daño del movimiento del pokemon que mete estado usando la potencia del movimiento, los tipos tanto del
   movimiento como del pokemon y las estadísticas del pokemon */
uint MovimientoEstado::getDamage(Pokemon *atacante,Pokemon *defensor) {
    srand(time(NULL));
    ppRemaining--;
    bool critico=false;
    uint atk_stat= atacante->estadisticas_actuales.attack;
    uint def_stat=defensor->estadisticas_actuales.defense;

    if(atckORsp==1)
        atk_stat=atacante->estadisticas_actuales.sp_attack;
    if(defORspdef==1)
        def_stat=defensor->estadisticas_actuales.sp_defense;

    // El golpe critico evade los cambios de características que bajen el daño del movimiento
    if((uint)(rand()%10000+1)/100<6.25){
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
        critico=true;
    }

    //          Este precision_mod se usará cuando se añada la evasion y la precision como estadisticas de los pokemon.
    //        int precision_mod=precision*atacante->estadisticas_actuales.precision/defensor->estadisticas_actuales.evasion;
    if ((uint)(rand() % 100+1) <= precision){
        float stab=atacante->type.getStab(type);
        float effectiveness=defensor->type.multiplicador(type);
        uint variacion=rand()%16+85;
        uint N=atacante->level;

        int damage= (int)(0.01*stab*effectiveness*variacion*(((0.2*N+1)*atk_stat*potencia)/(25*def_stat)+2));

        if(potencia==0){
            damage=0;
        }else if(damage<1)    //El golpe minimo es de 1 ps.
            damage=1;

        defensor->setHP(defensor->estadisticas_actuales.hp-damage);

        if ((rand() % 100+1)<=porcentaje){
            defensor->state->changeState(estado,defensor);
            if(potencia==0)
                return 5; // Si mete estado y la potencia del movimiento es cero, es decir, solo mete estado
            else {
                if(critico)
                    return 4; // Si es critico y mete estado
                else
                    return 2; // Si no es critico pero mete estado
            }
        }

        if(critico)
            return 3; //Si el ataque acierta y es crítico, pero no mete estado
        else
            return 1; // Si el ataque acierta y no es ni crítico ni mete estado
    }
    return 0; // Si el ataque falla
}
