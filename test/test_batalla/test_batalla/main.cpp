#include <iostream>
#include "../../../src/entrenador.h"
#include "../../../src/pokemon.h"
#include "../../../src/movimientos.h"
#include <QtGlobal>

//typedef unsigned int uint;
using namespace std;

int main() {
    Entrenador* cpu = new Entrenador("Nerea.txt");
    Entrenador* user = new Entrenador("Willy",MALE,"user.txt");
    Pokemon* user_poke=user->getPokemon(0);
    Pokemon* cpu_poke=cpu->getPokemon(0);

    uint acertado;
    int vida_anterior;
    if(user_poke->getSpeed()>>cpu_poke->getSpeed()){
        if (user_poke->getStatePtr()->getMov()){
            vida_anterior=cpu_poke->getHP();
            acertado=user_poke->getMove(0)->getDamage(user_poke,cpu_poke);
            if(acertado!=0)
                cout<<"El usuario ha pegado primero y ha hecho: "<<vida_anterior-cpu_poke->getHP()<<endl;
            else
                cout << "Ha fallado el golpe" << endl;
        }else{
            cout << "El pokemon no se ha podido mover" << endl;
        }

        if (cpu_poke->getStatePtr()->getMov()){
            vida_anterior=user_poke->getHP();
            Movimientos* move=cpu_poke->getMove(rand()%4);
            acertado=move->getDamage(cpu_poke,user_poke);;
            if(acertado!=0)
                cout<<"El rival ha pegado y ha hecho: "<<vida_anterior-cpu_poke->getHP()<<endl;
            else
                cout << "Ha fallado el golpe" << endl;
        }else{
            cout << "El pokemon rival no se ha podido mover" << endl;
        }

    }else{
        if (cpu_poke->getStatePtr()->getMov()){
            vida_anterior=user_poke->getHP();
            Movimientos* move=cpu_poke->getMove(rand()%4);
            acertado=move->getDamage(cpu_poke,user_poke);;
            if(acertado!=0)
                cout<<"El rival ha pegado y ha hecho: "<<vida_anterior-cpu_poke->getHP()<<endl;
            else
                cout << "Ha fallado el golpe" << endl;
        }else{
            cout << "El pokemon rival no se ha podido mover" << endl;
        }

        if (user_poke->getStatePtr()->getMov()){
            vida_anterior=cpu_poke->getHP();
            acertado=user_poke->getMove(0)->getDamage(user_poke,cpu_poke);
            if(acertado!=0)
                cout<<"El usuario ha pegado primero y ha hecho: "<<vida_anterior-cpu_poke->getHP()<<endl;
            else
                cout << "Ha fallado el golpe" << endl;
        }else{
            cout << "El pokemon no se ha podido mover" << endl;
        }

    }

    vida_anterior=cpu_poke->getHP();
    cpu_poke->getStatePtr()->resolveState(cpu_poke);
    Estado estado = cpu_poke->getState();
    cout << cpu_poke->getName() << "esta " << cpu_poke->getStatePtr()->getStateName() << endl;

    vida_anterior=user_poke->getHP();
    user_poke->getStatePtr()->resolveState(user_poke);
    estado = user_poke->getState();
    cout << user_poke->getName() << "esta " << user_poke->getStatePtr()->getStateName() << endl;


    delete cpu;
    delete user;
}


