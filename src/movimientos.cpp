#include "movimientos.h"
#include "pokemon.h"

Movimientos::Movimientos() {

}

Movimientos::Movimientos(std::string _name, std::string _type, uint _atckORsp, uint _precision, uint _potencia, uint _pp, uint _defORspdef) {
    nombre = _name;
    type = Tipo::getTypeByName(_type);
    atckORsp = _atckORsp;
    precision = _precision;
    potencia = _potencia;
    ppTotal = _pp;
    ppRemaining = _pp;
    defORspdef = _defORspdef;
}

Movimientos::~Movimientos() {

}

void Movimientos::getDamage(Pokemon *atacante,Pokemon *defensor){

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
            // Bajar la barra de vida
//            defensor->estadisticas_actuales.hp=defensor->estadisticas_actuales.hp-damage;
            defensor->setHP(defensor->estadisticas_actuales.hp-damage);
        }
    }
}

std::string Movimientos::getType(){

}
std::string Movimientos::getName(){
    return nombre;
}
