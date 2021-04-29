#include <iostream>
#include "../../../src/entrenador.h"

using namespace std;

// Test de constructores superado

int main() {
    Entrenador* jesus = new Entrenador("Jesus.txt");
    Entrenador* chus = new Entrenador("Chus.txt");
    Entrenador* maria = new Entrenador("Maria.txt");
    Entrenador* nerea = new Entrenador("Nerea.txt");
    Entrenador* user = new Entrenador("Willy",MALE,"user.txt");
    Entrenador* def = new Entrenador();
    Entrenador* prueba = new Entrenador("prueba.txt");
    Entrenador* prueba2 = new Entrenador("prueba2.txt");
    string flag = "";
    cin >> flag;
    delete jesus;
    delete chus;
    delete maria;
    delete nerea;
    delete user;
    delete def;
    delete prueba;
    delete prueba2;
    return 0;
}
