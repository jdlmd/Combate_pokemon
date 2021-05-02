#include <iostream>
#include "../../../src/entrenador.h"
#include "../../../src/pokemon.h"
#include "../../../src/movimientos.h"

typedef unsigned int uint;
using namespace std;

int main() {
    Entrenador* cpu = new Entrenador("Nerea.txt");
    Entrenador* user = new Entrenador("Willy",MALE,"user.txt");
    Pokemon* user_poke=user->getPokemon(0);
    Pokemon* cpu_poke=cpu->getPokemon(0);

    uint acertado;
    int vida_anterior;
    if (user_poke->getStatePtr()->getMov()){
        vida_anterior=cpu_poke->getHP();
        acertado=_move->getDamage(user_poke,cpu_poke);
        BattleText(acertado,_move,vida_anterior,user_poke,cpu_poke);
//        hpBarAnimation(vida_anterior,cpu_poke);
        updateBars();
        return checkCpuPokeHp();
    }
        else{
//        qDebug()<<"No se ha movido por pringado";
        ui->cuadro_texto->setText(QString("%1 esta %2.\nY no ha podido moverse.").arg(QString::fromStdString(user_poke->getName())).arg(QString::fromStdString(user_poke->getStatePtr()->getStateName())));
        this->repaint();
        QThread::msleep(500);

    delete cpu;
    delete user;
}


/* Ataque del pokemon del usuario */
bool UserAttack(Movimientos* _move){
    uint acertado;
    int vida_anterior;
    if (user_poke->getStatePtr()->getMov()){
        qDebug()<<"El mas rapido del oeste";
        vida_anterior=cpu_poke->getHP();
        acertado=_move->getDamage(user_poke,cpu_poke);
        BattleText(acertado,_move,vida_anterior,user_poke,cpu_poke);
//        hpBarAnimation(vida_anterior,cpu_poke);
        updateBars();
        return checkCpuPokeHp();
    }
        else{
//        qDebug()<<"No se ha movido por pringado";
        ui->cuadro_texto->setText(QString("%1 esta %2.\nY no ha podido moverse.").arg(QString::fromStdString(user_poke->getName())).arg(QString::fromStdString(user_poke->getStatePtr()->getStateName())));
        this->repaint();
        QThread::msleep(500);


    }
    return true;
}

/* Ataque aleatorio del rival */
bool CpuAttack(){
    uint acertado;
    int vida_anterior;
    if (cpu_poke->getStatePtr()->getMov()){
        vida_anterior=user_poke->getHP();
        Movimientos* move=cpu_poke->getMove(rand()%4);
//        move=cpu_poke->getMove(2);
        acertado=move->getDamage(cpu_poke,user_poke);
        BattleText(acertado,move,vida_anterior,cpu_poke,user_poke);
//        hpBarAnimation(vida_anterior,user_poke);
        updateBars();
        return checkUserPokeHp();
    }else{
//        qDebug()<<"No se ha movido por pringado";
        ui->cuadro_texto->setText(QString("%1 esta %2.\nY no ha podido moverse").arg(QString::fromStdString(cpu_poke->getName())).arg(QString::fromStdString(cpu_poke->getStatePtr()->getStateName())));
        QThread::msleep(500);

    }
    return true;
}

/* Resuelve el estado del pokemon afectado */
void resolveStates(Pokemon* poke){
    int vida_anterior=poke->getHP();
    poke->getStatePtr()->resolveState(poke);
    Estado estado = poke->getState();
    if(estado == 2 || estado == 3){
        ui->cuadro_texto->setText(QString("%1 se encuentra %2.\n Y se resiente por ello.").arg(QString::fromStdString(poke->getName())).arg(QString::fromStdString(poke->getStatePtr()->getStateName())));
    }
    hpBarAnimation(vida_anterior,poke);
    if(poke==user_poke)
        checkUserPokeHp();
    else
        checkCpuPokeHp();
}
