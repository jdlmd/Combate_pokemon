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
    /*
    if(potencia>0){
        uint atk_stat= atacante->estadisticas_actuales.atack;
        uint def_stat=defensor->estadisticas_actuales.defense;

        if(atckORsp==1)
            atk_stat=atacante->estadisticas_actuales.sp_atack;
        if(defORspdef==true)
            def_stat=defensor->estadisticas_actuales.sp_defense;

        // El golpe critico evade las
        if((rand()%10000+1)/100<6.25){
            if(atckORsp==0){
                if(atacante->estadisticas_actuales.atack<atacante->getAtack())
                    atk_stat=atacante->getAtack();
            }else{
                if(atacante->estadisticas_actuales.sp_atack<atacante->getSpAtack())
                    atk_stat=atacante->getSpAtack();
            }
            if(defORspdef==false){
                if(defensor->estadisticas_actuales.defense>defensor->getDefense())
                    def_stat=defensor->getDefense();
            }else{
                if(defensor->estadisticas_actuales.sp_defense>defensor->getSpDefense())
                    def_stat=defensor->getSpDefense();
            }


        }

        int precision_mod=precision*atacante->estadisticas_actuales.precision/defensor->estadisticas_actuales.evasion;
        if ((rand() % 100+1)>precision_mod){
            float stab=atacante->getStab(type);
            float effectiveness=defensor->tipo_Pkm.multiplicador(type.getPrimary());
            uint variacion=rand()%16+85;
            uint N=atacante->getLevel();

            int damage= (int)(0.01*stab*effectiveness*variacion*(((0.2*N+1)*atk_stat*potencia)/(25*def_stat)+2));

            // Bajar la barra de vida
            defensor->estadisticas_actuales.hp=defensor->estadisticas_actuales.hp-damage;

        }
    } */
}
